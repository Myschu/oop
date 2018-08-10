#include "std_lib_facilities.h"

class vect {
	int sz;
	double* elem;
public:
	vect(int s)
		:sz{ s }, elem{ new double[s] } {
	}
	vect(const vect& arg)
		:sz{ arg.sz }, elem{ new double[arg.sz] }
	{
		copy(arg.elem, arg.elem + arg.sz, elem);
	}
	~vect()
	{
		delete[] elem;
	}
	vect& operator=(const vect& a)
	{
		double* p = new double[a.sz];
		copy(a.elem, a.elem + a.sz, p);
		delete[] elem;
		elem = p;
		sz = a.sz;
		return *this;
	}
	double& operator[](int n) { return elem[n]; }
};


void f(int n)
{
	vect v(3);
	v[2] = 2.2;
	vect v2 = v;
	v[1] = 9.9;
	v2[0] = 8.8;
	cout << v[0] << ' ' << v2[1] << endl;
}

int main() {
	for (int i = 0; i < 10000;i++) {
		f(i);
	}
	return 0;
}