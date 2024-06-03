#include "cVikingo.h"
int cVikingo::contVikingos = 0;

cVikingo::~cVikingo()
{
}



cVikingo::cVikingo(string nombre, string apellido, string posicion, 
    string apodo, string fecha_nac, int contadorDragonesTerminados, cHabilidades& habilidades){
    this->nombre = nombre;
    this->apellido = apellido;
    this->posicion = posicion;
    this->apodo = apodo;
    this->fecha_nac = fecha_nac;
    this->contadorDragonesTerminados = contadorDragonesTerminados;
    this->habilidades = &habilidades;//desreferencio mi clase y la copio
    //this->nivel = nivel; falta nivel!
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
/*void cVikingo::V_actualizarFormaDeAtaque() {
    if (habilidades->get_ataque() <= 30) {
        this->nivel = VformaDeAtaque::Vpunyo;
    }
    if (habilidades->get_ataque() > 30 && habilidades->get_ataque() <= 60) {
        this->nivel = VformaDeAtaque::Varco;
    }
    if (habilidades->get_ataque() > 60) {
        this->nivel = VformaDeAtaque::Vhacha;
    }
}*/
void cVikingo::AnularVikingo() {
    this->habilidades = NULL;
}

void cVikingo::V_baja() {
    if (habilidades->get_salud() == 0) {
        AnularVikingo();
        contVikingos--;
    }
}










