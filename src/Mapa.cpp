/** \mainpage Program MAPA
 *
 * \section wprowadzenie Wprowadzenie
 *
 * Program MAPA, to program umożliwiający znalezenie najkrótszej trasy między dwoma miastami.
 * Drogi między tymi miastami połączone są jednokierunkowymi drogami, o ustalonej długości.
 * Plik zawierający trasy oraz trasy do wyznaczenia ma ustaloną postać. <br>
 * Wynikiem działania programu jest plik z wyznaczonymi trasami - podana jest nazwa trasy, jej długość, oraz kolejne jej odcinki.
 * 
 *
 * \section uruchamianie Uruchamianie
 *
 * Program uruchamiany jest z poziomu wiersza poleceń.
 * Do uruchomienia wymaga trzech argumentów: <br>
 * - -d (plik wejściowy z drogami) <br>
 * - -t (plik wejściowy z trasami do wyznaczenia) <br>
 * - -o (plik wynikowy z wyznaczonymi trasami) <br>
 *
 * \section funkcje Funkcje programu
 *
 * - Powiadamianie o nieprawidłowym użyciu programu <br>
 * - Wyznaczanie najkrótszej możliwej trasy między miastami <br>
 * - Informowanie o niemożliwości wyznaczenia trasy <br>
 *
 */

#include "mapa.h"

/**
* Funkcja main zawierająca:
* - argumenty uruchamiania <br> 
* - wywołanie funkcji readRoads, readRoutes, shortestPath oraz writeResults <br>
* - unordered_map zawierająca informacje o trasach <br>
* @param argc liczba przełączników - gdy równa 1, to program jest uruchomiony bez przełączników 
* @param argv argumenty wiersza polecen
*/
int main(int argc, char* argv[]) {
    cout << "=== Program MAPA ===" << endl;
    string roadsFilename, routesFilename, outputFilename;
    if (argc == 1) 
        cout << "Wprowadz w argumentach programu lokalizacje plikow zawierajace: -d (plik z drogami) -t (plik z trasami) -o (plik wyjsciowy)" << endl << endl;
    else {
        for (int i = 1; i < argc; i++) {
            if (string(argv[i]) == "-d") {
                roadsFilename = argv[i + 1];
            }
            else if (string(argv[i]) == "-t") {
                routesFilename = argv[i + 1];
            }
            else if (string(argv[i]) == "-o") {
                outputFilename = argv[i + 1];
            }
        }
    }

    /* Wczytaj drogi i trasy z pliku */
    auto roads = readRoads(roadsFilename);
    auto routes = readRoutes(routesFilename);

    unordered_map <string, vector <Road>> cityToRoads;
    for (auto road : roads) {
        cityToRoads[road.city1].push_back(road); 
    }
 
    /* Sprawdz trasy, a nastepnie zapisz wyniki do pliku */
    vector<pair<pair<string, string>, vector<Road>>> results = shortestPath(routes, cityToRoads);
    writeResults(results, outputFilename);
    
    return 0;
}