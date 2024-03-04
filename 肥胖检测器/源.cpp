#include<iostream>
using namespace std;


int main() {
	char name[100];
	int height;
	int weight;
	cin >> name >> height >> weight;
	if (weight > height - 105) {
		cout << name<< ", you are overweight!";
	}
	else {
		cout << name<< ", you are keeping the perfect figure!";
	}
	system("pause");

	return 0;

}