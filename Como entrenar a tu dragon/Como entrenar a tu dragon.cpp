// Como entrenar a tu dragon.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "cAdministradora.h"

int main()
{
    cAdministradora Administradora;//me creo una clase administradora
    /*string nombre, string apellido, string posicion, string apodo, string fecha_nac, 
    int contadorDragonesTerminados, string level, unsigned int ataque, unsigned int defensa, 
    unsigned int salud) */
    cVikingo* viki1 = new cVikingo("Pedro", "Delgado", "Jefe", "Pepe", "6 de julio de 1000", 2, "", 10, 20, 100);
    Administradora.AgregarVikingo(viki1);
    viki1->nivel();
    viki1->faltanteNuevoNivel();
    //Administradora.AgregarVikingo;    

    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
