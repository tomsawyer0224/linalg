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

int main(){
	//constructors
	/*
	cout<<"--constructor with nothing"<<endl;
	mat m1;
	const dmat dm1;
	cout<<"cout<<m1:"<<endl;
	cout<<m1;
	cout<<"m1.print():"<<endl; m1.print();
	cout<<"m1.get_attr(): "; m1.get_attr(); cout<<endl;
	cout<<"cout<<dm1:"<<endl;
	cout<<dm1;
	cout<<"dm1.print():"<<endl; dm1.print();
	cout<<"dm1.get_attr(): "; dm1.get_attr(); cout<<endl;

	

	cout<<"--constructor with n_rows, n_cols"<<endl;
	//const int i = 2, j = 3;
	//int i = 2, j = 0;
	//int i = -2, j = 0;
	//int i = 0, j = 0;
	//int i = -2, j = -3;
	//int i = 1, j = 3;
	int i = 2, j = 3;
	mat m2(i, j);
	const dmat dm2(j, i);
	cout<<"cout<<m2:"<<endl;
	cout<<m2;
	cout<<"m2.print():"<<endl; m2.print();
	cout<<"m2.get_attr(): "; m2.get_attr(); cout<<endl;
	cout<<"cout<<dm2:"<<endl;
	cout<<dm2;
	cout<<"dm2.print():"<<endl; dm2.print();
	cout<<"dm2.get_attr(): "; dm2.get_attr(); cout<<endl;



	cout<<"--constructor with std::vector<std::vector>"<<endl;
	//vector<vector<int>> vi3 = {{}};
	//vector<vector<double>> vd3 = {{},{}};
	//vector<vector<int>> vi3 = {{1}};
	//vector<vector<double>> vd3 = {{1.7,2.0}};
	//vector<vector<int>> vi3 = {{1},{2, 3}};
	//vector<vector<double>> vd3 = {{1.7,2.0}};
	vector<vector<int>> vi3 = {{1,2},{3,4},{5,6}};
	vector<vector<double>> vd3 = {{1.2, 2.3, 3.4567},{67890.4345435435, 1.8, 1.9}};
	mat m3(vi3);
	const dmat dm3(vd3);
	cout<<"cout<<m3:"<<endl;
	cout<<m3;
	cout<<"m3.print():"<<endl; m3.print();
	cout<<"m3.get_attr(): "; m3.get_attr(); cout<<endl;
	cout<<"cout<<dm3:"<<endl;
	cout<<dm3;
	cout<<"dm3.print():"<<endl; dm3.print();
	cout<<"dm3.get_attr(): "; dm3.get_attr(); cout<<endl;

	

	cout<<"--constructor with Vec"<<endl;
	//vec v4 = {};
	//dvec dv4 = {};
	vec v4 = {1,2,3,4,5};
	dvec dv4 = {2.8};
	mat m4(v4);
	const dmat dm4(dv4);
	cout<<"cout<<m4:"<<endl;
	cout<<m4;
	cout<<"m4.print():"<<endl; m4.print();
	cout<<"m4.get_attr(): "; m4.get_attr(); cout<<endl;
	cout<<"cout<<dm4:"<<endl;
	cout<<dm4;
	cout<<"dm4.print():"<<endl; dm4.print();
	cout<<"dm4.get_attr(): "; dm4.get_attr(); cout<<endl;

	

	cout<<"--constructor with Mat"<<endl;
	//const mat m51(2,3);
	//dmat dm51(3,2);
	//mat m51(2,0);
	//dmat dm51(0,2);
	//mat m51(-2,0);
	//dmat dm51(0,2);
	mat m51({{1,2,3},{4,5,6}});
	dmat dm51({{1.6, 2.3, 4.5},{1.2, 2.4, 5.6}});
	mat m5(m51);
	const dmat dm5(dm51);
	cout<<"cout<<m5:"<<endl;
	cout<<m5;
	cout<<"m5.print():"<<endl; m5.print();
	cout<<"m5.get_attr(): "; m5.get_attr(); cout<<endl;
	cout<<"cout<<dm5:"<<endl;
	cout<<dm5;
	cout<<"dm5.print():"<<endl; dm5.print();
	cout<<"dm5.get_attr(): "; dm5.get_attr(); cout<<endl;

	

	cout<<"--constructor with std::initializer_list<std::initializer_list>"<<endl;
	mat m61 = {{1,2,3},{4,5,6}};
	dmat dm61 = {{1.6, 2.3, 4.5},{1.2, 2.4, 5.6}};
	//mat m61 = {{}};
	//dmat dm61 = {{},{},{}};
	mat m6(m61);
	const dmat dm6(dm61);
	cout<<"cout<<m6:"<<endl;
	cout<<m6;
	cout<<"m6.print():"<<endl; m6.print();
	cout<<"m6.get_attr(): "; m6.get_attr(); cout<<endl;
	cout<<"cout<<dm6:"<<endl;
	cout<<dm6;
	cout<<"dm6.print():"<<endl; dm6.print();
	cout<<"dm6.get_attr(): "; dm6.get_attr(); cout<<endl;

	
	//subscript overloading

	mat m7 = {{1,2,3},{4,5,6},{7,8,9}};
	const dmat dm7 = {{1.0, 2.3},{4.5, 6.7}};
	cout<<"---before changing---"<<endl;
	cout<<"cout<<m7:"<<endl;
	cout<<m7;
	cout<<"m7.print():"<<endl; m7.print();
	cout<<"m7.get_attr(): "; m7.get_attr(); cout<<endl;
	cout<<"cout<<dm7:"<<endl;
	cout<<dm7;
	cout<<"dm7.print():"<<endl; dm7.print();
	cout<<"dm7.get_attr(): "; dm7.get_attr(); cout<<endl;
	
	
	cout<<"---after changing---"<<endl;
	m7[1][2] = 100;
	//m7[-1][0] = 100;
	//m7[1][-1] = 100;-->accessing vector m7[1] is right, but m7[1][-1] (vector[-1]) is not accepted
	//m7[0] = {111, 222, 333};
	m7[0] = {111, 222};//in this case m7[0][0], m7[0][1] are modified
	//m7[0] = {111, 222, 66, 77, 88};//in this case m7[0][0], m7[0][1], m7[0][2] are modified
	//m7[1][10] = 100;//column index out of range but nothing is happened
	//m7[10][1] = 100;
	cout<<"cout<<m7:"<<endl;
	cout<<m7;
	//dm7[0][0] = 100;//error because of assigning value to const Mat
	//dm7[0] = {1,2};//error
	cout<<"dm7[0][0] = "<<dm7[0][0]<<endl;
	cout<<"dm7[0] = ";
	for(int i = 0; i < dm7[0].size(); i++){
		cout<<dm7[0][i]<<" ";
	}

	
	//transpose

	//mat m8 = {{1,2,3,5},{4,5,6,8},{7,8,9,3}};
	//dmat dm8 = {{1.0},{4.5}};
	//mat m8 = {{},{},{}};
	//dmat dm8 = {{}};
	mat m8(3,0);
	dmat dm8(0,4);
	
	cout<<"cout<<m8:"<<endl;
	cout<<m8;
	cout<<"m8.print():"<<endl; m8.print();
	cout<<"m8.get_attr(): "; m8.get_attr(); cout<<endl;
	mat m8_t = m8.t();
	cout<<"m8.t():"<<endl; 
	cout<<m8_t;
	cout<<"m8_t.get_attr(): " ; m8_t.get_attr(); cout<<endl;
	cout<<"cout<<dm8:"<<endl;
	cout<<dm8;
	cout<<"dm8.print():"<<endl; dm8.print();
	cout<<"dm8.get_attr(): "; dm8.get_attr(); cout<<endl;
	dmat dm8_t = dm8.t();
	cout<<"dm8.t():"<<endl; 
	cout<<dm8_t;
	cout<<"dm8_t.get_attr(): " ; dm8_t.get_attr(); cout<<endl;

	
	//flatten

	mat m9 = {{1,2,3},{4,5,6},{7,8,9}};
	dmat dm9 = {{1.0, 2.3},{4.5, 6.7}};
	cout<<"cout<<m9:"<<endl;
	cout<<m9;
	cout<<"m9.print():"<<endl; m9.print();
	cout<<"m9.get_attr(): "; m9.get_attr(); cout<<endl;
	cout<<"m9.flatten():"<<endl;
	vec m9_f = m9.flatten();
	cout<<m9_f;
	cout<<"cout<<dm9:"<<endl;
	cout<<dm9;
	cout<<"dm9.print():"<<endl; dm9.print();
	cout<<"dm9.get_attr(): "; dm9.get_attr(); cout<<endl;
	cout<<"dm9.flatten():"<<endl;
	dvec dm9_f = dm9.flatten();
	cout<<dm9_f;

	
	//---op +

	mat m101 = {{1,2,3},{3,4,5}};
	mat m102 = {{5,6,7},{7,8,9}};
	
	dmat dm101 = {{1.5,2.0},{3.5,4.5}};
	dmat dm102 = {{5.0,6.5},{7.6,8.0}};
	
	cout<<"m101:"<<endl; cout<<m101;
	cout<<"m102:"<<endl; cout<<m102;
	cout<<"m101 + m102:"<<endl; cout<<m101+m102;
	
	cout<<"dm101:"<<endl; cout<<dm101;
	cout<<"dm102:"<<endl; cout<<dm102;
	cout<<"dm101 + dm102:"<<endl; cout<<dm101+dm102;
	
	int i101 = 4;
	double d101 = 2.5;
	cout<<"i101 = "<<i101<<endl;
	cout<<"m101:"<<endl; cout<<m101;
	cout<<"i101 + m101:"<<endl; cout<<i101 + m101;
	
	cout<<"dm101:"<<endl; cout<<dm101;
	cout<<"d101 = "<<d101<<endl;
	cout<<"dm101 + d101:"<<endl; cout<<dm101 + d101;
	
	vec v101 = {3,4};
	dvec dv101 = {1.5, 2.5};
	cout<<"v101 = \n"<<v101<<endl;
	cout<<"m101:"<<endl; cout<<m101;
	cout<<"v101 + m101:"<<endl; cout<<v101+m101;
	
	cout<<"dm101:"<<endl; cout<<dm101;
	cout<<"dv101 = \n"<<dv101<<endl;
	cout<<"dm101 + dv101:"<<endl; cout<<dm101 + dv101;

	
	//---op -

	mat m111 = {{1,2,3},{3,4,5}};
	mat m112 = {{5,6,7},{7,8,9}};
	
	dmat dm111 = {{1.5,2.0},{3.5,4.5}};
	dmat dm112 = {{5.0,6.5},{7.6,8.0}};
	
	cout<<"m111:"<<endl; cout<<m111;
	cout<<"m112:"<<endl; cout<<m112;
	cout<<"m111 - m112:"<<endl; cout<<m111-m112;
	
	cout<<"dm111:"<<endl; cout<<dm111;
	cout<<"dm112:"<<endl; cout<<dm112;

	cout<<"dm111 - dm112:"<<endl; cout<<dm111-dm112;
	
	int i111 = 4;
	double d111 = 2.5;

	//m111 = {{},{}};
	cout<<"i111 = "<<i111<<endl;
	cout<<"m111:"<<endl; cout<<m111;
	cout<<"i111 - m111:"<<endl; cout<<i111 - m111;
	//dm111 = {{},{}};
	cout<<"dm111:"<<endl; cout<<dm111;
	cout<<"d111 = "<<d111<<endl;
	cout<<"dm111 - d111:"<<endl; cout<<dm111 - d111;
	
	vec v111 = {3,4};
	dvec dv111 = {1.5, 2.5};
	
	//v111 = {};
	//m111 = {{}};
	cout<<"v111 = \n"<<v111<<endl;
	cout<<"m111:"<<endl; cout<<m111;
	cout<<"v111 - m111:"<<endl; cout<<v111-m111;
	//dv111 = {{},{}}; -> it will create a Vec [0, 0]
	cout<<"dm111:"<<endl; cout<<dm111;
	cout<<"dv111 = \n"<<dv111<<endl;
	cout<<"dm111 - dv111:"<<endl; cout<<dm111 - dv111;

	
	//---op *

	mat m121 = {{1,2,3},{3,4,5}};
	mat m122 = {{5,6,7},{7,8,9},{10,11,12}};
	//mat m122 = {{5},{7},{10}};
	dmat dm121 = {{1.5,2.0},{3.5,4.5}};
	dmat dm122 = {{5.0,6.5},{7.6,8.0}};

	cout<<"m121: "<<endl; cout<<m121;
	cout<<"m122:"<<endl; cout<<m122;
	cout<<"m121 * m122:"<<endl; cout<<m121*m122;

	cout<<"dm121:"<<endl; cout<<dm121;
	cout<<"dm122:"<<endl; cout<<dm122;
	cout<<"dm121 * dm122:"<<endl; cout<<dm121*dm122;

	int i121 = 4;
	double d121 = 2.5;

	//m121 = {{},{}};

	cout<<"i121 = "<<i121<<endl;
	cout<<"m121:"<<endl; cout<<m121;
	cout<<"i121 * m121:"<<endl; cout<<i121 * m121;

	//dm121 = {{},{}};
	cout<<"dm121:"<<endl; cout<<dm121;
	cout<<"d121 = "<<d121<<endl;
	cout<<"dm121 * d121:"<<endl; cout<<dm121 * d121;
	
	vec v121 = {3,4};
	dvec dv121 = {1.5, 2.5};

	//v121 = {};
	//m121 = {{}};
	cout<<"v121 = \n"<<v121<<endl;
	cout<<"m121:"<<endl; cout<<m121;
	cout<<"v121 * m121:"<<endl; cout<<v121*m121;
	
	//dv121 = {};//{{},{}}; //-> it will create a Vec [0, 0]
	cout<<"dm121:"<<endl; cout<<dm121;
	cout<<"dv121 = \n"<<dv121<<endl;
	cout<<"dm121 * dv121:"<<endl; cout<<dm121 * dv121;

	
	//norm
	mat m131 = {{3,2,1},{4,4,5}};
	dmat dm131 = {{4.5, 5.5, 6.5,7.5},{1.2, 2.3, 3.4, 4.5}};
	const dmat dm132 = {{1.9},{2.5},{3.0}};
	cout<<"m131:"<<endl; cout<<m131;
	cout<<"m131.norm() = "<<m131.norm()<<endl;
	cout<<"dm131:"<<endl; cout<<dm131;
	cout<<"dm131.norm() = "<<dm131.norm()<<endl;
	cout<<"dm132:"<<endl; cout<<dm132;
	cout<<"dm132.norm() = "<<dm132.norm();
	*/
	/*
	dmat A_lin = linspace(1,900, 200000).reshape(500,400);
	cout<<A_lin<<endl;
	dmat B_lin = linspace(2.0, 1100., 360000).reshape(400,900);
	cout<<B_lin<<endl;
	cout<<A_lin*B_lin<<endl;
	*/
	
	//swap
	/*
	cout<<"swap"<<endl;

	mat A_sw = {{1,2,3}, {4,5,6}, {7,8,9}};
	cout<<"before swap_row(0,2):\n"; cout<<A_sw;
	A_sw.swap_row(0,2);
	cout<<"after swap_row(0,2):\n"; cout<<A_sw;

	mat A_sw = {{1,2,3}, {4,5,6}, {7,8,9}};
	cout<<"before swap_row(-2,-1) <=> (1, 2):\n"; cout<<A_sw;
	A_sw.swap_row(-2,-1);
	cout<<"after swap_row(-2,-1) <=> (1, 2):\n"; cout<<A_sw;

	mat A_sw = {{1,2,3}, {4,5,6}, {7,8,9}};
	cout<<"before swap_row(0,-2) <=> (0, 1):\n"; cout<<A_sw;
	A_sw.swap_row(0,-2);
	cout<<"after swap_row(0,-2) <=> (0, 1):\n"; cout<<A_sw;
		

	dmat B_sw = {{10,20,30}, {40,50,60}, {70,80,90}};
	cout<<"before swap_col(0,2):\n"; cout<<B_sw;
	B_sw.swap_col(0,2);
	cout<<"after swap_col(0,2):\n"; cout<<B_sw;

	dmat B_sw = {{10,20,30}, {40,50,60}, {70,80,90}};
	cout<<"before swap_col(-1,-2) <=> (2,1):\n"; cout<<B_sw;
	B_sw.swap_col(-1,-2);
	cout<<"after swap_col(-1,-2) <=> (2,1):\n"; cout<<B_sw;	

	dmat B_sw = {{10,20,30}, {40,50,60}, {70,80,90}};
	cout<<"before swap_col(-2,2) <=> (1,2):\n"; cout<<B_sw;
	B_sw.swap_col(-2,2);
	cout<<"after swap_col(-2,2) <=> (1,2):\n"; cout<<B_sw;
	*/
	
	//row(), col()
	/*
	mat A_rc = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	
	cout<<"A_rc:\n"<<A_rc;
	int b = 0, e = -1;
	cout<<"A_rc.row("<<b<<","<<e<<"):\n"<<A_rc.row(b,e);

	cout<<"A_rc:\n"<<A_rc;
	int b = 1, e = 2;
	cout<<"A_rc.col("<<b<<","<<e<<"):\n"<<A_rc.col(b,e);
	*/
	//one_row(), one_col()
	/*
	mat A_rc = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	cout<<"A_rc:\n"<<A_rc;
	int row = 4;
	cout<<"A_rc.one_row("<<row<<"):\n"<<A_rc.one_row(row);
	
	mat A_rc = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	cout<<"A_rc:\n"<<A_rc;
	int col = -1;
	cout<<"A_rc.one_col("<<col<<"):\n"<<A_rc.one_col(col);
	*/
	
	//concatenate
	/*
	mat A_concat = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	mat B_concat = {{101,102,103,104},{111,112,113,114},{121,122,123,124},{1,3,5,7}};
	//mat B_concat = {{101,102,103},{111,112,113},{121,122,123},{1,3,5}};
	cout<<"A_concat:\n"<<A_concat<<endl;
	cout<<"B_concat:\n"<<B_concat<<endl;
	cout<<"concatenate(A_concat, B_concat, 0):\n"<<concatenate(A_concat, B_concat, 0)<<endl;
	*/
	/*
	cout<<identity<int>(5)<<endl;
	cout<<identity<double>(5)<<endl;
	cout<<identity<float>(5)<<endl;
	
	cout<<zeros<int>(5,3)<<endl;
	cout<<zeros<double>(2,4)<<endl;
	
	cout<<ones<int>(3,5)<<endl;
	cout<<ones<double>(4,3)<<endl;
	*/
	return 0;
}
