// Como entrenar a tu dragon.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "cAdministradora.h"

int main()
{
    cAdministradora Administradora;//me creo una clase administradora

   Administradora.historia();//se imprime la historia de nuestro juego

   string nombre, apellido, apodo, fecha, caract;//comienza la aventura creando a su personaje 
   cout << "\t" << "Creemos a tu jinete!" << endl;
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
   
   cout << "Ingresa la fecha en la que nacio (dia de mes de anio): " << endl;
   cin.get();
   cin >> fecha;
   cin.get();
   
   cout << "Cual es la caracteristica fisica que lo representa? " << endl;
   
   cin.get();
   cin >> caract;
   cin.get();
   cJinete* tuPersonaje = new cJinete(nombre, apellido, "jinete", apodo, fecha, 0, "", 0, 0, 100, caract, noAsistio);
   cout << "\t" << "¡Todo listo!Ahora, a buscar tu dragon!" << endl << endl << endl;
   system("cls");
   cin.get();
   cin.get();

   //me creo algunos personajes
    cVikingo* viki1 = new cVikingo("Pedro", "Delgado", "Jefe", "Pepe", "6 de julio de 1000", 2, "", 10, 20, 100);
    cVikingo* enemigo1 = new cVikingo("Ulf", "Iversen", "Jefa de la tribu Draugr","Ulf", "14 de junio de 990", 5, "", 100, 70, 100);
    cVikingo* enemigo2 = new cVikingo("Ari", "Iversen", "Sub-Jefa de la tribu Draugr", "Ari", "14 de junio de 990", 3, "", 60, 99, 100);
    cVikingo* enemigo3 = new cVikingo("Birger", "Nielsen", "Guerrero de la tribu Draugr", "carnicero", "30 de octubre de 988", 4, "", 80, 20, 100);
    
    Administradora.AgregarVikingo(viki1);

    Administradora.NuevoVikingoM(enemigo1);
    Administradora.NuevoVikingoM(enemigo2);
    Administradora.NuevoVikingoM(enemigo3);
    
    int option=Administradora.menu(tuPersonaje);//llamo a la funcion menu, y ahora hago los try y catch
   
    cin.get();
    do {
        switch (option) {
        case 1: {
            try {
                Administradora.buscarDragon(tuPersonaje);
            }
            catch (exception* e) {
                cout << "Vuelve a intentarlo!" << endl;
                Administradora.menu(tuPersonaje);
            }
            break;
        }
        case 2: {
            try {
                Administradora.PruebaBocon(tuPersonaje);
            }
            catch (exception* e) {
                cout << "Vuelve a intentarlo!" << endl;
                Administradora.menu(tuPersonaje);
            }
            break;
        }
        case 3: {
            //entrenarDragon(bool habilidadAEntrenar)
            cout << "Ingrese A si quiere entrenar ataque y B si quiere entrenar defensa" << endl;
            char c;
            cin >> c;
            if (c == 'A' || c == 'a') {
                tuPersonaje->entrenarDragon(true);
            }
            else if (c == 'B' || c == 'b') {
                tuPersonaje->entrenarDragon(false);
            }
            else {
                cout << "Opcion ingresada no valida" << endl;
                Administradora.menu(tuPersonaje);
            }

            break;
        }
        case 4: {
            cout << "Ingrese A si quiere curar tu dragon y B si quiere curarse a uno mismo" << endl;
            char f;
            cin >> f;
            if (f == 'A' || f == 'a') {
                tuPersonaje->curarDragon();
            }
            else if (f == 'B' || f == 'b') {
                tuPersonaje->curandero();
            }
            else {
                cout << "Opcion ingresada no valida" << endl;
                Administradora.menu(tuPersonaje);
            }
            break;
        }

        case 5: {
            try {
                //llamarATribu(cDragon* dragonAAtacar)
                Administradora.llamarATribu(tuPersonaje->get_MiDragon());
              
            }
            catch (exception* e) {
                cout << tuPersonaje->get_MiDragon()->get_nombre() << " ha muerto." << endl << "La tribu Draugr comenzo una pelea contigo, tras unas golpizas " << endl;
                
                tuPersonaje->IncorporarDragon(nullptr);//cambio el dragon a nullo
                tuPersonaje->set_salud(tuPersonaje->get_salud() - 50);//disminuyo la salud
                tuPersonaje->set_result(noAsistio);//desparobada la prueba

                if (tuPersonaje->get_salud() > 0) {
                    cout << "tuvieron piedad contigo, y tan solo te dejaron con " << tuPersonaje->get_salud()<<
                        "de vida y te dejaron volver a tu aldea." <<endl<< endl << "Comienza nuevamente la historia con un nuevo dragon!" << endl;
                    Administradora.menu(tuPersonaje);
                }
                else {
                    cout << "te mataron." << endl << endl << "GAME OVER" << endl;
                    cin.get();
                    //manejar aca si es fin del juego o si quiere volver a empezar
                }
                
               
            }
            break;
        }
        default:
            cin.get();

        }
    } while (option != 6);
    

    delete viki1;
    delete enemigo1;
    delete enemigo2;
    delete enemigo3;
    delete tuPersonaje;
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
