#include "Tester_alg.h"

void Tester_alg::test_alg(int chose, int size, float density, std::string type) {
    switch (chose) {
        case 1:
            //prim
            if(type == "matrix")test_prim_matrix(size,density);
            else test_prim_list(size,density);
            break;
        case 2:
            //kruskal
            if(type == "matrix")test_kruskal_matrix(size,density);
            else test_kruskal_list(size,density);
            break;
        case 3:
            //dijkstra
            if(type == "matrix")test_dijkstra_matrix(size,density);
            else test_dijkstra_list(size,density);
            break;
        case 4:
            //ford_bell
            if(type == "matrix")test_bell_ford_matrix(size,density);
            else test_bell_ford_list(size,density);
            break;
        default:
            break;
    }
}



void Tester_alg::test_prim_matrix(int size, float density) {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, size - 1);

    long long int avg = 0;

    for(int i = 0; i < 200; i++) {
        std::cout << i << ", ";
        int st = dist(gen);
        g = gen_graph.generate(size, false, density, true, st, 0);
        prim = new Prim_alg(g);

        timer.startStopwatch();
        prim->solution_matrix();
        avg += timer.stopStopwatch();

        delete g;
        delete prim;

    }

     writer.save(std::to_string(avg / 200.0f));


}

void Tester_alg::test_prim_list(int size, float density) {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, size - 1);

    long long int avg = 0;

    for(int i = 0; i < 200; i++) {
        std::cout << i << ", ";
        int st = dist(gen);
        g = gen_graph.generate(size, false, density, true, st, 0);
        prim = new Prim_alg(g);

        timer.startStopwatch();
        prim->solution_list();
        avg += timer.stopStopwatch();

        delete g;
        delete prim;

    }

    writer.save(std::to_string(avg / 200.0f));

}

void Tester_alg::test_kruskal_matrix(int size, float density) {

    long long int avg = 0;

    for(int i = 0; i < 200; i++) {
        std::cout << i << ", ";
        g = gen_graph.generate(size, false, density, true, 0, 0);
        kruskal = new Kruskal_alg(g);

        timer.startStopwatch();
        kruskal->solution_matrix();
        avg += timer.stopStopwatch();

        delete g;
        delete kruskal;

    }

    writer.save(std::to_string(avg / 200.0f));
}

void Tester_alg::test_kruskal_list(int size, float density) {

    long long int avg = 0;

    for(int i = 0; i < 200; i++) {
        std::cout << i << ", ";
        g = gen_graph.generate(size, false, density, true, 0, 0);
        kruskal = new Kruskal_alg(g);

        timer.startStopwatch();
        kruskal->solution_list();
        avg += timer.stopStopwatch();

        delete g;
        delete kruskal;

    }

    writer.save(std::to_string(avg / 200.0f));

}

void Tester_alg::test_dijkstra_matrix(int size, float density) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, size - 1);

    long long int avg = 0;

    for(int i = 0; i < 200; i++) {
        std::cout << i << ", ";
        int st = dist(gen);
        g = gen_graph.generate(size, true, density, true, st, 0);
        dijkstra = new Dijkstra_alg(g);

        timer.startStopwatch();
        dijkstra->solution_matrix();
        avg += timer.stopStopwatch();

        delete g;
        delete dijkstra;

    }

    writer.save(std::to_string(avg / 200.0f));
}

void Tester_alg::test_dijkstra_list(int size, float density) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, size - 1);

    long long int avg = 0;

    for(int i = 0; i < 200; i++) {
        std::cout << i << ", ";

        int st = dist(gen);
        g = gen_graph.generate(size, true, density, true, st, 0);
        dijkstra = new Dijkstra_alg(g);

        timer.startStopwatch();
        dijkstra->solution_list();
        avg += timer.stopStopwatch();

        delete g;
        delete dijkstra;

    }

    writer.save(std::to_string(avg / 200.0f));
}

void Tester_alg::test_bell_ford_matrix(int size, float density) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, size - 1);

    long long int avg = 0;

    for(int i = 0; i < 200; i++) {
        std::cout << i << ", ";

        int st = dist(gen);
        g = gen_graph.generate(size, true, density, false, st, 0);
        ford_bell = new Ford_bell_alg(g);

        timer.startStopwatch();
        ford_bell->solution_matrix();
        avg += timer.stopStopwatch();

        delete g;
        delete ford_bell;

    }

    writer.save(std::to_string(avg / 200.0f));
}

void Tester_alg::test_bell_ford_list(int size, float density) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, size - 1);

    long long int avg = 0;

    for(int i = 0; i < 200; i++) {
        std::cout << i << ", ";

        int st = dist(gen);
        g = gen_graph.generate(size, true, density, false, st, 0);
        ford_bell = new Ford_bell_alg(g);

        timer.startStopwatch();
        ford_bell->solution_list();
        avg += timer.stopStopwatch();

        delete g;
        delete ford_bell;

    }

    writer.save(std::to_string(avg / 200.0f));
}





