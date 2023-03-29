//
// Created by Usuario on 28/03/2023.
//

#ifndef PROYECTO_ZOOLOGICO_ANIMAL_H
#define PROYECTO_ZOOLOGICO_ANIMAL_H

#include <iostream>
#include <string>
using namespace std ;

class Animal {
protected:
    int idanimal;
    string tipoHabitad;
    string nombreEspecie;
    string nombreAnimal;
    //string tamAnimal;
    int tipoAdap;
    int tipoDieta;
    int idTipoHA;
    int edad;
    int sexoAnimal;
    int tempDormir;
public:
    Animal() = default;
    Animal(int id ,string tipoH,string nombreEspecie, string nombreAnimal, int tipoD, int edad, int sexo, int tadaptacion, int idTipoHani,int tempDormir);
    virtual ~Animal() = default;
    int getIdAnimal();
    string getTipoHabitad();
    string getNombreEspecie();
    string getNombreAnimal();
    int getIdTipoHA();
    int getTipoDieta();
    int getedad();
    int getSexoA();
    int getTipoAdapA();
    virtual string getAdaptacion() = 0;
    void setedad(int newEdad);
    void setIdAnimal(int id);
    virtual void comer() = 0;
    virtual void mostrarAnimal(Animal* animalaMostrar) = 0;
    virtual void jugar()=0;
    virtual void dormir(int tiempoS)=0;

};


#endif //PROYECTO_ZOOLOGICO_ANIMAL_H
