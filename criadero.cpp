#include "criadero.h"

Criadero::Criadero(int cantT,int cantV,int cantA,int cantSA): cantT(cantT),cantV(cantV),cantA(cantA),cantSA(cantSA){}
Criadero::~Criadero(){
    vector<Animal*>::iterator itVector;
    for(itVector = this->criasTerrestres.begin(); itVector != this->criasTerrestres.end(); ++itVector){
        delete *itVector;
    }
    for(itVector = this->criasVolador.begin(); itVector != this->criasVolador.end(); ++itVector){
        delete *itVector;
    }
    for(itVector = this->criasAcuatico.begin(); itVector != this->criasAcuatico.end(); ++itVector){
        delete (*itVector);
    }
    for(itVector = this->criasSemiAcuatico.begin(); itVector != this->criasSemiAcuatico.end(); ++itVector){
        delete (*itVector);
    }


}

void Criadero::mostrarAnimal(Animal* animalaMostrar) {

    cout << "Identificado el especimen con el Id :" << animalaMostrar->getIdAnimal() << endl;
    cout << " [*] Especie: " << animalaMostrar->getNombreEspecie()<< endl;
    cout << " [*] Nombre: " << animalaMostrar->getNombreAnimal()<<endl;
    cout << " [*] Sexo: " ;
    if(animalaMostrar->getSexoA() == 1){cout << "Macho"<<endl;
    }else if(animalaMostrar->getSexoA() == 2){cout << "Hembra"<<endl;
    }else{cout << "Asexual"<<endl;
    }
    //cout << " [*] Tamaño: " << animalTemp->getNombreEspecie();
    cout << " [*] Tipo Adaptacion: " << animalaMostrar->getAdaptacion()<<endl;
    cout << " [*] Edad: " << animalaMostrar->getedad()<<endl;
    cout << " [*] Tipo de Habitad: " << animalaMostrar->getTipoHabitad()<<endl;
    cout << " [*] Dieta : " ;
    if(animalaMostrar->getTipoDieta() == 1){cout << "Carnivoro"<<endl;
    }else if(animalaMostrar->getTipoDieta()== 2){cout << "Hervivoro"<<endl;
    }else{cout << "Omnivoro"<<endl;
    }
    cout << endl;
}

void Criadero::mostrarCrias(int tp){
  if(tp==0){
    vector<Animal*>::iterator itVector;
    for(itVector = this->criasTerrestres.begin(); itVector != this->criasTerrestres.end(); ++itVector){
        Animal* animalTemp = *itVector;
        mostrarAnimal(animalTemp);
    }
  }
  else if(tp==1){
    vector<Animal*>::iterator itVector;
    for(itVector = this->criasVolador.begin(); itVector != this->criasVolador.end(); ++itVector){
        Animal* animalTemp = *itVector;
        mostrarAnimal(animalTemp);
    }
  }
  else if(tp==2){
    vector<Animal*>::iterator itVector;
    for(itVector = this->criasAcuatico.begin(); itVector != this->criasAcuatico.end(); ++itVector){
        Animal* animalTemp = *itVector;
        mostrarAnimal(animalTemp);
    }
  }
  else if(tp==3){
    vector<Animal*>::iterator itVector;
    for(itVector = this->criasSemiAcuatico.begin(); itVector != this->criasSemiAcuatico.end(); ++itVector){
        Animal* animalTemp = *itVector;
        mostrarAnimal(animalTemp);
    }
  }
}

int Criadero::randomZeroOrOne(){ 
    int randomNum = rand(); 
    if (randomNum % 2 == 0) { 
        return 0;
    } else { 
        return 1;
    }
}

Animal* Criadero::crearNuevaCria(Animal* p1, Animal* p2){
    Animal* temp;
    Animal* temp2;
    if(randomZeroOrOne()==0){
      temp = p1;
    }else{
      temp = p2;
    }

  if(temp->getAdaptacion()=="Terrestre"){
    temp2 = new Terrestre(get_cantT(),temp->getTipoHabitad(),temp->getNombreEspecie(),temp->getNombreAnimal(),temp->getTipoDieta(),1,temp->getSexoA(),temp->getTipoAdapA(),0,0);
    criasTerrestres.push_back(temp2); set_cantT(1);
  }

  else if(temp->getAdaptacion()=="Volador"){
    temp2 = new Volador(get_cantV(),temp->getTipoHabitad(),temp->getNombreEspecie(),temp->getNombreAnimal(),temp->getTipoDieta(),1,temp->getSexoA(),temp->getTipoDieta(),0,0);
    criasVolador.push_back(temp2); set_cantV(1);
  }
  else if(temp->getAdaptacion()=="Acuatico"){
    temp2 = new Acuatico(get_cantA(),temp->getTipoHabitad(),temp->getNombreEspecie(),temp->getNombreAnimal(),temp->getTipoDieta(),1,temp->getSexoA(),temp->getTipoDieta(),0,0);
    criasAcuatico.push_back(temp2); set_cantA(1);
  }
  else if(temp->getAdaptacion()=="Semi Acuatico"){
      temp2 = new SemiAcuatico(get_cantSA(),temp->getTipoHabitad(),temp->getNombreEspecie(),temp->getNombreAnimal(),temp->getTipoDieta(),1,temp->getSexoA(),temp->getTipoDieta(),0,0);
    criasSemiAcuatico.push_back(temp2); set_cantSA(1);
  }
  return temp2;
}


int Criadero::get_cantT(){
  return this->cantT;
}
int Criadero::get_cantV(){
  return this->cantV;
}
int Criadero::get_cantA(){
  return this->cantA;
}
int Criadero::get_cantSA(){
  return this->cantSA;
}

void Criadero::set_cantT(int i){
  cantT+=i;
}
void Criadero::set_cantV(int i){
  cantV+=i;
}
void Criadero::set_cantA(int i){
  cantA+=i;
}
void Criadero::set_cantSA(int i){
  cantSA+i;
}
