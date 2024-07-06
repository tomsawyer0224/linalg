#include <iostream>
#include <vector>
#include <list>
#include <initializer_list>
#include <string>
#include <cstdbool>

#include "blas.h"
#include "blas_bits/utils.h"
typedef Mat<int> mat;
typedef Mat<double> dmat;

typedef Vec<int> vec;
typedef Vec<double> dvec;

using namespace std;
int main(){
	//test Vec
	//constructors
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
	
	vec v7 = {3};
	dvec dv7 = {3.001, 4.001};
	const vec v71 = {3,4};
	cout<<"const Vec<int> v71:"<<endl;
	v71.print();
	cout<<"v7.norm() = "<<v7.norm()<<endl;
	cout<<"dv7.norm() = "<<dv7.norm()<<endl;
	cout<<"const Vec v71 v71.norm() = "<<v71.norm()<<endl;
	return 0;
}
