#include "std_lib_facilities.h"

class Token {
public:
	char kind;
	double value;
};

class Token_stream {
public:
	Token get();
	void putback(Token t);
private:
	Token buffer;
	bool full = false;
};

void Token_stream::putback(Token t) {
	buffer = t;
	full = true;
}

Token Token_stream::get() {
	if (full) {
		full = false;
		return buffer;
	}
	char ch;
	cin >> ch;
	switch(ch){
	case';':
	case'q':
	case'(':
	case')':
	case'+':
	case '-': 
	case '/': 
	case '*': 
	case '%':
		return Token{ ch };
	case'.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9': 
	{
		cin.putback(ch);
		double val;
		cin >> val;
		return Token{ '8', val };
	}
	default:
		return Token{ 'i', double(ch) };
	}
	return Token{ 'q' };		
}

Token_stream ts;

int main() {
	Token t = ts.get();
	while (t.kind != 'q') {
		cout << "got token of kind " << t.kind << " with value of: " << t.value << endl;
		t = ts.get();
	}
}
