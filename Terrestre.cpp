//
// Created by Usuario on 30/03/2023.
//

#include "Terrestre.h"

void Terrestre::setAdaptacion() {
    this->tipoAdaptacion = "Terrestre";

}
string Terrestre::getAdaptacion() { return  this->tipoAdaptacion; }

Terrestre::Terrestre(int id ,string tipoH,string nombreEspecie, string nombreAnimal, int tipoD, int edad, int sexo, int tadaptacion, int idTipoHA, int tempDormir):Animal( id , tipoH, nombreEspecie, nombreAnimal, tipoD, edad, sexo, tadaptacion,idTipoHA,tempDormir), tipoAdaptacion("Terrestre"){}

Terrestre::~Terrestre() { Animal::~Animal(); }

void Terrestre::mostrarAnimal(Animal*animalaMostrar) {

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
void Terrestre::comer() {
    int dieta = this->tipoDieta;
    if(dieta == 1){
      cout << "Comiendo carne freca!" << endl;
    }else if(dieta == 2){
      cout << "Comiendo vegetales frutas o pasto!" << endl;
    } else if(dieta == 3){
      cout << "Comiendo carne fresca o frutas y vegetales!" << endl;
    }
}

void Terrestre::jugar(){
    cout << "Persiguiendo la pelota" << endl;
}

void Terrestre::dormir(int tiempoS){
    if (7 <= tiempoS <= 9){
      if(tempDormir+tiempoS <= 9){
        cout << "Durmiendo!" << endl;
        tempDormir += tiempoS;
      }else{
        cout << "El " << getNombreAnimal() << " no tiene sueno" << endl;
      }
    }else{
      cout << "El " << getNombreAnimal() << " no tiene sueno" << endl;
    }
}
