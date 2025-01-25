#include "BinarySearchTree.h"
#include <iostream>
using namespace std;

int main()
{
    BinarySearchTree<int> tree;

    tree.insert(10);
    tree.insert(5);
    tree.insert(14);
    tree.insert(2);
    tree.insert(7);
    tree.insert(12);
    tree.insert(17);

    int *minVal = tree.find_min();
    int *maxVal = tree.find_max();

    if (minVal != nullptr)
    {
        cout << "Minimum value in the tree: " << *minVal << endl;
    }
    else
    {
        cout << "The tree is empty, no minimum value." << endl;
    }

    if (maxVal != nullptr)
    {
        cout << "Maximum value in the tree: " << *maxVal << endl;
    }
    else
    {
        cout << "The tree is empty, no maximum value." << endl;
    }

    return 0;
}