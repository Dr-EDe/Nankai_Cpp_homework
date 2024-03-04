#include<iostream>
using namespace std;


int main() {
	int m, i, a, b,c=0;
	cin >> m;
	for (i = m; i > 1; i--) {
		b = 1;
		for (a = i - 1; a > 1; a--) {
			if (i % a == 0) {	b = 0;}
		if (b==1) {
				cout << i << ' '; c++;
				if (c % 5 == 0)cout << endl;
		
			}
		}
	}

	system("pause");

	return 0;

}