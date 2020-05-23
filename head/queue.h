#include<iostream> 
#include<cstring>
using namespace std;

typedef char element;

template<class element>
class queue
{
	private:
		int max_size;
		int fron;
		int rear;
		element* list;
	public:
		queue(int);
		bool get_fron(element&);
		bool get_rear(element&);
		bool isempty() { return fron == rear;};
		bool isfull() { return (fron == (rear + 1) % max_size);};
		bool enqueue(element&);
		bool dequeue(element&);
		~queue() { delete[]list;};
};

template<class element>
queue::queue<element>(int msize)
{
	max_size = msize;
	list = new element[max_size];
	fron = rear = 0;
}

template<class element>
bool queue<element>::get_fron(element &temp)
{
	if (isempty())
	    return false;
	temp = list[fron];
	return true;
}

template<class element>
bool queue<element>::get_rear(element &temp)
{
	if (isempty())
	    return false;
	temp = list[rear];
	return true;
}

template<class element>
bool queue<element>::enqueue(element& temp)
{
	if (isfull())
	    return false;
	if (isempty())
		list[fron] = temp;
	else
	{
		rear = (rear + 1) % max_size;
		list[rear] = temp;
	}
	return true;
}

template<class element>
bool queue<element>::dequeue(element& temp)
{
	if (isempty())
	    return false;
	temp = list[fron];
	fron = (fron + 1) % max_size;
	return true;
}
