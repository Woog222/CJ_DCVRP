#ifndef CJ_CVRP_LOGGER_H
#define CJ_CVRP_LOGGER_H

#include <string>
#include <map>
#include "object/objects.h"
using namespace std;



class Logger {

    map<string, OrderResult> orderResults;
    vector<OrderResult> loadingLog;
    double total_cost = 0.0;
    long long sequence = 0;

    void log_orders(const vector<OrderResult>& results);
    void loading()
};


#endif //CJ_CVRP_LOGGER_H
