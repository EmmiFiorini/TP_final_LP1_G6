#include "cAdministradora.h"


cAdministradora::cAdministradora() //constructor nulo, se usa en el main
{
   
}

void cAdministradora::NuevoVikingoM(cVikingo* nuevoVikM) // se usa en el main
{
    this->listaDeEnemigos.push_back(nuevoVikM);

}

void cAdministradora::AgregarVikingo(cVikingo* vikingo) //se usa en el main
{
    this->listaDeVikingos.push_back(vikingo);

}

void cAdministradora::AgregarJinete(cJinete* jinete) //se usa en el main
{
    this->listaDeJinetes.push_back(jinete);
}

void cAdministradora :: operator+=(cDragon* drago) { //se usa en el main
    listaDeDragones.push_back(drago);
}

void cAdministradora::historia()
{
    std::cout << "COMO ENTRENAR A TU DRAGON 2.0, version de Pili y Emma" << std::endl;
    std::cout << "Presiona 'enter' para empezar!" << endl;
    std::cin.get();

    std::cout << "En el anio 1010, la isla de Berk vivia en paz y armonia." << endl;
    std::cout << "Hasta que un dia aparecieron los malvados vikingos de la tribu Draugr, que atacaron la aldea" << endl;
    std::cout << "y asesinaron a muchos de sus aldeanos." << endl;

    std::cout << "\n" << endl;
    std::cout << "\t" << "     _.-^^---....,,--       " << endl;
    std::cout << "\t" << " _--                  --_  " << endl;
    std::cout << "\t" << "<                        >)" << endl;
    std::cout << "\t" << "|                         | " << endl;
    std::cout << "\t" << " \._                   _./  " << endl;
    std::cout << "\t" << "    ```--. . , ; .--'''       " << endl;
    std::cout << "\t" << "         | |   |             " << endl;
    std::cout << "\t" << "      .-=||  | |=-.   " << endl;
    std::cout << "\t" << "      `-=#$%&%$#=-'   " << endl;
    std::cout << "\t" << "         | ;  :|     " << endl;
    std::cout << "\t" << "_____.,-#%&$@%#&#~,._____" << endl << endl;

    std::cin.get();
    std::cout << "\n" << endl;

    std::cout << "Ese mismo dia, Estoico el Vasto, el jefe de la aldea, designo un grupo de jovenes valientes vikingos" << endl;
    std::cout << "que domarian dragones." << endl;
    std::cout << "Si logran pasar la prueba del jefe de seguridad Bocon, formaran parte de un grupo de elite encargado" << endl;
    std::cout << "de defender a la aldea de las tribus enemigas." << endl;
    std::cout << "\n" << endl;

    std::cout << "\t" << " <>=======() " << endl;
    cout << "\t" << "(/\___   /|\\          ()==========<>_" << endl;
    cout << "\t" << "      \_/ | \\        //|\   ______/ \)" << endl;
    cout << "\t" << "        \_|  \\      // | \_/" << endl;
    cout << "\t" << "          \|\/|\_   //  /\/" << endl;
    cout << "\t" << "           (oo)\ \_//  /" << endl;
    cout << "\t" << "          //_/\_\/ /  |" << endl;
    cout << "\t" << "         @@/  |=\  \  |" << endl;
    cout << "\t" << "              \_=\_ \ |" << endl;
    cout << "\t" << "                \==\ \|\_ " << endl;
    cout << "\t" << "             __(\===\(  )\ " << endl;
    cout << "\t" << "            (((~) __(_/   |" << endl;
    cout << "\t" << "                 (((~) \  /" << endl;
    cout << "\t" << "                 ______/ /" << endl;
    cout << "\t" << "                 '------'" << endl;

    cin.get();
    cout << "\n" << endl;


    cout << "Desde ese dia, decidiste que querias formar parte de aquel grupo, para vengar a aquellos hermanos Bercianos" << endl;
    cout << "muertos en manos de la despiadada Ulf y sus guerreros. " << endl;
    cout << "\n" << endl;
    cout << "Comenza tu aventura domando a un dragon, pasando la prueba de Bocon y luego enfrentandote a todos los vikingos enemigos." << endl;
    cout << "Comenzamos? Vamos a la aldea!" << endl;
    cin.get();
    system("cls");
}


