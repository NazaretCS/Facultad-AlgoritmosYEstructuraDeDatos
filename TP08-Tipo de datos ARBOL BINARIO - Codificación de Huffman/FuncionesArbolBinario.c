#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


typedef char itemAB;
const int indefinido = -9999;

struct NodoAB
{
    itemAB raiz;
    struct NodoAB *izq;
    struct NodoAB *der;
} typedef *AB;




AB ABVacio(){
    return NULL;
}


int EsABVacio(AB ArbolB){
    if (ArbolB == NULL)
    {
        return 1;
    } else {
        return 0;
    }
}

/*
AB CrearNodo(itemAB raiz){
    
    NuevoNodo->der = NULL;
    NuevoNodo->izq = NULL;
    return NuevoNodo;
}
*/

AB ArmarAB(AB I, itemAB raiz, AB D){
    /*
            PASOS:
                Crear dinámicamente un nuevo nodo //Funcion aparte CrearNodo
                Agregar el valor de la Raiz al nodo
                Apuntar el puntero izq del nuevo nodo al árbol I
                Apuntar el puntero der del nuevo nodo al árbol D
                Retornar el nuevo nodo
    */
    AB NuevoNodo;
    NuevoNodo = (AB) malloc(sizeof(AB));
    NuevoNodo->raiz = raiz;
    NuevoNodo->der = D;
    NuevoNodo->izq = I;
    return NuevoNodo;
}





AB Izquierdo(AB ArbolB){
    if (!EsABVacio(ArbolB))
    {
        return ArbolB->izq;
    } else {
        return NULL;
    }
}


AB Derecho(AB ArbolB){
    if (!EsABVacio(ArbolB))
    {
        return ArbolB->der;
    } else {
        return NULL;
    }
}


itemAB Raiz(AB ArbolB){
    if (!EsABVacio(ArbolB))
    {
        return ArbolB->raiz;
    } else {
        return indefinido;
    } 
}



int EsABHoja(AB ArbolB)
{
    if(ArbolB)
    {
        return(ArbolB->izq == NULL && ArbolB->der == NULL);
    }else{
        return (0);
    }
}


void imprimirPre(AB T)
{
    if(!EsABVacio(T))
    {
        printf("%c\n", Raiz(T));
        imprimirPre(T->izq);
        imprimirPre(T->der);
    }
}




void imprimirSimertrico(AB T)
{
    if(!EsABVacio(T))
    {
        imprimirSimertrico(T->izq);
        printf("%c\n", Raiz(T));
        imprimirSimertrico(T->der);
    }
}



void imprimirPos(AB T)
{
    if(!EsABVacio(T))
    {
        imprimirPos(T->izq);
        imprimirPos(T->der);
        printf("%c\n", Raiz(T));
    }
}

int PerteneceAB(AB ArbolB, itemAB x){
   // AB ArbolBAux;
    //ArbolB = ArbolB;
    if (!EsABVacio(ArbolB))
    {
        if (Raiz(ArbolB) == x || PerteneceAB(Izquierdo(ArbolB), x) || PerteneceAB( Derecho(ArbolB),  x ))
        {
            return 1;
        } else {
            return 0;
        }
        
    }
    
}


