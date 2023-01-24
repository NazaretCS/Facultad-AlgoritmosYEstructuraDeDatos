#include<stdio.h>
#include<stdlib.h> //Para la reserva de memoria dinamica

typedef int item;

struct Nodo
{
    item dato;
    struct Nodo* Siguiente;
};

typedef struct Nodo* Lista;


Lista CrearLista();
Lista Insertar( Lista L, item x);
int EsListaVacia(Lista L);
Lista BorrarPrimerElemento(Lista L);
item PrimerElemento(Lista L);
void MostrarLista(Lista L);
int LonguitudDeLaLista(Lista L);
int Pertenece(Lista L, item x);
Lista BorrarK( Lista L, item x);
int EstaContenida(Lista L1, Lista L2);

int main(void){

    int Activador, NodoAgregar, primerDato, LargoLista, Valor, result, valor2;

    Lista L;
    L = CrearLista();


    do
    {
        printf("=============   Programa de Listas   =======================\n");
        printf("Por favor, seleccione la operacion que desea realizar: \n");
        printf("1:  Insertar un item en la lista\n");
        printf("2:  Mostrar la Lista\n");
        printf("3:  Saber cual es el primer elemento de la lista\n");
        printf("4:  Borrar el primer elemento de la Lista\n");
        printf("5:  Conocer la Longuitud de la lista\n");
        printf("6:  Determinar si un valor ya se encuentra ingresado en la lista\n");
        printf("7:  Borrar todos los nodos que sean igual a un determinado valor\n");
        //printf("8:  Provar funcion EstaContenida\n");
        printf("8  Para salir del programa.\n");

        scanf("%d",&Activador);

        switch (Activador)
        {
        case 1:
            //int NodoAgregar;
            printf("Ingrese el valor a Agregar: \n");
            scanf("%d",&NodoAgregar);
            L = Insertar(L, NodoAgregar);
            printf("\nEl valor fue agregado con Exito. \n\n\n\n");
            break;

        case 2:
            MostrarLista(L);
            break;
        case 3:
            //int primerDato;
            primerDato = PrimerElemento(L);
            printf("El primer Elemento de la lista correspode a: %d\n\n\n\n", primerDato);
            break;

        case 4:
            L = BorrarPrimerElemento(L);
            printf("El primer elemento de al lista fue borrado con exito\n\n\n\n");
            break;

        case 5:
            //int LargoLista;
            LargoLista = LonguitudDeLaLista(L);
            printf("La Longuitud de la Lista es de: %d \n\n\n\n", LargoLista);
            break;

        case 6:
            //item Valor, result;
            printf("Ingrese el valor que desea conocer si se encuentra en la lista: \n");
            scanf("%d",&Valor);
            result = Pertenece(L, Valor);
            if (result > 0) {
                printf("El valor si se encuentra en la lista\n\n\n\n");
            } else {
                printf("El valor no se encuentra en la lista\n\n\n\n");
            }
            break;
        
        case 7:
            //int valor2;
            printf("Ingrese el Valor que desea eliminar completamente de la lista: \n");
            scanf("%d",&valor2);
            L = BorrarK(L, valor2);
            printf("La operacion se realizo exitosamente \n\n\n\n");
            break;

        case 8:
            Activador == 0;
            break;
        }

    } while (Activador != 0);
    

    return 0;
}

Lista CrearLista(){
    return NULL;
}

Lista Insertar( Lista L, item x){
    Lista DatoAInsertar;
    DatoAInsertar = malloc(sizeof(Lista));
    DatoAInsertar->dato = x;
    DatoAInsertar->Siguiente = L;
    L =DatoAInsertar;
    return L;
}

int EsListaVacia(Lista L){
    Lista Seguidor;
    Seguidor = L;
    if (Seguidor == NULL){
        return 1;
    } else {
        return 0;
    }
}

Lista BorrarPrimerElemento(Lista L){
    if (!EsListaVacia(L)){
        Lista Auxiliar;
        Auxiliar = L;
        L = Auxiliar->Siguiente;
        free(Auxiliar);
        return L;
    } else {
        return L;
    }
}

item PrimerElemento(Lista L){
    Lista Auxiliar;
    Auxiliar = L;
    if (EsListaVacia(Auxiliar))
    {
        printf("Actualmente, la lista no posee ningun elemento\n");
    } else {
        return Auxiliar->dato;
    }
}

void MostrarLista(Lista L){
    Lista Auxiliar;
    Auxiliar = L;
    int NumElemento=1;
    if (!EsListaVacia(Auxiliar))
    {
        while (!EsListaVacia(Auxiliar))
        {
            printf("El elemento %d de la lista es %d \n",NumElemento, Auxiliar->dato);
            NumElemento = NumElemento + 1;
            Auxiliar = Auxiliar->Siguiente;
        }    
    } else {
        printf("La Lista se encuentra vacia\n");
    }
}

int LonguitudDeLaLista(Lista L){
    int Posicicion;
    Lista Auxiliar;
    Auxiliar = L;
    while (!EsListaVacia(Auxiliar))
    {
        Posicicion++;
        Auxiliar = Auxiliar->Siguiente;
    }
    return Posicicion;
}

int Pertenece(Lista L, item x){
    Lista Auxiliar;
    Auxiliar = L;
    int Coincidencias=0;
    if(!EsListaVacia(Auxiliar)){
        while (!EsListaVacia(Auxiliar) && Coincidencias == 0)
        {
            if(Auxiliar->dato == x){
                Coincidencias++;
            }
            Auxiliar = Auxiliar->Siguiente;
        }
        
    }
    return Coincidencias;
}

/*
Especificacion Algebraica:

Borrark: Lista x item -> Lista

Para todo L perteneciente a Lista, Para todo x perteneciente a item

BorrarK(ListaVacia, x) = ListaVacia
BorrarK(Insertar(L, i), x) = Si x = i Entonces
                                BorrarK(L,x)
                             Sino 
                                Insertar( BorrarK( L, x), i)
*/

Lista BorrarK( Lista L, item x){
    Lista Auxiliar;
    Auxiliar = L;
    item Iauxiliar, Iauxiliar2;
    if (EsListaVacia(Auxiliar))
    {
        return L;
    } else {
        Iauxiliar = Auxiliar->dato;
        if (Iauxiliar == x)
        {
            Auxiliar = BorrarPrimerElemento(Auxiliar);
            BorrarK(Auxiliar, x);
        } else 
            Iauxiliar2 = Auxiliar->dato;
            Auxiliar = BorrarPrimerElemento(Auxiliar);
            Insertar(BorrarK(Auxiliar, x), Iauxiliar2);
        }
    return L;        
}



int EstaContenida(Lista L1, Lista L2){
    int Coincidencias = 0, CantItemL1;
    CantItemL1 = LonguitudDeLaLista(L1);
    if (!EsListaVacia(L1))
    {
        while (!EsListaVacia(L1) && !EsListaVacia(L2))
        {
            if (PrimerElemento(L1) == PrimerElemento(L2))
            {
                Coincidencias++;
            }
            BorrarPrimerElemento(L1);
            BorrarPrimerElemento(L2);
        }
  
    }
    if (Coincidencias == CantItemL1)
    {
        return 1;
    } else {
        return 0;
    }
    
}

void ContarMenoresQue(Lista L, item k){
    int contador;
    Lista seguidor;
    seguidor = L;
    if (!EsListaVacia(seguidor))
    {
         while (seguidor != NULL)
        {
            if (seguidor->dato < k)
            {
                contador++;
            }
            seguidor = seguidor->Siguiente;
        }
    }
}





