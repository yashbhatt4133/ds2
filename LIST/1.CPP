#include<bits/stdc++.h>
using namespace std;
template <typename T>
int linear_search(T arr[] ,int size , T x){
    int result = -1;
    for(int i =0;i<size;i++){
        if (arr[i]== x){
            result = i;
            break;
        }
    }
    return result;
}

int main()
{
    int n,x;
    cout<<"Enter Size Of Array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter "<<n<<" Array Elements : ";
    for (int i = 0; i < n; i++){
        cin>>arr[i];        
    }
    cout<<"Enter the element to look for : ";
    cin>>x;
    int index = linear_search(arr,n,x);
    if (index == -1){
        cout<<"Not Found\n";
    }
    else{
        cout<<"Found At "<<index<<endl;
    }
    return 0;
}