# Mapa

## Opis projektu

Projekt dotyczy implementacji programu do wyznaczania najkrótszej trasy między dwoma miastami przy użyciu algorytmu Dijkstry. Program został napisany w języku C++ z wykorzystaniem zaawansowanych struktur danych, takich jak wektor, mapa, para, oraz kolejka, co zapewnia efektywność obliczeniową oraz łatwość w rozbudowie i utrzymaniu kodu.

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

## Instalacja i uruchomienie

1. Sklonuj repozytorium:
   ```sh
   git clone https://github.com/siwiaszczykb/mapa.git
   ```

2. Przejdź do katalogu z projektem:
   ```sh
   cd mapa
   ```

3. Zbuduj projekt za pomocą CMake:
   ```sh
   mkdir build
   cd build
   cmake ..
   make
   ```

4. Uruchom program, podając odpowiednie pliki wejściowe:
   ```sh
   ./mapa -d drogi.txt -t trasy.txt -o wyniki.txt
   ```

## Wymagania

- C++11 lub nowszy

## Dokumentacja

Dokumentacja projektu została wygenerowana przy użyciu narzędzia Doxygen. Zawiera szczegółowy opis funkcji oraz struktur użytych w projekcie. Dokumentację można znaleźć w katalogu `docs`.

## Autor

Projekt został zrealizowany przez Bartosza Siwiaszczyka w ramach kursu Podstawy Programowania Komputerów na Politechnice Śląskiej w roku akademickim 2022/2023.