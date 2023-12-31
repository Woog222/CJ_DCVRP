#include "vehicle.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <map>

Vehicle_Table::Vehicle_Table(const std::string &file_dir, const Graph& graph) {
    ifstream fs(file_dir);
    if (fs.fail()) {
        cerr << ("invalid directories : " + file_dir) << endl;
        exit(1);
    }

    string veh_num, start_center, temp;
    int veh_ton, capa, fc;
    double vc;
    while (fs >> veh_num >> veh_ton >> temp >>temp
              >> capa >> start_center >> fc >> vc) {
        table.emplace_back(capa, fc, vc, veh_ton, graph.id2idx(start_center),veh_num);
    }
}
