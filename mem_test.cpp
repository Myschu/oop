#include "std_lib_facilities.h"

int main() {
	int i = 0;
	while (true) {
		double* dptr = new double[10000];
		cout << "loop " << i << ": dptr[0]= " << dptr[0] << endl;
		i++;
	}
}