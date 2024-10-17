# Map [EN]

## Project Description

This project involves the implementation of a program to determine the shortest route between two cities using Dijkstra's algorithm. The program is written in C++ utilizing  data structures such as vectors, maps, pairs, and queues.

## Program Features

- **Route Calculation**: The program allows for the calculation of the shortest route between two cities using Dijkstra's algorithm.
- **Multiple Routes Handling**: Users can specify multiple routes to calculate in a single run of the program.
- **Input Files**: The program uses two input files: one containing the road map and the other specifying the routes to calculate.
- **Output File**: The program generates an output file with the results, detailing the calculated routes or indicating if a route could not be determined.

## Project Structure

The project consists of the following functions and structures:

- **main**: The main function responsible for processing command-line arguments, running the algorithm, and saving the results to a file.
- **readRoads**: A function responsible for reading the road map from a file.
- **readRoutes**: A function that reads the routes to be calculated from a file.
- **writeResults**: A function that saves the calculated routes to a file.
- **shortestPath**: The implementation of Dijkstra's algorithm, which calculates the shortest paths between cities.

## Requirements

- C++11 or newer

## Documentation

The project documentation was generated using Doxygen. It contains a detailed description of the functions and structures used in the project. The documentation can be found in the `docs` directory.

## Info

This project was completed as part of the Computer Programming Basics course at the Silesian University of Technology in the 2022/2023 academic year.

# Mapa [PL]

## Opis projektu

Projekt dotyczy implementacji programu do wyznaczania najkrótszej trasy między dwoma miastami przy użyciu algorytmu Dijkstry. Program został napisany w języku C++ z wykorzystaniem struktur danych, takich jak wektor, mapa, para, oraz kolejka.

## Funkcje programu

- **Wyznaczanie trasy**: Program umożliwia znalezienie najkrótszej trasy między dwoma miastami, korzystając z algorytmu Dijkstry.
- **Obsługa wielu tras**: Użytkownik może określić wiele tras do wyznaczenia w jednym uruchomieniu programu.
- **Pliki wejściowe**: Program korzysta z dwóch plików wejściowych: jeden zawiera mapę dróg, a drugi - trasy do wyznaczenia.
- **Plik wynikowy**: Program generuje plik wyjściowy z wynikami, zawierający szczegóły wyznaczonych tras lub informację o braku możliwości ich wyznaczenia.

## Struktura projektu

Projekt składa się z następujących funkcji i struktur:

- **main**: Funkcja główna odpowiedzialna za przetwarzanie argumentów linii poleceń, uruchamianie algorytmu oraz zapisywanie wyników do pliku.
- **readRoads**: Funkcja odpowiedzialna za wczytywanie mapy dróg z pliku.
- **readRoutes**: Funkcja wczytująca trasy do wyznaczenia z pliku.
- **writeResults**: Funkcja zapisująca wyniki wyznaczonych tras do pliku.
- **shortestPath**: Implementacja algorytmu Dijkstry, wyznaczająca najkrótsze trasy pomiędzy miastami.

## Wymagania

- C++11 lub nowszy

## Dokumentacja

Dokumentacja projektu została wygenerowana przy użyciu narzędzia Doxygen. Zawiera szczegółowy opis funkcji oraz struktur użytych w projekcie. Dokumentację można znaleźć w katalogu `docs`.

## Informacje

Projekt został zrealizowany w ramach kursu Podstawy Programowania Komputerów na Politechnice Śląskiej w roku akademickim 2022/2023.