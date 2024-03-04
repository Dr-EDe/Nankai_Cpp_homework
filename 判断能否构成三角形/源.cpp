#include<iostream>
using namespace std;


int main() {
	int a = 0;
	int b = 0;
	int c = 0;
	cin >> a;
	cin >> b;
	cin >> c;



	if (a == b) {
		cout << "yes" << endl;
	}
	else if (b == c) {
		cout << "yes" << endl;
	}
	else if (a == c) {
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}
	system("pause");

	return 0;

}