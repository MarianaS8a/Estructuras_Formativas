#ifndef DLinkEDDList_H_
#define DLinkEDDList_H_

#include <string>
#include <sstream>
#include "exception.h"

using namespace std;

template <class T> class DList;

template <class T>
class DLink {
private:
	DLink(T);
	DLink(T, DLink<T>*, DLink<T>*);
	DLink(const DLink<T>&, const DLink<T>&);

	T	    value;
	DLink<T> *next;
	DLink<T> *previous;

	friend class DList<T>;
};

template <class T>
DLink<T>::DLink(T val):value(val), next(0), previous(0){}

template <class T>
DLink<T>::DLink(T val, DLink* nxt, DLink* prvs):value(val), next(nxt), previous(prvs) {}

template <class T>
DLink<T>::DLink(const DLink<T> &source, const DLink<T> &source2):value(source.value), next(source.next), previous(source.source) {}

template <class T>
class DList{
public:
  DList();
  ~DList();
  string toStringForward()const;
	string toStringBackward()const;
	void clear();
	bool empty()const;
	void addFirst(T val) throw(OutOfMemory);
  void add(T val) throw(OutOfMemory);
	int find(T val);
	void update(T index, T val);
	void removeFirst();
	void remove(T index);
private:
  DLink<T> *head;
	DLink<T> *tail;
  int size;
};

template <class T>
DList<T>::DList():head(0),tail(0),size(0){}

template <class T>
DList<T>::~DList(){
  clear();
}

template <class T>
string DList<T>::toStringForward() const {
	stringstream aux;
	DLink<T> *p;
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
string DList<T>::toStringBackward() const {
	stringstream aux;
	DLink<T> *p;
	p = tail;
	aux << "[";
	while (p != 0) {
		aux << p->value;
		if (p->previous != 0) {
			aux << ", ";
		}
		p = p->previous;
	}
	aux << "]";
	return aux.str();
}

template <class T>
bool DList<T>::empty() const {
	return (head == 0);
}

template <class T>
void DList<T>::clear() {
	DLink<T> *p, *q;

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
void DList<T>::addFirst(T val) throw(OutOfMemory){
	DLink<T> *newDLink;

	newDLink = new DLink<T>(val);
	if (newDLink == 0)
		throw OutOfMemory();

	newDLink->next = head;
	head = newDLink;

	newDLink->previous = tail;
	tail = newDLink;

	size++;
}

template <class T>
void DList<T>::add(T val) throw(OutOfMemory){
  DLink<T> *newDLink, *p;

  newDLink = new DLink<T>(val);
  if (newDLink == 0) {
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

	newDLink->next = 0;
	p->next = newDLink;

	newDLink->previous = p;
	tail = newDLink;


	size++;
}

template <class T>
int DList<T>::find(T val){
	DLink<T> *p;
	p = head;

	for (int i = 0; i<size; i++){
		if (p->value == val)
			return i;
		p = p->next;
	}
	return -1;
}

template <class T>
void DList<T>::update(T index, T val){
	DLink<T> *p;
	p = head;

	for (int i = 0; i<index; i++){
		p = p->next;
	}
	p->value = val;
}

template <class T>
void DList<T>::removeFirst(){
	DLink<T> *p;
	p = head;
	head = p->next;
	p->next->previous = 0;

	delete p;
	size --;
}

template <class T>
void DList<T>::remove(T index){
	if (index ==0)
		removeFirst();

	else{
	DLink<T> *p, *q, *r;
	p = head;
	for(int i =0; i==index; i++){
		p = p->next;
	}
	q = p;
	p = p->next;
	r = p->next;
	q->next = r;
	r->previous = q;
	tail = r;

	delete p;
	size --;
	}
}

#endif
