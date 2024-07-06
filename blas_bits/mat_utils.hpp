/*
template <class T>
void Mat<T>::print(){
	if (this->n_elem == 0){
		std::cout<<"[matrix "<<this->n_rows<<"x"<<this->n_cols<<"]"<<std::endl;
		return;
	}
	for(int i = 0; i < this->n_rows; i++){
		for(auto it = this->val[i].begin(); it != this->val[i].end(); it++){
			std::cout<<left<<setw(12)<<*it;
		}
		std::cout<<std::endl;
	}
}
*/
template <class T>
void Mat<T>::print() const{
	if (this->n_elem == 0){
		std::cout<<"[matrix "<<this->n_rows<<"x"<<this->n_cols<<"]"<<std::endl;
		return;
	}
	for(int i = 0; i < this->n_rows; i++){
		for(auto it = this->val[i].begin(); it != this->val[i].end(); it++){
			std::cout<<left<<setw(12)<<*it;
		}
		std::cout<<std::endl;
	}
}
/*
template <class T>
void Mat<T>::get_attr(){
	std::cout<<"n_rows = "<<this->n_rows<<", n_cols = "<<this->n_cols<<", n_elem = "<<this->n_elem<<std::endl;
}
*/
template <class T>
void Mat<T>::get_attr() const{
	std::cout<<"n_rows = "<<this->n_rows<<", n_cols = "<<this->n_cols<<", n_elem = "<<this->n_elem<<std::endl;
}
template <class T>
Mat<T> Mat<T>::t(){
	Mat<T> res(this->n_cols, this->n_rows);
	for(int i = 0; i < res.n_rows; i++){
		for(int j = 0; j < res.n_cols; j++){
			res.val[i][j] = this->val[j][i]; 
		}
	}
	return res;
}

template <class T>
Vec<T> Mat<T>::flatten(){
	std::vector<T> temp;
	for(int i = 0; i < this->n_rows; i++){
		for(int j = 0; j < this->n_cols; j++){
			temp.push_back(this->val[i][j]);
		}
	}
	Vec<T> res(temp);
	return res;
}

template <class T>
double Mat<T>::norm() const{
	if(this->n_elem == 0){
		std::cout<<"finding norm failed! zero element"<<std::endl;
		exit(1);
	}
	double t = 0;
	for(int i = 0; i < this->n_rows; i++){
		for(int j = 0; j < this->n_cols; j++){
			t += double(this->val[i][j])*double(this->val[i][j]);
		}
	}
	return sqrt(t);
}

template <class T>
void Mat<T>::swap_row(const int& row1, const int& row2){
	if(row1 >= this->n_rows || row2 >= this->n_rows || row1 < -this->n_rows || row2 < -this->n_rows){
		std::cout<<"swapping error! index out of range"<<std::endl;
		exit(1);
	}
	int r1 = row1, r2 = row2;
	if(row1 < 0){
		r1 = this->n_rows + row1;
	}
	if(row2 < 0){
		r2 = this->n_rows + row2;
	}
	std::swap(this->val[r1], this->val[r2]);
}

template <class T>
void Mat<T>::swap_col(const int& col1, const int& col2){
	if(col1 >= this->n_cols || col2 >= this->n_cols || col1 < -this->n_cols || col2 < -this->n_cols){
		std::cout<<"swapping error! index out of range"<<std::endl;
		exit(1);
	}
	int c1 = col1, c2 = col2;
	if(col1 < 0){
		c1 = this->n_cols + col1;
	}
	if(col2 < 0){
		c2 = this->n_cols + col2;
	}
	for(int i = 0; i < this->n_rows; i++){
		std::swap(this->val[i][c1], this->val[i][c2]);
	}
}

template <class T>
Mat<T> Mat<T>::row(const int& begin, const int& end){
	if(begin >= this->n_rows || end - 1 >= this->n_rows || begin < -this->n_rows || end -1 < -this->n_rows){
		std::cout<<"getting row error! index out of range"<<std::endl;
		exit(1);
	}
	int rb = begin, re = end;
	if(begin < 0){
		rb = this->n_rows + begin;
	}
	if(end < 0){
		re = this->n_rows + end;
	}
	if(rb >= re){
		std::cout<<"getting row error! 'begin' must be less than 'end'"<<std::endl;
		std::cout<<"in this case: begin = "<<begin<<"("<<rb<<"), end = "<<end<<"("<<re<<")"<<std::endl;
		exit(1);
	}
	/*
	std::vector<std::vector<T>> temp;
	for(int i = rb; i < re; i++){
		temp.push_back(this->val[i]);
	} 
	*/
	auto it = this->val.begin();
	std::vector<std::vector<T>> temp(it + rb, it + re);
	Mat<T> res(temp);
	return res;
}