int cAdministradora::print_menu(cJinete* jinete) //en el main y en otros metodos
{
    int option;//creo la opcion q va a elegir el usuario
    
    cout << "       ###            ###            ###             " << endl;
    cout << "      #o###          #o###          #o###            " << endl;
    cout << "     ####o###       ####o###       ####o###          " << endl;
    cout << "   #o###|#/###    #o###|#/###    #o###|#/###         " << endl;
    cout << "    ####|/#o#      ####|/#o#      ####|/#o#          " << endl;
    cout << "   #  } | {  #    #  } | {  #    #  } | {  #         " << endl;
    cout << "      } | {          } | {          } | {            " << endl;
    
    cout << "\n" << endl;
    if (jinete->get_MiDragon() == nullptr) {//si no tiene dragon, solamente le aparece estas opciones:
        cout << "                     MENU:                " << endl;
        cout << "1) Buscar Dragon" << endl;
        cout << "6) Salir" << endl;
    }
    else if (jinete->get_Result() == noAsistio || jinete->get_Result() == desaprobado || jinete->get_Result() == 0 || jinete->get_Result() == 3 ||jinete->get_Result() == ultimo || jinete->get_Result() == 1) {
        cout << "                     MENU:" << endl;
        cout << "2) Prueba de Bocon" << endl;
        cout << "6) Salir" << endl;
    }else if(listaDeEnemigos.empty()){
        cout <<"                      MENU:" << endl;
        cout << "6) Salir" << endl;
    }
    else {
        cout << "\t MENU:" << endl;
        cout << "3) Entrenar " << endl;
        cout << "4) Curandero" << endl;
        cout << "5) Pelea contra todos los enemigos" << endl;
        cout << "6) Salir" << endl;
    }
    cout << "\n" << endl;
    cout << "A donde vamos? Ingresa el numero que corresponda a tu opcion: " << endl;
    cin >> option;
    return option;

}

