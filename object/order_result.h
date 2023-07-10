#ifndef CJ_CVRP_ORDER_RESULT_H
#define CJ_CVRP_ORDER_RESULT_H

#include <ostream>
#include "config.h"


class OrderResult{
public:
    // order
    OrderResult(const string& vehicleId, const string& ordNo, const string &siteCode, const string &delivered,
                int arrivalTime, int waitingTime, int serviceTime, int departureTime, long long sequence);

    // terminal
    OrderResult(const string &vehicleId, const string &siteCode, long long int sequence);

    friend ostream &operator<<(ostream &os, const OrderResult &result);

    string VehicleID, ORD_NO, SiteCode, Delivered;
    int ArrivalTime, WaitingTime, ServiceTime, DepartureTime;
    long long Sequence;
};



#endif //CJ_CVRP_ORDER_RESULT_H
