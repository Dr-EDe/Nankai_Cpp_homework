#include<iostream>
using namespace std;


int main() {
	char n;
	cin >> n;
	if (n == 65 || n == 97) {
		cout << 4;
	}
	else if (n == 66 || n == 98) {
		cout << 3;
	}
	else if (n == 67 || n == 99) {
		cout << 2;
	}
	else if (n == 68 || n == 100) {
		cout << 1;
	}
	else if (n == 69 || n == 101) {
		cout << 0;
	}
	else cout << "error";

	system("pause");

	return 0;

}