//======================================================================================== 
// Practica Computabilidad y Algoritmia
// Autor Darwin Gonzalez Suarez
// Declaración clase DFA_t
//========================================================================================

#pragma once

#include "status.hpp"
#include <iostream>
#include <set>
#include <fstream>
#include <algorithm>
#include <stdio.h>

using namespace std;

//!  Clase DFA_t.
/*!
  Una clase destinada a la declaración de atributos y metodos de la clase DFA_t
*/
class DFA_t
{

//! Atributos privados de la clase DFA_t
/*! En este apartado declaran las variables solo accecibles por metodos del objeto DFA_t */
private:

    //! num_total_stat_.
    /*!Declaración de una variable que contiene numero total de estados del DFA*/
    int num_total_stat_;

    //! stat_ini_.
    /*!Declaración de una variable que contiene numero del estado inicial o de partida*/
    int stat_ini_;

    //! stat_.
    /*!Declaración de una variable tipo estado que almacena un conjunto de posibles estados*/
    set<status_t> stat_;

//! Atributos y metodos publicos de la clase DFA_t
/*! En este apartado declaran los metodos publicos del objeto DFA_t */
public:

    DFA_t();//Metodo contructor del DFA(leer el DFA)
    ~DFA_t();//Metodo destructor del FDA()
    void create_DFA(char nombrefichero[]);
    void start();
    void show_DFA();//Metodo que muestre el DFA(mostrar el DFA)
    void ident_deathstat();//Metodo que identifique los estados de muerte
    void check_string();//Metodo que analice cadenas de caracteres y diga si la cadena es aceptada o no es aceptada
    void start_menu();   //Metodo que muestra el menu del DFA.



};
