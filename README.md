# Simulación DFA
Simulación de autómatas finitos deterministas codificada en c++ para la signatura de Computabilidad y Algoritmia en la Universidad de La Laguna.

Los pasos necesarios para la compilación y ejecución del programa son los siguientes:
``` r
 $ cd \src
 $ make
 $ ./test
```
El formato necesario de los DFA es el siguiente :

![dfa](https://github.com/DarwinGonzalez/simulation_DFA/blob/master/SimulacionDFA.jpg?raw=true)
Valoramos como estado de aceptación la segunda columna siendo de aceptación si se encentra a 1, y de no aceptación si se encuentra a 0.
```
4               //Número de estados del DFA
0               //Estado inicial
0 0 2 a 1 b 3   //Estado partida / Aceptación-Noaceptación / Estado / Símbolo con el que transita | Estado / Símbolo con el que transita
1 1 2 a 1 b 2
2 1 2 a 1 b 3
3 0 2 a 3 b 3
```


