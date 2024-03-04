#include<iostream>
using namespace std;


int main() {
	char arr[5];
	cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4];
	for (int i = 0; i <= 4; i++){
		if (arr[i] <= 90) {
			cout << (char)(arr[i] + 32);
		}
		else { cout << (char)(arr[i] - 32); }
	}
	

	system("pause");

	return 0;

}