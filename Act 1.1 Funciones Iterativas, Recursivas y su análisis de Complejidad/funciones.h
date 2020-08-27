#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <iostream>
using namespace std;

class Funciones{
public:
  long sumaIterativa(int n);
  long sumaRecursiva(int n);
  long sumaDirecta(int n);
};

long Funciones::sumaIterativa(int n){
  long acum = 0;
  for(long i = 1; i<=n; i++)
    acum = acum + i;
  return acum;
}
// 0+1
// 1+2
// 2+3

long Funciones::sumaRecursiva(int n){
  if (n<1)
    return 0;
  else
    return n+sumaRecursiva(n-1);
}

// 3+2
//2+1
//1+0
//0

long Funciones::sumaDirecta(int n){
  return (n*(n+1))/2;
}
#endif
/*int main(int argc, char* argv[]){
  int n;
  cout << "Introduce un número para obtener su sumatoria";
  cin >> n;
  cout << sumaRecursiva(n) << "\n";

}*/
