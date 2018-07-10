#include "std_lib_facilities.h"

int main() {
	int i;
	vector<int> v;
	while (cin >> i) {
		v.push_back(i);
	}
	for (int i = 0;i < v.size();i++) {
		cout << v[i] << ' ';
	}
}
