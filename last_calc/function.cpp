#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <string>
#include "function.h"

using namespace std;

std::map <const string, std::function<double(double)> >dispTable {
	{ "sin", [](double a) { return sin(a); } },
	{ "cos", [](double a) { return cos(a); } },
	{ "tan", [](double a) { return tan(a); } },
	{ "asin", [](double a) { return asin(a); } },
	{ "acos", [](double a) { return acos(a); } },
	{ "atan", [](double a) { return atan(a); } },
	{ "log", [](double a) { return log(a); } },
	{ "log2", [](double a) { return log2(a); } },
	{ "log10", [](double a) { return log10(a); } },
};

double exec_func(string funcname, double arg) {
	try {
		return dispTable[funcname](arg);
	}
	catch (exception) {
		cout << "Error: Undefined function " << funcname << '\n';
	}
	return 0.0;
}
