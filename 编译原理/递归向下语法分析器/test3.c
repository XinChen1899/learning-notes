#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define true 1
#define false 0
#define bool int

// 异常处理
void error(char* errmsg) {
	printf("\n%s\n",errmsg);
	exit(1);
}

/***********************************词法分析***************************************/
int move[128][24] = {
0,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
0,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
0,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
0,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
0,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
0,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
0,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
0,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
0,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
0,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
0,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
0,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
0,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
0,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
0,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
0,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
0,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
0,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
0,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
0,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
0,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
0,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
0,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
0,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
0,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
0,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
0,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
0,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
0,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
0,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
0,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
0,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
0,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
11,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
21,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
0,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
0,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
16,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
13,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	14,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
21,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
21,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
21,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
16,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
16,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
21,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
16,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
21,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
16,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
4,	2,	2,	0,	4,	5,	19,	19,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	19,	0,	22,	0,	17,
4,	2,	2,	0,	4,	5,	19,	19,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	19,	0,	22,	0,	17,
4,	2,	2,	0,	4,	5,	19,	19,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	19,	0,	22,	0,	17,
4,	2,	2,	0,	4,	5,	19,	19,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	19,	0,	22,	0,	17,
4,	2,	2,	0,	4,	5,	19,	19,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	19,	0,	22,	0,	17,
4,	2,	2,	0,	4,	5,	19,	19,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	19,	0,	22,	0,	17,
4,	2,	2,	0,	4,	5,	19,	19,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	19,	0,	22,	0,	17,
4,	2,	2,	0,	4,	5,	19,	19,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	19,	0,	22,	0,	17,
4,	2,	2,	0,	4,	5,	19,	19,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	19,	0,	22,	0,	17,
4,	2,	2,	0,	4,	5,	19,	19,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	19,	0,	22,	0,	17,
0,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
21,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
8,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
23,	3,	3,	0,	20,	20,	18,	18,	9,	10,	0,	9,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	9,
8,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
0,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
0,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
1,	2,	2,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
1,	2,	2,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
1,	2,	2,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
1,	2,	2,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
1,	2,	2,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
1,	2,	2,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
1,	2,	2,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
1,	2,	2,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
1,	2,	2,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
1,	2,	2,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
1,	2,	2,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
1,	2,	2,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
1,	2,	2,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
1,	2,	2,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
1,	2,	2,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
1,	2,	2,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
1,	2,	2,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
1,	2,	2,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
1,	2,	2,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
1,	2,	2,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
1,	2,	2,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
1,	2,	2,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
1,	2,	2,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
1,	2,	2,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
1,	2,	2,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
1,	2,	2,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
21,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
21,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
21,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
16,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
1,	2,	2,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
0,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
1,	2,	2,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
1,	2,	2,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
1,	2,	2,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
1,	2,	2,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
1,	2,	2,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
1,	2,	2,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
1,	2,	2,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
1,	2,	2,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
1,	2,	2,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
1,	2,	2,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
1,	2,	2,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
1,	2,	2,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
1,	2,	2,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
1,	2,	2,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
1,	2,	2,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
1,	2,	2,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
1,	2,	2,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
1,	2,	2,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
1,	2,	2,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
1,	2,	2,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
1,	2,	2,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
1,	2,	2,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
1,	2,	2,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
1,	2,	2,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
1,	2,	2,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
1,	2,	2,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
21,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
12,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	14,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
21,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
16,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
0,	3,	3,	0,	20,	20,	18,	18,	10,	10,	0,	0,	0,	0,	15,	0,	17,	0,	0,	20,	0,	22,	0,	17,
};

struct tableElement{
    int num;           //指针
    char value[256];   //符号值
    char type[20];     //类型
} arithmeticTable[256], delimiterTable[256], digitTable[256], identifierTable[256],
 keywordTable[256], logicalTable[256], relationalTable[256], symbol_table[1000];

int existedInTable(char* symbol, struct tableElement* table, int length){
    int i;
    for(i = 0; strcmp(table[i].value, symbol) && i < length; i++);
    if(i >= length && strcmp(symbol, table[length].value)){
        return -1;
    }
    else{
        return i;
    }
}

