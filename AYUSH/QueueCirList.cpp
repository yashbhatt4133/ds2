#include <iostream>
#include "CircularList.cpp"
using namespace std;
class QueueList
{
public:
    CList q;
    int n;
    QueueList()
    {
        n = 0;
    }
    bool empty()
    {
        return (n == 0);
    }
    void enqueue(int x)
    {
        q.add_tail(x);
        n++;
    }
    void dequeue()
    {
        if (n == 0)
            throw "Empty Queue";
        q.del_head();
        n--;
    }
    int front()
    {
        if (n == 0)
            throw "Empty Queue";
        return q.get_head();
    }
    void display()
    {
        q.display();
    }
};
int main()
{
    try
    {

        QueueList q;
        q.enqueue(2);
        q.enqueue(4);
        q.enqueue(1);
        q.enqueue(3);
        q.enqueue(20);

        q.dequeue();
        q.dequeue();

        q.enqueue(1);
        q.enqueue(3);

        q.dequeue();
        q.dequeue();

        q.enqueue(1);
        q.enqueue(3);
        q.display();
        // cout << q.front();
    }
    catch (char const *msg)
    {
        cout << msg << endl;
    }
    return 0;
}