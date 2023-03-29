//
// Created by Usuario on 28/03/2023.
//

#include "Habitad.h"



string Habitad::getTipoH(){ return this->tipoHabitad;}

string Habitad::getAdecuacionS(){ return  this->AdecuacionH; }

void Habitad::setTipoH(string TipoH) {
    this->tipoHabitad = TipoH;
}
int Habitad:: getIdTipoH(){ return  this->idTipoHabitad; }

int Habitad::getTipoDieta(){ return  this->tipoDietaAnimales; }

void Habitad::setTipoDieta(int tipo){
    this->tipoDietaAnimales = tipo;
}

int Habitad::getTipoAdecuacion(){ return this->tipoAdecuacion;}

void Habitad::setTipoAdecuacion(int tipo){
    this->tipoAdecuacion = tipo;
}

int Habitad::getCantidadAH(){ return this->cantidadAnimalesH; }

void Habitad::setCantidadAH(int newCA){
    if(newCA == 1){
        this->cantidadAnimalesH ++ ;
    }else{
        this->cantidadAnimalesH --;
    }
}
Habitad:: Habitad(string tipoH,int idTipoH,int tipoDietaAH, int tipoAdecuacionH, int cantidadAH, string tipoAdecuS): tipoHabitad(tipoH),idTipoHabitad(idTipoH),tipoDietaAnimales(tipoDietaAH),tipoAdecuacion(tipoAdecuacionH),cantidadAnimalesH(0),vectorAnimales(),AdecuacionH(tipoAdecuS){}

Habitad::~Habitad(){
    vector<Animal*>::iterator itVector;
    for(itVector = this->vectorAnimales.begin(); itVector != this->vectorAnimales.end(); ++itVector){
        delete  (*itVector);
    }
    this->vectorAnimales.clear();

}
int Habitad::agregarAnimalH(Animal* newAnimal){
    int ban = 0, banCondi = 0;
    try {
        /* AGREGAR MAS CONDICIONES ANTES DE AGRAGR AL ANIMAL TENER EN CUENTA CARACTERISTICAS DEL ANIMAL Y DEL HABITAD*/
        // Verifica que Tipo de habitad coincida entre el animal y el habitat
        if(this->idTipoHabitad == newAnimal->getIdTipoHA() ){
            if(this->tipoAdecuacion == newAnimal->getTipoAdapA()){ // verifica que el tipo de adecuacion del habitad y del animal coincidan
                if(this->tipoDietaAnimales == newAnimal->getTipoDieta()) { // verifica que los animales dentro del habitat compartan la dieta del nuevo animal
                    if (this->vectorAnimales.size() == 0) { // Lo ingresa pues no hay animales dentro del habitat
                        this->vectorAnimales.push_back(newAnimal);
                        banCondi = 1;
                    } else if (this->vectorAnimales.size() <= 14) { // verifica que haya espacio para el animal dentro del habitat
                        if (newAnimal->getTipoDieta() == 1) {
                            if (newAnimal->getNombreEspecie() == newAnimal->getNombreEspecie()) {
                                this->vectorAnimales.push_back(newAnimal);
                                banCondi = 1;
                            } else {
                                cout << "La especies carnivoras distintas no pueden convivir juntas " << endl << newAnimal->getNombreEspecie() << " y " << newAnimal->getNombreEspecie();
                                cout << "Es Peligroso tenerlas Juntas intentalo en otro habitat\n";
                            }
                        }else if(newAnimal->getTipoDieta() == 3){
                            if (newAnimal->getNombreEspecie() == newAnimal->getNombreEspecie()) {
                                this->vectorAnimales.push_back(newAnimal);
                                banCondi = 1;
                            } else {
                                cout << "La especies omnivoras distintas no pueden convivir juntas " << endl << newAnimal->getNombreEspecie() << " y " << newAnimal->getNombreEspecie();
                                cout << "Es Peligroso tenerlas Juntas intentalo en otro habitat\n";
                            }

                        }else {
                            this->vectorAnimales.push_back(newAnimal);
                            banCondi = 1;
                        }
                    } else {
                        cout
                                << "El limite de especimenes por habitad es de 14 individuos, no hay espacio para uno mas.\n";
                        cout << "Busca en otro habitat dentro del Zoologico en donde pueda estar.\n";
                    }
                }else{
                    if (this->tipoDietaAnimales  == 1){
                        cout << "La dieta de los animales dentro de este habitat que es de Carnivoros\n";

                    }else if(this->tipoDietaAnimales  == 2){
                        cout << "La dieta de los animales dentro de este habitat que es de Herbivoros\n";
                    }else{
                        cout << "La dieta de los animales dentro de este habitat que es de Omnivoros\n" ;
                    }
                    cout << "No puede estar con la especie " << newAnimal->getNombreEspecie() << " que tiene una dieta" << newAnimal->getTipoDieta();
                    cout << "Puede llegar a ser peligroso, no puedes ingresarlo en este habitad, Busca Otro habitat";
                }

            }else{
                cout<< "El tipo de adecuacion no es el adecuado para este animal, Busca otro habitat \n";
            }
        }else{
            cout << "El tipo de habitad es " << this->tipoHabitad << "\nMientras que el animal que deseas ingresar nesecita un habitat " <<newAnimal->getTipoHabitad()<<endl;
            cout << " Seria PELIGROSO HACERLO\n" << "Por lo tanto busca otro recinto con el habitat adecuado para esa espcie. \n";
        }

        //_____________________________________________________
        if(banCondi == 1){
            if(this->vectorAnimales[vectorAnimales.size()-1] != newAnimal){
                throw logic_error("Agregar en vector");
            }else{
                ban = 1;
            }
        }

    }catch (const exception& e){
        cout << " Error: " << e.what() << endl;
    }
    return ban;
}
/*
  Busca a el animal dentro del habitat
 */
