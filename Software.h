#include <iostream>
#include <string>
#include "Material.h"
using namespace std;
#ifndef SOFTWARE_H
#define SOFTWARE_H

class Software : public Material{
  private:
    int version;
    string so;
  public:
    // Constructores
    Software(){version = 0; so = "";};
    Software(int id, string t, int v, string s);

    // Métodos de acceso y modificación
    int getVersion(){return version;};
    string getSo(){return so;};
    void setVersion(int v){version = v;};
    void setSo(string s){so = s;};

    // Métodos abstractos
    void muestraDatos();
    int cantidadDiasPrestamo();

};

// Constructor por parámetros
Software :: Software(int id, string t, int v, string s){
  idMaterial = id;
  titulo = t;
  version = v;
  so = s;
}

// Métodos abstractos
void Software :: muestraDatos(){
  cout << "Software" << endl;
  cout << "ID Material: " << idMaterial << endl;
  cout << "Título: " << titulo << endl;
  cout << "Versión: " << version << endl;
  cout << "Sistema Operativo: " << so << endl;
}

int Software :: cantidadDiasPrestamo(){
  return 1;
};

#endif