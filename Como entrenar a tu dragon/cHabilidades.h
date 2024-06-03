#pragma once
#pragma once
#ifndef CHABILIDADES_H
#define CHABILIDADES_H

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

enum class combate { defensa = 0, ataque = 1 };//declaro mi enum de combate, para utilizarlo en mi funcion entrenar

class cHabilidades
{
private:
    unsigned int ataque;
    unsigned int defensa; //valor del 0 al 100, se obtiene con el método entrenar habilidades
    unsigned int salud;//valor del 0 al 100. por cada combate perdido baja 50 puntos. Al llegar al 0 se llama a funcion baja en la clase correspondiente


public:
    cHabilidades(const cHabilidades& otrasHabilidades); //constructor x copia

    cHabilidades();

    cHabilidades(unsigned int ataque, unsigned int defensa, unsigned int salud);

    ~cHabilidades(); //en .cpp

    /*El usuario elige si entrenar defensa o ataque, dependiendo lo que elija se le suma +3 puntos por cada entrenamiento.
    Sirve para dragon y/o vikingo*/
    void entrenar(combate habilidadaAentrenar);

    void combate(cHabilidades h_dragon, cHabilidades hab_vikingo); //en cpp

    void curandero();
    unsigned int get_salud() { return this->salud; }
    unsigned int get_ataque() { return this->ataque; }
    unsigned int get_defensa() { return this->defensa; }
};

#endif

