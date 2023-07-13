#include "graph.h"
#include <iostream>
#include <fstream>


Graph::Graph(const string& file_dir) {

    // table reset with {-1,-1}
    edge init_value = {-1};
    table = new edge*[GRAPH_SIZE];
    for (int i = 0; i < GRAPH_SIZE; ++i) {
        table[i] = new edge[GRAPH_SIZE];
        for (int j = 0; j < GRAPH_SIZE; ++j) {
            table[i][j] = init_value; // Initialize the elements as needed
            if (i==j) table[i][j] = edge{0};
        }

    }

    // input
    ifstream fs(file_dir);

    int idx = 0;
    string origin, dest;
    double length, time;

    while (fs >> origin >> dest >> length >> time) {
        // index setting
        if (IDX.count(origin) == 0) IDX[origin] = idx++;
        if (IDX.count(dest) == 0) IDX[dest] = idx++;
        int from = IDX[origin], to = IDX[dest];

        // adj matrix
        table[from][to] = edge{time};
    }

    // ID setting
    for (const auto& pair : IDX)
        ID[pair.second] = pair.first;
}

int Graph::id2idx(const string& id) const {
    auto iter = IDX.find(id);
    if (iter == IDX.end()) {
        cout << id << " is not in od_matrix" << endl;
        exit(1);
    }
    return iter->second;
}

string Graph::idx2id(int idx) const {
    auto iter = ID.find(idx);
    if (iter == ID.end()) {
        cout << idx << " is not an valid index." << endl;
        exit(1);
    }
    return iter->second;
}
