#ifndef GRAPH_H_
#define GRAPH_H_

#include <string>
#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>
#include <stack>
#include <queue>
#include <list>

using namespace std;

class Graph {
  private:
    int nodes;
    int connections;
    vector <int> *adjList;
    int *adjMatrix;
    string fileName;
    void readFile();
    int edjesList;
    int edjesMat;
    void addEdjeAdjList(int u, int v);
    void addEdjeAdjMat(int u, int v);
    void sortAdjList();
    void ordenaSeleccion(vector<int> &v);
    void swapArray(vector<int> &v, int i, int j);

    bool isTreeHelper(int current, bool visited[], int parent[], stack <int> &stack);
    void topologicalSortHelper(int current, bool visited[], int parent[], stack <int> &stack, vector <int> &sorted);
    bool bipartiteHelper(int visited[], int current, int color, stack <int> &stack);

  public:
    void loadGraphMat(string f, int n, int c);
    void loadGraphList(string f, int n, int c);
    bool isTree();
    string topologicalSort();
    bool bipartiteGraph();
};

void Graph::loadGraphMat(string f, int n, int c){
  fileName = f;
  nodes = n;
  connections = c;
  edjesMat = 0;
  adjMatrix = new int [nodes*connections];

  for (int i = 0; i < nodes*connections; i++){
    adjMatrix[i] = 0;
  }

  readFile();
}

void Graph::loadGraphList(string f, int n, int c){
  fileName = f;
  nodes = n;
  connections = c;
  adjList = new vector <int> [nodes];
  edjesList = 0;
}

void Graph::addEdjeAdjMat(int u, int v){
  adjMatrix[u*nodes+v] = 1;
  adjMatrix[v*nodes+u] = 1;
  edjesMat ++;
}

void Graph::addEdjeAdjList(int u, int v){
  adjList[u].push_back(v);
  adjList[v].push_back(u);
  edjesList ++;
}

void Graph::readFile(){
  string first;
  string second;
  int u;
  int v;
  int iline;
  string line;
  ifstream file(fileName);
  if (file.is_open()) {
      int i = 0;
      while (getline(file, line)) {
          first = line.substr(1);
          second = line.substr(4);
          u = stoi(first);
          v = stoi(second);
          addEdjeAdjMat(u, v);
          addEdjeAdjList(u, v);
          i++;
      }
      file.close();
  }
  sortAdjList();
}

void Graph::sortAdjList(){
  for(int i = 0; i<nodes; i++)
    ordenaSeleccion(adjList[i]);
}

void Graph::ordenaSeleccion(vector<int> &v) {
  for (int i=0; i<v.size()-1; i++){
    int min = i;
    for (int j=i+1; j<v.size(); j++){
      if (v[j]<v[min])
        min = j;
    }
    swapArray(v, i, min);
  }
}

void Graph::swapArray(vector<int> &v, int i, int j) {
	int temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}


bool Graph::isTree(){
  int current = 0;
  bool *visited = new bool[nodes];
  int *parent = new int[nodes];
  stack <int> stack;
  stack.push(current);

  for (int i = 0; i < nodes; i++){
    visited[i] = false;
  }

  for (int i = 0; i < nodes; i++){
    parent[i] = 0;
  }

  return isTreeHelper(current, visited, parent, stack);

}

bool Graph::isTreeHelper(int current, bool visited[], int parent[], stack <int> &stack){

  parent[stack.top()] = current;
  current = stack.top();
  stack.pop();
  visited[current] = true;
  for (int i = 0; i < adjList[current].size(); i++){
      if(!visited[adjList[current][i]]){
          stack.push(adjList[current][i]);
          if (!isTreeHelper(current, visited, parent, stack))
            return false;
      }
      else if (visited[i] != parent[i] && parent[i] != 0 ){
        return false;
      }

  }
  return true;
}

string Graph::topologicalSort(){
  int current = 0;
  bool *visited = new bool[nodes];
  int *parent = new int[nodes];
  stack <int> stack;
  stack.push(current);
  vector <int> sorted;
  string order;

  for (int i = 0; i < nodes; i++){
    visited[i] = false;
  }

  for (int i = 0; i < nodes; i++){
    parent[i] = 0;
  }

  topologicalSortHelper(current, visited, parent, stack, sorted);

  for (int i = nodes-1; i>=0; i--) {
    order = order + to_string(sorted[i]);
    if (i > 0)
      order = order + " ";
  }

  return order;

}

void Graph::topologicalSortHelper(int current, bool visited[], int parent[], stack <int> &stack, vector <int> &sorted){
    if (stack.size() == nodes)
      return;
    parent[stack.top()] = current;
    current = stack.top();
    stack.pop();
    visited[current] = true;
    for (int i = 0; i < adjList[current].size(); i++){
        if(!visited[adjList[current][i]]){
            stack.push(adjList[current][i]);
            topologicalSortHelper(current, visited, parent, stack, sorted);

        }
    }
    sorted.push_back(current);
}

bool Graph::bipartiteGraph(){
  int *visited = new int [nodes];
  stack <int> stack;
  stack.push(0);

  for (int i = 0; i < nodes; i++){
    visited[i] = -1;
  }

  return bipartiteHelper(visited, 0, 1, stack);
}

bool Graph::bipartiteHelper(int visited[], int current, int color, stack <int> &stack){


  if(visited[current] != -1 && visited[current] != color){
    return false;
  }
  color = 1-color;
  current = stack.top();
  stack.pop();
  visited[current] = color;
  bool ans = true;

  for (int i = 0; i < adjList[current].size(); i++){
      if(visited[adjList[current][i]] == -1){
          stack.push(adjList[current][i]);
          if (!bipartiteHelper(visited, current, color, stack)){
            ans = false;
          }
      }
      else if(visited[adjList[current][i]] != -1 && visited[adjList[current][i]] != 1-color)
        return false;

      if (!ans)
        return false;
  }

  return true;

}


#endif
