// Plik trojkat.cpp
// Implementacja metod klasy trojkat
#include "program_trojkat.h"

namespace MojeFigury {
    void Trojkat::rysuj(){
        std::cout << "Rysuje trojkat o pierwszym wierzcholku " << w1
                  << " drugim wierzcholku " << w2 << " trzecim wierzcholku " << w3 << "." << std::endl;
    }
    // Funkcja do przesuwania odcinka o wektor (dx,dy)
    void Trojkat::przesun(double dx, double dy) { 
        w1.przesun(dx,dy);
        w2.przesun(dx,dy);
        w3.przesun(dx,dy);
    }
    // Funkcja do skalowania odcinka
    void Trojkat::skaluj(double s) {
        if(s <= 0) throw Figura::ZlaSkala(s, "Trojkat"); 
        double x0 = w1.dajX();
        double delx= w2.dajX() -x0;
        double y0 = w1.dajY();
        double dely= w2.dajY() -y0;
        double x1 = w1.dajX();
        double delx1= w3.dajX() -x1;
        double y1 = w1.dajY();
        double dely1= w3.dajY() -y1;
        // Nowe współrzędne końca -po przeskalowaniu
        double x = x0 + s*delx;
        double y = y0 + s*dely;
        w2 = Punkt(x,y);
        double xv2 = x1 + s*delx1;
        double yv2 = y1 + s*dely1;
        w3 = Punkt(xv2,yv2);
        
    }
    
}
