#ifndef CJ_CVRP_ORDER_RESULT_H
#define CJ_CVRP_ORDER_RESULT_H

#include <ostream>
#include "config.h"


class OrderResult{
public:
    // order
    OrderResult(const string& vehicleId, const string& ordNo, const string &siteCode,
                int arrivalTime, int waitingTime, int serviceTime, int departureTime, long long sequence);

    friend ostream &operator<<(ostream &os, const OrderResult &result);

    string VehicleID, ORD_NO, SiteCode;
    int Delivered;
    int ArrivalTime_print, WaitingTime_print, ServiceTime_print, DepartureTime_print;
    int ArrivalTime, WaitingTime, ServiceTime, DepartureTime;
    long long Sequence;

    void update(int cur_time);
};



#endif //CJ_CVRP_ORDER_RESULT_H
