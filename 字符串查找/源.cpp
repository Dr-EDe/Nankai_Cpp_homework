#include<iostream>
using namespace std;


int main() {
	char arr[100]; char str[10];
	cin >> arr;
	cin >> str;
	int a = strlen(arr);
	int b = strlen(str);
	for (int i = 0; i <= a - b; i++) {
		if (arr[i] ==str[0]) {
				for (int d = 0; d <= b-1; d++) {
					if (arr[i+d] == str[d]) {
						cout << "1";
					}
					else {
						cout << "-1";
					}
				}
				
			}
		
	}

	system("pause");

	return 0;

}