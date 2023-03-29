//
// Created by Usuario on 03/04/2023.
//

#include "Volador.h"

void Volador::setAdaptacion() {
    this->tipoAdaptacion = "Volador";
}
string Volador::getAdaptacion() { return  this->tipoAdaptacion; }

Volador::Volador(int id ,string tipoH,string nombreEscpecie, string nombreAnimal, int tipoD, int edad, int sexo, int tadaptacion, int idTipoHA, int tempDormir):
        Animal( id , tipoH, nombreEscpecie, nombreAnimal, tipoD, edad, sexo, tadaptacion,idTipoHA,tempDormir),tipoAdaptacion("Volador"){}

Volador::~Volador() { Animal::~Animal(); }

void Volador::mostrarAnimal(Animal*animalaMostrar) {

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
void Volador::comer() {

    int dieta = this->tipoDieta;
    if(dieta == 1){
      cout << "Comiendo peces!" << endl;
    }else if(dieta == 2){
      cout << "Comiendo frutas!" << endl;
    } else if(dieta == 3){
      cout << "Comiendo peces y frutas!" << endl;
    }
}

void Volador::jugar(){
    cout << "Haciendo piruetas en el aire" << endl;
}

void Volador::dormir(int tiempoS){
    if (4 <= tiempoS <= 13){
      if(tempDormir+tiempoS <= 13){
        cout << "Durmiendo!" << endl;
        tempDormir += tiempoS;
      }else{
        cout << "El " << getNombreAnimal() << " no tiene sueno" << endl;
      }
    }else{
      cout << "El " << getNombreAnimal() << " no tiene sueno" << endl;
    }
}
    
