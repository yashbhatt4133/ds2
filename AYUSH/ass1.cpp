#include <bits/stdc++.h>
using namespace std;
int lin_search(int *arr, int target, int s)
{   
    if(s==0)
        return -1;
    for(int i=0;i<s;i++){
        if(arr[i]==target)
            return i;
    }
    return -1;
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
    cout<<"Enter value to be searched: ";
    int target;
    cin>>target;
    int ind=lin_search(arr,target,s);
    if(ind==-1)
        cout<<"Element was not found"<<endl;
    else
        cout<<"Index of element : "<<ind<<endl;
}