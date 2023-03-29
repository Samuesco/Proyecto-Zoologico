//
// Created by Usuario on 05/04/2023.
//

#ifndef PROYECTO_ZOOLOGICO_MAIN_H
#define PROYECTO_ZOOLOGICO_MAIN_H
#include <iostream>
#include <algorithm>
#include <string>
#include "Animal.h"
#include "Zoologico.h"
#include "Habitad.h"
#include "Terrestre.h"
#include "Volador.h"
#include "Acuatico.h"
#include "SemiAcuatico.h"
#include "criadero.h"

using std::cin;

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

void menuGeneral();
int panelAdecucion();
int paneltipodieta();
int panelTipoHabi();
int resivirobcion();
int paneledad();
int panelSexo();
void menuInteracciones(Animal* temAni,Zoologico* zoo, Criadero* cria);
void clear();
void submenuHabitad(Zoologico* zoo,Habitad* HabitadActual,unordered_map<int, string>& mapaTH,unordered_map<int,string>& mapaAD, int idHabitat, Criadero* cria);
Animal* crearAnimal(Zoologico* zoo,unordered_map<int, string>& mapaTH);


#endif //PROYECTO_ZOOLOGUICO_MAIN_H
