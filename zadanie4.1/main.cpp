#include <iostream>
#include <cassert>
#include "singlelist.h"

void test_push_back()
{
    SingleList<int> list;
    list.push_back(5);
    list.push_back(53);
    list.push_back(84);
    assert(list.size() == 3);
    assert(list.front() == 5);
    assert(list.back() == 84);
    std::cout << "test_push_back passed" << std::endl;
}

void test_push_front()
{
    SingleList<int> list;
    list.push_back(23);
    list.push_back(11);
    list.push_front(3);
    assert(list.size() == 3);
    assert(list.front() == 3);
    assert(list.back() == 11);
    std::cout << "test_push_front passed" << std::endl;
}

void test_pop_back()
{
    SingleList<int> list;
    list.push_back(12);
    list.push_back(61);
    list.push_back(7);
    list.pop_back();
    assert(list.size() == 2);
    assert(list.front() == 12);
    assert(list.back() == 61);
    std::cout << "test_pop_back passed" << std::endl;
}

void test_pop_front()
{
    SingleList<int> list;
    list.push_back(4);
    list.push_back(8);
    list.push_back(10);
    list.pop_front();
    assert(list.size() == 2);
    assert(list.front() == 8);
    assert(list.back() == 10);
    std::cout << "test_pop_front passed" << std::endl;
}

void test_clear()
{
    SingleList<int> list;
    list.push_back(10);
    list.push_back(92);
    list.push_back(33);
    list.clear();
    assert(list.size() == 0);
    std::cout << "test_clear passed" << std::endl;
}

void test_reverse()
{
    SingleList<int> list;
    list.push_back(90);
    list.push_back(2);
    list.push_back(84);
    list.reverse();
    assert(list.front() == 84);
    assert(list.back() == 90);
    std::cout << "test_reverse passed" << std::endl;
}

int main()
{
    test_push_back();
    test_push_front();
    test_pop_back();
    test_pop_front();
    test_clear();
    test_reverse();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}