#include<iostream>
using namespace std;
int eatpeach(int n) {
	int x = 1;
	for (int i = 0; i < n-1; i++) {
		x = (x + 2) * 2;
	}
	return x;
}

int main() {
	int n;
	cin >> n;
	cout << eatpeach(n);


	system("pause");

	return 0;

}