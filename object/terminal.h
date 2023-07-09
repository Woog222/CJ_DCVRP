#ifndef CJ_CVRP_TERMINALS_H
#define CJ_CVRP_TERMINALS_H

#include <vector>
#include <string>
#include <map>
using namespace std;

class Terminal {

public:
    const pair<double, double> loc; // (latitude, longitude)
    const int region;

    Terminal(double latitude, double longitude, int region_)
    : loc(pair<double,double>(latitude, longitude)), region(region_)
    {}

};

class Terminal_Table {
public:
    map<string, Terminal> table;

    Terminal_Table(const string& fname);
};


#endif //CJ_CVRP_TERMINALS_H
