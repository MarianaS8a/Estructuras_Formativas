**Análisis asintótico**

#add O(n)
La función utiliza recursividad para avanzar a lo largo del árbol hasta encontrar el lugar que le corresponde al valor que se quiere insertar. Como no hay un algorítmo de ordenación (en este caso se usa splay) dentro de la función, el árbol puede estar desbalanceado. Por lo tanto, la función add puede realizar hasta n iteraciones y la complejidad en el peor de los casos de O(n).

#remove O(n)
El algoritmo también utiliza recursividad para avanzar a lo largo del árbol y eliminar un valor específico. Como no se manda a llamar a la función splay en la clase Nodo, entonces el árbol puede estar desbalanceado y remove se puede tardar hasta n veces en encontrar al valor que desea borrar. Por lo tanto, la complejidad de este algoritmo es O(n) en el peor de los casos.

#find O(n)
Nuevamente la función splay que se encarga de modificar el orden del árbol no se manda a llamar en la clase nodo. Por lo tanto, el arbol puede estar desbalanceado y el algoritmo tiene una complejidad de O(n) en el peor de los casos.

#inorder O(n)
La complejidad de esta función es O(n) porque recorre todo el árbol de manera recursiva para ordenar los datos de la siguiente manera. Inicia en el nodo más a la izquierda, encuentra la raíz del subarbol o árbol, encuentra el nodo derecho y se repite hasta recorrer todo el árbol.

#size O(1)
La complejidad de este algoritmo es constante en el peor de los casos porque sólo accede a una variable y regresa su valor.
