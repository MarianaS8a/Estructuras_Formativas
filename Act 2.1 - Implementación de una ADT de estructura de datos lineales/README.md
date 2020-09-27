**Análisis de complejidad**

#add(); O(n)
El algoritmo recorre la lista con un ciclo while para encontrar el último valor y añadir un índice más. Por lo tanto, se realizan n iteraciones y la complejidad es de O(n).

#find(); O(n)
El algoritmo se implementó con un ciclo for que recorre la lista hasta encontrar el valor buscado. Por lo que en el peor de los casos se realizarán n iteraciones para encontrar un valor y la complejidad es de O(n).

#update(); O(n)
El algoritmo también utiliza un ciclo for para llegar al indice que se introduce y sustituir el valor del mismo. Consecuentemente, se harán n iteraciones en el peor de los casos y la complejidad es O(n).

#remove(); O(n)
El algoritmo igualmente fue implementado con un ciclo for que puede recorrer toda la lista hasta que encuentre el indice que se quiere eliminar. La complejidad también es O(n).
