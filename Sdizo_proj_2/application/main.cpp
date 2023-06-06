#include <iostream>
#include <vector>

//------------------------------------------------------------

#include "../file_oi/FileReader.h"
#include "../graf/Graf.h"
#include "../alg/prim/Prim_alg.h"
#include "../alg/kruskal/Kruskal_alg.h"
#include "../alg/dikjstra/Dijkstra_alg.h"
#include "../alg/ford_bell/Ford_bell_alg.h"
#include "../tester/Tester_alg.h"

//------------------------------------------------------------

void menu();
void prim_menu();
void kruskal_menu();
void dijkstra_menu();
void bell_ford_menu();
void menu_table();

//------------------------------------------------------------

void tests();
void prim_tests();
void kruskal_tests();
void dijkstra_tests();
void bell_ford_tests();

//------------------------------------------------------------

int main() {

    menu();

}

void menu_table(){
    std::cout << "Wybierz algorytm" << std::endl;
    std::cout << "1. Prim" << std::endl;
    std::cout << "2. Kruskal" << std::endl;
    std::cout << "3. Dijkstra" << std::endl;
    std::cout << "4. Bellman-Ford" << std::endl;
    std::cout << "0. Koniec programu" << std::endl;
}

void menu(){

    std::string path = "..//data//path//";
    std::string mst = "..//data//mst//";

    int num;

    do{
        menu_table();
        std::cin >> num;
        system("cls");
        switch (num) {

            case 1:
                //implementacja tablicy
                prim_menu();
                system("cls");
                break;

            case 2:
                //implementacji listy
                kruskal_menu();
                system("cls");
                break;

            case 3:
                //implementacja kopca
                dijkstra_menu();
                system("cls");
                break;
            case 4:
                //implementacja drzewa bst
                bell_ford_menu();
                system("cls");
                break;
            case 10:
                //implementacja testów
                tests();

                break;
            case 0:
                exit(0);

            default:
                std::cout << "Brak takiej opcji" << std::endl;
                system("pause");
                system("cls");
                break;
        }
    } while (num);


}

void prim_menu(){

    int num;
    std::string file;
    std::string mst = "..//data//mst//";

    auto *  fileReader = new FileReader();

    do {
        std::cout << "Algorytm Prima: " << std::endl;
        std::cout << "--------------------------------------------------------------" << std::endl;

        std::cout << "Wybierz forme wykonania algorytmu " << std::endl;
        std::cout << "1. Macierz" << std::endl;
        std::cout << "2. Lista" << std::endl;
        std::cout << "0. Cofnij do menu glownego" << std::endl;

        std::cout << "Podaj numer operacji: ";
        std::cin >> num;

        system("cls");

        if(num == 0) break;

        if(num > 2){
            std::cout << "Brak takiej opcji ! "<< std::endl;
            system("pause");
            system("cls");
            continue;
        }

        std::cout << "Podaj nazwe pliku (bez dopisku txt): ";
        std::cin >> file;

        auto * g = new Graf(fileReader->readNumbers(mst + file + ".txt"), false);
        auto * prim = new Prim_alg(g);

        g->display();

        switch (num) {
            case 1:

                prim->solution_matrix();
                prim->display_solution();

                system("pause");
                system("cls");

                break;

            case 2:

                prim->solution_list();
                prim->display_solution();

                system("pause");
                system("cls");

                break;

            default:
                break;
        }

        delete g;
        delete prim;


    } while (true);

    delete fileReader;

}

void kruskal_menu(){

    int num;
    std::string file;
    std::string mst = "..//data//mst//";

    auto *  fileReader = new FileReader();

    do {
        std::cout << "Algorytm Kruskala: " << std::endl;
        std::cout << "--------------------------------------------------------------" << std::endl;

        std::cout << "Wybierz forme wykonania algorytmu " << std::endl;
        std::cout << "1. Macierz" << std::endl;
        std::cout << "2. Lista" << std::endl;
        std::cout << "0. Cofnij do menu glownego" << std::endl;

        std::cout << "Podaj numer operacji: ";
        std::cin >> num;

        system("cls");

        if(num == 0) break;

        if(num > 2){
            std::cout << "Brak takiej opcji ! "<< std::endl;
            system("pause");
            system("cls");
            continue;
        }

        std::cout << "Podaj nazwe pliku (bez dopisku txt): ";
        std::cin >> file;

        auto * g = new Graf(fileReader->readNumbers(mst + file + ".txt"), false);
        auto * kruskal = new Kruskal_alg(g);

        g->display();

        switch (num) {
            case 1:

                kruskal->solution_matrix();
                kruskal->display_solution();

                system("pause");
                system("cls");

                break;

            case 2:

                kruskal->solution_list();
                kruskal->display_solution();

                system("pause");
                system("cls");

                break;

            default:
                break;
        }

        delete g;
        delete kruskal;


    } while (true);

    delete fileReader;

}

