// Como entrenar a tu dragon.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "cAdministradora.h"

int main()
{

    cAdministradora Administradora;//me creo una clase administradora, las listas se inicializan vacias

    //defino los enemigos del juego (para el combate) y los agrego a la lista de vikingos enemigos
  
    cVikingo* enemigo1 = new cVikingo("Ulf", "Iversen", "Jefa de la tribu Draugr", "Ulf", "14 de junio de 990", 5, "4: espada", 100, 70, 100);
    cVikingo* enemigo2 = new cVikingo("Ari", "Iversen", "Sub-Jefa de la tribu Draugr", "Ari", "14 de junio de 990", 3, "3: hacha", 60, 99, 100);
    cVikingo* enemigo3 = new cVikingo("Birger", "Nielsen", "Guerrero de la tribu Draugr", "carnicero", "30 de octubre de 988", 4, "2: arco", 80, 20, 100);
    Administradora.NuevoVikingoM(enemigo3);
    //Administradora.NuevoVikingoM(enemigo2);
    Administradora.NuevoVikingoM(enemigo1);
    
    //defino algunos personajes de la pelicula y los agrego a las listas correspondientes
    cVikingo* Bocon = new cVikingo("Bocon", "el Rudo", "consejero de Berk", "Bocon", "desconocido", 23, "3: hacha", 100, 100, 100);
    cVikingo* Estoico = new cVikingo("Estoisco", "el Vasto", "jefe de Berk", "Estoisco", "desconocido", 46, "4: espada", 200, 200, 100);
    cJinete* Hipo = new cJinete("Hipo", "Abadejo", "jinete", "Hipo", "desconocido", 0, "3: hacha", 80, 80, 100, "dientes desparejos", primero);
    cDragon* Chimuelo = new cDragon("Chimuelo", "dientes retractiles", mediano, "negro", true, "4:fuego", 120, 120, 100);
    
    Administradora.AgregarVikingo(Bocon);
    Administradora.AgregarVikingo(Estoico);
    Administradora.AgregarJinete(Hipo);
    
    //Administradora.listaDeDragones+=Chimuelo; CHEQUEAR ESTO!! me da error


   Administradora.historia();//se imprime la historia de nuestro juego (introduccion)

   //se crea al jinete
   string nombre, apellido, apodo, fecha, caract;
   cout << "Para empezar a jugar, creemos a tu jinete:" << endl;
   cout << "\n" << endl;
    
   cout << "       (/T\)" << endl;
   cout << "       (-,-)   ()---)  " << endl;
   cout << "        (o)/     -|3   " << endl;
   cout << "      /= '' == =//||  " << endl;
   cout << " ,OOO//|   |    "<< endl;
   cout << " O:O:O LLLLL " << endl;
   cout << "  OOO/ || ||  " << endl;
   cout << "      C_) (_D" << endl;

   cout << "\n" << endl;
   cout << "Ingresa el nombre de tu jinete: " << endl;
   cin.get();
   cin >> nombre;
   
   cout << "Ingresa el apellido de tu jinete: " << endl;
   cin.get();
   cin >> apellido;
   cin.get();
  
   cout << "Cual es su apodo? " << endl;
   cin.get();
   cin >> apodo;
   cin.get();
   
   cout << "Ingresa la fecha en la que nacio (dia/mes/anio): " << endl;
   cin.get();
   cin >> fecha;
   cin.get();
   
   cout << "Cual es la caracteristica fisica que lo representa? " << endl;
   cin.get();
   cin >> caract;
   cin.get();

   cJinete* tuPersonaje = new cJinete(nombre, apellido, "jinete", apodo, fecha, 0, "", 0, 0, 100, caract, noAsistio);
   Administradora.AgregarJinete(tuPersonaje); //agrego al jinete creado a mi lista de jinetes
   
   cout << "\t" << "Todo listo! Ahora vamos a buscar a tu dragon!" << endl << "Presiona 'enter' para ir a la aldea." << endl << endl;
   cin.get();
   cin.get();
   
   //una vez que se termina de crear, se limpia la consola y se llama a las funciones de menu
   system("cls");
   int opcion =Administradora.print_menu(tuPersonaje);
   Administradora.switch_menu(opcion, tuPersonaje);

   //hicimos el codigo de tal forma que, una vez que el menu se llama desde el main, cualquier caso que pase en el juego el menu se llama
   // dentro de otras funciones. 

    



   //manejo de objetos dinamicos:
    delete enemigo1;
    delete enemigo2;
    delete enemigo3;
    delete Bocon;
    delete Estoico;
    delete Hipo;
    delete Chimuelo;
    delete tuPersonaje;
    
    return 0;
}
