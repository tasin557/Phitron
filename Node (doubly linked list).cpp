#include <bits/stdc++.h>
using namespace std;

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

// Example 1: Print Doubly Linked List in Normal Order
void printNormal(Node* head) {
    Node* tmp = head;
    while (tmp != NULL) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

// Example 2: Print Doubly Linked List in Reverse Order
void printReverse(Node* tail) {
    Node* tmp = tail;
    while (tmp != NULL) {
        cout << tmp->val << " ";
        tmp = tmp->prev;
    }
    cout << endl;
}

// Example 3: Insert at Tail
void insertTail(Node*& head, Node*& tail, int val) {
    Node* newNode = new Node(val);
    if (tail == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

// Example 4: Insert at Position
void insertAtPosition(Node* head, int pos, int val) {
    Node* newNode = new Node(val);
    Node* tmp = head;
    for (int i = 1; i <= pos - 1; i++) {
        tmp = tmp->next;
    }
    newNode->next = tmp->next; 
    if (tmp->next != NULL) {
        tmp->next->prev = newNode;
    }
    tmp->next = newNode;
    newNode->prev = tmp;
}

// Example 5: Insert at Head
void insertHead(Node*& head, Node*& tail, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

// Example 6: Delete from Position
void deleteAtPosition(Node* head, int pos) {
    Node* tmp = head;
    for (int i = 1; i <= pos - 1; i++) {
        tmp = tmp->next;
    }
    Node* deleteNode = tmp->next;
    tmp->next = tmp->next->next;
    if (tmp->next != NULL) {
        tmp->next->prev = tmp;
    }
    delete deleteNode;
}

// Example 7: Delete Tail
void deleteTail(Node*& head, Node*& tail) {
    Node* deleteNode = tail;
    tail = tail->prev;
    delete deleteNode;
    if (tail == NULL) {
        head = NULL;
        return;
    }
    tail->next = NULL;
}

// Example 8: Delete Head
void deleteHead(Node*& head, Node*& tail) {
    Node* deleteNode = head;
    head = head->next;
    delete deleteNode;
    if (head == NULL) {
        tail = NULL;
        return;
    }
    head->prev = NULL;
}

// Example 9: Reverse Doubly Linked List
void reverseDoublyLinkedList(Node*& head, Node*& tail) {
    Node* i = head;
    Node* j = tail;
    while (i != j && i->next != j) {
        swap(i->val, j->val);
        i = i->next;
        j = j->prev;
    }
    swap(i->val, j->val);
}

// Example 10: Linked List Size
int linkedListSize(Node* head) {
    Node* tmp = head;
    int count = 0;
    while (tmp != NULL) {
        count++;
        tmp = tmp->next;
    }
    return count;
}

// Example 11: Delete Node from End
class Solution {
public:
    int size(ListNode* head) {
        ListNode* tmp = head;
        int cnt = 0;
        while (tmp != NULL) {
            cnt++;
            tmp = tmp->next;
        }
        return cnt;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* current = dummy;

        int a = size(head) - n;

        for (int i = 0; i < a; i++) {
            current = current->next;
        }

        ListNode* deleteNode = current->next;
        current->next = current->next->next;
        delete deleteNode;

        head = dummy->next;
        delete dummy;
        return head;
    }
};

// Example 12: Check if Palindrome
class SolutionPalindrome {
public:
    void insertTail(ListNode*& head, ListNode*& tail, int val) {
        ListNode* newNode = new ListNode(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = tail->next;
    }

    void reverse(ListNode*& head, ListNode* cur) {
        if (cur->next == NULL) {
            head = cur;
            return;
        }
        reverse(head, cur->next);
        cur->next->next = cur;
        cur->next = NULL;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* newHead = NULL;
        ListNode* newTail = NULL;
        ListNode* tmp = head;
        while (tmp != NULL) {
            insertTail(newHead, newTail, tmp->val);
            tmp = tmp->next;
        }
        reverse(newHead, newHead);
        tmp = head;
        ListNode* tmp2 = newHead;
        while (tmp != NULL) {
            if (tmp->val != tmp2->val) {
                return false;
            }
            tmp = tmp->next;
            tmp2 = tmp2->next;
        }
        return true;
    }
};

// Example 13: Delete Duplicates
class SolutionDeleteDuplicates {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL)
            return head;
        ListNode* tmp = head;
        while (tmp->next != NULL) {
            if (tmp->val == tmp->next->val) {
                ListNode* deleteNode = tmp->next;
                tmp->next = tmp->next->next;
                delete deleteNode;
            }
            if (tmp->next == NULL)
                break;
            else if (tmp->val != tmp->next->val) {
                tmp = tmp->next;
            }
        }
        return head;
    }
};

// Example 14: Reverse List
class SolutionReverseList {
public:
    void reverse(ListNode*& head, ListNode* cur) {
        if (cur->next == NULL) {
            head = cur;
            return;
        }
        reverse(head, cur->next);
        cur->next->next = cur;
        cur->next = NULL;
    }

    ListNode* reverseList(ListNode* head) {
        if (head == NULL)
            return head;
        reverse(head, head);
        return head;
    }
};

int main() {
    // Call any of the above functions to see the examples in action
    Node* head = new Node(10);
    Node* tail = head;

    // Perform operations...
    insertTail(head, tail, 20);
    insertTail(head, tail, 30);
    insertTail(head, tail, 40);

    printNormal(head);
    printReverse(tail);

    // Additional operations...
    int pos, val;
    cin >> pos >> val;
    if (pos >= linkedListSize(head)) {
        cout << "Invalid" << endl;
    } else if (pos == 0) {
        insertHead(head, tail, val);
    } else if (pos == linkedListSize(head)) {
        insertTail(head, tail, val);
    } else {
        insertAtPosition(head, pos, val);
    }

    printNormal(head);
    printReverse(tail);

    return 0;
}
