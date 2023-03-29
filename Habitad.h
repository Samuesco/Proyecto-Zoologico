//
// Created by Usuario on 28/03/2023.
//

#ifndef PROYECTO_ZOOLOGICO_HABITAD_H
#define PROYECTO_ZOOLOGICO_HABITAD_H
#include "Animal.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std ;

class Habitad {

private:
    string tipoHabitad;
    string AdecuacionH;
    int idTipoHabitad;//
    int tipoDietaAnimales; // Unicas posible valores que se tendran en cuenta.  1 = CARNIVORO , 2 = HERVIVORO, 3 = OMNIVORO
    int tipoAdecuacion; // Unicos posibles valroes que se tendran en cuenta. 1 = Terrestre , 2 = Volador, 3 = Acuatico, 4. Semi Acuatico.
    int cantidadAnimalesH; // Tiene limite de 15 Animales por habitad.
public:
    vector<Animal*> vectorAnimales;

public:
    Habitad()= default;
    Habitad(string tipoH,int idTipoH,int tipoDietaAH, int tipoAdecuacionH, int cantidadAH, string tipoAdecuS);
    //Habitad(string tipoH,int tipoAd,int canA);
    ~Habitad();
    string getTipoH();
    void setTipoH(string TipoH);
    int getIdTipoH();
    int getTipoDieta();
    void setTipoDieta(int tipo);
    int getTipoAdecuacion();
    void setTipoAdecuacion(int tipo);
    int getCantidadAH();
    void setCantidadAH(int newCA);
    string getAdecuacionS();
    int agregarAnimalH(Animal* newAnimal);
    int buscarenHabitad(int idA);
    Animal* sacarAnimalH(int idA);
    int eliminarAnimal(int idA);
    void mostrarAnimalesH();
    Animal* mirarAnimal(int idA);
//    Animal* buscarenHabitad2(int idA);

};


#endif //PROYECTO_ZOOLOGUICO_HABITAD_H
