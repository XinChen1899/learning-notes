#include<cstring>
#include<iostream>
#include<stdio.h>
using namespace std;

typedef char elementdata;

typedef struct element
{
	elementdata data;
	element* link;
}student;

template<class element>
class linked_list
{
	private:
		element* head;
		element* tail;
		int length;
		element* list;
		element* prec;
	public:
		linked_list();
		bool get_element(int, element&);
		bool del_element(int, element&);
		void insert_element(elementdata&);
		bool modify_element(int, elementdata&);
		~linked_list();
};

template<class element>
linked_list<element>::linked_list()
{
	length = 0;
	head = new element;
	tail = head;
}

template<class element>
void linked_list<element>::insert_element(elementdata& temp)
{
	if (length == 0)
		head->data = temp;
	list = new element;
	list->data = temp;
    tail->next = list;
    tail = list;
    tail->next = NULL;
    length++;
    return;
}

template<class element>
bool linked_list<element>::get_element(int k, element& temp)
{
	if (k >= length)
	    return false;
	list = head, prec = head;
	for (int i = 0; i < k; i++)
	{
		prec = list;
		list = list->next;
	}
	temp = list;
	return true;
}

template<class element>
bool linked_list<element>::del_element(int k, element& temp)
{
	if (!get_element(k, temp))
	    return false;
	prec->next = list->next;
	if (tail == list)
	    tail = prec;
	delete list;
	length--;
	return true;
}

template<class element>
bool linked_list<element>::modify_element(int k, elementdata& temp)
{
	element* p;
	if (!get_element(k, p))
	    return false;
	list->data = temp;
	return true;
}

template<class element>
linked_list<element>::~linked_list()
{
	list = head;
	while (list != NULL)
	{
		head = list->next;
		delete list;
		list = head;
	}
	delete head; 
}
