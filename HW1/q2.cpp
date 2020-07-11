#include <iostream>
#include <vector>

using namespace std;

bool odd_product(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = i+1; j < vec.size(); j++)
        {
            if ((vec[i] * vec[j]) % 2 != 0)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    vector<int> vect1 {1, 2, 3, 4};
    vector<int> vect2 {1, 2, 4, 6};
    cout << odd_product(vect1);
    cout << endl;
    cout << odd_product(vect2);

    return 0;
}