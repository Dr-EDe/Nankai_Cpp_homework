#include<iostream>
using namespace std;


int main() {
	char arr[100];
	cin >> arr;
	char* p = arr;
	while (*p != '\0') {
		for (char* p1 = p + 1; *p1 != '\0'; p1++) {
			if (*p1 == *p) {
				*p1 = '0';
			}
		}
		p++;
	}
	char* p2 = arr;
	while (*p2 != '\0') {
		if (*p2 != '0') {
			cout << *p2;
		}
		p2++;
	}

	system("pause");

	return 0;

}