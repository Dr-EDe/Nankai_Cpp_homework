#include<iostream>
using namespace std;


int main() {
	char a;
	cin >> a;
	if (a >= 97&&a<=122) {
		a = a - 32;
		cout << "" << a << endl;
	}
	else if (a<=90&&a>=65){
		a = a + 32;
		cout << "" << a << endl;
	}
	else { cout << "no" << endl; }
	system("pause");

	return 0;

}