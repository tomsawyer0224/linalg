template <class T>
bool isRectangle(const std::vector<std::vector<T>>& v){
	auto itr = v.begin();
	int n_cols = itr->size();
	for(; itr != v.end(); itr++){
		if (n_cols != itr->size()){
			return false;
		}
	}
	return true;
}

template <class T>
bool isRectangle(const std::list<std::list<T>>& v){
	auto itr = v.begin();
	int n_cols = itr->size();
	for(; itr != v.end(); itr++){
		if (n_cols != itr->size()){
			return false;
		}
	}
	return true;
}

template <class T>
bool isRectangle(const std::initializer_list<std::initializer_list<T>>& v){
	auto itr = v.begin();
	int n_cols = itr->size();
	for(; itr != v.end(); itr++){
		if (n_cols != itr->size()){
			return false;
		}
	}
	return true;
}
