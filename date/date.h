#include "std_lib_facilities.h"

enum class month {
	jan = 1, feb, mar, apr, may, jun, jul, aug, sept, oct, nov, dec
};

enum class day {
	monday, tuesday, wednesday, thursday, friday, saturday, sunday
};

class Date {
public:
	Date(int y, int m, int d);
	Date();
	void add_day(int n);
	void add_month();
	void add_year();
	void print_date();
	bool leap_year();
	int year() const { return y; }
	int month() const { return m; }
	int day() const { return d; }
	class Invalid{};
private:
	int y, m, d;
	bool is_valid();
};

ostream& operator<<(ostream& os, const Date& d);
/*
istream& operator>>(istream& is, Date& d);
*/
bool operator==(const Date& first, const Date& second);

bool operator!= (const Date& first, const Date second);