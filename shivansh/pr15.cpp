#include <bits/stdc++.h>
#include <vector>
using namespace std;
class heap
{
    public:
    vector<int> arr;
    heap()
    {
        // cout<<"called";
        arr.push_back(-1);
    }
    void insert(int x)
    {
        int i,pi,tmp;
        arr.push_back(x);
        i=arr.size()-1;
        while(i>1)
        {
            pi=i/2;
            if(arr[pi]<arr[i])
            {
                swap(arr[i],arr[pi]);
            }
            else
            return;
        }
    }
    void deleteroot()
    {
        int s;
        s=arr.size();
        // cout<<arr[s-1];
        arr[1]=arr[s-1];
        arr.pop_back();
        int i=1;
        while(i<s-1)
        {
            int lc=i*2;
            int rc=i*2+1;
            if(lc<s-1&&arr[lc]>arr[rc])
            {
                swap(arr[lc],arr[i]);
                i=lc;
            }
            else if(rc<s-1&&arr[rc]>arr[lc])
            {
                swap(arr[rc],arr[i]);
                i=rc;
            }
            else
                return;
        }
    }
    void display()
    {
        int i,size;
        bool f=true;
        size=arr.size();
        for(auto i:arr){
            if(f){
                f=!f;
                continue;
            }
            cout<<i<<" ";
        }
        cout<<endl;
    }
};
int main()
{
    heap h;
    h.insert(10);
    h.insert(2);
    h.insert(1);
    h.insert(5);
    h.display();
    h.deleteroot();
    h.display();
}