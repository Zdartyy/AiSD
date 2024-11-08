#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <iostream>     // deklaracje strumieni cout, cin, cerr
#include <cassert>    // assert()

template <typename T>
struct DoubleNode {
    T value;
    DoubleNode *next, *prev;
    DoubleNode() : value(T()), next(nullptr), prev(nullptr) {}
    DoubleNode(const T& item, DoubleNode *nptr=nullptr, DoubleNode *pptr=nullptr)
        : value(item), next(nptr), prev(pptr) {}
    ~DoubleNode() {}
};

template <typename T>
class DoubleList {
    DoubleNode<T> *head, *tail;
public:
    DoubleList() : head(nullptr), tail(nullptr) {}
    ~DoubleList();

    DoubleList(const DoubleList& other); // copy constructor
    DoubleList& operator=(const DoubleList& other); // copy assignment operator

    bool empty() const { return head == nullptr; }
    std::size_t size() const;
    void push_front(const T& item);
    void push_back(const T& item);
    T& front() const { assert(!empty()); return head->value; }
    T& back() const { assert(!empty()); return tail->value; }
    void pop_front();
    void pop_back();
    void clear();
    void display() const;
    void display_reversed() const;
};

template <typename T>
DoubleList<T>::~DoubleList() {
    clear();
}

template <typename T>
DoubleList<T>::DoubleList(const DoubleList& other) : head(nullptr), tail(nullptr) {
    DoubleNode<T> *node = other.head;
    while (node != nullptr) {
        push_back(node->value);
        node = node->next;
    }
}

template <typename T>
DoubleList<T>& DoubleList<T>::operator=(const DoubleList& other) {
    if (this != &other) {
        clear();
        DoubleNode<T> *node = other.head;
        while (node != nullptr) {
            push_back(node->value);
            node = node->next;
        }
    }
    return *this;
}

template <typename T>
std::size_t DoubleList<T>::size() const {
    std::size_t count = 0;
    DoubleNode<T> *node = head;
    while (node != nullptr) {
        ++count;
        node = node->next;
    }
    return count;
}

template <typename T>
void DoubleList<T>::push_front(const T& item) {
    if (!empty()) {
        head = new DoubleNode<T>(item, head);
        head->next->prev = head;
    } else {
        head = tail = new DoubleNode<T>(item);
    }
    assert(head != nullptr && "Failed to push_front");
}

template <typename T>
void DoubleList<T>::push_back(const T& item) {
    if (!empty()) {
        tail->next = new DoubleNode<T>(item, nullptr, tail);
        tail = tail->next;
    } else {
        head = tail = new DoubleNode<T>(item);
    }
    assert(tail != nullptr && "Failed to push_back");
}

template <typename T>
void DoubleList<T>::pop_front() {
    assert(!empty() && "List is empty");
    DoubleNode<T> *node = head;
    if (head == tail) {
        head = tail = nullptr;
    } else {
        head = head->next;
        head->prev = nullptr;
    }
    delete node;
    assert((head != nullptr || tail == nullptr) && "Failed to pop_front");
}

template <typename T>
void DoubleList<T>::pop_back() {
    assert(!empty() && "List is empty");
    DoubleNode<T> *node = tail;
    if (head == tail) {
        head = tail = nullptr;
    } else {
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete node;
    assert((tail != nullptr || head == nullptr) && "Failed to pop_back");
}

template <typename T>
void DoubleList<T>::clear() {
    while (!empty()) {
        pop_front();
    }
    assert(empty() && "Failed to clear list");
}

template <typename T>
void DoubleList<T>::display() const {
    DoubleNode<T> *node = head;
    while (node != nullptr) {
        std::cout << node->value << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

template <typename T>
void DoubleList<T>::display_reversed() const {
    DoubleNode<T> *node = tail;
    while (node != nullptr) {
        std::cout << node->value << " ";
        node = node->prev;
    }
    std::cout << std::endl;
}

#endif // DOUBLELIST_H