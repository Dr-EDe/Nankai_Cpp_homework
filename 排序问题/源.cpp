#include<iostream>
using namespace std;


int main() {
	int n; cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (arr[j] >= arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	for (int a = 0; a < n; a++) {
		cout << arr[a] << ' ';
	}

	int start = 0; int end = n - 1;
	do {
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++; end--;
	}
	while(start < end);
	cout << endl;
	for (int a = 0; a < n; a++) {
		cout<< arr[a] << ' ';
	}



	system("pause");

	return 0;

}