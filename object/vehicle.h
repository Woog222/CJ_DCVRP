#ifndef CJ_CVRP_VEHICLE_H
#define CJ_CVRP_VEHICLE_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Vehicle {

public:
    const int capa, fc, veh_ton; // max_capacity
    const double vc;
    const string veh_num, start_center;

    Vehicle(int capa_, int fc_, double vc_, int veh_ton_,
            const string& veh_num_, const string& start_center_):
            capa(capa_), fc(fc_), vc(vc_), veh_ton(veh_ton_),
            veh_num(veh_num_), start_center(start_center_)
    {}
    friend std::ostream& operator<<(std::ostream& os, const Vehicle& obj) {
        os << obj.veh_num << " : " << obj.capa << obj.fc << obj.vc << endl;
        return os;
    }
};

class Vehicle_Table{

public:
    vector<Vehicle> table;

    Vehicle_Table(const string& file_dir);

};


#endif //CJ_CVRP_VEHICLE_H
