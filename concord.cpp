#include "std_lib_facilities.h"

int main() {
	vector<string> text;
	for (string word; cin >> word; )
		text.push_back(word);
	sort(text);
	int index = 1;
	string prev = text[0];
	int count = 1;
	while (index < text.size()) {
		if (text[index] == prev) {
			count++;
		}
		else {
			cout << prev << ": " << count << endl;
			prev = text[index];
			count = 1;
		}
		index++;
	}
	cout << prev << ": " << count << endl;
	return 0;
}
