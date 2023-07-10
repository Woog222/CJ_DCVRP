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


}


Program::Program(): graph(OD_MATRIX), terminalTable(TERMINALS, graph),
                    vehicleTable(VEHICLES, graph), orderTable(ORDERS, graph){
    sort(vehicleTable.table.begin(), vehicleTable.table.end());
}