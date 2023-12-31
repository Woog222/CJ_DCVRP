#ifndef CJ_CVRP_PROGRAM_H
#define CJ_CVRP_PROGRAM_H

#include "config.h"
#include "object/objects.h"
#include "logger.h"


class Program {
    Vehicle_Table vehicleTable;
    Terminal_Table terminalTable;
    OrderTable orderTable;
    Graph graph;
    Logger logger;

public:
    explicit Program();
    void simulator();

};


#endif //CJ_CVRP_PROGRAM_H
