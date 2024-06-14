
#pragma once
#ifndef CVIKINGO_H
#define CVIKINGO_H

#include "cDragon.h"//cDragon tiene a cHabilidades, para q no nos pase como en IRI JAJAJ
//typedef enum { nada = 0, Vpunyo = 1, Varco = 2, Vhacha = 3 } VformaDeAtaque;


class cVikingo : public cHabilidades
{
   protected:
    string nombre;
    string apellido;
    string posicion;
    string apodo;
    string fecha_nac;
    string level;

    //VformaDeAtaque nivel;
    int contadorDragonesTerminados;//Cuenta la cantidad de veces que se ejecutó la funcion "combate" de la clase cHabilidades y ganó
   

   public:
    static int contVikingos;

   /* cVikingo() : cHabilidades(){ //constructor nulo
        this->nombre = "";
        this->apellido = "";
        this->posicion = "";
        this->apodo = "";
        this->fecha_nac = "";
        this->level = "";
        //this->nivel = ;
        this->contadorDragonesTerminados = 0;
        //this->nivel = VformaDeAtaque::nada;
        contVikingos++;
    }*/

    ~cVikingo(); //en cpp

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

    string get_nombre() { return this->nombre; }

    void faltanteNuevoNivel() override;
};

#endif




