//
// Created by Usuario on 28/03/2023.
//
#include "Animal.h"


Animal::Animal(int id ,string tipoH,string nombreEspecie, string nombreAnimal, int tipoD, int edad, int sexo, int tadaptacion,int idTipoHan, int tempDormir): idanimal(id),tipoHabitad(tipoH),nombreEspecie(nombreEspecie),nombreAnimal(nombreAnimal),tipoDieta(tipoD),edad(edad),sexoAnimal(sexo), tipoAdap(tadaptacion),idTipoHA(idTipoHan),tempDormir(tempDormir){}
int Animal:: getIdAnimal(){ return this->idanimal; }
string Animal:: getTipoHabitad(){ return  this->tipoHabitad; }
string Animal:: getNombreEspecie(){ return this->nombreEspecie; }
string Animal:: getNombreAnimal(){return  this->nombreAnimal; }
int Animal:: getTipoDieta(){ return  this->tipoDieta; }
int Animal:: getedad(){ return this->edad;}
int Animal:: getSexoA(){ return this->sexoAnimal;}
int Animal::getTipoAdapA() { return  this->tipoAdap; }
int Animal:: getIdTipoHA(){return  this->idTipoHA; }
void Animal:: setedad(int newEdad){
    this-> edad = newEdad;
}
void Animal:: setIdAnimal(int id){
    this-> idanimal = id;
}





