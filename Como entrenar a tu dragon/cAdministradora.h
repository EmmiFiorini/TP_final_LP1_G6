
#pragma once
#ifndef CADMINISTRADORA_H
#define CADMINISTRADORA_H
using namespace std;
#include "cJinete.h"

#include <list> 
class cAdministradora {

public:
	//agrego una lista de cjinete, una lista de cvikingo, una lista de cdragon
	list <cVikingo*> listaDeVikingos;
	list <cJinete*> listaDeJinetes;
	list <cDragon*> listaDeDragones;
	list <cDragon*> listaDragonesMuertos;
	list <cVikingo*> listaDeEnemigos;

	cAdministradora();//constructor

	~cAdministradora();//destructor

	int CantidadEnemigos();

	int CantidadVikingos();

	bool llamarATribu(cJinete* tuPersonaje);

	void historia();

    void dragonEliminado(cDragon* dragon_muerto);

    //en clase cAdministradora: se usa cuando se llama la excepción de combate de muerte de dragon
    void baja_dragon(cDragon* dragon);

    void enemigoEliminado(cVikingo* enemigo);

	void vikingoEliminado(cVikingo* vikingo);
	
	void jineteEliminado(cJinete* jinete);

	void AgregarVikingo(cVikingo* vikingo);

	void AgregarJinete(cJinete* jinete);

	void operator+=(cDragon* drago);

	friend ostream& operator <<(ostream& os, cDragon& dragon);

	int buscarDragon(string nombre); //lista

	void operator-=(string nombre);

	void NuevoVikingoM(cVikingo* nuevoVikM);

	bool PruebaBocon(cJinete* jinete);

	bool RecuperatorioBocon(cJinete* tuPersonaje);

	void PrintPeleaImagen(cDragon* dragon, cVikingo* vikingo) const;
	
	void  buscarDragon(cJinete* jinete); //historia
	bool RECUbuscarDragon(cJinete* jinete, int nulo); //historia 2

	int print_menu(cJinete* jinete);

	//bool switch_menu(int opcion, cJinete* jinete);

	bool VikingoMuertos();

	//void PrintGanaste(cJinete* tuPersonaje);

	void PrintPeleaVJ(cJinete* jinete, cVikingo* vikingo);
	
};
#endif