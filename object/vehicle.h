#ifndef CJ_CVRP_VEHICLE_H
#define CJ_CVRP_VEHICLE_H

#include "graph.h"
#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

class Vehicle {

public:
    int capa, fc, veh_ton, start_center;
    double vc;
    string veh_num;

    int free_time;

    Vehicle(int capa_, int fc_, double vc_, int veh_ton_,
            int start_center_, const string& veh_num_):
            capa(capa_), fc(fc_), vc(vc_), veh_ton(veh_ton_),
            veh_num(veh_num_), start_center(start_center_),
            free_time(0)
    {}

    friend ostream &operator<<(ostream &os, const Vehicle &vehicle) {
        os << "capa: " << vehicle.capa << " vc: " << vehicle.vc << " veh_num: " << vehicle.veh_num << " free_time: "
           << vehicle.free_time;
        return os;
    }

    bool operator<(const Vehicle &rhs) const {
        if (free_time == rhs.free_time) {
            if (rhs.capa == capa)
                return vc < rhs.vc;
            return capa > rhs.capa;
        }
        return free_time < rhs.free_time;
    }

};

class Vehicle_Table{

public:
    vector<Vehicle> table;

    Vehicle_Table(const string& file_dir, const Graph& graph);
};


#endif //CJ_CVRP_VEHICLE_H
