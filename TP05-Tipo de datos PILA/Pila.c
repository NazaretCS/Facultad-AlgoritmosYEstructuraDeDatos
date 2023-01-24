#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<unistd.h>

typedef int item;
const item indefinido = -9999;
struct nodo
{
    item Dato;
    struct nodo *Siguiente;
}typedef Nodo;

typedef struct 
{
    struct nodo *Cabecera;
    int altura;
}Pila;


void CreaPila(Pila *PP);
int EsPilaVacia(Pila *PP);
void PUSH(Pila *PP, item x);
item TOP(Pila *PP);
void POP(Pila *PP);
void PUSHF(Pila *PP, item x);
item FONDO(Pila *PP);
int AlturaPila(Pila *PP);
Pila MostrarPila(Pila *PP);

int main(void){
    item x, y=0, elemento;
    int altura, Accion=1, operacion;
    Pila PP, *Ppila;
    CreaPila(&PP);
    Ppila = &PP;

    /*
    if (Ppila->Cabecera == NULL)
    {
        printf("La pila se creo con exito\n");
    } else {
        printf("fallo total\n");
    }
    

    if(EsPilaVacia(Ppila)){
        printf("La pila se encuentra vacia \n");
    } else {
        printf("La pila no se encuentra vacia \n");
    }

    PUSH(Ppila, 1);

    if(EsPilaVacia(Ppila)){
        printf("La pila se encuentra vacia \n");
    } else {
        printf("La pila no se encuentra vacia \n");
    }

    
    x = TOP(Ppila);
    printf("El tope de la pila es: %d\n",x);

    PUSH(Ppila, 2);
    PUSH(Ppila, 3);

    x = TOP(Ppila);
    printf("El tope de la pila es: %d\n",x);

    POP(Ppila);

    x = TOP(Ppila);
    printf("El tope de la pila es: %d\n",x);

    POP(Ppila);

    x = TOP(Ppila);
    printf("El tope de la pila es: %d\n",x);

    POP(Ppila);

    x = TOP(Ppila);
    printf("El tope de la pila es: %d\n",x);
    
    PUSH(Ppila,2);
    PUSH(Ppila,3);
    PUSH(Ppila,4);
    PUSH(Ppila,5);

    x = TOP(Ppila);
    printf("El tope de la pila es: %d\n",x);  
    
    PUSHF(Ppila,9);
    x = TOP(Ppila);
    printf("El tope de la pila es: %d\n",x);

    altura = AlturaPila(Ppila);
    printf("La altura de la pila es de: %d\n",altura);

    y = FONDO(Ppila);
    printf("El fondo de la pila corresponde a: %d \n",y);

    altura = AlturaPila(Ppila);
    printf("La altura de la pila es de: %d\n",altura);
    */

    do
    {
        printf("\n\n::::::::::::::   PROGRAMA_PILA_DE_ENTEROS   ::::::::::::::\n\n");
        printf("Seleccione la operacion que desea realizar________________\n");
        printf("1  Saber si la pila se encuentra vacia\n");
        printf("2  Insertar un elemento a la pila\n");
        printf("3  Devoler el tope de la pila\n");
        printf("4  Quitar el tope de la pila\n");
        printf("5  Insertar un elemento en el fondo de la pila\n");
        printf("6  Determinar que elemento se encuentra en el fondo de la pila\n");
        printf("7  Determinar la Altura de la Pila\n");
        printf("8  Mostrar la Pila\n\n");
        printf("0  Salir del Programa\n\n");

        scanf("%d",&operacion);

        switch (operacion)
        {
        case 1:
            printf("1  Saber si la pila se encuentra vacia\n");
            if (EsPilaVacia(Ppila))
            {
                printf("La Pila Si se Encuentra Vacia\n");
            } else {
                printf("La pila no se Encuentra Vacia\n");
            }
            //getchar();
            sleep(4);
            printf("\n\n\n\n\n\n");
            break;

        case 2:
            printf("2  Insertar un elemento a la pila\n");
            printf("Ingrese el elemento numerico que desea ingresar a la pila:  ");
            scanf("%d",&elemento);
            PUSH(Ppila, elemento);
            printf("Insercion Exitosa\n");
            sleep(4);
            printf("\n\n\n\n\n\n");
            break;
        
        case 3:
            printf("3  Devoler el tope de la pila\n");  
            elemento = TOP(Ppila);
            printf("En el tope de la pila se encuentra el elemento [ %d ] \n",elemento);
            sleep(4);
            printf("\n\n\n\n\n\n");
            break;

        case 4:
            printf("4  Quitar el tope de la pila\n");
            POP(Ppila);
            printf("Tope de la pila quitado exitosamente\n");
            sleep(4);
            printf("\n\n\n\n\n\n");
            break;
        
        case 5:
            printf("5  Insertar un elemento en el fondo de la pila\n");
            printf("Ingrese el elemento numerico que desea ingresar en la pila:  ");
            scanf("%d",&elemento);
            PUSHF(Ppila,elemento);
            printf("Insercion del elemento en el fondo de la pila Exitosa");
            sleep(4);
            printf("\n\n\n\n\n\n");        
            break;

        case 6:
            printf("6  Determinar que elemento se encuentra en el fondo de la pila\n");
            elemento = FONDO(Ppila);
            printf("El elemento que se encuetra en el fondo de la pila es: [ %d ] ", elemento);
            sleep(4);
            printf("\n\n\n\n\n\n");   
            break;
        
        case 7: 
            printf("7  Determinar la Altura de la Pila\n");
            altura = AlturaPila(Ppila);
            printf("La altura de la pila es de: [ %d ] ", altura);
            sleep(4);
            printf("\n\n\n\n\n\n");   
            break;
        
        case 8:  
            printf("8  Mostrar la Pila\n");
           
            *Ppila = MostrarPila(Ppila);
            sleep(4);
            break;
        case 0:
            printf("0  Salir del Programa\n");
            sleep(4);
            Accion = 0;
            break;
        }
    } while (Accion != 0);
    
    return 0;
}

