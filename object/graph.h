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
    vector<pair<int,edge>> adj[GRAPH_SIZE];
    edge table[GRAPH_SIZE][GRAPH_SIZE]; // graph matrix

    Graph(const string& file_dir);
};


#endif //CJ_CVRP_GRAPH_H
