**Análisis asintótico**

#loadGraphMat
Este algoritmo lee un archivo de texto y llama a la función addEdjeAdjMat para añadir la cantidad de conexiones que hay en el archivo de texto. La complejidad de añadir una relación es de O(1) porque solo se marca como true a dos celdas de la matriz que guarda las relaciones entre nodos. Sin embargo, la función loadGraphMat realiza este proceso E veces (la cantidad de edjes). Por lo tanto, la complejidad es O(E) sin tomar en cuenta que la inicialización de la matriz tiene un ciclo O(V*E) para inicializarse.

#loadGraphList
La función llama al algoritmo addEdjeAdjList para ligar una nueva relación entre dos nodos, la cual es O(1). Esta función también realiza el proceso E veces. Por lo tanto, la complejidad es O(E).

#DFS O(V+E)
Este algoritmo recorre adjList desde cierto número para encontrar otro, pasando por los hijos más chicos de los nodos. La complejidad es O(V+E) porque en el peor de los casos recorre todos los edjes y vertices.

#BFS O(V+E)
Este algoritmo también recorre adjList desde cierto número para encontrar a otro. La diferencia es que el algorítmo recorre todos los hijos del nodo actual y luego ya continua con los hijos de los hijos. La complejidad también es O(V+E) porque el algoritmo puede llegar a recorrer todos los edjes y vertices.