void dijkstra_menu(){

    int num;
    std::string file;
    std::string path = "..//data//path//";

    auto *  fileReader = new FileReader();

    do {
        std::cout << "Algorytm Dijkstry: " << std::endl;
        std::cout << "--------------------------------------------------------------" << std::endl;

        std::cout << "Wybierz forme wykonania algorytmu " << std::endl;
        std::cout << "1. Macierz" << std::endl;
        std::cout << "2. Lista" << std::endl;
        std::cout << "0. Cofnij do menu glownego" << std::endl;

        std::cout << "Podaj numer operacji: ";
        std::cin >> num;

        system("cls");

        if(num == 0) break;

        if(num > 2){
            std::cout << "Brak takiej opcji ! "<< std::endl;
            system("pause");
            system("cls");
            continue;
        }

        std::cout << "Podaj nazwe pliku (bez dopisku txt): ";
        std::cin >> file;

        auto * g = new Graf(fileReader->readNumbers(path + file + ".txt"), true);
        auto * dijkstra = new Dijkstra_alg(g);

        g->display();

        switch (num) {
            case 1:

                dijkstra->solution_matrix();
                dijkstra->display_solution();

                system("pause");
                system("cls");

                break;

            case 2:

                dijkstra->solution_list();
                dijkstra->display_solution();

                system("pause");
                system("cls");

                break;

            default:
                break;
        }

        delete g;
        delete dijkstra;


    } while (true);

    delete fileReader;

}

void bell_ford_menu(){

    int num;
    std::string file;
    std::string path = "..//data//path//";

    auto *  fileReader = new FileReader();

    do {
        std::cout << "Algorytm Bellmana-Forda : " << std::endl;
        std::cout << "--------------------------------------------------------------" << std::endl;

        std::cout << "Wybierz forme wykonania algorytmu " << std::endl;
        std::cout << "1. Macierz" << std::endl;
        std::cout << "2. Lista" << std::endl;
        std::cout << "0. Cofnij do menu glownego" << std::endl;

        std::cout << "Podaj numer operacji: ";
        std::cin >> num;

        system("cls");

        if(num == 0) break;

        if(num > 2){
            std::cout << "Brak takiej opcji ! "<< std::endl;
            system("pause");
            system("cls");
            continue;
        }

        std::cout << "Podaj nazwe pliku (bez dopisku txt): ";
        std::cin >> file;

        auto * g = new Graf(fileReader->readNumbers(path + file + ".txt"), true);
        auto * bell_ford = new Ford_bell_alg(g);

        g->display();

        switch (num) {
            case 1:

                bell_ford->solution_matrix();
                bell_ford->display_solution();

                system("pause");
                system("cls");

                break;

            case 2:

                bell_ford->solution_list();
                bell_ford->display_solution();

                system("pause");
                system("cls");

                break;

            default:
                break;
        }

        delete g;
        delete bell_ford;


    } while (true);

    delete fileReader;


}

void tests(){

//    prim_tests();
    kruskal_tests();
    dijkstra_tests();
    bell_ford_tests();

}

