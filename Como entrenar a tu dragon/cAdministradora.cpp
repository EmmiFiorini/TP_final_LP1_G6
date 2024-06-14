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



void cAdministradora::buscarDragon(cJinete* jinete) {
    cout << "Con el primer rayo de sol, me adentré al bosque de los Susurros.Caminé con cautela, siguiendo el camino que mis ancestros me habían indicado, hasta que se bifurcó en dos: uno mostraba huellas peculiares… no podría decir de qué animal en específico.El otro era un camino llano, no mostraba signos de que habia sido recorrido ¿Cuál voy a elegir ?" << endl;
    cout << "\t" << "Ingrese A si quiere ir por el camino con huellas; ingrese B si quiere ir por el camino llano" << endl;
    // la respuesta incorrecta es la 2
    char respuesta1;
    cin >> respuesta1;
    getchar();
    if (respuesta1 == 'B'|| respuesta1 == 'b') {
        cout << "Me adentré por el camino llano, confiado en que mis ancestros me guiarian.Sin embargo, apareció una niebla densa y el paisaje se tornó confuso.Me encontré desorientado, rodeado por la niebla" << endl;
        cout << "\t" << "¡No llegaste a ningún dragón!Presiona enter para volver a la aldea y volver a intentarlo" << endl;
        getchar();
        return;
    }
    else {
        cout << "Decidí seguir las huellas, sin saber a qué criatura pertenecían.Caminé durante horas siguiendo este rastro.La vegetación se hacía más densa.De repente, las huellas desaparecieron en una zona pantanosa, y frente a mí el camino se dividía en dos; uno llevaba hacia una colina empinada, cubierta de espinas, y el otro descendía hacia un valle oscuro.Debía decidir : ¿subir la colina espinosa o descender al valle sombrío ? " << endl;

        cout << "\t" << "Ingrese “1” si quiere ir subir por la colina espinosa; ingrese “2” si quiere descender por el valle sombrio" << endl;
        // la respuesta incorrecta es la 1
        char respuesta2;
        cin >> respuesta2;
        if (respuesta2 == '1') {
            cout << "Decidí enfrentar la colina espinosa.Sin embargo, las espinas eran más traicioneras de lo que imaginé.Cada paso era una lucha, y pronto me encontré atrapado, con las espinas rasgando mi ropa.Perdí mucho tiempo y, finalmente, tuve que retroceder, herido y frustrado" << endl;
            cout << "\t" << "¡No llegaste a ningún dragón!Presiona enter para volver a la aldea y volver a intentarlo" << endl;
            getchar();
            return;
        }
        else {
            cout << "Tome el camino hacia el valle sombrío.La oscuridad era densa.Sin embargo, segui avanzando, sintiendo que estaba en el camino correcto.De repente, el valle se abrió en un claro iluminado por una luz azulada" << endl;
            cout << "En el centro, descansando majestuosamente, estaba el dragón.Me acerqué con cautela, recitando las palabras que mis ancestros me habian enseñado.El dragon levantó su cabeza y se quedó observandome.Debia tomar una decision final: mostrarme respetuoso, esperando que el dragon aceptara mi presencia, o intentar imponerme, demostrando mi fuerza.Sabia que solo una opcion me llevaria a ganarme su confianza" << endl;
            cout << "\t" << "Ingrese “1” si quiere mostrarse respetuoso con el dragon; ingrese “2” si quiere imponerse ante al dragon" << endl;
            // la respuesta incorrecta es la 2
            char respuesta3;
            cin >> respuesta3;
            if (respuesta3 == '2') {
                cout << "Opte por imponer mi fuerza.Me acerque al dragon con firmeza, levantando mi voz y mostrando una postura desafiante.Sin embargo, el dragon no se impresiono.Rugio de tal forma que el suelo temblo bajo mis pies.Luego, lanzo una rafaga de fuego que me obligo a retroceder rapidamente.Tropece y cai al suelo, comprendiendo mi error.La fuerza bruta no era el camino para ganar el respeto de una criatura tan majestuosa.Me retiré hacia mi aldea, sabiendo la oportunidad que habia perdido" << endl;
                cout << "\t" << "¡No llegaste a ningún dragón!Presiona enter para volver a la aldea y volver a intentarlo" << endl;
                getchar();
                return;
            }
            else {
                cout << "Me incliné ante el dragon, mostrando respeto y humildad.El dragon, sorprendentemente, bajo su cabeza y me permitio tocar sus escamas.Con cuidado, subi a su lomo.Juntos, volamos hacia la aldea.Oficialmente, habia domado a mi primer dragon" << endl;
                cout << "\t" << "¡Felicitaciones!Domaste a tu dragon.A continuación, ingresa el nombre de tu nuevo dragon : " << endl;
                string nombreD;
                cin >> nombreD;
                cout << "\t" << "¿Que caracteristica fisica tiene ?" << endl;
                string caractD;
                cin >> caractD;
                cout << "\t" << "¿Qué color tiene ?" << endl;
                string colorD;
                cin >> colorD;

                cDragon* tuDragon = new cDragon(nombreD, caractD, mediano, colorD, true, "", 0, 0, 100);
                jinete->IncorporarDragon(tuDragon);

                cout << "\t" << "¡Dragon creado!Ingresa “enter” para volver a la aldea y seguir con tu aventura " << endl;
                getchar();
            }
        }
    }
}

