#include "alloc.h"
#include <cmath>



/**
 * feasible and earliest loading start time
 * @param arrival_time (at destination)
 * @param from (unloading available time start)
 * @param to (unloading available time end)
 * @return
 */
int can_time_cal(int arrival_time, int from, int to) {
    int quotient = arrival_time / 1440;
    if (from < to) {
        if (from <= arrival_time && arrival_time <= to) return arrival_time;
        else return (quotient+1)*1440 + from;
    }
    else {
        if (from < arrival_time && arrival_time < to) return (quotient+1)*1440 + from;
        else return arrival_time;
    }
}


vector<OrderResult> veh_cycle(const Vehicle& veh, vector<Order>& batch, const Graph& graph, const vector<Vehicle>& vehicles) {

    vector<OrderResult> ret;

    // for each order
    int left = veh.capa, when = veh.free_time, where = veh.start_center;
    string current_orderId = "not-yet";
    for (auto& order : batch) {
        edge e = graph.get_edge(where, order.dest_id);
        if (order.serviced || left < order.cbm || e.time == -1.0)
            continue; // already serviced or too heavy or not connected

        // new place!
        if (current_orderId != order.order_id) {
            int arrival_time = when + int(ceil(e.time));
            int next = can_time_cal(arrival_time, where, order.dest_id);
            if (next > MAX_START_TIME) continue;

            current_orderId = order.order_id;
            when = next + order.load;
            where = order.dest_id;
        }
        /////// logging!!
        left -= order.cbm;

    }
    return ret;
}

/**
 *
 * @param batch
 * @param graph
 * @param vehicles
 * @return
 */
batchResult batch_alloc(vector<Order>& batch, const Graph& graph, const vector<Vehicle>& vehicles) {

    // return value init
    batchResult ret;
    for (auto& veh : vehicles) ret[veh.veh_num] = vector<OrderResult>();

    // calculating start time : max(arrival time, can time)
    auto start_time = [&graph](const Vehicle& veh, const Order& order) {
        edge e = graph.get_edge(veh.start_center, order.dest_id);
        if (e.time == -1.0 && e.length==-1.0 ) return -1; // not connected

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

            vector<OrderResult> one_cycle = veh_cycle(veh, batch, graph, vehicles);
            if (one_cycle.size() > 0) {
                allocated = true;
                one_cycle.emplace_back(veh.veh_num, veh.)
            }

            auto& alloc = ret[veh.veh_num];
            alloc.insert(alloc.end(), one_cycle.begin(),one_cycle.end());
        } //for
        if (!allocated) break;
    } // while

    return ret;
}