int takeWords(){
    FILE *arithmeticFile, *delimiterFile, *keywordFile, *logicalFile, *relationalFile;
    char buf[256] = "";
    int arithmeticTableLength = 0, delimiterTableLength = 0, digitTableLength = 0,
     identifierTableLength = 0, keywordTableLength = 0, logicalTableLength = 0, relationalTableLength = 0;
    int index;

    //算术运算符表导入
    arithmeticFile = fopen("arithmetic_table.txt", "r");
    arithmeticTableLength = 0;
    while(fgets(buf, sizeof(buf), arithmeticFile)){
        arithmeticTable[arithmeticTableLength].num = (int)buf[0] - '0';
        index = 0;
        for(int i = 1; buf[i] != '\0'; i++){
            if(buf[i] != 9 && buf[i] != 10){
                if(buf[i] >= '0' && buf[i] <= '9'){
                    arithmeticTable[arithmeticTableLength].num = arithmeticTable[arithmeticTableLength].num*10 + (int)buf[i] - '0';
                }
                else{
                    arithmeticTable[arithmeticTableLength].value[index] = buf[i];
                    index++;
                }
            }
        }
        strcpy(arithmeticTable[arithmeticTableLength].type, "算术运算符");
        arithmeticTableLength++;
    }

    //分隔符表导入
    delimiterFile = fopen("delimiter_table.txt", "r");
    delimiterTableLength = 0;
    while(fgets(buf, sizeof(buf), delimiterFile)){
        delimiterTable[delimiterTableLength].num = (int)buf[0] - '0';
        index = 0;
        for(int i = 1; buf[i] != '\0'; i++){
            if(buf[i] != 9 && buf[i] != 10){
                if(buf[i] >= '0' && buf[i] <= '9'){
                    delimiterTable[delimiterTableLength].num = delimiterTable[delimiterTableLength].num*10 + (int)buf[i] - '0';
                }
                else{
                    delimiterTable[delimiterTableLength].value[index] = buf[i];
                    index++;
                }
            }
        }
        strcpy(delimiterTable[delimiterTableLength].type, "分隔符");
        delimiterTableLength++;
    }

    //关键字表导入
    keywordFile = fopen("keyword_table.txt", "r");
    keywordTableLength = 0;
    while(fgets(buf, sizeof(buf), keywordFile)){
        keywordTable[keywordTableLength].num = (int)buf[0] - '0';
        index = 0;
        for(int i = 1; buf[i] != '\0'; i++){
            if(buf[i] != 9 && buf[i] != 10){
                if(buf[i] >= '0' && buf[i] <= '9'){
                    keywordTable[keywordTableLength].num = keywordTable[keywordTableLength].num*10 + (int)buf[i] - '0';
                }
                else{
                    keywordTable[keywordTableLength].value[index] = buf[i];
                    index++;
                }
            }
        }
        strcpy(keywordTable[keywordTableLength].type, "关键字");
        keywordTableLength++;
    }

    //逻辑运算符表导入
    logicalFile = fopen("logical_table.txt", "r");
    logicalTableLength = 0;
    while(fgets(buf, sizeof(buf), logicalFile)){
        logicalTable[logicalTableLength].num = (int)buf[0] - '0';
        index = 0;
        for(int i = 1; buf[i] != '\0'; i++){
            if(buf[i] != 9 && buf[i] != 10){
                if(buf[i] >= '0' && buf[i] <= '9'){
                    logicalTable[logicalTableLength].num = logicalTable[logicalTableLength].num*10 + (int)buf[i] - '0';
                }
                else{
                    logicalTable[logicalTableLength].value[index] = buf[i];
                    index++;
                }
            }
        }
        strcpy(logicalTable[logicalTableLength].type, "逻辑运算符");
        logicalTableLength++;
    }

    //关系运算符表导入
    relationalFile = fopen("relational_table.txt", "r");
    relationalTableLength = 0;
    while(fgets(buf, sizeof(buf), relationalFile)){
        relationalTable[relationalTableLength].num = (int)buf[0] - '0';
        index = 0;
        for(int i = 1; buf[i] != '\0'; i++){
            if(buf[i] != 9 && buf[i] != 10){
                if(buf[i] >= '0' && buf[i] <= '9'){
                    relationalTable[relationalTableLength].num = relationalTable[relationalTableLength].num*10 + (int)buf[i] - '0';
                }
                else{
                    relationalTable[relationalTableLength].value[index] = buf[i];
                    index++;
                }
            }
        }
        strcpy(relationalTable[relationalTableLength].type, "关系运算符");
        relationalTableLength++;
    }

    fclose(arithmeticFile);
    fclose(delimiterFile);
    fclose(keywordFile);
    fclose(logicalFile);
    fclose(relationalFile);

    FILE* identifierFile = fopen("identifier_table.txt", "w");
    FILE* digitFile = fopen("digit_table.txt", "w");

    FILE* infile = fopen("infile.txt", "r");
    FILE* outfile = fopen("symbol_table.txt", "w");
    char ch;
    int state = 0;
    int symbolLength = 0;   
    char symbol[256] = "";
    int symbolNum = 0;
    ch = fgetc(infile);
    while(ch != EOF){
        state = 0;
        symbolLength = 0;
        while(ch != EOF){
            state = move[ch][state];
            if(state != 3 && state != 17 && state != 10 
            && state != 20 && state != 18 && state != 15 && state != 22){
                if(state != 0){
                    symbol[symbolLength] = ch;
                    symbolLength++;
                }
            }
            else{
                break;
            }
            ch = fgetc(infile);
        }
        symbol[symbolLength] = '\0';
        int flag;
        if((flag = existedInTable(symbol, symbol_table, symbolNum)) < 0){
            switch(state){
                //判断为标识符或者关键字
                case 3:
                    if((flag = existedInTable(symbol, keywordTable, keywordTableLength)) >= 0){
                        fprintf(outfile, "%d\t\t%s\t\t%s\n", flag, symbol, "keyword");
                        symbol_table[symbolNum].num = flag;
                        strcpy(symbol_table[symbolNum].value, symbol);
                        strcpy(symbol_table[symbolNum].type, "keyword");
                        symbolNum++;
                        break;
                    }
                    else{
                        identifierTable[identifierTableLength].num = identifierTableLength;
                        strcpy(identifierTable[identifierTableLength].value, symbol);
                        strcpy(identifierTable[identifierTableLength].type, "identifier");
                        symbol_table[symbolNum].num = identifierTableLength;
                        strcpy(symbol_table[symbolNum].value, symbol);
                        strcpy(symbol_table[symbolNum].type, "identifier");
                        symbolNum++;
                        fprintf(outfile, "%d\t\t%s\t\t%s\n", identifierTableLength, symbol, "identifier");
                        fprintf(identifierFile, "%d\t\t%s\t\t%s\n", identifierTableLength, symbol, "identifier");
                        identifierTableLength++;
                        break;
                    }
                //判断为关系运算符
                case 10:
                    flag = existedInTable(symbol, relationalTable, relationalTableLength);
                    fprintf(outfile, "%d\t\t%s\t\t%s\n", flag, symbol, "relational");
                    symbol_table[symbolNum].num = flag;
                    strcpy(symbol_table[symbolNum].value, symbol);
                    strcpy(symbol_table[symbolNum].type, "relational");
                    symbolNum++;
                    break;
                //判断为逻辑运算符
                case 15:
                    flag = existedInTable(symbol, logicalTable, logicalTableLength);
                    fprintf(outfile, "%d\t\t%s\t\t%s\n", flag, symbol, "logical");
                    symbol_table[symbolNum].num = flag;
                    strcpy(symbol_table[symbolNum].value, symbol);
                    strcpy(symbol_table[symbolNum].type, "logical");
                    symbolNum++;
                    break;
                //判断为算术运算符
                case 17:
                    flag = existedInTable(symbol, arithmeticTable, arithmeticTableLength);
                    fprintf(outfile, "%d\t\t%s\t\t%s\n", flag, symbol, "arithmetic");
                    symbol_table[symbolNum].num = flag;
                    strcpy(symbol_table[symbolNum].value, symbol);
                    strcpy(symbol_table[symbolNum].type, "arithmetic");
                    symbolNum++;
                    break;
                //判断为无符号数
                case 20:
                    fprintf(outfile, "%d\t\t%s\t\t%s\n", digitTableLength, symbol, "digit");
                    fprintf(digitFile, "%d\t\t%s\t\t%s\n", digitTableLength, symbol, "digit");
                    symbol_table[symbolNum].num = digitTableLength;
                    strcpy(symbol_table[symbolNum].value, symbol);
                    strcpy(symbol_table[symbolNum].type, "digit");
                    digitTable[digitTableLength].num = digitTableLength;
                    strcpy(digitTable[digitTableLength].value, symbol);
                    strcpy(digitTable[digitTableLength].type, "digit");
                    symbolNum++;
                    digitTableLength++;
                    break;
                //判断为分隔符
                case 22:
                    flag = existedInTable(symbol, delimiterTable, delimiterTableLength);
                    fprintf(outfile, "%d\t\t%s\t\t%s\n", flag, symbol, "delimiter");
                    symbol_table[symbolNum].num = flag;
                    strcpy(symbol_table[symbolNum].value, symbol);
                    strcpy(symbol_table[symbolNum].type, "delimiter");
                    symbolNum++;
                    break;
                default:
                    break;
            }
        }
    }
    fclose(digitFile);
    fclose(identifierFile);
    fclose(infile);
    fclose(outfile);
    return symbolNum;
}

