//
// Created by Usuario on 28/03/2023.
//

#include "Zoologico.h"

Zoologico::Zoologico(string nombre): nombreZoo(nombre) , totalAnimales(0) , totalHabitads(0),creadorIds(0), mapaHabits(){}
Zoologico::~Zoologico(){
    unordered_map<int,Habitad*>::iterator itMap;
    for (itMap = this->mapaHabits.begin(); itMap != this->mapaHabits.end(); ++itMap){
        //itMap->second ~Habitad();
        delete this->mapaHabits[itMap->first];
    }
    this->mapaHabits.clear();
}

//Zoologico(string nombre,int totalA, int totalH);
/*Gets y sets de algunas propiedades de la clase */
int Zoologico::getTotalA(){ return this->totalAnimales; }

int Zoologico::getTotalH(){ return this->totalHabitads; }

string Zoologico::getNombreZoo(){ return this->nombreZoo; }

int Zoologico::getCreadorIdA() { return this->creadorIds; }

int Zoologico::getCreadorKeys() { return  this->creadorKeysM; }

void Zoologico::setNombreZoo(string nombreZ){
 this->nombreZoo = nombreZ;
}
void Zoologico::setTotalA(int newT){
    if(newT == 1){
        this->totalAnimales ++ ;
    }else{
        this->totalAnimales --;
    }

}

void Zoologico:: setTotalH(int newT){
    if(newT == 1){
        this->totalHabitads ++ ;
    }else{
        this->totalHabitads --;
    }
}
void Zoologico::setCreadorIdA() {
    this->creadorIds ++;
}
void  Zoologico::setCreadorKeysM() {
    this->creadorKeysM++;
}

 bool Zoologico::buscarHabitad(int keyB) {
    bool ban = false;
    if (this->mapaHabits.find(keyB) != mapaHabits.end()) {
        ban = true;
        //"La clave se encuentra en el mapa.
    }
    //"La clave no se encuentra en el mapa.
     return ban;

}
int Zoologico::moverAnimalH(int KeyHSalida, int idAnimalHSalida ,int KeyHLlegada){
    int banGeneral = 0;
    bool banHSalida = buscarHabitad(KeyHSalida);
    bool banHLlegada = buscarHabitad(KeyHLlegada);
    if (banHSalida == true && banHLlegada == true){
        int banIndiceAnimal = this->mapaHabits[KeyHSalida]->buscarenHabitad(idAnimalHSalida);
        if(banIndiceAnimal >= 0){
            Animal* temAnimal = this->mapaHabits[KeyHSalida]->sacarAnimalH(banIndiceAnimal);
            this->mapaHabits[KeyHSalida]->setCantidadAH(-1);
            banGeneral = this->mapaHabits[KeyHLlegada]->agregarAnimalH(temAnimal);
            this->mapaHabits[KeyHLlegada]->setCantidadAH(1);
        }else{
            cout <<"El Animal con el Id " << idAnimalHSalida << "No fue encontrado \n" << "| ** REVISE EL ID E INTENTELO NUEVAMENTE ** |\n";
        }
    }else {
        if(banHSalida == false && banHLlegada == false){
            cout <<"Ninguno de los 2 Habitads fue encontrado no fue encontrado\n";
        }
        else if(banHSalida == false){
            cout <<"El Habitad de llegada no fue encontrado\n";
        }else{
            cout <<"El Habitad de Salida no fue encontrado\n";
        }
        cout <<"| ** REVISE LOS IDS E INTENTELO NUEVAMENTE ** |\n";
    }
    return banGeneral;
}
/*
 AgrgarHabitad es una funcion que recibe como parametros una Key unica y un puntero de un objeto de la clase habitad
 para agregarlo dentro del mapa.
 */
