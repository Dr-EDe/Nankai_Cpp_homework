#include<iostream>
using namespace std;


int main() {
	int arr[5];
	int max = 0;
	for (int i = 0; i <= 4; i++) {
		cin >> arr[i];
		if (arr[i] >= max) {
			max = arr[i];
		}
	}cout << max;


	system("pause");

	return 0;

}