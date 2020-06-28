// Plik prostokat.cpp
// Implementacja metod klasy Prostokat
#include "program_prostokat.h" 

namespace MojeFigury {
        // Funkcja do rysowania prostokata
    void Prostokat::rysuj(){
        std::cout << "Rysuje prostokat o poczatku P" << poczatek
                  << " dlugosci pierwszego boku " << a << " i dlugosci drugiego boku " << b << "." << std::endl;
    }
    // Funkcja do przesuwania prostokata o wektor (dx,dy)
    void Prostokat::przesun(double dx, double dy) { 
        poczatek.przesun(dx,dy);
    }
    // Funkcja do skalowania odcinka
    void Prostokat::skaluj(double s) {
        if(s <= 0) throw Figura::ZlaSkala(s, "Prostokat"); 
        a = s*a;
        b = s*b;
    }
    
}
