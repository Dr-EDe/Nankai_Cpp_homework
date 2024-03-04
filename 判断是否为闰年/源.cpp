#include<iostream>
using namespace std;


int main() {
	int a = 0;
	cin >> a;
	int b = 0;
	b = a % 4;
	int c = 0;
	c = a % 100;
	int d = 0;
	d = a %400 ;
	if (d == 0) {
		cout << "yes" << endl;
	}
	else if (b == 0 && c != 0) {
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}
	system("pause");

	return 0;
}