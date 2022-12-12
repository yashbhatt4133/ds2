#include <iostream>
using namespace std;
class stackarray
{
    public:
    int top;
    int* arr;
    int n;
    stackarray(int x)
    {
        n=x;
        top=-1;
        arr=new int[n];
    }
    void push(int x)
    {
        if(top<n-1)
        arr[++top]=x;
        else
        throw "Overflow";
    }
    int pop()
    {
        if(top!=-1)
        {
            return arr[top--];
        }
        else
        throw "Underflow";
    }
    void display()
    {
        for(int i=0;i<top+1;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    int peek()
    {
        if(top==-1)
        throw "Stack is empty.Nothing to peek.";
        else
        return arr[top];
    }
};
int main()
{
    try{
    stackarray st(2);
    st.push(1);
    st.push(2);
    st.display();
    cout<<st.pop()<<endl;
    cout<<st.pop()<<endl;
    cout<<st.peek()<<endl;
    }
    catch(char const* msg)
    {
        cout<<msg<<endl;
    }
}