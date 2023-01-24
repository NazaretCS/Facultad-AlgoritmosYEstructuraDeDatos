/**
 
    Aplicación: unir 2 listas circulares
    Ejercitacion:
        3) Como usuario del ADT LC, función recursiva
        4) Como usuario del ADT LC, función iterativa
    
        hacer luego.

        al incertar nodos, la LC se mueve en sentido horario
        la rotacion tamien se hace en sentido antihorario.
        caundo se boora se mueve en sentido antihorario

    

    Trabajo Práctico no. 7 :  Tema: Tipo de datos LISTA CIRCULAR

    1. Agregue a la especificación algebraica del tipo LC(ITEM) las siguientes operaciones:

         LCPertenece: operación test que dada una LC y un ítem determina si el ítem se encuentra en la lista circular.

            SINTAXIS:   
                    LCPertenece : ListaCircular x Item → Bolean
            
            SEMANTICA: ∀ LC ∈ ListaCircular, ∀ i, j ∈ item
                    LCPertenece ( LCVacia, i ) ≡ False
                    LCPertenece ( LCInsertar( LC, i ), j ) ≡ SI ( i = j ) ENTONCES 
                                                                    RETORNA True
                                                                SINO 
                                                                    LCPertenece ( LC, j ) 
        

         LCBorrark: operación que, dada una LC y un ítem, borra de la lista todas las ocurrencias de dicho ítem.

            SINTAXIS:
                    LCBorrark: ListaCircular x Item → ListaCircular
            
            SEMANTICA: ∀ LC ∈ ListaCircular, ∀ i, k ∈ item
                    LCBorrark ( LCVacia, k ) ≡ LCVacia
                    LCBorrark ( LCInsertar( LC, i ), k ) ≡ SI ( i = k ) ENTONCES
                                                                LCBorrark ( LC, k )
                                                            SINO 
                                                               LCInsertar (LCBorrark(  LC , k ), i)

                                   


         LCLongitud: operación que devuelve la cantidad de ítems que contiene la lista circular.
            SINTAXIS:
                    LCLongitud: ListaCircular → Entero >= 0

            SEMANTICA: ∀ LC ∈ ListaCircular, ∀ i ∈ item
                       LCLongitud ( LCVacia ) ≡ 0
                       LCLongitud ( LCInsertar( LC, i ) ) ≡ 1 + Longitud( LC )


    2. Como usuario del ADT LC(ITEM) diseñe una función recursiva LCContarK que, dada una LC y un ítem, cuente todas las veces que aparece dicho item en la LC. Su función no debe eliminar la LC.

            Operaciones Disponibles:
                → LCVacia
                → LCInsertar
                → LCBorrar: Borra el valor que se encuentra en la ventana de la lista
                → LCValor: Devuelve el valor de la ventana 
                → EsLCVacia: Test
                → LCRotar: Rota la LC
                → LCUnir: Une dos listas
                → LCPertenece: Test
                → LCBorrark: Borra de la lista todas las ocurrencias de K.
                → LCLonguitud

        FUNCION LCContarK: ListaCircular x Item → Entero >= 0
            SI EsLCVacia( LC ) Entonces
                Retorna 0
            SINO 
                Valor <- LCValor( LC )
                L


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

*/  

