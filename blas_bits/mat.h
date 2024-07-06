#ifndef MAT_H
#define MAT_H

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <initializer_list>
#include <cstdbool>
#include <iomanip>
#include <cmath>
#include <algorithm>

#include "utils.h"
#include "tensor.h"
#include "vec.h"

template <class T>
class Vec;//prototype of class Vec

template <class T>
class Mat : public Tensor<T>{
//attributes
public:
	int n_rows, n_cols;
protected:
	std::vector<std::vector<T>> val;
//methods
public:
	//constructors
	Mat();
	Mat(const int&, const int&);
	Mat(const std::vector<std::vector<T>>&);
	Mat(const Vec<T>&);
	Mat(const Mat<T>&);
	Mat(const std::initializer_list<std::initializer_list<T>>&);//for Mat<T> A = {{}, {}};
	
	//overload operators
	//---op +
	template <class U>
	friend Mat<U> operator+(const Mat<U>&, const Mat<U>&);
	
	template <class U>
	friend Mat<U> operator+(const U&, const Mat<U>&);

	template <class U>
	friend Mat<U> operator+(const Mat<U>&, const U&);
	
	template <class U>
	friend Mat<U> operator+(const Mat<U>&, const Vec<U>&);
	
	template <class U>
	friend Mat<U> operator+(const Vec<U>&, const Mat<U>&);

	//---op -	
	template <class U>
	friend Mat<U> operator-(const Mat<U>&, const Mat<U>&);
	
	template <class U>
	friend Mat<U> operator-(const U&, const Mat<U>&);

	template <class U>
	friend Mat<U> operator-(const Mat<U>&, const U&);
	
	template <class U>
	friend Mat<U> operator-(const Mat<U>&, const Vec<U>&);
	
	template <class U>
	friend Mat<U> operator-(const Vec<U>&, const Mat<U>&);
	
	//---op *
	template <class U>
	friend Mat<U> operator*(const Mat<U>&, const Mat<U>&);
	
	template <class U>
	friend Mat<U> operator*(const U&, const Mat<U>&);

	template <class U>
	friend Mat<U> operator*(const Mat<U>&, const U&);
	
	template <class U>
	friend Vec<U> operator*(const Mat<U>&, const Vec<U>&);
	
	template <class U>
	friend Vec<U> operator*(const Vec<U>&, const Mat<U>&);//'row vector' = 'row vector' * matrix
	
	//---op /
	template <class U>
	friend Mat<U> operator/(const Mat<U>&, const Mat<U>&);
	
	template <class U>
	friend Mat<U> operator/(const U&, const Mat<U>&);

	template <class U>
	friend Mat<U> operator/(const Mat<U>&, const U&);
	
	template <class U>
	friend Mat<U> operator/(const Mat<U>&, const Vec<U>&);
	
	template <class U>
	friend Mat<U> operator/(const Vec<U>&, const Mat<U>&);
	
	//---op []
	std::vector<T>& operator[](const int&);
	const std::vector<T>& operator[](const int&)const;

	template <class U>
	friend std::ostream& operator<<(std::ostream&, const Mat<U>&);
	template <class U>
	friend Mat<U> concatenate(const Mat<U>&, const Mat<U>&, const int&);//int = 0 -> more row, int = 1 -> more column
	template <class U>
	friend Mat<U> identity(const int&);//identity matrix
	template <class U>
	friend Mat<U> zeros(const int&, const int&);
	template <class U>
	friend Mat<U> ones(const int&, const int&);
	
	
	//utilities
	//void print();
	void print() const;
	//void get_attr();
	void get_attr() const;
	Mat<T> t();//transpose
	Vec<T> flatten();//flatten
	double norm() const;//Frobenius norm
	void swap_row(const int&, const int&);//swap 2 rows
	void swap_col(const int&, const int&);//swap 2 cols
	Mat<T> row(const int&, const int&);//return matrix from row index [begin] to row index [end-1]
	Mat<T> col(const int&, const int&);//return matrix from column index [begin] to column index [end-1]
	Vec<T> one_row(const int&);//return Vec from only one row of Mat
	Vec<T> one_col(const int&);//return Vec from only one column of Mat
	//void resize(const int&, const int&);//resize a matrix
	int count_zero(const int&);//count number of zero along column (int = 0) or row (int = 1)
};
#include "mat_cons.hpp"
#include "mat_utils.hpp"
#include "mat_ovlops.hpp"


#endif
