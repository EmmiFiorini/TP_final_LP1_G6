
#pragma once
#ifndef CVIKINGO_H
#define CVIKINGO_H

#include "cDragon.h"//cDragon tiene a cHabilidades, para q no nos pase como en IRI JAJAJ



class cVikingo : public cHabilidades
{
   protected:
    string nombre;
    string apellido;
    string posicion;
    string apodo;
    string fecha_nac;
    string level; //puño, arco y flecha, hacha, espada
    int contadorDragonesTerminados;//Cuenta la cantidad de veces que se ejecutó la funcion "combate" de la clase cHabilidades y ganó
   

   public:
    static int contVikingos;


    ~cVikingo();

    cVikingo(string nombre, string apellido, string posicion, string apodo, string fecha_nac, 
        int contadorDragonesTerminados,string level, unsigned int ataque, unsigned int defensa, 
        unsigned int salud);

    string to_string();
    void print();
    
    void set_trabajar(string posicion) {
        this->posicion = posicion;
    }
    string get_trabajar() {
        return this->posicion;
    }


    bool dragonesTerminados(); //true si mató a más de 1 dragón. false si no mato ninguno

    void nivel() override;
    void faltanteNuevoNivel() override;

    string get_nombre() { return this->nombre; } //se usa en cAdministradora:: PrintPeleaImagen
    string get_level() { return this->level; } //se usa en cAdministradora:: PrintPeleaImagen

    
   
};

#endif




