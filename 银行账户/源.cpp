#include<iostream>  
using  namespace  std;
class  Account
{
private :
    int money;
public:
    void debit(int a) {
        if (money - a < 0) { cout << "Debit amount exceeded account balance." << endl; }
        else money -= a;
    }
    void credit(int a) {
        money += a;
    }
    int getBalance() {
        if (money < 0) { cout << "Error:Initial balance cannot be negative." << endl; money = 0; return money; }
        else return money;
    }
    Account(int a) {
        money = a;
    }
};

int  main()
{
    Account  account1(50);

    int  withdrawalAmount;
    cin >> withdrawalAmount;
    cout << "attempting  to  subtract  " << withdrawalAmount << "  from  account1\n";

    account1.debit(withdrawalAmount);
    cout << "account1  balance:$" << account1.getBalance() << endl;

    Account  account2(-2);
    cout << "account2  balance  :$" << account2.getBalance() << endl;
    cin >> withdrawalAmount;
    account2.credit(withdrawalAmount);
    cout << "attempting  to  add  " << withdrawalAmount << "  to  account2\n";
    cout << "account2  balance  :$" << account2.getBalance() << endl;

    return  0;
}