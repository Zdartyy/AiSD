#ifndef RANDOM_BINARY_TREE_H
#define RANDOM_BINARY_TREE_H

#include <iostream>
#include <queue>
#include <cassert>

template <typename T>
class RandomBinaryTree
{
    struct BSTNode
    {
        T value;
        BSTNode *left;
        BSTNode *right;
        BSTNode(const T &val) : value(val), left(nullptr), right(nullptr) {}
    };

    BSTNode *root;

    int calc_leaves_recursive(BSTNode *node) const
    {
        if (node == nullptr)
            return 0;
        if (node->left == nullptr && node->right == nullptr)
            return 1;
        return calc_leaves_recursive(node->left) + calc_leaves_recursive(node->right);
    }

public:
    RandomBinaryTree() : root(nullptr) {} // konstruktor domyślny
    ~RandomBinaryTree() { clear(); }      // trzeba wyczyścić (rekurencyjnie)
    void clear()
    {
        delete root;
        root = nullptr;
    }
    bool empty() const { return root == nullptr; }
    T &top()
    {
        assert(root != nullptr);
        return root->value;
    } // podgląd korzenia
    void insert(const T &item) { root = insert(root, item); }
    // void remove(const T& item); // na razie nie usuwamy elementów
    //  Szukając element dostajemy wskaźnik do elementu lub nullptr.
    T *search(const T &item) const
    {
        auto ptr = search(root, item);
        return ((ptr == nullptr) ? nullptr : &(ptr->value));
    }
    T *find_min() const;
    T *find_max() const;
    void preorder() { preorder(root); }
    void inorder() { inorder(root); }
    void postorder() { postorder(root); }
    void iter_preorder();
    void iter_inorder();   // trudne
    void iter_postorder(); // trudne
    void bfs();            // przejście poziomami (wszerz)
    void display() { display(root, 0); }

    // Metody bezpośrednio odwołujące się do node.
    // Mogą działać na poddrzewie.
    BSTNode *insert(BSTNode *node, const T &item); // zwraca nowy korzeń
    BSTNode *search(BSTNode *node, const T &item) const;
    void preorder(BSTNode *node);
    void inorder(BSTNode *node);
    void postorder(BSTNode *node);
    void display(BSTNode *node, int level);
    virtual void visit(BSTNode *node)
    {
        assert(node != nullptr);
        std::cout << "visiting " << node->value << std::endl;
    }

    int calc_leaves_recursive() const
    {
        return calc_leaves_recursive(root);
    }

    int calc_leaves_iterative() const
    {
        if (root == nullptr)
            return 0;
        int leafCount = 0;
        std::queue<BSTNode *> Q;
        Q.push(root);
        while (!Q.empty())
        {
            BSTNode *node = Q.front();
            Q.pop();
            if (node->left == nullptr && node->right == nullptr)
            {
                leafCount++;
            }
            if (node->left != nullptr)
            {
                Q.push(node->left);
            }
            if (node->right != nullptr)
            {
                Q.push(node->right);
            }
        }
        return leafCount;
    }
};

template <typename T>
typename RandomBinaryTree<T>::BSTNode *RandomBinaryTree<T>::insert(BSTNode *node, const T &item)
{
    if (node == nullptr)
    {
        return new BSTNode(item);
    }
    if (item < node->value)
    {
        node->left = insert(node->left, item);
    }
    else
    {
        node->right = insert(node->right, item);
    }
    return node;
}

template <typename T>
typename RandomBinaryTree<T>::BSTNode *RandomBinaryTree<T>::search(BSTNode *node, const T &item) const
{
    if (node == nullptr || node->value == item)
    {
        return node;
    }
    if (item < node->value)
    {
        return search(node->left, item);
    }
    else
    {
        return search(node->right, item);
    }
}

template <typename T>
void RandomBinaryTree<T>::display(BSTNode *node, int level)
{
    if (node == nullptr)
        return;
    display(node->right, level + 1);
    for (int i = 0; i < level; ++i)
    {
        std::cout << "   ";
    }
    std::cout << node->value << std::endl;
    display(node->left, level + 1);
}

#endif // RANDOM_BINARY_TREE_H