#include<iostream>
using namespace std;


int main() {
	int n;
	cin >> n;
	char* str = new char[n];
	int* arr = new int[n];
	cin >> str;
	for (int i = 0; i < n; i++) {
		arr[i] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (str[i] + 32 == str[j] || str[i] - 32 == str[j]||str[j]==str[i]) {
				arr[i]++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (str[i] + 32 == str[j] || str[i] - 32 == str[j] || str[j] == str[i]) { str[j] = 0; }
		}
	}
	for (int i = 0; i < n; i++) {
		if (arr[i] > 1) { 
			if (str[i] < 97) { cout << char(str[i] + 32); }
			else { cout << str[i]; }
		}
	}


	system("pause");

	return 0;

}