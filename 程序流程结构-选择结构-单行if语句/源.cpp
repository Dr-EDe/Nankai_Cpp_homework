#include<iostream>
using namespace std;


int main() {
	//选择结构中的单行语句if

	//用户输入IQ，如果IQ>120,则为天才

	//用户输入
	int IQ = 0;
	cout << "请输入你的IQ" << endl;
	cin >> IQ;
	
	//显示用户输入
	cout << "你的IQ是" << IQ << endl;
	//判断分数
	if (IQ > 120) {
		cout << "你是天才" << endl;
	}//注意事项if后面不能加；











	system("pause");
	return 0;


}