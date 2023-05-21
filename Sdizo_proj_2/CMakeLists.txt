cmake_minimum_required(VERSION 3.25)
project(Sdizo_proj_2)

set(CMAKE_CXX_STANDARD 11)

add_executable(Sdizo_proj_2 application/main.cpp
        file_oi/FileReader.h file_oi/FileReader.cpp
        time_watch/TimeWatch.cpp
        graf/Graf.cpp graf/Graf.h
        struct_help/matrix/Matrix.cpp struct_help/matrix/Matrix.h
        struct_help/adj_tab/AdjList.cpp struct_help/adj_tab/AdjList.h
        struct_help/adj_tab/AdjNode.cpp struct_help/adj_tab/AdjNode.h
        struct_help/que_prio/Que.cpp struct_help/que_prio/Que.h
        struct_help/que_prio/QueNode.cpp struct_help/que_prio/QueNode.h
        alg/prim/Prim_alg.cpp alg/prim/Prim_alg.h
        alg/kruskal/Kruskal_alg.cpp alg/kruskal/Kruskal_alg.h
        alg/ford_bell/Ford_bell_alg.cpp alg/ford_bell/Ford_bell_alg.h
        alg/dikjstra/Dijkstra_alg.cpp alg/dikjstra/Dijkstra_alg.h
        struct_help/edge/Edge.cpp struct_help/edge/Edge.h)
