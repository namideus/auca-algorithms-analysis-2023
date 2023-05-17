#pragma once

template <typename T>
struct Node {
    T data;
    Node* next;
    Node* prev;
    explicit Node(const T& data) : data(data), next(nullptr), prev(nullptr) {}
};

template <typename T>
class DoublyLinkedList {
    Node<T>* head;
    Node<T>* tail;
    int size;
public:

    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    void push_front(const T& data) {
        auto* new_node = new Node<T>(data);
        if (size == 0){
            head = new_node;
            tail = new_node;
            size++;
            return;
        }
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
        size++;
    }

    void push_back(const T& data) {
        auto* new_node = new Node<T>(data);
        if (size == 0){
            head = new_node;
            tail = new_node;
            size++;
            return;
        }
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
        size++;
    }

    void pop_front() {
        if (size == 0) {
            return;
        }
        if (size  == 1){
            delete head;
            head = nullptr;
            tail = nullptr;
            size--;
            return;
        }
        Node<T>* new_head = head->next;
        new_head->prev = nullptr;
        delete head;
        head = new_head;
        size--;
    }

    void pop_back() {
        if (size == 0) {
            return;
        }
        if (size  == 1){
            delete tail;
            head = nullptr;
            tail = nullptr;
            size--;
            return;
        }
        Node<T>* new_tail = tail->prev;
        new_tail->next = nullptr;
        delete tail;
        tail = new_tail;
        size--;
    }

    Node<T>* find_node_by_index(int index) {
        if (index >= size) {
            return nullptr;
        }

        Node<T>* current;
        if (index < size / 2) {
            current = head;
            for (int i = 0; i < index; i++) {
                current = current->next;
            }
        } else {
            current = tail;
            for (int i = size - 1; i > index; i--) {
                current = current->prev;
            }
        }
        return current;
    }
    void insert(const T& data, int index) {
        if (index == 0) {
            push_front(data);
            return;
        } else if (index == size) {
            push_back(data);
            return;
        }

        auto* new_node = new Node<T>(data);
        Node<T>* current = find_node_by_index(index);
        if (!current) {
            return;
        }

        new_node->prev = current->prev;
        new_node->next = current;
        current->prev->next = new_node;
        current->prev = new_node;
        size++;
    }

    int length() {
        return size;
    }

    void print() {
        Node<T>* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    ~DoublyLinkedList() {
        while (head) {
            pop_front();
        }
    }
};