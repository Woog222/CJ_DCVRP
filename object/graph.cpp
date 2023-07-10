#include "graph.h"
#include <iostream>
#include <fstream>

Graph::Graph(const string& file_dir){

    // table reset with {-1,-1}
    edge init_value = {-1.0,-1.0};

    for (int i =0; i<GRAPH_SIZE; ++i) {
        for (int j =0; j<GRAPH_SIZE; ++j) {
            table[i][j] = init_value;
        }
    }

    ifstream fs(file_dir);

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
                pair<int, edge>(to, {length, time})
        );
        table[from][to] = edge{length, time};
    }


}