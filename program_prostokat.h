// Plik prostokat.h
// Definicja klasy Prostokat do reprezentowania odcinka
// Klasa Prostokat dziedziczy po klasie abstrakcyjnej Figura
#ifndef PROSTOKAT_H
#define PROSTOKAT_H

#include "program_figura.h"  // Plik nagłówkowy dla klasy Figura
#include "program_punkt.h"   // Plik nagłówkowy dla klasy Punkt

namespace MojeFigury {
    
    // Klasa Prostokat – dziedziczy po klasie Figura
    class Prostokat: public Figura { 
        Punkt poczatek;
        double a;
        double b;
    public:
            //Konstruktor, w tym domyślny (przykładowy)
            Prostokat(Punkt p = Punkt(0,1), double bok1 = 2, double bok2 = 3); 
            // Funkcja do rysowania odcinka w oknie
            void rysuj(void);
            // Funkcja do przesuwania odcinka
            void przesun(double, double);
            // Funkcja do skalowania odcinka
            void skaluj(double);
            // Klasa do obsługi wyjątków
        class ZleBoki {
                double r, s;  // wierzcholki boki
            public:
                // Konstruktor
                ZleBoki(double bok1, double bok2): r(bok1), s(bok2) {}
                // Zwróć boki prostokata
                void dajBoki(double &bok1, double &bok2) const
                { bok1 = r; bok2 = s;}
                // Komunikat
                void Komunikat() const
                { 
                    std::cerr<< "\n* Wyjatek: class Prostokat: Boki są ujemne. Pierwszy: "
                                << r << ", drugi: " << s << "." <<std::endl;
                
                }
        }; // class ZleBoki
    };
    inline Prostokat::Prostokat(Punkt p, double bok1, double bok2) {
        if ((bok1 >= 0) && (bok2 >= 0)) {
            a = bok1; b = bok2;
            poczatek = p;
        }
        // Rzucanie wyjątku gdy złe końce, 
        // tzn. bok1 i bok2 < 0
        else 
            throw Prostokat::ZleBoki(bok1, bok2); 
    }
}
#endif
