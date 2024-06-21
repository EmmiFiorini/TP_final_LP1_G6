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
    Administradora.NuevoVikingoM(enemigo2);
    Administradora.NuevoVikingoM(enemigo1);

    //defino algunos personajes de la pelicula y los agrego a las listas correspondientes
    cVikingo* Bocon = new cVikingo("Bocon", "el Rudo", "consejero de Berk", "Bocon", "desconocido", 23, "3: hacha", 100, 100, 100);
    cVikingo* Estoico = new cVikingo("Estoisco", "el Vasto", "jefe de Berk", "Estoisco", "desconocido", 46, "4: espada", 200, 200, 100);
    cJinete* Hipo = new cJinete("Hipo", "Abadejo", "jinete", "Hipo", "desconocido", 0, "3: hacha", 80, 80, 100, "dientes desparejos", primero);
    cDragon* Chimuelo = new cDragon("Chimuelo", "dientes retractiles", mediano, "negro", true, "4:fuego", 120, 120, 100);

    Administradora.AgregarVikingo(Bocon);
    Administradora.AgregarVikingo(Estoico);
    Administradora.AgregarJinete(Hipo);
    Administradora.listaDeDragones.push_back(Chimuelo);

    //Se imprime la introduccion del juego
    Administradora.historia();

    //se crea al jinete
    string nombre, apellido, apodo, fecha, caract;
    cout << "Para empezar a jugar, creemos a tu jinete:" << endl;
    cout << "\n" << endl;

    cout << "       (/T\)" << endl;
    cout << "       (-,-)   ()---)  " << endl;
    cout << "        (o)/     -|3   " << endl;
    cout << "      /= '' == =//||  " << endl;
    cout << " ,OOO//|   |    " << endl;
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

    //una vez que se termina de crear, se limpia la consola
    system("cls");

    //se llama al menu (texto), ignorar lo que devuelve!!
    int opcion = Administradora.print_menu(tuPersonaje);



    try {
        Administradora.buscarDragon(tuPersonaje); //minijuego de opciones que, si se elijen las correctas, se doma a un dragon 
    }
    catch (exception* e) {
        cout << "\n" << endl;
        cout << "No encontraste al dragon! Tenes un intento mas para encontrarlo..." << endl;
        cout << "Presiona 'Enter' para volver al bosque. " << endl;
 
        cin.get();
        cin.get();
        system("cls"); //se limpia la consola

        //se llama a la funcion "recuperatorio" de buscarDragon (misma historia, cambia en el tipo de retorno para poder salir del juego)
        bool result = Administradora.RECUbuscarDragon(tuPersonaje);
        
        if (result == false) { //false --> no encontró al dragón
            system("cls");

            cout << "Despues de dos intentos fallidos, te perdiste en el bosque. " << endl;
            cout << "Tu cansancio de tanto recorrerlo te jugo en contra y moriste esperando que uno de tus hermanos te encuentre algun dia..." << endl;
            
            cout << "\n" << endl;
            cout << "GAME OVER" << endl;
            cout << "\n" << endl;

            cout << "               uuuuuuu" << endl;
            cout << "           uu$$$$$$$$$$$uu " << endl;
            cout << "        uu$$$$$$$$$$$$$$$$$uu " << endl;
            cout << "       u$$$$$$$$$$$$$$$$$$$$$u" << endl;
            cout << "      u$$$$$$$$$$$$$$$$$$$$$$$u " << endl;
            cout << "      u$$$$$$$$$$$$$$$$$$$$$$$$$u " << endl;
            cout << "      u$$$$$$$$$$$$$$$$$$$$$$$$$u " << endl;
            cout << "      u$$$$$$'   '$$$'   '$$$$$$u " << endl;
            cout << "      '$$$$'      u$u       $$$$' " << endl;
            cout << "       $$$u       u$u       u$$$ " << endl;
            cout << "       $$$u      u$$$u      u$$$ " << endl;
            cout << "        '$$$$uu$$$   $$$uu$$$$' " << endl;
            cout << "         '$$$$$$$'   '$$$$$$$' " << endl;
            cout << "           u$$$$$$$u$$$$$$$u " << endl;
            cout << "            u$'$'$'$'$'$'$u " << endl;
            cout << "   uuu      $$u$ $ $ $ $u$$     uuu " << endl;
            cout << "  u$$$$       $$$$$u$u$u$$$       u$$$$ " << endl;
            cout << "   $$$$$uu     '$$$$$$$$$'     uu$$$$$$ " << endl;
            cout << " u$$$$$$$$$$$uu   ''''    uuuu$$$$$$$$$$ " << endl;
            cout << " $$$$'''$$$$$$$$$$uuu   uu$$$$$$$$$'''$$$''' " << endl;
            cout << " '''      ''$$$$$$$$$$$uu ''$''' " << endl;
            cout << "            uuuu '''$$$$$$$$$$uuu " << endl;
            cout << " u$$$uuu$$$$$$$$$uu ''$$$$$$$$$$$uuu$$$ " << endl;
            cout << " $$$$$$$$$$''''           '''$$$$$$$$$$$' " << endl;
            cout << "  '$$$$$'                      ''''$$$$''' " << endl;
            cout <<"     $$$                           $$$$ "<< endl;


            cout << "Gracias por jugar!!" << endl;
            
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
    }

    if (tuPersonaje->get_MiDragon() != nullptr) {
        cout << "Ahora que ya tenes a tu dragon, vamos a superar la prueba de Bocon y a convertirnos en verdaderos jinetes!" << endl;
        cout << "Presiona 'Enter' para empezar la prueba: " << endl;
        cin.get();
        bool result = Administradora.PruebaBocon(tuPersonaje);

        if (result == false) {
            system("cls");

            cout << "Despues de dos intentos fallidos, Bocon hablo con Estoico sobre tus habilidades para ser jinete." << endl;
            cout << "Ambos llegaron a la conclusion de que no eres apto para semejante rol." << endl;
            cout << "En cambio, te designaron como limpiador de jaulas de dragones... Buena suerte con eso!" << endl;

            cout << "\n" << endl;
            cout << "GAME OVER" << endl;
            cout << "\n" << endl;

            cout << "               uuuuuuu" << endl;
            cout << "           uu$$$$$$$$$$$uu " << endl;
            cout << "        uu$$$$$$$$$$$$$$$$$uu " << endl;
            cout << "       u$$$$$$$$$$$$$$$$$$$$$u" << endl;
            cout << "      u$$$$$$$$$$$$$$$$$$$$$$$u " << endl;
            cout << "      u$$$$$$$$$$$$$$$$$$$$$$$$$u " << endl;
            cout << "      u$$$$$$$$$$$$$$$$$$$$$$$$$u " << endl;
            cout << "      u$$$$$$'   '$$$'   '$$$$$$u " << endl;
            cout << "      '$$$$'      u$u       $$$$' " << endl;
            cout << "       $$$u       u$u       u$$$ " << endl;
            cout << "       $$$u      u$$$u      u$$$ " << endl;
            cout << "        '$$$$uu$$$   $$$uu$$$$' " << endl;
            cout << "         '$$$$$$$'   '$$$$$$$' " << endl;
            cout << "           u$$$$$$$u$$$$$$$u " << endl;
            cout << "            u$'$'$'$'$'$'$u " << endl;
            cout << "   uuu      $$u$ $ $ $ $u$$     uuu " << endl;
            cout << "  u$$$$       $$$$$u$u$u$$$       u$$$$ " << endl;
            cout << "   $$$$$uu     '$$$$$$$$$'     uu$$$$$$ " << endl;
            cout << " u$$$$$$$$$$$uu   ''''    uuuu$$$$$$$$$$ " << endl;
            cout << " $$$$'''$$$$$$$$$$uuu   uu$$$$$$$$$'''$$$''' " << endl;
            cout << " '''      ''$$$$$$$$$$$uu ''$''' " << endl;
            cout << "            uuuu '''$$$$$$$$$$uuu " << endl;
            cout << " u$$$uuu$$$$$$$$$uu ''$$$$$$$$$$$uuu$$$ " << endl;
            cout << " $$$$$$$$$$''''           '''$$$$$$$$$$$' " << endl;
            cout << "  '$$$$$'                      ''''$$$$''' " << endl;
            cout << "     $$$                         $$$$ " << endl;


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
        else {
            int op = 0;
            do {
                cout << "       ###            ###            ###             " << endl;
                cout << "      #o###          #o###          #o###            " << endl;
                cout << "     ####o###       ####o###       ####o###          " << endl;
                cout << "   #o###|#/###    #o###|#/###    #o###|#/###         " << endl;
                cout << "    ####|/#o#      ####|/#o#      ####|/#o#          " << endl;
                cout << "   #  } | {  #    #  } | {  #    #  } | {  #         " << endl;
                cout << "      } | {          } | {          } | {            " << endl;

                cout << "\n" << endl;
                cout << "                     MENU:" << endl;
                cout << "3) Entrenar" << endl;
                cout << "4) Curandero" << endl;
                cout << "5) Pelea contra todos los enemigos" << endl;
                cout << "\n" << endl;
                cout << "A donde vamos? Ingresa el numero que corresponda a tu opcion: " << endl;
                cin.get();
                cin >> op;

                if (op == 3) { //se selecciona "entrenar" 
                    system("cls");
                    cout << "valores actuales de tu jinete: ";
                    cout << "\n" << endl;
                    tuPersonaje->print();

                    cout << "valores actuales de tu dragon: ";
                    tuPersonaje->get_MiDragon()->print(); 
                   
                    cout << "\n" << endl;

                    cout << "Ingrese 'a' si quiere entrenar ataque y 'b' si quiere entrenar defensa" << endl; //cuando se entrena al dragon, se entrena al jinete
                    char c;
                    cin >> c;
                    
                    if (c == 'A' || c == 'a') {
                        system("cls");
                        tuPersonaje->entrenarDragon(true);
                        tuPersonaje->entrenar(true);
                    }
                    else if (c == 'B' || c == 'b') {
                        system("cls");
                        tuPersonaje->entrenarDragon(false);
                        tuPersonaje->entrenar(false);
                    }
                    else {
                        cout << "Opcion ingresada no valida." << endl;
                    }
                }

                if (op == 4) { //se selecciona "curandero"
                    system("cls");
                    cout << "Estos son los valores actuales de tus personajes:" << endl;
                    cout << "\n" << endl;

                    tuPersonaje->print();
                    
                    cout << "\n" << endl;
                    
                    tuPersonaje->get_MiDragon()->print();

                    cout << "\n" << endl;

                    cout << "Ingrese 'a' si quiere curar tu dragon y 'b' si quiere curarse a si mismo" << endl;
                    char f;
                    cin >> f;
                    if (f == 'A' || f == 'a') {
                        tuPersonaje->curarDragon();
                        cout << "Dragon curado con exito! la salud de tu dragon ahora es de " << tuPersonaje->get_MiDragon()->get_salud() << "/100" << endl;
                    }
                    else if (f == 'B' || f == 'b') {
                        tuPersonaje->curandero();
                        cout << "Jinete curado con exito! la salud de " << tuPersonaje->get_nombre() << " ahora es de " << tuPersonaje->get_salud() << "/100" << endl;
                    }
                    else {
                        cout << "Opcion ingresada no valida. Presiona 'enter' para volver al menu" << endl;
                        cin.get();
                    }
                }

            } while (op != 5);

            system("cls");
            cout << "Empezo la pelea! Presiona 'enter' para ver como se desarrolla." << endl;
            cout << "\n" << endl;
            bool resultado = Administradora.llamarATribu(tuPersonaje);
            
            if (resultado == false) {
                
                if (tuPersonaje->get_salud() <= 0) {
                    cout << "\n" << endl;
                    cout << "GAME OVER" << endl;
                    cout << "\n" << endl;

                    cout << "               uuuuuuu" << endl;
                    cout << "           uu$$$$$$$$$$$uu " << endl;
                    cout << "        uu$$$$$$$$$$$$$$$$$uu " << endl;
                    cout << "       u$$$$$$$$$$$$$$$$$$$$$u" << endl;
                    cout << "      u$$$$$$$$$$$$$$$$$$$$$$$u " << endl;
                    cout << "      u$$$$$$$$$$$$$$$$$$$$$$$$$u " << endl;
                    cout << "      u$$$$$$$$$$$$$$$$$$$$$$$$$u " << endl;
                    cout << "      u$$$$$$'   '$$$'   '$$$$$$u " << endl;
                    cout << "      '$$$$'      u$u       $$$$' " << endl;
                    cout << "       $$$u       u$u       u$$$ " << endl;
                    cout << "       $$$u      u$$$u      u$$$ " << endl;
                    cout << "        '$$$$uu$$$   $$$uu$$$$' " << endl;
                    cout << "         '$$$$$$$'   '$$$$$$$' " << endl;
                    cout << "           u$$$$$$$u$$$$$$$u " << endl;
                    cout << "            u$'$'$'$'$'$'$u " << endl;
                    cout << "   uuu      $$u$ $ $ $ $u$$     uuu " << endl;
                    cout << "  u$$$$       $$$$$u$u$u$$$       u$$$$ " << endl;
                    cout << "   $$$$$uu     '$$$$$$$$$'     uu$$$$$$ " << endl;
                    cout << " u$$$$$$$$$$$uu   ''''    uuuu$$$$$$$$$$ " << endl;
                    cout << " $$$$'''$$$$$$$$$$uuu   uu$$$$$$$$$'''$$$''' " << endl;
                    cout << " '''      ''$$$$$$$$$$$uu ''$''' " << endl;
                    cout << "            uuuu '''$$$$$$$$$$uuu " << endl;
                    cout << " u$$$uuu$$$$$$$$$uu ''$$$$$$$$$$$uuu$$$ " << endl;
                    cout << " $$$$$$$$$$''''           '''$$$$$$$$$$$' " << endl;
                    cout << "  '$$$$$'                      ''''$$$$''' " << endl;
                    cout << "     $$$                            $$$$ " << endl;

                    
                    cout << "\n" << endl;
                    cout << "Gracias por jugar!!" << endl;
                    
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
            }
            else {
                system("cls");
                
                cout << "\n" << endl;
               
                cout << "Felicidades! Ganaste el Juego!";
                cout << "Gracias a tu valentia y destreza, la isla de Berk volvio a tener la paz que tanto la caracteriza, y la tribu Draugr ya no los molesta mas." << endl;
   

                cout << "\n" << endl;
                cout << "    ___________ " << endl;
                cout << "   '._==_==_=_.' " << endl;
                cout << " . - :        / -. " << endl;
                cout << " | (| :.      | ) | " << endl;
                cout << "  '-|:.       |-' " << endl;
                cout << "     ::.      / " << endl;
                cout << "     '::. .' " << endl;
                cout << "        ) ( " << endl;
                cout << "      _.' '._ " << endl;
                cout << "     `''''''` " << endl;
                
                cout << "\n" << endl;
                cout << "Gracias por jugar!!" << endl;
            }

        }
    }

    

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
