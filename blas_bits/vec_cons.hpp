template <class T>
Vec<T>::Vec() : Tensor<T>::Tensor(){
	this->val = std::vector<T>();
}

template <class T>
Vec<T>::Vec(const int& n_elem){
	if(n_elem <= 0){
		std::cout<<"error while constructing a vector with non-positive number of elements"<<std::endl;
		exit(1);
	}
	this->n_elem = n_elem;
	this->val.assign(n_elem, T(0));
}

template <class T>
Vec<T>::Vec(const std::vector<T>& v){
	this->n_elem = v.size();
	this->val = v;
}

template <class T>
Vec<T>::Vec(const Vec<T>& v) : Tensor<T>::Tensor(v){
	this->val = v.val;
}

template <class T>
Vec<T>::Vec(const std::initializer_list<T>& v){
	this->n_elem = v.size();
	for(auto it = v.begin(); it != v.end(); it++){
		this->val.push_back(*it);
	}
}

