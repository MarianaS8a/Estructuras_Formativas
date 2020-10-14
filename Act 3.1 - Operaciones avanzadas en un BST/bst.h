#ifndef BST_H_
#define BST_H_

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

template <class T> class BST;

template <class T>
class Node {
private:
  T value;
  Node *left, *right;
  Node<T>* succesor;
  void inorder(stringstream &aux);
  void preorder(stringstream &aux);
  void postorder(stringstream &aux);
  void print(stringstream &aux, int level);
  void levelByLevel(stringstream &aux);
  bool find(T val);
  bool ancestors(T val, stringstream &aux);
  int whatlevelamI(T val);

public:
  Node(T);
  Node(T, Node<T> *lft, Node<T> *rght);
  void removeChilds();
  void add(T val);
  friend class BST<T>;
  int height();
};

template <class T>
Node<T>::Node(T v): value(v), left(0), right(0) {}

template <class T>
Node<T>::Node(T val, Node<T> *lft, Node<T> *rght):value(val), left(lft), right(rght) {}

template <class T>
void Node<T>::removeChilds() {
  if (right != 0) {
		right->removeChilds();
		delete right;
		right = 0;
	}
  if (left != 0) {
		left->removeChilds();
		delete left;
		left = 0;
	}
}

template <class T>
void Node<T>::add(T val){
  if (val < value){
    if(left == 0)
      left = new Node<T>(val);
    else
      left -> add(val);
  }
  else{
    if(right == 0)
      right = new Node<T>(val);
    else
      right->add(val);
  }
}

template <class T>
bool Node<T>::find(T val) {
	if (val == value) {
		return true;
	} else if (val < value) {
		return (left != 0 && left->find(val));
	} else if (val > value) {
		return (right != 0 && right->find(val));
	}
}

template <class T>
void Node<T>::inorder(stringstream &aux){
	if (left != 0){
		left->inorder(aux);
	}
	if (aux.tellp() != 1){
		aux << " ";
	}
	aux << value;
	if (right != 0){
		right->inorder(aux);
	}
}

template <class T>
void Node<T>::preorder(stringstream &aux){
	aux << value;
	if (left != 0){
		aux << " ";
		left->preorder(aux);
	}
	if (right != 0){
		aux << " ";
		right->preorder(aux);
	}
}

template <class T>
void Node<T>::postorder(stringstream &aux){
	if (left != 0){
		left->postorder(aux);
	}
	if (right != 0){
		right->postorder(aux);
	}
	if (aux.tellp() != 1){
			aux << " ";
	}
	aux << value;
}

template <class T>
void Node<T>::print(stringstream &aux, int level){

	if(level == 0){
		if (aux.tellp() != 1) {
				aux << " ";
		}
		aux << value;
	}
	if (left != 0) {
		left->print(aux, level -1);
	}
	if (right != 0) {
		right->print(aux, level -1);
	}

}

template <class T>
void Node<T>::levelByLevel(stringstream &aux) {
	int level = height();
	for(int i = 0; i < level; i++){
			print(aux, i);
	}
}

template <class T>
int Node<T>::height(){

  int leftSide = 0;
  int rightSide = 0;
  if (left != 0)
    leftSide = left -> height() + 1;
  if (right != 0)
    rightSide = right -> height() + 1;
  if (rightSide == 0 && leftSide == 0)
    return 1;
  if (leftSide>rightSide)
    return leftSide;
  else
    return rightSide;
}

template <class T>
bool Node<T>::ancestors(T val, stringstream &aux){
  if (val < value){
    if (aux.tellp()!= 1)
      aux << " ";
    aux << value;
    return (left != 0 && left -> ancestors(val, aux));
}
  else if (val > value){
    if (aux.tellp()!= 1)
      aux << " ";
    aux << value;
    return (right != 0 && right -> ancestors(val, aux));
  }
  else if(val == value)
    return true;
}

template <class T>
int Node<T>::whatlevelamI(T val) {
	if (val == value){
		return 1;
	}
  else if (val < value){
		if(left != 0)
			return left->whatlevelamI(val) + 1;
	}
  else if (val > value) {
		if (right != 0)
		return right->whatlevelamI(val) + 1;
	}
	return -1;
}

template <class T>
class BST {
private:
  Node<T> *root;

public:
  BST();
  ~BST();
  void removeAll();
  bool empty();
  bool find(T val);
  string inorder();
  void add(T val);
  string preorder();
  string postorder();
  string levelByLevel();
  string visit();
  int height();
  string ancestors(T val);
  int whatlevelamI(T val);
};

template <class T>
BST<T>::BST():root(0){}

template <class T>
BST<T>::~BST(){
  removeAll();
}

template <class T>
void BST<T>::removeAll() {
	if (root != 0) {
		root->removeChilds();
	}
	delete root;
	root = 0;
}

template <class T>
bool BST<T>::empty(){
  if (root == 0)
    return true;
  else
    return false;
}

template <class T>
bool BST<T>::find(T val){
  if (root == 0)
    return false;
  else
    return root->find(val);
}

template <class T>
void BST<T>::add(T val){
  if (root == 0)
    root = new Node<T>(val);
  else{
    if (!root -> find(val))
      root->add(val);
  }
}

template <class T>
string BST<T>::inorder(){
	stringstream aux;
	aux << "[";
	if (!empty()) {
		root->inorder(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T>
string BST<T>::preorder(){
	stringstream aux;
	aux << "[";
	if (!empty()) {
		root->preorder(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T>
string BST<T>::postorder(){
	stringstream aux;
	aux << "[";
	if (!empty()) {
		root->postorder(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T>
string BST<T>::levelByLevel(){
	stringstream aux;
	aux << "[";
	if (!empty()) {
		root->levelByLevel(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T>
string BST<T>::visit(){
	stringstream aux;
	aux << preorder() << "\n";
	aux << inorder() << "\n";
	aux << postorder() << "\n";
	aux << levelByLevel();
	return aux.str();
}

template <class T>
int BST<T>::height(){
  if (root!= 0)
    return (root->height());
  else
    return 0;
}

template <class T>
string BST<T>::ancestors(T val){
  stringstream aux;
  aux << "[";
  if (root ->ancestors(val, aux) == false)
    return "[]";
  aux << "]";
  return aux.str();
}

template <class T>
int BST<T>::whatlevelamI(T val){
	if (root == 0)
	 	return -1;
	else
		return(root->whatlevelamI(val));
}

#endif