int Habitad::buscarenHabitad(int idA) {
    vector<Animal*>::iterator itVector;
    int indice = 0, ban = 0;/*Suma ala variable indice un 1, cada vez que avance en el vector, para retornar el indice
        si la bandera toma el valor de 1 "Encontrado", en el que se encuentra el animal para buscarlo mas facilmente posteriormente,
        en caso de que no la bandera quedara en 0 "No encontrado", retornara -1 "Error No encontrado".
         */
    for(itVector = this->vectorAnimales.begin(); itVector != this->vectorAnimales.end(); ++itVector){
        if((*itVector)->getIdAnimal() == idA){
            ban = 1;
            break;
        }
            indice++;
    }
    if (ban == 1){
        return indice;
    }else{
        return -1;
    }
}
/*
 La funcion saca al animal del habitat y retorna su puntero, si esque lo encuentra segun el id de
 que entra como parametro, sino lo retorna vacio.
 */
Animal* Habitad::sacarAnimalH(int idA){
    Animal* temAnimal;
    int indice = buscarenHabitad(idA);
    if(indice >= 0){
        temAnimal = this->vectorAnimales[indice];
        this->vectorAnimales.erase(vectorAnimales.begin() + indice);
        try{
            int ban = buscarenHabitad(idA);
            if(ban >= 0){
                throw logic_error("Eliminar en vector");
            }
        }catch (const exception& e) {
            cout << " Error: " << e.what() << endl;
        }

        return temAnimal;
    }else{
     return nullptr;
    }
}


/*
 Busca a el animal dentro del habitat en el vector y si lo encuentra lo elimina,definiticamente del
del Zoologico"Libera memoria dinamica".
 */
int Habitad:: eliminarAnimal(int idA){
    int indice = buscarenHabitad(idA);
    if(indice >= 0){
        Animal* pAnimal = this->vectorAnimales[indice];
        this->vectorAnimales.erase(vectorAnimales.begin() + indice);
        try{
            int ban = buscarenHabitad(idA);
            if(ban >= 0){
                throw logic_error("Eliminar en vector");
            }else{
                //Liberar Memoria dinamica
                delete pAnimal;
                return 1;
            }

        }catch (const exception& e) {
            cout << " Error: " << e.what() << endl;
        }
    }else{
        cout << "No se encontro a el animal, para poder Trasladarlo fuera del Zoologico\n";
    }
    return 0;
}
/*
  Muestra A Todos los animales dentro del habitad.
 */
void Habitad::mostrarAnimalesH(){
    cout << "En este habitad "<< this->tipoHabitad << " Adecuado para especies de la clase " << this->AdecuacionH;
    if (this->tipoDietaAnimales == 1) {
        cout << " Carnivoras" << endl;

    } else if (this->tipoDietaAnimales == 2) {
        cout << " Hervivoras"<< endl;

    } else {
        cout << " Omnivoras"<< endl;
    }


    vector<Animal*>::iterator itVector;
    for(itVector = this->vectorAnimales.begin(); itVector != this->vectorAnimales.end(); ++itVector){
        Animal* animalTemp = *itVector;
        cout << "Identificado el especimen con el Id :" << animalTemp->getIdAnimal() << endl;
        cout << " [*] Especie: " << animalTemp->getNombreEspecie()<< endl;
        cout << " [*] Nombre: " << animalTemp->getNombreAnimal()<<endl;
        cout << " [*] Sexo: " ;
        if(animalTemp->getSexoA() == 1){cout << "Macho"<<endl;
        }else if(animalTemp->getSexoA() == 2){cout << "Hembra"<<endl;
        }else{cout << "Asexual"<<endl;
        }
        //cout << " [*] Tamaño: " << animalTemp->getNombreEspecie();
        cout << " [*] Edad: " << animalTemp->getedad()<<endl;
        cout << " [*] Tipo de Habitad: " << animalTemp->getTipoHabitad()<<endl;
        cout << " [*] Dieta : " ;
        if(animalTemp->getTipoDieta() == 1){cout << "Carnivoro"<<endl<<endl;
        }else if(animalTemp->getTipoDieta()== 2){cout << "Hervivoro"<<endl<<endl;
        }else{cout << "Omnivoro"<<endl<<endl;
        }

    }
}
/*
 Busca y retorna el puntero del que apunta al objeto animal si se encuentra.
 */
Animal* Habitad:: mirarAnimal(int idA){
    int indice = buscarenHabitad(idA);
    if(indice>= 0){
        return this->vectorAnimales[indice];
    }else{
        return nullptr;
    }
}


