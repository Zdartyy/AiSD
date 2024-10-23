#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>
#include <cassert>
#include <algorithm>

template <typename T>
class ArrayList
{
    T *tab;
    int msize;
    int last;

public:
    ArrayList(int s = 10) : msize(s), last(0)
    {
        assert(s > 0);
        tab = new T[s];
        assert(tab != nullptr);
    }

    ~ArrayList() { delete[] tab; }

    ArrayList(const ArrayList &other) : msize(other.msize), last(other.last)
    {
        tab = new T[msize];
        assert(tab != nullptr);
        std::copy(other.tab, other.tab + other.last, tab);
    }

    ArrayList &operator=(const ArrayList &other)
    {
        if (this != &other)
        {
            delete[] tab;
            msize = other.msize;
            last = other.last;
            tab = new T[msize];
            assert(tab != nullptr);
            std::copy(other.tab, other.tab + other.last, tab);
        }
        return *this;
    }

    bool empty() const { return last == 0; }
    bool full() const { return last == msize; }
    int size() const { return last; }
    int max_size() const { return msize; }

    void push_front(const T &item)
    {
        assert(!full() && "List is full");
        for (int i = last; i > 0; --i)
        {
            tab[i] = tab[i - 1];
        }
        tab[0] = item;
        ++last;
    }

    void push_back(const T &item)
    {
        assert(!full() && "List is full");
        tab[last++] = item;
    }

    T &front()
    {
        assert(!empty() && "List is empty");
        return tab[0];
    }

    T &back()
    {
        assert(!empty() && "List is empty");
        return tab[last - 1];
    }

    void pop_front()
    {
        assert(!empty() && "List is empty");
        for (int i = 0; i < last - 1; ++i)
        {
            tab[i] = tab[i + 1];
        }
        --last;
    }

    void pop_back()
    {
        assert(!empty() && "List is empty");
        --last;
    }

    void clear()
    {
        for (int i = 0; i < last; ++i)
        {
            tab[i].~T();
        }
        last = 0;
    }

    void display() const
    {
        for (int i = 0; i < last; ++i)
        {
            std::cout << tab[i] << " ";
        }
        std::cout << std::endl;
    }

    void reverse()
    {
        std::reverse(tab, tab + last);
    }

    void sort()
    {
        std::sort(tab, tab + last);
    }
};

#endif // ARRAYLIST_H