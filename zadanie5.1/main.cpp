#include <iostream>
#include <cassert>
#include "doublelist.h"

void test_push_back() {
    DoubleList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    assert(list.size() == 3);
    assert(list.front() == 1);
    assert(list.back() == 3);
    std::cout << "test_push_back passed" << std::endl;
}

void test_push_front() {
    DoubleList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_front(0);
    assert(list.size() == 3);
    assert(list.front() == 0);
    assert(list.back() == 2);
    std::cout << "test_push_front passed" << std::endl;
}

void test_pop_back() {
    DoubleList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.pop_back();
    assert(list.size() == 2);
    assert(list.front() == 1);
    assert(list.back() == 2);
    std::cout << "test_pop_back passed" << std::endl;
}

void test_pop_front() {
    DoubleList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.pop_front();
    assert(list.size() == 2);
    assert(list.front() == 2);
    assert(list.back() == 3);
    std::cout << "test_pop_front passed" << std::endl;
}

void test_clear() {
    DoubleList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.clear();
    assert(list.size() == 0);
    std::cout << "test_clear passed" << std::endl;
}

void test_display() {
    DoubleList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    std::cout << "List: ";
    list.display();
    std::cout << "test_display passed" << std::endl;
}

void test_display_reversed() {
    DoubleList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    std::cout << "Reversed List: ";
    list.display_reversed();
    std::cout << "test_display_reversed passed" << std::endl;
}

void test_copy_constructor() {
    DoubleList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    DoubleList<int> copy(list);
    assert(copy.size() == 3);
    assert(copy.front() == 1);
    assert(copy.back() == 3);
    std::cout << "test_copy_constructor passed" << std::endl;
}

void test_assignment_operator() {
    DoubleList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    DoubleList<int> copy;
    copy = list;
    assert(copy.size() == 3);
    assert(copy.front() == 1);
    assert(copy.back() == 3);
    std::cout << "test_assignment_operator passed" << std::endl;
}

int main() {
    test_push_back();
    test_push_front();
    test_pop_back();
    test_pop_front();
    test_clear();
    test_display();
    test_display_reversed();
    test_copy_constructor();
    test_assignment_operator();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}