#include "main.h"

int main() {
    menuGeneral();
    return 0;
}

void menuGeneral(){
    unordered_map<int, string> mapaTH;mapaTH[1] = "Selvatico";mapaTH[2] = "Bosque"; mapaTH[3] = "Desertico";mapaTH[4] = "Polar";
    /*
    MAPA CON INFORMACION DE LOS DISTINTOS HABITAT CREABLES DENTRO DEL ZOOLOGICO
    */
    mapaTH[5] = "Oceanico"; mapaTH[6] = "Acuatico Dulce"; mapaTH[7] = "Montañoso"; mapaTH[8] = "Tropical"; mapaTH[9] = "Sabana";
    /*
     MAPA CON INFORMACION DE LOS DISTINTAS ADECUACIONES PARA LOS HABITATS CREABLES DENTRO DEL ZOOLOGICO
     */
    unordered_map<int, string> mapaTA;mapaTA [1] = "Terrestre";mapaTA[2] = "Volador"; mapaTA[3] = "Acuatico";mapaTA[4] = "Semi Acuatico";


    Habitad* TemHabitat ;
   // Inicializo Zoologico
    Zoologico* zoologicoGeneral = new  Zoologico("ANIMALES INCREIBLES - CALI");
    Criadero* criadero = new Criadero(0,0,0,0);

    // Guardadores info y baderas
    int obc,ban,lol;
    int guardaRes,guardaRes2,guadaRes3;
    //opcion 2 general
    int  resAdecuacion, resTipoDieta ,resTipoHa;
    // opcoion 3/4 general
    int BusH;

    do {
        cout << "\n\n\n*** | Bienvenido al Zoologico " << zoologicoGeneral->getNombreZoo() << " | **\n";
        cout << "[1] Ver mapa Zoologico \n";
        cout << "[2] Crear habitat \n";
        cout << "[3] Ver Habitat \n";
        cout << "[4] Eliminar Habitad del Zoologico \n";
        cout << "[5] Mover Animal de Habitat\n";
        cout << "[6] Criadero\n";
        cout << "[0] Salir del Zoologico \n\n";
        cout << "Ingrese la obcion deseada: ";
        try{
            cin >> obc;cin.ignore();
            if(cin.fail()){
                obc = 10;
                throw runtime_error("Entrada invalida solo aceptan numeros enteros.");
            }
        }catch (const exception& e) { cout <<"Error: " << e.what() << endl;}
        cin.ignore(); clear();
        switch (obc) {
            case 1:
                if (zoologicoGeneral->getTotalH() == 0) {
                    cout << "No hay habitats dentro del Zoologico, cree uno nuevo e ingrese animales.\n\n";
                } else {
                    zoologicoGeneral->verMapaZoologico();
                }
                break;
            case 2:
                try {
                    cout << "Creeando nuevo habitat ingrese la siguiente informacion\n";
                    cout << "Ingrese el Tipo de adecuacion que tendra el habitat\n";
                    resAdecuacion = panelAdecucion(); cin.ignore(); clear();
                    cout << "Ingrese la dieta de los animales que condra el habitat\n";
                    resTipoDieta = paneltipodieta(); cin.ignore(); clear();
                    cout << "Ingrese el Tipo de Habitat \n";
                    resTipoHa = panelTipoHabi(); cin.ignore(); clear();
                    if(resTipoHa == -1 || resTipoDieta == -1 || resAdecuacion == -1 ){
                        throw runtime_error("No es posible continuar con el proceso.\n¡Intentelo nuevamente¡\n");
                    }else{
                        TemHabitat = new Habitad(mapaTH[resTipoHa], resTipoHa,resTipoDieta, resAdecuacion,0,mapaTA[resAdecuacion]);
                        zoologicoGeneral->setCreadorKeysM();// Crea un key unica para el habitat nuevo
                        guardaRes = zoologicoGeneral->agregarHabitad(zoologicoGeneral->getCreadorKeys(),TemHabitat);
                        if(guardaRes == 1){ // Aumente en 1 el total de Habitats dentro del zoo
                            zoologicoGeneral->setTotalH(1);
                            cout << "El habitat fue ingresado correctamente.\n";
                        }
                    }
                }catch (const exception& e) {
                    cout <<"Error: " << e.what() << endl;
                }cin.ignore(); clear();

                break;
            case 3:
                try {
                    cout << "Ingrese un Key de habitat: ";
                     cin >> BusH;cin.ignore();
                    if (cin.fail()) {
                        throw runtime_error("Entrada invalida solo aceptan numeros enteros.");
                    }else{
                        TemHabitat = zoologicoGeneral->entrarHabitad(BusH);
                        if(TemHabitat != nullptr){
                            submenuHabitad(zoologicoGeneral,TemHabitat,mapaTH,mapaTA, BusH,criadero); //Menu dentro de Habitad

                        }else{ cout << "El Habitat no fue encontrado\n";}
                    }
                }
                catch (const exception& e) { cout <<"Error: " << e.what() << endl;
                }


                break;
            case 4:
                try {
                    cout << "[--] Elimar Habitat del Zoologico [--]\n";
                    cout << "Ingrese un Key de habitat: ";
                    cin >> BusH;cin.ignore();
                    if (cin.fail()) {
                        throw runtime_error("Entrada invalida solo aceptan numeros enteros.");
                    }else{
                        guardaRes = zoologicoGeneral->eliminarHabitad(BusH);
                        if(guardaRes != 1) {
                            cout << "No pudo eliminarse con exito\n";
                        }
                        else{
                            zoologicoGeneral->setTotalH(-1);
                        }
                    }
                }
                catch (const exception& e) { cout <<"Error: " << e.what() << endl;
                }


                break;
            case 5:
                cout << " **** Mover Animal de habitat ****  \n Ingrese el Id del Habitat donde se encuentra el animal ";
                guardaRes =  resivirobcion();
                cout << "Ingrese el Id del animal dentro del habitat";
                guardaRes2 = resivirobcion();
                cout << "Ingrese el Id del Habitat de Llegada";
                guadaRes3 = resivirobcion();
                if(guardaRes == -1| guardaRes2 == -1 | guadaRes3 == -1){
                    cout << "Entrada incorrecta, intentelo nuevamente\n";
                }else{
                    ban = zoologicoGeneral->moverAnimalH(guardaRes,guardaRes2, guadaRes3);
                    if(ban == 1){
                        cout << "Proceso exitoso\n";
                    }else{
                        cout << "Fallo de proceso\n";

                    }
                }

                break;
            case 6: 
                  do {
                     cout << "[1] Terrestres\n";
                     cout << "[2] Voladoras\n";
                     cout << "[3] Acuaticas\n";
                     cout << "[4] Semi Acuaticas\n";
                     cout << "[0] Salir\n";
                     cout << "Ingrese la opcion: ";
                     try{
                        cin >> lol;cin.ignore();
                        if(cin.fail()){
                        lol = 10;
                        throw runtime_error("Entrada invalida solo aceptan numeros enteros.");
                      }
                    }catch (const exception& e) { cout <<"Error: " << e.what() << endl;}
                     cin.ignore(); clear();
                     switch(lol){
                       case 1: 
                        
                              if(criadero->get_cantT()>0){
                                criadero->mostrarCrias(0);
                              }else{
                                cout << "No hay crias" << endl;
                              }
                         break;
                       case 2:
                              if(criadero->get_cantV()>0){
                                criadero->mostrarCrias(1);
                              }else{
                                cout << "No hay crias" << endl;
                              }
                             break;
                       case 3: 
                              if(criadero->get_cantA()>0){
                                criadero->mostrarCrias(2);
                              }else{
                                cout << "No hay crias" << endl;
                              }
                              break;
                       case 4: 
                              if(criadero->get_cantSA()>0){
                                criadero->mostrarCrias(3);
                              }else{
                                cout << "No hay crias" << endl;
                              }
                              break;
                       default: break;
                     }
                    cin.ignore(); clear();

                  }while(lol!=0);

            default:
                break;
        }
        cin.ignore(); clear();
        
        }while (obc != 0);

    };