void cAdministradora::buscarDragon(cJinete* jinete) { 
    bool flag = false;
    system("cls");
    ;
    cout << "Con el primer rayo de sol, me adentre al bosque de los Susurros. Camine con cautela, siguiendo el camino que mis ancestros me habian indicado, hasta que se bifurco en dos:" << endl;
    cout << "uno mostraba huellas peculiares... no podria decir de que animal en especifico. El otro era un camino llano, no mostraba signos de que habia sido recorrido" << endl;
    cout << "Cual voy a elegir? " << endl;
    cout << "\n" << endl;
    cout << "\t" << "Ingrese 'a' si quiere ir por el camino con huellas; ingrese 'b' si quiere ir por el camino llano" << endl;
    // la respuesta correcta es la A
    char respuesta1;
    cin.get();

    cin >> respuesta1;
    cout << "\n" << endl;
    if (respuesta1 == 'B' || respuesta1 == 'b') { //si se selecciona la respuesta incorrecta, sale del if y la flag sigue false
        cout << "Me adentre por el camino llano, confiado en que mis ancestros me guiarian. Sin embargo, aparecio una niebla densa y el paisaje se torno confuso. Me encontre desorientado, rodeado por la niebla" << endl;
        cout << "\n" << endl;
    }
    else { //se selecciona la respuesta correcta
        cout << "Decidi seguir las huellas, sin saber a que criatura pertenecian. Camine durante horas siguiendo este rastro. La vegetacion se hacia mas densa" << endl;
        cout << "De repente, las huellas desaparecieron en una zona pantanosa, y frente a mi el camino se dividio en dos:" << endl;
        cout << "uno llevaba hacia una colina empinada, cubierta de espinas, y el otro descendia hacia un valle oscuro." << endl;
        cout << "Debia decidir: subir la colina espinosa o descender al valle sombrio? " << endl;
        cout << "\n" << endl;
        cout << "\t" << "Ingrese 'a' si quiere ir subir por la colina espinosa; ingrese 'b' si quiere descender por el valle sombrio" << endl;
        char respuesta2;
        cin.get();
        cin >> respuesta2;
        cout << "\n" << endl;
        if (respuesta2 == 'A' || respuesta2 == 'a') { //respuesta incorrecta
            cout << "Decidi enfrentar la colina espinosa. Sin embargo, las espinas eran mas traicioneras de lo que imagine" << endl;
            cout << "Cada paso era una lucha, y pronto me encontre atrapado, con las espinas rasgando mi ropa" << endl;
            cout << "Perdi mucho tiempo y, finalmente, tuve que retroceder, herido y frustrado." << endl;
            cout << "\n" << endl;

        }
        else { //respuesta correcta
            cout << "Tome el camino hacia el valle sombrio. La oscuridad era densa. Sin embargo, segui avanzando, sintiendo que estaba en el camino correcto." << endl;
            cout << "De repente, el valle se abrio en un claro iluminado por una luz azulada." << endl;
            cout << "En el centro, descansando majestuosamente, estaba el dragon. Me acerque con cautela, recitando las palabras que mis ancestros me habian mostrado." << endl;
            cout << "El dragon levanto su cabeza y se quedo observandome." << endl;
            cout << "Debia tomar una decision final: mostrarme respetuoso, esperando que el dragon aceptara mi presencia, o intentar imponerme, demostrando mi fuerza." << endl;
            cout << "\n" << endl;
            cout << "\t" << "Ingrese 'a' si quiere mostrarse respetuoso con el dragon; ingrese 'b' si quiere imponerse ante al dragon" << endl;
            char respuesta3;
            cin.get();
            cin >> respuesta3;
            cout << "\n" << endl;
            if (respuesta3 == 'B' || respuesta3 == 'b') { //respuesta incorrecta
                cout << "Opte por imponer mi fuerza. Me acerque al dragon con firmeza, levantando mi voz y mostrando una postura desafiante. Sin embargo, el dragon no se impresiono." << endl;
                cout << "Rugio de tal forma que el suelo temblo bajo mis pies." << endl;
                cout << "Luego, lanzo una rafaga de fuego que me obligo a retroceder rapidamente. Tropece y cai al suelo, comprendiendo mi error.La fuerza bruta no era el camino para ganar su respeto. Me retire hacia la aldea, sabiendo la oportunidad que habia perdido" << endl;
                cout << "\n" << endl;

            }
            else { //respuesta correcta (final), la flag cambia a true y se encuentra al dragon
                flag = true;
                cout << "Me incline ante el dragon, mostrando respeto y humildad. Este, sorprendentemente, bajo su cabeza y me permitio tocar sus escamas." << endl;
                cout << "Con cuidado, subi a su lomo y juntos volamos hacia la aldea." << endl;
                cout << "\n" << endl;
                cin.get();
                system("cls");

                cout << "\t" << "Felicitaciones! Domaste a tu dragon. A continuacion vamos a crearlo!" << endl;
                cout << "\n" << endl;
                cout << "Ingresa el nombre de tu nuevo dragon: " << endl;
                string nombreD;
                cin >> nombreD;

                cin.get();
                cout << "\n" << endl;
                cout << "Que caracteristica fisica tiene?" << endl;
                string caractD;
                cin >> caractD;

                cin.get();
                cout << "\n" << endl;
                cout << "Que color tiene?" << endl;
                string colorD;
                cin >> colorD;

                cDragon* tuDragon = new cDragon(nombreD, caractD, mediano, colorD, true, "1: morder", 0, 0, 100);
                jinete->IncorporarDragon(tuDragon); //metodo de cJinete
                //tuDragon += ; se agrega al dragon en la lista de dragones CHEQUEAR OPERADOR PORQUE NO ME LO TOMA
                cout << "\n" << endl;

                cout << "\t" << "Dragon creado! Ingresa 'enter' para volver a la aldea y seguir con tu aventura" << endl;
                cin.get();
                cin.get();
                system("cls");
                //se llama al menu para que vuelva a elegir la opcion. Ahora aparece el menu con nuevas opciones desbloqueadas

            }
        }
    }
    if (!flag) { //si la flag nunca cambió a true, se lanza una excepcion
        throw new exception("No se encontro el dragon");
    }
}

