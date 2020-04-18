#pragma warning(disable:4996)
#include<iostream>
#include<cstring>
#include<iomanip>
#include<stdlib.h>
using namespace std;
//链表节点类
class element
{
public:
	int id;
	char name[20];
	int score;
	element* prec;   //直接前驱
	element* next;   //直接后继
};
//头指针类
class head
{
public:
	element* first;
	int length;
};
//节点数据域交换函数
void swap(element* temp1, element* temp2)
{
	int t_id = 0, t_score = 0;
	char t_name[10] = "000";
	//学号对换 
	t_id = temp1->id;
	temp1->id = temp2->id;
	temp2->id = t_id;
	//名字对换
	strcpy(t_name, temp1->name);
	strcpy(temp1->name, temp2->name);
	strcpy(temp2->name, t_name);
	//成绩对换
	t_score = temp1->score;
	temp1->score = temp2->score;
	temp2->score = t_score;
}
//双向链表操作类
template<class element, class head>
class double_link_list
{
private:
	head head_ptr;       //头指针
	element* tail;       //尾指针
public:
	//构造函数
	double_link_list()
	{
		head_ptr.first = NULL;
		head_ptr.length = 0;
		tail = NULL;
	};
	bool set(element);
	element* find(int);
	element* find(char*);
	void modify(element*, int);
	void modify(element*, char*);
	void modify(int, element*);
	void del(element*);
	void insert(element*);
	void sort(element*, element*);
	void all_del();
	void view();
	//析构函数
	~double_link_list()
	{
		all_del();
	};
};
//建立链表
template<class element, class head>
bool double_link_list<element, head>::set(element data)
{
	//当id为0时结束建立
	if (data.id == 0)
	{
		if (head_ptr.first == NULL)
			return false;
		return true;
	}
	element* temp;
	temp = new element;
	temp->id = data.id;
	strcpy(temp->name, data.name);
	temp->score = data.score;
	if (head_ptr.first == NULL)
	{
		head_ptr.first = temp;
		temp->prec = NULL;
		temp->next = NULL;
		tail = temp;
	}
	else
	{
		temp->prec = tail;
		temp->next = NULL;
		tail->next = temp;
		tail = temp;
	}
	head_ptr.length++;
	sort(head_ptr.first, tail);
	return true;
}
//根据id查找
template<class element, class head>
element* double_link_list<element, head>::find(int id)
{
	element* explore = head_ptr.first;
	while (explore != NULL)
	{
		if (explore->id == id)
			break;
		explore = explore->next;
	}
	return explore;
}
//根据name查找
template<class element, class head>
element* double_link_list<element, head>::find(char* name)
{
	element* explore = head_ptr.first;
	while (explore != NULL)
	{
		if (!strcmp(explore->name, name))
			break;
		explore = explore->next;
	}
	return explore;
}
//修改指定学生的id
template<class element, class head>
void double_link_list<element, head>::modify(element* temp, int new_id)
{
	element* explore = temp;
	explore->id = new_id;
	return;
}
//修改指定学生的name
template<class element, class head>
void double_link_list<element, head>::modify(element* temp, char* new_name)
{
	element* explore = temp;
	strcpy(explore->name, new_name);
	return;
}
//修改指定学生的score
template<class element, class head>
void double_link_list<element, head>::modify(int new_score, element* temp)
{
	element* explore = temp;
	explore->score = new_score;
	sort(head_ptr.first, tail);
	return;
}
//删除指定学生
template<class element, class head>
void double_link_list<element, head>::del(element* temp)
{
	element* explore = temp;
	if (explore == tail)
	{
		tail = explore->prec;
	}
	else if (explore == head_ptr.first)
	{
		head_ptr.first = explore->next;
	}
	else
	{
		explore->prec->next = explore->next;
		explore->next->prec = explore->prec;
	}
	delete explore;
	head_ptr.length--;
	return;
}
//添加学生
template<class element, class head>
void double_link_list<element, head>::insert(element* new_element)
{
	element* explore = head_ptr.first, * p = explore->prec;
	while (explore != NULL)
	{
		if (new_element->score < explore->score)
		{
			break;
		}
		explore = explore->next, p = explore->prec;
	}
	if (explore == head_ptr.first)
	{
		new_element->next = explore;
		explore->prec = new_element;
		head_ptr.first = new_element;
	}
	else if (explore == NULL)
	{
		new_element->prec = p;
		p->next = new_element;
		tail = new_element;
		tail->next = NULL;
	}
	else
	{
		new_element->next = explore;
		new_element->prec = p;
		p->next = new_element;
		explore->prec = new_element;
	}
	head_ptr.length++;
	return;
}
//根据成绩降序排序
template<class element, class head>
void double_link_list<element, head>::sort(element* Head, element* tail)
{
	if (Head == tail || Head == NULL || Head == tail->next)
	{
		return; // 递归出口
	}
	element* temp1, * temp2, * key;
	temp1 = temp2 = key = Head;
	while (temp2 != tail)
	{
		temp2 = temp2->next; // 对于一个链表只遍历一遍
		if (temp2->score > Head->score)
		{
			// 如果temp2的值大于key则放在左边
			key = temp1;
			temp1 = temp1->next;
			swap(temp1, temp2);
		}
	}
	swap(Head, temp1);
	sort(Head, key);
	sort(temp1->next, tail);
	return;
}
//全部删
template<class element, class head>
void double_link_list<element, head>::all_del()
{
	if (tail == NULL)
	{
		head_ptr.length = 0;
		return;
	}
	element* temp = tail;
	tail = temp->prec;
	delete temp;
	all_del();
}
//总览
template<class element, class head>
void double_link_list<element, head>::view()
{
	sort(head_ptr.first, tail);
	cout << "结果：\n";
	int n;                   //用于记录名次
	element* temp = head_ptr.first;
	cout.setf(ios::left);
	cout << setw(12) << "名次" << setw(12) << "学号" << setw(12) << "姓名" << setw(12) << "分数" << '\n' << endl;
	for (n = 1; temp != NULL; n++, temp = temp->next)
	{
		cout << setw(12) << n << setw(12) << temp->id << setw(12) << temp->name << setw(12) << temp->score << '\n' << endl;
	}
	cout << "                                                              人数：" << head_ptr.length << endl;
	return;
}


