#pragma once
#ifndef CJINETE_H
#define CJINETE_H

#include "cDragon.h"

//defino mi enum:
typedef enum { noAsistio = 0, aprobado = 4, desaprobado = 3, primero = 10, ultimo = 1 } resultado;//por entrenamiento con Bocon

class cJinete
{
private:
    string nombre;
    string apellido;
    string apodo;
    string fecha_nac;
    string caracteristicaFisica;//s�lo una, la que le da el apodo a la persona.
    cDragon* MiDragon; //por relaci�n
    resultado result;

public:
    cJinete();

    ~cJinete();

    tm convertirFecha();



    cJinete(string nombre, string apellido, string apodo, string fecha_nac,
        string caracteristicaFisica, resultado result);

    void IncorporarDragon(cDragon* nuevoDragon);

    void entrenarDragon(combate habilidadAEntrenar);
    //accedo a mi dragon (objeto dinamico) para, a su vez, acceder a sus habilidades (otro objeto din�mico de �l). Dentro de habilidades, llamo al m�todo entrenar

    void curarDragon();

    string to_string();
    void print();

  
    void controlarDragon() {
        if (MiDragon->get_habilidades()->get_salud() == 0) {
            throw new exception("Muerte del drag�n. Busca uno nuevo!"); // poner MiDragon en null 
        }
    }
};
#endif