template <class T>
Mat<T> Mat<T>::col(const int& begin, const int& end){
	if(begin >= this->n_cols || end - 1 >= this->n_cols || begin < -this->n_cols || end -1 < -this->n_cols){
		std::cout<<"getting column error! index out of range"<<std::endl;
		exit(1);
	}
	int cb = begin, ce = end;
	if(begin < 0){
		cb = this->n_cols + begin;
	}
	if(end < 0){
		ce = this->n_cols + end;
	}
	if(cb >= ce){
		std::cout<<"getting column error! 'begin' must be less than 'end'"<<std::endl;
		std::cout<<"in this case: begin = "<<begin<<"("<<cb<<"), end = "<<end<<"("<<ce<<")"<<std::endl;
		exit(1);
	}
	std::vector<std::vector<T>> temp;
	for(int i = 0; i < this->n_rows; i++){
		auto it = this->val[i].begin();
		std::vector<T> ri(it + cb, it + ce);
		temp.push_back(ri);
	}
	Mat<T> res(temp);
	return res;
}

template <class T>
Vec<T> Mat<T>::one_row(const int& row){
	if(row >= this->n_rows || row < -this->n_rows){
		std::cout<<"getting column error! index out of range"<<std::endl;
		exit(1);
	}
	int r = row;
	if(row < 0){
		r = this->n_rows + row;
	}
	std::vector<T> temp(this->val[r]);
	Vec<T> res(temp);
	return res;
}

template <class T>
Vec<T> Mat<T>::one_col(const int& col){
	if(col >= this->n_cols || col < -this->n_cols){
		std::cout<<"getting column error! index out of range"<<std::endl;
		exit(1);
	}
	int c = col;
	if(col < 0){
		c = this->n_cols + col;
	}
	std::vector<T> temp;
	for(int i = 0; i < this->n_rows; i++){
		temp.push_back(this->val[i][c]);
	}
	Vec<T> res(temp);
	return res;
}

template <class U>
Mat<U> concatenate(const Mat<U>& m1, const Mat<U>& m2, const int& d){
	if(m1.n_elem == 0 || m2.n_elem == 0){
		std::cout<<"concatenating failed! zero element"<<std::endl;
		exit(1);
	}
	if(d < 0 || d > 1){
		std:cout<<"concatenating failed!"<<std::endl
		<<"d = 0 for concatenating along column (add more row)"<<std::endl
		<<"d = 1 for concatenating along row (add more colum)"<<std::endl;
		exit(1);
	}
	else{
		if (d == 0){//add more row
			if(m1.n_cols != m2.n_cols){
				std::cout<<"concatenating failed! different column size"<<std::endl;
				exit(1);
			}
			std::vector<std::vector<U>> temp(m1.val);
			auto end_temp = temp.end();
			std::vector<std::vector<U>> v2(m2.val);
			auto beg_v2 = v2.begin(), end_v2 = v2.end();
			temp.insert(end_temp, beg_v2, end_v2);
			Mat<U> res(temp);
			return res;
		}
		else{
			if(m1.n_rows != m2.n_rows){
				std::cout<<"concatenating failed! different row size"<<std::endl;
				exit(1);
			}
			std::vector<std::vector<U>> temp(m1.val);
			for(int i = 0; i < temp.size(); i++){
				std::vector<U> v2 = m2.val[i];
				auto tempi_end = temp[i].end();
				auto v2_beg = v2.begin(), v2_end = v2.end();
				temp[i].insert(tempi_end, v2_beg, v2_end);
			}
			Mat<U> res(temp);
			return res;
		}
	}
}

template <class U>
Mat<U> identity(const int& n){//identity matrix
	if(n <= 0){
		std::cout<<"creating identity matrix failed! negative size"<<std::endl;
		exit(1);
	}
	Mat<U> m(n,n);
	for(int i = 0; i < n; i++){
		m.val[i][i] = U(1);
	}
	return m;
}

template <class U>
Mat<U> zeros(const int& n_rows, const int& n_cols){
	if(n_rows <= 0 || n_cols <= 0){
		std::cout<<"creating zeros matrix failed! negative size"<<std::endl;
		exit(1);
	}
	Mat<U> res(n_rows, n_cols);
	return res;
}

template <class U>
Mat<U> ones(const int& n_rows, const int& n_cols){
	if(n_rows <= 0 || n_cols <= 0){
		std::cout<<"creating ones matrix failed! negative size"<<std::endl;
		exit(1);
	}
	Mat<U> res(n_rows, n_cols);
	for(int i = 0; i < res.n_rows; i++){
		for(int j = 0; j < res.n_cols; j++){
			res.val[i][j] = U(1);
		}
	}
	return res;
}
/*
template <class T>
void Mat<T>::resize(const int& n_rows, const int& n_cols){
	if(n_rows <= 0 || n_cols <= 0){
		std::cout<<"resizing failed! negative size"<<std::endl;
		exit(1);
	}
}
*/
template <class T>
int Mat<T>::count_zero(const int& d){//count number of zero along column (int = 0) or row (int = 1)
	if(this->n_elem == 0){
		std::cout<<"counting zero failed!"<<std::endl;
		exit(1);
	}
}