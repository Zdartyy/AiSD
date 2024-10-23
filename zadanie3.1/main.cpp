#include <iostream>
#include "arraylist.h"

int main()
{
    ArrayList<int> list(10);

    list.push_back(5);
    list.push_back(4);
    list.push_back(8);
    list.push_back(2);
    list.push_back(3);

    std::cout << "List after adding elements: ";
    list.display();

    std::cout << "First element: " << list.front() << std::endl;
    std::cout << "Last element: " << list.back() << std::endl;

    list.pop_front();
    list.pop_back();

    std::cout << "List after removing first and last elements: ";
    list.display();

    list.sort();

    std::cout << "Sorted list: ";
    list.display();

    list.reverse();

    std::cout << "Reversed list: ";
    list.display();

    list.clear();

    std::cout << "List after clearing: ";
    list.display();

    return 0;
}