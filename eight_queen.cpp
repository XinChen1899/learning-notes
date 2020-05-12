#include<iostream>
#include<cmath>
using namespace std;
const int n = 8;
int chess[n][n] = {0};
bool success(int row, int line)
{ 
	for(int ro = 0; ro < row; ro++)
	{
		for(int li = 0; li < n; li++)
		{
			if(chess[ro][li] == 1)
			{
				if(row == ro || line == li || abs(ro - row) == abs(li - line))
					return false;
			}
		}
	}
	return true;
}
void print_chess()
{	
	for(int ro = 0; ro < n; ro++)
	{
		for(int li = 0; li < n; li++)
		{
			cout << chess[ro][li] << " ";
		}
		cout << endl;
	}
	cout << endl;
	return;
}
int  num = 0;
void queue(int row)
{
	if(row == n)
	{
		cout << "第" << ++num << "个八皇后序列输出：" << endl;
		print_chess();
	}
	else
	{
		for (int li = 0; li < n; li++)
		{
			chess[row][li] = 1;
			if (success(row, li))
			{
				queue(row + 1);
			} 			
			chess[row][li] = 0;
		}
	}
	return;
} 
int main()
{
	queue(0);
	return 0;
}
