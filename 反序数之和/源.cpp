#include<iostream>
using namespace std;


int main() {
	int n;
	cin >> n;
	int x = 0;
	int s = n;
	while (s > 0) {
		x = x * 10 + s % 10;
		s = s / 10;
	}
	cout << x + n;


	system("pause");

	return 0;

}