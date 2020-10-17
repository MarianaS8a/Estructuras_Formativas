#Análisis asintótico

**push** O(logn)
La función va añadiendo nuevos nodos, primero en la raíz y luego en los subárboles de izquierda a derecha. Sin embargo, la función debe de insertar nuevos nodos forzosamente en lugares en los que su nodo padre es menor a su propio valor. Como se realiza una comparación de valores solo en ciertas secciones del arbol porque éste ya está un poco ordenado, la complejidad es de O(logn)

**pop** O(logn)
Pop elimina el valor de la raíz, para después sustituirlo con el último número añadido. Finalmente, se asegura de que la raíz sí sea más chica que los demás números, por lo que nuevamente se hace un chequeo de O(logn), ya que el arbol está semiordenado y no se necesita considerar a todos los nodos.

**top** O(1)
Esta función accede al valor que se encuentra en el primer espacio del arreglo, por lo que no hay ciclos y el algoritmo tiene una complejidad constante en el peor de los casos.

**empty** O(1)
El algoritmo verifica que el valor de la variable count sea 0 para después regresar true o false. Como no se necesita realizar ninguna iteración, la complejidad de la función también es constante.

**size** O(1)
El algoritmo regresa el valor de una variable que guarda la cantidad de nodos en el árbol. Por lo tanto, tampoco realiza iteraciones y la complejidad de la función es O(1).
