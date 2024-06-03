#include "cVikingo.h"
int cVikingo::contVikingos = 0;

cVikingo::~cVikingo()
{
}

cVikingo::cVikingo(string nombre, string apellido, string posicion, string apodo, string fecha_nac, 
    int contadorDragonesTerminados, string level, unsigned int ataque, unsigned int defensa, 
    unsigned int salud) : cHabilidades(ataque,defensa,salud)
{
    this->nombre = nombre;
    this->apellido = apellido;
    this->posicion = posicion;
    this->apodo = apodo;
    this->fecha_nac = fecha_nac;
    this->contadorDragonesTerminados = contadorDragonesTerminados;
    this->level = level;
    contVikingos++;
}

string cVikingo::to_string() {
    stringstream ss;
    ss << "El nombre del Vikingo es: " << nombre << endl;
    ss << "Su apellido es: " << apellido << endl;
    ss << "Su apodo es: " << apodo << endl;
    ss << "Su posicion es: " << posicion << endl;
    ss << "El nivel del Vikingo es: " << level << endl;
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
void cVikingo::nivel()
{
    if (ataque <= 30) {
        this->level = "Puños";
    }
    if (ataque > 30 && ataque <= 60) {
        this->level = "Arco y Flecha";
    }
    if (ataque > 60 && ataque<100) {
        this->level = "Hacha";
    }
    if (ataque >= 100) {
        this->level = "Espada";
    }
}














