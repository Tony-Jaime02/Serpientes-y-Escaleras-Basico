#include <bits/stdc++.h>/// Librer�a din�mica
#include "Casilla.h"

using namespace std;

Casilla::Casilla()
{
    tipo='N';
}

Casilla::Casilla(char t){
    tipo=t;
}

Casilla::~Casilla()
{
    //dtor
}

void Casilla::imprimirCasilla(){
    cout<<"Tipo de casilla: "<<tipo<<endl;
}
