#include "cVikingo.h"

cVikingo::~cVikingo()
{
}


cVikingo::cVikingo(string nombre, string apellido, string posicion, int contadorDragonesTerminados, cHabilidades* habilidades, VformaDeAtaque nivel) :apellido(apellido) { //constructor por parametros
    this->nombre = nombre;
    this->posicion = posicion;
    this->contadorDragonesTerminados = contadorDragonesTerminados;
    this->habilidades = habilidades;//desreferencio mi clase y la copio
    this->nivel = nivel;
    contVikingos++;
}

string cVikingo::to_string() {
    stringstream ss;
    ss << "El nombre del Vikingo es: " << nombre << endl;
    ss << "El apellido del Vikingo es: " << apellido << endl;
    ss << "La posicion del Vikingo es: " << posicion << endl;
    return ss.str();
}
void cVikingo::print() {
    cout << to_string() << endl;
}
bool cVikingo::dragonesTerminados() {
    if (contadorDragonesTerminados > 0)
        return true;
    else {
        return false;
    }
}
void cVikingo::V_actualizarFormaDeAtaque() {
    if (habilidades->get_ataque() <= 30) {
        this->nivel = VformaDeAtaque::Vpunyo;
    }
    if (habilidades->get_ataque() > 30 && habilidades->get_ataque() <= 60) {
        this->nivel = VformaDeAtaque::Varco;
    }
    if (habilidades->get_ataque() > 60) {
        this->nivel = VformaDeAtaque::Vhacha;
    }
}
void cVikingo::AnularVikingo() {
    this->nombre = "";
    this->posicion = "";
    this->contadorDragonesTerminados = 0;
    this->nivel = VformaDeAtaque::nulo;
    this->habilidades = NULL;
}
void cVikingo::V_baja() {
    if (habilidades->get_salud() == 0) {
        AnularVikingo();
        contVikingos--;
    }
}


cHabilidades::cHabilidades(const cHabilidades& otrasHabilidades) {
    this->ataque = otrasHabilidades.ataque;
    this->defensa = otrasHabilidades.defensa;
    this->salud = otrasHabilidades.salud;
}

cHabilidades::~cHabilidades() {}

void cHabilidades::combate(cHabilidades h_dragon, cHabilidades hab_vikingo) {// hacelo recibir la referencia sino vas a modificar la copia
    if (h_dragon.defensa > hab_vikingo.ataque && h_dragon.ataque > hab_vikingo.defensa) {
        hab_vikingo.salud = hab_vikingo.salud - 50;
    }
    else if ((h_dragon.defensa < hab_vikingo.ataque && h_dragon.ataque < hab_vikingo.defensa)) {
        h_dragon.salud = h_dragon.salud - 50;
    }
    else {
        h_dragon.salud = h_dragon.salud - 25;
        hab_vikingo.salud = hab_vikingo.salud - 25;
    }
    if (hab_vikingo.salud <= 0) {
        throw new exception("Error: muerte de vikingo"); //el try catch se hace en el main. Se llama en el main a la funcion "baja"
    }
    if (hab_vikingo.salud <= 0) {
        throw new exception("Error: muerte de dragon");
    }

}








