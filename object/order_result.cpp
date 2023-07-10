#include "order_result.h"



OrderResult::OrderResult(const string &vehicleId, const string &ordNo, const string &siteCode, const string &delivered,
                         int arrivalTime, int waitingTime, int serviceTime, int departureTime, long long sequence)
        : VehicleID(vehicleId), ORD_NO(ordNo), SiteCode(siteCode), Delivered(delivered), ArrivalTime(arrivalTime),
          WaitingTime(waitingTime), ServiceTime(serviceTime), DepartureTime(departureTime), Sequence(sequence) {}

ostream &operator<<(ostream &os, const OrderResult &result) {
    os << result.ORD_NO << ","
    << result.VehicleID << ","
    << result.Sequence << ","
    << result.SiteCode << ","
    << result.ArrivalTime << ","
    << result.WaitingTime << ","
    << result.ServiceTime << ","
    << result.DepartureTime << ","
    << result.Delivered << "\n";
    return os;
}

OrderResult::OrderResult(const string &vehicleId, const string &siteCode, long long int sequence) : VehicleID(
        vehicleId), SiteCode(siteCode), Sequence(sequence) {}
