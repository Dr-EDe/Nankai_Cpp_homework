#include<iostream>
using namespace std;
class Date {
private:
	int year;
	int month;
	int day;
public:
	bool isleapyear() {
		if (year % 400 == 0) { return true; }
		if (year % 4 == 0 && year % 100 != 0) { return true; }
		return false;
	}
	bool isright() {
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
			if (day > 31 || day < 1) {
				return false;
			}
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11) {
			if (day > 30 || day < 1) {
				return false;
			}
		}
		else if (month == 2) {
			if (isleapyear()) {
				if (day > 29 || day < 1) { return false; }
			}
			else {
				if (day > 28 || day < 1) {
					return false;
				}
			}
		}
		else { return false; }
		return true;
	}
	void caldays(){
		int i = 0;
		if (isright()) {
			if (month > 0) { i += day; }
			if (month > 1) { i += 31; }
			if (month > 2) { if (isleapyear()) { i += 29; } else { i += 28; } }
			if (month > 3) { i += 31; }
			if (month > 4) { i += 30; }
			if (month > 5) { i += 31; }
			if (month > 6) { i += 30; }
			if (month > 7) { i += 31; }
			if (month > 8) { i += 31; }
			if (month > 9) { i += 30; }
			if (month > 10) { i += 31; }
			if (month > 11) { i += 30; }
			cout << "The" << ' ' << i << "th" << ' ' << "day in" << ' ' << year;
		}
		else cout << "illegal input!" << endl << year << '-' << month << '-' << day;
	}
	Date() {
		cin >> year >> month >> day;
	}
};
int main() {
	Date date = Date();
	date.caldays();
}
