#ifndef FUNCIONESGENERALA_H_INCLUDED
#define FUNCIONESGENERALA_H_INCLUDED

///PROTOTIPOS PARA GENERALA

void InicializarEnCero(int *v,int t);
void CargarCadena(char *pal, int tam);
void Menu();
void Submenu();
int TirarDado();
void Tirada(int *v, int cant); //simula una cantidad de tiradas (dentro contiene TirarDado() y asigna el valor al vector de dados
void LanzarDados(int v[], int t); // Lanza 5 dados de una o reemplaza en todas las posciones que hay 0
void OrdenarMenorAMayor(int *v, int tam);

void ReemplazarDados (int vDados[],int t);
void MostrarVector(int v[],int t);
void NotarPatrones(int v[], int t, int *v2, int t2);
int PuntajesEspeciales(int *v, int tam); //Obtiene el valor de las condiciones especiales del juego (Poker, Full House, Escalera, Generala)
void OpcionesCargarDatos(int *v, int t, int *v2, int t2, int *v3, int t3); //rellena el vector de puntajes

void PartidaJ1(char *NombreJ1, int tam, int *v, int tam2, int &Score);
void PartidaJ2(char *Nj1,int t1,int *JugadorUno,int t2,char *Nj2,int t3, int *JugadorDos, int t4, int &S1, int &S2);

void Estadisticas (int &PuntajeMax, int ScoreAux1, int ScoreAux2);
///DESARROLLO:

void CargarCadena(char *pal, int tam){
  int i;
  fflush(stdin);
  for(i=0;i<tam;i++){
      pal[i]=cin.get();
	  if(pal[i]=='\n') break;
	  }
  pal[i]='\0';
  fflush(stdin);
}

void InicializarEnCero(int *v,int t){
    int i;
    for(i=0;i<t;i++){
        v[i]=0;
    }
}

void Submenu(){
        cout << "Menu de dados" << endl;
        cout << "===================" << endl;
        cout << "1. Reemplazar Valores Obtenidos" << endl;
        cout << "2. Tachar Combinacion" << endl;
}

void Menu(){
        cout << "=====MENU PRINCIPAL======" << endl;
        cout << "=========================" << endl;
        cout << "1) Juego nuevo de a 1" << endl;
        cout << "2) Juego nuevo de a 2." << endl;
        cout << "3) Mostrar puntuacion mas alta." << endl;
        cout << "=========================" << endl;
        cout << "Salir 0." << endl;
}

int TirarDado(){
    int numdado , caras=6;
    Sleep(780);
    srand(time(NULL));
    numdado = 1+(rand()%caras);
    /*
    cout << endl << numdado << endl;
    if (numdado==1){
    cout << "+-------+" << endl << "|       |" << endl << "|   O   |" << endl << "|       |" << endl << "+-------+" << endl;
    }
    if (numdado==2){
    cout << "+-------+" << endl << "| O     |" << endl << "|       |" << endl << "|     O |" << endl << "+-------+" << endl;
    }
    if (numdado==3){
    cout << "+-------+" << endl << "| O     |" << endl << "|   O   |" << endl << "|     O |" << endl << "+-------+" << endl;
    }
    if (numdado==4){
    cout << "+-------+" << endl << "| O   O |" << endl << "|       |" << endl << "| O   O |" << endl << "+-------+" << endl;
    }
    if (numdado==5){
    cout << "+-------+" << endl << "| O   O |" << endl << "|   O   |" << endl << "| O   O |" << endl << "+-------+" << endl;
    }
    if (numdado==6){
    cout << "+-------+" << endl << "| O   O |" << endl << "| O   O |" << endl << "| O   O |" << endl << "+-------+" << endl;
    }*/
    return numdado;
}

void LanzarDados(int Dados[], int t){
    int i, ContCeros=0;
    ///contar ceros dentro del vector para lanzar correctamente
    for(i=0;i<t;i++){
        if (Dados[i]==0){
            ContCeros++;
        }
    }

    /// generacion de numero aleatorio de 1 a 6 para simular dados en base a tiempo
    srand(time(0));
    for(int i=0;i<ContCeros;i++){
        int resultado=(rand()%6)+1;

        /// cargo vector
        if(Dados[i]==0){
            Dados[i]=resultado;
        }

    }
}

void Tirada(int *v, int cant){
    int i;
    cout<< "Tirando dados..."<<endl;
    for(i=0;i<cant;i++){
        v[i]=TirarDado();
    }
}

void OrdenarMenorAMayor(int *P, int cant){
    int aux;
    for(int i=1;i<cant;i++){
        for(int j=0;j<cant-1;j++){
            if (P[j] > P[j+1]){
                aux=P[j];
                P[j]=P[j+1];
                P[j+1]=aux;
            }
        }
    }
}

