#Análisis de complejidad

**inorder, preorder, y postorder**
La complejidad de cada una de estas funciones es O(n) porque recorren todo el árbol de manera recursiva para ordenar los datos de la siguiente manera.
Inorder: inicia en el nodo más a la izquierda, encuentra la raíz del subarbol o árbol, encuentra el nodo derecho y se repite hasta recorrer todo el árbol.
Preorder: inicia en la raíz, encuentra el nodo izquierdo de la raíz o subraíz, encuentra el nodo derecho de la raíz o subraíz y se repite el proceso recursivamente.
Postorder: inicia en el nodo más izquierdo, encuentra el nodo derecho del padre del nodo pasado, encuentra el padre de ambos nodos y se repite el proceso recursivamente.

**visit**
La complejidad de esta función por sí sola es O(1) porque solo regresa los valores que inorder, preorder y postorder ya regresaron.

**height**
El algoritmo recorre cada uno de los niveles del árbol de manera recursiva para contarlos. Como el árbol puede tener hasta n niveles, entonces la complejidad de la función es O(n), tomando en cuenta que n es cada nodo o elemento del árbol.

**ancestors**
La función recorre el árbol contando los niveles que necesita para llegar al nodo seleccionado y la altura puede ser n en el peor de los casos. Consecuentemente, el algoritmo tiene una complejidad de O(n).

**whatlevelamI**
El algoritmo recorre el arbol hasta encontrar el valor deseado y recorrer todo el árbol puede tomar hasta n iteraciones recursivas, por lo tanto la complejidad de la función también es O(n).
