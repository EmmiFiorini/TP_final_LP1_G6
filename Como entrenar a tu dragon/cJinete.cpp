#include "cJinete.h"
#include "cJinete.h"

cJinete::cJinete() : cVikingo() {//constructor nulo
    this->caracteristicaFisica = "";
    this->result = resultado::noAsistio;//inicializo en 0
    // Inicialización de MiDragon (requiere un constructor adecuado para cDragon)
    this->MiDragon = NULL;
}

cJinete::~cJinete() {

    delete MiDragon;//y la pedida en dragon!
}

tm cJinete::convertirFecha()
{
    int anio_nacimiento, mes_nacimiento, dia_nacimiento;

    stringstream ss(this->fecha_nac);

    char delim;
    ss >> anio_nacimiento >> delim >> mes_nacimiento >> delim >> dia_nacimiento;

    tm fnac;
    fnac.tm_year = anio_nacimiento;
    fnac.tm_mon = mes_nacimiento;
    fnac.tm_mday = dia_nacimiento;

    return fnac;
}


cJinete:: cJinete(string nombre, string apellido, string posicion, string apodo, string fecha_nac, int contadorDragonesTerminados, cHabilidades& habilidades, string caracteristicaFisica, resultado result) : cVikingo(string nombre, string apellido, string posicion, string apodo, string fecha_nac, int contadorDragonesTerminados, cHabilidades& habilidades)
{
    this->caracteristicaFisica = caracteristicaFisica;
    this->MiDragon = NULL;
    this->result = result;
}

void cJinete::IncorporarDragon(cDragon* nuevoDragon) {
    this->MiDragon = nuevoDragon;
}

void cJinete::entrenarDragon(bool habilidadAEntrenar)
{
    MiDragon->get_habilidades()->entrenar(habilidadAEntrenar);
}

void cJinete::curarDragon() {
    MiDragon->get_habilidades()->curandero();
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