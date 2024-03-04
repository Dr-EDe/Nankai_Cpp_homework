#include<iostream>
using namespace std;
int g(int x) {
	int a = 1;
	for (int i = x; i> 0; i--) {
		a *= i;
	}
	return a;
}
int f(int x);
int f(int x) {
	int sum = 0;
	for (int i = x; i > 0;i--) {
		sum += g(i);
	}
	return sum;
}

int main() {
	int n; cin >> n;
	cout << f(n);

	system("pause");

	return 0;

}