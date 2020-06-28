// Plik okrag .cpp
// Implementacja metod klasy okrag
#include "program_okrag.h"

namespace MojeFigury {
        // Funkcja do rysowania okregu
    void Okrag::rysuj(){
        std::cout << "Rysuje okrag o srodku P" << srodek
                  << " i promieniu r " << r << "." << std::endl;
    }
    // Funkcja do przesuwania okregu o wektor (dx,dy)
    void Okrag::przesun(double dx, double dy) { 
        srodek.przesun(dx,dy);
    }
    // Funkcja do skalowania okregu
    void Okrag::skaluj(double s) {
        if(s <= 0) throw Figura::ZlaSkala(s, "Okrag"); 
        r = s*r;
    }
    
}
