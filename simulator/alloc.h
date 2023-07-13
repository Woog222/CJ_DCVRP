#ifndef CJ_CVRP_ALLOC_H
#define CJ_CVRP_ALLOC_H

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "object/objects.h"
#include "logger.h"
using namespace std;


typedef map<string, vector<OrderResult>> batchResult; // (vehId, ..)


int can_time_cal(int arrival_time, int from, int to);
bool veh_cycle(Vehicle& veh, vector<Order>& batch, const Graph& graph, const vector<Vehicle>& vehicles, Logger& logger);
batchResult batch_alloc(vector<Order>& batch, const Graph& graph, vector<Vehicle>& vehicles, Logger& logger);
#endif //CJ_CVRP_ALLOC_H