#define choose_find 1
#define choose_modify 2
#define choose_delete 3
#define choose_insert 4
#define choose_view 5
#define choose_all_del 6
#define choose_exit 0
#define choose_id 1
#define choose_name 2
#define choose_score 3
#define Error default
int main()
{
	cout << "------------------Hello World------------------\n";
	int choice = 0, n = 1;                                      //choice用来做选择
	element data;                                               //用于建立链表的数据域
	element* new_element, * result;                             //分别用来建立新学生和查找学生
	new_element = result = NULL;
	int find_id = 0, new_id = 0, new_score = 0;                 //分别为查找指定id，修改后id，修改后score
	char find_name[20] = { '\0' }, new_name[20] = { '\0' };     //分别为查找指定name，修改后name
	bool check = 0;                                             //用来判断链表建立进程是否结束
	double_link_list<element, head> run;                        //构造对象
	//开始构造链表
	system("pause");
	cout << "第1个学生(学号为0时结束):\n";
	cin >> data.id >> data.name >> data.score;
	check = run.set(data);
	while (check && data.id != 0)
	{
		n++;
		cout << "第" << n << "个学生(学号为0时结束):\n";
		cin >> data.id >> data.name >> data.score;
		check = run.set(data);
	}
	//操作
	while (true)
	{
		system("pause");
		system("cls");
		cout << "|  1、查找   |\n";
		cout << "|  2、修改   |\n";
		cout << "|  3、删除   |\n";
		cout << "|  4、添加   |\n";
		cout << "|  5、总览   |\n";
		cout << "|  0、退出   |\n";
		cout << "请选择：";
		cin >> choice;
		switch (choice)
		{
		case choose_find:
			cout << "您希望通过什么信息查找？（1--学号   2--姓名）";
			cin >> choice;
			switch (choice)
			{
			case choose_id:
				cout << "学号：";
				cin >> find_id;
				result = run.find(find_id);
				if (!result)
				{
					cout << "不存在！！\n";
					break;
				}
				cout << result->id << '\t' << result->name << '\t' << result->score << endl;
				break;
			case choose_name:
				cout << "姓名：";
				cin >> find_name;
				result = run.find(find_name);
				if (!result)
				{
					cout << "不存在！！\n";
					break;
				}
				cout << result->id << '\t' << result->name << '\t' << result->score << endl;
				break;
			Error:
				cout << "Error!!\n";
				break;
			}
			break;
		case choose_modify:
			cout << "您希望通过什么信息查找？（1--学号   2--姓名）";
			cin >> choice;
			switch (choice)
			{
			case choose_id:
				cout << "学号：";
				cin >> find_id;
				result = run.find(find_id);
				if (!result)
				{
					cout << "不存在！！\n";
					break;
				}
				break;
			case choose_name:
				cout << "姓名：";
				cin >> find_name;
				result = run.find(find_name);
				if (!result)
				{
					cout << "不存在！！\n";
					break;
				}
				break;
			Error:
				cout << "Error!!\n";
				break;
			}
			cout << "您想修改哪一项信息？（1--学号  2--姓名  3--成绩）";
			cin >> choice;
			switch (choice)
			{
			case choose_id:
				cout << "新学号：";
				cin >> new_id;
				run.modify(result, new_id);
				cout << "成功！\n";
				break;
			case choose_name:
				cout << "新姓名：";
				cin >> new_name;
				run.modify(result, new_name);
				cout << "成功！\n";
				break;
			case choose_score:
				cout << "新成绩：";
				cin >> new_score;
				run.modify(new_score, result);
				cout << "成功！\n";
				break;
			Error:
				cout << "Error!!\n";
				break;
			}
			break;
		case choose_delete:
			cout << "您希望通过什么信息查找？（1--学号   2--姓名）";
			cin >> choice;
			switch (choice)
			{
			case choose_id:
				cout << "学号：";
				cin >> find_id;
				result = run.find(find_id);
				if (!result)
				{
					cout << "不存在！！\n";
					break;
				}
				break;
			case choose_name:
				cout << "姓名：";
				cin >> find_name;
				result = run.find(find_name);
				if (!result)
				{
					cout << "不存在！！\n";
					break;
				}
				break;
			Error:
				cout << "Error!!\n";
				break;
			}
			run.del(result);
			cout << "成功！\n";
			break;
		case choose_insert:
			cout << "请输入新学生的信息：";
			new_element = new element;
			cin >> new_element->id >> new_element->name >> new_element->score;
			run.insert(new_element);
			cout << "成功！\n";
			break;
		case choose_view:
			run.view();
			break;
		Error:
			if (choice == choose_exit)
			{
				break;
			}
			else
			{
				cout << "Error!!\n";
				continue;
			}
		}
		if (choice == choose_exit)
		{
			cout << "确定???\n";
			cout << " 再次输入0继续:";
			cin >> choice;
			if (choice == choose_exit)
				break;
		}
	}
	return 0;
}
