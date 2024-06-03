#include "cDragon.h"

cDragon::~cDragon() {
    delete habilidades;
} //esta definido en el cpp

cDragon::cDragon() {//constructor nulo
    this->nombre = "";
    this->caracteristica = "";
    this->tam = tamanio::desconocido;
    this->color = "";
    this->estado = false;
    this->habilidades = new cHabilidades(); //me creo un objeto dinámico de habilidades
    this->nivel = formaDeAtaque::nulo;
}

cDragon::cDragon(string nombre, string caracteristica, tamanio tamanyoDragon, string color, bool estado, cHabilidades& habilidades, formaDeAtaque nivel)
{
    this->nombre = nombre;
    this->caracteristica = caracteristica;
    this->tam = tamanyoDragon;
    this->color = color;
    this->estado = estado;
    this->habilidades = &habilidades; // si recibe un puntero nulo se va a romper todo tenes que hacer el control afuera de si esto es nulo y tiene que recibir una referencia sino el delete no tiene sentido.
    this->nivel = nivel;
}

string cDragon::to_string() {
    stringstream ss;
    ss << "El nombre del dragon es: " << nombre << endl;
    ss << "La caracteristica es: " << caracteristica << endl;
    ss << "Su estado: " << estado << endl;
    ss << "El color es: " << color << endl;
    return ss.str();
}

void cDragon::D_actualizarFormaDeAtaque()
{
    if (habilidades->get_ataque() <= 30) {
        this->nivel = formaDeAtaque::Dmorder;
    }
    if (habilidades->get_ataque() > 30 && habilidades->get_ataque() <= 60) {
        this->nivel = formaDeAtaque::Dalas;
    }
    if (habilidades->get_ataque() > 60) {
        this->nivel = formaDeAtaque::Dgarras;
    }
}

void cDragon::AnularDragon() {
    this->nombre = "";
    this->caracteristica = "";
    this->tam = tamanio::desconocido;
    this->color = "";
    this->estado = false;
    this->habilidades = NULL;
    this->nivel = formaDeAtaque::nulo;
}

void cDragon::D_baja() {
    if (habilidades->get_salud() == 0) {
        AnularDragon();
    }
}

cHabilidades* cDragon::get_habilidades() {
    return this->habilidades;
}

