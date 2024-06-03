
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

	int CantidadVikingos();
	void llamarATribu(cDragon* dragonAAtacar);

	void combate(cDragon* dragon, cVikingo* vikingo);
	
};
