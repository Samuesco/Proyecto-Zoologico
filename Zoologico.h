//
// Created by Usuario on 28/03/2023.
//

#ifndef PROYECTO_ZOOLOGICO_ZOOLOGICO_H
#define PROYECTO_ZOOLOGICO_ZOOLOGICO_H
#include "Habitad.h"
#include "Animal.h"
#include <unordered_map>
using std::string;
class Zoologico {
private:
    string nombreZoo;
    int totalAnimales;
    int creadorKeysM;
    int totalHabitads;
    int creadorIds;
    unordered_map <int,Habitad*> mapaHabits;

public:
    Zoologico() = default;
    Zoologico(string nombre);
    ~Zoologico();
    //Zoologico(string nombre,int totalA, int totalH);
    int getTotalA();
    int getTotalH();
    int getCreadorIdA();
    int getCreadorKeys();
    string getNombreZoo();
    void setNombreZoo(string nombreZ);
    void setTotalA(int newT);
    void setTotalH(int newT);
    void setCreadorIdA();
    void setCreadorKeysM();
    int agregarHabitad(int KeyH,Habitad* newHabitad);
    int moverAnimalH(int KeyHSalida, int idAnimalHSalida ,int KeyHLlegada);
    int eliminarHabitad(int KeyH);
    Habitad* entrarHabitad(int KeyH);
    bool buscarHabitad(int keyB);
    void verMapaZoologico();
    Animal* buscarPareja(Animal* animal);

};


#endif //PROYECTO_ZOOLOGICO_ZOOLOGICO_H
