#include <iostream>
#include <string>
#include "Material.h" 
using namespace std;
#ifndef LIBRO_H
#define LIBRO_H

class Libro : public Material{
  private:
    int numPag;
    string autor;
  public:
    // Constructores
    Libro(){numPag = 0; autor = "";};
    Libro(int id, string t, int n, string a);

    // Métodos de acceso y modificación
    int getNumPag(){return numPag;};
    string getAutor(){return autor;};
    void setNumPag(int n){numPag = n;};
    void setAutor(string a){autor = a;};

    // Métodos abstractos
    void muestraDatos();
    int cantidadDiasPrestamo();

};

// Constructor por parámetros
Libro :: Libro(int id, string t, int n, string a){
  idMaterial = id;
  titulo = t;
  numPag = n;
  autor = a;
};

// Métodos abstractos
void Libro :: muestraDatos(){
  cout << "Libro" << endl;
  cout << "ID Material: " << idMaterial << endl;
  cout << "Título: " << titulo << endl;
  cout << "Número de paginas: " << numPag << endl;
  cout << "Autor: " << autor << endl;
}

int Libro :: cantidadDiasPrestamo(){
  return 7;
};

#endif