#include "deque.h"
#include <iostream>

int main()
{
    Deque<int> deque(5);

    deque.push_back(1);
    deque.push_back(2);
    deque.push_back(3);
    deque.push_front(0);
    deque.push_front(-1);

    std::cout << "Front element: " << deque.get_front() << std::endl;
    std::cout << "Back element: " << deque.get_back() << std::endl;

    deque.pop_front();
    deque.pop_back();

    std::cout << "Front element after pop: " << deque.get_front() << std::endl;
    std::cout << "Back element after pop: " << deque.get_back() << std::endl;

    return 0;
}