bool cAdministradora::RECUbuscarDragon(cJinete* jinete) { //en swtich_menu
    bool flag = false;
    system("cls");

    cout << "Con el primer rayo de sol, me adentre al bosque de los Susurros. Camine con cautela, siguiendo el camino que mis ancestros me habian indicado, hasta que se bifurco en dos:" << endl;
    cout << "uno mostraba huellas peculiares... no podria decir de que animal en especifico. El otro era un camino llano, no mostraba signos de que habia sido recorrido" << endl;
    cout << "Cual voy a elegir? " << endl;
    cout << "\n" << endl;
    cout << "\t" << "Ingrese 'a' si quiere ir por el camino con huellas; ingrese 'b' si quiere ir por el camino llano" << endl;
    // la respuesta correcta es la A
    char respuesta1;
    cin.get();

    cin >> respuesta1;
    cout << "\n" << endl;
    if (respuesta1 == 'B' || respuesta1 == 'b') { //si se selecciona la respuesta incorrecta, sale del if y la flag sigue false
        cout << "Me adentre por el camino llano, confiado en que mis ancestros me guiarian. Sin embargo, aparecio una niebla densa y el paisaje se torno confuso. Me encontre desorientado, rodeado por la niebla" << endl;
        cout << "\n" << endl;
    }
    else { //se selecciona la respuesta correcta
        cout << "Decidi seguir las huellas, sin saber a que criatura pertenecian. Camine durante horas siguiendo este rastro. La vegetacion se hacia mas densa" << endl;
        cout << "De repente, las huellas desaparecieron en una zona pantanosa, y frente a mi el camino se dividio en dos:" << endl;
        cout << "uno llevaba hacia una colina empinada, cubierta de espinas, y el otro descendia hacia un valle oscuro." << endl;
        cout << "Debia decidir: subir la colina espinosa o descender al valle sombrio? " << endl;
        cout << "\n" << endl;
        cout << "\t" << "Ingrese 'a' si quiere ir subir por la colina espinosa; ingrese 'b' si quiere descender por el valle sombrio" << endl;
        char respuesta2;
        cin.get();
        cin >> respuesta2;
        cout << "\n" << endl;
        if (respuesta2 == 'A' || respuesta2 == 'a') { //respuesta incorrecta
            cout << "Decidi enfrentar la colina espinosa. Sin embargo, las espinas eran mas traicioneras de lo que imagine" << endl;
            cout << "Cada paso era una lucha, y pronto me encontre atrapado, con las espinas rasgando mi ropa" << endl;
            cout << "Perdi mucho tiempo y, finalmente, tuve que retroceder, herido y frustrado." << endl;
            cout << "\n" << endl;

        }
        else { //respuesta correcta
            cout << "Tome el camino hacia el valle sombrio. La oscuridad era densa. Sin embargo, segui avanzando, sintiendo que estaba en el camino correcto." << endl;
            cout << "De repente, el valle se abrio en un claro iluminado por una luz azulada." << endl;
            cout << "En el centro, descansando majestuosamente, estaba el dragon. Me acerque con cautela, recitando las palabras que mis ancestros me habian mostrado." << endl;
            cout << "El dragon levanto su cabeza y se quedo observandome." << endl;
            cout << "Debia tomar una decision final: mostrarme respetuoso, esperando que el dragon aceptara mi presencia, o intentar imponerme, demostrando mi fuerza." << endl;
            cout << "\n" << endl;
            cout << "\t" << "Ingrese 'a' si quiere mostrarse respetuoso con el dragon; ingrese 'b' si quiere imponerse ante al dragon" << endl;
            char respuesta3;
            cin.get();
            cin >> respuesta3;
            cout << "\n" << endl;
            if (respuesta3 == 'B' || respuesta3 == 'b') { //respuesta incorrecta
                cout << "Opte por imponer mi fuerza. Me acerque al dragon con firmeza, levantando mi voz y mostrando una postura desafiante. Sin embargo, el dragon no se impresiono." << endl;
                cout << "Rugio de tal forma que el suelo temblo bajo mis pies." << endl;
                cout << "Luego, lanzo una rafaga de fuego que me obligo a retroceder rapidamente. Tropece y cai al suelo, comprendiendo mi error.La fuerza bruta no era el camino para ganar su respeto. Me retire hacia la aldea, sabiendo la oportunidad que habia perdido" << endl;
                cout << "\n" << endl;

            }
            else { //respuesta correcta (final), la flag cambia a true y se encuentra al dragon
                flag = true;
                cout << "Me incline ante el dragon, mostrando respeto y humildad. Este, sorprendentemente, bajo su cabeza y me permitio tocar sus escamas." << endl;
                cout << "Con cuidado, subi a su lomo y juntos volamos hacia la aldea." << endl;
                cout << "\n" << endl;
                cin.get();
                system("cls");

                cout << "\t" << "Felicitaciones! Domaste a tu dragon. A continuacion vamos a crearlo!" << endl;
                cout << "\n" << endl;
                cout << "Ingresa el nombre de tu nuevo dragon: " << endl;
                string nombreD;
                cin >> nombreD;

                cin.get();
                cout << "\n" << endl;
                cout << "Que caracteristica fisica tiene?" << endl;
                string caractD;
                cin >> caractD;

                cin.get();
                cout << "\n" << endl;
                cout << "Que color tiene?" << endl;
                string colorD;
                cin >> colorD;

                cDragon* tuDragon = new cDragon(nombreD, caractD, mediano, colorD, true, "1: morder", 0, 0, 100);
                jinete->IncorporarDragon(tuDragon); //metodo de cJinete
                //tuDragon += ; se agrega al dragon en la lista de dragones CHEQUEAR OPERADOR PORQUE NO ME LO TOMA
                cout << "\n" << endl;

                cout << "\t" << "Dragon creado! Ingresa 'enter' para volver a la aldea y seguir con tu aventura" << endl;
                cin.get();
                cin.get();
                system("cls");
                //se llama al menu para que vuelva a elegir la opcion. Ahora aparece el menu con nuevas opciones desbloqueadas
                int opcion = print_menu(jinete);

            }
        }
    }
    return flag; //si retorna false, no se encontró al dragon. Si retorna true, sí se encontró
}


