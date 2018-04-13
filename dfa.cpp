//========================================================================================
// Practica Computabilidad y Algoritmia
// Autor Darwin Gonzalez Suarez
// Implementacion clase DFA_t
//========================================================================================

#include "dfa.hpp"
#include <string.h>

using namespace std;


//Metodo contructor del DFA por defecto
DFA_t::DFA_t(void){}

//Metodo constructor por paso de fichero de la clase DFA
void DFA_t::create_DFA(char nombrefichero[]) {

	  ifstream file;
    int id_,trans_;
    bool acept_;
    int *destino;
    char *simbolo;

	file.open(nombrefichero);

	if(file.is_open()==1) {

        while(!file.eof()) {

        	file >> num_total_stat_;
        	file >> stat_ini_;

            for(int i=0;i<num_total_stat_;i++) {

                file>>id_>>acept_>>trans_;
                simbolo = new char[trans_];
                destino = new int[trans_];

                for(int j=0;j<trans_;j++){
                    file>>simbolo[j]>>destino[j];
                }

            status_t aux(id_,acept_,trans_,simbolo,destino);
            stat_.insert(aux);

            }

        if(stat_.size()==num_total_stat_) {

            cout<<"Automata cargado correctamente"<<endl;
        }

     file.close();
	}

	}
	else
    {

    cout << "Fichero inexistente" << endl;

    }



}

//Metodo destructor del FDA()
DFA_t::~DFA_t(){}


//Metodo que muestre el DFA(mostrar el DFA)
void DFA_t::show_DFA() {

     cout<<endl<<endl;
     cout<<"-----------------------------------"<<endl;
     cout<<"El DFA actual es : "<<endl;
     cout<<"Numero total de estados del DFA: "<<num_total_stat_<<endl;
     cout<<"Estado inicial o de partida del DFA: "<<stat_ini_<<endl;
     cout<<endl;

     for(set<status_t>::iterator i=stat_.begin();i!=stat_.end();i++) {

        cout<<(*i);
     }

     cout<<endl;
     cout<<"-----------------------------------"<<endl;

}


//Metodo que identifique los estados de muerte
void DFA_t::ident_deathstat() {

    bool existe=false;

    for(set<status_t>::iterator i=stat_.begin();i!=stat_.end();i++) {
        int cont=0;
        status_t aux;
        aux=(*i);
        for(int j=0;j<aux.num_trans_;j++) {
            if(aux.destin_[j]==aux.status_id_) {
                cont++;
            }
        }
      if(cont==aux.num_trans_) {
      	cout<<endl;
        cout<<"El estado "<<aux.status_id_<<" es un estado de muerte del DFA."<<endl;
        cout<<endl;
        existe=true;
      }
    }

    if(existe==false) {
        cout<<"No existen estados de muerte en este DFA"<<endl;
    }
}


//Metodo que analice cadenas de caracteres y diga si la cadena es aceptada o no es aceptada
void DFA_t::check_string() {

    char cadena[85];
    cout<<"Introduzca la cadena de caracteres a comprobar: "<<endl;
    cin>>cadena;
    cin.ignore();

    int actual_state=stat_ini_;
    int next_stat= stat_ini_;
    bool acept_;

    cout<<endl;
    cout<<"---------------------------------------------"<<endl;

    cout<<"|ESTADO ACTUAL|\t"<<"ENTRADA\t| "<<"SIGUIENTE ESTADO  |"<<endl;

    for(int j=0;j<strlen(cadena);j++) {
        actual_state=next_stat;

        for(set<status_t>::iterator i=stat_.begin();i!= stat_.end();i++) {
            status_t aux;
            aux=(*i);

            if(aux.status_id_==actual_state) {
                for(int k=0;k<aux.num_trans_;k++) {
                    if(cadena[j]==aux.symbol_[k]){
                        next_stat=aux.destin_[k];
                    }
                }
            }
        }

    cout<<"|"<< actual_state<<"\t      |\t"<<cadena[j]<<"\t| "<<next_stat<<"                 |"<<endl;
    cout<<"---------------------------------------------"<<endl;


    }

   for(set<status_t>::iterator i=stat_.begin();i!= stat_.end();i++) {
       status_t aux;
       aux=(*i);

       if(aux.status_id_==next_stat) {
        acept_=aux.num_acept_;
       }
   }

   if(acept_==true) {
   	cout<<endl;
    cout<<"La cadena introducida -> "<<cadena<< "<- es aceptada por el DFA introducido."<<endl;
    cout<<endl;
   }
   else {
   	cout<<endl;
    cout<<"La cadena introducida -> "<<cadena<< " <- no es aceptada por el DFA introducido."<<endl;
    cout<<endl;
   }


}

void DFA_t::start_menu() {
    int option;
    char nombrefichero[80];

       system("clear");

    while(option!=5) {

      cout <<
        "Elija solo una de las siguientes opciones\n"
        "[1].Introduzca el nombre del fichero.\n"
        "[2].Mostrar el dfa por pantalla\n"
        "[3].Mostrar los estados de muerte del dfa\n"
        "[4[.Introducir una entrada al dfa\n"
        "[5].Salir" << endl;
      cin >> option;
      switch (option) {

      case 1: {
              cout<<">> Introduzca el nombre del fichero: "<<endl;
              cin>>nombrefichero;
              create_DFA(nombrefichero);
      break;
      }
      case 2:{
              show_DFA();
      break;
      }

      case 3: {
              ident_deathstat();
      break;
      }

      case 4:{
              check_string();
      break;
      }

      case 5:{
      cout<<"Saliendo del programa...." <<endl;
      break;
      }
      }

    }
}
