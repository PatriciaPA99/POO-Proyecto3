#include <iostream>
#include <string>
using namespace std;
#ifndef MATERIAL_H
#define MATERIAL_H

class Material{
  protected:
    int idMaterial;
    string titulo;
  public:
    // Constructores
    Material(){idMaterial = 0; titulo = "";};
    Material(int id, string t){idMaterial = id; titulo = t;};

    // Métodos de acceso y modificacion
    int getIdMaterial(){return idMaterial;};
    string getTitulo(){return titulo;};
    void setIdMaterial(int id){idMaterial = id;};
    void setTitulo(string t){titulo = t;};

    // Métodos abstractos
    virtual void muestraDatos() = 0;
    virtual int cantidadDiasPrestamo() = 0;
    
};

void Material :: muestraDatos(){
  cout << "ID Material" << idMaterial << endl;
  cout << "Título" << titulo << endl; 
}

#endif