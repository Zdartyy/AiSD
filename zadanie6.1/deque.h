#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include <cassert>

template <typename T>
class Deque
{
private:
    T *array;
    int front;
    int rear;
    int capacity;
    int count;

public:
    Deque(int size);
    ~Deque();

    void push_front(const T &item);
    void push_back(const T &item);
    void pop_front();
    void pop_back();
    T &get_front() const;
    T &get_back() const;
    bool is_empty() const;
    bool is_full() const;
    int size() const;
};

template <typename T>
Deque<T>::Deque(int size) : capacity(size + 1), front(0), rear(0), count(0)
{
    array = new T[capacity];
}

template <typename T>
Deque<T>::~Deque()
{
    delete[] array;
}

template <typename T>
void Deque<T>::push_front(const T &item)
{
    assert(!is_full() && "Deque is full");
    front = (front - 1 + capacity) % capacity;
    array[front] = item;
    count++;
}

template <typename T>
void Deque<T>::push_back(const T &item)
{
    assert(!is_full() && "Deque is full");
    array[rear] = item;
    rear = (rear + 1) % capacity;
    count++;
}

template <typename T>
void Deque<T>::pop_front()
{
    assert(!is_empty() && "Deque is empty");
    front = (front + 1) % capacity;
    count--;
}

template <typename T>
void Deque<T>::pop_back()
{
    assert(!is_empty() && "Deque is empty");
    rear = (rear - 1 + capacity) % capacity;
    count--;
}

template <typename T>
T &Deque<T>::get_front() const
{
    assert(!is_empty() && "Deque is empty");
    return array[front];
}

template <typename T>
T &Deque<T>::get_back() const
{
    assert(!is_empty() && "Deque is empty");
    return array[(rear - 1 + capacity) % capacity];
}

template <typename T>
bool Deque<T>::is_empty() const
{
    return count == 0;
}

template <typename T>
bool Deque<T>::is_full() const
{
    return count == capacity - 1;
}

template <typename T>
int Deque<T>::size() const
{
    return count;
}

#endif // DEQUE_H