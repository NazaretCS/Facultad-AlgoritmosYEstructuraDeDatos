#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#include "FuncionesLC.c"

int main(void){
    item x;
    int longitud;
    LC ListaCircular, ListC2;
    ListaCircular = LCVacia(ListaCircular);
    ListC2 = LCVacia(ListC2);

    if (EsLCVacia(ListaCircular))
    {
        printf("La Lista Se encuentra Vacia\n");
    } else {
        printf("La Lista No se encuentra Vacia\n");
    }
    
    ListaCircular = LCInsertar(ListaCircular, 6);
    ListaCircular = LCInsertar(ListaCircular, 7);
    ListaCircular = LCInsertar(ListaCircular, 8);
    ListaCircular = LCInsertar(ListaCircular, 7);

    ListC2 = LCInsertar(ListC2, 1);
    ListC2 = LCInsertar(ListC2, 2);
    ListC2 = LCInsertar(ListC2, 3);    
    ListC2 = LCInsertar(ListC2, 4);    
    ListC2 = LCInsertar(ListC2, 5);

    //ListaCircular = LCBorrar(ListaCircular);
    MostraLC(ListC2);

    ListaCircular= LCUnir(ListaCircular, ListC2);

    MostraLC(ListaCircular);
    x = LCValor(ListaCircular);
    printf("El Valor de la ventana de lista circular es:  %d \n", x);

    if (LCPertenece(ListaCircular, 7))
    {
        printf("El item si pertenece\n");
    } else {
        printf("El item no pertence a la lista\n");
    }
    

    x = LCValor(ListaCircular);
    printf("El Valor de la ventana de lista circular es:  %d \n", x);

    ListaCircular = LCBorrarK(ListaCircular, 7);
    
    x = LCValor(ListaCircular);
    printf("El Valor de la ventana de lista circular es:  %d \n", x);

    longitud = LCLongitud(ListaCircular);
    printf("La Longuitud de la lista circular es:  %d \n", longitud);
    return 0;
}


