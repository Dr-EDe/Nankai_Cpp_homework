#include  <iostream>
using  namespace  std;
typedef  int  Item;
class  Stack
{
private:
    Item* pitems;        //  �洢ջԪ��
    int  size;              //  ջ�Ĵ�С
    int  top;                //  ջ��Ԫ�ص��±�
public:
    Stack(int  n);
    ~Stack();
    bool  isempty()  const;
    bool  isfull()  const;
    //  ��ջ���������ջ�������ؼ٣����򷵻��档
    bool  push(const  Item& item);
    //  ��ջ���������ջΪ�գ����ؼ٣����򷵻��档
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
    //����4����������
    for (int i = 0; i < num; i++) {
        cin >> x[i];
        st1.push(x[i]);
    }

    //st1��ջ��Ԫ�س�ջ�������
    while (!st1.isempty()) {
        st1.pop(temp);
        cout << temp << endl;
        st2.push(temp);
    }

    //st2��ջ��Ԫ�س�ջ���������
    if (st2.isfull()) {
        cout << "st2  is  full" << endl;
    }
    else {
        cout << "st2  is  not  full" << endl;
    }
    return  0;
}