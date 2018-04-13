//========================================================================================
// Practica Computabilidad y Algoritmia
// Autor Darwin Gonzalez Suarez
// Programa principal
//========================================================================================

#include <iostream>

using namespace std;

#include "dfa.hpp"
#include "status.hpp"


int main(void) {

  char f;
  system("clear");
  cout << endl;
    cout << "                                                                                                  " << endl;
    cout << "                                                                                                  " << endl;
    cout << "                                                                                                  " << endl;
    cout << "                                                                                                  " << endl;
    cout << "                          ___ AUTOMATAS FINITOS DETERMINISTAS(AFD-DFA) ___                   	   " << endl;
    cout << "                             COMPUTABILIDAD Y ALGORITMIA  2015-2016                               " << endl;
    cout << "                                																   " << endl;
    cout << "                         																		   " << endl;
    cout << "                               																   " << endl;
    cout << "                                          a             b                                         " << endl;
    cout << "                                  ►① ╦═════════ ►② ═════════ ►③                                 " << endl;
    cout << "                                     ║                        ║                                   " << endl;
    cout << "                                   b ║                      a ║                                   " << endl;
    cout << "                                     ║                        ║                                   " << endl;
    cout << "                                     ▼     b                  ║                                   " << endl;
    cout << "                                     ④ ═════════ ► ⑥          ▼                                   " << endl;
    cout << "                                     ║                        ⑦                                  " << endl;
    cout << "                                   a ║                                                            " << endl;
    cout << "                                     ║                                                            " << endl;
    cout << "                                     ▼                                                            " << endl;
    cout << "                                     ⑤                                                   			" << endl;
    cout << "                                  																   " << endl;
    cout << "                                    AUTOR: Darwin Gonzalez Suarez                                " << endl;
    cout << "                                                                                                  " << endl;
    cout << "                                                                                                  " << endl;
    cout << "                                                                                                  " << endl;
    cout << "                                                                                                  " << endl;
    cout << "                               Presione cualquier tecla para continuar.                           " << endl;
    cout << "                                                                                                  " << endl;
    cout << "                                                                                                  " << endl;
    cout << "                                                                                                  " << endl;

    f=getchar();
    system("clear");


	DFA_t dfa;
	dfa.start_menu();

	return 0;

}
