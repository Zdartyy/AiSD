#include "mypriorityqueue.h"
#include <iostream>
#include <cassert>

void test_push()
{
    MyPriorityQueue<int> pq;
    pq.push(3);
    pq.push(1);
    pq.push(4);
    pq.push(1);
    pq.push(5);
    assert(pq.size() == 5);
    assert(pq.top() == 5);
    std::cout << "test_push passed" << std::endl;
}

void test_pop()
{
    MyPriorityQueue<int> pq;
    pq.push(3);
    pq.push(1);
    pq.push(4);
    pq.push(1);
    pq.push(5);
    pq.pop();
    assert(pq.size() == 4);
    assert(pq.top() == 4);
    std::cout << "test_pop passed" << std::endl;
}

void test_clear()
{
    MyPriorityQueue<int> pq;
    pq.push(3);
    pq.push(1);
    pq.push(4);
    pq.push(1);
    pq.push(5);
    pq.clear();
    assert(pq.size() == 0);
    assert(pq.empty());
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