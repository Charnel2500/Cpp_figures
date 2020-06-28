// Plikfigura.h
// Klasa abstrakcyjna Figura dla figur geometrycznych
#include <string>
#include <iostream>
#include "program_figura.h"  // Plik nagłówkowy dla klasy Figura
#include "program_punkt.h"   // Plik nagłówkowy dla klasy Punkt
#include "program_odcinek.h"  // Plik nagłówkowy dla klasy Figura
#include "program_trojkat.h"   // Plik nagłówkowy dla klasy Punkt
#include "program_prostokat.h"  // Plik nagłówkowy dla klasy Figura
#include "program_okrag.h"   // Plik nagłówkowy dla klasy Punkt
#include "program_szablon.h"


using namespace std;

using namespace MojeFigury;

int main() {
    try {
        // deklaracje, definicje, instrukcje, wywołania funkcji, ...
    } catch(Odcinek::ZleKonce& zk) {
        // obsługa wyjątku dla konstruktora odcinka, np. 
        zk.Komunikat();
    } catch(Trojkat::ZleWierzcholki& zw) {
        // obsługa wyjątku dla konstruktora trójkąta
        zw.Komunikat();
    } catch(Prostokat::ZleBoki& zb) {
        // obsługa wyjątku dla konstruktora prostokąta
        zb.Komunikat();
    } catch(Okrag::ZlyPromien& zp) {
        // obsługa wyjątku dla konstruktora okręgu
        zp.Komunikat();
    } catch(Figura::ZlaSkala& zs) {
        // obsługa wyjątku dla metody skaluj()
        zs.Komunikat();
    } catch(...) { // domyślna obsługa wyjątków
      cerr << "Nieznany wyjątek" << endl;
      exit(1);
    }
    Odcinek odc1(Punkt(0,1), Punkt(0,3));
    odc1.rysuj();
    odc1.przesun(2,5);
    odc1.skaluj(3);
    odc1.rysuj();
    Odcinek* odc2 = new Odcinek(Punkt(2,6), Punkt(8,2));
    odc2->rysuj();
    odc2->przesun(4,1);
    odc2->skaluj(2);
    odc2->rysuj();
    
    Trojkat troj1(Punkt(0,1), Punkt(0,3), Punkt(1,3));
    troj1.rysuj();
    troj1.przesun(4,1);
    troj1.skaluj(2);
    troj1.rysuj();
    Trojkat* troj2 = new Trojkat(Punkt(1,2), Punkt(4,1), Punkt(5,5));
    troj2->rysuj();
    troj2->przesun(4,1);
    troj2->rysuj();
    troj2->skaluj(2);
    troj2->rysuj();
     
    
    Prostokat pros1(Punkt(3,1), 3, 5);
    pros1.rysuj();
    pros1.przesun(7,3);
    pros1.skaluj(7);
    pros1.rysuj();
    Prostokat* pros2 = new Prostokat(Punkt(1,2), 5, 2);
    pros2->rysuj();
    pros2->przesun(5,6);
    pros2->skaluj(5);
    pros2->rysuj();    

    Okrag okr1(Punkt(4,3), 25);
    okr1.rysuj();
    okr1.przesun(11,7);
    okr1.rysuj();
    okr1.skaluj(4);  
    okr1.rysuj();
    Okrag* okr2 = new Okrag(Punkt(15,3), 5);
    okr2->rysuj();
    okr2->przesun(4,2);
    okr2->skaluj(14);  
    okr2->rysuj();

    cout << "\n\n\n\n" << endl;

    
    
    Figura* wd[10];


    wd[0] = &odc1;
    wd[1] = &troj1;
    wd[2] = &pros1;
    wd[3] = &okr1;
    wd[4] = odc2;
    wd[5] = troj2;
    wd[6] = pros2;
    wd[7] = okr2;

    for(int i = 0; i <= 7; i++ )
    {
        wd[i]->rysuj();
    }
    cout << "\n\n\n\n" << endl;

    
    Tablica <Figura*> ti;          // tablica dla into rozmiarze 100
    cout << "Rozmiar tablicy ti= " << ti.rozmiar() << endl;
    
    ti[0] = &odc1;
    ti[1] = &troj1;
    ti[2] = &pros1;
    ti[3] = &okr1;
    ti[4] = odc2;
    ti[5] = troj2;
    ti[6] = pros2;
    ti[7] = okr2;
    
    for (int i = 0; i < ti.rozmiar(); i++) {
        ti[i] ->rysuj();
    }

    delete odc2; odc2 = 0; 
    delete troj2; troj2 = 0;
    delete pros2; pros2 = 0;
    delete okr2; okr2 = 0;
    
    return 0;
    
}
    
