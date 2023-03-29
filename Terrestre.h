//
// Created by Usuario on 30/03/2023.
//

#ifndef PROYECTO_ZOOLOGICO_TERRESTRE_H
#define PROYECTO_ZOOLOGICO_TERRESTRE_H
#include "Animal.h"

class Terrestre: public Animal{

protected:
    string tipoAdaptacion;
public:
    Terrestre() = default;
    Terrestre(int id ,string tipoH,string nombreEspecie, string nombreAnimal, int tipoD, int edad, int sexo, int tadaptacion, int idTipoHA, int tempDormir);
    virtual ~Terrestre();
    string getAdaptacion()override;
    void comer()override;
    void mostrarAnimal(Animal*animalaMostrar)override;
    void setAdaptacion();
    void jugar()override;
    void dormir(int tiempoS)override;


};


#endif //PROYECTO_ZOOLOGUICO_TERRESTRE_H
