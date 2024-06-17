#include "cHabilidades.h"





cHabilidades::cHabilidades(unsigned int ataque, unsigned int defensa, unsigned int salud) //al ser herencia, se usa cuando se crea al dragon y al vikingo en el main
{
    this->ataque = ataque;
    this->defensa = defensa;
    this->salud = salud;
}


void cHabilidades::entrenar(bool habilidadaAentrenar) //se usa en el metodo cJinete::entrenarDragon
{
    if (habilidadaAentrenar == true) { 
        ataque += 30;
    }
    else {
        defensa += 30;
    }
}
void cHabilidades::curandero() //se usa en el metodo cJinete::curarDragon
{
    if (salud > 0 && salud < 100) {
        if (salud + 30 >= 100) {
            salud = 100;
        }
        else {
            salud += 30;
        }
    }
}

int cHabilidades::formaDeAtaque() //se usa en cAdministradora::combate
{
    if (ataque <= 30) { //1: morder
        return 1;
    }
    if (ataque > 30 && ataque <= 60) { //1: morder, 2: alas
        int ataque = 1 + rand() % 2;
        return ataque;
    }
    if (ataque > 60 && ataque < 100) { //1: morder, 2: alas, 3: garras
        int ataque = 1 + rand() % 3;
        return ataque;
    }
    if (ataque >= 100) {
        int ataque = 1 + rand() % 4; //1: morder, 2: alas, 3: garras, 4: fuego
        return ataque;
    }
}




cHabilidades::cHabilidades(const cHabilidades& otrasHabilidades) { //constructor por copia
    this->ataque = otrasHabilidades.ataque;
    this->defensa = otrasHabilidades.defensa;
    this->salud = otrasHabilidades.salud;
}

cHabilidades::cHabilidades() //constructor nulo
{
    this->ataque = 0;
    this->defensa = 0;
    this->salud = 100;
}