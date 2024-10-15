#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename Iterator>
void mergeSort(Iterator start, Iterator end)
{
    auto length = std::distance(start, end);

    if (length > 1)
    {
        Iterator middle = start + length / 2;

        mergeSort(start, middle);

        mergeSort(middle, end);

        std::inplace_merge(start, middle, end);
    }
}

template <typename Iterator>
void printArray(Iterator start, Iterator end)
{
    for (Iterator it = start; it != end; ++it)
        cout << *it << " ";
    cout << endl;
}

int main()
{
    vector<int> numbers = {12, 2, 5, 14, 6, 7, 4, 5, 1, 2, 3, 4, 19, 8, 3, 14, 1, 8, 7};

    mergeSort(numbers.begin(), numbers.end());

    cout << "Sorted array: \n";
    printArray(numbers.begin(), numbers.end());

    return 0;
}