struct tableElement taken = {0, "", ""};

int table_pointer = 0;

void getNext(){
    strcpy(taken.type, symbol_table[table_pointer].type);
    taken.num = symbol_table[table_pointer].num;
    strcpy(taken.value, symbol_table[table_pointer].value);
    table_pointer++;
    printf("%s", taken.value);
}

/*************************************语法分析****************************************/
//归约
bool match(char* type, int pointer){
	bool result = true;
    if(!strcmp(taken.type, type)){
        if(!strcmp(taken.type, "identifier") || !strcmp(taken.type, "digit")){
            result = true;
        }
        else if(taken.num == pointer){
            result = true;
        }
    }
    else
        result = false;
	if(result)
        getNext();
    else
        error("Entry Word ERROR!");
}

void Exp();

void addop(){
    if (taken.num == 0)                                 // +
		match("arithmetic", 0) ;
	else
        match("arithmetic", 1) ;                       // -
}

void mulop(){
	if (taken.num == 2)                                 // *
		match("arithmetic", 2);
	else
        match("arithmetic", 3);                        // /
}

void factor(){
	if (!strcmp(taken.type, "identifier"))              // 标识符
		match("identifier", taken.num) ;
	else if (!strcmp(taken.type, "digit"))              // 无符号数
		match("digit", 0) ;
	else if (!strcmp(taken.type, "delimiter")){        // (
		match("delimiter", 3);
		Exp();
		match("delimiter", 4);                          // )
	} 
	else
        error("Entry Word ERROR!");
}

void term1(){
	if(!strcmp(taken.type, "arithmetic") && (taken.num == 2 || taken.num == 3)) {
		mulop();
		factor();
		term1();
	}
    else if(!strcmp(taken.type, "delimiter") || !strcmp(taken.type, "digit") || !strcmp(taken.type, "identifier")){
        return;
    }
    else if(!strcmp(taken.type, "keyword") || !strcmp(taken.type, "relational") || !strcmp(taken.type, "logical")){
        error("Entry Word ERROR!");
    }
}

void term(){
	factor();
	term1();
}

void exp1(){
	if (!strcmp(taken.type, "arithmetic") && (taken.num == 0 || taken.num == 1)) {
		addop();
		term();
		exp1();
	}
    else if(!strcmp(taken.type, "delimiter") || !strcmp(taken.type, "digit") || !strcmp(taken.type, "identifier")){
        return;
    }
    else if(!strcmp(taken.type, "keyword") || !strcmp(taken.type, "relational") || !strcmp(taken.type, "logical")){
        error("Entry Word ERROR!");
    }
}

void Exp(){
	term();
	exp1();
}

/**************************************主程序*****************************************/
void main(){
    int symbolNum = takeWords();
    getNext();
    Exp();
    printf("\nNo Error\n");
}