bool cAdministradora::PruebaBocon(cJinete* jinete) { //aparece en switch_menu
    float nota = 0;
    cout << "\n" << endl;

    cout << "'Bienvenido a mi prueba, soy Bocon. Buen dragon el tuyo, camarada!'" << endl;
    cout << "'Estas listo para la prueba?'" << endl;
    cout << "'Recuerda: tienes tan solo dos intentos'"<<endl<<"'El futuro de nuestra tribu esta en tus manos... Solo te lo recuerdo, sin presion!'" << endl;
    cout << "\n" << endl;
    
    cout << "LA PRUEBA DE BOCON:" << endl;
    cout << "Responde las preguntas correctamente para tener la mejor nota de la clase!" << endl;

    cout << "\n" << endl;
    cout << "\t" << "Quien es el novio de la dragona en la pelicula 'Shrek'?" << endl;
    cout << "\t1) Burro\n \t2) Shrek\n \t3) El Gato con Botas" << endl;
    cout << "\n" << endl;
    cout << "\t" << "Ingresa el numero (1, 2 o 3) de tu respuesta: "<<endl;
    int respuesta1 = 0;
    cin >> respuesta1;
    if (respuesta1 == 1) {
        nota += 10;
    }
    cout << "\n" << endl;

    cout << "\t" << "Cuantos dragones tiene la protagonista Daenerys de la serie 'Games of thrones'?" << endl;
    cout << "\t1) cero\n \t2) dos\n \t3) tres" << endl;
    cout << "\n" << endl;
    cout << "\t" << "Ingresa el numero (1, 2 o 3) de tu respuesta: "<<endl;
    int resp2;
    cin >> resp2;
    if (resp2 == 3) {
        nota += 10;
    }

    cout << "\n" << endl;

    cout << "\t" << "En la pelicula 'La Bella Durmiente', quien se trasforma en dragon?" << endl;
    cout << "\t1) Aurora\n \t2) Malefica\n \t3) Ningun personaje" << endl;
    cout << "\n" << endl;
    cout << "\t" << "Ingresa el numero (1, 2 o 3) de tu respuesta: "<<endl;
    int resp3;
    cin >> resp3;

    if (resp3 == 2) {
        nota += 10;
    }

    cout << "\n" << endl;
    cout << "\n" << endl;

    cout << "Ya terminaste la prueba!" << endl << "Tu nota es: " << nota << " / 30" << endl << "Tu resultado es: ";
    if (nota == 30) { // noAsistio/ultimo = 0 pts, desaprobado = 10 pts, aprobado = 20 pts, primero = 30 pts
        jinete->set_result(primero); //metodo de cJinete
    }
    else if (nota == 20) {
        jinete->set_result(aprobado);
    }
    else if (nota == 10) {
        jinete->set_result(desaprobado);
    }
    else if (nota == 0) {
        jinete->set_result(ultimo);
    }

    jinete->printResultado();
    
    if (nota < 20) {
        cout << "Desaprobaste, intentalo nuevamente en el recuperatorio!" << endl;
        cout << "Presiona 'Enter' para ir al recuperatorio de Bocon. " << endl;
        cin.get();
        bool result2 = RecuperatorioBocon(jinete);
    }
    else {
        cout << "'Felicitaciones!" << endl << "Eres oficialmente un Jinete!'" << endl << endl;
        cout << "Regresa a la aldea y prueba las nuevas opciones desbloqueadas!" << endl << endl;
        cin.get();
        cin.get();
        system("cls");
        return true;
    }   
}

