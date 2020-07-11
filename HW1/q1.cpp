#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

vector<double> multiply(const vector<double> a, const vector<double> b)
{
    vector<double> c;
    for (int i = 0; i < a.size(); i++)
    {
        c.push_back(a[i] * b[i]);
    }
    return c;
}

int main()
{
    int arr1[] = {1, 2, 3}; 
    int arr2[] = {4, 5, 6};

    vector<double> a(arr1, arr1 + 3); 
    vector<double> b(arr2, arr2 + 3);
    vector<double> c;

    c = multiply(a, b);

    cout << " a b c\n";

    for (int i = 0; i < c.size(); i++) 
    {
        cout << setw(4) << a[i] << setw(4) << b[i] << setw(4) << c[i] << "\n";
    }
}