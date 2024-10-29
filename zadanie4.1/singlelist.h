#ifndef SINGLELIST_H
#define SINGLELIST_H

#include <iostream> // deklaracje strumieni cout, cin, cerr
#include <cassert>  // assert()

template <typename T>
struct SingleNode
{
    T value;
    SingleNode *next;
    SingleNode() : value(T()), next(nullptr) {} // konstruktor domyslny
    SingleNode(const T &item, SingleNode *ptr = nullptr) : value(item), next(ptr) {}
    ~SingleNode() {} // destruktor
};

template <typename T>
class SingleList
{
    SingleNode<T> *head, *tail;

public:
    SingleList() : head(nullptr), tail(nullptr) {}
    ~SingleList(); // tu trzeba wyczyscic wezly

    SingleList(const SingleList &other);            // copy constructor
    SingleList &operator=(const SingleList &other); // copy assignment operator, return *this

    bool empty() const { return head == nullptr; }
    std::size_t size() const;       // O(n) bo trzeba policzyc
    void push_front(const T &item); // O(1), L.push_front(item)
    void push_back(const T &item);  // O(1), L.push_back(item)
    T &front() const
    {
        assert(!empty());
        return head->value;
    } // zwraca poczatek, nie usuwa
    T &back() const
    {
        assert(!empty());
        return tail->value;
    } // zwraca koniec, nie usuwa
    void pop_front();     // usuwa poczatek O(1)
    void pop_back();      // usuwa koniec O(n)
    void clear();         // czyszczenie listy z elementow O(n)
    void display() const; // O(n)
    void reverse();       // O(n)
};

template <typename T>
SingleList<T>::~SingleList()
{
    while (!empty())
    {
        pop_front();
    }
}

template <typename T>
std::size_t SingleList<T>::size() const
{
    std::size_t count = 0;
    SingleNode<T> *node = head;
    while (node != nullptr)
    {
        ++count;
        node = node->next;
    }
    return count;
}

template <typename T>
void SingleList<T>::push_front(const T &item)
{
    if (!empty())
    {
        head = new SingleNode<T>(item, head);
    }
    else
    {
        head = tail = new SingleNode<T>(item);
    }
    assert(head != nullptr && "Failed to push_front");
}

template <typename T>
void SingleList<T>::push_back(const T &item)
{
    if (!empty())
    {
        tail->next = new SingleNode<T>(item);
        tail = tail->next;
    }
    else
    {
        head = tail = new SingleNode<T>(item);
    }
    assert(tail != nullptr && "Failed to push_back");
}

template <typename T>
void SingleList<T>::pop_front()
{
    assert(!empty() && "List is empty");
    SingleNode<T> *node = head; // zapamietujemy
    if (head == tail)
    { // jeden wezel na liscie
        head = tail = nullptr;
    }
    else
    { // wiecej niz jeden wezel na liscie
        head = head->next;
    }
    delete node;
    assert((head != nullptr || tail == nullptr) && "Failed to pop_front");
}

template <typename T>
void SingleList<T>::pop_back()
{
    assert(!empty() && "List is empty");
    SingleNode<T> *node = tail; // zapamietujemy
    if (head == tail)
    { // jeden wezel na liscie
        head = tail = nullptr;
    }
    else
    { // wiecej niz jeden wezel na liscie
        // Szukamy poprzednika ogona.
        SingleNode<T> *before = head;
        while (before->next != tail)
        {
            before = before->next;
        }
        tail = before;
        tail->next = nullptr;
    }
    delete node;
    assert((tail != nullptr || head == nullptr) && "Failed to pop_back");
}

template <typename T>
void SingleList<T>::clear()
{
    while (!empty())
    {
        pop_front();
    }
    assert(empty() && "Failed to clear list");
}

template <typename T>
void SingleList<T>::display() const
{
    SingleNode<T> *node = head;
    while (node != nullptr)
    {
        std::cout << node->value << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

template <typename T>
void SingleList<T>::reverse()
{
    SingleNode<T> *prev = nullptr, *current = head, *next = nullptr;
    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    std::swap(head, tail);
    assert((head == nullptr || head->next != tail) && "Failed to reverse list");
}

#endif // SINGLELIST_H