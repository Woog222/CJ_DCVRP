#include "program.h"
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <simulator/alloc.h>






/*
 * at each batch, free_time got set to the start time of that group
 */
void Program::simulator() {

    cout << "Simulation ongoing..\n";
    logger.order_result_init(ORDER_RESULT_DIR);

    for (int group = 0; group < ORDER_GROUP_SIZE; ++group) {
        auto& batch = orderTable.table[group];
        if (batch.empty()) continue;

        cout << "\t";
        cout << "batch " << group << ".. ";
        batch_alloc(batch, graph, vehicleTable.table, logger);
        logger.write_order(group * 60 * 6);

        cout << "done\n";
    }
}


Program::Program(): graph(OD_MATRIX){
    cout << "Graph constructed\n";
    terminalTable = Terminal_Table(TERMINALS, graph);
    cout << "Terminal Table constructed\n";
    vehicleTable = Vehicle_Table(VEHICLES, graph);
    cout << "Vechicle Table constructed\n";
    orderTable = OrderTable(ORDERS, graph);
    cout << "Order Table constructed\n";
    cout << '\n';

    sort(vehicleTable.table.begin(), vehicleTable.table.end());
}