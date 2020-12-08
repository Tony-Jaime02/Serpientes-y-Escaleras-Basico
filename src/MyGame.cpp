#include <bits/stdc++.h>/// Librería dinámica
#include "MyGame.h"
#include "CDado.h"
#include "Player.h"
#include "Casilla.h"

using namespace std;

Player Jugadores[2];
int num_jug;
int turn=1, num_player=0;
int limit;
string desicion, open="C",game="C",next, open_2, modo_juego="T";
int num_jugadores;
int Box,Lad,Serp,LadMas,SerpMenos;
char boxes2[10];



MyGame::MyGame() // CONSTRUCTOR
{
    //ctor
}

MyGame::~MyGame() // DESTRUCTOR
{
    //dtor
}

void printTurno(int t, int c_a, int d, char tile, int p, int m){
  cout<<t<<" "<<c_a<<" "<<d<<" "<< tile <<" "<<p+m<<"\n\n";
}

void MyGame::start(){

    cout<<"¿Cuantas casillas?"<<endl;
    cin>>Box;
    cout<<"¿Cuantas casillas de escaleras?"<<endl;
    cin>>Lad;
    cout<<"¿Cuantas casillas van a aumentar las escaleras?"<<endl;
    cin>>LadMas;
    cout<<"¿Cuantas casillas de serpientes?"<<endl;
    cin>>Serp;
    cout<<"¿Cuantas casillas van a retroceder las serpientes?"<<endl;
    cin>>SerpMenos;

    int CasEsp=Lad+Serp;

    Casilla *Tablero[Box];
    ////////////
    srand(time(0));// iniciando la semilla aleatoria

	int vectorCas[CasEsp];
	int Max=Box-LadMas-1;
	int Min=SerpMenos+1;
	for(int i=0;i<(CasEsp);i++)
	{
        // Genera numero aleatorio
       int num = Min + rand()%Max;
	   if(i>0){
	      // Verifica si no se ha generado antes
	      for(int j=0; j < i; j++)
	          if(num==vectorCas[j])
	          {
	             num = Min + rand()%Max;
	             j=-1;
	          }
		}
	    vectorCas[i]=num;
		cout<<vectorCas[i]<<endl;
	}

    ////////////
    for (int k = 0; k <= Box; k++){
        Tablero[k] = new Casilla();
    }
    ////////////
    int l=0;
    for (int i = 0; i <(CasEsp); i++){
        if ( i < Lad){
            Tablero[vectorCas[i]] = new Casilla('L');
        }
        else if (i >= Lad && l<Serp){
            Tablero[vectorCas[i]] = new Casilla('S');
            l++;
        }
    }
    for (int i = 0; i < Box; i++){
        cout<<i+1<<" ";
        Tablero[i]->imprimirCasilla();
    }
    /*char boxes2[Box];
      for(int i=0;i<=Box;i++){
        boxes2[i]='N';
      }
    */
    /////////////////////////////////NUMERO DE JUGADORES//////////////////////////////////////////
    cout<<"¿Cuantos jugadores?"<<endl;
    cin>>num_jugadores;
    Player Jugadores[num_jugadores];
    char nombre_i[100];
    for(int a = 0 ; a<num_jugadores ; a++){
        cout<<"Introduce the nickname of player "<<a+1<<": "<<endl;
        cin>>nombre_i;
        Jugadores[a].setNombre(nombre_i);
    }
    /////////////////////////////////lIMITE DE TURNOS/////////////////////////////////////////
    cout<<"¿Cual es el limite de turnos?"<<endl;
    cin>>limit;

    ////////////////////////////Automatico o Manual///////////////////////////////////////////
    while (modo_juego != "A" && modo_juego != "M"){
        cout<<"¿Automatico(A) o Manual(M)? Letras Mayusculas"<<endl;
        cin>>modo_juego;
    }

    CDado dado; //Declarando la variable "d" (objeto) dentro de la clase Cdado, la cual es un dado.

    cout << "Instructions:" << endl;
    cout << "Press C to continue next turn, or E to end the game: " << endl;

    while(open=="C"){ // Ciclo de open

      cin >> desicion;

      if(desicion == "C"){ // Condicion de desición 1)
        open_2 = open;
        cout << "Press C to play" << endl;

        while(open_2=="C" || turn<=(limit+1)){//Ciclo open_2

          if (modo_juego == "M"){
            cin >> next;
          }else if(modo_juego == "A"){
            next="C";
          }

          if(next=="C"){// 1.1)
            if(turn < (limit)){
              //DEVELOP OF ONE TURN

                  //////////////////////////////////////
                  int j=0;
                 while(j<=num_jugadores-1){
                    //DICE
                    int num_dado = dado.GetValorDado(); // Toma el random

                    int cas_Antigua = Jugadores[j].getPosicion();
                    Jugadores[j].setPosicion(cas_Antigua+num_dado);
                    Jugadores[j].setPosicionAnt(cas_Antigua);
                    Jugadores[j].setTurno(turn);
                    Jugadores[j].setNum_dado(num_dado);

                    int p_2 = Jugadores[j].getPosicion();

                    if(Tablero[p_2]->Gettipo()=='S' && p_2 < Box){
                      //SNAKEs
                      Jugadores[j].setTipoCasilla(Tablero[p_2]->Gettipo());
                      Jugadores[j].setBonus(SerpMenos);
                      Jugadores[j]-SerpMenos;//Sobrecarga de Operadores
                      cout<<Jugadores[j]<<endl;
                      turn++;
                    }
                    else if(Tablero[p_2]->Gettipo()=='N' && p_2<Box){
                      //NORMAL
                      Jugadores[j].setTipoCasilla(Tablero[p_2]->Gettipo());
                      Jugadores[j].setBonus(0);
                      cout<<Jugadores[j]<<endl;
                      turn++;
                    }
                    else if(Tablero[p_2]->Gettipo()=='L' && p_2<Box){
                      //LADDER
                      Jugadores[j].setTipoCasilla(Tablero[p_2]->Gettipo());
                      Jugadores[j].setBonus(LadMas);
                      Jugadores[j]+LadMas;//Sobrecarga de Operadores
                      cout<<Jugadores[j]<<endl;
                      turn++;
                    }

                    else if(p_2 >= Box){
                      Jugadores[j].felicitaJugador(Box);
                      modo_juego="M";
                      open = "?"; break;
                    }

                    if(j==num_jugadores){
                        j=0;
                    }
                    if(turn==limit){
                        break;
                    }
                    j++;
                 }   ////////////////////////////////////////////////////////////////
            }//"turn" if closed

            else if(turn==(limit)){
              cout << "The maximum number of turns has been reached..." << endl; open = "?"; break;
            }
          }

          else if(next=="E"){// END THE GAME
            cout << "Thanks for playing!!!" << endl;
            open = "?"; break;
          }
          else{// USER PRESSED WEIRD KEY
            cout << "Invalid option, please press C to continue next turn or E to end the game" << endl << endl;
          }// else closed
        }// "open_2" while closed
      }// 'desicion' if closed

      else if(desicion == "E"){ // 2)
        cout << "GAME OVER" << endl; break;

      }// 'desicion' else if closed

      else{ // USER PRESSED WEIRD KEY
        cout << "Invalid option, please press C to continue next turn or E to end the game" << endl << endl;
      }//'desicion' else closed

    }// 'End' while closed
}//
