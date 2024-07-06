#include <iostream>
#include <vector>
#include <list>
#include <initializer_list>
#include <string>
#include <cstdbool>

//#include "../vec.h"
#include "../../blas.h"
//#include "vec.h"
//#include "blas.h"

typedef Mat<int> mat;
typedef Mat<double> dmat;

typedef Vec<int> vec;
typedef Vec<double> dvec;

using namespace std;
template <class T>
void print_vec(const vector<T>& v){
	for(auto it = v.begin(); it != v.end(); it++){
		cout<<*it<<" ";//<<endl;
	}
	cout<<endl;
}
int main(){
	//constructors
	/*
	vec v1;
	dvec dv1;
	cout<<"---constructor from nothing: \n"<<"Vec<int> v1: \n"<<v1;
	cout<<"Vec<double> dv1: \n"<<dv1;
	
	vec v2(5);
	dvec dv2(1);
	cout<<"---constructor from n_elem: \n"<<"Vec<int> v2: \n"<<v2;
	cout<<"Vec<double> dv2: \n"<<dv2;
	
	vec v3({1,2,3,4});
	dvec dv3({.4,5.6,7.89});
	cout<<"---constructor from list: \n"<<"Vec<int> v3: \n"<<v3;
	cout<<"Vec<double> dv3: \n"<<dv3;
	
	vec v31(v3);
	dvec dv31(dv3);
	cout<<"---constructor from Vec: \n"<<"Vec<int> v31: \n"<<v31;
	cout<<"Vec<double> dv31: \n"<<dv31;
	
	vec v4 = {};
	dvec dv4 = {.4,5.6,7.89, 123456.567,1,245.67890};
	cout<<"---constructor from list: \n"<<"Vec<int> v4: \n"<<v4;
	cout<<"Vec<double> dv4: \n"<<dv4;
	
	vector<int> vint = {1,4,6};
	vector<double> vdou = {1.2,3.4,5.678,9.0};
	
	vec v5 = vint;
	dvec dv5 = vdou;
	cout<<"---constructor from vector<>: \n"<<"Vec<int> v5: \n"<<v5;
	cout<<"Vec<double> dv5: \n"<<dv5;
	
	//access via []
	cout<<"---accessing via []:\n";
	v5[1] = 100;
	dv5[0] = 100.234;
	cout<<"v5 after changing: \n";
	cout<<v5;
	cout<<"dv5 after changing: \n";
	cout<<dv5;
	
	//operator oveloading
	cout<<"---operator +\n";
	vec v61 = {1,2,3,4};
	vec v62 = {5,6,7,8};
	cout<<"Vec<int> v61:"<<endl;
	cout<<v61;
	cout<<"Vec<int> v62:"<<endl;
	cout<<v62;
	cout<<"v61+v62 ="<<endl;
	cout<<v61+v62;
	cout<<"v61+ 10 ="<<endl;
	cout<<v61 + 10;
	cout<<"20 + v62 ="<<endl;
	cout<<20 + v62;
	
	dvec dv61 = {1.5,2.5,3.5,4.5};
	dvec dv62 = {5.6,6.6,7.6,8.6};
	cout<<"Vec<double> dv61:"<<endl;
	cout<<dv61;
	cout<<"Vec<double> dv62:"<<endl;
	cout<<dv62;
	cout<<"dv61+dv62 ="<<endl;
	cout<<dv61+dv62;
	cout<<"dv61+ 10.0 ="<<endl;
	cout<<dv61 + 10.0;
	cout<<"20.0 + dv62 ="<<endl;
	cout<<20.0 + dv62;
	
	cout<<"---operator -\n";
	cout<<"Vec<int> v61:"<<endl;
	cout<<v61;
	cout<<"Vec<int> v62:"<<endl;
	cout<<v62;	
	cout<<"v61 - v62 ="<<endl;
	cout<<v61 - v62;
	cout<<"v61 - 10 ="<<endl;
	cout<<v61 - 10;
	cout<<"20 - v62 ="<<endl;
	cout<<20 - v62;
	
	cout<<"Vec<double> dv61:"<<endl;
	cout<<dv61;
	cout<<"Vec<double> dv62:"<<endl;
	cout<<dv62;
	cout<<"dv61 - dv62 ="<<endl;
	cout<<dv61 - dv62;
	cout<<"dv61 - 10.0 ="<<endl;
	cout<<dv61 - 10.0;
	cout<<"20.0 - dv62 ="<<endl;
	cout<<20.0 - dv62;
	
	cout<<"---operator *\n";
	cout<<"Vec<int> v61:"<<endl;
	cout<<v61;
	cout<<"Vec<int> v62:"<<endl;
	cout<<v62;	
	cout<<"v61 * v62 ="<<endl;
	cout<<v61 * v62<<endl;
	cout<<"v61 * 10 ="<<endl;
	cout<<v61 * 10;
	cout<<"20 * v62 ="<<endl;
	cout<<20 * v62;
	
	cout<<"Vec<double> dv61:"<<endl;
	cout<<dv61;
	cout<<"Vec<double> dv62:"<<endl;
	cout<<dv62;
	cout<<"dv61 * dv62 ="<<endl;
	cout<<dv61 * dv62<<endl;
	cout<<"dv61 * 10.0 ="<<endl;
	cout<<dv61 * 10.0;
	cout<<"20.0 * dv62 ="<<endl;
	cout<<20.0 * dv62;
	
	cout<<"---operator /"<<endl;
	cout<<"Vec<int> v61:"<<endl;
	cout<<v61;
	cout<<"Vec<int> v62:"<<endl;
	cout<<v62;	
	cout<<"v61 / v62 ="<<endl;
	cout<<v61 / v62<<endl;
	cout<<"v61 / 10 ="<<endl;
	cout<<v61 / 10;
	cout<<"20 / v62 ="<<endl;
	cout<<20 / v62;
	
	cout<<"Vec<double> dv61:"<<endl;
	cout<<dv61;
	cout<<"Vec<double> dv62:"<<endl;
	cout<<dv62;
	cout<<"dv61 / dv62 ="<<endl;
	cout<<dv61 / dv62<<endl;
	cout<<"dv61 / 10.0 ="<<endl;
	cout<<dv61 / 10.0;
	cout<<"20.0 / dv62 ="<<endl;
	cout<<20.0 / dv62;

	//norm

	vec v7 = {3};
	dvec dv7 = {3.001, 4.001};
	const vec v71 = {3,4};
	cout<<"const Vec<int> v71:"<<endl;
	v71.print();
	cout<<"v7.norm() = "<<v7.norm()<<endl;
	cout<<"dv7.norm() = "<<dv7.norm()<<endl;
	cout<<"const Vec v71 v71.norm() = "<<v71.norm()<<endl;
	cout<<"v7.print():\n";v7.print();
	cout<<"const v71.print():\n"; v71.print();

	vec v8 = {1,2,3};
	vec v9 = {4,5};
	dvec dv8 = {2.5, 4.5};
	dvec dv9 = {1.0, 2.0, 3.0};
	cout<<"---outer product"<<endl;
	cout<<"v8 ="<<endl<<v8;
	cout<<"v9 ="<<endl<<v9;
	cout<<"outer(v8, v9) ="<<endl;
	cout<<outer(v8, v9);
	cout<<"dv8 ="<<endl<<dv8;
	cout<<"dv9 ="<<endl<<dv9;
	cout<<"outer(dv8, dv9) ="<<endl;
	cout<<outer(dv8, dv9);
	
	vec v10 = {1,2,3,4,5,6};
	dvec dv10 = {1.2, 2.3, 3.4, 5.6};
	cout<<"---reshaping"<<endl;
	cout<<"v10 ="<<endl;
	cout<<v10;
	cout<<"dv10 ="<<endl;
	cout<<dv10;
	int i = 2, j = 3;
	cout<<"v10.reshape(2,3)"<<endl;
	cout<<v10.reshape(i,j);
	cout<<"dv10.reshape(2,2)"<<endl;
	cout<<dv10.reshape(2,2);
	
	
	//get_val
	
	vec v11 = {1};
	dvec dv11 = {1,2,3};
	const dvec dv111 = {4,5,6,7};
	cout<<"v11:\n"; cout<<v11;
	vector<int> vi11 = v11.get_val(); cout<<"vi11 = "; print_vec(vi11);
	cout<<"dv11:\n"; cout<<dv11;
	vector<double> vd11 = dv11.get_val(); cout<<"vd11 = " ;print_vec(vd11);
	cout<<"dv111:\n"; cout<<dv111;
	vector<double> vdv111 = dv111.get_val(); cout<<"vdv111 = "; print_vec(vdv111);

	
	//arange

	//vec v12 = arange(1, 10);
	vec v12 = arange(1, 10, 2);
	//dvec dv12 = arange(1.5, 9.7);
	dvec dv12 = arange(1.5, 9.9,2.5);
	cout<<"v12:\n"<<v12;
	cout<<"dv12:\n"<<dv12;

	//linspace
	
	dvec dv13 = linspace(5,4, 20);
	cout<<"dv13:\n"<<dv13;
	*/
	//count_zero
	
	vec v14 = {1,2,3,4,5, 0,3, 0};
	dvec dv14 = {1.2, 2.3, 10, 0.0,0};
	cout<<"v14:\n"<<endl<<v14;
	cout<<"v14.count_zero() = "<<v14.count_zero()<<endl;
	cout<<"dv14:\n"<<endl<<dv14;
	cout<<"dv14.count_zero() = "<<dv14.count_zero()<<endl;
	cout<<"dv14.count_nonzero() = "<<dv14.count_nonzero()<<endl;
	return 0;
}
