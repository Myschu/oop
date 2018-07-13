#include "std_lib_facilities.h"

class Token {
public:
	char kind;
	double value;
};

void print_token(Token t) {
	cout << "Token.kind= " << t.kind << " Token.value=" << t.value << endl;
}

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
	switch (ch) {
	case';': case'q': case'(': case')': case'+':
	case '-': case '/': case '*': case '%':
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

double expression();
double term();
double primary();

double expression() {
	double left = term();
	Token t = ts.get();
	while (true) {
		switch (t.kind) {
		case'+':
			left += term();
			t = ts.get();
			break;
		case'-':
			left -= term();
			t = ts.get();
			break;
		default:
			ts.putback(t);
			return left;
		}
	}
}
double term() {
	double left = primary();
	Token t = ts.get();
	while (true) {
		switch (t.kind) {
		case'*':
			left *= primary();
			t = ts.get();
			break;
		case'/': {
			double d = primary();
			if (d == 0) error("divide by zero");
			left /= 0;
			t = ts.get();
			break;
			}
		default:
			ts.putback(t);
			return left;
		}
	}
}


double primary() {
	Token t = ts.get();
	switch (t.kind) {
	case'(': {
		double d = expression();
		t = ts.get();
		if (t.kind != ')') error("')' expected");
		return d;
		}
	case'8':
		return t.value;
	default:
		error("primary expected");
	}
}



int main() {
	/*
	Token t = ts.get();
	while (t.kind != 'q') {
	cout << "got token of kind " << t.kind << " with value of: " << t.value << endl;
	t = ts.get();
	}
	*/

	try {
		double val = 0.0;
		while (cin) {
			Token t = ts.get();
			cout << "in main(), got token: " << t.kind
				<< " with val of " << t.value << '\n';
			if (t.kind == 'q') break;
			if (t.kind == ';')
				cout << " = " << val << '\n';
			else
				ts.putback(t);
			val = expression();	
		}
	}
	catch (exception& e) {
		cerr << e.what() << '\n';
		return 1;
	}
	catch (...) {
		cerr << "exception \n";
		return 2;
	}
}
