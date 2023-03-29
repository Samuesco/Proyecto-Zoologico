//
// Created by Usuario on 03/04/2023.
//

#include "SemiAcuatico.h"


void SemiAcuatico::setAdaptacion() {
    this->tipoAdaptacion = "Semi Acuatico";

}
string SemiAcuatico::getAdaptacion() { return  this->tipoAdaptacion; }

SemiAcuatico::SemiAcuatico(int id ,string tipoH,string nombreEspecie, string nombreAnimal, int tipoD, int edad, int sexo, int tadaptacion, int idTipoHA, int tempDormir):Animal( id , tipoH, nombreEspecie, nombreAnimal, tipoD, edad, sexo, tadaptacion,idTipoHA,tempDormir), tipoAdaptacion("Semi Acuatica"){
}
SemiAcuatico::~SemiAcuatico() { Animal::~Animal(); }

void SemiAcuatico::mostrarAnimal(Animal*animalaMostrar) {

    cout << "Identificado el especimen con el Id :" << animalaMostrar->getIdAnimal() << endl;
    cout << " [*] Especie: " << animalaMostrar->getNombreEspecie()<< endl;
    cout << " [*] Nombre: " << animalaMostrar->getNombreAnimal()<<endl;
    cout << " [*] Sexo: " ;
    if(animalaMostrar->getSexoA() == 1){cout << "Macho"<<endl;
    }else if(animalaMostrar->getSexoA() == 2){cout << "Hembra"<<endl;
    }else{cout << "Asexual"<<endl;
    }
    //cout << " [*] Tamaño: " << animalTemp->getNombreEspecie();
    cout << " [*] Tipo Adaptacion: " << animalaMostrar->getAdaptacion()<<endl;
    cout << " [*] Edad: " << animalaMostrar->getedad()<<endl;
    cout << " [*] Tipo de Habitad: " << animalaMostrar->getTipoHabitad()<<endl;
    cout << " [*] Dieta : " ;
    if(animalaMostrar->getTipoDieta() == 1){cout << "Carnivoro"<<endl;
    }else if(animalaMostrar->getTipoDieta()== 2){cout << "Hervivoro"<<endl;
    }else{cout << "Omnivoro"<<endl;
    }

}

void SemiAcuatico::comer() {
    int dieta = this->tipoDieta;
    if(dieta == 1){
      cout << "Comiendo peces, crustáceos, moluscos y pequeños mamíferos!" << endl;
    }else if(dieta == 2){
      cout << "Comiendo algas, nenúfares y lirios acuáticos!" << endl;
    } else if(dieta == 3){
      cout << "Comiendo algas, plantas acuáticas, crustáceos, peces y pequeños mamíferos!" << endl;
    }
}

void SemiAcuatico::jugar(){
    cout << "Jugando a atrapar objetos!" << endl;
}

void SemiAcuatico::dormir(int tiempoS){
    if (10 <= tiempoS <= 12){
      if(tempDormir+tiempoS <= 12){
        cout << "Durmiendo!" << endl;
        tempDormir += tiempoS;
      }else{
        cout << "El " << getNombreAnimal() << " no tiene sueno" << endl;
      }
    }else{
      cout << "El " << getNombreAnimal() << " no tiene sueno" << endl;
    }
}
