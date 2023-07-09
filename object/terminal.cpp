#include "terminal.h"
#include <iostream>
#include <fstream>

Terminal_Table::Terminal_Table(const std::string &file_dir) {
    ifstream fs(file_dir);
    if (fs.fail()) {
        cerr << ("invalid directories : " + file_dir) << endl;
        exit(1);
    }

    while (fs.good()) {
        string id;
        double latitude, longitude;
        int region;
        fs >> id >> latitude >> longitude >> region;

        auto iter = table.find(id);
        if (iter == table.end()) {
            table.insert(
                    pair<string, Terminal>(
                            id, Terminal(latitude, longitude, region)
                    )
            );
        }
        else {
            cout << "duplicates in terminals.csv" << endl;
            exit(1);
        }
    }
}

