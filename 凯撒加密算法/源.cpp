#include<iostream>
#include<string.h>

using namespace std;


int main() {
	int game = 0;
	cin >> game;//game为1为加密模式，game为2为解密模式
	char r[100];
	cin.get();
		cin.getline(r,100);
	if (game == 1) {
		int i = strlen(r);
		int a = strlen(r);
		for (i; i >= 1; i--) {
			if (r[i - 1] >= 65 && r[i - 1] <= 87) {
				r[i - 1] += 3;
			}
			else if (r[i - 1] > 87 && r[i - 1] <= 90) {
				r[i - 1] = r[i - 1] - 23;
			}
			else if (r[i - 1] >= 97 && r[i - 1] <= 119) {
				r[i - 1] += 3;
			}
			else if (r[i - 1] == 32) { r[i - 1] = r[i - 1]; }
			else { r[i - 1] = r[i - 1] - 23; }
		}//加密完成
		for (int j = 0; j <= a - 1; j++) {
			cout << r[j];
		}
	}
	else {
		int i = strlen(r);
		int a = strlen(r);
		for (i; i >= 1; i--) {
			if (r[i - 1] >= 68 && r[i - 1] <= 90) {
				r[i - 1] -= 3;
			}
			else if (r[i - 1] >=65  && r[i - 1] <= 67) {
				r[i - 1] = r[i - 1] + 23;
			}
			else if (r[i - 1] >= 100 && r[i - 1] <= 122) {
				r[i - 1] -= 3;
			}
			else if (r[i - 1] == 32) { r[i - 1] = r[i - 1]; }
			else { r[i - 1] = r[i - 1] +23; }
		}//解密完成
		for (int j = 0; j <= a - 1; j++) {
			cout << r[j];
		}

	}
	



	system("pause");

	return 0;

}