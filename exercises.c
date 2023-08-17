#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Ejercicio 1: Encuentra el Elemento Mayor
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y devuelva el valor más grande del arreglo.
*/
int findMax(int lista[], int tamano)
{
  int mayor = lista[0];
  for (int i = 0; i < tamano; i++)
    {
      if(mayor < lista[i])
      {
        mayor = lista[i];
      }
    }
  return mayor;
}



/*
Ejercicio 2: Invertir un Arreglo
Descripción: Escribe una función que tome un arreglo y su tamaño, y luego
invierta el orden de sus elementos.
*/
void reverseArray(int lista[], int tamano)
{
  int listaAux[tamano];
  int aux = tamano-1;
  
  for(int q=0; q < tamano ;q++)
    {
      listaAux[q] = lista[aux];
      aux--;
    }
  
  for(int q = 0; q<tamano ;q++)
    {
      lista[q] = listaAux[q];
    }
}



/*
Ejercicio 3: Filtrar Números Pares
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y luego devuelva un nuevo arreglo que contenga solo
los números pares del arreglo original.
*/
int *filterEvenNumbers(int lista[], int tamano, int *nuevoTam) 
{
  int *listaPar = (int*)malloc(tamano * sizeof(int));
  int aux = 0;
  for(int i = 0; i<tamano ;i++)
    {
      if(lista[i] % 2 == 0)
      {
        listaPar[aux] = lista[i];
        aux++;
      }
    }
  *nuevoTam = aux;
  return listaPar;
}


/*
Ejercicio 4: Fusión de dos Arreglos Ordenados
Descripción: Escribe una función que tome dos arreglos
ordenados y sus tamaños, y luego fusione estos dos
arreglos en un tercer arreglo también ordenado.
*/
void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2, int result[])
{
  int i,k,j;
  i = 0;
  k = 0;
  j = 0;
  while (i<size1 && k<size2)
  {
    if(arr1[i] <= arr2[k])
    {
      result[j] = arr1[i];
      j++;
      result[j] = arr2[k];
    }
    else
    {
      result[j] = arr2[k];
      j++;
      result[j] = arr1[i];
    }
    if(i < size1)
    {
      i++;
    }
    if(k < size2)
    {
      k++;
    }
  }
}

/*
Ejercicio 5: Comprobación de Ordenación
Descripción: Escribe una función que tome un arreglo y su tamaño,
y luego devuelva 1 si el arreglo está ordenado en orden ascendente,
  0 si no está ordenado, y -1 si está ordenado en orden descendente.
*/
int checkSorted(int arr[], int size) 
{
  int orden = 0;
  for(int i = 1; i<size ; i++)
    {
      if(arr[i-1] <= arr[i])
      {
        orden++;
        if(arr[i] > arr[i+1])
        {
          return 0;
        }
      }
      else
      {
        orden--;
        if(arr[i] > arr[i+1])
        {
          return 0;
        }
      }
    }

      if(orden > 0)
      {
        orden = 1;
        return orden;
      }
      orden = -1;
      return orden;
    
}

/*
Ejercicio 6: Información de una Biblioteca
Descripción: Vamos a representar la información de una biblioteca. En la
biblioteca, hay libros, y cada libro tiene un autor. Queremos organizar esta
información utilizando estructuras anidadas en C. Escribe la función para
inicializar la información de un libro.
*/

typedef struct {
  char nombre[50];
  int anioNacimiento;
} Autor;

typedef struct {
  char titulo[100];
  Autor autor;
  int anioPublicacion;
} Libro;

void inicializarLibro(Libro *libro, const char *titulo, const char *nombreAutor,int anioNacimiento, int anioPublicacion) 
{
  strcpy(libro->titulo, titulo);
  anioPublicacion = libro->anioPublicacion;
  
  strcpy(libro->autor.nombre, nombreAutor);
  anioNacimiento = libro->autor.anioNacimiento;
}

/*
Ejercicio 7: Lista enlazada de números
Descripción: Escribe una función que tome un arreglo de enteros y su tamaño, y
luego cree una lista enlazada usando la estructura Nodo. Cada nodo de la lista
debe contener un número del arreglo, y los nodos deben estar enlazados en el
mismo orden que los números aparecen en el arreglo. El último nodo de la lista
debe apuntar a NULL. La función debe devolver un puntero al primer nodo de la
lista enlazada.
Recuerda reservar memoria dinámica para cada nodo usando malloc.
  */

typedef struct nodo {
  int numero;
  struct nodo *siguiente; // puntero al siguiente nodo
} Nodo;

Nodo *crearListaEnlazada(int arr[], int size) 
{ 
  Nodo* cabeza = NULL; // Inicializamos la cabeza de la lista enlazada
  Nodo* actual = NULL;
  Nodo* sgte = NULL;

  for (int i = 0; i < size; i++) 
  {
    actual = (Nodo*)malloc(sizeof(Nodo));
    actual->numero = arr[i];
    actual->siguiente = NULL;
    if (cabeza == NULL) 
    {
      cabeza = actual; 
    } 
    else 
    {
      sgte->siguiente = actual; 
    }
    sgte = actual; 
  }

  return cabeza;
 
}
