#include "std_lib_facilities.h"
#include "date.h"

void f(int x, int y)
try {
	Date dxy{ 2004,x,y };
	cout << dxy << '\n';
	dxy.add_day(2);
}
catch (Date::Invalid) {
	error("invalid date");
}


Date::Date(int yy, int mm, int dd)
	:y{ yy }, m{ mm }, d{ dd } {
	if (!is_valid()) throw Invalid();
}
/*
Date::Date() : y(0), m(0), d(0) {
	if (!is_valid()) throw Invalid();
}
*/
bool Date::leap_year() {
	if (y % 4 == 0)
		return true;
	else
		return false;
}

void Date::add_day(int n) {
	switch (m) {
	case 12:
	{
		if (d == 31) {
			y++;
			m = 1;
			d = 1;
			return;
		}
		else {
			d++;
			return;
		}
	}

	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	{
		if (d == 31) {
			m++;
			d = 1;
			return;
		}
		else {
			d++;
			return;
		}
	}

	case 4:
	case 6:
	case 9:
	case 11:
	{
		if (d == 30) {
			m++;
			d = 1;
			return;
		}
		else {
			d++;
			return;
		}
	}
	case 2:
	{
		if (leap_year())
			if (d == 29) {
				m++;
				d = 1;
				return;
			}
			else {
				d++;
				return;
			}
		else {
			if (d == 28) {
				m++;
				d = 1;
				return;
			}
			else {
				d++;
				return;
			}
		}
	}
	}

}

void Date::add_month() {
	switch (m) {
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
	case 10:
	case 11:
	{
		m++;
		return;
	}
	case 12:
	{
		y++;
		m = 1;
		return;
	}
	}
}

void Date::add_year() {
	y++;
	return;
}


bool Date::is_valid() {
	if (int(m) < 1 || int(m) > 12)
	return false;
	return true;

	switch (m) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (d < 1 || d > 31) {
			return false;
		}
	case 4:
	case 6:
	case 9:
	case 11:
		if (d < 1 || d > 30) {
			return false;
		}
	case 2:
		if (d < 1 || d > 29) {
			return false;
		}

	}
	return true;
}

void Date::print_date() {
	switch (m) {
	case 1:
		cout << "January ";
		break;
	case 2:
		cout << "February ";
		break;
	case 3:
		cout << "March ";
		break;
	case 4:
		cout << "April ";
		break;
	case 5:
		cout << "May ";
		break;
	case 6:
		cout << "June ";
		break;
	case 7:
		cout << "July ";
		break;
	case 8:
		cout << "August ";
		break;
	case 9:
		cout << "September ";
		break;
	case 10:
		cout << "October ";
		break;
	case 11:
		cout << "November ";
		break;
	case 12:
		cout << "December ";
		break;
	}
	cout << day() << ", " << year() << endl;
}


ostream& operator<<(ostream& os, const Date& d) {
	return os << '(' << d.year() << ", " << d.month() << ", " << d.day() << ')';
}
/*
istream& operator>>(istream& is, const Date& d) {
	is >> d.year() >> d.month() >> d.day();
	return is;
}
*/

bool operator==(const Date& first, const Date& second) {
	if (first.year() == second.year() && first.month() == second.month() && first.day() == second.day()) {
		return true;
	}
	return false;
} 

bool operator != (const Date& first, const Date& second) {
	if (first.year() == second.year() && first.month() == second.month() && first.day() == second.day())
		return false;
	else
		return true;
}