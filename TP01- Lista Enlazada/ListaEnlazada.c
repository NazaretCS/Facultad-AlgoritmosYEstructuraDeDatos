/* Lista Enlazada */

#include<stdio.h>
#include<stdlib.h>

/* Creacion de la Lista Enlazada */
typedef int item;
struct nodo
{
    item dato;
    struct nodo* siguiente;
}nodo;
typedef struct nodo* Lista;

/*
Lista crearLista(){
    Lista L;
    L = NULL;
    return L;
}
*/

Lista CrearLista(){
    return NULL;  //Un puntero que apunta a NULL
}

Lista Insertar(Lista L, item x){
    Lista nuevo = (Lista) malloc(sizeof(Lista));   //Reservo la memoria dinámica para el nuevo nodo.
    nuevo->dato = x;                        // Inserto el dato al nodo creado.
    nuevo->siguiente = L;                   // Hago que el nodo apunte a la Cabecera de la lista (osea, al primer elemento de la lista)
    L = nuevo;                              // La vabecera de la lista apunta al nuevo nodo creado
    return L;                               // Las Funciones siempre deven llevar el return, a menos que sean del tipo void
}

int EsListaVacia(Lista L){
    //La lista se debe recorrer a traves de un seguidor, porque despues
    //si otra funcion la recorre a la lista L el puntero queda mal posicionado
    //pero si usamos una copia (seguidor) se recorre la copia de la lista y no
    //cambia la lista original.
    struct nodo *seguidor = L;
    if (seguidor == NULL)                          
    {
        return 1;
    } else {
        return 0;
    }
}

void Mostrar(Lista L){ 
    printf("Mostrado de la Lista \n");
    struct nodo *seguidor = L;
    if(EsListaVacia(L) != 1)
    {
        while (seguidor!=NULL)
        {
            printf(" - %d\n", seguidor->dato); 
            //Hay que poner %d dentro de las comillas del print para poder mostrar el contenido de la variable
            seguidor = seguidor->siguiente;
        }
    }else
    {
        printf("\nLa lista esta vacia.");
    }
}

item PrimerElemento(Lista L){
    struct nodo *seguidor = L;
    int dato;
    if (EsListaVacia(L))
    {
        printf("La lista se encuntra vacia\n");
        
    } else {
        printf("El primer elemento de la lista corresponde al valo de: %d\n", seguidor->dato);
        return seguidor->dato;
    }
}

Lista BorrarPrimerElemento(Lista L){
    if (!EsListaVacia(L))
    {
        struct nodo* auxialiar = L;//Al no estar instanciada daba error de segmentacion
        //tenes que inicializar el auxiliar con la lista original L
        
        L = L->siguiente;
        free(auxialiar); //Se elimina el primer elemento

        /*
        auxialiar->siguiente = L->siguiente;
        L->siguiente = (L->siguiente)->siguiente;
        free(auxialiar);
        Con este codigo estabas eliminando el segundo elemento no el primero, ksi
        */
        return L;
    } else {
        return NULL;
    }
    
}

int Longuitud(Lista L){
    int contador = 0;
    struct nodo *seguidor = L;
    while(seguidor != NULL){
        seguidor = seguidor->siguiente;
        contador++;
    }
    return contador;
}

//Provar poner un tercer campo en la estructura y usarlo como contador, cada vez que se incremente un nodo incrementar ese contador; asi se reduciria el costo del algoritmo.

int Pertenece(Lista L, item k){
    struct nodo *seguidor = L;
    int coincidencias = 0;
    while (!EsListaVacia(seguidor)) //Si debo recorrer la lista me manejo con la copia de la lista original
    {
        if (seguidor->dato == k)
        {
            coincidencias++;
        }
        seguidor = seguidor->siguiente; //Debe avanzar el recorrido de la lista        
    }
    return coincidencias;
}

