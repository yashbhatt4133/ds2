#include <iostream>
using namespace std;
class SNode
{
public:
    int d;
    SNode *next;
    SNode(int x = 0)
    {
        d = x;
        next = NULL;
    }
};