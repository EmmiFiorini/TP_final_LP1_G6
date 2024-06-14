#include "cJinete.h"
#include "cJinete.h"

/*cJinete::cJinete() : cVikingo() {//constructor nulo
    this->caracteristicaFisica = "";
    this->result = resultado::noAsistio;//inicializo en 0
    // Inicialización de MiDragon (requiere un constructor adecuado para cDragon)
    this->MiDragon = NULL;
}*/

cJinete::~cJinete() {

    delete MiDragon;//y la pedida en dragon!
}


cJinete::cJinete(string nombre, string apellido, string posicion, string apodo, 
    string fecha_nac, int contadorDragonesTerminados, string level,
    unsigned int ataque, unsigned int defensa, unsigned int salud, 
    string caracteristicaFisica, resultado result) : cVikingo(nombre, apellido, posicion, apodo, fecha_nac,
        contadorDragonesTerminados, level, ataque, defensa, salud)
{
    this->caracteristicaFisica = caracteristicaFisica;
    this->MiDragon = NULL;
    this->result = result;// Inicializa los miembros específicos de cJinete aquí, si es necesario
}

void cJinete::IncorporarDragon(cDragon* nuevoDragon) {
    this->MiDragon = nuevoDragon;
}

void cJinete::entrenarDragon(bool habilidadAEntrenar)
{
    MiDragon->entrenar(habilidadAEntrenar);
}

void cJinete::curarDragon() {
    MiDragon->curandero();
}

string cJinete::to_string() {
    stringstream ss;
    ss << "El nombre del Jinete es: " << nombre << endl;
    ss << "El apellido del Jinete es: " << apellido << endl;
    ss << "El apodo del Jinete es: " << apodo << endl;
    ss << "La caracteristica fisica del Jinete es: " << caracteristicaFisica << endl;
    return ss.str();
}

void cJinete::print() {
    cout << to_string() << endl;
}