/*jugadno se pregunta si se quiere anotar el puntaje obtenido o seguir tirando dados para tirar nuevamente 1 dado hasta 2 veces pregunta (original, tirada 2 y tirada 3)
se puede anular combinaciones (ej la generala si es que no se piensa que se puede sacar para sumar mas puntos)



otras{
    rondas a jugar elegir por nro
    dados simulados para simular
    GENERALA (5 IGUALES) Victoria inmediata
    ronda 3 tiradas por persona.
    Tira 5 dados, pregunta cuales quiere volver a tirar y reemplazar hasta maximo 2
    Tras cada tirada se anota la puntuacion
    si se saca generala se gana la partida. pero si hay 2 personas si se comienza con una generala servida se le da oportunidad al 2do jugador de empatar con otra generala servida
}

*/

void ReemplazarDados (int vDados[],int t){
    int PosDado=20, Cont=0;
    cout<<endl<<"Indique posicion de dado // 9 para reelanzar todos // 0 para terminar de elegir"<<endl;
    //reemplazar de uno en uno el vector de Dados por cero;
    while (PosDado!=0){
        cout<<endl<<">>";
        cin>>PosDado;
        if ((PosDado!=0)&(PosDado!=9)){
            vDados[PosDado-1]=0;
            Cont++;
        }
        if(PosDado==9){
            InicializarEnCero(vDados,5);
            PosDado=0;
        }
    }
}

/*
void ReemplazarDados (int vDados[],int t){
    int PosDado, CantReemplazo;
    cout<<"Cuantos dados desea reemplazar? (de 1 a 5)"<<endl;
    cin>>CantReemplazo;

    for(int i=0;i<CantReemplazo;i++){
    cout <<"Indica la posicion del dado que quieres reemplazar "<<endl;
    cin>>PosDado;
    vDados[PosDado-1]=TirarDado();
    }
    system("pause");
}*/

void NotarPatrones(int v[], int t, int *v2, int t2){
    ///int patron[6]{};
    for(int i=0;i<5;i++){
        v2[v[i]-1]++;
    }
}

void MostrarVector(int v[],int t){
    for(int i=0;i<t;i++){
        cout<<v[i]<<"\t"<<endl;
    }
}

int PuntajesEspeciales(int *v, int tam){ //tomo el vector de repeticiones de 1 a 6 cuantas veces se repite
    int i,c=0;
    for(i=0;i<tam;i++){
        if(v[i]==5){
        cout << "Generala!" << endl;
        return 50;
        }
    }
    for(i=0;i<tam;i++){
        if(v[i]==4){
        cout << "Poker!" << endl;
        return 40;
        }
    }
    for(i=0;i<tam;i++){
        if(v[i]==3){
            for(int i=0;i<tam;i++){
                if(v[i]==2){
                    cout<< "Full House!" <<endl;
                    return 30;
                }
            }
        }
    }
    for(i=0;i<tam;i++){
        if(v[i]==1) c++;
    }
    if(c==5) cout << "Escalera!" <<endl;
    return 25;
}

void OpcionesCargarDatos(int *v, int t, int *v2, int t2, int *v3, int t3){

    ///A) Calcular y mostrar las opciones posibles
    int i, dice, puntos,opcionMenu=1;
    ///B) F while para ingresar en vector opciones y desp puntaje
    int opcion_elegida, busq=0, pos=0;

    ///A
    cout<<"Elija una opcion: "<<endl;
    for(i=0;i<6;i++){
        dice=i+1;
        puntos=dice*v[i];
        if((puntos>0)&&(v3[i]==0)){
            v2[i]=puntos;
            cout<<opcionMenu<<")"<<"anotar "<<puntos<<" puntos al "<<dice<<endl;

            opcionMenu++;
        }
    }
    cout<<endl<<">>";

    ///B)
    cin>>opcion_elegida;
    ///F while que solo contabiliza los puntos posibles
    while(busq<opcion_elegida){
        if(v2[pos]>0){
            busq++;
        }
        pos++;
    }
    ///solo ubica correctamente si le resto 1 a posicion post-ciclo
    pos--;
    v3[pos]=v2[pos];
}

void TacharPuntos(int Score[],int t){
    ///obligatorio que este por encima de CalcMostrarOpciones
    //funcion que busca los 0 en el Score para tachar alguno
    //misma logica utilizada que en CargarPuntaje; pero invertida.
    int i,opcion=1, OpcionTachar;
    cout<<"Eliga una opcion a tachar"<<endl;
    for(i=0;i<t;i++){
        if(Score[i]==0){
            cout<<opcion<<")_Tachar ";
            opcion++;
            if(i<6)
                cout<<"Juego de "<<i+1<<"."<<endl;;

            if(i>=6){
                if(i==6)
                    cout<<"Escalera."<<endl;;
                if(i==7)
                    cout<<"Full"<<endl;;
                if(i==8)
                    cout<<"Poker"<<endl;;
                if(i==9)
                    cout<<"Generala"<<endl;;
            }
        }

    }
    cout<<">>";
    cin>>OpcionTachar;
    int  busq=0, pos=0;
    while(busq<OpcionTachar){
        if(Score[pos]==0){
            busq++;
        }
        pos++;
    }
    ///solo ubica correctamente si le resto 1 a posicion post-ciclo
    pos--;
    Score[pos]=-1;
}