int panelAdecucion(){
    int opcP ;
    do {
        cout << "[1] Terrestres\n";
        cout << "[2] Voladoras\n";
        cout << "[3] Acuaticas\n";
        cout << "[4] Semi Acuaticas\n";
        cout << "[0] Salir\n";

        try {
            cout << "Elija una de esas opciones: ";
            cin >> opcP;cin.ignore();
            if (cin.fail()) {
                opcP = -1;
                throw runtime_error("Entrada invalida solo aceptan numeros enteros.");
            }else if(opcP <= 0 || opcP > 4){

                if(opcP == 0){
                    opcP = -1;
                }else{
                    opcP = -1;
                    throw range_error("Opcion invalida.");
                }

            }else{
                return opcP;
            }
        }
        catch (const exception& e) {
            cout <<"Error: " << e.what() << endl;
        }
        cin.ignore(); clear();

    }while(opcP >= 0 && opcP <=4);
    return opcP;

}
int paneltipodieta(){
    int opcP ;
    do {
        cout << "[1] Carnivoros\n";
        cout << "[2] Herbivoros\n";
        cout << "[3] Omnivoros\n";
        cout << "[0] Salir\n";

        try {
            cout << "Elija una de esas opciones: ";
             cin >> opcP;cin.ignore();
            if (cin.fail()) {
                opcP = -1;
                throw runtime_error("Entrada invalida solo aceptan numeros enteros.");
            }else if(opcP <= 0 || opcP > 3){
                if(opcP == 0){
                    opcP = -1;
                }else{
                    opcP = -1;
                    throw range_error("Opcion invalida.");
                }
            }else{
                return opcP;
            }
        }
        catch (const exception& e) {
            cout <<"Error: " << e.what() << endl;
        }
      cin.ignore(); clear();

    }while(opcP >= 0 && opcP <=3);

    return opcP;

}
int panelTipoHabi(){
    int opcP ;
    do {
        cout << "[1] Selvatico\n"; cout << "[2] Bosque\n";
        cout << "[3] Desertico\n"; cout << "[4] Polar\n";
        cout << "[5] Oceanico\n"; cout << "[6] Acuatico Dulce\n";
        cout << "[7] Montañoso\n"; cout << "[8] Tropical\n";
        cout << "[9] Sabana\n"; cout << "[0] Salir\n";

        try {
            cout << "Elija una de esas opciones: ";
             cin >> opcP;cin.ignore();
            if (cin.fail()) {
                opcP = -1;
                throw runtime_error("Entrada invalida solo aceptan numeros enteros.");
            }else if(opcP <= 0 || opcP > 9){
                if(opcP == 0){
                    opcP = -1;
                }else{
                    opcP = -1;
                    throw range_error("Opcion invalida.");
                }
            }else{
                return opcP;
            }
        }
        catch (const exception& e) {
            cout <<"Error: " << e.what() << endl;
        }
      cin.ignore(); clear();

    }while( opcP <=8 && opcP >= 0);


    return opcP;
}
int resivirobcion(){
    int opc;
    try {
        cout << ": ";
        cin >> opc;cin.ignore();
        if (cin.fail()) {
            throw runtime_error("Entrada invalida solo aceptan numeros enteros Positivos.");
        }else if(opc < 0){
            throw logic_error("Entrada invalida solo aceptan numeros enteros Positivos.");
        }
        else{
            return opc;
        }
    }catch (const exception& e) { cout <<"Error: " << e.what() << endl;}
    cin.ignore(); clear();
    return -1;
}
Animal* crearAnimal(Zoologico* zoo,unordered_map<int, string>& mapaTH){
    string guarda, nombre;
    int opcAde,opcTH,opcDieta, edad,sexo;

    cout << " [---------] Ingreso nuevo Animal al Zoologico "<< zoo->getNombreZoo() << " [---------] \n";
    cout << "Ingrese la especie del Animal: ";
    getline(cin, guarda,'\n');
    cin.ignore();
    transform(guarda.begin(), guarda.end(), guarda.begin(), [](unsigned char c){ return tolower(c); });
    cout << "Ingrese el Tipo de habitat que nesecita el Animal\n";
    opcTH = panelTipoHabi(); cin.ignore(); clear();
    cout << "Ingrese el Tipo de Alimentacion\n";
    opcDieta = paneltipodieta(); cin.ignore(); clear();
    cout << "Ingrese el Tipo de Adecuacion necesaria para el Animal\n";
    opcAde = panelAdecucion(); cin.ignore(); clear();
    cout << "Ingrese el nombre del Animal: ";
    getline(cin, nombre,'\n');
    cin.ignore();
    transform(nombre.begin(), nombre.end(), nombre.begin(), [](unsigned char c){ return tolower(c); });
    cout<< "Ingrese la edad del animal ";
    edad = paneledad(); cin.ignore(); clear();
    cout << "Ingrese el Sexo del especimen\n";
    sexo = panelSexo(); cin.ignore(); clear();
    if(opcDieta == -1 || opcTH == -1 || opcAde == -1 || edad == -1 || sexo == -1){
        cout << "No es posible continuar con el proceso intentelo nuevamente\n";
        return nullptr;
    }else{
        zoo->setCreadorIdA();
        if(opcAde == 1){
            Terrestre* newt = new Terrestre(zoo->getCreadorIdA(),mapaTH[opcTH],guarda,nombre,opcDieta,edad,sexo,1,opcTH,0);
            return newt;
        }else if(opcAde == 2){
            Volador* newv = new Volador(zoo->getCreadorIdA(),mapaTH[opcTH],guarda,nombre,opcDieta,edad,sexo,2,opcTH,0);
            return  newv;
        }else if(opcAde == 3){
            Acuatico* newa = new Acuatico(zoo->getCreadorIdA(),mapaTH[opcTH],guarda,nombre,opcDieta,edad,sexo,3,opcTH,0);
            return newa;
        }else if(opcAde == 4){
            SemiAcuatico* newsa = new SemiAcuatico(zoo->getCreadorIdA(),mapaTH[opcTH],guarda,nombre,opcDieta,edad,sexo,4,opcTH,0);
            return newsa;
        }
    }
    cin.ignore(); clear();
}
int paneledad(){
    int opc;
    try {
        cout << " : ";
         cin >> opc;cin.ignore();
        if (cin.fail()) {
            throw runtime_error("Entrada invalida solo aceptan numeros enteros Positivos.");
        }else if(opc < 0 ){
            throw logic_error("Entrada invalida solo aceptan numeros enteros Positivos.");
        }else if(opc > 25){
            throw logic_error("La edad del Animal Sospechoza.");
        } else{
            return opc;
        }
    }catch (const exception& e) { cout <<"Error: " << e.what() << endl;}
    cin.ignore(); clear();
    return -1;

}
int panelSexo() {
    int opcP;
    do {
        cout << "[1] Macho\n";
        cout << "[2] Hembra\n";
        cout << "[3] Asexual\n";
        cout << "[0] Salir\n";

        try {
            cout << "Elija una de esas opciones: ";
            cin >> opcP;cin.ignore();
            if (cin.fail()) {
                opcP = -1;
                throw runtime_error("Entrada invalida solo aceptan numeros enteros.");
            } else if (opcP <= 0 || opcP > 3) {
                if (opcP == 0) {
                    opcP = -1;
                } else {
                    opcP = -1;
                    throw range_error("Opcion invalida.");
                }
            }else{
                return opcP;
            }
        }
        catch (const exception &e) {
            cout << "Error: " << e.what() << endl;
        }
      cin.ignore(); clear();
    } while (opcP >= 0 && opcP <= 3);

    return -1;
}


