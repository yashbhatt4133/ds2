#include <iostream>
#include "DList.cpp"
using namespace std;
class DEQueueList
{
public:
    DList q;
    int n;
    DEQueueList()
    {
        n = 0;
    }
    bool empty()
    {
        return (n == 0);
    }
    void insert_front(int x)
    {
        q.insert_at_head(x);
        n++;
    }
    void insert_back(int x)
    {
        q.insert_at_tail(x);
        n++;
    }
    void delete_front()
    {
        if (n == 0)
            throw "Empty Queue";
        q.delete_front();
        n--;
    }
    void delete_back()
    {
        if (n == 0)
            throw "Empty Queue";
        q.delete_back();
        n--;
    }
    int front()
    {
        if (n == 0)
            throw "Empty Queue";
        return q.get_tail();
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

        DEQueueList q;
        q.insert_front(1);
        q.insert_front(2);
        q.insert_front(3);
        q.insert_front(4);
        q.insert_front(5);
        q.insert_front(6);

        // q.delete_back();
        q.delete_front();

        q.insert_back(10);
        q.display();
    }
    catch (char const *msg)
    {
        cout << msg << endl;
    }
    return 0;
}