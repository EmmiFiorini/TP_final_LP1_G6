﻿#include "cAdministradora.h"


cAdministradora::cAdministradora()
{
}

cAdministradora::~cAdministradora()
{
}

int cAdministradora::CantidadEnemigos()
{
	return listaDeEnemigos.size();
}

int cAdministradora::CantidadVikingos()
{
    return listaDeVikingos.size();
}

void cAdministradora::llamarATribu(cDragon* dragonAAtacar) //recorre la lista de vikingos y genera un combate con el mismo dragón (un combate para c/vikingo)
{
	list <cVikingo*>::iterator it = this->listaDeEnemigos.begin();
	while (it != listaDeEnemigos.end() && (*it)->get_salud()!=0 || dragonAAtacar->get_salud()!=0) {
        combate(dragonAAtacar, (*it));
        it++;
	}
}


void cAdministradora::combate(cDragon* dragon, cVikingo* vikingo)//hay q re pensarla
{
    PrintPeleaImagen(dragon, vikingo);
    if (dragon->get_defensa() > vikingo->get_ataque() && dragon->get_ataque() > vikingo->get_defensa()) {
        vikingo->set_salud(vikingo->get_salud() - 50);
    }
    else if (dragon->get_defensa() < vikingo->get_ataque() && dragon->get_ataque() < vikingo->get_defensa()) {
        dragon->set_salud(dragon->get_salud() - 50);
    }
    else {
        dragon->set_salud(dragon->get_salud() - 25);
        vikingo->set_salud(vikingo->get_salud() - 25);
    }
    //ya habiendo sido la pelea, vuelvo a imprimir los datos de cada uno
    PrintPeleaImagen(dragon, vikingo);

    if (vikingo->get_salud() <= 0) {
        cout << "Felicidades! acabaste con el vikingo: " << vikingo->get_nombre() << endl;//Se llama a la funcion "baja"
    }

    if (dragon->get_salud() <= 0) {
        throw new exception("muerte de dragon"); //se cae el jinte de arriba del dragon y pierde 70 de vida, si sigue vivo tiene q peliar el solo contra los vikingos malos
    }
}

void cAdministradora::historia()
{
    cout << "COMO ENTRENAR A TU DRAGON 2.0, version de Pili y Emma" << endl;
    cout << "Presiona 'enter' para empezar!" << endl;
    cin.get();

    cout << "En el anio 1010, la isla de Berk vivia en paz y armonia." << endl;
    cout << "Hasta que un dia aparecieron los malvados vikingos de la tribu Draugr, que atacaron la aldea" << endl;
    cout << "y asesinaron a muchos de sus aldeanos." << endl;
    cin.get();

    cout << "\n" << endl;
    cout << "\t" << "     _.-^^---....,,--       " << endl;
    cout << "\t" << " _--                  --_  " << endl;
    cout << "\t" << "<                        >)" << endl;
    cout << "\t" << "|                         | " << endl;
    cout << "\t" << " \._                   _./  " << endl;
    cout << "\t" << "    ```--. . , ; .--'''       " << endl;
    cout << "\t" << "         | |   |             " << endl;
    cout << "\t" << "      .-=||  | |=-.   " << endl;
    cout << "\t" << "      `-=#$%&%$#=-'   " << endl;
    cout << "\t" << "         | ;  :|     " << endl;
    cout << "\t" << "_____.,-#%&$@%#&#~,._____" << endl << endl;
   
    cin.get();
    cout << "\n" << endl;
    cout << "\n" << endl;

    cout << "Ese mismo dia, Estoico el Vasto, el jefe de la aldea, designo un grupo de jovenes valientes vikingos" << endl;
    cout << "que domarian dragones." << endl;
    cout << "Si logran pasar la prueba del jefe de seguridad Bocon, formaran parte de un grupo de elite encargado" << endl;
    cout << "de defender a la aldea de las tribus enemigas." << endl;
    cout << "\n" << endl;

    cout << "\t" << " <>=======() " << endl;
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
    cout << "Presiona 'enter' para comenzar" << endl;
    cin.get();
    system("cls");
}

void cAdministradora::dragonEliminado(cDragon* dragon_muerto) {
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
    if (!encontrado) {
        throw new exception("Error, no se encontró el dragón");
    }
}

void cAdministradora::baja_dragon(cDragon* dragon) {
    if (dragon->get_salud() == 0) {
        cout << "El dragón murió" << endl;
        dragonEliminado(dragon);
    }
}

