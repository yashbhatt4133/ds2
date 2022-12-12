#include <iostream>
#include <cmath>
using namespace std;
int solve(int *arr, int l, int r)
{
    if ((arr[l] < arr[r]) || r == 0)
        return arr[0];

    int mid = int(ceil((float(r) + float(l)) / 2.0));

    // checking mid is min
    if (arr[mid] < arr[mid - 1])
        return arr[mid];

    if (arr[l] < arr[mid])
        return solve(arr, mid, r);
    else
        return solve(arr, l, mid);
}
int main()
{
    // int arr[] = {3, 4, 7, 10, 12, 20, 30, 40, 1};
    // int arr[] = {0, 3, 4, 7, 10, 12, 20, 30, 40, 1};
    // int arr[] = {3, 4, 7, 10, 12, 1, 2};
    // int arr[] = {1};
    int arr[] = {45, 1, 3, 4, 7, 10, 12, 20, 30, 40};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << solve(arr, 0, size - 1);
    return 0;
}