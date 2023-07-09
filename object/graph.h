#ifndef CJ_CVRP_GRAPH_H
#define CJ_CVRP_GRAPH_H

#include <vector>
#include <algorithm>
#include "config.h"
#include <map>

typedef pair<double, double> edge;

class Graph {

public:
    map<string, int> IDX;
    vector<pair<int,edge>> adj[GRAPH_SIZE];
    vector<vector<edge>> table; // graph matrix

    Graph(const string& file_dir);
};


#endif //CJ_CVRP_GRAPH_H
