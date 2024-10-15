#include <iostream>
#include <vector>
using namespace std;

template <typename Iterator>
void bubbleSort(Iterator start, Iterator end)
{

    for (Iterator i = start; i != end; ++i)
    {
        for (Iterator j = start; j < end - (i - start) - 1; ++j)
        {
            if (*(j + 1) < *j)
            {
                auto temp = *j;
                *j = *(j + 1);
                *(j + 1) = temp;
            }
        }
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
    vector<double> numbers = {2.3, 5.6, 6.7, 4.5, 1.2, 3.4, 7.8, 3.2, 1.87};

    bubbleSort(numbers.begin(), numbers.end());

    cout << "Sorted array: \n";
    printArray(numbers.begin(), numbers.end());

    return 0;
}