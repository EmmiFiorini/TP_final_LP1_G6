#pragma once

//me creo mi .h de dragon
#ifndef CDRAGON_H
#define CDRAGON_H


#include "cHabilidades.h"

//defino mis enums:

typedef enum { desconocido = 0, mini = 1, chico = 2, mediano = 3, grande = 4, gigante = 5 } tamanio;


class cDragon : public cHabilidades
{
protected:
    string nombre;
    string caracteristica;
    tamanio tam;
    string color;
    bool estado;
    string level;  //1) morder, 2) morder y golpear con alas, 3) morder, golpear con alas y rasguñar, 4)  morder, golpear con alas, rasguñar y lanzar fuego

public:
    ~cDragon();

    cDragon();

    cDragon(string nombre, string caracteristica, tamanio tamanyoDragon, string color, bool estado,
        string level, unsigned int ataque, unsigned int defensa, unsigned int salud); //constructor por parametros

    void nivel() override;

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
        faltanteNuevoNivel();
    }

    string get_nombre() { return this->nombre; }

    void faltanteNuevoNivel() override;

    string get_level() { return this->level; }
    
    
};

#endif