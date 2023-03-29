//
// Created by Usuario on 03/04/2023.
//

#include "Acuatico.h"
void Acuatico::setAdaptacion() {
    this->tipoAdaptacion = "Acuatico";

}
string Acuatico::getAdaptacion() { return  this->tipoAdaptacion; }

Acuatico::Acuatico(int id ,string tipoH,string nombreEspecie, string nombreAnimal, int tipoD, int edad, int sexo, int tadaptacion, int idTipoHA,int tempDormir):Animal( id , tipoH, nombreEspecie, nombreAnimal, tipoD, edad, sexo, tadaptacion,idTipoHA,tempDormir), tipoAdaptacion("Acuatica"){}


Acuatico::~Acuatico() { Animal::~Animal(); }

void Acuatico::mostrarAnimal(Animal*animalaMostrar) {

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

void Acuatico::comer() {
    int dieta = this->tipoDieta;
    if(dieta == 1){
      cout << "Comiendo peces, moluscos y crustáceos !" << endl;
    }else if(dieta == 2){
      cout << "Comiendo algas y plantas acuáticas!" << endl;
    } else if(dieta == 3){
      cout << "Comiendo algas, plantas acuáticas, peces, moluscos y crustaceos!" << endl;
    }
}

void Acuatico::jugar(){
    cout << "Jugando a lanzar la pelota!" << endl;
}

void Acuatico::dormir(int tiempoS){
    if (3 <= tiempoS <= 4){
      if(tempDormir+tiempoS <= 4){
        cout << "Durmiendo!" << endl;
        tempDormir += tiempoS;
      }else{
        cout << "El " << getNombreAnimal() << " no tiene sueno" << endl;
      }
    }else{
      cout << "El " << getNombreAnimal() << " no tiene sueno" << endl;
    }
}

