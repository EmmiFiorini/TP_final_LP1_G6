#pragma once
#pragma once
#ifndef CHABILIDADES_H
#define CHABILIDADES_H

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;

//declaro mi enum de combate, para utilizarlo en mi funcion entrenar

class cHabilidades
{
protected:
    unsigned int ataque;
    unsigned int defensa; //valor del 0 al 100, se obtiene con el método entrenar habilidades
    unsigned int salud;//valor del 0 al 100. por cada combate perdido baja 50 puntos. Al llegar al 0 se llama a funcion baja en la clase correspondiente


public:
    cHabilidades(const cHabilidades& otrasHabilidades); //constructor x copia

    cHabilidades();

    cHabilidades(unsigned int ataque, unsigned int defensa, unsigned int salud);

    virtual ~cHabilidades() {}; //destructor virtual porque es una clase virtual pura

    void entrenar(bool habilidadaAentrenar);

    void curandero();

    unsigned int get_salud() { return this->salud; } //aparece en cAdministradora::combate
    unsigned int get_ataque() { return this->ataque; } //aparece en cAdministradora::combate
    unsigned int get_defensa() { return this->defensa; } //aparece en cAdministradora::combate

    void set_salud(unsigned int nuevaSalud) { //aparece en cAdministradora::combate
        this->salud = nuevaSalud;
    }

    virtual void nivel() = 0;//funcion virtual pura
    virtual void faltanteNuevoNivel() = 0; //funcion virtual pura
    
    int formaDeAtaque();
};

#endif

