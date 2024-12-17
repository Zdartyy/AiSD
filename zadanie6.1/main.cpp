#include "deque.h"
#include <iostream>
#include <cassert>

void test_push_front()
{
    MyDeque<int> deque(5);
    deque.push_front(1);
    deque.push_front(2);
    deque.push_front(3);
    assert(deque.size() == 3);
    assert(deque.front() == 3);
    std::cout << "test_push_front passed" << std::endl;
}

void test_push_back()
{
    MyDeque<int> deque(5);
    deque.push_back(1);
    deque.push_back(2);
    deque.push_back(3);
    assert(deque.size() == 3);
    assert(deque.back() == 3);
    std::cout << "test_push_back passed" << std::endl;
}

void test_pop_front()
{
    MyDeque<int> deque(5);
    deque.push_back(1);
    deque.push_back(2);
    deque.push_back(3);
    deque.pop_front();
    assert(deque.size() == 2);
    assert(deque.front() == 2);
    std::cout << "test_pop_front passed" << std::endl;
}

void test_pop_back()
{
    MyDeque<int> deque(5);
    deque.push_back(1);
    deque.push_back(2);
    deque.push_back(3);
    deque.pop_back();
    assert(deque.size() == 2);
    assert(deque.back() == 2);
    std::cout << "test_pop_back passed" << std::endl;
}

void test_clear()
{
    MyDeque<int> deque(5);
    deque.push_back(1);
    deque.push_back(2);
    deque.push_back(3);
    deque.clear();
    assert(deque.size() == 0);
    assert(deque.empty());
    std::cout << "test_clear passed" << std::endl;
}

int main()
{
    test_push_front();
    test_push_back();
    test_pop_front();
    test_pop_back();
    test_clear();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
