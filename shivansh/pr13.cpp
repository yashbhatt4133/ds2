#include <iostream>
using namespace std;
// class ltmatrix
// {
//     public:
//     int n;
//     int* arr;
//     ltmatrix(int x)
//     {
//         n=x;
//         int size=n*(n+1)/2;
//         arr=new int[size];
//     }
//     void input()
//     {
//         int i,s,index;
//         s=n*(n+1)/2;
//         cout<<"Enter the elements of lower triangle row wise - "<<endl;   
//         for(i=0;i<s;i++)
//         {
//             cin>>arr[i];
//         }
//         for(int i=1;i<=n;i++)
//         {
//             for(int j=1;j<=n;j++)
//             {
//                 if(j>i)
//                     cout<<0<<" ";
//                 else{
//                 index=i*(i-1)/2+j-1;
//                 cout<<arr[index]<<" ";
//                 }
//             }
//             cout<<endl;
//         }
//     }
// };
// class utmatrix
// {
//     public:
//     int n;
//     int* arr;
//     utmatrix(int x)
//     {
//         n=x;
//         int size=n*(n+1)/2;
//         arr=new int[size];
//     }
//     void input()
//     {
//         int i,s,index;
//         s=n*(n+1)/2;
//         cout<<"Enter the elements of upper triangle column wise - "<<endl;   
//         for(i=0;i<s;i++)
//         {
//             cin>>arr[i];
//         }
//         for(int i=1;i<=n;i++)
//         {
//             for(int j=1;j<=n;j++)
//             {
//                 if(j<i)
//                     cout<<0<<" ";
//                 else{
//                 index=j*(j-1)/2+i-1;
//                 cout<<arr[index]<<" ";
//                 }
//             }
//             cout<<endl;
//         }
//     }
// };
// class symatrix
// {
//     public:
//     int n;
//     int* arr;
//     symatrix(int x)
//     {
//         n=x;
//         int size=n*(n+1)/2;
//         arr=new int[size];
//     }
//     void input()
//     {
//         int i,s,index;
//         s=n*(n+1)/2;
//         cout<<"Enter the elements of lower triangle row wise - "<<endl;   
//         for(i=0;i<s;i++)
//         {
//             cin>>arr[i];
//         }
//         for(int i=1;i<=n;i++)
//         {
//             for(int j=1;j<=n;j++)
//             {
//                 if(j>i){
//                     index=j*(j-1)/2+i-1; 
//                     cout<<arr[index]<<" ";
//                 }
//                 else{
//                 index=i*(i-1)/2+j-1;
//                 cout<<arr[index]<<" ";
//                 }
//             }
//             cout<<endl;
//         }
//     }
// };
class dmatrix
{
    public:
    int n;
    int* arr;
    dmatrix(int x)
    {
        n=x;
        arr=new int[x];
    }
    void input()
    {
    int i,index;
    cout<<"Enter the elements of the diagonal - "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i!=j)
            cout<<0<<" ";
            else{
            index=j;
            cout<<arr[index-1]<<" ";
            }
        }
        cout<<endl;
    }
    }
};
int main()
{
    // ltmatrix obj1(4);
    // obj1.input();
    // utmatrix obj2(4);
    // obj2.input();
    // symatrix obj3(4);
    // obj3.input();
    dmatrix obj4(4);
    obj4.input();
}