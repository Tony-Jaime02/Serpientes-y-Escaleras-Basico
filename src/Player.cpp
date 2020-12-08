#include <bits/stdc++.h>/// Librería dinámica
#include "Player.h"
#include "MyGame.h"
#include "CDado.h"

using namespace std;

//Constructores
Player::Player(){   // Construtor por omisión
  //getline(cin,nombre = "Fulanito");
  nombre = "Omision";
  posicion = 1;
  num_dado=1;
  tipo_casilla='N';
  bonus=0;
}

Player::Player(int n, string laCadena){ // Constructor especifo
  nombre = laCadena;
  posicion = n;
}

Player::Player(int b){
    bonus = b;
}

Player::~Player() // Destructor
{
    //dtor
}

//Setters
void Player::setPosicion(int n){
  posicion = n;
}
void Player::setNombre(string laCadena){
  nombre = laCadena;
}

//Getters

//Funciones
void Player::felicitaJugador(int n){
  cout << "\n   --- GAME OVER ---\nPlayer " << nombre << " is the winner!!!" << endl;
  posicion = n;
  cout << "Position: " << posicion << endl;
}

ostream& operator<<(ostream& salida, Player& f){

  salida<<f.getNombre()<<" "<<f.getTurno()<<" "<<f.getPosicionAnt()<<" "<<f.getNum_dado()<<" "<<f.getTipoCasilla()<<" "<<f.getBonus()<<" "<<f.getPosicion()<<endl;
  return salida;
}

void Player::operator+(int &b){

    setPosicion(getPosicion() + b);


}

void Player::operator-(int &f){

    setPosicion(getPosicion() - f);

}
