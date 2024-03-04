#include<iostream>
using namespace std;


int main() {
	int i = 1,a=0;
	for (i; i <= 100; i++) {
		if (i % 7 == 0 || i / 10 == 7 || i % 10 == 7) {
			cout << i << ' '; a++;
		}if (a % 5 == 0) { cout << endl; }
	}


	system("pause");

	return 0;

}