#include "cAdministradora.h"
/*void cAdministradora::atacarDragon()
{
}
*/

int cAdministradora::CantidadEnemigos()
{
	return listaDeEnemigos.size();
}

int cAdministradora::CantidadVikingos()
{
    return listaDeVikingos.size();
}

void cAdministradora::llamarATribu(cDragon* dragonAAtacar) //recorre la lista de vikingos y genera un combate con el mismo dragón (un combate para c/vikingo)
{
	list <cVikingo*>::iterator it = this->listaDeEnemigos.begin();
	while (it != listaDeEnemigos.end()) {
        combate(dragonAAtacar, (*it));
        it++;
	}
}

void cAdministradora::combate(cDragon* dragon, cVikingo* vikingo)
{
    if (dragon->get_habilidades()->get_defensa() > vikingo->get_habilidades()->get_ataque() && dragon->get_habilidades()->get_ataque() > vikingo->get_habilidades()->get_defensa()) {
        vikingo->get_habilidades()->set_salud(vikingo->get_habilidades()->get_salud() - 50);
    }
    else if (dragon->get_habilidades()->get_defensa() < vikingo->get_habilidades()->get_ataque() && dragon->get_habilidades()->get_ataque() < vikingo->get_habilidades()->get_defensa()) {
        dragon->get_habilidades()->set_salud(dragon->get_habilidades()->get_salud() - 50);
    }
    else {
        dragon->get_habilidades()->set_salud(dragon->get_habilidades()->get_salud() - 25);
        vikingo->get_habilidades()->set_salud(vikingo->get_habilidades()->get_salud() - 25);
    }
    if (vikingo->get_habilidades()->get_salud() <= 0)
        throw new exception("muerte de vikingo"); //el try catch se hace en el main. Se llama en el main a la funcion "baja"

    if (dragon->get_habilidades()->get_salud() <= 0) {
        throw new exception("muerte de dragon");
    }
}
