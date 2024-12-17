#include "myqueue.h"
#include <iostream>
#include <cassert>

void test_push()
{
    MyQueue<int> queue(5);
    queue.push(1);
    queue.push(2);
    queue.push(3);
    assert(queue.size() == 3);
    assert(queue.front() == 1);
    assert(queue.back() == 3);
    std::cout << "test_push passed" << std::endl;
}

void test_pop()
{
    MyQueue<int> queue(5);
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.pop();
    assert(queue.size() == 2);
    assert(queue.front() == 2);
    std::cout << "test_pop passed" << std::endl;
}

void test_clear()
{
    MyQueue<int> queue(5);
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.clear();
    assert(queue.size() == 0);
    assert(queue.empty());
    std::cout << "test_clear passed" << std::endl;
}

int main()
{
    test_push();
    test_pop();
    test_clear();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}