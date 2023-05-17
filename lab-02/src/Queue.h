#include "LinkedList.h"

template <typename T>
struct Queue {
    DoublyLinkedList<T> list;

    Queue(): list () {}

    void enqueue(const T& data) {
        list.push_back(data);
    }

    T dequeue(){
        return list.pop_front();
    }

    int peek_front() {
        return list.head->data;
    }

    int peek_back() {
        return list.tail->data;
    }
};
