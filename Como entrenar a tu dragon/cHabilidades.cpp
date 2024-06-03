#include "cHabilidades.h"
cHabilidades::cHabilidades(const cHabilidades& otrasHabilidades) {
    this->ataque = otrasHabilidades.ataque;
    this->defensa = otrasHabilidades.defensa;
    this->salud = otrasHabilidades.salud;
}

cHabilidades::cHabilidades()
{
    this->ataque = 0;
    this->defensa = 0;
    this->salud = 100;
}

cHabilidades::cHabilidades(unsigned int ataque, unsigned int defensa, unsigned int salud)
{
    this->ataque = ataque;
    this->defensa = defensa;
    this->salud = salud;
}


void cHabilidades::entrenar(bool habilidadaAentrenar)
{
    if (habilidadaAentrenar == true) {
        ataque += 10;
    }
    else {
        defensa += 10;
    }
}

void cHabilidades::curandero()
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
