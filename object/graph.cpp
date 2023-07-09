//
// Created by achui on 2023-07-09.
//

#include "graph.h"
#include <iostream>
#include <fstream>

Graph::Graph(const string& file_dir){

    ifstream fs(file_dir);
    if (fs.fail()) {
        cerr << ("invalid directories : " + file_dir) << endl;
        exit(1);
    }

    int idx = 0;
    while (fs.good()) {
        string origin, dest;
        double length, time;
        fs >> origin >> dest >> length >> time;

        // index setting
        if (IDX.count(origin) == 0) IDX[origin] = idx++;
        if (IDX.count(dest) == 0) IDX[dest] = idx++;
        int from = IDX[origin], to = IDX[dest];

        adj[from].push_back(
                pair<int, edge>(to, edge{length, time})
        );
    }
}