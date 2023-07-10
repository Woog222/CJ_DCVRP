#ifndef CJ_CVRP_CONFIG_H
#define CJ_CVRP_CONFIG_H

#include <string>
using namespace std;

const int GRAPH_SIZE = 2000;
const int ORDER_GROUP_SIZE = 40;
const int GROUP_INTERVAL = 360;  // 6hour, 360 min


const string ORDERS = "../data/orders.txt";
const string OD_MATRIX = "../data/od_matrix.txt";
const string TERMINALS = "../data/terminals.txt";
const string VEHICLES = "../data/vehicles.txt";




#endif //CJ_CVRP_CONFIG_H
