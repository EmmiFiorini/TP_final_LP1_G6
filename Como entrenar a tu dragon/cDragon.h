#pragma once

//me creo mi .h de dragon
#ifndef CDRAGON_H
#define CDRAGON_H


#include "cHabilidades.h"

//defino mis enums:
enum class clase { Desconocida = 0, Fogonero = 1, Piedra = 2, Espanto = 3, Rastreadora = 4, Afilada = 5, Marejada = 6, Misterio = 7, Embestida = 8 };
enum class tamanyo { desconocido = 0, mini = 1, chico = 2, mediano = 3, grande = 4, gigante = 5 };
enum class formaDeAtaque { nulo = 0, Dmorder = 1, Dalas = 2, Dgarras = 3 };

class cDragon
{
private:
    string nombre;
    string caracteristica;
    clase claseDragon;
    tamanyo tam;
    string color;
    bool estado;
    cHabilidades* habilidades; //objeto de la clase habilidades
    formaDeAtaque nivel;

public:
    ~cDragon();

    cDragon();

    cDragon(string nombre, string caracteristica, tamanyo tamanyoDragon, string color, bool estado, clase claseDragon, cHabilidades* habilidades, formaDeAtaque nivel); //constructor por parametros

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

    void AnularDragon();

    void D_baja();

    cHabilidades* get_habilidades();
};

#endif