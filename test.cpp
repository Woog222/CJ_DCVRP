#include "init/setting.h"
#include "object/objects.h"
#include "config.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

void graph_test();
void terminal_test(const Graph& graph);
void vehicle_test(const Graph& graph);
void order_test(const Graph& graph);

int main(){
    Graph graph(OD_MATRIX);
    cout << "Terminal_test : \n";
    terminal_test(graph);
    cout << "Vehicle_test : \n";
    vehicle_test(graph);
    cout << "Order Test : \n";
    order_test(graph);
}

void graph_test() {
    cout << "?" << endl;
    Graph graph(OD_MATRIX);
}

void terminal_test(const Graph& graph) {
    Terminal_Table terminals(TERMINALS, graph);

    int idx = 0;
    auto& table = terminals.table;
    for(auto iter = table.begin(); iter != table.end(); ++iter) {
        auto& terminal = iter->second;

        cout << graph.ID.find(iter->first)->second << " : "
        << terminal << '\n';

        if (++idx > 20) break;
    }
}

void vehicle_test(const Graph& graph) {
    Vehicle_Table vehicles(VEHICLES, graph);

    int idx = 0;
    auto& table = vehicles.table;
    for(auto iter = table.begin(); iter != table.end(); ++iter) {
        cout << graph.ID.find(iter->start_center)->second << " : " << *iter << '\n';
        idx++;
        if (idx > 10) {
            break;
        }
    }

    sort(table.begin(), table.end());
    idx = 0;
    for(auto iter = table.begin(); iter != table.end(); ++iter) {
        cout << graph.ID.find(iter->start_center)->second << " : " << *iter << '\n';
        idx++;
        if (idx > 10) {
            break;
        }
    }
}

void order_test(const Graph& graph) {
    OrderTable orders(ORDERS, graph);

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