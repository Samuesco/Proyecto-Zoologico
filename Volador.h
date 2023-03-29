//
// Created by Usuario on 03/04/2023.
//

#ifndef PROYECTO_ZOOLOGICO_VOLADOR_H
#define PROYECTO_ZOOLOGICO_VOLADOR_H
#include "Animal.h"

class Volador : public Animal {

protected:
    string tipoAdaptacion;
public:
    Volador() = default;
    Volador(int id ,string tipoH,string nombreEspecie, string nombreAnimal, int tipoD, int edad, int sexo, int tadaptacion, int idTipoHA, int tempDormir);
    virtual ~Volador() ;

    string getAdaptacion() override;

    void comer() override;

    void mostrarAnimal(Animal *animalaMostrar) override;

    void setAdaptacion();

    void jugar() override;

    void dormir(int tiempoS) override;
};

#endif //PROYECTO_ZOOLOGUICO_VOLADOR_H
