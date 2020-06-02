#include<iostream>
#include<cstring>
using namespace std;

typedef char elementdata;

struct btelement
{
	elementdata data;
	btelement* left;
	btelement* right;
};

//typedef btelement* element;

struct element
{
	btelement* ptr;
	bool check;
};

#include"stack.h"

/*
0、构建树
1、前中后序遍历，递归与非递归
2、是否空
3、求高度
4、求叶子数
5、删除树
*/

template<class btelement>
class binary_tree
{
public:
//*******************数据********************
	btelement* btroot;
	int num;
	int leaves_num;
//*******************函数********************
	binary_tree() { num = 0; btroot = NULL; leaves_num = 0; };
	btelement* create_node(elementdata&);
	void create_bt(btelement*, btelement*, btelement*);
	bool isempty() { return btroot == NULL; };
	int measure_heigh(btelement*);
	int count_leaves(btelement*);
	//递归遍历
	void preorder_re(btelement*);
	void inorder_re(btelement*);
	void postorder_re(btelement*);
	//非递归遍历
	void preorder();
	void inorder();
	void postorder();
	void delete_bt(btelement*);
	~binary_tree() { delete_bt(btroot); };
};

template<class btelement>
btelement* binary_tree<btelement>::create_node(elementdata& temp)
{
	btelement* newvalue = new btelement;
	if (!newvalue)
		return NULL;
	newvalue->data = temp;
	newvalue->left = NULL;
	newvalue->right = NULL;
	return newvalue;
}

template<class btelement>
void binary_tree<btelement>::create_bt(btelement* root, btelement* le, btelement* ri)
{
	if (btroot == NULL)
	{
		btroot = root;
		num++;
	}
	root->left = le;
	root->right = ri;
	num += 2;
	return;
}

template<class btelement>
int binary_tree<btelement>::measure_heigh(btelement* root)
{
	if (root == NULL)
		return 0;
	int le = measure_heigh(root->left);
	int ri = measure_heigh(root->right);
	if (le >= ri)
	{
		le++;
		return le;
	}

	else
	{
		ri++;
		return ri;
	}
}

template<class btelement>
int binary_tree<btelement>::count_leaves(btelement* root)
{
	if (root->left == 0 && root->right == 0)
		return ++leaves_num;
    count_leaves(root->left);
	count_leaves(root->right);
}

template<class btelement>
void binary_tree<btelement>::preorder_re(btelement* root)
{
	if (root)
	{
		cout << root->data << '\t';
		preorder_re(root->left);
		preorder_re(root->right);
	}
}

template<class btelement>
void binary_tree<btelement>::inorder_re(btelement* root)
{
	if (root)
	{
		inorder_re(root->left);
		cout << root->data << '\t';
		inorder_re(root->right);
	}
}

template<class btelement>
void binary_tree<btelement>::postorder_re(btelement* root)
{
	if (root)
	{
		postorder_re(root->left);
		postorder_re(root->right);
		cout << root->data << '\t';
	}
}

template<class btelement>
void binary_tree<btelement>::delete_bt(btelement* root)
{
	if (root)
	{
		delete_bt(root->left);
		delete_bt(root->right);
		delete root;
	}
}

template<class btelement>
void binary_tree<btelement>::preorder()
{
	btelement* temp = btroot;
	element p;
	stack s(num);
	while (temp != NULL || !s.isempty())
	{
		if (temp != NULL)
		{
			cout << temp->data << '\t';
			p.ptr = temp;
			s.push(p);
			temp = temp->left;
		}
		else if (!s.isempty())
		{
			s.pop(p);
			temp = p.ptr;
			temp = temp->right;
		}
	}
}

template<class btelement>
void binary_tree<btelement>::inorder()
{
	btelement* temp = btroot;
	element p;
	stack s(num);
	while (temp != NULL || !s.isempty())
	{
		while (temp != NULL)
		{
			p.ptr = temp;
			s.push(p);
			temp = temp->left;
		}
		if (!s.isempty())
		{
			s.pop(p);
			temp = p.ptr;
			cout << temp->data << '\t';
			temp = temp->right;
		}
	}
}

template<class btelement>
void binary_tree<btelement>::postorder()
{
	btelement* temp = btroot;
	element p;
	stack s(num);
	while (temp != NULL || !s.isempty())
	{
		while (temp != NULL)
		{
			p.ptr = temp;
			p.check = false;
			s.push(p);
			temp = temp->left;
		}
		if (!s.isempty())
		{
			s.pop(p);
			temp = p.ptr;
			if (p.check)
			{
				cout << temp->data << '\t';
				temp = NULL;          //very important
			}
			else
			{
				p.check = true;
				s.push(p);
				temp = temp->right;
			}
		}
	}
}

int main()
{
	char bt_data[10] = { '1','2','3','4','5','6','7','8','9','0' };
	binary_tree<btelement> run;
	btelement* p[11];
	for (int i = 0; i < 10; i++)
	{
		p[i] = run.create_node(bt_data[i]);
		p[i + 1] = NULL;
	}
	for (int i = 1; 2 * i <= 10; i++)
	{
		run.create_bt(p[i - 1], p[2 * i - 1], p[2 * i]);
	}
	for (int i = 0; i < 10; i++)
	{
		cout << i << '\t' << p[i]->data << '\t' << p[i]->left << '\t' << p[i]->right << '\n';
	}
	cout << p[9];
	cout << endl;
	run.preorder_re(run.btroot);
	cout << endl;
	run.preorder();
	cout << endl;
	run.inorder_re(run.btroot);
	cout << endl;
	run.inorder();
	cout << endl;
	run.postorder_re(run.btroot);
	cout << endl;
	run.postorder();
	cout << endl;
	return 0;
}
