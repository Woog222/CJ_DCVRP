#ifndef CJ_CVRP_ORDER_H
#define CJ_CVRP_ORDER_H

#include "config.h"
#include "graph.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Order {
public:
    Order(const string &orderId, int terminalId, int destId, double latitude, double longitude,
          double cbm, int load, int group, int from, int to);

    string order_id;
    double latitude, longitude, cbm;
    int load, group, from, to, terminal_id, dest_id;// whole group
    bool serviced = false;

    friend std::ostream& operator<<(std::ostream& os, const Order& obj) {
        os << obj.order_id << "( " << obj.group << " )" << " : \n"
        << obj.from << " - " << obj.to << ", " << obj.terminal_id << " -> " << obj.dest_id << '\n';
        return os;
    }

};

class OrderTable {

public:
    vector<Order> table[ORDER_GROUP_SIZE];

    OrderTable(const string& file_dir, const Graph& graph);

};


#endif //CJ_CVRP_ORDER_H
