
#pragma once
#ifndef CADMINISTRADORA_H
#define CADMINISTRADORA_H
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

	cAdministradora();//constructor

	~cAdministradora();//destructor

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

	void AgregarVikingo(cVikingo* vikingo);

	void operator+=(cDragon* drago);

	friend ostream& operator <<(ostream& os, cDragon& dragon);

	int buscarDragon(string nombre);

	void operator-=(string nombre);

	void NuevoVikingoM(cVikingo* nuevoVikM);

	void PruebaBocon(cJinete* jinete);

	void PrintPeleaImagen(cDragon* dragon, cVikingo* vikingo) const;
	
	void buscarDragon(cJinete* jinete);

	int print_menu(cJinete* jinete);

	void switch_menu(int opcion, cJinete* jinete);

	bool VikingoMuertos();

	void PrintGanaste(cJinete* tuPersonaje);
};
#endif