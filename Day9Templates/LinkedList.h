// Header file and implementation for template linked list class

#include <iostream>
#include <string>
using namespace std;

template <class Type>
class LinkedList {
public:
    LinkedList();
    LinkedList(const LinkedList& lst);
    ~LinkedList();

    void add(Type data);
    void insertAt(int pos, Type data);
    bool findVal(Type data);
    void removeAll();
    void printList();

private:
    struct Node {
        Type data;
        Node *next;
    };

    Node *head;
    int size;
};

// Default constructor
template <class Type>
LinkedList<Type>::LinkedList() {
    head = NULL;
    size = 0;
}

// Copy constructor
template <class Type>
LinkedList<Type>::LinkedList(const LinkedList& lst) {
    if (lst.head == NULL) {
        head = NULL;
        size = 0;
    } else {
        head = new Node;
        head->data = lst.head->data;
        Node *pNewNode = head;
        Node *pOldNode = lst.head->next;
        while (pOldNode != NULL) {
            pNewNode->next = new Node;
            pNewNode = pNewNode->next;
            pNewNode->data = pOldNode->data;
            pOldNode = pOldNode->next;
        }
        pNewNode->next = NULL;
        size = lst.size;
    }
}

// Destructor
template <class Type>
LinkedList<Type>::~LinkedList() {
    removeAll();
}

// Adds a node to the front of the list
template <class Type>
void LinkedList<Type>::add(Type x) {
    Node *p = new Node;
    p->data = x;
    p->next = head;
    head = p;
    size++;
}

// Inserts a new node at the given position (index) in the list
template <class Type>
void LinkedList<Type>::insertAt(int pos, Type x) {
    if (pos <= 0 || head == NULL) {
        add(x);
        return;
    }
    Node *p = head;
    for (int i = 0; i < pos - 1 && p->next != NULL; i++) {
        p = p->next;
    }
    Node *newNode = new Node;
    newNode->data = x;
    newNode->next = p->next;
    p->next = newNode;
    size++;
}

// Returns true if x is found in the list, false otherwise
template <class Type>
bool LinkedList<Type>::findVal(Type x) {
    Node *p = head;
    while (p != NULL) {
        if (p->data == x) return true;
        p = p->next;
    }
    return false;
}

// Empties the list
template <class Type>
void LinkedList<Type>::removeAll() {
    Node *p = head;
    while (p != NULL) {
        head = head->next;
        delete p;
        p = head;
    }
    head = NULL;
    size = 0;
}

// Prints the list
template <class Type>
void LinkedList<Type>::printList() {
    Node *p = head;
    cout << "[";
    while (p != NULL) {
        cout << p->data;
        p = p->next;
        if (p != NULL) cout << ",";
    }
    cout << "]";
}
