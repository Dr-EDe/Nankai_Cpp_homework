#include<iostream>
using namespace std;


int main() {
	int n; cin >> n;
	char* arr = new char[n];
	int* str = new int[n];
	for (int i = 0; i <= n - 1; i++) {
		str[i] = 1;
	}
	cin >> arr;
 	for (int i = 0; i <= n - 1; i++) {
		if (arr[i] < 97) {
			for (int t = i + 1; t <= n - 1; t++) {
				if (arr[t] == arr[i] || arr[t] == arr[i] + 32) {
					str[i] = str[i] + 1;
				}
			}
		}
		if (arr[i] >=97) {
			for (int t = i + 1; t <= n - 1;t++) {
				if (arr[t] == arr[i] || arr[t] == arr[i] - 32) {
					str[i] = str[i] + 1;
				}
			}
		}
	}
	int max = str[0];
	for (int i = 1; i <= n - 1; i++) {
		if (str[i] > max) {
			max = str[i];
		}
	}
	for (int i = 0; i < n; i++) {
		if (str[i] == max) {
			if (arr[i] >= 97) {
				cout << arr[i];
				break;
			}
			cout << char(arr[i] + 32);
			break;
		}

	}


	system("pause");

	return 0;

}