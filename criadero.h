#ifndef PROYECTO_ZOOLOGICO_CRIADERO_H
#define PROYECTO_ZOOLOGICO_CRIADERO_H

#include <iostream>
#include <stdlib.h>
#include "Animal.h"
#include "Terrestre.h"
#include "Volador.h"
#include "Acuatico.h"
#include "SemiAcuatico.h"
#include<vector>

class Criadero{
protected: 
  vector<Animal*> criasTerrestres, criasVolador, criasAcuatico, criasSemiAcuatico;
  int cantT;
  int cantV;
  int cantA;
  int cantSA;
public:
  Criadero()=default;
  Criadero(int cantT,int cantV,int cantA,int cantSA);
  ~Criadero();
  void mostrarCrias(int tp);
  int randomZeroOrOne();
  Animal* crearNuevaCria(Animal* p1, Animal* p2);
  void mostrarAnimal(Animal* animalMostrar);
  int get_cantT();
  int get_cantV();
  int get_cantA();
  int get_cantSA();
  void set_cantT(int i);
  void set_cantV(int i);
  void set_cantA(int i);
  void set_cantSA(int i);
};

#endif