void cAdministradora::enemigoEliminado(cVikingo* enemigo) { // va para listaDeEnemigos
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

void cAdministradora::AgregarVikingo(cVikingo* vikingo)
{
    this->listaDeVikingos.push_back(vikingo);

}

void cAdministradora :: operator+=(cDragon *drago) {
    listaDeDragones.push_back(drago);
}

ostream&  operator<<(ostream& os, cDragon& dragon) {
    os << "Dragon eliminado : "<< "nombre : "<<dragon.get_nombre() << ", nivel : " << dragon.get_level()<< endl;
    return os;
}

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


void cAdministradora::NuevoVikingoM(cVikingo* nuevoVikM)
{
    this->listaDeEnemigos.push_back(nuevoVikM);

}
void cAdministradora::PruebaBocon(cJinete* jinete) {
    cout << "'Bienvenido " << jinete->get_nombre() << " a mi prueba, soy Bocon. Buen dragon el tuyo, camarada!'" << endl << endl;
    cout << "'Estas listo para la prueba?'" << endl;
    cout << "'Recuerda: el futuro de nuestra tribu esta en tus manos... Solo te lo recuerdo, sin presion!'" << endl;
    cout << "\n" << endl;
    cout << "\t" << "LA PRUEBA DE BOCON:" << endl;
    cout << "\t" << "Responde las preguntas correctamente para tener la mejor nota de la clase!" << endl;
    cin.get();
    
    float nota = 0;

    

    cout << "\t" << "Quien es el novio de la dragona en la pelicula 'Shrek'?" << endl;
    cout << "\t1)Burro\n \t2)Shrek\n \t3)El Gato con Botas" << endl;
    cout << "Ingresa el numero de tu respuesta: ";
    cin.get();
    int respuesta1 = 0;
    cin >> respuesta1;
    if (respuesta1 == 1) {
        nota += 10;
    }
    cout << "\n" << endl;
    cout << "\n" << endl;

    cout << endl << "\t" << "Cuantos dragones tiene la protagonista Daenerys de la serie 'Games of thrones'?" << endl;
    cout << "\t1)0\n \t2)2\n \t3)3" << endl;
    cout << "Ingresa el numero de tu respuesta: ";
    cin.get();
    int resp2;
    cin >> resp2;
    if (resp2 == 3) {
        nota += 10;
    }
    
    cout << "\n" << endl;
    cout << "\n" << endl;

    cout << endl << "\t" << "En la pelicula 'La Bella Durmiente', quien se trasforma en dragon?" << endl;
    cout << "\t1) Aurora\n \t2)Malefica\n \t3)Ningun personaje" << endl;
    cout << "Ingresa el numero de tu respuesta: ";
    cin.get();
    int resp3;
    cin >> resp3;
    
    if (resp3 == 2) {
        nota += 10;
    }
    
    cout << "\n" << endl;
    cout << "\n" << endl;
    
    cout << endl << endl << "Ya terminaste la prueba!" << endl << "\tTu nota es: " << nota << "/30" << endl << "Tu resultado es: " << endl;
    if (nota == 30) // noAsistio = 0, aprobado = 4, desaprobado = 3, primero = 10, ultimo = 1
        jinete->set_result(primero);
    else if (nota == 20)
        jinete->set_result(aprobado);
    else if (nota == 10)
        jinete->set_result(desaprobado);
    else if (nota == 0)
        jinete->set_result(ultimo);

    jinete->printResultado();

    if (nota == 10 || nota == 0) {
        throw exception("Prueba desaprobada");
    }
}


void cAdministradora::PrintPeleaImagen(cDragon* dragon, cVikingo* vikingo) const
{
    cout << dragon->get_nombre() << ":\tsalud: " << dragon->get_salud() << "\tnivel: " << dragon->get_level() << "\tataque: " << dragon->get_ataque() << "\tdefensa: " << dragon->get_defensa() << endl;
    cout << "\t vs" << endl;
    cout << vikingo->get_nombre() << ":\tsalud: " << vikingo->get_salud() << "\tnivel: " << vikingo->get_level() << "\tataque: " << vikingo->get_ataque() << "\tdefensa: " << vikingo->get_defensa() << endl;
}

int cAdministradora::menu(cJinete* jinete)
{
    int option;//creo la opcion q va a elegir el usuario
    if (jinete->get_MiDragon() == nullptr) {//si no tiene dragon, solamente le aparece asi
        cout << "\t MENU:" << endl;
        cout << "1) Buscar Dragon" << endl;
        cout << "6) Salir" << endl;
    }
    else if (jinete->get_Result() == noAsistio || jinete->get_Result() == desaprobado) {
        cout << "\t MENU:" << endl;
        cout << "2) Prueba Bocon" << endl;
        cout << "6) Salir" << endl;
    }
    else {
        cout << "\t MENU:" << endl;
        cout << "3) Entrenar Dragon" << endl;
        cout << "4) Curandero" << endl;
        cout << "5) Pelea contra todos los enemigos" << endl;
        cout << "6) Salir" << endl;
    }
    cout << "Ingrese la opcion:" << endl;
    cin >> option;
    cin.get();
    return option;

}



void cAdministradora::buscarDragon(cJinete* jinete) {
    bool flag = false;
    
    cin.get();
    cout << "Con el primer rayo de sol, me adentre al bosque de los Susurros. Camine con cautela, siguiendo el camino que mis ancestros me habian indicado, hasta que se bifurco en dos:" << endl;
    cout << "uno mostraba huellas peculiares… no podria decir de que animal en especifico. El otro era un camino llano, no mostraba signos de que habia sido recorrido. Cual voy a elegir? " << endl;
    cout << "\n" << endl;
    cout << "\t" << "Ingrese A si quiere ir por el camino con huellas; ingrese B si quiere ir por el camino llano" << endl;
    // la respuesta incorrecta es la A
    char respuesta1;
    cin.get();
    
    cin >> respuesta1;

    if (respuesta1 == 'B'|| respuesta1 == 'b') {
        cout << "Me adentre por el camino llano, confiado en que mis ancestros me guiarian. Sin embargo, aparecio una niebla densa y el paisaje se torno confuso. Me encontre desorientado, rodeado por la niebla" << endl;
        cout << "\t" << "No llegaste a ningun dragon! Presiona 'enter' para volver a la aldea y volver a intentarlo" << endl;
        return;
    } else {
        cout << "Decidi seguir las huellas, sin saber a que criatura pertenecian. Camine durante horas siguiendo este rastro. La vegetación se hacia mas densa" << endl;
        cout << "De repente, las huellas desaparecieron en una zona pantanosa, y frente a mi el camino se dividio en dos:" << endl;
        cout << "uno llevaba hacia una colina empinada, cubierta de espinas, y el otro descendia hacia un valle oscuro. Debía decidir: subir la colina espinosa o descender al valle sombrio?" << endl;
        cout << "\n" << endl;
        cout << "\t" << "Ingrese A si quiere ir subir por la colina espinosa; ingrese B si quiere descender por el valle sombrio" << endl;
        // la respuesta incorrecta es la 1
        char respuesta2;
        cin.get();
        cin >> respuesta2;
        if (respuesta2 == 'A' || respuesta2 == 'a') {
            cout << "Decidi enfrentar la colina espinosa. Sin embargo, las espinas eran mas traicioneras de lo que imagine. Cada paso era una lucha, y pronto me encontre atrapado, con las espinas rasgando mi ropa" << endl;
            cout << "Perdi mucho tiempo y, finalmente, tuve que retroceder, herido y frustrado" << endl;
            cout << "\t" << "No llegaste a ningún dragon! Presiona 'enter' para volver a la aldea y volver a intentarlo" << endl;
            return;
        }
        else {
            cout << "Tome el camino hacia el valle sombrio. La oscuridad era densa. Sin embargo, segui avanzando, sintiendo que estaba en el camino correcto. De repente, el valle se abrio en un claro iluminado por una luz azulada" << endl;
            cout << "En el centro, descansando majestuosamente, estaba el dragon. Me acerque con cautela, recitando las palabras que mis ancestros me habian enseñado. El dragon levanto su cabeza y se quedo observandome" << endl;
            cout <<"Debia tomar una decision final: mostrarme respetuoso, esperando que el dragon aceptara mi presencia, o intentar imponerme, demostrando mi fuerza. Sabia que solo una opcion me llevaria a ganarme su confianza" << endl;
            cout << "\n" << endl;
            cout << "\t" << "Ingrese A si quiere mostrarse respetuoso con el dragon; ingrese B si quiere imponerse ante al dragon" << endl;
            // la respuesta incorrecta es la 2
            char respuesta3;
            cin.get();
            cin >> respuesta3;
            if (respuesta3 == 'B' || respuesta3 == 'b') {
                cout << "Opte por imponer mi fuerza. Me acerque al dragon con firmeza, levantando mi voz y mostrando una postura desafiante. Sin embargo, el dragon no se impresiono. Rugio de tal forma que el suelo temblo bajo mis pies." << endl;
                cout << "Luego, lanzo una rafaga de fuego que me obligo a retroceder rapidamente. Tropece y cai al suelo, comprendiendo mi error.La fuerza bruta no era el camino para ganar su respeto. Me retire hacia la aldea, sabiendo la oportunidad que habia perdido" << endl;
                cout << "\t" << "No llegaste a ningun dragon! Presiona 'enter' para volver a la aldea y volver a intentarlo" << endl;
                return;
            }
            else {
                flag = true;
                cout << "Me incline ante el dragon, mostrando respeto y humildad. El dragon, sorprendentemente, bajo su cabeza y me permitio tocar sus escamas.Con cuidado, subi a su lomo. Juntos, volamos hacia la aldea. Habia domado a mi primer dragon" << endl;
                cout << "\n" << endl;
                system("cls");
                cin.get();
                cout << "\t" << "Felicitaciones! Domaste a tu dragon. A continuacion, ingresa el nombre de tu nuevo dragon: " << endl;
                string nombreD;
                cin >> nombreD;
                cin.get();
                cout << "\t" << "Que caracteristica fisica tiene?" << endl;
                string caractD;
                cin >> caractD;
                cin.get();
                cout << "\t" << "Que color tiene ?" << endl;
                string colorD;
                cin.get();
                cin >> colorD;

                cDragon* tuDragon = new cDragon(nombreD, caractD, mediano, colorD, true, "", 0, 0, 100);
                jinete->IncorporarDragon(tuDragon);
                cout << "\n" << endl;
                cout << "\t" << "Dragon creado! Ingresa 'enter' para volver a la aldea y seguir con tu aventura " << endl;
                cin.get();
            }
        }
    }
    if (!flag) {
        throw new exception("No se encontro el dragon");
        return;
    }
}

