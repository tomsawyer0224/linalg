//---op <<
template <class U>
std::ostream& operator<<(std::ostream& out, const Mat<U>& m){
	if (m.n_elem == 0){
		out<<"[matrix "<<m.n_rows<<"x"<<m.n_cols<<"]"<<std::endl;
		return out;
	}
	for(int i = 0; i < m.n_rows; i++){
		for(int j= 0; j < m.n_cols; j++){
			out<<left<<setw(12)<<m.val[i][j];
		}
		std::cout<<"\n";
	}
	return out;
}
//----------------------------------------------------

//---op []
template <class T>
std::vector<T>& Mat<T>::operator[](const int& i){
	if(i < 0 || i > this->n_rows - 1){
		std::cout<<"index out of range"<<std::endl;
		exit(1);
	}
	return this->val[i];
}

template <class T>
const std::vector<T>& Mat<T>::operator[](const int& i) const{
	if(i < 0 || i > this->n_rows - 1){
		std::cout<<"index out of range"<<std::endl;
		exit(1);
	}
	return this->val[i];
}
//------------------------------------------------------------


//---op +
template <class U>
Mat<U> operator+(const Mat<U>& m1, const Mat<U>& m2){
	if((m1.n_rows == m2.n_rows) && (m1.n_cols == m2.n_cols)){
		if(m1.n_elem > 0){
			Mat<U> res(m1.n_rows, m1.n_cols);
			for(int i = 0; i < res.n_rows; i++){
				for(int j = 0; j < res.n_cols; j++){
					res.val[i][j] = m1.val[i][j] + m2.val[i][j];
				}
			}
			return res;
		}
		else{
			std::cout<<"adding failed! zero element"<<std::endl;
			exit(1);
		}
	}
	else{
		std::cout<<"adding failed! different size"<<std::endl;
		exit(1);
	}
}

template <class U>
Mat<U> operator+(const U& m1, const Mat<U>& m2){
	if(m2.n_elem == 0){
		std::cout<<"adding failed! zero element"<<std::endl;
		exit(1);
	}
	Mat<U> res(m2.n_rows, m2.n_cols);
	for(int i = 0; i < res.n_rows; i++){
		for(int j = 0; j < res.n_cols; j++){
			res.val[i][j] = m1 + m2.val[i][j];
		}
	}
	return res;
}

template <class U>
Mat<U> operator+(const Mat<U>& m1, const U& m2){
	if(m1.n_elem == 0){
		std::cout<<"adding failed! zero element"<<std::endl;
		exit(1);
	}
	Mat<U> res(m1.n_rows, m1.n_cols);
	for(int i = 0; i < res.n_rows; i++){
		for(int j = 0; j < res.n_cols; j++){
			res.val[i][j] = m1.val[i][j] + m2;
		}
	}
	return res;
}

template <class U>
Mat<U> operator+(const Mat<U>& m1, const Vec<U>& m2){
	if(m1.n_rows == m2.n_elem){
		if(m2.n_elem == 0 || m1.n_elem == 0){
			std::cout<<"adding failed! zero element"<<std::endl;
			exit(1);
		}
		else{
			Mat<U> res(m1);
			vector<U> m2_val = m2.get_val();
			for(int j = 0; j < res.n_cols; j++){
				for(int i = 0; i < res.n_rows; i++){
					res.val[i][j] += m2_val[i];
					//res.val[i][j] += m2.val[i];
				}
			}
			return res;
		}
	}
	else{
		std::cout<<"adding failed! different size"<<std::endl;
		exit(1);
	}
}

template <class U>
Mat<U> operator+(const Vec<U>& m1, const Mat<U>& m2){
	if(m2.n_rows == m1.n_elem){
		if(m1.n_elem == 0 || m2.n_elem == 0){
			std::cout<<"adding failed! zero element"<<std::endl;
			exit(1);
		}
		else{
			Mat<U> res(m2);
			vector<U> m1_val = m1.get_val();
			for(int j = 0; j < res.n_cols; j++){
				for(int i = 0; i < res.n_rows; i++){
					res.val[i][j] += m1_val[i];
					//res.val[i][j] += m1.val[i];
				}
			}
			return res;
		}
	}
	else{
		std::cout<<"adding failed! different size"<<std::endl;
		exit(1);
	}
}
//--------------------------------------------------------------

//---op -
template <class U>
Mat<U> operator-(const Mat<U>& m1, const Mat<U>& m2){
	if((m1.n_rows == m2.n_rows) && (m1.n_cols == m2.n_cols)){
		if(m1.n_elem > 0){
			Mat<U> res(m1.n_rows, m1.n_cols);
			for(int i = 0; i < res.n_rows; i++){
				for(int j = 0; j < res.n_cols; j++){
					res.val[i][j] = m1.val[i][j] - m2.val[i][j];
				}
			}
			return res;
		}
		else{
			std::cout<<"substracting failed! zero element"<<std::endl;
			exit(1);
		}
	}
	else{
		std::cout<<"substracting failed! different size"<<std::endl;
		exit(1);
	}
}

template <class U>
Mat<U> operator-(const U& m1, const Mat<U>& m2){
	if(m2.n_elem == 0){
		std::cout<<"substracting failed! zero element"<<std::endl;
		exit(1);
	}
	Mat<U> res(m2.n_rows, m2.n_cols);
	for(int i = 0; i < res.n_rows; i++){
		for(int j = 0; j < res.n_cols; j++){
			res.val[i][j] = m1 - m2.val[i][j];
		}
	}
	return res;
}

