// Patricia Palula Aguilar
// A01732537
// POO
// Proyecto 3

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
#include "Disco.h"
#include "Libro.h"
#include "Software.h"
#include "Reserva.h"


int main() {
  // Arreglos
  Material *arrMa[30];
  Reserva arrRe[60];
  Disco arrDi[30];
  Libro arrLi[30];
  Software arrSo[30];

  // Archivos
  ifstream mater;
  mater.open("Material.txt");
  ifstream reser;
  reser.open("Reserva.txt");

  // Variables
  string titulo, extString;
  char claveMat;
  int j = 0, contaRes = 0, contLi = 0, contDi =0, contSo = 0, cuentMat = 0;
  int dia, mes, anio, idMat, idCli, extInt;
  Fecha fecha, fechaB, fechaC;

  while(mater >> idMat >> titulo >> claveMat >> extInt >> extString){
    switch(claveMat){
      case 'L':
        arrMa[contLi] = &arrLi[contLi];
        arrMa[contLi] -> setIdMaterial(idMat);
        arrMa[contLi] -> setTitulo(titulo);
        arrLi[contLi].setNumPag(extInt);
        arrLi[contLi].setAutor(extString);
        contLi++;
      break;

      case 'D':
        arrMa[contDi] = &arrDi[contDi];
        arrMa[contDi] -> setIdMaterial(idMat);
        arrMa[contDi] -> setTitulo(titulo);
        arrDi[contDi].setDuracion(extInt);
        arrDi[contDi].setGenero(extString);
        contDi++;
      break;

      case 'S':
        arrMa[contSo] = &arrSo[contSo];
        arrMa[contSo] -> setIdMaterial(idMat);
        arrMa[contSo] -> setTitulo(titulo);
        arrSo[contSo].setVersion(extInt);
        arrSo[contSo].setSo(extString);
        contSo++;
      break;

      default:
      cout << "Revisa la lista de materiales" << endl;
      break;

    }
  }
  while(reser >> dia >> mes >> anio >> idMat >> idCli){
    fecha.setFecha(dia, mes, anio);
    arrRe[contaRes].setFechaR(fecha);
    arrRe[contaRes].setIdMaterial(idMat);
    arrRe[contaRes].setIdCliente(idCli);
    contaRes++;
  }
  char opcion;
  int id, idM, idC, idMaterial, valiMa;
  do{
    cout << endl;
    cout << "\n\t\t\t   >>>> LIBRERIA <<<<" << endl;
  cout << "\t\t(A) Consultar lista de materiales" << endl;
  cout << "\t\t(B) Consultar lista de reservaciones" << endl;
  cout << "\t\t(C) Consultar reservaciones por material" << endl;
  cout << "\t\t(D) Consultar reservaciones por fecha" << endl;
  cout << "\t\t(E) Hacer reservación " << endl;
  cout << "\t\t(F) Terminar" << endl;

  cout << "\n Introduzca la opcion que desee: \t";
    cin >> opcion;
    opcion = toupper(opcion);
    cout << endl;
    int z = 0, n = 0, day, month, year;
    
    switch(opcion){
      case 'A':
        cout << "Lista de materiales. \n" << endl;
        for(int i = 0; i < contLi; i++){
          arrLi[i].muestraDatos();
          cout << endl;
        }
        for(int i = 0; i < contDi; i++){
          arrDi[i].muestraDatos();
          cout << endl;
        }
        for(int i = 0; i < contSo; i++){
          arrSo[i].muestraDatos();
          cout << endl;
        }
      break;
      case 'B':
        cout << "Lista de reservaciones: " << endl;
        for(int i = 0; i < contaRes; i++){
          cout << "De: " << arrRe[i].getFechaR() << endl;
          id = arrRe[i].getIdMaterial();
          for(int j = 0; j < contLi; j++){
            idM = arrLi[j].getIdMaterial();
            if(id == idM){
              cout << "A: " << arrRe[i].calculaFechaFinReserva(7) << endl;
              cout << arrLi[j].getTitulo() << endl;
            }
          }
          for(int j = 0; j < contDi; j++){
            idM = arrDi[j].getIdMaterial();
            if(id == idM){
              cout << "A: " << arrRe[i].calculaFechaFinReserva(2) << endl;
              cout << arrDi[j].getTitulo() << endl;
            }
          }
          for(int j = 0; j < contSo; j++){
            idM = arrSo[j].getIdMaterial();
            if(id == idM){
              cout << "A: " << arrRe[i].calculaFechaFinReserva(1) << endl;
              cout << arrSo[j].getTitulo() << endl;
            }
          }
          cout << "Por: " << arrRe[i].getIdCliente() << "\n" << endl;
        }
      break;

      case 'C':
        do{
          cout << "Teclea id Material: ";
          cin >> idMaterial;
          cout << endl;
          for(int j = 0; j < contLi; j++){
            idM = arrLi[j].getIdMaterial();
            if(idMaterial == idM){
              n = 1;
            }
          }
          for(int j = 0; j < contDi; j++){
            idM = arrDi[j].getIdMaterial();
            if(idMaterial == idM){
            n = 1;
            }
          }
          for(int j = 0; j < contLi; j++){
            idM = arrSo[j].getIdMaterial();
            if(idMaterial == idM){
              n = 1;
            }
          }
        }while(n == 0);
        for(int i = 0; i < contaRes; i++){
          idM = arrRe[i].getIdMaterial();
          fecha = arrRe[i].getFechaR();
          if(idMaterial == idM){
            cout << "De: " << arrRe[i].getFechaR() << endl;
            for(int j = 0; j < contLi; j++){
              idM = arrLi[j].getIdMaterial();
              if(idMaterial == idM){
                cout << "A: " << arrRe[i].calculaFechaFinReserva(7) << endl;
                cout << arrLi[j].getTitulo() << endl;
                z = 1;
              }
            }
            for(int j = 0; j < contDi; j++){
              idM = arrDi[j].getIdMaterial();
              if(idMaterial == idM){
                cout << "A: " << arrRe[i].calculaFechaFinReserva(2) << endl;
                cout << arrDi[j].getTitulo() << endl;
                z = 1;
              }
            }
            for(int j = 0; j < contSo; j++){
              idM = arrSo[j].getIdMaterial();
              if(idMaterial == idM){
                cout <<  "A: " << arrRe[i].calculaFechaFinReserva(1) << endl;
                cout << arrSo[j].getTitulo() << endl;
                z = 1;
              }
            }
          }
        }
        if(z == 0){
          cout << "El material no esta reservado" << endl;
        }
      break;

      case 'D':
        cout << "Ingrese fecha deseada: " << endl;
        cin >> fechaB;
        for(int i = 0; i < contaRes; i++){
          fecha = arrRe[i].getFechaR();
          id = arrRe[i].getIdMaterial();
          for(int j = 0; j < contLi; j++){
            idM = arrLi[j].getIdMaterial();
            if(id == idM){
              fechaC = arrRe[i].calculaFechaFinReserva(7);
            }
          }
          for(int j = 0; j < contDi; j++){
            idM = arrDi[j].getIdMaterial();
            if(id == idM){
              fechaC = arrRe[i].calculaFechaFinReserva(2);
            }
          }
          for(int j = 0; j < contSo; j++){
            idM = arrSo[j].getIdMaterial();
            if(id == idM){
              fechaC = arrRe[i].calculaFechaFinReserva(1);
            }
          }
          if((fechaB >= fecha) && (fechaB <= fechaC)){
            cout << endl;
            cout << "Reservaciones en la fehca: \n" << endl;
            for(int j = 0; j < contLi; j++){
              idM = arrLi[j].getIdMaterial();
              if(id == idM){
              cout << arrLi[j].getTitulo() << endl;
              }
            }
            for(int j = 0; j < contDi; j++){
              idM = arrDi[j].getIdMaterial();
              if(id == idM){
              cout << arrDi[j].getTitulo() << endl;
              }
            }
            for(int j = 0; j < contSo; j++){
              idM = arrSo[j].getIdMaterial();
              if(id == idM){
              cout << arrSo[j].getTitulo() << endl;
              }
            }
            cout << "Por: " << arrRe[i].getIdCliente() << endl;
            z = 1;
          }
        }
        if(z == 0){
          cout << "Fecha: " << fechaB << endl;
          cout << "No hay reservaciones en esta fecha" << endl;
        }
      break;

      case 'E':
        cout << "Teclea la fecha en la que desees reservar" << endl;
        cout << "Dia: ";
        cin >> day;
        cout << "Mes: ";
        cin >> month;
        cout << "Año: ";
        cin >> year;
        fechaB.setFecha(day, month, year);
        cout << "Teclea tu ID de cliente: ";
        cin >> idC;
        do{
          cout << "Teclea ID del material: ";
          cin >> idMaterial;
          for(int j = 0; j < contLi; j++){
            idM = arrLi[j].getIdMaterial();
            if(idMaterial == idM){
              n = 1;
            }
          }
          for(int j = 0; j < contDi; j++){
            idM = arrDi[j].getIdMaterial();
            if(idMaterial == idM){
              n = 1;
            }
          }
          for(int j = 0; j < contSo; j++){
            idM = arrSo[j].getIdMaterial();
            if(idMaterial == idM){
              n = 1;
            }
          }
        }while(n == 0);
        for(int i = 0; i < contaRes; i++){
          id = arrRe[i].getIdMaterial();
          if(idMaterial == id){
            fecha = arrRe[i].getFechaR();
            for(int j = 0; j < contLi; j++){
              idM = arrLi[j].getIdMaterial();
              if(idM == id){
                fechaC = arrRe[i].calculaFechaFinReserva(7);
              }
            }
            for(int j = 0; j < contDi; j++){
              idM = arrDi[j].getIdMaterial();
              if(idM == id){
                fechaC = arrRe[i].calculaFechaFinReserva(2);
              }
            }
            for(int j = 0; j < contSo; j++){
              idM = arrSo[j].getIdMaterial();
              if(idM == id){
                fechaC = arrRe[i].calculaFechaFinReserva(1);
              }
            }
            if((fechaB >= fecha) && (fechaB <= fechaC)){
              cout << "\nMaterial no disponible para la fecha indicada" << endl;
              z = 1;
            }
          }
        }
        
        if(z == 0){
        cout << "\nEl material ha sido reservado en la fecha indicada" << endl;
        ofstream escribir;
        escribir.open("Reserva.txt", ios :: app);
        escribir << day << " " << month << " " << year << " " << idMaterial << " " << idC << endl;
        escribir.close();
        }
      break;

      case 'F':
      break;

      default:
        cout << "Seleccione una opcion valida" << endl;
      break;

    }

  }while(opcion != 'F');
  mater.close();
  reser.close();

  return 0;
};