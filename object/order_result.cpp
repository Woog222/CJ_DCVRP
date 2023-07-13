#include "order_result.h"



OrderResult::OrderResult(const string &vehicleId, const string &ordNo, const string &siteCode,
                         int arrivalTime, int waitingTime, int serviceTime, int departureTime, long long sequence)
        : VehicleID(vehicleId), ORD_NO(ordNo), SiteCode(siteCode), ArrivalTime(arrivalTime), Delivered(0),
          WaitingTime(waitingTime), ServiceTime(serviceTime), DepartureTime(departureTime), Sequence(sequence),
          ArrivalTime_print(-1), WaitingTime_print(-1), ServiceTime_print(-1), DepartureTime_print(-1) {}

ostream &operator<<(ostream &os, const OrderResult &result) {
    os << result.ORD_NO << ","
    << result.VehicleID << ","
    << result.Sequence << ","
    << result.SiteCode << ","
    << result.ArrivalTime_print << ","
    << result.WaitingTime_print << ","
    << result.ServiceTime_print << ","
    << result.DepartureTime_print << ","
    << result.Delivered << "\n";
    return os;
}

void OrderResult::update(int cur_time) {
    if (DepartureTime <= cur_time) {
        ArrivalTime_print = ArrivalTime;
        WaitingTime_print = WaitingTime;
        ServiceTime_print = ServiceTime;
        DepartureTime_print = DepartureTime;
        Delivered = 1;
    }
}
