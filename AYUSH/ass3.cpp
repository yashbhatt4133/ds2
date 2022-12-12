#include <iostream>
using namespace std;
template <typename T>
void bub_sort()
{
    cout << "Enter number of values\n";
    int s;
    cin >> s;
    T arr[s];
    cout << "Enter the values:\n";
    for (int i = 0; i < s; i++)
        cin >> arr[i];
    T temp = 0;
    for (int i = 0; i < s - 1; i++)
    {
        for (int j = 0; j < s - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    cout << "Sorted array: " << endl;
    for (int j = 0; j < s; j++)
    {
        cout << arr[j] << " ";
    }
    cout << endl;
}

template <typename T>
void ins_sort()
{
    cout << "Enter number of values\n";
    int s;
    cin >> s;
    T arr[s];
    cout << "Enter the values:\n";
    for (int i = 0; i < s; i++)
        cin >> arr[i];
    int j = 0;
    T key;
    for (int i = 1; i < s; i++)
    {
        j = i - 1;
        T c = 0;
        key = arr[i];
        while (j >= 0 && key < arr[j])
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    cout << "Sorted array:";
    for (int i = 0; i < s; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template <typename T>
void sel_sort()
{
    cout << "Enter number of values\n";
    int s;
    cin >> s;
    T arr[s];
    cout << "Enter the values:\n";
    for (int i = 0; i < s; i++)
        cin >> arr[i];
    for (int i = 0; i < s - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < s; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        swap(arr[i], arr[min]);
    }
    cout << "Sorted array: " << endl;
    for (int i = 0; i < s; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    cout << "Enter:\n1 for integer input\n2 for floating input\n3 for character input\n";
    int c;
    cin >> c;
    cout << "Enter:\n1 for bubble sort\n2 for insertion sort\n3 for selection sort\n";
    int t;
    cin >> t;
    switch (c)
    {
    case 1:
        switch (t)
        {
        case 1:
            bub_sort<int>();
            break;
        case 2:
            ins_sort<int>();
            break;
        case 3:
            sel_sort<int>();
            break;
        default:
            cout << "Wrong input of sorting algo";
        }
        break;
    case 2:
        switch (t)
        {
        case 1:
            bub_sort<float>();
            break;
        case 2:
            ins_sort<float>();
            break;
        case 3:
            sel_sort<float>();
            break;
        default:
            cout << "Wrong input of sorting algo";
        }
        break;
    case 3:
        switch (t)
        {
        case 1:
            bub_sort<char>();
            break;
        case 2:
            ins_sort<char>();
            break;
        case 3:
            sel_sort<char>();
            break;
        default:
            cout << "Wrong input of sorting algo";
        }
        break;
    default:
        cout << "Wrong input of type!";
    }
}