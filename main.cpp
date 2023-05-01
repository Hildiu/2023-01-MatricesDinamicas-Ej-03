#include <iostream>
#include <iomanip>

using namespace std;

int * * dimensionar( int filas, int col );
void imprimir(  int * *pM, int filas, int col );
int  hallarMenor( int* *pM,  int filas, int col);
int hallaSumaDeDiagonal(  int **p, int filas, int col);
int sumaPorEncimaDeLaDiagonal(  int * *pM, int filas );
void  llenarDatos(int **pMat, int filas, int col);

int main()
{   int **pMat = nullptr;

   srand(time(nullptr));
   pMat = dimensionar(8,8);
   //--- ahora generamos datos aleatorios y los colocamos en la matriz
   llenarDatos(pMat,8,8);
   imprimir(pMat,8,8);
   int elMenor = hallarMenor(pMat, 8, 8);
   cout <<"\nEl dato mas pequenno es: " << elMenor << "\n";
   int diagonal= hallaSumaDeDiagonal(pMat, 8, 8);
   cout << "La suma de los elementos de la diagonal es: " << diagonal << "\n";
   int sumaPorEncima  = sumaPorEncimaDeLaDiagonal(pMat,8);
   cout<< "\nLa suma de los elementos que estan por encima de la matriz es : " << sumaPorEncima;
   //----liberamos la memoria!!!
   for(int f=0; f<8; f++)
       delete []pMat[f];
   delete []pMat;
   pMat= nullptr;
   return 0;
}

void  llenarDatos(int **pMat, int filas, int col)
{
  for(int f=0; f<filas; f++)
    for(int c=0; c<col; c++)
      pMat[f][c]= rand() % 100 + 1;

}

int sumaPorEncimaDeLaDiagonal(  int * *pM, int filas )
{
  int suma =0;
  for(int f=0; f<filas-1; f++)
      for(int c=f+1; c<filas; c++)
          suma = suma + pM[f][c];
  return suma;
}

int hallaSumaDeDiagonal(  int **p, int filas, int col)
{
    int suma=0;
    for(int f=0; f<filas; f++)
        suma = suma + p[f][f];
    return suma;
}


int  hallarMenor( int* *pM,  int filas, int col)
{
    int elmenor = pM[0][0];
    for(int f=0; f<filas; f++)
        for(int c=0; c<col; c++)
            if(pM[f][c]<elmenor)
                elmenor= pM[f][c];
    return elmenor;
}


int * * dimensionar( int filas, int col )
{
   int **p = new int*[filas];
   for(int f=0; f<filas; f++)
       p[f] = new int[col];
   return p;
}


void imprimir(  int * *pM, int filas, int col )
{
    for(int f=0; f<filas; f++)
    {
        for(int c=0; c<col; c++)
            cout << setw(6) << pM[f][c];
        cout << "\n";
    }

}