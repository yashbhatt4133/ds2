#include <iostream>
using namespace std;
int minimum(int arr[], int lb, int ub)
{   //O(log n)
    int mid = (ub+lb) / 2;
    if (lb == ub)
    {//single element left
        return arr[lb];
    }
    else if (lb > ub)
    {//handles unrotated case
        return arr[0];
    }
    else if (arr[mid] < arr[mid - 1] && mid > lb)
    {//eg. 10 20 30 1 2 3 4 (1<30) found at mid,and not at corner case
        return arr[mid];
    }
    else if (arr[mid+1] < arr[mid] && mid < ub)
    {//eg. 10 20 30 1 2 (1 < 30) found at mid +1, and not at corner case
        return arr[mid + 1];
    }
    else if (arr[ub] > arr[mid])
    {//take left half  
        return minimum(arr, lb, mid - 1);
    }
    else
    {//take right half
        return minimum(arr, mid + 1, ub);
    }
}
int main()
{
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {10, 20, 130, 4, 5};
    int arr3[] = {10, 11, 12, 32, 33, 4, 5};
    int arr[] = { 5, 6, 1, 2, 3, 4 };
    cout << minimum(arr1, 0, 4) << '\n';
    cout << minimum(arr2, 0, 4) << '\n';
    cout << minimum(arr3, 0, 6) << '\n';
    cout << minimum(arr, 0, 5) << '\n';
    return 0;
}