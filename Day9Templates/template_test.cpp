#include "LinkedList.h"

#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "=== int LinkedList ===" << endl;
    LinkedList<int> intList;
    intList.add(3);
    intList.add(2);
    intList.add(1);
    cout << "After add(1), add(2), add(3): ";
    intList.printList();
    cout << endl;

    intList.insertAt(1, 99);
    cout << "After insertAt(1, 99): ";
    intList.printList();
    cout << endl;

    cout << "findVal(99): " << (intList.findVal(99) ? "true" : "false") << endl;
    cout << "findVal(42): " << (intList.findVal(42) ? "true" : "false") << endl;

    intList.removeAll();
    cout << "After removeAll(): ";
    intList.printList();
    cout << endl;

    cout << endl;

    cout << "=== string LinkedList ===" << endl;
    LinkedList<string> strList;
    strList.add("world");
    strList.add("hello");
    cout << "After add(\"hello\"), add(\"world\"): ";
    strList.printList();
    cout << endl;

    strList.insertAt(1, "there");
    cout << "After insertAt(1, \"there\"): ";
    strList.printList();
    cout << endl;

    cout << "findVal(\"hello\"): " << (strList.findVal("hello") ? "true" : "false") << endl;
    cout << "findVal(\"bye\"): " << (strList.findVal("bye") ? "true" : "false") << endl;

    strList.removeAll();
    cout << "After removeAll(): ";
    strList.printList();
    cout << endl;

    return 0;
}
