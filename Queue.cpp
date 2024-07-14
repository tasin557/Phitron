#include <bits/stdc++.h>
using namespace std;

// Example 1: Queue Implementation Using Two Stacks
class MyQueue {
public:
    stack<int> st;

    MyQueue() {}

    void push(int x) {
        st.push(x);
    }

    int pop() {
        stack<int> newSt;
        int last;
        while (!st.empty()) {
            int k = st.top();
            st.pop();
            if (st.empty()) {
                last = k;
                break;
            }
            newSt.push(k);
        }
        while (!newSt.empty()) {
            st.push(newSt.top());
            newSt.pop();
        }
        return last;
    }

    int peek() {
        stack<int> newSt;
        int last;
        while (!st.empty()) {
            int k = st.top();
            st.pop();
            if (st.empty()) {
                last = k;
            }
            newSt.push(k);
        }
        while (!newSt.empty()) {
            st.push(newSt.top());
            newSt.pop();
        }
        return last;
    }

    bool empty() {
        return st.empty();
    }
};

// Example 2: Stack Implementation Using Queue
class MyStack {
public:
    queue<int> q;

    MyStack() {}

    void push(int x) {
        q.push(x);
    }

    int pop() {
        queue<int> newQ;
        int last;
        while (!q.empty()) {
            int k = q.front();
            q.pop();
            if (q.empty()) {
                last = k;
                break;
            }
            newQ.push(k);
        }
        q = newQ;
        return last;
    }

    int top() {
        queue<int> newQ;
        int last;
        while (!q.empty()) {
            int k = q.front();
            q.pop();
            if (q.empty()) {
                last = k;
            }
            newQ.push(k);
        }
        q = newQ;
        return last;
    }

    bool empty() {
        return q.empty();
    }
};

// Example 3: Queue Implementation Using Doubly Linked List
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

class MyQueueDoublyLinkedList {
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
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void pop() {
        if (sz == 0) return;
        sz--;
        Node* deleteNode = head;
        head = head->next;
        if (head == NULL) {
            tail = NULL;
        } else {
            head->prev = NULL;
        }
        delete deleteNode;
    }

    int front() {
        return head->val;
    }

    int size() {
        return sz;
    }

    bool empty() {
        return sz == 0;
    }
};

// Example 4: Queue Implementation Using List
class MyQueueList {
public:
    list<int> l;

    void push(int val) {
        l.push_back(val);
    }

    void pop() {
        l.pop_front();
    }

    int front() {
        return l.front();
    }

    int size() {
        return l.size();
    }

    bool empty() {
        return l.empty();
    }
};

// Example 5: Queue Implementation Using Singly Linked List
class MyQueueSinglyLinkedList {
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
        tail->next = newNode;
        tail = newNode;
    }

    void pop() {
        if (sz == 0) return;
        sz--;
        Node* deleteNode = head;
        head = head->next;
        delete deleteNode;
        if (head == NULL) {
            tail = NULL;
        }
    }

    int front() {
        return head->val;
    }

    int size() {
        return sz;
    }

    bool empty() {
        return sz == 0;
    }
};

// Example 6: Queue Implementation Using Standard Library
void standardLibraryQueue() {
    queue<int> q;
    int n;
    cout << "Enter number of elements for standard library queue: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(x);
    }
    cout << "Queue size: " << q.size() << endl;
    cout << "Queue elements:" << endl;
    while (!q.empty()) {
        cout << q.front() << endl;
        q.pop();
    }
}

// Example 7: Reverse a Queue
queue<int> reverseQueue(queue<int> q) {
    stack<int> s;
    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
    return q;
}

int main() {
    // Using MyQueue (Two Stacks)
    MyQueue q1;
    int n1;
    cout << "Enter number of elements for queue-based stack: ";
    cin >> n1;
    cout << "Enter elements: ";
    for (int i = 0; i < n1; i++) {
        int x;
        cin >> x;
        q1.push(x);
    }
    cout << "Queue elements (queue-based stack):" << endl;
    while (!q1.empty()) {
        cout << q1.peek() << endl;
        q1.pop();
    }

    // Using MyStack (Queue)
    MyStack q2;
    int n2;
    cout << "Enter number of elements for stack-based queue: ";
    cin >> n2;
    cout << "Enter elements: ";
    for (int i = 0; i < n2; i++) {
        int x;
        cin >> x;
        q2.push(x);
    }
    cout << "Stack elements (stack-based queue):" << endl;
    while (!q2.empty()) {
        cout << q2.top() << endl;
        q2.pop();
    }

    // Using MyQueueDoublyLinkedList
    MyQueueDoublyLinkedList q3;
    int n3;
    cout << "Enter number of elements for doubly linked list-based queue: ";
    cin >> n3;
    cout << "Enter elements: ";
    for (int i = 0; i < n3; i++) {
        int x;
        cin >> x;
        q3.push(x);
    }
    cout << "Queue elements (doubly linked list-based):" << endl;
    while (!q3.empty()) {
        cout << q3.front() << endl;
        q3.pop();
    }

    // Using MyQueueList
    MyQueueList q4;
    int n4;
    cout << "Enter number of elements for list-based queue: ";
    cin >> n4;
    cout << "Enter elements: ";
    for (int i = 0; i < n4; i++) {
        int x;
        cin >> x;
        q4.push(x);
    }
    cout << "Queue elements (list-based):" << endl;
    while (!q4.empty()) {
        cout << q4.front() << endl;
        q4.pop();
    }

    // Using MyQueueSinglyLinkedList
    MyQueueSinglyLinkedList q5;
    int n5;
    cout << "Enter number of elements for singly linked list-based queue: ";
    cin >> n5;
    cout << "Enter elements: ";
    for (int i = 0; i < n5; i++) {
        int x;
        cin >> x;
        q5.push(x);
    }
    cout << "Queue elements (singly linked list-based):" << endl;
    while (!q5.empty()) {
        cout << q5.front() << endl;
        q5.pop();
    }

    // Using Standard Library Queue
    standardLibraryQueue();

    // Reverse Queue Example
    queue<int> q6;
    cout << "Enter number of elements to reverse queue: ";
    int n6;
    cin >> n6;
    cout << "Enter elements: ";
    for (int i = 0; i < n6; i++) {
        int x;
        cin >> x;
        q6.push(x);
    }
    q6 = reverseQueue(q6);
    cout << "Reversed Queue elements:" << endl;
    while (!q6.empty()) {
        cout << q6.front() << endl;
        q6.pop();
    }

    return 0;
}
