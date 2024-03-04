#include<iostream>
using namespace std;


int main() {
	int a, b;
	cin >> a;
	int* arr = new int[a];
	for (int i = 0; i < a; i++) {
		cin >> arr[i];
	}
	cin >> b;
	int* str = new int[b];
	for (int i = 0; i < b; i++) {
		cin >> str[i];
	}
	int* goal = new int[a + b];
	for (int i = 0; i < a; i++) {
		goal[i] = arr[i];
	}
	for (int i = a; i < a + b; i++) {
		goal[i] = str[i-a];
    }
	for (int i = 0; i < a + b - 1; i++) {
		for (int j = 0; j < a + b - 1 - i; j++) {
			if (goal[j] >= goal[j + 1]) {
				int temp = goal[j];
				goal[j] = goal[j + 1];
				goal[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < a + b; i++) {
		cout << goal[i] << ' ';
	}
	
	system("pause");

	return 0;

}