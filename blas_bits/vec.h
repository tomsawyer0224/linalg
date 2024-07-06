#ifndef VEC_H
#define VEC_H

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <initializer_list>
#include <typeinfo>
#include <cmath>
#include <algorithm>

#include "utils.h"
#include "tensor.h"
#include "mat.h"

template <class T>
class Mat;//prototype of class Mat

template <class T>
class Vec : public Tensor<T>{
//attributes
protected:
	std::vector<T> val;
//methods
public:
	//constructors
	Vec();
	Vec(const int&);
	Vec(const std::vector<T>&);
	Vec(const Vec<T>&);
	Vec(const std::initializer_list<T>&);
	
	//overload operators	
	//---op <<
	template <class U>
	friend std::ostream& operator<<(std::ostream&, const Vec<U>&);
	
	//---op +
	template <class U>
	friend Vec<U> operator+(const Vec<U>&, const Vec<U>&);
	template <class U>
	friend Vec<U> operator+(const U&, const Vec<U>&);
	template <class U>
	friend Vec<U> operator+(const Vec<U>&, const U&);
	
	//---op -
	template <class U>
	friend Vec<U> operator-(const Vec<U>&, const Vec<U>&);
	template <class U>
	friend Vec<U> operator-(const U&, const Vec<U>&);
	template <class U>
	friend Vec<U> operator-(const Vec<U>&, const U&);
	template <class U>
	friend Vec<U> operator-(const Vec<U>&);
	
	//---op *
	template <class U>
	friend double operator*(const Vec<U>&, const Vec<U>&);
	template <class U>
	friend Vec<U> operator*(const U&, const Vec<U>&);
	template <class U>
	friend Vec<U> operator*(const Vec<U>&, const U&);
	
	//---op /
	template <class U>
	friend Vec<double> operator/(const Vec<U>&, const Vec<U>&);
	template <class U>
	friend Vec<double> operator/(const U&, const Vec<U>&);
	template <class U>
	friend Vec<double> operator/(const Vec<U>&, const U&);
	
	//---op []	
	T& operator[](const int&);

	//utilities
	//void print();// print a Vec
	void print() const;//print a const Vec
	
	//std::vector<T> get_val();//get val of Vec
	std::vector<T> get_val() const;//get val of const Vec
	
	//double norm();//l2 norm of Vec
	double norm() const;//l2 norm of const Vec
	int count_zero();//count number of zero
	int count_nonzero();//count number of non-zero
	
	Mat<T> reshape(const int& n_rows, const int& n_cols);//reshape a Vec to a Mat
	
	template <class U>
	friend Mat<U> outer(const Vec<U>&, const Vec<U>&);//outer product
	
	//Return evenly spaced values within a given interval
	template <class U>
	friend Vec<U> arange(const U&, const U&, U);
	//Return evenly spaced numbers over a specified interval (double)
	template <class U>
	friend Vec<double> linspace(const U&, const U&, int);
	
};
#include "vec_cons.hpp"
#include "vec_utils.hpp"
#include "vec_ovlops.hpp"

#endif
