#ifndef MYPRIORITYQUEUE_H
#define MYPRIORITYQUEUE_H

#include <vector>
#include <algorithm> // make_heap, push_heap, pop_heap
#include <iostream>

template <typename T>
class MyPriorityQueue
{
    std::vector<T> lst; // działa domyślny konstruktor dla std::vector
public:
    MyPriorityQueue(std::size_t s = 10) { lst.reserve(s); } // default constructor
    ~MyPriorityQueue() { lst.clear(); }
    MyPriorityQueue(const MyPriorityQueue &other);            // copy constructor
    MyPriorityQueue(MyPriorityQueue &&other);                 // move constructor
    MyPriorityQueue &operator=(const MyPriorityQueue &other); // copy assignment operator
    MyPriorityQueue &operator=(MyPriorityQueue &&other);      // move assignment operator
    bool empty() const { return lst.empty(); }
    std::size_t size() const { return lst.size(); } // liczba elementów w kolejce
    void push(const T &item);                       // dodanie do kolejki
    void push(T &&item);                            // dodanie do kolejki
    T &top() { return lst.front(); }                // zwraca element największy, nie usuwa
    void pop();                                     // usuwa element największy
    void clear() { lst.clear(); }                   // czyszczenie listy z elementów
    void display();                                 // nie oczekujemy jakiegoś uporządkowania elementów
};

template <typename T>
MyPriorityQueue<T>::MyPriorityQueue(const MyPriorityQueue &other) : lst(other.lst)
{
    std::make_heap(lst.begin(), lst.end());
}

template <typename T>
MyPriorityQueue<T>::MyPriorityQueue(MyPriorityQueue &&other) : lst(std::move(other.lst))
{
    std::make_heap(lst.begin(), lst.end());
}

template <typename T>
MyPriorityQueue<T> &MyPriorityQueue<T>::operator=(const MyPriorityQueue &other)
{
    if (this != &other)
    {
        lst = other.lst;
        std::make_heap(lst.begin(), lst.end());
    }
    return *this;
}

template <typename T>
MyPriorityQueue<T> &MyPriorityQueue<T>::operator=(MyPriorityQueue &&other)
{
    if (this != &other)
    {
        lst = std::move(other.lst);
        std::make_heap(lst.begin(), lst.end());
    }
    return *this;
}

template <typename T>
void MyPriorityQueue<T>::push(const T &item)
{
    lst.push_back(item);
    std::push_heap(lst.begin(), lst.end());
}

template <typename T>
void MyPriorityQueue<T>::push(T &&item)
{
    lst.push_back(std::move(item));
    std::push_heap(lst.begin(), lst.end());
}

template <typename T>
void MyPriorityQueue<T>::pop()
{
    std::pop_heap(lst.begin(), lst.end());
    lst.pop_back();
}

template <typename T>
void MyPriorityQueue<T>::display()
{
    for (const auto &item : lst)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

#endif // MYPRIORITYQUEUE_H