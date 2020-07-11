#include <iostream>
#include <vector> 

using namespace std;

template <class T>
T Binary_Search(vector<int> &v, int x)
{
    int mid, low = 0;
    int high = (int)v.size() - 1;
    int num_comp = 0;
    while (low < high)
    {
        mid = (low + high) / 2;
        if (num_comp++, v[mid] < x)
        {
            low = mid + 1;
        }
        else 
        {
            high = mid;
        }
    }
    if (num_comp++, x == v[low]) //found
    {
        return low;        
    }  
    throw Unsuccessful_Search(); //not found
    }
}

int main () 
{
    vector<int> vect1 {1, 2, 3, 4, 10, 12, 15};
    vector<int> vect2 {1, 2, 4, 6, 11, 15, 17};
    cout << Binary_Search<int>(vect1, 3);
    cout << endl;
    cout << Binary_Search<int>(vect2, 0);
}