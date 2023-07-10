//
// Created by achui on 2023-07-09.
//

#include "order.h"
#include <iostream>
#include <fstream>


OrderTable::OrderTable(const string& file_dir, const Graph& graph) {

    ifstream fs(file_dir);
    if (fs.fail()) {
        cerr << ("invalid directories : " + file_dir) << endl;
        exit(1);
    }

    string order_id, terminal_id, dest_id, temp;
    int load, group, from, to;
    double latitude, longitude, cbm;
    while (fs >> order_id >> latitude >> longitude
              >> terminal_id >> dest_id >> cbm
              >> from >> to >> load
              >> temp >> temp >> group) {// date, group, whole_group


        table[group].emplace_back(order_id, graph.id2idx(terminal_id), graph.id2idx(dest_id),
                                  latitude, longitude,cbm,
                                  load, group, from, to
                );
    }
}

Order::Order(const string &orderId, int terminalId, int destId,
             double latitude, double longitude, double cbm,
             int load, int group, int from, int to) :
             order_id(orderId), terminal_id(terminalId), dest_id(destId),
             latitude(latitude), longitude(longitude), cbm(cbm),
             load(load), group(group), from(from), to(to)
             {}
