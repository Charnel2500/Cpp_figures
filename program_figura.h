// Plikfigura.h
// Klasa abstrakcyjna Figura dla figur geometrycznych
#include <string>
#include <iostream>

#ifndef FIGURA_H 
#define FIGURA_H

using namespace std;

namespace MojeFigury {
    
    class Figura { // Klasa abstrakcyjna Figura
        public:
            // Czysto wirtualny destruktor
            virtual~Figura() = 0;
            // Funkcja czysto wirtualna do rysowania figur
            virtual void rysuj(void) = 0;
            // Funkcja czysto wirtualna do przesuwania figur
            virtual void przesun(double, double) = 0;
            // Funkcja czysto wirtualna do skalowania figur
            virtual void skaluj(double) = 0;
            
// Zagnieżdżonaklasa do obsługi wyjątków dla funkcji skaluj
        class ZlaSkala{
            double s;         // skala 
            string gdzie;    // miejsce zgłoszenia wyjątku: klasa
            
        public:
            // Konstruktor
            ZlaSkala(double x=0,std::string opis=""): s(x),gdzie(opis){}
            // Zwróć skalę
            float dajSkale() const{ return s; }
            // Komunikat
            void Komunikat() const{
                std::cerr<< "\nWyjatek w funkcji skaluj dla klasy: " 
                    << gdzie << ": zla skala s = " << s << std::endl;
            }
        }; // classZlaSkala
        
    }; // classFigur
    // Definicja czysto wirtualnego destruktora (tu: pusty).
    //Obowiązkowa!!! 
    //-> Na wypadek gdyby jakaś klasa pochodna
    //    nie zdefiniowała własnego destruktora!
    //    (Wtedy stałaby się klasą abstrakcyjną,
    //    bo destruktor zadeklarowaliśmy jako
    //    czysto wirtualny.)
    inline Figura::~Figura() {}
    
} // namespace MojeFigury

#endif // FIGURA_H
