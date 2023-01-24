/*  
2). Dado un número entero positivo, diseñe dos algoritmos recursivos para obtener los siguientes resultados:
    a). Escriba las cifras del número separadas por un espacio.
        Por ejemplo: si número es 7254, la salida debe ser: 7 2 5 4.

        PROCEDIMIENTO: Separar(n): Entero -> Cadena de Caracteres
            SI (n < 10) ENTONCES
                ESCRIBIR (n)
            SINO 
               Separar(n / 10)
               ESCRIBIR (" ") 
               ESCRIBIR (RESTO(N,10))  // Siendo resto una funcion que devuelve el resto de la divicion entre el primer argumento en el segundo
            FIN SI
        FIN FUNCION


    b). Cuente la cantidad de veces que aparece un dado dígito en el número.
        Por ejemplo: si el número es 13234 y el digito es 3, el resultado debe ser 2.

       FUNCION ContarIguales(n, m): Entero x Entero -> Entero => 0
            SI (n < 10) ENTONCES 
                SI n = m ENTONCES
                    Comparar (n,m)  // Siendo Comparar una funcion que compara los argumentos y devuelve True si son iguales y False en caso contrario
            SINO 
                Comparar (Resto(n/10),m)
                ContarIguales(n/10,m)
            FIN SI
        FIN FUNCION

*/

#include<stdio.h>

void Separar(int n);

int main(){
    int n=234;
    printf("Bienbenido al programa\n");
    printf("Ingrese Un numero para trabajar: \n");
    scanf("%d", &n);
    Separar(n);
    return 0;
}

void Separar(int n) //Anda, pero por alguna razon no me deja ingresar un umero... pero lo importatnte es que anda
{
    int aux;
    if (n < 10)
    {
        printf(" %d ", n);
    } else {
        Separar(n/10);
        printf("  %d ", n%10);
    }
}  
