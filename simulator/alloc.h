#ifndef CJ_CVRP_ALLOC_H
#define CJ_CVRP_ALLOC_H

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "object/objects.h"
using namespace std;


typedef map<string, vector<OrderResult>> batchResult; // (vehId, ..)


int can_time_cal(int arrival_time, int from, int to);
vector<OrderResult> veh_cycle(const Vehicle& veh, vector<Order>& batch, const Graph& graph, const vector<Vehicle>& vehicles);
batchResult batch_alloc(vector<Order>& batch, const Graph& graph, const vector<Vehicle>& vehicles);
#endif //CJ_CVRP_ALLOC_H
