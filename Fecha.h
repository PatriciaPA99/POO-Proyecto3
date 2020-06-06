#include <iostream>
#include <string>
using namespace std;
#ifndef FECHA_H
#define FECHA_H

class Fecha{
  private:
    int dd, mm, aa;
    string nombreMes();

  public:
    // Constructores
    Fecha(){dd = 0; mm = 0; aa = 0;};
    Fecha(int d, int m, int a){dd = d; mm = m; aa = a;};

    // Métodos de acceso
    int getDd(){return dd;};
    int getMm(){return mm;};
    int getAa(){return aa;};

    void setFecha(int d, int m, int a);

    // Sobrecarda de operadores
    Fecha operator + (int dias);
    bool operator >= (Fecha f2);
    bool operator <= (Fecha f2);
    bool operator > (Fecha f2);
    bool operator < (Fecha f2);
    bool operator == (Fecha f2);
    friend istream &operator >> (istream &is, Fecha &f);
    friend ostream &operator << (ostream &os, Fecha f);
};

void Fecha :: setFecha(int d, int m, int a){
  dd = d;
  mm = m;
  aa = a;
};

Fecha Fecha :: operator + (int dias){
  int d, m, a;
  d = dd + dias;
  m = mm;
  a = aa;
  if(d > 31 ){
    if(mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12){
      d = d - 31;
      if(mm == 12){
        m = 1;
        a++;
      }else{
        m++;
      }
    }
  }else if(dd > 30 && (mm == 4 || mm == 6 || mm == 9 || mm == 11)){
    d = d - 30;
    m++;
  }else if(d > 28 && m == 2){
    d = d - 28;
    m++;
  }
  Fecha nueva(d, m, a);
  return nueva;
};

bool Fecha :: operator >= (Fecha f2){
  if(aa >= f2.aa && mm >= f2.mm && dd >= f2.dd){
    return true;
  }else{
    return false;
  }
};

bool Fecha :: operator <= (Fecha f2){
  if(aa <= f2.aa && mm <= f2.mm && dd <= f2.dd){
    return true;
  }else{
    return false;
  }
};

bool Fecha :: operator > (Fecha f2){
  if(aa > f2.aa && mm > f2.mm && dd > f2.dd){
    return true;
  }else{
    return false;
  }
};

bool Fecha :: operator < (Fecha f2){
  if(aa < f2.aa && mm < f2.mm && dd < f2.dd){
    return true;
  }else{
    return false;
  }
};

bool Fecha :: operator == (Fecha f2){
  if(aa == f2.aa && mm == f2.mm && dd == f2.dd){
    return true;
  }else{
    return false;
  }
};

string Fecha :: nombreMes(){
  string mes;
  switch(mm){
    case 1:
    mes = "Ene";
    break;
    case 2:
    mes = "Feb";
    break;
    case 3:
    mes = "Mar";
    break;
    case 4:
    mes = "Abr";
    break;
    case 5:
    mes = "May";
    break;
    case 6:
    mes = "Jun";
    break;
    case 7:
    mes = "Jul";
    break;
    case 8:
    mes = "Ago";
    break;
    case 9:
    mes = "Sep";
    break;
    case 10:
    mes = "Oct";
    break;
    case 11:
    mes = "Nov";
    break;
    case 12:
    mes = "Dic";
    break;
  }
  return mes;
};

istream &operator >> (istream &is, Fecha &f){
  cout << "Día: ";
  is >> f.dd;
  cout << "Mes: ";
  is >> f.mm;
  cout << "Año: ";
  is >> f.aa;
  return is;
}

ostream &operator << (ostream &os, Fecha f){
  os << f.dd << "/" << f.nombreMes() << "/" << f.aa;
  return os;
}

#endif