bool cAdministradora::RecuperatorioBocon(cJinete* tuPersonaje) {
    system("cls");
    int nota = 0;
    cout << "'Bueno, " << tuPersonaje->get_nombre() << " este es tu ultimo intento'." << endl;
    cout<< "'En caso de desaprobar, tendremos que dejar ir a " << tuPersonaje->get_MiDragon()->get_nombre() << " '." << endl;
    cout << "'Muchisima Suerte!'" << endl;
    
    cout << "\n" << endl;
    cout << "\n" << endl;

    cout << "RECUPERATORIO DE BOCON: " << endl;
    cout << "Responde las preguntas correctamente para tener la mejor nota de la clase y convertirte en jinete!" << endl;

    cout << "\n" << endl;

    cout << "\t" << "Que tipo de dragon enfrenta Harry, personaje de 'Harry Potter', en el 'Torneo de los Tres Magos'?" << endl;
    cout << "\t1) Colacuerno Hungaro\n \t2) Bola de Fuego Chino\n \t3) Ninguno de los anteriores" << endl;
    cout << "\n" << endl;
    cout << "\t" << "Ingresa el numero (1, 2 o 3) de tu respuesta: " << endl;
    int respuesta1 = 0;
    cin >> respuesta1;
    if (respuesta1 == 1) {
        nota += 10;
    }

    cout << "\n" << endl;
    cout << "\t" << "Como se llama el dragon guardian de Mulan en la pelicula de Disney?" << endl;
    cout << "\t1) Smaug\n \t2) Mushu\n \t3) Falkor" << endl;
    cout << "\n" << endl;
    cout << "\t" << "Ingresa el numero (1, 2 o 3) de tu respuesta: " << endl;
    int respuesta2 = 0;
    cin >> respuesta2;
    if (respuesta2 == 2) {
        nota += 10;
    }

    cout << "\n" << endl;
    cout << "\t" << "Cual de las siguientes culturas no tiene mitos sobre dragones?" << endl;
    cout << "\t1) Cultura China\n \t2) Cultura Azteca\n \t3) Cultura Aborigen Australiana" << endl;
    cout << "\n" << endl;
    cout << "\t" << "Ingresa el numero (1, 2 o 3) de tu respuesta: " << endl;
    int respuesta3 = 0;
    cin >> respuesta3;
    if (respuesta3 == 3) {
        nota += 10;
    }

    cin.get();
    cout << "\n" << endl;
    cout << "\n" << endl;

    cout << "Ya terminaste la prueba!" << endl << "Tu nota es: " << nota << " / 30" << endl << "Tu resultado es: ";
    if (nota == 30) { // noAsistio/ultimo = 0 pts, desaprobado = 10 pts, aprobado = 20 pts, primero = 30 pts
        tuPersonaje->set_result(primero); //metodo de cJinete
    }
    else if (nota == 20) {
        tuPersonaje->set_result(aprobado);
    }
    else if (nota == 10) {
        tuPersonaje->set_result(desaprobado);
    }
    else if (nota == 0) {
        tuPersonaje->set_result(ultimo);
    }

    tuPersonaje->printResultado();//imprimo el resultado
    //manejo ambos casos
    if (nota < 20) {
        cout << "\n" << endl;
        cout << "\n" << endl;
        cout << "Desaprobaste." << endl << "Lo lamento pero no estas calificado para ser un jinete" << endl;
        cout << "No estas calificado para montar a " << tuPersonaje->get_MiDragon()->get_nombre() << endl;
        cout << "GAME OVER" << endl;

        tuPersonaje->get_MiDragon()->set_estado(false);
        tuPersonaje->IncorporarDragon(nullptr);//libero al dragon
        return false;

    }else {
        cout << "\n" << endl;
        cout << "\n" << endl;
        cout << "Felicitaciones " << tuPersonaje->get_nombre() << " !" << endl;
        cout << "Oficialmente te convertiste en jinete!" << endl;
        cout << "Regresa a la aldea y continua con la aventura. Presiona 'Enter' para volver: " << endl << endl;
        cin.get();
        cin.get();
        system("cls");
        return true;
   
    }
   
}


