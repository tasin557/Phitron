#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

// Example 1: Basic Node Operations
void basicNodeOperations() {
    Node a, b;
    a.val = 10;
    b.val = 20;

    a.next = &b;
    b.next = NULL;

    cout << a.val << endl;
    cout << b.val << endl;
    cout << (*a.next).val << endl;
    cout << a.next->val << endl;
}

// Example 2: Node Creation with Dynamic Memory
void dynamicNodeCreation() {
    Node* head = new Node(10);
    Node* a = new Node(20);

    head->next = a;

    cout << head->val << endl;
    cout << a->val << endl;
    cout << head->next->val << endl;
}

// Example 3: Creating and Linking Multiple Nodes
void createAndLinkNodes() {
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);
    Node* c = new Node(40);
    Node* d = new Node(50);

    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;

    Node* tmp = head;
    while (tmp != NULL) {
        cout << tmp->val << endl;
        tmp = tmp->next;
    }
}

// Example 4: Insert at Tail
void insertAtTail(Node*& head, int v) {
    Node* newNode = new Node(v);
    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* tmp = head;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = newNode;
    cout << "Inserted at tail" << endl;
}

// Example 5: Insert at Position
void insertAtPosition(Node* head, int pos, int v) {
    Node* newNode = new Node(v);
    Node* tmp = head;
    for (int i = 1; i <= pos - 1; i++) {
        tmp = tmp->next;
    }
    newNode->next = tmp->next;
    tmp->next = newNode;
    cout << "Inserted at position " << pos << endl;
}

// Example 6: Insert at Head
void insertAtHead(Node*& head, int v) {
    Node* newNode = new Node(v);
    newNode->next = head;
    head = newNode;
    cout << "Inserted at head" << endl;
}

// Example 7: Delete from Position
void deleteFromPosition(Node* head, int pos) {
    Node* tmp = head;
    for (int i = 1; i <= pos - 1; i++) {
        tmp = tmp->next;
    }
    Node* deleteNode = tmp->next;
    tmp->next = tmp->next->next;
    delete deleteNode;
    cout << "Deleted position " << pos << endl;
}

// Example 8: Delete Head
void deleteHead(Node*& head) {
    Node* deleteNode = head;
    head = head->next;
    delete deleteNode;
    cout << "Deleted head" << endl;
}

// Example 9: Print Linked List
void printLinkedList(Node* head) {
    cout << "Your Linked List: ";
    Node* tmp = head;
    while (tmp != NULL) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

// Example 10: Linked List Operations Menu
void linkedListOperations() {
    Node* head = NULL;
    while (true) {
        cout << "Option 1: Insert at Tail" << endl;
        cout << "Option 2: Print Linked List" << endl;
        cout << "Option 3: Insert at any Position" << endl;
        cout << "Option 4: Insert at Head" << endl;
        cout << "Option 5: Delete from Position" << endl;
        cout << "Option 6: Delete Head" << endl;
        cout << "Option 7: Terminate" << endl;
        int op;
        cin >> op;
        if (op == 1) {
            cout << "Please enter value: ";
            int v;
            cin >> v;
            insertAtTail(head, v);
        } else if (op == 2) {
            printLinkedList(head);
        } else if (op == 3) {
            int pos, v;
            cout << "Enter position: ";
            cin >> pos;
            cout << "Enter value: ";
            cin >> v;
            if (pos == 0) {
                insertAtHead(head, v);
            } else {
                insertAtPosition(head, pos, v);
            }
        } else if (op == 4) {
            int v;
            cout << "Enter value: ";
            cin >> v;
            insertAtHead(head, v);
        } else if (op == 5) {
            int pos;
            cout << "Enter position: ";
            cin >> pos;
            if (pos == 0) {
                deleteHead(head);
            } else {
                deleteFromPosition(head, pos);
            }
        } else if (op == 6) {
            deleteHead(head);
        } else if (op == 7) {
            break;
        }
    }
}

// Example 11: Print Linked List Recursively
void printRecursively(Node* n) {
    if (n == NULL) return;
    cout << n->val << " ";
    printRecursively(n->next);
}

// Example 12: Print Linked List in Reverse Recursively
void printReverseRecursively(Node* n) {
    if (n == NULL) return;
    printReverseRecursively(n->next);
    cout << n->val << " ";
}

// Example 13: Linked List Size
int linkedListSize(Node* head) {
    Node* tmp = head;
    int count = 0;
    while (tmp != NULL) {
        count++;
        tmp = tmp->next;
    }
    return count;
}

// Example 14: Remove Nth Node from End of List
class Solution {
public:
    int size(Node* head) {
        Node* tmp = head;
        int cnt = 0;
        while (tmp != NULL) {
            cnt++;
            tmp = tmp->next;
        }
        return cnt;
    }

    Node* removeNthFromEnd(Node* head, int n) {
        Node* dummy = new Node(0);
        dummy->next = head;
        Node* current = dummy;

        int a = size(head) - n;

        for (int i = 0; i < a; i++) {
            current = current->next;
        }

        Node* deleteNode = current->next;
        current->next = current->next->next;
        delete deleteNode;

        head = dummy->next;
        delete dummy;
        return head;
    }
};

int main() {
    // Call any of the above functions to see the examples in action
    basicNodeOperations();
    dynamicNodeCreation();
    createAndLinkNodes();
    linkedListOperations();

    return 0;
}
