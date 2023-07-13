#ifndef CJ_CVRP_LOGGER_H
#define CJ_CVRP_LOGGER_H

#include <string>
#include <map>
#include "object/objects.h"
using namespace std;



class Logger {

public:
    vector<OrderResult> orderResults;
    string order_result_dir;
    double total_cost;
    long long sequence;
    int cur_time;

    Logger(): total_cost(0.0), sequence(0), cur_time(0) {}

    void update_logs(int cur_time_);
    void add_order(const string& vehicleId, const string& ordNo, const string &siteCode,
                           int arrivalTime, int waitingTime, int serviceTime, int departureTime);
    void write_order(int cur_time);
    void order_result_init(const string& file_dir);
};


#endif //CJ_CVRP_LOGGER_H
