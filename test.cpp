#include "init/setting.h"
#include "object/objects.h"
#include "config.h"
#include <iostream>
#include <unistd.h>

void terminal_test();
void vehicle_test();
void order_test();

int main(){
//    cout << "\nVehicle Test : \n";
//    vehicle_test();
//    cout << "\nTerminal Test : \n";
//    terminal_test();
    order_test();
}

void terminal_test() {
    Terminal_Table terminals("../data/" + TERMINALS);

    int idx = 0;
    auto& table = terminals.table;
    for(auto iter = table.begin(); iter != table.end(); ++iter) {
        auto& terminal = iter->second;

        cout << terminal.region << " : (" <<
        terminal.loc.first << ", " << terminal.loc.second << ")\n";
        idx++;
        if (idx > 20) {
            return;
        }
    }
}

void vehicle_test() {
    Vehicle_Table vehicles("../data/" + VEHICLES);

    int idx = 0;
    auto& table = vehicles.table;
    for(auto iter = table.begin(); iter != table.end(); ++iter) {
        cout << *iter << '\n';
        idx++;
        if (idx > 20) {
            return;
        }
    }
}

void order_test() {
    OrderTable orders("../data/" + ORDERS);

    for (int i =0; i<10; i+=3) {
        int idx = 0;
        auto& table = orders.table[i];
        for(auto iter = table.begin(); iter != table.end(); ++iter) {
            cout << *iter << '\n';
            idx++;
            if (idx > 5) break;
        }
    }

    int group = 0;
    for (auto& table : orders.table) {
        cout << group++ << " : " << table.size() << '\n';
    }
}