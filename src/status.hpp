//========================================================================================
// Practica Computabilidad y Algoritmia
// Autor Darwin Gonzalez Suarez
// Declaración clase status_t
//========================================================================================


#pragma once

#include <iostream>
#include <stdio.h>


using namespace std;

//!  Clase status_t.
/*!
  Una clase destinada a la declaración de atributos y metodos de la clase DFA_t
*/
class status_t
{
    friend std::ostream &operator<<(std::ostream &,const status_t &);

//! Atributos privados de la clase status_t
/*! En este apartado declaran las variables solo accecibles por metodos del objeto status_t */
public:

  //! status_id_.
  /*!Declaración de una variable que contiene numero identificador de estado*/
	int status_id_;

  //! num_trans_.
  /*!Declaración de una variable que contiene numero de transciciones que tiene el estado*/
	int num_trans_;

  //! num_acept_.
  /*!Declaración de una variable que contiene numero que determina el valor es de aceptacion o no*/
	bool num_acept_;

  //! symbol_.
  /*!Declaración de una variable puntero que contiene simbolo de entrada*/
  char *symbol_;

  //! destin_.
  /*!Declaración de una variable puntero que contiene Estado estino de llegada*/
  int *destin_;

  status_t();                               //Metodo constructor por defecto de la clase estado
  status_t(int,bool,int,char*,int*);        //Metodo constructor con el paso de los parametros objetos de la clase estado
  status_t(const status_t &);               //Metodo constructor de copia
  ~status_t();

  //Sobrecarga de operadores obtenidos de los ficheros elements dados por el profesor
  status_t &operator=(const status_t &rhs);    //Sobrecarga operador '='
  int operator==(const status_t &rhs) const;   //Sobrecarga operador '=='
  int operator<(const status_t &rhs) const;    //Sobrecarga operador '<'



};
