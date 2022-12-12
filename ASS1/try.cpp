#include <iostream>
using namespace std;
typedef int TYPE;
class Node
{
public:
	TYPE elem;
	Node *next;
	friend class SLL;
};
class SLL
{
	// protected:

public:
	Node *head, *tail;
	SLL()
	{
		head = NULL;
		tail = 0;
	}
	bool empty()
	{
		return (!head);
	}
	void addFront(TYPE x)
	{
		Node *p = new Node;
		p->elem = x;
		p->next = head;
		head = p;
		if (!tail)
			tail = p;
	}
	void addtail(TYPE x)
	{
		Node *p = new Node;
		p->elem = x;
		p->next = NULL;
		tail->next = p;
		tail = p;
		if (empty())
			head = p;
	}
	void add(TYPE x, int pos)
	{
		Node *p = new Node;
		p->elem = x;
		Node *temp = head;
		if (pos == 1)
		{
			p->next = head;
			head = p;
			if (!tail)
				tail = p;
			return;
		}
		int count = 1;
		while (temp != NULL && count < pos - 1)
		{
			temp = temp->next;
			count++;
		}
		if (temp == NULL)
			throw "INVALID POSITION";
		p->next = temp->next;
		temp->next = p;
		if (temp->next == NULL)
			tail = temp;
	}
	void removeFront()
	{
		if (head == 0)
			throw "Already Empty";
		if (head == tail)
		{

			delete[] head;
			head = 0;
			tail = 0;
		}
		else
		{
			Node *oldhead = head;
			head = head->next;
			delete oldhead;
		}
	}
	void pop(int pos)
	{
		Node *ptr = head;
		if (head == 0)
			throw "EMPTY LIST";
		if (pos == 1)
		{
			Node *oldhead = head;
			head = oldhead->next;
			delete oldhead;
			return;
		}
		int count = 1;
		while (ptr != NULL && count < pos - 1)
		{
			ptr = ptr->next;
			count++;
		}
		if (ptr == NULL)
			throw "INVALID POSITION";
		Node *old = ptr->next;
		ptr->next = old->next;
		delete old;
	}
	Node *search(TYPE x)
	{
		Node *p = head;
		while (p)
		{
			if (p->elem == x)
			{
				return p;
			}
			p = p->next;
		}
		return NULL;
	}
	void show()
	{
		if (empty())
		{
			cout << "BLANK\n";
			return;
		}
		Node *temp = head;
		while (temp != NULL)
		{
			cout << temp->elem << "->";
			temp = temp->next;
		}
		cout << "NULL \n";
	}
	void concat(SLL &l2)
	{
		while (!l2.empty())
		{
			int x = l2.head->elem;
			l2.removeFront();
			this->addtail(x);
		}
	}
	void swapp(Node *x, Node *y)
	{
		cout<<"here";
		Node *x_trailer = head;
		Node *y_trailer = head;
		Node *temp;
		cout<<"here";
		while (x_trailer->next != x && x_trailer != NULL)
		{
			x_trailer = x_trailer->next;
		}
		while (y_trailer->next != y && y_trailer != NULL)
		{
			y_trailer = y_trailer->next;
		}
		cout << x_trailer->elem << "    " << y_trailer->elem << "\n";
		x_trailer->next = y;
		y_trailer->next = x;
		temp = y->next;
		y->next = x->next;
		x->next = temp;
	}
};
int main()
{
	SLL list;
	list.addFront(9);
	list.addtail(2);
	list.addtail(3);
	list.addtail(4);
	list.addtail(5);
	list.addtail(6);
	list.show();
	list.swapp(list.head->next, list.head->next->next->next->next);
	list.show();
	return 0;
}
