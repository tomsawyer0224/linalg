template <class T>
Mat<T>::Mat() : Tensor<T>::Tensor(){
	this->n_rows = 0;
	this->n_cols = 0;
	//this->val.push_back(std::vector<T> ());
}

template <class T>
Mat<T>::Mat(const int& n_rows, const int& n_cols){
	if(n_rows < 0 || n_cols < 0){
		std::cout<<"error while constructing a Mat with negative number of rows or columns";
		exit(1);
	}
	this->n_rows = n_rows;
	this->n_cols = n_cols;
	this->n_elem = n_rows*n_cols;
	if (this->n_elem == 0) {
		return;
	}
	for(int i = 0; i < n_rows; i++){
		std::vector<T> temp;
		temp.assign(n_cols, T(0));
		this->val.push_back(temp);
	}
}

template <class T>
Mat<T>::Mat(const std::vector<std::vector<T>>& v){
	if(!isRectangle<T>(v)) {
		std::cout<<"opp! some rows has different number of elements!"<<std::endl;
		exit(1);
	}
	this->n_rows = v.size();
	this->n_cols = v[0].size();
	this->n_elem = v.size()*v[0].size();//this->n_rows*this->n_cols;
	this->val = v;
}

template <class T>
Mat<T>::Mat(const Vec<T>& v){
	this->n_rows = v.n_elem;
	this->n_cols = 1;
	this->n_elem = v.n_elem;
	std::vector<T> value = v.get_val();
	for(int i = 0; i < v.n_elem; i++){
		std::vector<T> temp;
		temp.push_back(value[i]);
		this->val.push_back(temp);
	}
}

template <class T>
Mat<T>::Mat(const Mat<T>& m) : Tensor<T>::Tensor(m){
	this->n_rows = m.n_rows;
	this->n_cols = m.n_cols;
	this->val = m.val;
}

template <class T>
Mat<T>::Mat(const std::initializer_list<std::initializer_list<T>>& l){
	if(!isRectangle<T>(l)) {
		std::cout<<"opp! some rows has different size!"<<std::endl;
		exit(1);
	}
	this->n_rows = l.size();
	auto it = l.begin();
	this->n_cols = it->size();
	this->n_elem = l.size()*it->size();//this->n_rows*this->n_cols;
	for(; it != l.end(); it++){
		std::vector<T> temp = *it;
		this->val.push_back(temp);
	}
}