void CalcMostrarOpciones(int *Repetidos6, int t, int *PosiblesPuntos, int t2, int *Score, int t3, int &OpcionElegida){

    ///A) Calcular y mostrar las opciones posibles
    int i, Dice, puntos,opcionMenu=1, Intento=3;

    bool Escalera=false, Full=false, Poker=false, Generala=false;

    ///A
    cout<<"Jugadas posibles:"<<endl;
    for(i=0;i<6;i++){
        Dice=i+1;
        puntos=Dice*Repetidos6[i];
        if((puntos>0)&&(Score[i]==0)){
            PosiblesPuntos[i]=puntos;
            cout<<opcionMenu<<")"<<"anotar "<<puntos<<" puntos al "<<Dice<<endl;

            opcionMenu++;
        }
    }

    ///Puntajes especiales
    int c=0;

    //Escalera 25
    for(i=0;i<t;i++){
        if(Repetidos6[i]==1) c++;
    }
    if(c==5)
        Escalera=true;
    if((Escalera==true)&& (Score[6]==0)){
        cout<<opcionMenu<<")_Anotar Escalera: 25 puntos"<<endl;
        PosiblesPuntos[6]=25;
    }
    //Full 30
    for(i=0;i<t;i++){
        if(Repetidos6[i]==3){
            for(int i=0;i<t;i++){
                if(Repetidos6[i]==2) Full=true;
                }
        }
    }
    if((Full==true)&& (Score[7]==0)){
    cout<<opcionMenu<<")_Anotar Full: 30 puntos"<<endl;
    PosiblesPuntos[7]=30;
    }
    //Poker 40
    for(i=0;i<t;i++){
        if(Repetidos6[i]==4){
        Poker=true;
        }
    }
    if((Poker==true)&& (Score[8]==0)){
        cout<<opcionMenu<<")_Anotar Poker: 40 puntos"<<endl;
        PosiblesPuntos[8]=40;
    }
    //Generala 50
    for(i=0;i<t;i++){
        if(Repetidos6[i]==5){
        Generala=true;
        }
    }
    if((Generala==true)&& (Score[9]==0)){
        cout<<opcionMenu<<")_Anotar Generala: 50 puntos"<<endl;
        PosiblesPuntos[9]=50;
        //opcionMenu++;

    }

    if(Intento==3){

    cout<<"0)_Tachar"<<endl;
    }


    cout<<"Elija una opcion"<<endl<<">>";
    cin>>OpcionElegida;
    if(OpcionElegida==0)
        TacharPuntos(Score,t3);
}

void PartidaJ1(char *NombreJ1, int tam, int *v, int tam2, int &Score){
    int pos=0, Dados[5]={};
    bool f=true, g=true;
    cout << "Ingrese el nombre del jugador: "<< endl;
    CargarCadena(NombreJ1,29);
    system("cls");
    while(f==true){
        pos++;
        cout << "Jugador: " << NombreJ1 << "                Score: ";  //GOTOXY
        MostrarVector(v,tam2);
        cout << endl;

        /*int cant;
        cout << "Cantidad de dados a tirar: " << endl;
        cin >> cant;*/
        Tirada(Dados,5);
        OrdenarMenorAMayor(Dados,5);
        MostrarVector(Dados,5);
        while(g==true){
            int opc;
            Submenu();
            cin>>opc;
            system("cls");
            switch(opc){
            case 1:
                system("cls");
                ReemplazarDados(Dados,5);
                break;
            case 2:
                system("cls");
                //TacharScore();
                break;
            default:
                cout << "INGRESE UNA OPCION INCORRECTA"<<endl;
            }
            system("pause");
            system("cls");
            g=false;
            OrdenarMenorAMayor(Dados,5);
            MostrarVector(Dados,5);
        }
         //muestra el vector de dados ya ordenado luego del reemplazo
        if(pos>=3) f=false;
    }
    ///SUMATORIA //LANZAMIENTOS //
}

void PartidaJ2(char *Nj1,int t1,int *JugadorUno,int t2,char *Nj2,int t3, int *JugadorDos, int t4, int &S1, int &S2){

}

void Estadisticas (int &PuntajeMax, int ScoreAux1, int ScoreAux2, char *n1, int t, char *n2, int t2=1){
    char Campeon[30];
    if(PuntajeMax<ScoreAux1 && ScoreAux2==0){
        strcpy(Campeon, n1);
    }
    if(ScoreAux1<ScoreAux2){
        strcpy(Campeon, n2);
    }
    cout << Campeon << " Obtuvo un score maximo de: " << PuntajeMax;
}

#endif // FUNCIONESGENERALA_H_INCLUDED
