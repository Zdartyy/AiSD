#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <array>
#include <cassert>
#include <iostream>

template <typename T, std::size_t N>
class ArrayStack
{
    std::array<T, N> data;
    std::size_t top_index;

public:
    ArrayStack() : top_index(0) {}

    bool empty() const { return top_index == 0; }
    bool full() const { return top_index == N; }
    std::size_t size() const { return top_index; }

    void push(const T &item)
    {
        assert(!full() && "Stack overflow");
        data[top_index++] = item;
    }

    void pop()
    {
        assert(!empty() && "Stack underflow");
        --top_index;
    }

    T &top()
    {
        assert(!empty() && "Stack is empty");
        return data[top_index - 1];
    }

    const T &top() const
    {
        assert(!empty() && "Stack is empty");
        return data[top_index - 1];
    }
};

#endif // ARRAYSTACK_H