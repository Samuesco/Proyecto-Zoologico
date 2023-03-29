//
// Created by Usuario on 03/04/2023.
//

#ifndef PROYECTO_ZOOLOGICO_ACUATICO_H
#define PROYECTO_ZOOLOGICO_ACUATICO_H
#include "Animal.h"

class Acuatico: public Animal{

protected:
    string tipoAdaptacion;
public:
    Acuatico() = default;
    Acuatico(int id ,string tipoH,string nombreEspecie, string nombreAnimal, int tipoD, int edad, int sexo, int tadaptacion, int idTipoHA, int tempDormir);
    virtual ~Acuatico();
    string getAdaptacion()override;
    void comer()override;
    void mostrarAnimal(Animal*animalaMostrar)override;
    void setAdaptacion();
    void jugar() override;
    void dormir(int tiempoS) override;

};


#endif //PROYECTO_ZOOLOGICO_ACUATICO_H
