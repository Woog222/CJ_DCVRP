#include "program.h"
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>

inline int start_time(const )

void batch_alloc(const vector<Order>& batch, const Graph& graph, const vector<Vehicle>& vehicles) {

    // calculating start time : max(arrival time, can time)
    auto start_time = [&graph](const Vehicle& veh, const Order& order) {
        auto edge = graph.get_edge(veh.start_center, order.dest_id);
        int arrival_time = ceil(edge.time)
    };

    for (auto& veh : vehicles) {
        auto order_comp = [&veh](const Order& a, const Order& b) {
            auto& now = veh.start_center;

        };
    }

}
/*
 * at each batch, free_time got set to the start time of that group
 */
void Program::simulator() {


}


Program::Program(): graph(OD_MATRIX), terminalTable(TERMINALS),
                    vehicleTable(VEHICLES),orderTable(ORDERS) {
    sort(vehicleTable.table.begin(), vehicleTable.table.end());
}