#include<iostream>
#include<iomanip>
using namespace std;
int main() {
	float h; cin >> h;
	int n; cin >> n;
	float s = h; float S = 2 * h;
	for (int i = 1; i <= n; i++) {
		h = h / 2;
		if (i > 1) {
			S = S / 2;
			s = s + S;
		}
	}
	cout << setiosflags(ios::fixed);
	cout << setprecision(2) << h << endl;
	cout << setprecision(2) << s << endl;
	system("pause");

	return 0;

}