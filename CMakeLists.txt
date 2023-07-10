cmake_minimum_required(VERSION 3.23)
project(CJ_CVRP)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CJ_CVRP
        init/setting.cpp
        init/setting.h
        object/graph.cpp
        object/graph.h
        object/objects.h
        object/terminal.h
        object/terminal.cpp
        object/vehicle.h
        object/vehicle.cpp
        object/order.cpp
        object/order.h
        object/order_result.h
        object/order_result.cpp

        simulator/program.cpp
        simulator/program.h
        simulator/logger.h
        simulator/logger.cpp
        simulator/alloc.h
        simulator/alloc.cpp


        test.cpp)
