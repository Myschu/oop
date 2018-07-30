#include "std_lib_facilities.h"
#include "date.h"

int main() {
	/*
	cout << "Please enter a date in format(YYYY,MM,DD): ";
	*/
	Date today(2018, 7, 25);
	/*
	cin >> today;
	*/
	Date tomorrow(2018, 7, 26);
	cout << today << endl;
	string input = "";


	cout << "Enter 'd' to incrament the day, 'm' to incrament the month or 'y' to incrament the year. \nEnter 'e' to compare dates with todays date or enter 'q' to quit.\n";
	while (input != "q") {
		cin >> input;
		if (input == "d") {
			today.add_day(0);
		}
		else if (input == "m") {
			today.add_month();
		}
		else if (input == "y") {
			today.add_year();
		}
		else if (input == "e") {
			cout << "Checking today's date: " << today << " against tomorrow's date: " << tomorrow << " Results printed below:\n";
			if (today == tomorrow) {
				cout << "The dates match\n";
			}
			else {
				cout << "The dates do not match\n";
			}
		}
		cout << today << endl;
	}
	today.print_date();
	return 0;
}