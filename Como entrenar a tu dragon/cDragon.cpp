#include "cDragon.h"

cDragon::~cDragon() {

}

cDragon::cDragon(string nombre, string caracteristica, tamanio tamanyoDragon, 
    string color, bool estado, string level, unsigned int ataque,
    unsigned int defensa, unsigned int salud) : cHabilidades(ataque, defensa, salud)
{
    this->nombre = nombre;
    this->caracteristica = caracteristica;
    this->tam = tamanyoDragon;
    this->color = color;
    this->estado = estado;
    this->level = level;
}

void cDragon::nivel()
{
    if (ataque <= 30) {
        this->level = "Morder";
    }
    if (ataque > 30 && ataque <= 60) {
        this->level = "Alas";
    }
    if (ataque > 60 && ataque<100) {
        this->level = "Garras";
    }
    if (ataque >= 100)
        this->level = "Fuego";
}


cDragon::cDragon() : cHabilidades() {//constructor nulo
    this->nombre = "";
    this->caracteristica = "";
    this->tam = tamanio::desconocido;
    this->color = "";
    this->estado = false;
    this->level = "";
}


string cDragon::to_string() {
    stringstream ss;
    ss << "El nombre del dragon es: " << nombre << endl;
    ss << "La caracteristica es: " << caracteristica << endl;
    ss << "Su estado: " << estado << endl;
    ss << "El color es: " << color << endl;
    ss << "Su nivel es:" << level << endl;
    return ss.str();
}

void cDragon::faltanteNuevoNivel()
{ 
    std::cout << "Tu nivel actual es: " << level << std::endl;
    int n = 0; 
    if (ataque < 100) {
        if (ataque <= 30) {
            n = 31 - ataque;
        }
        if (ataque > 30 && ataque <= 60) {
            n = 61 - ataque;
        }
        if (ataque > 60 && ataque < 100) {
            n = 100 - ataque;
        }
        std::cout << "Te faltan aumentar tu ataque  " << n << " puntos para llegar al nuevo nivel " << std::endl;
    }
    else {
        std::cout << "Ya estas en el maximo nivel!" << std::endl;
    }
}