void submenuHabitad(Zoologico* zoo,Habitad* HabitadActual,unordered_map<int, string>& mapaTH,unordered_map<int,string>& mapaAD, int idHabitat, Criadero* cria){
    int obcSubmenu, resban ,resban2;
    Animal* temAni;
    do {
        cout << "*** | Bienvenido al Habitat " << idHabitat  << " " << HabitadActual->getTipoH() << " | **\n";
        cout << "  /**[]**/  Adecuado para especies de tipo:  "<< mapaAD[HabitadActual->getTipoAdecuacion()] << "   /**[]**/\n";
        cout << "[1] Agregar Animal al habitat \n";
        cout << "[2] Sacar Animal del Habitat \n";
        cout << "[3] Mostrar Animales dentro del habitat\n";
        cout << "[4] Interactuar Animal \n";
        cout << "[0] Salir del habitat \n\n";
        cout << "Ingrese la obcion deseada: ";

        try{
             cin >>obcSubmenu;cin.ignore();
            if(cin.fail()){
                obcSubmenu = 10;
                throw runtime_error("Entrada invalida solo aceptan numeros enteros.");
            }
    }catch (const exception& e) { cout <<"Error: " << e.what() << endl;}
        cin.ignore(); clear();

        switch (obcSubmenu) {
            case 1:
                cout << endl;
                temAni = crearAnimal(zoo,mapaTH);
                resban = HabitadActual->agregarAnimalH(temAni);
                if(resban == 1){
                    zoo->setTotalA(1);// aumenta en 1 la cantidad de animales dentro del habitat
                    HabitadActual->setCantidadAH(1);// aumenta la cantidad en 1 dentro del habitat

                }else{
                    delete temAni;
                    cout << "'No pudo agregarse correctamente el nuevo animal dentro del habitat'\n";
                }

                break;
            case 2:
                cout << "Ingrese el id del animal para sacarlo del habitat";
                resban = resivirobcion(); cout << endl;
                resban2 = HabitadActual->eliminarAnimal(resban);
                if(resban2 == 1){
                    HabitadActual->setCantidadAH(-1);
                    zoo->setTotalA(-1);
                    cout << "El animal fue trasladado fuera del Zoologico\n";
                }
                break;
            case 3:
                if(HabitadActual->getCantidadAH() == 0){
                    cout << "No hay animales dentro del habitat, Agrega nuevos animales\n";
                }else{
                    HabitadActual->mostrarAnimalesH();
                }
                break;
            case 4:
                cout << "Ingrese el id del animal con el cual desea interactuar ";
                resban = resivirobcion();cout << endl;
                temAni = HabitadActual->mirarAnimal(resban);
                if(temAni != nullptr){
                    // MENU PARA LAS COSAS QUE SE PUEDEN HACER CON EL ANIMAL - INTERACCIONES
                    menuInteracciones(temAni,zoo,cria);

                }else{
                    cout << "El animal no pudo ser encontrado dentro del habitat\nINTENTELO NUEVAMENTE\n";
                }
                break;
            default:
                break;
        }
        cin.ignore(); clear();

    }while(obcSubmenu != 0);

}

