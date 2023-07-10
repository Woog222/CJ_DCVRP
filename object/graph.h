#ifndef CJ_CVRP_GRAPH_H
#define CJ_CVRP_GRAPH_H

#include <vector>
#include <algorithm>
#include "config.h"
#include <map>

typedef struct {
    double length, time;
} edge;

class Graph {

public:
    map<string, int> IDX;
    map<int, string> ID;
    edge** table; // graph matrix

    explicit Graph(const string& file_dir);
    int id2idx(const string& id) const;
    string idx2id(int idx) const;
    inline edge get_edge (int from, int to) const;
};


#endif //CJ_CVRP_GRAPH_H
