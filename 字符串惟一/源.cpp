#include<iostream>
using namespace std;

int main() {
	int len; cin >> len;
	char* arr = new char[len];
	cin >> arr;
	char* str = new char[len];
	int step; cin >> step;
	step = step % len;
	if (step > 0) {
		int a = 0; 
		for (int i = len -step; i < len ; i++) {
			str[a] = arr[i]; a++;
		}
		for (int i = 0; i < len - step; i++) {
			str[a] = arr[i]; a++;
		}
		for (int i = 0; i < len; i++) {
			cout << str[i];
		}
	}
	else if (step == 0) {
		for (int i = 0; i < len; i++) {
			cout << arr[i];
		}
	}
	else {
		step = 0 - step;
		int a = 0;
		for (int i = step; i < len; i++) {
			str[a] = arr[i]; a++;
		}
		for (int i = 0; i < step; i++) {
			str[a] = arr[i]; a++;
		}
		for (int i = 0; i < len; i++) {
			cout << str[i];
		}
	}

	

	system("pause");

	return 0;

}