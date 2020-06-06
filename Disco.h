#include <iostream>
#include <string>
#include "Material.h"
using namespace std;
#ifndef DISCO_H
#define DISCO_H

class Disco : public Material{
  private:
    int duracion;
    string genero;
  public:
  // Constructores
  Disco(){duracion = 0; genero = "";};
  Disco(int id, string t, int d, string g);

  // Métodos de acceso y modificación 
  int getDuracion(){return duracion;};
  string getGenero(){return genero;};
  void setDuracion(int d){duracion = d;};
  void setGenero(string g){genero = g;};

  // Métodos abstractos
  void muestraDatos();
  int cantidadDiasPrestamo() ;

};

// Constructor por parámetros
Disco :: Disco(int i, string t, int d, string g){
  idMaterial = i;
  titulo = t;
  duracion = d;
  genero = g;
};

// Métodos abstractos
void Disco :: muestraDatos(){
  cout << "Disco" << endl;
  cout << "ID Material: " << idMaterial << endl;
  cout << "Título: " << titulo << endl;
  cout << "Duracion: " << duracion << endl;
  cout << "Género: " << genero << endl;
}

int Disco :: cantidadDiasPrestamo(){
  return 2;
};

#endif