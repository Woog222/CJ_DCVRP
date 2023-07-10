#ifndef CJ_CVRP_TERMINALS_H
#define CJ_CVRP_TERMINALS_H

#include "graph.h"
#include <vector>
#include <string>
#include <map>
#include <ostream>

using namespace std;

class Terminal {

public:
    pair<double, double> loc; // (latitude, longitude)
    int region;

    Terminal(double latitude, double longitude, int region_)
    : loc(pair<double,double>(latitude, longitude)), region(region_)
    {}

    friend ostream &operator<<(ostream &os, const Terminal &terminal) {
        os << "loc: (" << terminal.loc.first << ", " << terminal.loc.second
        << "), region: " << terminal.region;
        return os;
    }

};

class Terminal_Table {
public:
    map<int, Terminal> table;

    Terminal_Table(const string& file_dir, const Graph& graph);
};


#endif //CJ_CVRP_TERMINALS_H
