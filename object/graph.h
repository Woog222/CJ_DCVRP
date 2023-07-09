#ifndef CJ_CVRP_GRAPH_H
#define CJ_CVRP_GRAPH_H

#include <vector>
#include <algorithm>
#include "config.h"
#include <map>


class Graph {
    struct edge{
        double length, time;
    };

public:
    map<string, int> IDX;
    vector<pair<int,edge>> adj[GRAPH_SIZE];

    Graph(const string& file_dir);
};


#endif //CJ_CVRP_GRAPH_H
