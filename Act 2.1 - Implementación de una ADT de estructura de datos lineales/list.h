#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <string>
#include <sstream>
#include "exception.h"

using namespace std;

template <class T> class List;

template <class T>
class Link {
private:
	Link(T);
	Link(T, Link<T>*);
	Link(const Link<T>&);

	T	    value;
	Link<T> *next;

	friend class List<T>;
};

template <class T>
Link<T>::Link(T val):value(val), next(0){}

template <class T>
Link<T>::Link(T val, Link* nxt):value(val), next(nxt) {}

template <class T>
Link<T>::Link(const Link<T> &source):value(source.value), next(source.next) {}

template <class T>
class List{
public:
  List();
  ~List();
  string toString()const;
	void clear();
	bool empty()const;
	void addFirst(T val) throw(OutOfMemory);
  void add(T val) throw(OutOfMemory);
	int find(T val);
	void update(T index, T val);
	void removeFirst();
	void remove(T index);
private:
  Link<T> *head;
  int size;
};

template <class T>
List<T>::List():head(0),size(0){}

template <class T>
List<T>::~List(){
  clear();
}

template <class T>
string List<T>::toString() const {
	stringstream aux;
	Link<T> *p;
	p = head;
	aux << "[";
	while (p != 0) {
		aux << p->value;
		if (p->next != 0) {
			aux << ", ";
		}
		p = p->next;
	}
	aux << "]";
	return aux.str();
}

template <class T>
bool List<T>::empty() const {
	return (head == 0);
}

template <class T>
void List<T>::clear() {
	Link<T> *p, *q;

	p = head;
	while (p != 0) {
		q = p->next;
		delete p;
		p = q;
	}
	head = 0;
	size = 0;
}

template <class T>
void List<T>::addFirst(T val) throw(OutOfMemory){
	Link<T> *newLink;

	newLink = new Link<T>(val);
	if (newLink == 0)
		throw OutOfMemory();
	newLink->next = head;
	head = newLink;
	size++;
}

template <class T>
void List<T>::add(T val) throw(OutOfMemory){
  Link<T> *newLink, *p;

  newLink = new Link<T>(val);
  if (newLink == 0) {
    throw OutOfMemory();
  }

  if (empty()) {
		addFirst(val);
		return;
	}

  p = head;
	while (p->next != 0) {
		p = p->next;
	}

	newLink->next = 0;
	p->next = newLink;
	size++;
}

template <class T>
int List<T>::find(T val){
	Link<T> *p;
	p = head;

	for (int i = 0; i<size; i++){
		if (p->value == val)
			return i;
		p = p->next;
	}
	return -1;
}

template <class T>
void List<T>::update(T index, T val){
	Link<T> *p;
	p = head;

	for (int i = 0; i<index; i++){
		p = p->next;
	}
	p->value = val;
}

template <class T>
void List<T>::removeFirst(){
	Link<T> *p;
	p = head;
	head = p->next;

	delete p;
	size --;
}

template <class T>
void List<T>::remove(T index){
	if (index ==0)
		removeFirst();

	else{
	Link<T> *p, *q, *r;
	p = head;
	for(int i =0; i==index; i++){
		p = p->next;
	}
	q = p;
	p = p->next;
	r = p->next;
	q->next = r;

	delete p;
	size --;
	}
}

#endif
