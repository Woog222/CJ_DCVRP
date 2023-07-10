#include "terminal.h"
#include <iostream>
#include <fstream>

Terminal_Table::Terminal_Table(const string& file_dir, const Graph& graph) {
    ifstream fs(file_dir);
    if (fs.fail()) {
        cerr << ("invalid directories : " + file_dir) << endl;
        exit(1);
    }


    string id;
    double latitude, longitude;
    int region, idx;
    while (fs >> id >> latitude >> longitude >> region) {
        idx = graph.id2idx(id);

        auto iter = table.find(idx);
        if (iter == table.end()) {
            table.insert(
                    pair<int, Terminal>(
                            idx, Terminal(latitude, longitude, region)
                    )
            );
        }
        else {
            cout << "duplicates in terminals.csv" << endl;
            exit(1);
        }
    }
}

