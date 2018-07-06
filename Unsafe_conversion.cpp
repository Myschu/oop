#include "std_lib_facilities.h"

int main() {
	double doub;
	cout << "Please enter a double: ";
	cin >> doub;
	int in = doub;
	char ch = doub;
	bool bo = doub;
	cout << "double to int: " << in << "\n";
	cout << "double to char: " << ch << "\n";
	cout << "double to bool: " << bo << "\n";
	int in2;
	cout << "Please enter an int: ";
	cin >> in2;
	char ch2 = in2;
	bool bo2 = in2;
	cout << "int to char: " << ch2 << "\n";
	cout << "int to bool: " << bo2 << "\n";
	char ch3;
	cout << "Please enter a char: ";
	cin >> ch3;
	bool bo3 = ch3;
	cout << "char to bool: " << bo3 << "\n";
}