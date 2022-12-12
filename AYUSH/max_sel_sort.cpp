#include <bits/stdc++.h>
using namespace std;
void sel_sort(int *arr, int s)
{   
    for(int i=s-1;i>0;i--){
        int max=i;
        for (int j = i-1; j >= 0; j--)
        {
            if(arr[j]>arr[max])
                max=j;
        }
        swap(arr[i],arr[max]);
    }
    cout<<"Sorted array: "<<endl;
    for (int i = 0; i < s; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    cout << "Enter number of values: ";
    int s;
    cin >> s;
    int arr[s];
    cout<<"Enter the values : "<<endl;
    for (int i = 0; i < s; i++)
        cin>>arr[i];
    sel_sort(arr,s);
}