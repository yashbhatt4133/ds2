#include <iostream>
using namespace std;
class DNode
{
public:
    int d;
    DNode *next;
    DNode *prev;
    DNode(int x = 0)
    {
        d = x;
        next = NULL;
        prev = NULL;
    }
};