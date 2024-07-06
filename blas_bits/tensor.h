#ifndef TENSOR_H
#define TENSOR_H

#include <iostream>
#include <vector>
#include <tuple>
#include <string>

using namespace std;

template <class T>
class Tensor{
//attributes
public: 
	int n_elem;
	//tuple<int> shape;
//method
public:
	//constructors
	Tensor();
	Tensor(const Tensor<T>&);
};

#include "tensor.hpp"


#endif
