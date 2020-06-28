// Plikfigura.h
// Klasa abstrakcyjna Figura dla figur geometrycznych
#ifndef FIGURY_H
#define FIGURY_H
#include <iostream>
#include <cstdlib>
#include <string>
#include <iostream>
#include "program_figura.h"  // Plik nagłówkowy dla klasy Figura
#include "program_punkt.h"   // Plik nagłówkowy dla klasy Punkt
#include "program_odcinek.h"  // Plik nagłówkowy dla klasy Figura
#include "program_trojkat.h"   // Plik nagłówkowy dla klasy Punkt
#include "program_prostokat.h"  // Plik nagłówkowy dla klasy Figura
#include "program_okrag.h"   // Plik nagłówkowy dla klasy Punkt

using namespace std;

using namespace MojeFigury;

template <typename T, int n = 8 >  // definicja szablonu klasy
class Tablica {       // tablica z kontrolą zakresu indeksów
    T tab[n];
    public:T& operator[](int i) { // operator indeksowania tablicy
        if(i < 0 || i >= n) {
            std::cerr<< "Indeks poza zakresem: " << i << std::endl;std::exit(1);
            }
            return tab[i];
    } // operator[]
    int rozmiar() const { return n; }
}; // classWektor
#endif
