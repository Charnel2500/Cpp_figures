// Plik okrag.h
// Definicja klasy Okrag do reprezentowania odcinka
// Klasa Okrag dziedziczy po klasie abstrakcyjnej Figura
#ifndef OKRAG_H
#define OKRAG_H

#include "program_figura.h"  // Plik nagłówkowy dla klasy Figura
#include "program_punkt.h"   // Plik nagłówkowy dla klasy Punkt

namespace MojeFigury {
    
    // Klasa Okrag – dziedziczy po klasie Figura
    class Okrag: public Figura { 
        Punkt srodek;
        double r;
    public:
            //Konstruktor, w tym domyślny (przykładowy)
            Okrag(Punkt a = Punkt(3,4), double promien = 3); 
            // Funkcja do rysowania odcinka w oknie
            void rysuj(void);
            // Funkcja do przesuwania odcinka
            void przesun(double, double);
            // Funkcja do skalowania odcinka
            void skaluj(double);
            // Klasa do obsługi wyjątków
        class ZlyPromien {
                double s;  // promien okregu
            public:
                // Konstruktor
                ZlyPromien(double promien): s(promien) {}
                // Zwróć promien okregu
                void dajPromien(double &promien) const
                { promien = s;}
                // Komunikat
                void Komunikat() const
                { 
                    std::cerr<< "\n* Wyjatek: class Okrag: Promien jest ujemny. Wynosi: " << s << "." <<std::endl;
                
                }
        }; // class ZlyPromien
    };
    inline Okrag::Okrag(Punkt a, double promien) {
        if (promien > 0) {
            r = promien;
            srodek = a;
        }
        // Rzucanie wyjątku gdy promien ujemny, 
        // tzn. r < 0
        else 
            throw Okrag::ZlyPromien(promien); 
    }
}
#endif
