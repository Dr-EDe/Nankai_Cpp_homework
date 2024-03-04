#include<iostream>
using namespace std;


int main() {
	char a;
	cin >> a;
	char arr[100];
	cin >> arr;
	for (char* p = arr; *p != '\0'; p++) {
		if (*p == a) {
			cout << endl;
			continue;
		}
		cout << *p;
	}

	system("pause");

	return 0;

}