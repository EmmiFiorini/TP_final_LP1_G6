
#pragma once
#ifndef CVIKINGO_H
#define CVIKINGO_H

#include "cDragon.h"//cDragon tiene a cHabilidades, para q no nos pase como en IRI JAJAJ
enum class VformaDeAtaque { nulo = 0, Vpunyo = 1, Varco = 2, Vhacha = 3 };


class cVikingo
{
   private:
    string nombre;
    const string apellido;
    string posicion;
    VformaDeAtaque nivel;
    int contadorDragonesTerminados;//Cuenta la cantidad de veces que se ejecutó la funcion "combate" de la clase cHabilidades y ganó
    cHabilidades* habilidades;

   public:
    static int contVikingos;

    cVikingo() : apellido("") { //constructor nulo
        this->nombre = "";
        this->posicion = "";
        this->contadorDragonesTerminados = 0;
        this->nivel = VformaDeAtaque::nulo;
        this->habilidades = new cHabilidades(); //me creo un objeto dinámico de habilidades
        contVikingos++;
    }

    ~cVikingo(); //en cpp


    cHabilidades* get_habilidades() {
        return this->habilidades;
    }


    cVikingo(string nombre, string apellido, string posicion, int contadorDragonesTerminados, cHabilidades* habilidades, VformaDeAtaque nivel);

    string to_string();
    void print();
    void set_trabajar(string posicion) {
        this->posicion = posicion;
    }

    string get_trabajar() {
        return this->posicion;
    }

    bool dragonesTerminados(); //true si mató a más de 1 dragón. false si no mato ninguno


    // ACLARACIÓN: nuestra idea es que actualizarFormaAtaque sea una sola función, útil tanto para dragón como para vikingo(debería ser virtual y, por lo tanto,
    // cHabilidades sería una clase abstracta).Lo vamos a modificar cuando entendamos mejor el tema!!!

    void V_actualizarFormaDeAtaque();

    void AnularVikingo();

    void V_baja();
};

#endif