//en switch_menu
bool cAdministradora::llamarATribu(cJinete* tuPersonaje) //recorre la lista de vikingos y genera un combate con el mismo dragón
{
    if (!tuPersonaje || !tuPersonaje->get_MiDragon()) {
        cout << "Error: Personaje o Dragón no válido." << endl;
        return false;
    }
    list <cVikingo*>::iterator it = this->listaDeEnemigos.begin();

    while (it != listaDeEnemigos.end()) {
        do {
            cout << "Valores actuales de los participantes: " << endl;
            PrintPeleaImagen(tuPersonaje->get_MiDragon(), (*it));
            cout << "\n" << endl;
            cout << "\t ------------------PELEA------------------" << endl;

            if (tuPersonaje->get_MiDragon()->get_defensa() >= (*it)->get_ataque() && tuPersonaje->get_MiDragon()->get_ataque() >= (*it)->get_defensa()) { //gana el dragon
                (*it)->set_salud((*it)->get_salud() - 50);

                int opcion = tuPersonaje->get_MiDragon()->formaDeAtaque();

                switch (opcion) {
                case 1:
                    cout << tuPersonaje->get_MiDragon()->get_nombre() << " ataco al enemigo con sus dientes!" << endl;
                    break;
                case 2:
                    cout << tuPersonaje->get_MiDragon()->get_nombre() << " ataco al enemigo con sus alas!" << endl;
                    break;
                case 3:
                    cout << tuPersonaje->get_MiDragon()->get_nombre() << " ataco al enemigo con sus garras!" << endl;
                    break;
                case 4:
                    cout << tuPersonaje->get_MiDragon()->get_nombre() << " ataco al enemigo lanzandole fuego!" << endl;
                    break;
                default:
                    break;
                }
            }

            else {
                tuPersonaje->get_MiDragon()->set_salud(tuPersonaje->get_MiDragon()->get_salud() - 50);
                int opcion = (*it)->formaDeAtaque();
                switch (opcion) {
                case 1:
                    cout << (*it)->get_nombre() << " ataco al dragon con golpes!" << endl;
                    break;
                case 2:
                    cout << (*it)->get_nombre() << " ataco al dragon con arco y flechas!" << endl;
                    break;
                case 3:
                    cout << (*it)->get_nombre() << " ataco al dragon con su hacha!" << endl;
                    break;
                case 4:
                    cout << (*it)->get_nombre() << " ataco al dragon con su espada!" << endl;
                    break;
                default:
                    break;
                }
            }

            //ya habiendo sido la pelea, vuelvo a imprimir los nuevos datos de cada uno
            cin.get();
            cout << "Valores de los participantes despues de la pelea: " << endl;
            PrintPeleaImagen(tuPersonaje->get_MiDragon(), (*it));
        } while (tuPersonaje->get_MiDragon()->get_salud() > 0 && (*it)->get_salud() > 0);



        if (tuPersonaje->get_MiDragon()->get_salud() <= 0) { //si el dragon se muere, te toman como prisionero
            cout << "El vikingo " << (*it)->get_nombre() << " acabo con " << tuPersonaje->get_MiDragon()->get_nombre() << " ." << endl;

            tuPersonaje->set_salud(tuPersonaje->get_salud() - 50);

            listaDragonesMuertos.push_back(tuPersonaje->get_MiDragon());
            tuPersonaje->IncorporarDragon(nullptr);//libero al dragon
            
            cout << "\n" << endl;
            cout << "Los vikingos de la tribu de Draugr te han tomado como prisionero! Esto te debilito tanto que termino con tu vida." << endl;
            cout << "\n" << endl;
            return false;
        }

        if ((*it)->get_salud() <= 0) {
            cout << "Felicidades! acabaste con el vikingo: " << (*it)->get_nombre() << endl;
            cout << "Presiona 'enter' para seguir luchando. " << endl;
            cin.get();
            system("cls");
            it++;
        }
   
    }
    return VikingoMuertos();//si es true mato a todos los malos, si es false

    //
}

void cAdministradora::PrintPeleaVJ(cJinete* jinete, cVikingo* vikingo) 
{
    cout << "\n" << endl;
    jinete->print();
    cout << "\t vs" << endl;
    cout << vikingo->get_nombre() << ":\tsalud: " << vikingo->get_salud() << "\tnivel: " << vikingo->get_level() << "\tataque: " << vikingo->get_ataque() << "\tdefensa: " << vikingo->get_defensa() << endl;
    cout << "\n" << endl;
}
void cAdministradora::PrintPeleaImagen(cDragon* dragon, cVikingo* vikingo) const
{
    cin.get();
    cout << "\t ------------------PELEA------------------" << endl;
    cout << "\n" << endl;
    cout << dragon->get_nombre() << ":\tsalud: " << dragon->get_salud() << "\tnivel: " << dragon->get_level() << "\tataque: " << dragon->get_ataque() << "\tdefensa: " << dragon->get_defensa() << endl;
    cout << "\t vs" << endl;
    cout << vikingo->get_nombre() << ":\tsalud: " << vikingo->get_salud() << "\tnivel: " << vikingo->get_level() << "\tataque: " << vikingo->get_ataque() << "\tdefensa: " << vikingo->get_defensa() << endl;
    cout << "\n" << endl;
}


