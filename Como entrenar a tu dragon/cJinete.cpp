#include "cJinete.h"
#include "cJinete.h"

/*cJinete::cJinete() : cVikingo() {//constructor nulo
    this->caracteristicaFisica = "";
    this->result = resultado::noAsistio;//inicializo en 0
    // Inicialización de MiDragon (requiere un constructor adecuado para cDragon)
    this->MiDragon = NULL;
}*/

//aparece en el main
cJinete::cJinete(string nombre, string apellido, string posicion, string apodo, string fecha_nac, int contadorDragonesTerminados, string level, unsigned int ataque, unsigned int defensa, unsigned int salud,string caracteristicaFisica, resultado result) : cVikingo(nombre, apellido, posicion, apodo, fecha_nac,contadorDragonesTerminados, level, ataque, defensa, salud)
{
    this->caracteristicaFisica = caracteristicaFisica;
    this->MiDragon = NULL;
    this->result = result;
}


void cJinete::IncorporarDragon(cDragon* nuevoDragon) { //aparece en cAdministradora::buscarDragon
    this->MiDragon = nuevoDragon;
}


void cJinete::set_result(resultado result) //aparece en cAdministradora::pruebaBocon
{
    this->result = result;
}

void cJinete::printResultado() const //aparece en cAdministradora::pruebaBocon
{
    if (this->result == 0)
        cout << "No Asistio" << endl;
    if (this->result == 4) 
        cout << "Aprobado" << endl;
    if (this->result == 3)
        cout << "Desaprobado" << endl;
    if (this->result == 10)
        cout << "Primero: aprobado con nota maxima" << endl;
    if (this->result == 1)
        cout << "Ultimo: desaprobado y con la peor nota" << endl;
}

cDragon* cJinete::get_MiDragon() //aparece en cAdministradora::switch_menu
{
    return this->MiDragon;
}

void cJinete::print() { //aparece en cAdministradora::switch_menu
    cout << to_string() << endl;
}

string cJinete::to_string() { //aparece en el metodo de arriba
    stringstream ss;
    ss << "Tu jinete: " << nombre << "\t Salud: " << salud << "\t Ataque: " << ataque << "\t Defensa: " << defensa << endl << endl;
    return ss.str();
}


void cJinete::entrenarDragon(bool habilidadAEntrenar) //true: se entrena ataque, false: se entrena defensa
{
    MiDragon->entrenar(habilidadAEntrenar);
    MiDragon->nivel();
    cout << "Dragon entrenado con exito. Los nuevos valores de tu dragon son:" << endl;
    MiDragon->print();
    cout << "\n" << endl;
}

void cJinete::curarDragon() { //aparece en cAdministradora::switch_menu
    MiDragon->curandero();
}


resultado cJinete::get_Result() const
{
    return result;
}


cJinete::~cJinete() {

    delete MiDragon;//y la pedida en dragon!
}
