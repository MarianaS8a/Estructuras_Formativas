#sumaIterativa

**Análisis de complejidad temporal**

El algoritmo contiene un ciclo for que va de 1 a n y que incrementa de 1 en 1. En el peor de los casos, el ciclo se ejecuta las veces que el número de datos establezca (n).  Por lo tanto, esta suma iterativa tiene un orden de O(n) u orden lineal.

#sumaRecursiva

**Análisis de complejidad temporal**

El algoritmo se manda a llamar así mismo n veces, por lo que su complejidad es O(n) para el peor de los casos. Por ejemplo si n vale 3, entonces se realizaría 3 + llamada recursiva, luego 2 + llamada recursiva, 1 + llamada recursiva y finalmente encuentra el caso base.

#sumaDirecta

**Análisis de complejidad temporal**

Este algoritmo tiene un orden O(1) porque el tiempo de ejecución no varía al cambiar el tamaño del número introducido en la fórmula.
