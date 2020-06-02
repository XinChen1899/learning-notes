#include<iostream>
#include<cstring>
using namespace std;


//typedef btelement* element;


/*
0、构建树
1、前中后序遍历(递归)
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
		cout << root->data.weight << '\t';
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
		cout << root->data.weight << '\t';
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
		cout << root->data.weight << '\t';
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
