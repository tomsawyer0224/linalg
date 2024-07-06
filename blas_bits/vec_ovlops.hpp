//overload operator <<
template <class U>
std::ostream& operator<<(std::ostream& out, const Vec<U>& v){
	for(auto it = v.val.begin(); it != v.val.end(); it++){
		out<<*it<<"\n";
	}
	return out;
}

//overload operator +
template <class U>
Vec<U> operator+(const Vec<U>& v1, const Vec<U>& v2){
	if(v1.n_elem == 0 || v2.n_elem == 0){
		std::cout<<"adding failed! zero element"<<std::endl;
		exit(1);
	}
	if (v1.n_elem != v2.n_elem){
		std::cout<<"adding failed! different size"<<std::endl;
		exit(1);
	}
	Vec<U> v(v1);
	for(int i = 0; i < v.n_elem; i++){
		v.val[i] += v2.val[i];
	}
	return v;
}

template <class U>
Vec<U> operator+(const U& v1, const Vec<U>& v2){
	if(v2.n_elem == 0){
		std::cout<<"adding failed! zero element"<<std::endl;
		exit(1);
	}
	Vec v(v2);
	for(int i = 0; i < v.n_elem; i++){
		v.val[i] += v1;
	}
	return v;
}

template <class U>
Vec<U> operator+(const Vec<U>& v1, const U& v2){
	if(v1.n_elem == 0){
		std::cout<<"adding failed! zero element"<<std::endl;
		exit(1);
	}
	Vec v(v1);
	for(int i = 0; i < v.n_elem; i++){
		v.val[i] += v2;
	}
	return v;
}
//--------------------------------------------------


//overload operator-
template <class U>
Vec<U> operator-(const Vec<U>& v1, const Vec<U>& v2){
	if(v1.n_elem == 0 || v2.n_elem == 0){
		std::cout<<"substracting failed! zero element"<<std::endl;
		exit(1);
	}
	if (v1.n_elem != v2.n_elem){
		std::cout<<"2 vectors are not same size"<<std::endl;
		exit(1);
	}
	Vec<U> v(v1);
	for(int i = 0; i < v.n_elem; i++){
		v.val[i] -= v2.val[i];
	}
	return v;
}
template <class U>
Vec<U> operator-(const U& v1, const Vec<U>& v2){
	if(v2.n_elem == 0){
		std::cout<<"substracting failed! zero element"<<std::endl;
		exit(1);
	}
	Vec<U> v(v2);
	for(int i = 0; i < v.n_elem; i++){
		v.val[i] = v1 - v2.val[i];
	}
	return v;
}

template <class U>
Vec<U> operator-(const Vec<U>& v1, const U& v2){
	if(v1.n_elem == 0){
		std::cout<<"substracting failed! zero element"<<std::endl;
		exit(1);
	}
	Vec<U> v(v1);
	for(int i = 0; i < v.n_elem; i++){
		v.val[i] -= v2 ;
	}
	return v;
}

template <class U>
Vec<U> operator-(const Vec<U>& v){
	if(v.n_elem == 0){
		std::cout<<"negative Vec failed! zero element"<<std::endl;
		exit(1);
	}
	Vec<U> res(v);
	for(int i = 0; i < v.n_elem; i++){
		res.val[i] = -res.val[i];
	}
	return res;
}
//----------------------------------------------------

//overload operator *
template <class U>
double operator*(const Vec<U>& v1, const Vec<U>& v2){
	if(v1.n_elem == 0 || v2.n_elem == 0){
		std::cout<<"multiplying failed! zero element"<<std::endl;
		exit(1);
	}
	if (v1.n_elem != v2.n_elem){
		std::cout<<"different size"<<std::endl;
		exit(1);
	}
	double res = 0;
	for(int i = 0; i < v1.n_elem; i++){
		res += v1.val[i]*v2.val[i];
	}
	return res;
}

template <class U>
Vec<U> operator*(const U& v1, const Vec<U>& v2){
	if(v2.n_elem == 0){
		std::cout<<"multiplying failed! zero element"<<std::endl;
		exit(1);
	}
	Vec<U> v(v2);
	for(int i = 0; i < v.n_elem; i++){
		v.val[i] *= v1 ;
	}
	return v;
}

template <class U>
Vec<U> operator*(const Vec<U>& v1, const U& v2){
	if(v1.n_elem == 0){
		std::cout<<"multiplying failed! zero element"<<std::endl;
		exit(1);
	}
	Vec<U> v(v1);
	for(int i = 0; i < v.n_elem; i++){
		v.val[i] *= v2 ;
	}
	return v;
}
//----------------------------------------------------

//overload operator /
template <class U>
Vec<double> operator/(const Vec<U>& v1, const Vec<U>& v2){
	if(v1.n_elem == 0 || v2.n_elem == 0){
		std::cout<<"dividing failed! zero element"<<std::endl;
		exit(1);
	}
	if (v1.n_elem != v2.n_elem){
		std::cout<<"different size"<<std::endl;
		exit(1);
	}
	Vec<double> v(v1.n_elem);
	for(int i = 0; i < v.n_elem; i++){
		if(v2.val[i] == 0){
			std::cout<<"dividing by zero"<<std::endl;
			exit(1);
		}
		v.val[i] = double(v1.val[i])/double(v2.val[i]) ;
	}
	return v;
}

template <class U>
Vec<double> operator/(const U& v1, const Vec<U>& v2){
	if(v2.n_elem == 0){
		std::cout<<"dividing failed! zero element"<<std::endl;
		exit(1);
	}
	Vec<double> v(v2.n_elem);
	for(int i = 0; i < v.n_elem; i++){
		if(v2.val[i] == 0){
			std::cout<<"dividing by zero"<<std::endl;
			exit(1);
		}
		v.val[i] = double(v1)/double(v2.val[i]);	
	}
	return v;
}

template <class U>
Vec<double> operator/(const Vec<U>& v1, const U& v2){
	if(v1.n_elem == 0){
		std::cout<<"dividing failed! zero element"<<std::endl;
		exit(1);
	}
	if (v2 == 0){
		std::cout<<"dividing by zero"<<std::endl;
		exit(1);
	}
	Vec<double> v(v1.n_elem);
	for(int i = 0; i < v.n_elem; i++){
		v.val[i] = double(v1.val[i])/double(v2);
	}
	return v;
}
//----------------------------------------------------

//overload operator []
template <class T>
T& Vec<T>::operator[](const int& i){
	if(i < 0 || i > this->n_elem - 1){
		std::cout<<"index out of range"<<std::endl;
		exit(1);
	}
	return this->val[i];
}






