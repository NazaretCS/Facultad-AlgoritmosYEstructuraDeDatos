/* FUNCION: Acumulando(Arreglo): -> Real
      i <- 0
      MIENTRAS (Arreglo =! MF)
         Elemento <- Arreglo[i]
         Resto <- Resto(Elemento,2)
         Si (Resto = 0)
            Acumulado <- OperacionParaPares(Acumulado, Elemento)
         SINO
            Acumulado <- OperacionParaImpares(Acumulado, Elemento)
         FIN SI
         i <- i + 1
      FIN MIENTRAS
      RETORNAR Acumulado
    FIN FUNCION

    FUNCION: OperacionParaPares(Acumulado,Elemento):->Real
        Acumulado <- Acumulado + Elemento
        RETORNAR Acumulado
    FIN FUNCION

    FUNCION: OperacionParaImpares(Acumulado,Elemento):->Real
        Acumulado <- Acumulado - Elemento
        RETORNAR Acumulado
    FIN FUNCION


      ALGORTIMO: Acumular(Arreglo): -> Real
      A0. LEER(Arreglo)
      A1. Acumulado <- Acumulando(Arreglo)
      A2. ESCRIBIR(Acumulado)
      A3. PARAR
*/

int main(void)
{
    int x[6]={3,4,5,6,7,8};

    return 0;
}