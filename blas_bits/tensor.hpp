#include <iostream>
#include <vector>
#include <tuple>
#include <string>

using namespace std;

template <class T>
Tensor<T>::Tensor(){
	this->n_elem = 0;
}

template <class T>
Tensor<T>::Tensor(const Tensor<T>& t){
	this->n_elem = t.n_elem;
}