**Análisis de complejidad temporal**

#ordenaSeleccion O(n^2)
El algoritmo de ordenamiento contiene un ciclo for anidado en otro ciclo. Consecuentemente, se realizan n iteraciones n veces y la complejidad es de O(n^2).

#ordenaBurbuja  O(n^2)
El algorítmo también contiene un ciclo for anidado en otro ciclo, por lo que se realizan n iteraciones n veces y la complejidad es O(n^2). Es un poco más rápido que ordenaSeleccion, sobre todo cuando los datos están casi ordenados.

#ordenaMerge O(nlogn)
Este algoritmo de ordenamiento es más rápido que los dos anteriores porque tiene complejidad O(nlogn). La separación de todos los elementos es de O(n) porque se realiza una separación por elemento, mientras que el merge o unión de los números de manera ordenada es de O(logn) porque se realizan menos cantidad de pasos que el número de elementos. La desventaja es que es un algoritmo más difícil de implementar.

#busqSecuencial O(n)
El algoritmo de búsqueda recorre el vector n veces en el peor de los casos. Por lo tanto, tiene una complejidad de O(n).

#busqBinaria O(logn)
Como el algoritmo reduce el área de búsqueda a medida que se ejecuta, su complejidad es de O(logn). No se tiene que recorrer todo el vector para encontrar un elemento.
