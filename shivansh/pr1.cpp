#include <iostream>
using namespace std;
int search(int* arr,int x)
{
    int pos=0;
    for(int i=0;i<5;i++)
    {
        if(arr[i]==x){
        pos=i+1;
        break;}
    }
    if(pos==0)
    return -1;
    else
    return pos;
}
int main()
{
    int i,x,r;
    cout<<"Enter a list of 5 numbers - "<<endl;
    int a[5];
    for(i=0;i<5;i++)
    {
        cin>>a[i];
    }
    cout<<"Enter the element to be searched - "<<endl;
    cin>>x;
    r=search(a,x);
    if(r==-1)
    cout<<x<<" not found"<<endl;
    else
    cout<<x<<" found at position "<<r<<endl;
}
