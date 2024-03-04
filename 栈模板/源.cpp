#include<iostream>
using  namespace  std;

//  定义Stack类
template<class  T, int  MaxSize>
class  Stack {
public:
    Stack() {
        elems = new  T[MaxSize];
        top = -1;
    }
    ~Stack() { delete  elems; }
    T  Top()  const;
    void  Push(const  T& x);
    void  Pop(T& x);
    template<class    T1, int    Max>
    friend  ostream& operator<<(ostream& os, Stack<T1, Max>& s);
private:
    int  top;
    T* elems;
};

template<class  T, int  MaxSize>
T Stack<T,MaxSize>::Top()const {
    return elems[top];
}
template<class  T, int  MaxSize>
void Stack<T, MaxSize>::Push(const  T& x) {
    elems[top + 1] = x;
    top++;
}
template<class  T, int  MaxSize>
void Stack<T, MaxSize>::Pop(T& x){
    x = elems[top];
    top--;
}
template<class    T1, int    Max>
ostream& operator<<(ostream& os, Stack<T1, Max>& s) {
    for (int i = 0; i < s.top+1; i++) {
        cout << s.elems[i] << ' ';
    }
    return cout;
}






int  main() {
    //  构造不同数据类型进行测试验证
    Stack<int, 10>  stack_int;
    for (int i = 0; i < 10; i++)
        stack_int.Push(5 * i);
    cout << "stack_int:  " << stack_int << endl;
    cout << "delete  two  elements:  ";
    for (int i = 0; i < 2; i++) {
        int  x;
        stack_int.Pop(x);
        cout << x << "    ";
    }
    cout << endl << "stack_int:  " << stack_int << endl << endl << endl;

    Stack<double, 10>  stack_double;
    for (int i = 0; i < 10; i++)
        stack_double.Push(5.2 * i + 0.3);
    cout << "stack_double:  " << stack_double << endl;
    cout << "delete  two  elements:  ";
    for (int i = 0; i < 2; i++) {
        double  x;
        stack_double.Pop(x);
        cout << x << "    ";
    }
    cout << endl << "stack_double:  " << stack_double << endl << endl << endl;

    Stack<char, 10>  stack_char;
    for (int i = 0; i < 10; i++)
        stack_char.Push(char(2 * i + 68));
    cout << "stack_char:  " << stack_char << endl;
    cout << "delete  two  elements:  ";
    for (int i = 0; i < 2; i++) {
        char  x;
        stack_char.Pop(x);
        cout << x << "    ";
    }
    cout << endl << "stack_char:  " << stack_char << endl << endl << endl;
    return  0;
}