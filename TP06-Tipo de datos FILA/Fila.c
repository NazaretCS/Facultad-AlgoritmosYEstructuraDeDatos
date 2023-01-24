#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#include "FuncionesPila.c"

int main(void){
    Fila F;
    item x;

    F = FilaVacia();
    if (EsFilaVacia(F))
    {
        printf("La fila esta Vacia\n");
    } else {
        printf("La fila no se encuentra vacia\n");
    }
    
    printf("Funcion Enfilar:\n");

    F = EnFila(F,1);
    F = EnFila(F,2);
    F = EnFila(F,3);
    
    if (EsFilaVacia(F))
    {
        printf("La fila esta Vacia\n");
    } else {
        printf("La fila no se encuentra vacia\n");
    }
    
    x = Frente(F);
    printf("Frente de la fila: %d\n",x);
    
    x = Final(F);
    printf("Final de la fila: %d\n",x);


    F = EnFilaN(F, 5, 2);
    printf("Enfilados exitosos\n");

    x = Final(F);
    printf("Final de la fila: %d\n",x);
    return 0;
}





