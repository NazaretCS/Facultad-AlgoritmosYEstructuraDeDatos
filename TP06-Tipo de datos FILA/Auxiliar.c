/** 

1) Agregue a la especificación algebraica del tipo FILA(ITEM) las siguientes operaciones:

    FINAL: operación selectora que dada una Fila obtiene el valor del último item enfilado
        Especificacion Algebraica:
            Sintaxis:
                Final: Fila → Item U {Indefinido}

            Semantica: ∀ q ∈ Fila, ∀ i ∈ item
                Final(FilaVacia) ≡ Indefinido
                Final(Enfila(q,i)) ≡ i
            
    ENFILAN: operación que, dada una Fila, un ítem y una cantidad, agrega a la fila el ítem tantas veces como indica la cantidad.
        Especificacion Algebraica:
            Sintaxis:   
                Enfilan: Fila x Item x Entero>= 0 → Fila
            
            Semantica: ∀ q ∈ Fila, ∀ i ∈ item, ∀ n ∈ Naturales ≥ 0

                Entero igual a cero -- Entero mayor que cero -- fila vacia -- fila no vacia

                Enfilan(q, i, n) ≡  Si n = 0 Entonces
                                         q
                                    Sino 
                                        Enfilan(Enfila(q,i), i , n-1)



                                 
                
2) Dada la siguiente operación Misterio del ADT FILA(ITEM), indique qué tarea realiza la misma y dé un nombre más adecuado a la función.
    Sintaxis:
        Misterio: Fila → Fila

    Semántica: ∀ F ∈ Fila, ∀ x ∈ item
        Misterio( Filavacia ) ≡ Filavacia
        Misterio( Enfila(F, x) ) ≡  SI Pertenece(F, x) ENTONCES
                                        Misterio( F )
                                    SINO
                                        Enfila( Misterio( F ) ,x )
        


        La funcion Misterio lo q hace es eliminar los items repetidos
        Nombre mas adecuado: Eliminadora de repetidos
        

                                  

3. Como usuario del ADT Fila diseñe una función recursiva MEZCLAR que, dadas dos Filas de números enteros ordenadas retorne una fila ordenada que resulta de la combinación de ambas filas.

        FUNCION OrdenarFilas(F1, F2, F3): Fila x Fila x Fila → Fila 
            F3 <- FilaVacia()
            SI EsFilaVacia(F1) y EsFilaVacia(F2) ENTONCES
                Retorna F3
            

            Talvez en otro momento



                                    &&&&&&&&&&&&&&&&&&&&&&&&&&&&
                                    %%                        %%
                                    %%          ###           %%
                                    %%       ##     ##        %%
                                    %%       ##     ##        %%
                                    %%            #           %%
                                    %%           #            %%
                                    %%                        %%
                                    %%           #            %%
                                    %%                        %%
                                    %%%%%%%%%%%%%%%%%%%%%%%%%%%%
             




Fila EnFilaN(Fila F, item x, int cant){
    /*
    Especificacion Algebraica:
            Sintaxis:   
                Enfilan: Fila x Item x Entero>= 0 → Fila
            
            Semantica: ∀ q ∈ Fila, ∀ i ∈ item, ∀ n ∈ Naturales ≥ 0

                Entero igual a cero -- Entero mayor que cero -- fila vacia -- fila no vacia

                Enfilan(q, i, n) ≡  Si n = 0 Entonces
                                         q
                                    Sino 
                                        Enfilan(Enfila(q,i), i , n-1)
   

   if (cant == 0)
   {
        return F;
   } else {
        cant--;
        F = EnFila(F, x);
        F = EnFilaN(F, x, cant);
   }
   return F;
}
*/