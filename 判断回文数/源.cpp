#include<iostream>
using namespace std;


int main() {
	int n;
	cin >> n;
	int x = 0;
	int s = n;
	for (; s > 0;) {
		x = x * 10 + s % 10;
		s = s / 10;
	}
	if (x == n) {
		cout << "yes";
	}
	else { cout << "no"; }
	system("pause");

	return 0;

}