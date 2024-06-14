#include "cAdministradora.h"


cAdministradora::cAdministradora()
{
}

cAdministradora::~cAdministradora()
{
}

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
    if (dragon->get_defensa() > vikingo->get_ataque() && dragon->get_ataque() > vikingo->get_defensa()) {
        vikingo->set_salud(vikingo->get_salud() - 50);
    }
    else if (dragon->get_defensa() < vikingo->get_ataque() && dragon->get_ataque() < vikingo->get_defensa()) {
        dragon->set_salud(dragon->get_salud() - 50);
    }
    else {
        dragon->set_salud(dragon->get_salud() - 25);
        vikingo->set_salud(vikingo->get_salud() - 25);
    }
    if (vikingo->get_salud() <= 0)
        throw new exception("muerte de vikingo"); //el try catch se hace en el main. Se llama en el main a la funcion "baja"

    if (dragon->get_salud() <= 0) {
        throw new exception("muerte de dragon"); //se cae el jinte de arriba del dragon y pierde 70 de vida, si sigue vivo tiene q peliar el solo contra los vikingos malos
    }
}

void cAdministradora::historia()
{
    cout << " _______  _______  _______  _______    _______  _       _________ _______  _______  _        _______  _______    _______   _________            ______   _______  _______  _______  _______  _       " << endl;
    cout << "(  ____ \(  ___  )(       )(  ___  )  (  ____ \( (    /|\__   __/(  ____ )(  ____ \( (    /|(  ___  )(  ____ )  (  ___  )  \__   __/|\     /|  (  __  \ (  ____ )(  ___  )(  ____ \(  ___  )( (    /|" << endl;
    cout << "| (    \/| (   ) || () () || (   ) |  | (    \/|  \  ( |   ) (   | (    )|| (    \/|  \  ( || (   ) || (    )|  | (   ) |     ) (   | )   ( |  | (  \  )| (    )|| (   ) || (    \/| (   ) ||  \  ( |" << endl;
    cout << "| |      | |   | || || || || |   | |  | (__    |   \ | |   | |   | (____)|| (__    |   \ | || (___) || (____)|  | (___) |     | |   | |   | |  | |   ) || (____)|| (___) || |      | |   | ||   \ | |" << endl;
    cout << "| |      | |   | || |(_)| || |   | |  |  __)   | (\ \) |   | |   |     __)|  __)   | (\ \) ||  ___  ||     __)  |  ___  |     | |   | |   | |  | |   | ||     __)|  ___  || | ____ | |   | || (\ \) |" << endl;
    cout << "| |      | |   | || |   | || |   | |  | (      | | \   |   | |   | (\ (   | (      | | \   || (   ) || (\ (     | (   ) |     | |   | |   | |  | |   ) || (\ (   | (   ) || | \_  )| |   | || | \   |" << endl;
    cout << "| (____/\| (___) || )   ( || (___) |  | (____/\| )  \  |   | |   | ) \ \__| (____/\| )  \  || )   ( || ) \ \__  | )   ( |     | |   | (___) |  | (__/  )| ) \ \__| )   ( || (___) || (___) || )  \  |" << endl;
    cout << "(_______/(_______)|/     \|(_______)  (_______/|/    )_)   )_(   |/   \__/(_______/|/    )_)|/     \||/   \__/  |/     \|     )_(   (_______)  (______/ |/   \__/|/     \|(_______)(_______)|/    )_)" << endl;

    cout << "     _.-^^---....,,--       " << endl;
    cout << " _--                  --_  " << endl;
    cout << "<                        >)" << endl;
    cout << "|                         | " << endl;
    cout << " \._                   _./  " << endl;
    cout << "    ```--. . , ; .--'''       " << endl;
    cout << "         | |   |             " << endl;
    cout << "      .-=||  | |=-.   " << endl;
    cout << "      `-=#$%&%$#=-'   " << endl;
    cout << "         | ;  :|     " << endl;
    cout << "_____.,-#%&$@%#&#~,._____" << endl;

}

void cAdministradora::dragonEliminado(cDragon* dragon_muerto) {
    list<cDragon*> ::iterator it = this->listaDeDragones.begin();
    bool encontrado = false;
    while (it != this->listaDeDragones.end()) {
        if ((*it)->get_nombre() == dragon_muerto->get_nombre()) {
            this->listaDeDragones.erase(it);
            encontrado = true;
            break;
        }
        it++;
    }
    if (!encontrado) {
        throw new exception("Error, no se encontró el dragón");
    }
}

void cAdministradora::baja_dragon(cDragon* dragon) {
    if (dragon->get_salud() == 0) {
        cout << "El dragón murió" << endl;
        dragonEliminado(dragon);
    }
}

void cAdministradora::enemigoEliminado(cVikingo* enemigo) { // va para listaDeEnemigos
    list<cVikingo*> ::iterator it = this->listaDeEnemigos.begin();
    bool encontrado = false;
    while (it != this->listaDeEnemigos.end()) {
        if ((*it)->get_nombre() == enemigo->get_nombre()) {
            this->listaDeEnemigos.erase(it);
            encontrado = true;
            break;
        }
        it++;
    }
    if (!encontrado) {
        throw new exception("Error, no se encontró al enemigo");
    }
}

void cAdministradora::vikingoEliminado(cVikingo* vikingo) { // va para listaDeVikingos
    list<cVikingo*> ::iterator it = this->listaDeVikingos.begin();
    bool encontrado = false;
    while (it != this->listaDeVikingos.end()) {
        if ((*it)->get_nombre() == vikingo->get_nombre()) {
            this->listaDeVikingos.erase(it);
            encontrado = true;
            break;
        }
        it++;
    }
    if (!encontrado) {
        throw new exception("Error, no se encontró al vikingo");
    }
}

void cAdministradora::AgregarVikingo(cVikingo* vikingo)
{
    this->listaDeVikingos.push_back(vikingo);

}
