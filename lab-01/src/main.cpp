#include <bits/stdc++.h>
#include "LinkedList.h"
using namespace std;

int main()
{
    DoublyLinkedList<int> l;

    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.push_back(6);
    l.push_back(7);

    l.pop_back();
    l.pop_front();
    l.insert(666, 2);
    l.push_front(9);
    l.push_back(10);

    cout << "List: ";
    l.print();
    cout << endl;
    cout << "List size: " << l.length() << endl;

    return 0;
}