#include <bits/stdc++.h>
using namespace std;

// Example 1: Stack Implementation Using Vector
class MyStackVector {
public:
    vector<int> v;

    void push(int val) {
        v.push_back(val);
    }

    void pop() {
        v.pop_back();
    }

    int top() {
        return v.back();
    }

    int size() {
        return v.size();
    }

    bool empty() {
        return v.empty();
    }
};

// Example 2: Stack Implementation Using Doubly Linked List
class Node {
public:
    int val;
    Node* next;
    Node* prev;

    Node(int val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class MyStackDoublyLinkedList {
public:
    Node* head = NULL;
    Node* tail = NULL;
    int sz = 0;

    void push(int val) {
        sz++;
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    void pop() {
        if (sz == 0) return;
        sz--;
        Node* deleteNode = tail;
        tail = tail->prev;
        if (tail == NULL) {
            head = NULL;
        } else {
            tail->next = NULL;
        }
        delete deleteNode;
    }

    int top() {
        return tail->val;
    }

    int size() {
        return sz;
    }

    bool empty() {
        return sz == 0;
    }
};

// Example 3: Stack Implementation Using List
class MyStackList {
public:
    list<int> l;

    void push(int val) {
        l.push_back(val);
    }

    void pop() {
        l.pop_back();
    }

    int top() {
        return l.back();
    }

    int size() {
        return l.size();
    }

    bool empty() {
        return l.empty();
    }
};

int main() {
    // Using MyStackVector
    MyStackVector st1;
    int n1;
    cout << "Enter number of elements for vector-based stack: ";
    cin >> n1;
    cout << "Enter elements: ";
    for (int i = 0; i < n1; i++) {
        int x;
        cin >> x;
        st1.push(x);
    }
    cout << "Stack elements (vector-based):" << endl;
    while (!st1.empty()) {
        cout << st1.top() << endl;
        st1.pop();
    }

    // Using MyStackDoublyLinkedList
    MyStackDoublyLinkedList st2;
    int n2;
    cout << "Enter number of elements for doubly linked list-based stack: ";
    cin >> n2;
    cout << "Enter elements: ";
    for (int i = 0; i < n2; i++) {
        int x;
        cin >> x;
        st2.push(x);
    }
    cout << "Stack elements (doubly linked list-based):" << endl;
    while (!st2.empty()) {
        cout << st2.top() << endl;
        st2.pop();
    }

    // Using MyStackList
    MyStackList st3;
    int n3;
    cout << "Enter number of elements for list-based stack: ";
    cin >> n3;
    cout << "Enter elements: ";
    for (int i = 0; i < n3; i++) {
        int x;
        cin >> x;
        st3.push(x);
    }
    cout << "Stack elements (list-based):" << endl;
    while (!st3.empty()) {
        cout << st3.top() << endl;
        st3.pop();
    }

    // Using Standard Library Stack
    stack<int> st4;
    int n4;
    cout << "Enter number of elements for standard library stack: ";
    cin >> n4;
    cout << "Enter elements: ";
    for (int i = 0; i < n4; i++) {
        int x;
        cin >> x;
        st4.push(x);
    }
    cout << "Stack elements (standard library):" << endl;
    while (!st4.empty()) {
        cout << st4.top() << endl;
        st4.pop();
    }

    return 0;
}
