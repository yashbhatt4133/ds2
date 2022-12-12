




#include <iostream>
using namespace std;
template <typename T>

int binary_search(T arr[], int lb, int ub, T x)
{
    int mid = (lb + ub) / 2;
    if (lb > ub)
    {
        return -1;
    }
    else if (arr[mid] == x)
    {
        return mid;
    }
    else if (arr[mid] < x)
    {
        return binary_search(arr, mid + 1, ub, x);
    }
    else
    {
        return binary_search(arr, lb, mid - 1, x);
    }
}

int main()
{
    int n, x;
    cout << "Enter Size Of Array : ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " Array Elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the element to look for : ";
    cin >> x;
    int index = binary_search(arr, 0, n - 1, x);
    if (index == -1)
    {
        cout << "Not Found\n";
    }
    else
    {
        cout << "Found At " << index << endl;
    }
    return 0;
}