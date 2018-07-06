#include "std_lib_facilities.h"

int main() {
	cout << "Enter the name of the person you want to write to:\n";
	string first_name;
	cin >> first_name;
	
	cout << "Please enter a friend's name:\n";
	string friend_name;
	cin >> friend_name;
	
	cout << "Enter the age of the person:\n";
	int age;
	cin >> age;
	cout << "Dear " << first_name << "\n";
	cout << "Have you seen " << friend_name << " lately?\n";
	cout << "I hear you had a birthday and you are " << age << " years old!\n";
	if (age <= 0 || age >= 110) {
		simple_error("That's not true.\n");
	}
	if (age <= 17) {
		cout << "You are young to be at NYU!\n";
	}
	if (age >= 65) {
		cout << "It's great to see senior students around campus!\n";
	}
}
