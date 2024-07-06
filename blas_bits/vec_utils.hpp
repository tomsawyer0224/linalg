/*
template <class T>
void Vec<T>::print(){
	for(auto it = this->val.begin(); it != this->val.end(); it++){
		std::cout<<*it<<endl;
	}
}
*/
template <class T>
void Vec<T>::print() const{
	for(auto it = this->val.begin(); it != this->val.end(); it++){
		std::cout<<*it<<endl;
	}
}
/*
template <class T>
vector<T> Vec<T>::get_val(){
	return this->val;
}
*/
template <class T>
vector<T> Vec<T>::get_val() const{
	if(this->n_elem == 0){
		std::cout<<"get_val() failed! zero element"<<std::endl;
		exit(1);
	}
	return this->val;
}
/*
template <class T>
double Vec<T>::norm(){
	//return sqrt((*this)*(*this));
	if(this->n_elem == 0){
		std::cout<<"finding norm failed! zero element"<<std::endl;
		exit(1);
	}
	double t = 0;;
	for(int i = 0; i < this->n_elem; i++){
		t += double(this->val[i])*double(this->val[i]);
	}
	return sqrt(t);
}
*/
template <class T>
double Vec<T>::norm() const{
	//return sqrt((*this)*(*this));
	if(this->n_elem == 0){
		std::cout<<"finding norm failed! zero element"<<std::endl;
		exit(1);
	}
	double t = 0;
	for(int i = 0; i < this->n_elem; i++){
		t += double(this->val[i])*double(this->val[i]);
	}
	return sqrt(t);
}

template <class U>
Mat<U> outer(const Vec<U>& v1, const Vec<U>& v2){
	if(v1.n_elem == 0 || v2.n_elem == 0){
		std::cout<<"outer producting failed! zero element"<<std::endl;
		exit(1);
	}
	int n_rows = v1.n_elem;
	int n_cols = v2.n_elem;
	std::vector<std::vector<U>> temp;
	for(int i = 0; i < n_rows; i++){
		std::vector<U> r;
		for(int j = 0; j < n_cols; j++){
			r.push_back(v1.val[i]*v2.val[j]);
		}
		temp.push_back(r);
	}
	Mat<U> res(temp);
	return res;
}

template <class T>
Mat<T> Vec<T>::reshape(const int& n_rows, const int& n_cols){
	if(n_rows == 0 || n_cols == 0){
		std::cout<<"reshaping failed! zero element"<<std::endl;
		exit(1);
	}
	if(this->n_elem != n_rows*n_cols){
		std::cout<<"can not reshape Vec of size "<<this->n_elem<<
		" to Mat of size "<<n_rows<<"x"<<n_cols<<std::endl;
		exit(1);
	}
	else{
		if(n_rows > 0 && n_cols > 0){
			std::vector<std::vector<T>> temp;
			for(int i = 0; i < n_rows; i++){
				std::vector<T> r;
				for(int j = i*n_cols ; j < (i+1)*n_cols; j++){
					r.push_back(this->val[j]);
				}
				temp.push_back(r);
			}
			Mat<T> res(temp);
			return res;
		}
		else{
			std::cout<<"can not reshape Vec of size "<<this->n_elem<<
			" to Mat of size "<<n_rows<<"x"<<n_cols<<std::endl;
			exit(1);
		}
	}
}

template <class U>
Vec<U> arange(const U& start, const U& stop, U interval = U(1)){//Return evenly spaced values within a given interval
	if(start >= stop){
		std::cout<<"opp! start must be less than stop"<<std::endl;
		exit(1);
	}
	std::vector<U> v;
	int num = int(double(stop - start)/double(interval));
	v.push_back(U(start));
	int i = 1;
	for(; i < num; i++){
		v.push_back(U(start) + i*interval);
	}
	U last = v.back() + interval;
	if(last < stop){
		v.push_back(last);
	}
	Vec<U> res(v);
	return res;

}
template <class U>
Vec<double> linspace(const U& start, const U& stop, int num = 10){//Return evenly spaced numbers over a specified interval (double)
	if(num < 2){
		std::cout<<"Vec must be at least 2 element"<<std::endl;
		exit(1);
	}
	std::vector<double> v;
	double interval = double(stop - start)/double(num-1);
	for(int i = 0; i < num - 1; i++){
		v.push_back(double(start) + i*interval);
	}
	v.push_back(double(stop));
	Vec<double> res(v);
	return res;
}

template <class T>
int Vec<T>::count_zero(){
	if(this->n_elem == 0){
		std::cout<<"count_zero() failed! zero element"<<std::endl;
		exit(1);
	}
	return std::count(this->val.begin(), this->val.end(), 0);
}

template <class T>
int Vec<T>::count_nonzero(){
	if(this->n_elem == 0){
		std::cout<<"count_nonzero() failed! zero element"<<std::endl;
		exit(1);
	}
	return this->n_elem - std::count(this->val.begin(), this->val.end(), 0);
}