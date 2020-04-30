#pragma warning(disable:4996)
#include<iostream>
#include<cstring>
using namespace std;

typedef char element;

template<class element>
class stack
{
private:
	int stack_size;               //堆栈的最大长度
	int top;                      //栈顶坐标
	element* stack_element;       //堆栈存储池
public:
    stack(int);
	bool isempty() { return top == -1; };                //判断堆栈是否为空
	bool isfull() { return top >= stack_size - 1; };     //判断堆栈是否已满
	bool push(element&);                                 //向堆栈压入元素
	bool pop(element&);                                  //从堆栈弹出元素
	bool get_top(element&);                              //取到栈顶元素的值
	~stack() { delete[] stack_element; };
};

template<class element>
stack<element>::stack(int max_size)
{
	stack_size = max_size;
	top = -1;
	stack_element = new element[stack_size];
}

template<class element>
bool stack<element>::push(element& temp)
{
	if (isfull())
		return false;
	top++;
	stack_element[top] = temp;
	return true;
}

template<class element>
bool stack<element>::pop(element& temp)
{
	if (isempty())
		return false;
	temp = stack_element[top];
	top--;
	return true;
}

template<class element>
bool stack <element>::get_top(element& temp)
{
	if (isempty())
		return false;
	temp = stack_element[top];
	return true;
}
//表达式转换类
class expression
{
private:
	char sentence[50];        //需要输入的中缀表达式
public:
	expression(char* cin_sen) { strcpy(sentence, cin_sen); };
	bool check();               //检查表达式的括号匹配
	bool translate();           //将表达式翻译成后缀表达式
};

bool expression::check()
{
	//判断表达式的各类括号的匹配程度
	bool check_sentence = true;
	int max_size;
	char temp = '\0';
	max_size = sizeof(sentence);
	stack<element> run(max_size);
	for (int i = 0; sentence[i] != '\0'; i++)
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
			check_sentence = run.get_top(temp);
			if (!check_sentence || temp != '(')
			{
				cout << "有‘)’不匹配！\n";
				check_sentence = false;
				break;
			}
			run.pop(temp);
			break;
		case ']':
			check_sentence = run.get_top(temp);
			if (!check_sentence || temp != '(')
			{
				cout << "有‘]’不匹配！\n";
				check_sentence = false;
				break;
			}
			run.pop(temp);
			break;
		case '}':
			check_sentence = run.get_top(temp);
			if (!check_sentence || temp != '(')
			{
				cout << "有‘}’不匹配！\n";
				check_sentence = false;
				break;
			}
			run.pop(temp);
			break;
		default:
			break;
		}
	}
	if (run.get_top(temp))  //检查是否仍有左括号未匹配
	{
		cout << "有‘" << temp << "’不匹配！\n";
		check_sentence = false;
	}
	return check_sentence;
}

bool expression::translate()
{
	int max_size;
	max_size = sizeof(sentence);
	char tran_sen[50] = {'\0'}, temp = '\0';       //tran_sen即为后缀表达式
	char* memory = tran_sen;
	stack<element> run(max_size);
	if (!check())
		return false;
	for (int i = 0; sentence[i] != '\0'; i++)
	{
		if (sentence[i] <= '9' && sentence[i] >= '0')        //当为数字时，直接压入tran_sen
		{
			*memory = sentence[i];
			memory++;
		}
		else if (sentence[i] == '{' || sentence[i] == '[' || sentence[i] == '(')    //当为左括号或 * ，/ 时，压入栈中
			run.push(sentence[i]);
		else if (sentence[i] == '*' || sentence[i] == '/')
			run.push(sentence[i]);
		else if (sentence[i] == '+' || sentence[i] == '-')//当为 + , - 时，与栈顶比较，若栈顶为 * , / ，则 * , / 出栈，否则 + ， - 入栈
		{
			run.get_top(temp);
			while ((temp == '*' || temp == '/')&& !run.isempty())
			{
				run.pop(temp);
				*memory = temp;
				memory++;
				run.get_top(temp);
			}
			run.push(sentence[i]);
		}
		else if (sentence[i] == '}' || sentence[i] == ']' || sentence[i] == ')')//当为右括号时，左括号以前的元素全部出栈
		{
			switch (sentence[i])
			{
			case '}':
				while (temp != '{')
				{
					run.pop(temp);
					if (temp != '{')
					{
						*memory = temp;
						memory++;
					}
				}
				break;
			case ']':
				while (temp != '[')
				{
					run.pop(temp);
					if (temp != '[')
					{
						*memory = temp;
						memory++;
					}
				}
				break;
			case ')':
				while (temp != '(')
				{
					run.pop(temp);
					if (temp != '(')
					{
						*memory = temp;
						memory++;
					}
				}
				break;
			default:
				break;
			}
		}
	}
	while (!run.isempty())        //使栈中剩余元素出栈
	{
		run.pop(temp);
		if (temp != '(' && temp != '[' && temp != '{')
		{
			*memory = temp;
			memory++;
		}
	}
	cout << tran_sen;
	return true;
}

int main()
{
	char sentence[50];
	cout << "请输入需要计算的表达式（皆为已知数,无需“=”，enter结束）:\n";
	cin.getline(sentence,50);
	expression run(sentence);
	if (run.translate())
		return 1;
	return 0;
}
