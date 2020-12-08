#include <bits/stdc++.h>/// Librería dinámica
#ifndef PLAYER_H
#define PLAYER_H

using namespace std;

class Player{

  public:
    //Metodos
    Player();
    Player(int);//Bonus
    Player(int, string);//Nombre y posicion
    virtual ~Player();

    //Getters
    int getPosicion(){return posicion;}
    int getPosicionAnt(){return posicionAnt;}
    string getNombre(){return nombre;}
    int getNum_dado(){return num_dado;}
    char getTipoCasilla(){return tipo_casilla;}
    int getBonus(){return bonus;}
    int getTurno(){return turno;}
    //Setters
    void setPosicion(int);
    void setPosicionAnt(int val){
      posicionAnt=val;
    }
    void setNombre(string);
    void felicitaJugador(int);

    void setNum_dado(int val){num_dado=val;}
    void setTipoCasilla(char val){tipo_casilla = val;}
    void setBonus(int val){bonus = val;}
    void setTurno(int val){turno = val;}

    friend ostream& operator<< (ostream&,Player&);

    void operator+(int&);
    void operator-(int&);

      private:
    //Atributos
    int posicion;//Posicion Nueva despues del dado
    int posicionAnt;//Posicion antigua antes del dado
    string nombre;
    int num_dado;
    char tipo_casilla;
    int bonus;
    int turno;

};// Class closed

#endif // MYGAME_H
