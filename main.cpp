#include <iostream>
#include <fstream>
using namespace std;
#define tam 50

void ingresarElementosArreglo(int arr[], int t);
int busqueda(int arr[], int t, int dato);
void imprimirElementosArreglo(int arr[], int t);
void escribirArchivo(int arrr[], string nombrearchivo, int t, int dato);


int main() {
  ofstream archivo;
  archivo.open("demo.txt", ios::app);

  int arreglo[tam];
  int t,dato;
  string narchivo;
  cout<<"Ingresar nombre del archivo";
  getline(cin,narchivo);
  cout<<"Ingrese el tamaño del arreglo: ";
  cin>>t;
  ingresarElementosArreglo(arreglo,t);
  cout<<"Ingrese el numero que desea buscar: ";
  cin>>dato;
  archivo<<"El numero a buscar: "<<dato<<endl;
  if(busqueda(arreglo, t, dato)==-1){
      cout<<"Elemento no encontrado";
      archivo<<"Elemento no encontrado\n";
    }
  else {cout<<"Elemento encontrado en la posicion: "<<busqueda(arreglo, t, dato)<<endl;
  archivo<<"Elemento encontrado en la posicion: "<<busqueda(arreglo, t, dato)<<endl<<endl;}
  imprimirElementosArreglo(arreglo, t);

archivo.close();
}



void escribirArchivo(int arrr[], string nombrearchivo, int t, int dato)
{
  int i;
  ofstream archivoarreglo;
  archivoarreglo.open(nombrearchivo.c_str(),ios::out);
  archivoarreglo<<"Arreglo de elementos:\n";
  for (i=0; i<t; i++)
  {
    archivoarreglo<<"|"<<arrr[i]<<"|";
  }
  archivoarreglo<<endl;
  archivoarreglo.close();
}

int busqueda(int arr[], int t, int dato){
  int aux =  -1;
  for(int i = 0; i<t;i++){
    if(arr[i]==dato){
      aux = i;
    }
  }
  return aux;
}

void imprimirElementosArreglo(int arr[], int t){
   for(int i = 0; i<t;i++){
    cout<<"["<<arr[i]<<"] ";   
  }
}