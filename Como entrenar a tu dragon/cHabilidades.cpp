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


void cHabilidades::entrenar(combate habilidadaAentrenar)
{
    if()
}

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
        throw new exception("muerte de vikingo"); //el try catch se hace en el main. Se llama en el main a la funcion "baja"
    }
    if (hab_vikingo.salud <= 0) {
        throw new exception("muerte de dragon");
    }

}