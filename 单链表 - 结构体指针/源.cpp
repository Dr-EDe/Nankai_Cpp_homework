#include  <iostream>
using  namespace  std;

typedef  struct  Node {
    int  elem;    //  代表数据域
    struct  Node* next;    //  代表指针域，指向直接后继元素
}  Linklist;
Linklist* initLink() {
    Linklist* head = (Linklist*)malloc(sizeof(Linklist));
    head->next = NULL;
    return head;
}
bool isEmpty(Linklist* head) {
    if (head->next == NULL)return true;
    else return false;
}
int getLen(Linklist* head) {
    int i = 0;
    Node* cur = head;
    if (cur->next == NULL) return 0;
    else {
        while (cur->next != NULL) {
            i++;
            cur = cur->next;
        }
        return i;
    }
}
void printLinklist(Linklist* head) {
    Node* cur = head->next;
    while (cur!= NULL) {
        cout << cur->elem << ' ';
        cur = cur->next;
   }
    cout << endl;
}
void addNode(Linklist* head, int elem) {
    Node* cur = head;
    while (cur->next!=NULL) {
        cur = cur->next;
    }
    Node* newnode = new Node();
    newnode->elem = elem;
    newnode->next = NULL;
    cur->next = newnode;
}
void insert(Linklist* head, int i, int elem) {
    Node* cur = head;
    Node* newnode = new Node();
    newnode->elem = elem;
    for (int j = 0; j < i-1; j++) {
        cur = cur->next;
    }
    Node* after = cur->next;
    cur->next = newnode;
    newnode->next = after;
}
void delNode(Linklist* head, int i){
    Node* cur = head;
    for (int j = 0; j < i - 1; j++) {
        cur = cur->next;
    }
    Node* after = cur->next;
    cur->next = after->next;
}
void updateNode(Linklist* head, int i, int elem) {
    Node* cur = head;
    for (int j = 0; j < i; j++) {
        cur = cur->next;
    }
    cur->elem = elem;
}
int getElem(Linklist* head, int i) {
    Node* cur = head;
    for (int j = 0; j < i; j++) {
        cur = cur->next;
    }
    return cur->elem;
}
int getIndex(Linklist* head, int elem) {
    Node* cur = head;
    int i = 1;
    while(cur->next!=NULL){
        if (cur->elem == elem) { return i-1; break; }
        else{
            i++;
            cur = cur->next;
        }
    }
    return 0;
}



int  main() {
    Linklist* link = initLink();
    std::cout << isEmpty(link) << std::endl;
    std::cout << getLen(link) << std::endl;
    //  增
    addNode(link, 1);
    addNode(link, 2);
    addNode(link, 3);
    addNode(link, 5);
    addNode(link, 6);
    addNode(link, 7);
    insert(link, 4, 4);
    std::cout << isEmpty(link) << std::endl;
    std::cout << getLen(link) << std::endl;
    printLinklist(link);
    //  删
    delNode(link, 2);
    std::cout << getLen(link) << std::endl;
    printLinklist(link);
    //  改
    updateNode(link, 4, 7);
    printLinklist(link);
    //  查
    std::cout << getElem(link, 4) << "  " << getElem(link, 6) << std::endl;
    std::cout << getIndex(link, 2) << std::endl;
    std::cout << getIndex(link, 3) << std::endl;
}
