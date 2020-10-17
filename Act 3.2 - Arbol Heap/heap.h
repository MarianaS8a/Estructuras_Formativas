#ifndef HEAP_H_
#define HEAP_H_


#include <string>
#include <sstream>
#include "exception.h"
#include <iostream>

template <class T>
class Heap {
private:
	T *data;
	unsigned int tam;
	unsigned int count;

	unsigned int parent(unsigned int) const;
	unsigned int left(unsigned int) const;
	unsigned int right(unsigned int) const;
	void heapify(unsigned int);
	void swap(unsigned int, unsigned int);

public:
	Heap(unsigned int) throw (OutOfMemory);
	~Heap();
	bool empty() const;
	bool full() const;
	void push(T) throw (Overflow);
	T pop() throw (NoSuchElement);
  T size() const;
  T top() throw (NoSuchElement);
	void clear();
	std::string toString() const;
};

template <class T>
Heap<T>::Heap(unsigned int sze) throw (OutOfMemory) {
	tam = sze;
	data = new T[tam];
	if (data == 0) {
		throw OutOfMemory();
	}
	count = 0;
}

template <class T>
Heap<T>::~Heap() {
	delete [] data;
	data = 0;
	tam = 0;
	count = 0;
}

template <class T>
bool Heap<T>::empty() const {
	if (count == 0)
		return 1;
	else
		return 0;
}

template <class T>
bool Heap<T>::full() const {
	if (count == tam)
		return 1;
	else
		return 0;
}

template <class T>
unsigned int Heap<T>::parent(unsigned int pos) const {
	return (pos -1)/2;
}

template <class T>
unsigned int Heap<T>::left(unsigned int pos) const {
	return (2*pos+1);
}

template <class T>
unsigned int Heap<T>::right(unsigned int pos) const {
	return (2*pos+2);
}

template <class T>
void Heap<T>::swap(unsigned int i, unsigned int j) {
	T aux = data[i];
	data[i] = data[j];
	data[j] = aux;
}

template <class T>
void Heap<T>::heapify(unsigned int pos) {
	unsigned min = pos;
	if(left(pos) <= count && data[left(pos)]< data[min])
		min = left(pos);

	if(left(pos) <= count && data[left(pos)]< data[min])
		min = left(pos);
	if (min!=pos){
		swap(pos, min);
		heapify(min);
	}
}

template <class T>
void Heap<T>::push(T val) throw (Overflow) {
	if (full())
		throw Overflow();
	unsigned int index = count;
	while (index > 0 && val < data[parent(index)]){
		data[index] = data[parent(index)];
		index = parent(index);
	}
	data [index] = val;
	count++;
}

template <class T>
T Heap<T>::pop() throw (NoSuchElement) {
	if(empty())
		throw NoSuchElement();
	T aux = data[0];
	count --;
	data[0] = data[count];
	heapify(0);
	return aux;
}

template <class T>
T Heap<T>::size() const{
  return count;
}

template <class T>
T Heap<T>::top() throw (NoSuchElement){
  if(empty())
		throw NoSuchElement();

  return data[0];
}

template <class T>
void Heap<T>::clear() {
	count = 0;
}


template <class T>
std::string Heap<T>::toString() const {
	std::stringstream aux;

		aux << "[";
		for (unsigned int i = 0; i < count; i++) {
			if (i != 0) {
				aux << " ";
			}
			aux << data[i];
		}
		aux << "]";
		return aux.str();

}
#endif /* HASH_H_ */
