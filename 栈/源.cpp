#include  <iostream>
using  namespace  std;
typedef  int  Item;
class  Stack
{
private:
    Item* pitems;        //  存储栈元素
    int  size;              //  栈的大小
    int  top;                //  栈顶元素的下标
public:
    Stack(int  n);
    ~Stack();
    bool  isempty()  const;
    bool  isfull()  const;
    //  入栈函数。如果栈满，返回假，否则返回真。
    bool  push(const  Item& item);
    //  出栈函数。如果栈为空，返回假，否则返回真。
    bool  pop(Item& item);
    int get(int n) { return pitems[n]; }
};
Stack::~Stack() {};
Stack::Stack(int n) {
    pitems = new Item[n];
    size = n;
    top = -1;
}
bool Stack::isempty()const {
    if (top==-1) { return true; }
    return false;
}
bool Stack::isfull()const {
    if (top==size-1) { return true; }
    return false;
}

bool Stack::pop(Item& item) {
    if (top==-1) { return false; }
    else if (top == 0) { item = pitems[top];  top--; return true; }
    else { item = pitems[top]; top--; return true; }
}
bool Stack::push(const Item& item) {
    if (top==-1) {
        pitems[0] = item;
        top++;
        return true;
    }
    else if (top==size-1) {
        return false;
    }
    else {
        pitems[++top] = item;
        return true;
    }
}
int  main()
{
    int  num;
    cin >> num;

    Item  temp = 0;
    Item* x = new  Item[num];
    Stack  st1(5), st2(5);
    //输入4个测试数据
    for (int i = 0; i < num; i++) {
        cin >> x[i];
        st1.push(x[i]);
    }

    //st1的栈顶元素出栈，并输出
    while (!st1.isempty()) {
        st1.pop(temp);
        cout << temp << endl;
        st2.push(temp);
    }

    //st2的栈顶元素出栈，并输出。
    if (st2.isfull()) {
        cout << "st2  is  full" << endl;
    }
    else {
        cout << "st2  is  not  full" << endl;
    }
    return  0;
}