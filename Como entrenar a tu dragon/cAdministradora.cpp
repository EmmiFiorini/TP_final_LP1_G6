#include "cAdministradora.h"


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
	while (it != listaDeEnemigos.end()) {
        combate(dragonAAtacar, (*it));
        it++;
	}
}

void cAdministradora::combate(cDragon* dragon, cVikingo* vikingo)
{
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
    if (vikingo->get_salud() <= 0)
        throw new exception("muerte de vikingo"); //el try catch se hace en el main. Se llama en el main a la funcion "baja"

    if (dragon->get_salud() <= 0) {
        throw new exception("muerte de dragon"); //se cae el jinte de arriba del dragon y pierde 70 de vida, si sigue vivo tiene q peliar el solo contra los vikingos malos
    }
}

void cAdministradora::historia()
{
    cout << "COMO ENTRENAR A TU DRAGON" << endl;
    getchar();

    cout << "En el año 1010, la isla de Berk vivía en paz y armonía." << endl;
    cout << "Hasta que un día aparecieron los malvados vikingo de la tribu Draugr que atacaron la aldea y asesinaron a muchos aldeanos." << endl;
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
    getchar();


    cout << "Ese mismo dia  Estoico el Vasto, el jefe de la aldea, designo un grupo de jóvenes valientes vikingos que domarian dragones" << endl;
    cout << "y si pasan la prueba del jefe de seguridad Bocon, serían parte de un grupo de élite encargado de defender a la aldea de los enemigos." << endl << endl;
    
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
    getchar();
    cout << "Desde ese día tú, decidiste  que el querías formar parte de aquel grupo, para vengar aquellos hermanos Bercianos muertos en manos de la despiadada Ulf y sus guerreros. " << endl;
    cout << "Comienza tu aventura, domando a un dragon, pasando la prueba de Bocon y luego enfrentarse a todos los vikingos enemigos!" << endl << endl<<endl;
    
    cout << "Presiona enter para comenzar tu aventura:" << endl;
    getchar();
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

void cAdministradora::PruebaBocon(cJinete* jinete)
{
    cout << "Bienvenido " << jinete->get_nombre() << " a mi prueba, soy Bocon." << endl;
    cout << "Buen dragon el tuyo camarada" << endl << endl;
    cout << "Estas listo para la prueba?" << endl;
    cout << "Recuerda el futuro de nuestra tribu esta en tus manos...." << endl;
    cout << "Solo te lo recuerdo, sin presion..." << endl << endl << endl;

    cout << "\t" << "LA PRUEBA DE BOCON:" << endl << endl << endl;
    char rta;
    float nota = 0;

    cout << "\t" << "¿Quien es el novio de la dragona en Shrek?" << endl;
    cout << "\t a) Burro\n \tb)Shrek\n \tc)El Gato con Botas" << endl;
    cout << "Ingresa la letra de tu respuesta: ";
    cin >> rta;
    switch (rta) //donde opción es la variable a comparar
    {
    case 'a' || 'A': {
        nota = nota + 10;
        break;
    }
    case 'b': //Bloque de instrucciones 2;
        nota = nota + 0;
        break;
    case 'B': //Bloque de instrucciones 3;
        nota = nota + 0;
        break;
    case 'c': //Bloque de instrucciones 3;
        nota = nota + 0;
        break;
    case 'C': //Bloque de instrucciones 3;
        nota = nota + 0;
        break;
    default: 
        nota = nota + 0;
        break;
    }

    cout <<endl<< "\t" << "¿Cuantos dragones tiene Daenerys?" << endl;
    cout << "\t a) 0\n \tb)2\n \tc)3" << endl;
    cout << "Ingresa la letra de tu respuesta: ";
    cin >> rta;
    switch (rta) //donde opción es la variable a comparar
    {
    case 'c' || 'C': {
        nota = nota + 10;
        break;
    }
    case 'b': //Bloque de instrucciones 2;
        nota = nota + 0;
        break;
    case 'B': //Bloque de instrucciones 3;
        nota = nota + 0;
        break;
    case 'a': //Bloque de instrucciones 3;
        nota = nota + 0;
        break;
    case 'A': //Bloque de instrucciones 3;
        nota = nota + 0;
        break;
    default:
        nota = nota + 0;
        break;
    }
    cout << endl << "\t" << "En la Bella Durmiente, ¿Quien se trasforma en dragon?" << endl;
    cout << "\t a) Aurora\n \tb)Malefica\n \tc)Nadie" << endl;
    cout << "Ingresa la letra de tu respuesta: ";
    cin >> rta;
    switch (rta) //donde opción es la variable a comparar
    {
    case 'b' || 'B': {
        nota = nota + 10;
        break;
    }
    case 'c': //Bloque de instrucciones 2;
        nota = nota + 0;
        break;
    case 'C': //Bloque de instrucciones 3;
        nota = nota + 0;
        break;
    case 'a': //Bloque de instrucciones 3;
        nota = nota + 0;
        break;
    case 'A': //Bloque de instrucciones 3;
        nota = nota + 0;
        break;
    default:
        nota = nota + 0;
        break;
    }
    cout << endl << endl << "Ya terminaste la prueba" << endl << "\tTu nota es: " << nota << "/30" << endl << "Tu resultado es: " << endl;
    if (nota == 30)//noAsistio = 0, aprobado = 4, desaprobado = 3, primero = 10, ultimo = 1
        jinete->set_result(primero);
    if (nota == 10)
        jinete->set_result(desaprobado);
    if (nota == 0)
        jinete->set_result(ultimo);
    if (nota == 20)
        jinete->set_result(aprobado);
    jinete->printResultado();
    if (nota == 10 || nota == 0) {
        throw new exception("Prueba desaprobada");
    }
}

void cAdministradora::PrintPeleaImagen() const
{
    cout << "Imprimir un dibujo!" << endl;
}