void prim_tests(){

    auto * tester = new Tester_alg();
    auto * writer = new FileWriter;

    int chose = 1;
    std::string type = "matrix";

    //                                 wersja na macierzy
    std::cout << "Prim macierz"<< std::endl;
    writer->save("Prim macierz");
    for(int i = 200; i <= 700; i+= 100) {
        std::cout << "Testy dla "<< i <<" wierzcholkow"<< std::endl;
        writer->save("Testy dla "+ std::to_string(i) +" wierzcholkow");

        std::cout << "Testy dla "<< 1 <<"wierzcholkow"<< std::endl;
        tester->test_alg(chose, i, 0.25f, type);

        std::cout << "Testy dla "<< 2 <<"wierzcholkow"<< std::endl;
        tester->test_alg(chose, i, 0.50f, type);

        std::cout << "Testy dla "<< 3 <<"wierzcholkow"<< std::endl;
        tester->test_alg(chose, i, 0.75f,type);

        std::cout << "Testy dla "<< 4 <<"wierzcholkow"<< std::endl;
        tester->test_alg(chose, i, 0.99f,type);
    }



    //----------------------------------------------------------------------------------------------

    type = "list";

    //                                      wersja na listach
    std::cout << "Prim lista"<< std::endl;
    for(int i = 200; i <= 700; i+= 100) {
        std::cout << "Testy dla "<< i <<" wierzcholkow"<< std::endl;
        writer->save("Testy dla "+ std::to_string(i) +" wierzcholkow");

        std::cout << "Testy dla "<< 1 <<"wierzcholkow"<< std::endl;
        tester->test_alg(chose, i, 0.25f, type);

        std::cout << "Testy dla "<< 2 <<"wierzcholkow"<< std::endl;
        tester->test_alg(chose, i, 0.50f, type);

        std::cout << "Testy dla "<< 3 <<"wierzcholkow"<< std::endl;
        tester->test_alg(chose, i, 0.75f,type);

        std::cout << "Testy dla "<< 4 <<"wierzcholkow"<< std::endl;
        tester->test_alg(chose, i, 0.99f,type);
    }


    delete tester;
    delete writer;

}

void kruskal_tests(){

    auto * tester = new Tester_alg();
    auto * writer = new FileWriter();

    int chose = 2;
    std::string type = "matrix";

    //                                 wersja na macierzy
    std::cout << "Kruskal macierz"<< std::endl;
    writer->save("Kruskal macierz");
    for(int i = 500; i <= 700; i+= 100) {
        std::cout << "Testy dla "<< i <<"wierzcholkow"<< std::endl;
        writer->save("Testy dla "+ std::to_string(i) +" wierzcholkow");

        std::cout << "Testy dla "<< 1 <<"wierzcholkow"<< std::endl;
        tester->test_alg(chose, i, 0.25f, type);

        std::cout << "Testy dla "<< 2 <<"wierzcholkow"<< std::endl;
        tester->test_alg(chose, i, 0.50f, type);

        std::cout << "Testy dla "<< 3 <<"wierzcholkow"<< std::endl;
        tester->test_alg(chose, i, 0.75f,type);

        std::cout << "Testy dla "<< 4 <<"wierzcholkow"<< std::endl;
        tester->test_alg(chose, i, 0.99f,type);
    }



    //----------------------------------------------------------------------------------------------

    type = "list";

    //                                      wersja na listach
    std::cout << "Kruskal lista"<< std::endl;
    writer->save("Kruskal lista");
    for(int i = 200; i <= 700; i+= 100) {
        std::cout << "Testy dla "<< i <<"wierzcholkow"<< std::endl;
        writer->save("Testy dla "+ std::to_string(i) +" wierzcholkow");

        std::cout << "Testy dla "<< 1 <<"wierzcholkow"<< std::endl;
        tester->test_alg(chose, i, 0.25f, type);

        std::cout << "Testy dla "<< 2 <<"wierzcholkow"<< std::endl;
        tester->test_alg(chose, i, 0.50f, type);

        std::cout << "Testy dla "<< 3 <<"wierzcholkow"<< std::endl;
        tester->test_alg(chose, i, 0.75f,type);

        std::cout << "Testy dla "<< 4 <<"wierzcholkow"<< std::endl;
        tester->test_alg(chose, i, 0.99f,type);
    }


    delete tester;
    delete writer;

}

