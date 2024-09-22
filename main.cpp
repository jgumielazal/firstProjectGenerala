#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <ctime>
#include <Windows.h>
#include <string.h>

using namespace std;
#include "FuncionesGenerala.h"

//MAIN GENERALA
int main () {
    ///vector tabla de puntos del jugador 1 y 2; dados (5); dados repetidos, tirada de dados;
    int JugadorUno[10]{}, JugadorDos[10]{}, Lanzamientos[2], PuntajeMax=0, ScoreAux1=0, ScoreAux2=0;
    char NombreJ1 [30], NombreJ2[30]={};

    while(true){
        int opc;
        bool f=true;
        Menu();
        cin>>opc;
        system("cls");
        switch (opc){
        case 1:
            PartidaJ1(NombreJ1, 30, JugadorUno, 10, ScoreAux1);
            break;
        case 2:
            PartidaJ2(NombreJ1, 30, JugadorUno, 10, NombreJ2, 30, JugadorDos, 10, ScoreAux1, ScoreAux2);
            system("cls");
            break;
        case 3:
            Estadisticas(PuntajeMax, ScoreAux1, ScoreAux2, NombreJ1, 30, NombreJ2, 30);
            system("cls");
            cout << "opc 3" << endl;
            break;
        case 0:
            return 0;
        default:
            cout << "INGRESE UNA OPCION INCORRECTA" << endl;
        }
        system("pause");
        system("cls");
    }
}
