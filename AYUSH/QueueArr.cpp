#include <iostream>
using namespace std;
class QueueArr
{
public:
	int *arr;
	int size, n;
	int f = -1, l = 0;
	QueueArr(int s = 10)
	{
		size = s;
		arr = new int[size];
		n = 0;
	}
	bool empty()
	{
		return n == 0;
	}
	void enqueue(int x)
	{
		if (size == n)
			throw "QueueArr full";
		f = (f + 1) % size;
		arr[f] = x;
		n++;
	}
	void dequeue()
	{
		if (empty())
			throw "Empty QueueArr";
		l = (l + 1) % size;
		n--;
	}
	int front()
	{
		if (empty())
			throw "Empty QueueArr";
		return arr[l];
	}
	void display()
	{
		int c = 0, p = l;
		while (c != n)
		{
			p = p % size;
			cout << arr[p] << " ";
			p++;
			c++;
		}
		cout << endl;
	}
};
int main()
{
	try
	{

		QueueArr q(5);
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
}