#include<iostream>
using namespace std;
#include<algorithm>

int main() {
	int n; cin >> n;
	int* arr = new int[n];
	int* str = new int[n];
	int* target = new int[n * n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}
	int k = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			target[k] = arr[i] + str[j]; k++;
		}
	}
	for (int i = 0; i < n*n; i++) {
		for (int j = 0; j < n*n-i-1; j++) {
			if (target[j] > target[j + 1]) swap(target[j], target[j + 1]);
		}
	}
	for (int i = n * n -n; i < n * n ; i++) {
		cout << target[i] << ' ';
	}


	return 0;

}