void CreaPila(Pila *PP){
    PP->Cabecera = NULL;
    PP->altura = 0;
}

int EsPilaVacia(Pila *PP){
    if (PP->Cabecera == NULL)
    {
        return 1;
    }else {
        return 0;
    }
}

item TOP(Pila *PP){
    if(!EsPilaVacia(PP)){
        return PP->Cabecera->Dato;
    } else {
        printf("La pila no posee datos\n");
    }
}

void PUSH(Pila *PP, item x){
    /*
    reservar la memoria para el nuevo nodo
    hacer que el puntero siguiente del nuevo nodo apunte al primer elemento de la pila
    apuntar la cabecera al nuevo nodo
    incrementar la altura
    */
    Nodo *NodoAux;
    NodoAux = (Nodo *) malloc(sizeof(Nodo));
    NodoAux->Dato = x;
    NodoAux->Siguiente = PP->Cabecera;
    PP->Cabecera = NodoAux;
    PP->altura++;
}

void POP(Pila *PP){
    /*
    controlar que la pila no este vacia
    reservo memoria para el nodo.
    igualo el nodoAux y la cabecera
    apunto la cabecera a el siguiente del primer nodo
    decremento la altura
    libero la memoria
    */
    if (!EsPilaVacia(PP))
    {
        Nodo *NodoAux;
        NodoAux = PP->Cabecera;
        PP->Cabecera = NodoAux->Siguiente;
        PP->altura--;
        free(NodoAux);
    }
}


void PUSHF(Pila *PP, item x){
    /*
    Controlar si la pila esta vacia
    */
    if (!EsPilaVacia(PP))
    {
      /*
      Si la pila esta vacia creo un itemAux para guargar el dato del elemento al que apunta la cabecera.
      quito el primer elemento de la Pila,
      y hago el pushf
      */   
        item ItemAux;
        ItemAux = PP->Cabecera->Dato;
        POP(PP);
        PUSHF(PP, x);
        PUSH( PP, ItemAux);
    } else {
        PUSH(PP, x);
    }
    
}

item FONDO(Pila *PP){
    item ItemAux, ItemAux2;
    if (!EsPilaVacia(PP))
    {
        ItemAux = PP->Cabecera->Dato;
        POP(PP);
        if (EsPilaVacia(PP))
        {
            PUSHF(PP,ItemAux); // Por este camino solo entrara una sola vez asi que inserto el item q corresponderia al fondo
            return ItemAux;
        } else {
            ItemAux2 = FONDO(PP);
            PUSH(PP,ItemAux); //Vuelvo a insertar los items, porque sino me elimina toda la pila
        }
    } else {
        printf("La pila se encuentra vacia\n");
    }
    return ItemAux2;
}


int AlturaPila(Pila *PP){
    return PP->altura;
}

Pila MostrarPila(Pila *PP){  //Me borra los elementos de la pila. bueno no los borra en si.
    Pila *Auxiliar;
    Auxiliar = PP;
    if (!EsPilaVacia(Auxiliar))
    {
        printf(":::   Elementos de la Pila  ::: \n");
        while (!EsPilaVacia(Auxiliar))
        {
            printf("--- [ %d ] ---\n", Auxiliar->Cabecera->Dato);
            Auxiliar->Cabecera = Auxiliar->Cabecera->Siguiente;            
        }
    } else {
        printf("La pila ingresada no contiene elementos\n");
    }
    return *PP; // ya estaba desesperado...
}