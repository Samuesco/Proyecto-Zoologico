//
// Created by Usuario on 03/04/2023.
//

#ifndef PROYECTO_ZOOLOGICO_SEMIACUATICO_H
#define PROYECTO_ZOOLOGICO_SEMIACUATICO_H
#include "Animal.h"

class SemiAcuatico: public Animal {

protected:
    string tipoAdaptacion;
public:
    SemiAcuatico() = default;
    SemiAcuatico(int id ,string tipoH,string nombreEspecie, string nombreAnimal, int tipoD, int edad, int sexo, int tadaptacion, int idTipoHA, int tempDormir);
    virtual ~SemiAcuatico();

    string getAdaptacion() override;

    void comer() override;

    void mostrarAnimal(Animal *animalaMostrar) override;

    void setAdaptacion();
    
    void jugar() override;

    void dormir(int tiempoS) override;
};


#endif //PROYECTO_ZOOLOGICO_SEMIACUATICO_H
