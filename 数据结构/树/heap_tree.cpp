#include<iostream>
#include<cstring>
using namespace std;

typedef int htelement;

/*
判断空
判断满
构造最大堆
插入结点
删除堆顶
排序
遍历输出 
*/

template<class htelement>
class heap_tree
{
private:
	htelement* heap;
	int heapsize = 0;
	int maxsize = 20;
public:
	heap_tree(htelement*);
	bool isempty() { return heap == NULL; };
	bool isfull() { return heapsize >= maxsize; };
	void create_ht();
	bool insert_htnode(htelement&);
	bool delete_htnode(int, htelement&);
	void sort_htnode();
	void order();
	~heap_tree() { delete[]heap; };
};

template<class htelement>
heap_tree<htelement>::heap_tree(htelement* temp)
{
	heap = new htelement[maxsize];
	htelement* p = temp;
	for (int i = 0; p[i] != 0; i++)
	{
		heap[i] = p[i];
		heapsize = i + 1;
	}
	create_ht();
}

template<class htelement>
void heap_tree<htelement>::create_ht()
{
	int son = 0;
	for (int i = (heapsize - 2) / 2; i >= 0; i--)
	{
		heap[heapsize] = heap[i];
		son = i * 2 + 1;
		while (son < heapsize)
		{
			if (son < heapsize - 1 && heap[son] < heap[son + 1])
				son++;
			if (heap[heapsize] >= heap[son])
				break;
			heap[(son - 1) / 2] = heap[son];
			son = son * 2 + 1;
		}
		heap[(son - 1) / 2] = heap[heapsize];
	}
	return;
}

template<class htelement>
bool heap_tree<htelement>::insert_htnode(htelement& newvalue)
{
	if (isfull())
		return false;
	int i = ++heapsize - 1;
	while (i != 0 && newvalue > heap[(i - 1) / 2])
	{
		heap[i] = heap[(i - 1) / 2];
		i = (i - 1) / 2;
	}
	heap[i] = newvalue;
	return true;
}

template<class htelement>
bool heap_tree<htelement>::delete_htnode(int size, htelement& temp)
{
	if (isempty())
		return false;
	int dad = 0, son = dad * 2 + 1;
	temp = heap[0];
	heap[heapsize + 1] = heap[size - 1];
	size--;
	while (son < size)
	{
		if (son < size - 1 && heap[son] < heap[son + 1])
			son++;
		if (heap[heapsize + 1] >= heap[son])
			break;
		heap[dad] = heap[son];
		dad = son;
		son = dad * 2 + 1;
	}
	heap[dad] = heap[heapsize + 1];
	return true;
}

template<class htelement>
void heap_tree<htelement>::sort_htnode()
{
	htelement temp;
	for (int i = heapsize - 1; i >= 0; i--)
	{
		delete_htnode(i + 1, temp);
		heap[i] = temp;
	}
	return;
}

template<class htelement>
void heap_tree<htelement>::order()
{
	for (int i = 0; i < heapsize; i++)
		cout << heap[i] << '\t';
	cout << endl;
	return;
}

int main()
{
	int ht_node[20] = { 52,6,5,79,55,24,15,36,16,62,6,38 };
	heap_tree<htelement> ht(ht_node);
	ht.sort_htnode();
	ht.order();
	return 0;
}
