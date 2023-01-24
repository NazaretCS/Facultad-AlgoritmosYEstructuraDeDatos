/**
    ARBOL (ITEM)

    Especificación algebraica - OPERACIONES:
        SINTAXIS:

            ARBOLVACIO : → ARBOL
            ESARBOLVACIO :  ARBOL → BOOLEAN
            CONSTRUIR : ITEM X ARBOL x ARBOL → ARBOL
            PRIMERHIJO : ARBOL → ARBOL
            PROXHERMANO : ARBOL → ARBOL
            RAIZ : ARBOL → ITEM U {indefinido}

        SEMANTICA: ∀ a,b ∈ ARBOL , ∀ i ∈ ITEM

            ESARBOLVACIO(ARBOLVACIO) → TRUE
            ESARBOLVACIO(CONSTRUIR(i,a,b)) → FALSE

            PRIMERHIJO(ARBOLVACIO) → ARBOLVACIO
            PRIMERHIJO(CONSTRUIR(i,a,b)) → a

            PROXHERMANO(ARBOLVACIO) → ARBOLVACIO
            PROXHERMANO(CONSTRUIR(i,a,b)) → b
            
            RAIZ(ARBOLVACIO) → indefinido
            RAIZ(CONSTRUIR(i,a,b)) → i 
*/
