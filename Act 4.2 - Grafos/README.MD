**Análisis asintótico**

#isTree O(V+E)
El algoritmo recorre todo el grafo si es un arbol, regresando true si es árbol y false si no lo es. La complejidad es O(V+E) porque en el peor de los casos recorre todos los edjes y vertices.

#topologicalSort O(V+E)
La función encuentra el nodo más profundo, luego uno menos profundo, hasta regresar al nodo inicial. Regresa todos los nodos con orden de menor a mayor profundidad. La complejidad también es O(V+E) porque en el peor de los casos recorre todos los edjes y vertices.

#bipartiteGraph O(V+E)
Asigna dos colores diferentes a cada nodo, alternando 0 y 1. Si en algún punto, se encuentran dos nodos vecinos con un mismo color, el grafo no es bipartito. La complejidad igualmente es O(V+E) porque en el peor de los casos recorre todos los edjes y vertices.
