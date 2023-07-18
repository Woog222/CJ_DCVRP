#include "alloc.h"
#include <cmath>
#include "config.h"



/**
 * feasible and earliest loading start time
 * @param arrival_time (at destination)
 * @param from (unloading available time start)
 * @param to (unloading available time end)
 * @return
 */
int can_time_cal(int arrival_time, int from, int to) {
    int quotient = arrival_time / DAY;
    int remainder = arrival_time % DAY;

    if (from < to) {
        if (from <= remainder && remainder <= to) return arrival_time;
        else if (to < remainder) return (quotient+1)*DAY + from;
        else return quotient*DAY + from; // remainder < from;
    }
    else { // to < from
        if (from < remainder && remainder < to) return quotient*DAY + from;
        else return arrival_time;
    }
}

/**
 *
 * @param veh
 * @param batch
 * @param graph
 * @param vehicles
 * @param logger
 * @return allocated successfully (true) OR nothing allocated (false)
 */
bool veh_cycle(Vehicle& veh, vector<Order>& batch, const Graph& graph, const vector<Vehicle>& vehicles, Logger& logger) {

    bool ret = false;
    auto travel_time = [&graph](int from, int to) {
        return int(ceil(graph.get_edge(from, to).time));
    };

    // for each order
    int left = veh.capa, when = veh.free_time, where = veh.start_center;
    int terminal = -1;
    for (auto& order : batch) {
        if (order.serviced ||
            left < order.cbm ||
            (terminal !=-1 && terminal!=order.terminal_id) ||
            (terminal !=-1 && travel_time(where, order.dest_id) < 0 ) ||  //
            (terminal ==-1 && travel_time(where, order.terminal_id) < 0 ) ||
            (terminal ==-1 && travel_time(order.terminal_id, order.dest_id) < 0)
            )
            continue; // already serviced or too heavy or not connected

        int arrival_time, start_time;

        // terminal determined (first)
        if (terminal == -1) {
            arrival_time = when + travel_time(where, order.terminal_id) +travel_time(order.terminal_id, order.dest_id);
            start_time = can_time_cal(arrival_time, order.from, order.to);
            if (start_time > MAX_START_TIME) continue;
            terminal = order.terminal_id;
            when += travel_time(where, order.terminal_id);
            where = order.terminal_id;

            logger.add_order(veh.veh_num, STRING_NULL, graph.idx2id(terminal),
                             when,0,0,when);
        }

        // not first and different destination
        if (order.dest_id != where) {
            arrival_time = when + travel_time(where, order.dest_id);
            start_time = can_time_cal(arrival_time, order.from, order.to);
            if (start_time> MAX_START_TIME) continue;
            when = start_time+ order.load;
        }
        where = order.dest_id;
        left -= order.cbm;
        order.serviced = true;

        logger.add_order(veh.veh_num, order.order_id, graph.idx2id(order.dest_id), arrival_time,
                         start_time-arrival_time,order.load,when);

        ret |= true;
    }
    veh.free_time = when;
    veh.start_center = where;

    return ret;
}

/**
 * @param batch
 * @param graph
 * @param vehicles
 * @return
 */
batchResult batch_alloc(vector<Order>& batch, const Graph& graph, vector<Vehicle>& vehicles, Logger& logger) {

    // return value init
    batchResult ret;
    for (auto& veh : vehicles) ret[veh.veh_num] = vector<OrderResult>();

    // calculating start time : max(arrival time, can time)
    auto start_time = [&graph](const Vehicle& veh, const Order& order) {
        edge e = graph.get_edge(veh.start_center, order.dest_id);
        if (e.time == -1.0) return -1; // not connected

        int arrival_time = int(ceil(e.time)) + veh.free_time;
        return can_time_cal(arrival_time, order.from, order.to);
    };

    bool allocated = false;
    while (!allocated) {

        allocated = false;
        for (auto& veh : vehicles) {
            // sorting orders (earlier order that this can take)
            sort(batch.begin(), batch.end(), [&veh, &start_time, &graph](const Order& a, const Order& b) {
                auto& now = veh.start_center;
                return start_time(veh, a) < start_time(veh, b);
            });

            allocated |= veh_cycle(veh, batch, graph, vehicles, logger);
        } //for
        if (!allocated) break;
    } // while

    return ret;
}






