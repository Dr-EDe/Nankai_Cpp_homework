#include<iostream>
using namespace std;


int main() {
	int IQ = 0;
	cout << "请输入你的IQ" << endl;
	cin >> IQ;
	cout << "你的IQ为" << IQ << endl;
	if (IQ > 140) {
		cout << "你可真是个天才" << endl;
	}
	else {
		cout << "你就是个垃圾" << endl;
	}
	system("pause");

	return 0;

} 