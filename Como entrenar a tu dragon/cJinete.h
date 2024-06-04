#pragma once
#ifndef CJINETE_H
#define CJINETE_H

#include "cVikingo.h"

//defino mi enum:
typedef enum { noAsistio = 0, aprobado = 4, desaprobado = 3, primero = 10, ultimo = 1 } resultado;//por entrenamiento con Bocon

class cJinete : public cVikingo{
private:
   
    string caracteristicaFisica;//sólo una, la que le da el apodo a la persona.
    cDragon* MiDragon; //por relación
    resultado result;

public:
    cJinete();

    ~cJinete();




    cJinete(string nombre, string apellido, string posicion, string apodo, string fecha_nac,
        int contadorDragonesTerminados, string level, unsigned int ataque, unsigned int defensa,
        unsigned int salud,
        string caracteristicaFisica, resultado result);

    void IncorporarDragon(cDragon* nuevoDragon);

    void entrenarDragon(bool habilidadAEntrenar);
  
    void curarDragon();

    string to_string();
    void print();

  
    void controlarDragon() {
        if (MiDragon->get_salud() == 0) {
            throw new exception("Muerte del dragón. Busca uno nuevo!"); // poner MiDragon en null 
        }
    }
};
#endif
