#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


typedef int item;
const int indefinido=-9999;

struct nodo
{
    item dato;
    struct nodo *siguiente;
}typedef Nodo;

struct LC
{
    struct nodo * cabecera;
    int Longuitud;
}typedef LC;


LC LCVacia(LC ListC){
    ListC.cabecera = NULL;
    ListC.Longuitud = 0;
    return ListC;
}


int EsLCVacia(LC ListC){
    if (ListC.cabecera == NULL)
    {
       return 1;
    } else {
        return 0;
    }
}


LC LCInsertar(LC ListC, item x){
    struct nodo* NodoAux;
    NodoAux = (Nodo *) malloc (sizeof(Nodo));
    NodoAux->dato = x;
    if(EsLCVacia(ListC)){
        ListC.cabecera = NodoAux;  //La cabecera apuntara al nodo incertado
        NodoAux->siguiente = NodoAux; //El nodo se apunta a si mismo
        ListC.Longuitud++;  // incremento la longuitud
    } else {
        NodoAux->siguiente= ListC.cabecera->siguiente; // Apunto el siguiente del nuevo nodo hacia el siguiente de donde apunta la cabecera
        ListC.cabecera->siguiente = NodoAux; // cambio el sig de la cabecera para que apunte al nuevo nodo. (Diapo 8 y 9)
        ListC.Longuitud++;  // incremento la Long.
    }
    return ListC;
}


LC LCBorrar(LC ListC){
    Nodo *NodoAux;
    NodoAux = ListC.cabecera->siguiente;
    if (ListC.Longuitud == 1)
    {
        ListC.cabecera = NULL;
    } else {
        ListC.cabecera->siguiente = ListC.cabecera->siguiente->siguiente;
        ListC.Longuitud--;
        
    }
    free(NodoAux);
    return ListC;
}


LC LCRotar(LC ListC){
    ListC.cabecera = ListC.cabecera->siguiente;
    return ListC;
}

item LCValor(LC ListC){
    if (!EsLCVacia(ListC))
    {
        return ListC.cabecera->siguiente->dato;
    } else {
        printf("La Lista Circular no contiene Ningun elemento\n");
        return indefinido;
    }
}



/*
  LCPertenece: operación test que dada una LC y un ítem determina si el ítem se encuentra en la lista circular.

            SINTAXIS:   
                    LCPertenece : ListaCircular x Item → Bolean
            
            SEMANTICA: ∀ LC ∈ ListaCircular, ∀ i, j ∈ item
                    LCPertenece ( LCVacia, i ) ≡ False
                    LCPertenece ( LCInsertar( LC, i ), j ) ≡ SI ( i = j ) ENTONCES 
                                                                    RETORNA True
                                                                SINO 
                                                                    LCPertenece ( LC, j ) 

*/
int LCPertenece(LC ListC, item x){
    item ItemAux;
    if (EsLCVacia(ListC))
    {
        return 0;
    } else {
        ItemAux = LCValor(ListC);
        ListC = LCRotar(ListC);
        if (ItemAux == x)
        {
            return 1;
        } else {
            return LCPertenece(ListC, x);
        }
    }
}




/*     
     LCBorrark: operación que, dada una LC y un ítem, borra de la lista todas las ocurrencias de dicho ítem.

            SINTAXIS:
                    LCBorrark: ListaCircular x Item → ListaCircular
            
            SEMANTICA: ∀ LC ∈ ListaCircular, ∀ i, k ∈ item
                    LCBorrark ( LCVacia, k ) ≡ LCVacia
                    LCBorrark ( LCInsertar( LC, i ), k ) ≡ SI ( i = k ) ENTONCES
                                                                LCBorrark ( LC, k )
                                                            SINO 
                                                               LCInsertar (LCBorrark(  LC , k ), i)
*/
LC LCBorrarK(LC ListC, item x){
    item ItemAux;
    if (EsLCVacia(ListC))
    {
        return ListC;
    } else {
        ItemAux = LCValor(ListC);
        ListC = LCBorrar(ListC);
        if (ItemAux == x)
        {
            ListC = LCBorrarK(ListC, x);
        } else {
            ListC = LCInsertar(LCBorrarK(ListC,x),ItemAux);
        }
    }    
}  //Como.? no lo se, pero anda... Bendita sea la Espesificacion Algebreaica




/*
         LCLongitud: operación que devuelve la cantidad de ítems que contiene la lista circular.
                        SINTAXIS:
                                LCLongitud: ListaCircular → Entero >= 0

                        SEMANTICA: ∀ LC ∈ ListaCircular, ∀ i ∈ item
                                LCLongitud ( LCVacia ) ≡ 0
                                LCLongitud ( LCInsertar( LC, i ) ) ≡ 1 + Longitud( LC )


int LCLongitud(LC ListC){
    if (EsLCVacia(ListC))
    {
        return 0;
    } else {
        ListC = LCBorrar(ListC);
        return (1 + LCLongitud(ListC));
    }
}
*/

int LCLongitud(LC ListC){
    return ListC.Longuitud;
}


/* 
        Unir dos Listas Circulares::

            Sintaxis:
                LCUnir: LC x LC → LC
            
            Semantica: ∀ L1, L2 ∈ ListaCircular, ∀ i ∈ item
                LCUnir ( L1, LCVacia ) ≡ L1
                LCUnir ( L1, LCInsertar ( L2, i ) ) ≡ LCInsertar( LCUnir( L1, L2), i ) 
*/
 
LC LCUnir(LC ListC1, LC ListC2){ //Exito Rotundo
    item ItemAux;
    if (EsLCVacia(ListC1))
    {
        return ListC2;
    } else {
        if (EsLCVacia(ListC2))
        {
            return ListC1;
        } else {
            ItemAux = LCValor(ListC2);
            ListC2 = LCBorrar(ListC2);
            ListC1 = LCInsertar( LCUnir( ListC1, ListC2), ItemAux);
        }
        return ListC1;
    }
}

void MostraLC(LC ListC){  //Exito Rotundo
    for (int i = 0; i < ListC.Longuitud; i++)
    {
        printf("-> [  %d  | ]  ",ListC.cabecera->dato);
        ListC = LCRotar(ListC);
    }
    printf("->\n ");
}