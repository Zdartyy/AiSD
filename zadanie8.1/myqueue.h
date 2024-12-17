#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <iostream>
#include <cassert>

template <typename T>
class MyQueue
{
    T *tab;
    std::size_t msize; // największa możliwa liczba elementów plus jeden
    std::size_t head;  // pierwszy do pobrania
    std::size_t tail;  // pierwsza wolna pozycja
public:
    MyQueue(std::size_t s = 10) : msize(s + 1), head(0), tail(0)
    {
        tab = new T[s + 1];
        assert(tab != nullptr);
    } // default constructor
    ~MyQueue() { delete[] tab; }
    MyQueue(const MyQueue &other);            // copy constructor
    MyQueue(MyQueue &&other);                 // move constructor
    MyQueue &operator=(const MyQueue &other); // copy assignment operator
    MyQueue &operator=(MyQueue &&other);      // move assignment operator
    bool empty() const { return head == tail; }
    bool full() const { return (tail + 1) % msize == head; }
    std::size_t size() const { return (tail - head + msize) % msize; }
    std::size_t max_size() const { return msize - 1; }
    void push(const T &item); // dodanie na koniec
    void push(T &&item);      // dodanie na koniec
    T &front()
    {
        assert(!empty());
        return tab[head];
    } // zwraca początek
    T &back()
    {
        assert(!empty());
        return tab[(tail + msize - 1) % msize];
    } // zwraca koniec
    void pop();   // usuwa początek
    void clear(); // czyszczenie listy z elementów
    void display();
};

template <typename T>
MyQueue<T>::MyQueue(const MyQueue &other) : msize(other.msize), head(other.head), tail(other.tail)
{
    tab = new T[msize];
    assert(tab != nullptr);
    for (std::size_t i = 0; i < msize; ++i)
    {
        tab[i] = other.tab[i];
    }
}

template <typename T>
MyQueue<T>::MyQueue(MyQueue &&other) : msize(other.msize), head(other.head), tail(other.tail), tab(other.tab)
{
    other.msize = 1;
    other.head = other.tail = 0;
    other.tab = nullptr;
}

template <typename T>
MyQueue<T> &MyQueue<T>::operator=(const MyQueue &other)
{
    if (this != &other)
    {
        delete[] tab;
        msize = other.msize;
        head = other.head;
        tail = other.tail;
        tab = new T[msize];
        assert(tab != nullptr);
        for (std::size_t i = 0; i < msize; ++i)
        {
            tab[i] = other.tab[i];
        }
    }
    return *this;
}

template <typename T>
MyQueue<T> &MyQueue<T>::operator=(MyQueue &&other)
{
    if (this != &other)
    {
        delete[] tab;
        msize = other.msize;
        head = other.head;
        tail = other.tail;
        tab = other.tab;
        other.msize = 1;
        other.head = other.tail = 0;
        other.tab = nullptr;
    }
    return *this;
}

template <typename T>
void MyQueue<T>::push(const T &item)
{
    assert(!full());
    tab[tail] = item;
    tail = (tail + 1) % msize;
}

template <typename T>
void MyQueue<T>::push(T &&item)
{
    assert(!full());
    tab[tail] = std::move(item);
    tail = (tail + 1) % msize;
}

template <typename T>
void MyQueue<T>::pop()
{
    assert(!empty());
    head = (head + 1) % msize;
}

template <typename T>
void MyQueue<T>::clear()
{
    head = tail = 0;
}

template <typename T>
void MyQueue<T>::display()
{
    for (std::size_t i = head; i != tail; i = (i + 1) % msize)
    {
        std::cout << tab[i] << " ";
    }
    std::cout << std::endl;
}

#endif // MYQUEUE_H