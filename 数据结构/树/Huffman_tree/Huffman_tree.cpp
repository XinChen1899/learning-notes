#include<iostream>
using namespace std;

struct elementdata
{
	int weight = 0;
	char name = '\0';
};

struct btelement
{
	elementdata data;
	btelement* left = NULL;
	btelement* right = NULL;
};

typedef struct huffman
{
	int weight = 0;
	btelement* root = NULL;
}htelement;

#include"binary_tree.h"

template<class htelement>
class minheap_tree
{
private:
	htelement* heap;
	int heapsize = 0;
	int maxsize = 20;
public:
	minheap_tree(htelement*);
	minheap_tree() { heap = new htelement[maxsize]; heapsize = 0; };
	bool isempty() { return heap == NULL; };
	bool isfull() { return heapsize >= maxsize; };
	void create_minht();
	bool insert_htnode(htelement&);
	bool delete_htnode(int, htelement&);
	void sort_htnode();
	void order();
	btelement* huffman_tree(elementdata*);
	~minheap_tree() { delete[]heap; heap = NULL; };
};

template<class htelement>
minheap_tree<htelement>::minheap_tree(htelement* temp)
{
	heap = new htelement[maxsize];
	htelement* p = temp;
	for (int i = 0; p[i].weight != 0; i++)
	{
		heap[i].weight = temp.weight;
		heap[i].root = temp.root;
		heapsize = i + 1;
	}
	create_minht();
}

template<class htelement>
void minheap_tree<htelement>::create_minht()
{
	int son = 0;
	for (int i = (heapsize - 2) / 2; i >= 0; i--)
	{
		heap[heapsize].weight = heap[i].weight;
		heap[heapsize].root = heap[i].root;
		son = i * 2 + 1;
		while (son < heapsize)
		{
			if (son < heapsize - 1 && heap[son].weight > heap[son + 1].weight)
				son++;
			if (heap[heapsize].weight <= heap[son].weight)
				break;
			heap[(son - 1) / 2].weight = heap[son].weight;
			heap[(son - 1) / 2].root = heap[son].root;
			son = son * 2 + 1;
		}
		heap[(son - 1) / 2].weight = heap[heapsize].weight;
		heap[(son - 1) / 2].root = heap[heapsize].root;
	}
	return;
}

template<class htelement>
bool minheap_tree<htelement>::insert_htnode(htelement& newvalue)
{
	if (isfull())
		return false;
	int i = 0;
	i = ++heapsize - 1;
	while (i != 0 && newvalue.weight < heap[(i - 1) / 2].weight)
	{
		heap[i] = heap[(i - 1) / 2];
		i = (i - 1) / 2;
	}
	heap[i].weight = newvalue.weight;
	heap[i].root = newvalue.root;
	return true;
}

template<class htelement>
bool minheap_tree<htelement>::delete_htnode(int size, htelement& temp)
{
	if (isempty())
		return false;
	int dad = 0, son = dad * 2 + 1;
	temp.weight = heap[0].weight;
	temp.root = heap[0].root;
	heap[heapsize + 1].weight = heap[size - 1].weight;
	heap[heapsize + 1].root = heap[size - 1].root;
	size--;
	while (son < size)
	{
		if (son < size - 1 && heap[son].weight > heap[son + 1].weight)
			son++;
		if (heap[heapsize + 1].weight <= heap[son].weight)
			break;
		heap[dad].weight = heap[son].weight;
		heap[dad].root = heap[son].root;
		dad = son;
		son = dad * 2 + 1;
	}
	heap[dad].weight = heap[heapsize + 1].weight;
	heap[dad].root= heap[heapsize + 1].root;
	heapsize--;
	return true;
}

template<class htelement>
void minheap_tree<htelement>::sort_htnode()
{
	htelement temp;
	for (int i = heapsize - 1; i >= 0; i--)
	{
		delete_htnode(i + 1, temp);
		heap[i] = temp;
		heapsize++;
	}
	return;
}

template<class htelement>
void minheap_tree<htelement>::order()
{
	for (int i = 0; i < heapsize; i++)
		cout << heap[i].weight << '\t';
	cout << endl;
	return;
}

template<class htelement>
btelement* minheap_tree<htelement>::huffman_tree(elementdata* applist)
{
	btelement* ptr = new btelement;
	huffman newvalue;
	binary_tree<btelement> appbt;
	for (int i = 0; applist[i].weight != 0; i++)
	{
		ptr = appbt.create_node(applist[i]);
		newvalue.weight = applist[i].weight;
		newvalue.root = ptr;
		insert_htnode(newvalue);
	}
	cout << endl;
	create_minht();
	huffman ro, le, ri;
	int n = heapsize;
	for (int i = 1; i < n; i++)
	{
		delete_htnode(heapsize, le);
		delete_htnode(heapsize, ri);
		ro.weight = le.weight + ri.weight;
		ptr = new btelement;
		ptr->data.weight = ro.weight;
		ptr->data.name = '0';
		appbt.create_bt(ptr, le.root, ri.root);
		ro.root = ptr;
		insert_htnode(ro);
	}
	appbt.btroot = ptr;
	appbt.preorder_re(ptr);
	return ptr;
}

int main()
{
	elementdata temp[20] = { {6,'a'},{2,'b'},{3,'d'},{3,'f'},{4,'g'},{9,'h'} };
	minheap_tree<huffman> appheap;
	btelement* ptr = appheap.huffman_tree(temp);
	return 0;
}