void dijkstra_tests(){

    auto * tester = new Tester_alg();
    auto * writer = new FileWriter();

    int chose = 3;
    std::string type = "matrix";

    //                                 wersja na macierzy
    std::cout << "Dijkstra macierz"<< std::endl;
    writer->save("Dijkstra macierz");
    for(int i = 200; i <= 700; i+= 100) {
        std::cout << "Testy dla "<< i <<"wierzcholkow"<< std::endl;
        writer->save("Testy dla "+ std::to_string(i) +" wierzcholkow");

        std::cout << "Testy dla "<< 1 <<"wierzcholkow"<< std::endl;
        tester->test_alg(chose, i, 0.25f, type);

        std::cout << "Testy dla "<< 2 <<"wierzcholkow"<< std::endl;
        tester->test_alg(chose, i, 0.50f, type);

        std::cout << "Testy dla "<< 3 <<"wierzcholkow"<< std::endl;
        tester->test_alg(chose, i, 0.75f,type);

        std::cout << "Testy dla "<< 4 <<"wierzcholkow"<< std::endl;
        tester->test_alg(chose, i, 0.99f,type);
    }



    //----------------------------------------------------------------------------------------------

    type = "list";

    //                                      wersja na listach
    std::cout << "Dijkstra lista"<< std::endl;
    writer->save("Dijkstra lista");
    for(int i = 200; i <= 700; i+= 100) {
        std::cout << "Testy dla "<< i <<"wierzcholkow"<< std::endl;
        writer->save("Testy dla "+ std::to_string(i) +" wierzcholkow");

        std::cout << "Testy dla "<< 1 <<"wierzcholkow"<< std::endl;
        tester->test_alg(chose, i, 0.25f, type);

        std::cout << "Testy dla "<< 2 <<"wierzcholkow"<< std::endl;
        tester->test_alg(chose, i, 0.50f, type);

        std::cout << "Testy dla "<< 3 <<"wierzcholkow"<< std::endl;
        tester->test_alg(chose, i, 0.75f,type);

        std::cout << "Testy dla "<< 4 <<"wierzcholkow"<< std::endl;
        tester->test_alg(chose, i, 0.99f,type);
    }

    delete tester;
    delete writer;
}

void bell_ford_tests(){

    auto * tester = new Tester_alg();
    auto * writer = new FileWriter();

    int chose = 4;
    std::string type = "matrix";

    //                                 wersja na macierzy
    std::cout << "Bellman-Ford macierz"<< std::endl;
    writer->save("Bellman-Ford macierz");
    for(int i = 200; i <= 700; i+= 100) {
        std::cout << "Testy dla "<< i <<"wierzcholkow"<< std::endl;
        writer->save("Testy dla "+ std::to_string(i) +" wierzcholkow");

        std::cout << "Testy dla "<< 1 <<"wierzcholkow"<< std::endl;
        tester->test_alg(chose, i, 0.25f, type);

        std::cout << "Testy dla "<< 2 <<"wierzcholkow"<< std::endl;
        tester->test_alg(chose, i, 0.50f, type);

        std::cout << "Testy dla "<< 3 <<"wierzcholkow"<< std::endl;
        tester->test_alg(chose, i, 0.75f,type);

        std::cout << "Testy dla "<< 4 <<"wierzcholkow"<< std::endl;
        tester->test_alg(chose, i, 0.99f,type);
    }



    //----------------------------------------------------------------------------------------------

    type = "list";

    //                                      wersja na listach
    std::cout << "Bellman-Ford lista"<< std::endl;
    writer->save("Bellman-Ford lista");
    for(int i = 200; i <= 700; i+= 100) {
        std::cout << "Testy dla "<< i <<"wierzcholkow"<< std::endl;
        writer->save("Testy dla "+ std::to_string(i) +" wierzcholkow");

        std::cout << "Testy dla "<< 1 <<"wierzcholkow"<< std::endl;
        tester->test_alg(chose, i, 0.25f, type);

        std::cout << "Testy dla "<< 2 <<"wierzcholkow"<< std::endl;
        tester->test_alg(chose, i, 0.50f, type);

        std::cout << "Testy dla "<< 3 <<"wierzcholkow"<< std::endl;
        tester->test_alg(chose, i, 0.75f,type);

        std::cout << "Testy dla "<< 4 <<"wierzcholkow"<< std::endl;
        tester->test_alg(chose, i, 0.99f,type);
    }

    delete tester;
    delete writer;

}