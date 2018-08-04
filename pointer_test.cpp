#include "std_lib_facilities.h"


int main() {
	char c = 'a';
	int i = 17;
	double d = 4.4;

	char* cp = &c;
	int* ip = &i;
	double* dp = &d;

	cout << "cp = " << cp << ", its value is: " << *cp << ", and its size is: " << sizeof(c) << endl;
	cout << "ip = " << ip << ", its value is: " << *ip << ", and its size is: " << sizeof(i) << endl;
	cout << "dp = " << dp << ", its value is: " << *dp << ", and its size is: " << sizeof(d) << endl;
}