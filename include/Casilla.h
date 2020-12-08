#include <bits/stdc++.h>/// Librería dinámica

#ifndef CASILLA_H
#define CASILLA_H

using namespace std;

class Casilla
{
    public:
        Casilla();
        virtual ~Casilla();
        Casilla(char);

        char Gettipo() { return tipo; }
        void Settipo(char val) { tipo = val; }

        virtual void imprimirCasilla();

    private:
        char tipo;
};

#endif // CASILLA_H
