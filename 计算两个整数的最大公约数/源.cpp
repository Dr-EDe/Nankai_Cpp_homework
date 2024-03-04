#include<iostream>
using namespace std;


int main() {
	int a, b,c,d,e;
	cin >> a>>b;
	if (a > b) {
		c = b; d = a;
	}
	else { c = a; d = b; }
	for (e=c; e >= 1; e--) {
		if (d % e == 0&&c%e==0) {
			cout << e;
			break;
		}
	}
	system("pause");

	return 0;

}