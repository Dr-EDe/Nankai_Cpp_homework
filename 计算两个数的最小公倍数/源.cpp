#include<iostream>
using namespace std;


int main() {
	int a, b, c, d, e;
	cin >> a >> b;
	if (a > b) {
		c = a; d = b;
	}
	else { c = b; d = a; }
	for (e = c;; e++) {
		if (e % c == 0 && e % d == 0)
			break;
	}cout << e;

	system("pause");

	return 0;

}