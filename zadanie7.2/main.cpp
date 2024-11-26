#include <iostream>
#include "arraystack.h"

void test_push()
{
    ArrayStack<int, 5> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    assert(stack.size() == 3);
    assert(stack.top() == 3);
    std::cout << "test_push passed" << std::endl;
}

void test_pop()
{
    ArrayStack<int, 5> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.pop();
    assert(stack.size() == 2);
    assert(stack.top() == 2);
    std::cout << "test_pop passed" << std::endl;
}

void test_top()
{
    ArrayStack<int, 5> stack;
    stack.push(1);
    stack.push(2);
    assert(stack.top() == 2);
    stack.pop();
    assert(stack.top() == 1);
    std::cout << "test_top passed" << std::endl;
}

void test_empty()
{
    ArrayStack<int, 5> stack;
    assert(stack.empty());
    stack.push(1);
    assert(!stack.empty());
    std::cout << "test_empty passed" << std::endl;
}

void test_full()
{
    ArrayStack<int, 3> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    assert(stack.full());
    std::cout << "test_full passed" << std::endl;
}

int main()
{
    test_push();
    test_pop();
    test_top();
    test_empty();
    test_full();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}