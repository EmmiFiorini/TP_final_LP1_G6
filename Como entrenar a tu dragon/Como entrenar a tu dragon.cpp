// Como entrenar a tu dragon.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "cAdministradora.h"

int main()
{
    cAdministradora Administradora;//me creo una clase administradora
    Administradora.PrintPeleaImagen();
   // Administradora.historia();

    cVikingo* viki1 = new cVikingo("Pedro", "Delgado", "Jefe", "Pepe", "6 de julio de 1000", 2, "", 10, 20, 100);
    cVikingo* enemigo1 = new cVikingo("Ulf", "Iversen", "Jefa de la tribu Draugr","Ulf", "14 de junio de 990", 5, "", 100, 70, 100);
    cVikingo* enemigo2 = new cVikingo("Ari", "Iversen", "Sub-Jefa de la tribu Draugr", "Ari", "14 de junio de 990", 3, "", 60, 99, 100);
    cVikingo* enemigo3 = new cVikingo("Birger", "Nielsen", "Guerrero de la tribu Draugr", "carnicero", "30 de octubre de 988", 4, "", 80, 20, 100);
    
    Administradora.AgregarVikingo(viki1);

    Administradora.NuevoVikingoM(enemigo1);
    Administradora.NuevoVikingoM(enemigo2);
    Administradora.NuevoVikingoM(enemigo3);

    viki1->nivel();
    viki1->faltanteNuevoNivel();
    //Administradora.AgregarVikingo;    

    delete viki1;
    delete enemigo1;
    delete enemigo2;
    delete enemigo3;
    return 0;
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
