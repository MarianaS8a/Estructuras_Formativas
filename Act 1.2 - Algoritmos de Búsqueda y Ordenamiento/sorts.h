#ifndef SORTS_H_
#define SORTS_H_

#include <vector>

using namespace std;


template <class T>
class Sorts {
private:
	void swapArray(vector<int> &v, int i, int j);
	void splitArray(vector<int> &v, vector<int> &copy, int low, int high);
	void copyArray(vector<int> &v, vector<int> &copy, int low, int high);
	void mergeArray(vector<int> &v, vector<int> &copy, int low, int mid, int high);
public:
	void ordenaSeleccion(vector<int> &v);
	void ordenaBurbuja(vector<int> &v);
	void ordenaMerge(vector<int> &v);
	int busqSecuencial(const vector<int> &v, int num);
	int busqBinaria(const vector<int> &v, int);
	int busqBinariaAux(const vector<int> &v, int low, int high, int num);
};

template <class T>
void Sorts<T>::swapArray(vector<int> &v, int i, int j) {
	T temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

template <class T>
void Sorts<T>::ordenaSeleccion(vector<int> &v) {
  for (int i=0; i<v.size()-1; i++){
    int min = i;
    for (int j=i+1; j<v.size(); j++){
      if (v[j]<v[min])
        min = j;
    }
    swapArray(v, i, min);
  }
}

template <class T>
void Sorts<T>::ordenaBurbuja(vector<int> &v) {
	for (int i = 0; i<v.size()-1; i++){
		for(int j = 0; j<v.size()-i-1; j++){
			if(v[j]>v[j+1]){
				swapArray(v,j,j+1);
			}
		}
	}
}


template <class T>
void Sorts<T>::ordenaMerge(vector<int> &v) {
	vector<int> copy(v.size());
	splitArray(v, copy, 0, v.size()-1);
}

template <class T>
void Sorts<T>::splitArray(vector<int> &v, vector<int> &copy, int low, int high) {
	int mid;
  if ((high-low) < 1)
		return;
	mid = (high + low) / 2;
	splitArray(v, copy, low, mid);
	splitArray(v, copy, mid+1, high);
	mergeArray(v, copy, low, mid, high);
	copyArray(v, copy, low, high);
}

template <class T>
void Sorts<T>::mergeArray(vector<int> &v, vector<int> &copy, int low, int mid, int high) {

	int i=low;
	int j=mid+1;
	int k=low;

	while (i<= mid && j<= high){
		if (v[i]< v[j]){
			copy[k] = v[i];
			i++;
		}
		else{
			copy[k] = v[j];
			j++;
		}
		k++;
	}
	if (i > mid){
		while (j <= high){
			copy[k++] = v[j];
			j++;
		}
	}
	else{
		while(i<=mid){
			copy[k++] = v[i];
			i++;
		}
	}
}

template <class T>
void Sorts<T>::copyArray(vector<int> &v, vector<int> &copy, int low, int high) {
	for (int i = low; i<= high; i++)
		v[i] = copy[i];
}

template <class T>
int Sorts<T>::busqSecuencial(const vector<int> &v, int num) {

	for(int i = 0; i < v.size(); i++){
		if (v[i] == num)
			return i;
	}
	return -1;
}

template <class T>
int Sorts<T>::busqBinaria(const vector<int> &v, int num) {
	return busqBinariaAux(v, 0, v.size()- 1, num);
}

template <class T>
int Sorts<T>::busqBinariaAux(const vector<int> &v, int low, int high, int num) {

		if(high > low){
			int mid = (high+low)/2;
			if (v[mid] == num)
				return mid;
			else if (v[mid] < num)
				return busqBinariaAux(v, mid + 1, high, num);
			else
				return busqBinariaAux(v, low, mid - 1, num);
		}

		return low;
}



#endif
