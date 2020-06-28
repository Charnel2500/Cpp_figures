// Plik trojkat.h
// Definicja klasy Trojkat do reprezentowania odcinka
// Klasa Trojkat dziedziczy po klasie abstrakcyjnej Figura
#ifndef TROJKAT_H
#define TROJKAT_H

#include "program_figura.h"  // Plik nagłówkowy dla klasy Figura
#include "program_punkt.h"   // Plik nagłówkowy dla klasy Punkt

namespace MojeFigury {
    
    // Klasa Trojkat – dziedziczy po klasie Figura
    class Trojkat: public Figura { 
        Punkt w1, w2, w3;
        
        public:
            //Konstruktor, w tym domyślny (przykładowy)
            Trojkat(Punkt a = Punkt(0,1), Punkt b = Punkt(0,0), Punkt c = Punkt(1,1)); 
            // Funkcja do rysowania odcinka w oknie
            void rysuj(void);
            // Funkcja do przesuwania odcinka
            void przesun(double, double);
            // Funkcja do skalowania odcinka
            void skaluj(double);
            // Klasa do obsługi wyjątków
        class ZleWierzcholki {
                Punkt p, r, s;  // wierzcholki trojkata
            public:
                // Konstruktor
                ZleWierzcholki(Punkt a, Punkt b, Punkt c): p(a), r(b), s(c) {}
                // Zwróć wierzcholki trojkata
                void dajWierzcholki(Punkt& a, Punkt& b, Punkt& c) const
                { a = p; b = r; c = s;}
                // Komunikat
                void Komunikat() const
                { 
                    std::cerr<< "\n* Wyjatek: class Trojkat: wierzcholki sie nakladaja. Pierwszy: "
                                << p << ", drugi: " << r << ", trzeci: " << s << "." <<std::endl;
                
                }
        }; // class ZleWierzcholki
    };
    
    // Definicja konstruktora
    inline Trojkat::Trojkat(Punkt a, Punkt b, Punkt c) {
        if ((a != b) && (b != c) && (a != c)) {
            w1 = a; w2 = b; w3 = c;
        }
        // Rzucanie wyjątku gdy złe wierzcholki, 
        // tzn. w1 = w2 = w3
        else 
            throw Trojkat::ZleWierzcholki(a, b, c); 
    }
    
}
#endif
