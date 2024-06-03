
#pragma once
#include "cVikingo.h"
#include "cJinete.h"

#include <list> 
class cAdministradora {
public:
	//agrego una lista de cjinete, una lista de cvikingo, una lista de cdragon
	list <cVikingo> listaDeVikingos;
	list <cJinete> listaDeJinetes;
	list <cDragon> listaDeDragones;

	//void cVikingo::atacarDragones(cDragon* dragon, cVikingo* vikingo) {
	//vikingo->get_habilidades()->combate(dragon->get_habilidades(), vikingo->get_habilidades()); //no sabemos por qué nos marca error!!!
	//void atacarDragon();
};
