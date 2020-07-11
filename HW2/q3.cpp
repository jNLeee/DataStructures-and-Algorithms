#include <iostream>
using namespace std;

int arrayMax(int array[], int size, int max)
{
    int max_val = max;
    if (size == 0)
    {
        return max_val;
    }
    if (array[size-1] > max_val)
    {
        max_val = array[size-1];
    }
    return arrayMax(array, size-1, max_val);
}

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 15};
    int size = 11;
    int max = 0;
    cout << "The max value in the array is " << arrayMax(array, size, max);
    return 0;
}