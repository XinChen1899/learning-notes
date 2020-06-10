#include<iostream>
using namespace std;

typedef int element, htelement;

//**********************插入排序*************************

//插入排序
template<class element>
void insert_sort(element* list, int len)
{
	int i, j;
	element temp;
	for (i = 1; i < len; i++)
	{
		temp = list[i];
		for (j = 1 - 1; j >= 0 && temp < list[j]; j--)
			list[j + 1] = list[j];
		list[j + 1] = temp;
	}
	return;
}

//折半插入排序
template<class element>
void binary_insert_sort(element* list, int len)
{
	int low = 0, high = 0, mid = 0, i = 0, j = 0;
	element temp;
	for (i = 0; i < len; i++)
	{
		temp = list[i];
		low = 0, high = i - 1;
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (temp < list[i])
				high = mid - 1;
			else
				low = mid + 1;
		}
		for (j = i - 1; j >= high + 1; j--)
			list[j + 1] = list[j];
		list[j + 1] = temp;
	}
	return;
}

//希尔排序
template<class element>
void Shell_sort(element* list, int len, int d[])
{
	int i, j, k, m, span;//i, j用于小组内插入排序，k, m分别用于分组和取跨度，span为跨度
	element temp;
	for (m = 0; d[m] != 0; m++)//取跨度
	{
		span = d[m];
		for (k = 0; k < span; k++)//按照跨度分小组
		{
			for (i = k + span; i < len; i += span)
			{//小组内插入排序
				temp = list[i];
				for (j = i - span; j >= 0 && temp < list[j]; j -= span)
					list[j + span] = list[j];
				list[j + span] = temp;
			}
		}
	}
}

//冒泡排序
template<class element>
void bubble_sort(element* list, int len)
{
	int i = 0, j = len - 1;
	bool check = true;
	element temp;
	while (j > 0 && check)
	{
		check = false;
		for (i = 0; i < j; i++)
		{
			if (list[i] > list[i + 1])
			{
				temp = list[i];
				list[i] = list[i + 1];
				list[i + 1] = temp;
				check = true;
			}
		}
		j--;
	}
}

//快速排序
template<class element>
void quick_sort(element* list, int low, int high)
{
	if (low >= high)
		return;
	int key = 0, lo = low, hi = high;
	element temp;
	temp = list[lo];
	key = list[lo];
	while (lo < hi)
	{
		while (lo < hi && list[hi] > key)
			hi--;
		if (lo < hi)
		{
			list[lo] = list[hi];
			lo++;
		}
		while (lo < hi && list[lo] < key)
			lo++;
		if (lo < hi)
		{
			list[hi] = list[lo];
			hi--;
		}
	}
	list[lo] = temp;
	quick_sort(list, low, lo - 1);
	quick_sort(list, lo + 1, high);
	return;
}

//选择排序
template<class element>
void selectsort(element* list, int len)
{
	int min = 0;
	element temp;
	for (int i = 0; i < len - 1; i++)
	{
		min = i;
		for (int j = i - 1; j < len; j++)
		{
			if (list[j] < list[min])
				min = j;
		}
		if (min != i)
		{
			temp = list[i];
			list[i] = list[min];
			list[min] = temp;
		}
	}
	return;
}

//归并排序
template<class element>
void merge(element* list, element* swap, int size, int len)
{
	int i = 0, j = 0;
	int low1, high1, low2, high2, sp;
	low1 = 0;
	sp = 0;
	while (low1 + size <= len - 1 && size <= len)
	{
		low2 = low1 + size;
		high1 = low2 - 1;
		if (low2 + size - 1 >= len - 1)
			high2 = len - 1;
		else
			high2 = low2 + size - 1;
		for (i = low1, j = low2; i <= high1 && j <= high2; sp++)
		{
			if (list[i] <= list[j])
			{
				swap[sp] = list[i];
				i++;
			}
			else
			{
				swap[sp] = list[j];
				j++;
			}
		}
		for (; i <= high1; sp++, i++)
		{
			swap[sp] = list[i];
		}
		for (; j <= high2; sp++, j++)
		{
			swap[sp] = list[j];
		}
		low1 = low2 + size;
	}
	for (i = low1; i < len; sp++, i++)
	{
		swap[sp] = list[i];
	}
	return;
}

template<class element>
bool Msort(element* source, element* result, int len)
{
	bool flag = true;
	int size = 1;
	while (size < len)
	{
		merge(source, result, size, len);
		flag = true;
		size *= 2;
		if (size > len)
			break;
		merge(result, source, size, len);
		flag = false;
		size *= 2;
		if (size > len)
			break;
	}
	return flag;
}

template<class element>
void merge_sort(element* list, int len)
{
	element *temp;
	temp = new element[len];
	if (Msort(list, temp, len))
		list = temp;
	delete[]temp;
	temp = NULL;
	return;
}

//堆排
#include"heap_tree.h"


int main()
{
	int list[31] = { 1, 3, 13, 18, 44, 8, 10, 21, 23, 22, 9, 36, 11, 7, 20, 2, 25, 32, 6, 76, 70, 4, 5, 68, 99, 30, 59, 81, 12, 14, 0};
	cout << "排前:\t";
	for (int i = 0; i < 30; i++)
	{
		cout << list[i] << '\t';
	}
	cout << endl;
	merge_sort(list,30);
	cout << "排后:\t";
	for (int i = 0; i < 30; i++)
	{
		cout << list[i] << '\t';
	}
	cout << endl;
	Heap_tree<htelement> run(list);
	run.sort_htnode();
	run.order();
	return 0;
}


