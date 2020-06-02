

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

stack::stack(int max_size)
{
	stack_size = max_size;
	top = -1;
	stack_element = new element[stack_size];
}

bool stack::push(element& temp)
{
	if (isfull())
		return false;
	top++;
	stack_element[top] = temp;
	return true;
}

bool stack::pop(element& temp)
{
	if (isempty())
		return false;
	temp = stack_element[top];
	top--;
	return true;
}

bool stack::get_top(element& temp)
{
	if (isempty())
		return false;
	temp = stack_element[top];
	return true;
}
