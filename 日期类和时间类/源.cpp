#include  <iostream>
#include  <cmath>
#include  <iomanip>
using  namespace  std;
class Date;
class Time {
	int hour, minute, second;
public:
	Time(int a, int b, int c) {
		hour = a; minute = b; second = c;
	}
	friend void display(const Date& b, const Time& a);
};
class Date {
	int year, month, day;
public:
	Date(int a, int b, int c) {
		year = a; month = b; day= c;
	}
	friend void display(const Date& b, const Time& a);
};
void display(const Date& b, const Time& a) {
	cout << b.year << '/' << b.month << '/' << b.day << endl;
	cout << a.hour << ':' << a.minute << ':' << a.second;
}
int main() {
	int  year, month, day;
	cin >> year >> month >> day;
	Date  d1(year, month, day);

	int  hour, minute, second;
	cin >> hour >> minute >> second;
	Time  t1(hour, minute, second);

	display(d1, t1);
	system("pause");
	return  0;
}
