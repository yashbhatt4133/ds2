#include <iostream>
using namespace std;
class qarr
{
    public:
    int n,f,r;
    int* arr;
    qarr(int x)
    {
        n=x;
        f=-1;
        r=-1;
        arr[n];
    }
    bool isempty()
    {
        if(f==-1&&r==-1)
        return true;
        else
        return false;
    }
    void enqueue(int x)
    {
        if((r+1)%n==f)
        throw "Queue is Full";
        else{
            f=0;
            r=(r+1)%n;
            arr[r]=x;
        }
    }
    void dequeue()
    {
        if(isempty())
        throw "Queue is Empty";
        else if(f==r)
        {  //only 1 element present
            f=-1;
            r=-1;
        }
        else{
            f=(f+1)%n;
        }
    }
    void display()
    {
        for(int i=f;i<=r;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main()
{
    try{
    qarr q1(4);
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.display();
    q1.dequeue();
    q1.display();
    }
    catch(char const* msg)
    {
        cout<<msg<<endl;
    }
}