Lista BorrarK(Lista L, item k){
    //Para esta funcion se necesitan de dos listas auxiliares,
    //una que contenga el nodo anterior al que queres eliminar y otra
    //que recorra y busque el nodo que queres eliminar

    struct nodo *seguidor = L; //Copia de la lista original 
    struct nodo *anterior; //Lista que apuntara al nodo anterior al que queres eliminar, no se instancia

    
    if(!EsListaVacia(L) && Pertenece(L,k)!=0) //Controlo que la lista no sea vacia y que el elemento que quiero eliminar este contenido en la lista
    {
        while (seguidor != NULL && seguidor->dato != k) //Controlo que la lista no sea nula aun y si el dato que busco no sea el que analizo
        {
            anterior = seguidor; //El anterior apunta al nodo que se estaba analizando
            seguidor = seguidor->siguiente; //La lista avanza
        }
        if(seguidor!=NULL)
        {
            fflush(stdin);
            anterior->siguiente = seguidor->siguiente;
            free(seguidor);
            //L = anterior;
        }
    }else
    {
        printf("\nNo se puede eliminar el elemento %d, pues este no se encuentra en la lista.", k);
    }

    /*
    while (!EsListaVacia(L))
    {
        if (L->dato == k)
        {
            struct nodo* auxialiar;
            auxialiar->siguiente = L->siguiente;
            L->siguiente = (L->siguiente)->siguiente;
            free(auxialiar);
        }        
    }*/
    return L;
}


//Como usuario de la lista enlazada implemente una función booleana estaContenida que, dadas dos listas enlazadas de números enteros, retorne verdadero si los elementos de la primera lista se encuentran presentes en la segunda, caso contrario retorna falso.

int EstaContenida(Lista L1, Lista L2){
    int CantItemL1, coincidencias;
    
    CantItemL1 = Longuitud(L1);
    while (!EsListaVacia(L2))
    {
        if (PrimerElemento(L1) == PrimerElemento(L2))
        {
            coincidencias++;
        }
        BorrarPrimerElemento(L1);
        BorrarPrimerElemento(L2);
    }
    if (coincidencias == CantItemL1)
    {
        return 1;
    } else {
        return 0;
    }
    
}


int main(void){
    int accion, CantItemLista, decicion;
    item x, primerElemento, k, elementoElimina;
    int finalizar = 1;
    Lista L;
    L = CrearLista();
    do
    {       
        printf("Seleccione mediante el numero, la operacion que desea realizar: \n");
        printf("1 --- Crear Lista\n");
        printf("2 --- Cargar elementos a la Lista\n");
        printf("3 --- Determinar si la lista esta vacia\n");
        printf("4 --- Mostrar la lista\n");
        printf("5 --- Mostrar solo el primer elemento de a lista\n");
        printf("6 --- Borrar el primer elemento de la lista\n");
        printf("7 --- Determinar cuantos elemetos estan en la lista\n");
        printf("8 --- Determinar si un item pertenece o no a la lista\n");
        printf("9 --- Borrar de la lista todas las coincidencias de un item dado\n");
        printf("10 --- Probar la funcion EstaContenida\n");
        printf("11 --- Salir del Programa\n");

        
        scanf("%d",&accion);
         

        switch(accion)
        {
            case 1:                
                printf("La Lista se pudo Crear Exitosamente \n");
                break;
            
            case 2:
                decicion=1;
                //item x;                
                do
                {
                    printf("Por favor, ingrese el item que desea cargar en la lista\n");
                    scanf("%d",&x);
                    L = Insertar(L, x);
                    printf("El elemento se inserto exitosamente. \n Desea ingresar otros elementos? \n 1 --- Si\n2 --- No\n");
                    scanf("%d", &decicion);
                } while (decicion == 1);        
                break;

            case 3:
                if (EsListaVacia(L))
                {
                    printf("La lsiat esta vacia\n");
                } else {
                    printf("La Lista no se encuentra vacia\n");
                }        
                break;

            case 4:
                Mostrar(L);
                break;
            case 5:
                //item x;
                primerElemento = PrimerElemento(L);
                break;
            case 6:
                L = BorrarPrimerElemento(L);
                printf("Primer elemento borrado con exito\n");
                break;

            case 7:
                //int CantItemLista;
                CantItemLista = Longuitud(L);
                printf("La lista, actualmente, tiene una longitud de %d items\n", CantItemLista);
                break;
            
            case 8:
                printf("Ingrese el Item que desea evaluar si esta en la lista...\n");
                //item k;
                scanf("%d",&k);
                
                if (Pertenece(L, k) != 0)
                {
                    printf("El item cargado si se encuentra en la lista, se lo encontro un total de %d veces.\n", Pertenece(L,k));
                } else {
                    printf("El item cargado no pertenece a la lista \n");
                }
                
                break;
            
            case 9:
                printf("Ingrese el item que desea eliminar totalmente de la lista: \n");
                //item x;
                scanf("%d",&elementoElimina);
                L = BorrarK(L,elementoElimina);
                printf("Operacion realizada con exito\n");
                break;

            case 11: 
                finalizar=0;
                break;
        }
    } while (finalizar != 0);
    return 0;
}


