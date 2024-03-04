#include<iostream>
using namespace std;


int main() {
	char arr[30];
	char* p = arr;
	cin >> arr;
	if (*p >= 97) {
		p++;
		while (*p != '\0') {
			if (*p >= 97) {
				*p -= 32;
			}
			p++;
			if (*p == '\0') { break; }
			if (*p < 97) {
				*p += 32;
			}
			p++;
		}
	}
	else {
		p++;
		while (*p != '\0') {
			if (*p < 97) {
				*p += 32;
			}
			p++;
			if (*p == '\0') { break; }
			if (*p >= 97) {
				*p -= 32;
			}
			p++;
		}
	}
	cout << arr;

	system("pause");

	return 0;

}