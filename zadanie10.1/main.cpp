#include "RandomBinaryTree.h"
#include <iostream>
using namespace std;

int main()
{
    RandomBinaryTree<int> tree;

    tree.insert(3);
    tree.insert(1);
    tree.insert(5);
    tree.insert(2);
    tree.insert(3);
    tree.insert(6);

    cout << "Liczba liści (rekurencyjnie): " << tree.calc_leaves_recursive() << endl;
    cout << "Liczba liści (iteracyjnie): " << tree.calc_leaves_iterative() << endl;

    return 0;
}