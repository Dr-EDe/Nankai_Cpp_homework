#include<iostream>
using namespace std;


int main() {
	int m = 0;
	cin >> m;
	int a, b, c;
	int d = 0;
	for (a = 2; a <= m; a++) {
		c = 1;
		for (b = a - 1; b > 1; b--)
			if (a % b == 0)c = 0;
		
		if (c == 1) {
			 d++;
			cout << a << ' ';
			if (d % 5 == 0)cout << endl;
		}
	}
		
	system("pause");

	return 0;

}