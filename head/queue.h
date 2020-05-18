#include<iostream> 
#include<cstring>
using namespace std;

typedef char element;

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

queue::queue(int msize)
{
	max_size = msize;
	list = new element[max_size];
	fron = rear = 0;
}

bool queue::get_fron(element &temp)
{
	if (isempty())
	    return false;
	temp = list[fron];
	return true;
}

bool queue::get_rear(element &temp)
{
	if (isempty())
	    return false;
	temp = list[rear];
	return true;
}

bool queue::enqueue(element& temp)
{
	if (isfull())
	    return false;
	if (isempty())
		list[fron] = temp;
	else
		list[++rear] = temp;
	return true;
}

bool queue::dequeue(element& temp)
{
	if (isempty())
	    return false;
	temp = list[fron++];
	return true;
}
