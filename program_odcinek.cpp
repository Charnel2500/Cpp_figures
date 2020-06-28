// Plik odcinek.cpp
// Implementacja metod klasy Odcinek
#include "program_odcinek.h" 

namespace MojeFigury {
    // Funkcja do rysowania odcinka
    void Odcinek::rysuj(){
        std::cout << "Rysuje odcinek o poczatku P" << poczatek
                  << " i koncu K" << koniec << "." << std::endl;
    }
    // Funkcja do przesuwania odcinka o wektor (dx,dy)
    void Odcinek::przesun(double dx, double dy) { 
        koniec.przesun(dx,dy);
        poczatek.przesun(dx,dy);
    }
    // Funkcja do skalowania odcinka
    void Odcinek::skaluj(double s) {
        if(s <= 0) throw Figura::ZlaSkala(s, "Odcinek"); 
        double x0 = poczatek.dajX();
        double delx= koniec.dajX() -x0;
        double y0 = poczatek.dajY();
        double dely= koniec.dajY() -y0;
        // Nowe współrzędne końca -po przeskalowaniu
        double x = x0 + s*delx;
        double y = y0 + s*dely;
        koniec = Punkt(x,y);
    }
    
} // namespace MojeFigury