int Zoologico:: agregarHabitad(int KeyH, Habitad* newHabitad){
    this->mapaHabits.insert(make_pair(KeyH,newHabitad));
    bool ban = buscarHabitad(KeyH);
    try{
        if (ban == true) {
            //"La clave se encuentra en el mapa.
            return 1;
        } else {
            throw logic_error("Agregar en Mapa");
          //"La clave no se encuentra en el mapa.
        }

    }catch (const exception& e){
        cout << " Error: " << e.what() << endl;
        return 0;
    }

}

/*
 Elimina un Habitad del mapa, recibe como parametro la llave del mapa, se asegura que exista el habitad y que no contenga
 animales dentro, solo si cumple esas condiciones lo hace sino no.
 */
int Zoologico::eliminarHabitad(int KeyH){
    int banf = 0;
    bool banh = buscarHabitad(KeyH);
        if( banh == true ){
            if(this->mapaHabits[KeyH]->getCantidadAH() == 0){
                this->mapaHabits.erase(KeyH);
                cout << "El Habitad fue Eliminado del Zoologico";
                banf = 1;// Retorna 1 si no hay animales dentro del habitad y lo borra del map
            }else{
                cout << "Dentro de este Habitad:" << endl;
                cout <<mapaHabits[KeyH]->getTipoH() <<"Identificado con la clave "<< KeyH << "Todavia posee \n"<<this->mapaHabits[KeyH]->getCantidadAH();
                cout << "Animales dentro del Habitad, No se puede Destruir el habitad, porfavor reubiquelos e intentelo nuevamente\n";
                banf = 2;// Retorna 2 si lo encuentra pero todavia hay animales dentro del habitad.
            }
        }
       //retorna 0 sino encontro nada
    return banf;
}
/*
 Busca al habitad dentro del mapa con la clave y retorna el puntero hacia ese habitad.
 */
Habitad* Zoologico::entrarHabitad(int KeyH){
    bool banExistenciaH = buscarHabitad(KeyH);
    if(banExistenciaH == true) {
        return this->mapaHabits[KeyH];
    }else{
        return nullptr;
    }
}
void Zoologico::verMapaZoologico() {
    unordered_map<int,Habitad*>::iterator itMap;
    cout << "Hay dentro del zoologico " << this->totalHabitads;
    if(this->totalHabitads == 1){cout<< " habitat en total\n ";}else{cout<< " habitats en total\n ";}
    for (itMap = this->mapaHabits.begin(); itMap != this->mapaHabits.end(); ++itMap){
        cout<< "--------------------------------------------------------------------------------\n\n\n";
        cout<< "[*]Tipo Habitat: " << itMap->second->getTipoH()<< endl;
        cout<< "[*]Key Habitat: " << itMap->first << endl;
        cout<< "[*]Adecuacion Habitat: " << itMap->second->getAdecuacionS()<< endl;
        cout<< "[*]Cantidad Animales en el Habitat: " << itMap->second->getCantidadAH() << endl;
        cout<< "[*]Tipo dieta aniamles del habitat: " ;
        if(itMap->second->getTipoDieta() == 1){cout<< "Carnivoros"<< endl;
        }else if (itMap->second->getTipoDieta() == 2){cout<< "Herbivoros"<< endl;
        }else{ cout<< "Omnivoros"<< endl;}
    }
}

Animal* Zoologico::buscarPareja(Animal* animal){
    unordered_map<int,Habitad*>::iterator itMap;
    for (itMap = this->mapaHabits.begin(); itMap != this->mapaHabits.end(); ++itMap){
      vector<Animal*>::iterator itVector;
      if(itMap->second->getTipoH()==animal->getTipoHabitad()){
        for(itVector = itMap->second->vectorAnimales.begin(); itVector != itMap->second->vectorAnimales.end(); ++itVector){
            if((*itVector)->getNombreEspecie()==animal->getNombreEspecie() && (*itVector)->getSexoA()!=animal->getSexoA()){
              return *itVector;
            }
        }
      }
    }
    return nullptr;
}

