#include "init/setting.h"
#include "object/objects.h"
#include "config.h"
#include <iostream>
#include <unistd.h>

void terminal_test();
void vehicle_test();

int main(){
    vehicle_test();
}

void terminal_test() {
    char cwd[256];
    if (getcwd(cwd, sizeof(cwd)) != nullptr) {
        std::cout << "Current working directory: " << cwd << std::endl;
    } else {
        std::cerr << "Failed to get the current working directory." << std::endl;
    }
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
    char cwd[256];
    if (getcwd(cwd, sizeof(cwd)) != nullptr) {
        std::cout << "Current working directory: " << cwd << std::endl;
    } else {
        std::cerr << "Failed to get the current working directory." << std::endl;
    }
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