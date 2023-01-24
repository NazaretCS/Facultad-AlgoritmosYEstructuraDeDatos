#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#include "FuncionesArbolBinario.c"


int main(void){

    itemAB c;
    AB ArbolBinario, I, D, i, d, ArbolB;
    I = ABVacio();
    D = ABVacio();
    i = ABVacio();
    d = ABVacio();
    ArbolBinario = ABVacio();
    ArbolB = ABVacio();

    if (EsABVacio(ArbolBinario))
    {
        printf("El arbol esta vacio\n");
    } else {
        printf("El arbol no se encuentra vacio\n");
    }
    
    I = ArmarAB(I, 'i', D);
    D = ArmarAB(I, 'd', D);
    ArbolBinario = ArmarAB(I, 'a', D);
    

    if (EsABVacio(ArbolBinario))
    {
        printf("El arbol esta vacio\n");
    } else {
        printf("El arbol no se encuentra vacio\n");
    }

    c = Raiz(ArbolBinario);
    printf("La raiz del arbol es: %c\n",c);

    printf("Arbol Impreso en Posfija\n");
    imprimirPos(ArbolBinario);
    
    printf("Arbol Impreso en Prefija\n");
    imprimirPre(ArbolBinario);

    printf("Arbol Impreso en Orden Simetrico\n");
    imprimirSimertrico(ArbolBinario);

    ArbolB = ArmarAB(i, 'r',d);



    if (EsABHoja(ArbolB))
    {
        printf("Elarbol es Arbol Hoja\n");
    } else {
        printf("El arbol no es Arbol Hoja\n");
    }
    


    if (PerteneceAB(ArbolBinario, 'd'))
    {
        printf("El item si pertence al Arbol\n");
    } else {
        printf("El item ingreado no pertenece al arbol\n");
    }
    
    return 0;
}