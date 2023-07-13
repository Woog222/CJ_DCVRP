//
// Created by achui on 2023-07-10.
//

#include "logger.h"
#include <iostream>
#include <fstream>

void Logger::add_order(const string& vehicleId, const string& ordNo, const string &siteCode,
                            int arrivalTime, int waitingTime, int serviceTime, int departureTime) {
    orderResults.emplace_back(vehicleId, ordNo, siteCode,arrivalTime,
                              waitingTime, serviceTime, departureTime, sequence++);
}

void Logger::update_logs(int cur_time_) {
    cur_time = cur_time_;
    for (auto& order : orderResults) order.update(cur_time);
}

void Logger::order_result_init(const string& file_dir) {

    order_result_dir = file_dir;
    std::ofstream f(order_result_dir);
    f << ORDER_COLUMNS;
    f.close();
}

void Logger::write_order(int cur_time) {
    std::ofstream f(order_result_dir, std::ios::app);

    update_logs(cur_time);
    if (f.is_open()) {
        for (auto& order : orderResults)
            f << order;
    }
    else {
        cout << order_result_dir << "is not valid result directory.\n";
    }
    f.close();
}