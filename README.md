This is a personal project, for educational purpose only!

About this project:
  1. C/C++ linear algebra project.
  2. Implements simple operations like maxtrix/vector addition, multiplication, ... The other operations like det, inv,... may be implemented later.
  3. The code is naive, non-optimized.

How to use:
```
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
return 0;
}

```