void cAdministradora::baja_dragon(cDragon* dragon) { //en switch_menu
    if (dragon->get_salud() == 0) {
        cout << "El dragón " << dragon->get_nombre() <<" murió." << endl;
        dragonEliminado(dragon); //se borra de la lista de dragones
    }
}

void cAdministradora::dragonEliminado(cDragon* dragon_muerto) { //en el metodo de arriba
    list<cDragon*> ::iterator it = this->listaDeDragones.begin();
    bool encontrado = false;
    while (it != this->listaDeDragones.end()) {
        if ((*it)->get_nombre() == dragon_muerto->get_nombre()) {
            this->listaDeDragones.erase(it);
            encontrado = true;
            break;
        }
        it++;
    }
}

void cAdministradora::enemigoEliminado(cVikingo* enemigo) { // se usa en swtich_menu. Se borra de la lista de enemigos
    list<cVikingo*> ::iterator it = this->listaDeEnemigos.begin();
    bool encontrado = false;
    while (it != this->listaDeEnemigos.end()) {
        if ((*it)->get_nombre() == enemigo->get_nombre()) {
            this->listaDeEnemigos.erase(it);
            encontrado = true;
            break;
        }
        it++;
    }
    if (!encontrado) {
        throw new exception("Error, no se encontró al enemigo");
    }
}


ostream& operator<<(ostream& os, cDragon& dragon) { //se usa en swtich_menu
    os << "Dragon eliminado: " << "nombre: " << dragon.get_nombre() << ", nivel: " << dragon.get_level() << endl;
    return os;
}

void cAdministradora::jineteEliminado(cJinete* jinete) { //se usa en switch_menu. Se borra de la lista de jinetes
    list<cJinete*> ::iterator it = this->listaDeJinetes.begin();
    bool encontrado = false;
    while (it != this->listaDeJinetes.end()) {
        if ((*it)->get_nombre() == jinete->get_nombre()) {
            this->listaDeJinetes.erase(it);
            encontrado = true;
            break;
        }
        it++;
    }
}

cAdministradora::~cAdministradora()
{
}

//funciones que nunca usamos:
int cAdministradora::buscarDragon(string nombre) {
    int pos = 0;
    bool flag = false;
    list<cDragon*> ::iterator it = this->listaDeDragones.begin();
    while (it != listaDeDragones.end()) {
        if ((*it)->get_nombre() == nombre) {
            flag = true;
            return pos;
        }
        it++;
        pos++;
    }
    if (!flag){
        throw new exception("No se encontró al dragon");
        return -1;
       }
}
void cAdministradora:: operator-=(string nombre) { 
    try {
        list<cDragon*> ::iterator it = this->listaDeDragones.begin();
        int pos = buscarDragon(nombre);
        advance(it, pos);
        listaDeDragones.erase(it);
    }
    catch (const exception* e) {
        cout << e->what() << endl;
    }
}

void cAdministradora::vikingoEliminado(cVikingo* vikingo) { // va para listaDeVikingos
    list<cVikingo*> ::iterator it = this->listaDeVikingos.begin();
    bool encontrado = false;
    while (it != this->listaDeVikingos.end()) {
        if ((*it)->get_nombre() == vikingo->get_nombre()) {
            this->listaDeVikingos.erase(it);
            encontrado = true;
            break;
        }
        it++;
    }
    if (!encontrado) {
        throw new exception("Error, no se encontró al vikingo");
    }
}


int cAdministradora::CantidadEnemigos()
{
    return listaDeEnemigos.size();
}

int cAdministradora::CantidadVikingos()
{
    return listaDeVikingos.size();
}



bool cAdministradora::VikingoMuertos()
{
 //Que hace esta funcion: recorre la lista de los enemigos, y se fija su salud. en caso de que esten vivos retorna falso
 //si todos los vikingos estan muertos retorna verdadero
    list <cVikingo*>::iterator it = this->listaDeEnemigos.begin();//me creo el iterator
    while (it != listaDeEnemigos.end()) {
        if ((*it)->get_salud() != 0) {
            return false;
        }
        it++;
    }
    return true;
}








