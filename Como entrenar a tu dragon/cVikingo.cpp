#include "cVikingo.h"
int cVikingo::contVikingos = 0;

cVikingo::~cVikingo()
{
}

cVikingo::cVikingo(string nombre, string apellido, string posicion, string apodo, string fecha_nac, int contadorDragonesTerminados, string level, unsigned int ataque, unsigned int defensa, unsigned int salud) : cHabilidades(ataque,defensa,salud)
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

void cVikingo::print() {
    cout << to_string() << endl;
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
        this->level = "golpes"; //1) golpes
    }
    if (ataque > 30 && ataque <= 60) {
        this->level = "Arco y Flecha"; //1) golpes, 2) arco y flecha
    }
    if (ataque > 60 && ataque<100) { //1) golpes, 2)arco y flecha, 3)hacha
        this->level = "Hacha";
    }
    if (ataque >= 100) { //1) golpes, 2)arco y flecha, 3) flecha, 4) espada
        this->level = "Espada";
    }
}

void cVikingo::faltanteNuevoNivel()
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
        std::cout << "Te faltan aumentar tu ataque  " << n << " puntos para llegar al nuevo nivel. " << std::endl;
    }
    else {
        std::cout << "Ya estas en el maximo nivel!" << std::endl;
    }
}















