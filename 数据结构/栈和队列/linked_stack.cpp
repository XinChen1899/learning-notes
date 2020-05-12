#include<iostream>
#include<cstring>
using namespace std;

typedef struct element
{
	char data;
	element* prec;
};

typedef char element_data;

template<class element>
class linked_stack
{
private:
	int size;
	element* top;
public:
	linked_stack() { top = NULL, size = 0; };
	bool isempty() { return top == NULL; };
	void push(element_data);
	bool pop(element_data);
	bool get_top(element_data&);
	~linked_stack()
	{
		element* temp = top;
		while (temp != NULL)
		{
			temp = top->prec;
			delete top;
			top = temp;
		}
	}
};

template<class element>
void linked_stack<element>::push(element_data temp)
{
	element* p = new element;
	p->data = temp;
	p->prec = top;
	top = p;
	size++;
	return;
}

template<class element>
bool linked_stack<element>::pop(element_data temp)
{
	if (isempty())
		return false;
	temp = top->data;
	element* p = top->prec;
	delete top;
	top = p;
	return true;
}

template<class element>
bool linked_stack<element>::get_top(element_data& temp)
{
	if (isempty())
		return false;
	temp = top->data;
	return true;
}

int main()
{
	//判断字符串的各类括号的匹配程度
	bool check = true;
	int max_size;
	char sentence[100], temp = '\0';
	cout << "请输入一串带有括号的字符串(西文字符)：";
	cin.getline(sentence, 100);
	max_size = sizeof(sentence);
	linked_stack<element> run;
	for (int i = 0; i < max_size; i++)
	{
		switch (sentence[i])
		{
		case '(':
			run.push(sentence[i]);
			break;
		case '[':
			run.push(sentence[i]);
			break;
		case '{':
			run.push(sentence[i]);
			break;
		case ')':
			check = run.get_top(temp);
			if (!check || temp != '(')
			{
				cout << "有‘)’不匹配！\n";
				check = false;
				break;
			}
			run.pop(temp);
			break;
		case ']':
			check = run.get_top(temp);
			if (!check || temp != '(')
			{
				cout << "有‘]’不匹配！\n";
				check = false;
				break;
			}
			run.pop(temp);
			break;
		case '}':
			check = run.get_top(temp);
			if (!check || temp != '(')
			{
				cout << "有‘}’不匹配！\n";
				check = false;
				break;
			}
			run.pop(temp);
			break;
		default:
			break;
		}
	}
	if (run.get_top(temp))
	{
		cout << "有‘" << temp << "’不匹配！\n";
		check = false;
	}
	if (check)
		cout << "所有括号运用正确！！" << endl;
	return 0;
}
