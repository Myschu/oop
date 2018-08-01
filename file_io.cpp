#include "std_lib_facilities.h"

struct Reading {
	int num1;
	char sep1;
	double num2;
	char sep2;
	double num3;
};

int main() {
	cout << "Please enter input file name: ";
	string infile;
	cin >> infile;
	ifstream input{ infile };
	if (!input) error("can't open input file ", infile);

	string outfile;
	cout << "Please enter name of output file: ";
	cin >> outfile;
	ofstream output{ outfile };
	if (!output) error("can't open output file ", outfile);

	vector <Reading> temps;
	int num1;
	double num2;
	double num3;
	char sep1;
	char sep2;
	while (input >> num1 >> sep1 >> num2 >> sep2 >> num3) {
		if (num1 < 0 || 23 < num1) error("first out of range");
		temps.push_back(Reading{ num1, sep1, num2, sep2, num3 });
	}
	for (int i = 0; i<temps.size(); ++i)
		output << temps[i].num1 << '\t' << temps[i].num2 << '\t' << temps[i].num3 << '\n';
}