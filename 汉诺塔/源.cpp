
#include<iostream>
using namespace std;
void hanoi(int, char, char, char);

int main() {
	int n;
	cin >> n;
	hanoi(n, 'X', 'Y', 'Z');

	system("pause");

	return 0;

}
void move(int i, char A, char B) {
     cout << "Dish" << ' ' << i <<' ' << "from" << ' ' << A << ' ' << "to" << ' ' << B;
	 cout << endl;
}
void hanoi(int n, char a, char b, char c) {
	if (n == 1)  move(n, a, c);
	else {
		hanoi(n - 1, a, c, b);
		move(n, a, c); 
		hanoi(n - 1, b, a, c);
	}
}