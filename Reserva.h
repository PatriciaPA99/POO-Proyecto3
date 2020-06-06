#include <iostream>
#include <string>
#include "Fecha.h"
using namespace std;
#ifndef RESERVA_H
#define RESERVA_H

class Reserva{
  private:
    int idMaterial, idCliente;
    Fecha fechaReservacion;
  public:
    // Constructores
    Reserva();
    Reserva(int idM, int idC, Fecha f);
    
    Fecha calculaFechaFinReserva(int dias);

    // Métodos de acceso y modificacion
    int getIdMaterial(){return idMaterial;};
    int getIdCliente(){return idCliente;};
    Fecha getFechaR(){return fechaReservacion;};
    void setIdMaterial(int idM){idMaterial = idM;};
    void setIdCliente(int idC){idCliente = idC;};
    void setFechaR(Fecha f){fechaReservacion = f;};
};

// Constructor default
Reserva :: Reserva(){
  idMaterial = 0;
  idCliente = 0;
  Fecha f(0,0,0);
  fechaReservacion = f;
};

// Constructor por parametros
Reserva :: Reserva(int idM, int idC, Fecha f){
  idMaterial = idM;
  idCliente = idC;
  fechaReservacion = f;
};

Fecha Reserva :: calculaFechaFinReserva(int dias){
  return fechaReservacion + dias;
};

#endif