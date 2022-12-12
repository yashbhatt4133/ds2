#include <iostream>
using namespace std;
template <typename T>
void bubblesort(int n)
{
    T a[n],t;
    int i,j;
    cout<<"Enter array elements - "<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
    cout<<"Sorted Array - "<<endl;
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
template <typename T>
void inssort(int n)
{
    T tmp,a[n];
    int i, j = 0;
    cout<<"Enter array elements - "<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for (i = 1; i < n; i++)
    {
        tmp = a[i];
        j = i - 1;
        while ((j >= 0) && (a[j] > tmp))
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = tmp;
    }
    cout<<"Sorted Array - "<<endl;
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
template <typename T>
void selsort(int n)
{
    T tmp,a[n];
    int i, j, s;
    cout<<"Enter array elements - "<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for (i = 0; i < n - 1; i++)
    {
        s = i;
        for (j = (i + 1); j < n; j++)
        {
            if (a[j] < a[s])
            {
                s = j;
            }
        }
        tmp = a[s];
        a[s] = a[i];
        a[i] = tmp;
    }
    cout<<"Sorted Array - "<<endl;
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
int main()
{
    int n, cht, chs;
    cout << "Enter the number of elements - " << endl;
    cin >> n;
    cout << "Enter 1 for integer input" << endl;
    cout << "Enter 2 for decimal input" << endl;
    cout << "Enter 3 for character input" << endl;
    cin >> cht;
    cout << "Enter 1 for bubble sort" << endl;
    cout << "Enter 2 for selection sort" << endl;
    cout << "Enter 3 for insertion sort" << endl;
    cin >> chs;
    switch (cht)
    {
    case 1:
        switch (chs)
        {
        case 1:
            bubblesort<int>(n);
            break;
        case 2:
            selsort<int>(n);
            break;
        case 3:
            inssort<int>(n);
            break;
        default:
            cout << "Invalid Input" << endl;
        }
        break;
    case 2:
        switch (chs)
        {
        case 1:
            bubblesort<double>(n);
            break;
        case 2:
            selsort<double>(n);
            break;
        case 3:
            inssort<double>(n);
            break;
        default:
            cout << "Invalid Input" << endl;
        }
        break;
    case 3:
        switch (chs)
        {
        case 1:
            bubblesort<char>(n);
            break;
        case 2:
            selsort<char>(n);
            break;
        case 3:
            inssort<char>(n);
            break;
        default:
            cout << "Invalid Input" << endl;
        }
        break;
    default:
        cout << "Invalid choice" << endl;
    }
}