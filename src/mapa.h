#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <numeric>
using namespace std;

/**
 * Struktura zawierająca dane o drogach.
 * @param city1 Zawiera nazwę początkowego miasta
 * @param city2 Zawiera nazwę nazwę miasta końcowego
 * @param distance Zawiera odległość między miastem początkowym, a końcowym
 */
struct Road {
    string city1;
    string city2;
    int distance;
};

/**
* Funkcja służąca do odczytywania dróg z pliku.
* @param filename Zawiera nazwę pliku w którym znajdują się drogi.
*/
vector<Road> readRoads(string filename) {
    vector<Road> roads;
    ifstream input(filename);
    if (!input.is_open()) {
        cerr << "Nie udalo sie otworzyc pliku z drogami." << endl;
        return roads;
    }

    string city1, city2;
    int distance;
    while (input >> city1 >> city2 >> distance) {
        roads.push_back({ city1, city2, distance });
    }

    return roads;
}

/**
* Funkcja służąca do odczytywania tras z pliku.
* @param filename Zawiera nazwę pliku w którym znajdują się trasy.
*/
vector<pair<string, string>> readRoutes(string filename) {
    vector<pair<string, string>> routes;
    ifstream input(filename);
    if (!input.is_open()) {
        cerr << "Nie udalo sie otworzyc pliku z trasami." << endl;
        return routes;
    }

    string city1, city2;
    while (input >> city1 >> city2) {
        routes.push_back({ city1, city2 });
    }

    return routes;
}

/**
* Funkcja służąca do zapisywania wyniku działania programu do pliku.
* Jeżeli program nie znalazł trasy pomiędzy dwoma miastami funkcja zwraca o tym informację.
* @param results Zawiera docelowo wektor wyniku działania funkcji shortestPath.
* @param filename Zawiera nazwę pliku do którego będzie zapisywany wynik działania programu.
*/
void writeResults(vector<pair<pair<string, string>, vector<Road>>> results, string filename) {
    ofstream output(filename);
    if (!output.is_open()) {
        cerr << "Nie udalo sie otworzyc pliku wyjsciowego." << endl;
        return;
    }
    for (auto result : results) {
        auto route = result.first;
        auto roads = result.second;
        if (roads.empty()) {
            output << "Nie znaleziono trasy dla trasy: " << route.first << " --> " << route.second << endl;
        }
        else {
            output << "Trasa: " << route.first << " --> " << route.second << " (" << accumulate(roads.begin(), roads.end(), 0, [](int sum, Road road) { return sum + road.distance; }) << " km):" << endl;
            for (auto road : result.second) {
                output << road.city1 << " ---> " << road.city2 << " ---> " << road.distance << "km" << endl;
            }
        }
    }
}


/**
* Funkcja oparta na algorytmie Dijkstry służąca do znajdowania najkrótszej trasy między dwoma miastami.
* @param routes Zawiera wektor pary stringów z trasami (nazwami dwóch miast).
* @param cityToRoads Zawiera typ unordered_map z informacjami o trasach.
*/
vector<pair<pair<string, string>, vector<Road>>> shortestPath(vector<pair<string, string>> routes, unordered_map<string, vector<Road>> cityToRoads) {
    vector<pair<pair<string, string>, vector<Road>>> results;
    for (auto route : routes) {
        unordered_map<string, int> distance;
        unordered_map<string, string> predecessor;
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> queue;

        distance[route.first] = 0;
        queue.push({ 0, route.first });

        // Dopóki kolejka nie jest pusta:
        while (!queue.empty()) {
            auto top = queue.top();
            queue.pop();


            auto city = top.second;

            for (auto road : cityToRoads[city]) {
                // Jeśli dotarliśmy do końcowego miasta, zapamiętaj wynik
                if (road.city2 == route.second) {
                    distance[route.second] = distance[city] + road.distance;
                    predecessor[route.second] = city;
                    break;
                }

                // Jeśli jeszcze nie odwiedziliśmy danego miasta:
                if (distance.count(road.city2) == 0) {
                    distance[road.city2] = distance[city] + road.distance;
                    predecessor[road.city2] = city;
                    queue.push({ distance[road.city2], road.city2 });
                }
            }
        }

        // Jeśli udało się znaleźć trasę do końcowego miasta:
        if (predecessor.count(route.second) > 0) {
            vector<Road> result;
            auto currentCity = route.second;
            while (currentCity != route.first) {
                result.push_back({ predecessor[currentCity], currentCity, distance[currentCity] - distance[predecessor[currentCity]] });
                currentCity = predecessor[currentCity];
            }
            reverse(result.begin(), result.end());
            results.push_back({ route, result });
        }
        else {
            results.push_back({ route, {}});
        }
    }
    return results;
}

