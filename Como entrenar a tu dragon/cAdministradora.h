
#pragma once
#include "cVikingo.h"
#include "cJinete.h"

#include <list> 
class cAdministradora {
public:
	//agrego una lista de cjinete, una lista de cvikingo, una lista de cdragon
	list <cVikingo*> listaDeVikingos;
	list <cJinete*> listaDeJinetes;
	list <cDragon*> listaDeDragones;
	list <cVikingo*> listaDeEnemigos;

	int CantidadEnemigos();

	int CantidadVikingos();

	void llamarATribu(cDragon* dragonAAtacar);

	void combate(cDragon* dragon, cVikingo* vikingo);
	
	void historia();

    void dragonEliminado(cDragon* dragon_muerto);

    //en clase cAdministradora: se usa cuando se llama la excepción de combate de muerte de dragon
    void baja_dragon(cDragon* dragon);

    void enemigoEliminado(cVikingo* enemigo);

	void vikingoEliminado(cVikingo* vikingo);


};
