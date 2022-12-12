#include <bits/stdc++.h>
using namespace std;
int bin_search(int *arr,int target, int f, int l)
{   
    if(l==-1)
        return -1;
    while(f<=l){
        int mid=(f+l)/2;
        if(arr[mid]==target)
            return mid;
        else if(arr[mid]>target)
            l=mid-1;
        else
            f=mid+1;
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
    int ind=bin_search(arr,target,0,s-1);
    if(ind==-1)
        cout<<"Element was not found"<<endl;
    else
        cout<<"Index of element : "<<ind<<endl;
}