void menuInteracciones(Animal* temAni, Zoologico* zoo,Criadero* cria){
  int opt, temps;
  Animal* tempA;
  do{
      cout << "[1] Comer" << endl;
      cout << "[2] Jugar" << endl;
      cout << "[3] Dormir" << endl;
      cout << "[4] Reproducir" << endl;
      cout << "[0] Salir" << endl;
      cout << "[*] Ingrese la opcion deseada: "; 
      try{
          cin >>opt;cin.ignore();
            if(cin.fail()){
                opt = 10;
                throw runtime_error("Entrada invalida solo aceptan numeros enteros.");
            }
      }catch (const exception& e) { cout <<"Error: " << e.what() << endl;}  
    cin.ignore(); clear();
    switch(opt){
      case 1: temAni->comer();break;
      case 2: temAni->jugar();break;
      case 3: 
                cout << "[*] Los animales terrestres duermen entre 7 y 9 horas" << endl;
                cout << "[*] Los animales voladores duermen entre 4 y  13 horas" << endl;
                cout << "[*] Los animales semiAcuaticos duermen entre 10 y 12 horas" << endl;
                cout << "[*] Los animales acuaticos duermen entre 3 y 4 horas" << endl;
                cout << "[*] Ingrese el tiempo a dormir: "; 
                  
                try{
                    cin >>temps;cin.ignore();
                    if(cin.fail()){
                      throw runtime_error("Entrada invalida solo aceptan numeros enteros.");
                    }
                }catch (const exception& e) { cout <<"Error: " << e.what() << endl;break;}
                temAni->dormir(temps); break;
      case 4:
                tempA = zoo->buscarPareja(temAni);
                if(tempA!=nullptr){
                  cout << "Reproducciendose..!" << endl;
                  cin.ignore();clear();
                  Animal* criaA;
                  criaA = cria->crearNuevaCria(temAni,tempA);
                  criaA->mostrarAnimal(criaA);
                  cin.ignore();clear();
                }
                else{
                  cout << "No hay pareja" << endl;
                }
            
      default: break;
    }
    cin.ignore(); clear();
  }while(opt!=0);
}

void clear() {
    std::system(CLEAR);
}


