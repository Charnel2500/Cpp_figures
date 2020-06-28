// Plik punkt.h
// Klasa Punkt do reprezentowania punktu na płaszczyźnie
#ifndef PUNKT_H
#define PUNKT_H

#include <iostream>
#include <cstdlib>

namespace MojeFigury {
    
    
    class Punkt {   
        double x, y;    // wspolrzedne x i y
    public:
        // Konstruktor
        Punkt(double a = 0, double b = 0): x(a), y(b) {}
        // Funkcja zwracająca współrzedną x
        double dajX() const{ return x; }
        // Funkcja zwracająca współrzedną y
        double dajY() const{ return y; }
        // Funkcja do przesuwania punktu na płaszczyźnie 
        // o wektor (dx,dy)
        void przesun(double dx, double dy);
        // Funkcja do skalowania punktu -pusta
        void skaluj(double s) {}
        // Przeładowanie operatorów relacyjnych: == i !=
        friend bool operator==(const Punkt&, const Punkt&);
        friend bool operator!=(const Punkt&, const Punkt&);
        // Przeładowanie operatorów strumieniowych: << i >>
        friend std::ostream& operator<<(std::ostream&,const Punkt&);
        friend std::istream& operator>>(std::istream&, Punkt&);
    }; // classPunkt
    
    //-----------Funkcje inline--------------------------
    // Funkcja do przesuwania punktu na płaszczyźnie
    // o wektor (dx,dy)
    inline void Punkt::przesun(double dx,  double dy) { 
        x += dx; 
        y += dy; 
    } 
    //===== Przeładowanie operatorów relacyjnych =========
    inline bool operator==(const Punkt& a, const Punkt& b)
    {
        return (a.x== b.x) && (a.y== b.y);
    }
    inline bool operator!=(const Punkt& a, const Punkt& b)
    {
        return (a.x!= b.x) || (a.y!= b.y);
    }
//===== Przeładowanie operatorów strumieniowych =======

inline std::ostream& operator<<(std::ostream& wy, const Punkt& p)
{
    wy << '(' << p.x<< ',' << p.y<< ')';
    return wy;
    
} //operator<<

inline std::istream& operator>>(std::istream& we, Punkt& p)
{
    char c;
    we >> c;
    if (c != '(') {
        std::cerr<< "Operator >>: Nieprawidlowyformat punktu!" 
                 << std::endl;
            std::exit(1);
    }
    we >> p.x;
    we >> c;
    if (c != ',') {
        std::cerr << "Operator >>:  Nieprawidlowyformat punktu!"                
<< std::endl;
        std::exit(2);
    }
    we >> p.y;
    we >> c;
    if (c != ')') {
        std::cerr << "Operator >>:  Nieprawidlowyformat punktu!" 
                  << std::endl;
        std::exit(3);
    }
    return we;
} // operator >>    
} // namespace MojeFigury
#endif // PUNKT_H
