#ifndef CJ_CVRP_CONFIG_H
#define CJ_CVRP_CONFIG_H

#include <string>
using namespace std;

const int GRAPH_SIZE = 2000;
const int ORDER_GROUP_SIZE = 40;
const int GROUP_INTERVAL = 360;  // 6hour, 360 min
const int MAX_START_TIME = 60*24*7 - 60;
const int INT_NULL = -1;

const string STRING_NULL = "-1";
const string ORDERS = "../data/orders.txt";
const string OD_MATRIX = "../data/od_matrix.txt";
const string TERMINALS = "../data/terminals.txt";
const string VEHICLES = "../data/vehicles.txt";

const string ORDER_COLUMNS =
        "ORD_NO,"
        "VehicleID,"
        "Sequence,"
        "SiteCode,"
        "ArrivalTime,"
        "WaitingTime,"
        "ServiceTime,"
        "DepartureTime,"
        "Delivered\n";
const string ORDER_RESULT_DIR = "../results/order_result.csv";





#endif //CJ_CVRP_CONFIG_H
