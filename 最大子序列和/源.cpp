#include<iostream>
using namespace std;

int func(int arr[], int i, int j);
int func(int arr[], int i, int j) {
	if (i == j) { return arr[i]; }
	else {
		int sum = 0;
		for (int b = i; b <= j;b++) {
			sum += arr[b];
		}
		return sum;
	}
}
int main() {
	int n; cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int a = (n * n + n) / 2;
	int b = 0;
	int* str = new int[a];
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			str[b] = func(arr,i, j);
			b++;
		}
	}
	int max = str[0];
	for (int i = 0; i < a; i++) {
		if (str[i] > max) { max = str[i]; }
	}
	cout << max;
	system("pause");

	return 0;

}