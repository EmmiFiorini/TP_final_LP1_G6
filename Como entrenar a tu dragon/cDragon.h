#pragma once

//me creo mi .h de dragon
#ifndef CDRAGON_H
#define CDRAGON_H


#include "cHabilidades.h"

//defino mis enums:

typedef enum { desconocido = 0, mini = 1, chico = 2, mediano = 3, grande = 4, gigante = 5 } tamanio;
typedef enum { nulo = 0, Dmorder = 1, Dalas = 2, Dgarras = 3 } formaDeAtaque;

class cDragon
{
private:
    string nombre;
    string caracteristica;
    tamanio tam;
    string color;
    bool estado;
    cHabilidades* habilidades; //objeto de la clase habilidades
    formaDeAtaque nivel;

public:
    ~cDragon();

    cDragon();

    cDragon(string nombre, string caracteristica, tamanio tamanyoDragon, string color, bool estado, cHabilidades& habilidades, formaDeAtaque nivel); //constructor por parametros

    void set_nombre(string nombre) { //se modifica el nombre del dragón
        this->nombre = nombre;
    }
    bool domado(bool estado) {
        this->estado = estado; //true si está domado, false si no lo está
    }
    void set_caracteristica(string caracteristica) {
        this->caracteristica = caracteristica;
    }

    string to_string();

    void print() {
        cout << to_string() << endl;
    }

    void D_actualizarFormaDeAtaque();


    void D_baja();

    cHabilidades* get_habilidades();
};

#endif