template <class U>
Mat<U> operator-(const Mat<U>& m1, const U& m2){
	if(m1.n_elem == 0){
		std::cout<<"substracting failed! zero element"<<std::endl;
		exit(1);
	}
	Mat<U> res(m1.n_rows, m1.n_cols);
	for(int i = 0; i < res.n_rows; i++){
		for(int j = 0; j < res.n_cols; j++){
			res.val[i][j] = m1.val[i][j] - m2;
		}
	}
	return res;
}

template <class U>
Mat<U> operator-(const Mat<U>& m1, const Vec<U>& m2){
	if(m1.n_rows == m2.n_elem){
		if(m2.n_elem == 0 || m1.n_elem == 0){
			std::cout<<"substracting failed! zero element"<<std::endl;
			exit(1);
		}
		else{
			Mat<U> res(m1);
			vector<U> m2_val = m2.get_val();
			for(int j = 0; j < res.n_cols; j++){
				for(int i = 0; i < res.n_rows; i++){
					res.val[i][j] -= m2_val[i];
				}
			}
			return res;
		}
	}
	else{
		std::cout<<"substracting failed! different size"<<std::endl;
		exit(1);
	}
}

template <class U>
Mat<U> operator-(const Vec<U>& m1, const Mat<U>& m2){
	if(m2.n_rows == m1.n_elem){
		if(m1.n_elem == 0 || m2.n_elem == 0){
			std::cout<<"substracting failed! zero element"<<std::endl;
			exit(1);
		}
		else{
			Mat<U> res(m2);
			vector<U> m1_val = m1.get_val();
			for(int j = 0; j < res.n_cols; j++){
				for(int i = 0; i < res.n_rows; i++){
					res.val[i][j] = m1_val[i] - res.val[i][j];
				}
			}
			return res;
		}
	}
	else{
		std::cout<<"substracting failed! different size"<<std::endl;
		exit(1);
	}
}
//-----------------------------------------------------------------

//---op *
template <class U>
Mat<U> operator*(const Mat<U>& m1, const Mat<U>& m2){
	if (m1.n_elem == 0 || m2.n_elem == 0){
		std::cout<<"multiplying failed! zero element"<<std::endl;
		exit(1);
	}
	if(m1.n_cols == m2.n_rows){
		Mat<U> res(m1.n_rows, m2.n_cols);
		for(int i = 0; i < res.n_rows; i++){
			for(int j = 0; j < res.n_cols; j++){
				for(int k = 0; k < m1.n_cols; k++){
					res.val[i][j] += m1.val[i][k]*m2.val[k][j];
				}
			}
		}
		return res;
	}
	else{
		std::cout<<"multiplying failed! unsuitable size"<<std::endl;
		exit(1);
	}
}

template <class U>
Mat<U> operator*(const U& m1, const Mat<U>& m2){
	if(m2.n_elem == 0){
		std::cout<<"multiplying failed! zero element"<<std::endl;
		exit(1);
	}
	Mat<U> res(m2.n_rows, m2.n_cols);
	for(int i = 0; i < res.n_rows; i++){
		for(int j = 0; j < res.n_cols; j++){
			res.val[i][j] = m1 * m2.val[i][j];
		}
	}
	return res;
}

template <class U>
Mat<U> operator*(const Mat<U>& m1, const U& m2){
	if(m1.n_elem == 0){
		std::cout<<"multiplying failed! zero element"<<std::endl;
		exit(1);
	}
	Mat<U> res(m1.n_rows, m1.n_cols);
	for(int i = 0; i < res.n_rows; i++){
		for(int j = 0; j < res.n_cols; j++){
			res.val[i][j] = m1.val[i][j] * m2;
		}
	}
	return res;
}

template <class U>
Vec<U> operator*(const Mat<U>& m1, const Vec<U>& m2){
	if(m1.n_elem == 0 || m2.n_elem == 0){
		std::cout<<"multiplying failed! zero element"<<std::endl;
		exit(1);
	}
	if(m1.n_cols == m2.n_elem){
		vector<U> temp(m1.n_rows, U(0));
		vector<U> m2_val = m2.get_val();
		for(int i = 0; i < m1.n_rows; i++){
			for(int j = 0; j < m2.n_elem; j++){
				temp[i] += m1.val[i][j]*m2_val[j];
			}
		}
		Vec<U> res(temp);
		return res;
	}
	else{
		std::cout<<"multiplying failed! unsuitable size"<<std::endl;
		exit(0);
	}
}

template <class U>
Vec<U> operator*(const Vec<U>& m1, const Mat<U>& m2){
	if(m1.n_elem == 0 || m2.n_elem == 0){
		std::cout<<"multiplying failed! zero element"<<std::endl;
		exit(1);
	}
	if(m1.n_elem == m2.n_rows){
		vector<U> temp(m2.n_cols, U(0));
		vector<U> m1_val = m1.get_val();
		for(int j = 0; j < m2.n_cols; j++){
			for(int i = 0; i < m1.n_elem; i++){
				temp[j] += m1_val[i]*m2.val[i][j];
			}
		}
		Vec<U> res(temp);
		return res;
	}
	else{
		std::cout<<"multiplying failed! unsuitable size"<<std::endl;
		exit(0);
	}
}