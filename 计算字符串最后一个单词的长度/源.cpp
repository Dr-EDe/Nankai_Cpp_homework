#include<iostream>
using namespace std;
#include <string>

int main() {
	char a[200];
	cin.getline(a, 200);
	char* p = a;
	while (*p != '\0') {
		p++;
	}
	char* p1 = p;
	while (*p1 != 32) {
		p1--;
	}
	cout << p - p1 - 1;

	system("pause");

	return 0;

}