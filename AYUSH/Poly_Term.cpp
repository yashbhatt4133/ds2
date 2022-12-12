#include <iostream>
using namespace std;
class Term
{
public:
    int coeff;
    int power;
    Term *next;
    Term *prev;
    Term(int c = 0, int p = 0)
    {
        coeff = c;
        power = p;
        next = NULL;
        prev = NULL;
    }
};