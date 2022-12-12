#include <bits/stdc++.h>
using namespace std;
template <typename T>
void print(T *arr, int n)
{
    cout << "{ ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << ", ";
    cout << "}\n";
}

// INSERTION
template <typename T>
void insertion_sort(T *arr, int size)
{
    int c = 0;
    for (int i = 1; i < size; i++)
    {
        int backup = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > backup)
        {
            arr[j + 1] = arr[j];
            j--;
            c++;
        }
        arr[j + 1] = backup;
        c++;
    }
    cout << c << " swaps done\n";
}
// BUBBLE
template <typename T>
void bubble_sort(T *arr, int size)
{
    int c = 0, s = 0;
    for (int i = 0; i < size - 1; i++)
    {
        int tc = 0;
        int ts = 0;
        for (int j = 0; j < size - i - 1; j++)
        {

            c++;
            tc++;
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                s++;
                ts++;
            }
            print(arr, size);
        }
        cout << "PASS " << i << '\n';
        cout << tc << " comparisions done\n";
        cout << ts << " swaps done\n";
    }
    cout << c << " comparisions done\n";
    cout << s << " swaps done\n";
    cout << "FINALLY :";
    print(arr, size);
}
// SELECTION
template <typename T>
void selection_sort(T *arr, int size)
{
    int c = 0,s=0;
    for (int i = 0; i < size - 1; i++)
    {
        int tc = 0;
        int min_ele = i;
        for (int j = i + 1; j < size; j++){
            c++;
            tc++;
            if (arr[j] < arr[min_ele])
                min_ele = j;
        }
        cout<<"i = "<<i<<" COMPARISIONS = "<<tc<<"\n";
        swap(arr[i], arr[min_ele]);
        print(arr,size);
        s++;
    }
    cout << c << " comparisions done\n";
    cout << s << " swaps done\n";
}

int main()
{
    int n, i;
    cout << "Enter Size Of Array : ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " Array Elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Initial Array :";
    print(arr, n);
    cout << "1>Insertion 2>Bubble 3>Selection\n";
    cout << "Which Sorting do you want? : ";
    cin >> i;
    switch (i)
    {
    case 1:
        insertion_sort(arr, n);
        break;
    case 2:
        bubble_sort(arr, n);
        break;
    case 3:
        selection_sort(arr, n);
        break;
    default:
        cout << "Invalid Input,doing Bubble SORT\n";
        bubble_sort(arr, n);
    }
    cout << "Sorted Array : ";
    print(arr, n);

    return 0;
}