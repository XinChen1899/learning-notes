#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

void error(char *errmsg) {
	printf("%s\n",errmsg);
	exit(1);
}

/*******************符号表的相关准备工作**************************/
//符号表的基本数据结构
struct tableElement{
    int num;           //指针
    char value[256];   //符号值
    char type[20];     //类型
} arithmeticTable[256], delimiterTable[256], digitTable[256], identifierTable[256],
 keywordTable[256], logicalTable[256], relationalTable[256], symbol_table[1000];

//各种符号表的长度
int arithmeticTableLength = 0, delimiterTableLength = 0, digitTableLength = 0,identifierTableLength = 0, 
keywordTableLength = 0, logicalTableLength = 0, relationalTableLength = 0, symbolNum = 0;      //符号总个数

//查看符号symbol是否存在于某符号表table中
int existedInTable(char* symbol, struct tableElement* table, int length){
    int i;
    for(i = 0; strcmp(table[i].value, symbol) && i < length; i++);
    if(i >= length && strcmp(symbol, table[length-1].value)){
        return -1;
    }
    else{
        return i;
    }
}

//将文件中的默认符号表加载入程序
void initializeWordTable(){
    FILE *arithmeticFile, *delimiterFile, *keywordFile, *logicalFile, *relationalFile;
    char buf[256] = "";
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
}
/**************************读取符号相关准备*****************************/
//用来存放接下来获取的符号
struct taken{
    char type[20];      //符号类型
    int lineNum;        //符号在相应符号表中的索引
    char symbol[256];   //符号值
} takenSymbol = {"", 0, ""};

FILE* identifierFile;
FILE* digitFile;
FILE* infile;
FILE* outfile;

char ch;
int symbolLength = 0;   
char symbol[256] = "";

//获取下一个symbol
void takeNext(){
    initializeWordTable();
    int state = 0;
    symbolLength = 0;
    //先识别一个符号
    do{
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
    } while(ch != EOF);
    symbol[symbolLength] = '\0';
    int flag, flag1;        //flag用来查看符号在默认符号表中的索引值，flag1用来查看符号是否已经被识别过(查symbol_table)
    flag1 = existedInTable(symbol, symbol_table, symbolNum);    //如果符号表中并没有此符号就向表中加入此符号，并向相应文件输出
    char symbol_type[20] = "";
    switch(state){
    //判断为标识符或者关键字
        case 3:
            if((flag = existedInTable(symbol, keywordTable, keywordTableLength)) >= 0){
                strcpy(symbol_type, "keyword");
                if(flag1 < 0){
                    fprintf(outfile, "%d\t\t%s\t\t%s\n", flag, symbol, "keyword");
                    symbol_table[symbolNum].num = flag;
                    strcpy(symbol_table[symbolNum].value, symbol);
                    strcpy(symbol_table[symbolNum].type, "keyword");
                    symbolNum++;
                }
                break;
            }
            else{
                if(flag1 < 0){
                    identifierTable[identifierTableLength].num = identifierTableLength;
                    strcpy(identifierTable[identifierTableLength].value, symbol);
                    strcpy(identifierTable[identifierTableLength].type, "identifier");
                    symbol_table[symbolNum].num = identifierTableLength;
                    strcpy(symbol_table[symbolNum].value, symbol);
                    strcpy(symbol_table[symbolNum].type, "identifier");
                    symbolNum++;
                    fprintf(outfile, "%d\t\t%s\t\t%s\n", identifierTableLength, symbol, "identifier");
                    fprintf(identifierFile, "%d\t\t%s\t\t%s\n", identifierTableLength, symbol, "identifier");
                    flag = identifierTableLength;
                    identifierTableLength++;
                }
                else{
                    flag = existedInTable(symbol, identifierTable, identifierTableLength);
                }
                strcpy(symbol_type, "identifier");
                break;
            }
        //判断为关系运算符
        case 10:
            flag = existedInTable(symbol, relationalTable, relationalTableLength);
            if(flag1 < 0){
                fprintf(outfile, "%d\t\t%s\t\t%s\n", flag, symbol, "relational");
                symbol_table[symbolNum].num = flag;
                strcpy(symbol_table[symbolNum].value, symbol);
                strcpy(symbol_table[symbolNum].type, "relational");
                symbolNum++;
            }
            strcpy(symbol_type, "relational");
            break;
        //判断为逻辑运算符
        case 15:
            flag = existedInTable(symbol, logicalTable, logicalTableLength);
            if(flag1 < 0){
                fprintf(outfile, "%d\t\t%s\t\t%s\n", flag, symbol, "logical");
                symbol_table[symbolNum].num = flag;
                strcpy(symbol_table[symbolNum].value, symbol);
                strcpy(symbol_table[symbolNum].type, "logical");
                symbolNum++;
            }
            strcpy(symbol_type, "logical");
            break;
        //判断为算术运算符
        case 17:
            flag = existedInTable(symbol, arithmeticTable, arithmeticTableLength);
            if(flag1 < 0){
                fprintf(outfile, "%d\t\t%s\t\t%s\n", flag, symbol, "arithmetic");
                symbol_table[symbolNum].num = flag;
                strcpy(symbol_table[symbolNum].value, symbol);
                strcpy(symbol_table[symbolNum].type, "arithmetic");
                symbolNum++;
            }
            strcpy(symbol_type, "arithmetic");
            break;
        //判断为无符号数
        case 20:
            if(flag1 < 0){
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
            }
            strcpy(symbol_type, "digit");
            break;
        //判断为分隔符
        case 22:
            flag = existedInTable(symbol, delimiterTable, delimiterTableLength);
            if(flag1 < 0){
                fprintf(outfile, "%d\t\t%s\t\t%s\n", flag, symbol, "delimiter");
                symbol_table[symbolNum].num = flag;
                strcpy(symbol_table[symbolNum].value, symbol);
                strcpy(symbol_table[symbolNum].type, "delimiter");
                symbolNum++;
            }
            strcpy(symbol_type, "delimiter");
            break;
        default:
            break;
    }
    takenSymbol.lineNum = flag;
    strcpy(takenSymbol.symbol, symbol);
    strcpy(takenSymbol.type, symbol_type);
    printf("\nnext taken: %s\t%s\t%d\n\n", takenSymbol.symbol, takenSymbol.type, takenSymbol.lineNum);
}

/**************************语法分析相关准备***************************/
//定义goto转换矩阵结构，27为状态个数，5为非终结符数
int _goto[30][5] = 
{
-1, -1, -1, -1, -1,
-1, -1, -1, -1, -1,
3,  4,  5,  -1, -1,
-1, -1, -1, -1, 9,
-1, -1, -1, 12, -1,
-1, -1, -1, -1, -1,
15,	16,	17, -1, -1,
-1, -1, -1, -1, -1,
-1, -1, -1, -1, -1,
-1,	21,	5,  -1, -1,
-1, -1, -1, -1, -1,	
-1, -1, -1, -1, -1,	
-1,	-1,	22, -1, -1,
-1, -1, -1, -1, -1,	
-1, -1, -1, -1, -1,	
-1,	-1, -1, -1,	23,
-1, -1, -1,	25, -1,
-1, -1, -1, -1, -1,
26,	16,	17,	-1,	-1,
-1, -1, -1, -1, -1,	
-1, -1, -1, -1, -1,	
-1,	-1,	-1,	12, -1,
-1, -1, -1, -1, -1,	
-1,	27,	17,	-1, -1,
-1, -1, -1, -1, -1,	
-1, -1,	28, -1,	-1,
-1,	-1, -1, -1,	23,
-1,	-1,	-1,	25,	-1,	
-1, -1, -1, -1, -1,
-1, -1, -1, -1, -1
};

//定义动作表aciton结构，27为状态个数，8为终结符数
char action[30][10][5] = 
{
"", 	"", 	"", 	"", 	"", 	"", 	"", 	"s1",	"", 	"",
"", 	"", 	"", 	"", 	"", 	"", 	"s2",	"", 	"", 	"",
"", 	"", 	"", 	"", 	"s6",	"", 	"", 	"s7",	"s8",	"",
"s10",	"s11",	"", 	"", 	"", 	"", 	"", 	"", 	"", 	"acc",
"r3",	"r3",	"s13",	"s14",	"", 	"", 	"", 	"", 	"", 	"r3",
"r7",	"r7",	"r7",	"r7",	"", 	"", 	"", 	"", 	"", 	"r7",
"", 	"", 	"", 	"", 	"s18",	"s19",	"s20",	"", 	"", 	"", 
"r11",	"r11",	"r11",	"r11",	"", 	"", 	"", 	"", 	"", 	"r11",
"r12",	"r12",	"r12",	"r12",	"", 	"", 	"", 	"", 	"", 	"r12",
"", 	"", 	"", 	"", 	"s6",	"", 	"", 	"s7",	"s8",	"",
"", 	"", 	"", 	"", 	"r4",	"", 	"", 	"r4",	"r4",	"",
"", 	"", 	"", 	"", 	"r5",	"", 	"", 	"r5",	"r5",	"",
"", 	"", 	"", 	"", 	"s6",	"", 	"", 	"s7",	"s8",	"",
"", 	"", 	"", 	"", 	"r8",	"", 	"", 	"r8",	"r8",	"",
"", 	"", 	"",	    "", 	"r9",	"", 	"", 	"r9",	"r9",	"",
"s10",	"s11",	"", 	"", 	"", 	"s24",	"", 	"", 	"", 	"",
"r3",	"r3",	"s13",	"s14",	"", 	"r3",	"", 	"", 	"", 	"",
"r7",	"r7",	"r7",	"r7",	"", 	"r7",	"", 	"", 	"", 	"",
"", 	"", 	"", 	"", 	"s18",	"", 	"", 	"s19",	"s20",	"",
"r11",	"r11",	"r11",	"r11",	"", 	"r11",	"", 	"", 	"", 	"",
"r20",	"r20",	"r20",	"r20",	"", 	"r20",	"", 	"", 	"", 	"",
"r2",	"r2",	"s13",	"s14",	"", 	"", 	"", 	"", 	"", 	"r2",
"r6",	"r6",	"r6",	"r6",	"", 	"", 	"", 	"", 	"", 	"r6",
"", 	"", 	"", 	"", 	"s18",	"", 	"", 	"s19",	"s20",	"",
"r10",	"r10",	"r10",	"r10",	"",  	"", 	"", 	"", 	"", 	"r10",
"", 	"", 	"", 	"", 	"s18",	"", 	"", 	"s19",	"s20",	"",
"s10",	"s11",	"", 	"", 	"", 	"s29",	"", 	"", 	"", 	"",
"s2",	"r2",	"s13",	"s14",	"", 	"r2",	"", 	"",     "", 	"",
"", 	"", 	"", 	"", 	"s18",	"", 	"", 	"s19",	"s20",	"",
"r10",	"r10",	"r10",	"r10",	"", 	"r10",	"", 	"", 	"", 	""
};

int state_stack[20], top = 0;               //状态栈&栈顶指针

//symb用于语义规则计算
//其中lexeme代表组成该名字的字符串序列，place用来记住符号表条目的地址(一律在symbol_table查找)
//接下来还会编写三个函数：
//lookup(该名字是否存在，返回地址)、newTemp(产生一个新的临时变量名字，存入符号表并返回条目地址)、emit(构成一条三地址指令并输出)
struct symb{
    char lexeme[20];
    int place;
} id_symb_stack[20], expr, expr1, term, term1, addop, mulop, factor, id, num;      //id_symb_stack对战用于维护翻译过程中的标识符

int id_symb_stack_top = 0;      //id_symb_stack的栈顶指针

//临时变量可取的名字
char temps[30][4] = {"t0",  "t1",   "t2",   "t3",   "t4",   "t5",   "t6",   "t7",   "t8",   "t9",
                    "t10",  "t11",   "t12",   "t13",   "t14",   "t15",   "t16",   "t17",   "t18",   "t19",
                    "t20",  "t21",   "t22",   "t23",   "t24",   "t25",   "t26",   "t27",   "t28",   "t29"};

//lookup: 名字lexeme是否存在于符号表，若存在，返回条目地址，否则返回-1
int lookup(char* lexeme){
    return existedInTable(lexeme, symbol_table, symbolNum);
}

//newTemp: 新建临时变量，存入符号表中，返回条目地址
int newTemp(){
    int i;
    for(i = 0; i < 30; i++){
        if(existedInTable(temps[i], symbol_table, symbolNum) < 0){
            strcpy(symbol_table[symbolNum].value, temps[i]);
            strcpy(symbol_table[symbolNum].type, "temporary");
            symbol_table[symbolNum].num = -1;
            symbolNum++;
            return (symbolNum - 1);
        }
    }
    printf("临时变量不够......\n");
    return -1;
}

FILE* threeAddressFile;
//emit: 这里的place1全都是针对symbol_table索引的
void emit(int place1, int place2, char* op, int place3){
    char lexeme1[20], lexeme2[20], lexeme3[20];
    strcpy(lexeme1, symbol_table[place1].value);
    strcpy(lexeme2, symbol_table[place2].value);
    if(strcmp(op, "\0") && place3 != -1){
        strcpy(lexeme3, symbol_table[place3].value);
        fprintf(threeAddressFile, "%s=%s%s%s\n", lexeme1, lexeme2, op, lexeme3);
    }
    else{
        fprintf(threeAddressFile, "%s=%s\n", lexeme1, lexeme2);
    }
}

union un{
	int linenum;
	float number;
} attribute_stack[20];          //属性值栈

//LR1文法属性计算以及生成三地址代码
int produces(int class){
    int p = 0;
	int column;
	switch(class){
        case 1:	
            //printf("\nS = %f\n",attribute_stack[top].number);
            printf("%s\n" , "statmt -> id = expr"); 
            id_symb_stack_top = 0;                              //此处归约需要的标识符一定来自于栈底
            id.place = id_symb_stack[id_symb_stack_top].place;
            strcpy(id.lexeme, id_symb_stack[id_symb_stack_top].lexeme);
            top = top - 1;
            column = 0;
            printf("@@@@@@@@@@@@@@@@     pop %s\n", id.lexeme);
            p = lookup(id.lexeme);
            emit(p, expr.place, "\0", -1);
            fprintf(threeAddressFile, "\n");
            break;
        case 2:	
            if (attribute_stack[top - 1].linenum == 0)
                attribute_stack[top - 2].number = attribute_stack[top - 2].number + attribute_stack[top].number;
            else
                attribute_stack[top - 2].number = attribute_stack[top - 2].number - attribute_stack[top].number;
            printf("%s\n" , "expr -> expr addop term"); 
            top = top - 3;
            column = 0;
            expr1.place = expr.place;
            expr.place = newTemp();
            emit(expr.place, expr1.place, addop.lexeme, term.place);
            break; 
        case 3: 
            printf("%s\n" , "expr -> term"); 
            top = top - 1;
            column = 0;
            expr.place = newTemp();
            emit(expr.place, term.place, "\0", -1);
            break;	
        case 4: 
            printf("%s\n" , "addop -> +"); 
            top = top - 1;
            column = 4;
            strcpy(addop.lexeme, "+");
            break;	
        case 5: 
            printf("%s\n" , "addop -> -"); 
            top = top - 1;
            column = 4;
            strcpy(addop.lexeme, "-");
            break;
        case 6: 
            if (attribute_stack[top - 1].linenum == 2)
                attribute_stack[top - 2].number = attribute_stack[top - 2].number * attribute_stack[top].number;
            else
                attribute_stack[top - 2].number = attribute_stack[top - 2].number / attribute_stack[top].number;
            printf("%s\n" , "term -> term mulop factor"); 
            top = top - 3;
            column = 1;
            term1.place = term.place;
            term.place = newTemp();
            emit(term.place, term1.place, mulop.lexeme, factor.place);
            break; 
        case 7: 
            printf("%s\n" , "term -> factor"); 
            top = top - 1;
            column = 1;
            term.place = newTemp();
            emit(term.place, factor.place, "\0", -1);
            break;	
        case 8: 
            printf("%s\n" , "mulop -> *");
            top = top - 1;
            column = 3;
            strcpy(mulop.lexeme, "*");
            break;	 
        case 9: 
            printf("%s\n" , "mulop -> /");
            top = top - 1;
            column = 3;
            strcpy(mulop.lexeme, "/");
            break;	
        case 10:
            attribute_stack[top - 2].number = attribute_stack[top - 1].number ;
            printf("%s\n" , "factor -> (expr)");
            top = top - 3;
            column = 2;
            factor.place = newTemp();
            emit(factor.place, expr.place, "\0", -1);
            break; 
        case 11:
            printf("%s\n" , "factor -> id");
            id_symb_stack_top--;
            id.place = id_symb_stack[id_symb_stack_top].place;
            strcpy(id.lexeme, id_symb_stack[id_symb_stack_top].lexeme);
            printf("@@@@@@@@@@@@@@@@     pop %s\n", id.lexeme);
            top = top - 1;
            column = 2;
            p = lookup(id.lexeme);
            emit(factor.place, p, "\0", -1);
            break;
        case 12:
            printf("%s\n" , "factor -> number");
            top = top - 1;
            column = 2;
            factor.place = newTemp();
            p = lookup(num.lexeme);
            emit(factor.place, p, "\0", -1);
            break;
        default: 
            column = 5;
            break;
    };
	return column;
}

//LR1语法分析
int LR1(){
	int p, column;
	int state;
	column = 29;
    top = 0;
	state_stack[top] = 0;
	attribute_stack[top].number = 0.0;
 	while(1){
		if(!strcmp(takenSymbol.type, "delimiter")){
			if(takenSymbol.lineNum == 3){
                column = 4;
            } 
			else if(takenSymbol.lineNum == 4){
                column = 5;
            }
			else{
                column = 9; 
            }
        }
		if(!strcmp(takenSymbol.type, "arithmetic")){
            column = takenSymbol.lineNum;
        }
		if(!strcmp(takenSymbol.type, "digit")){
            strcpy(num.lexeme, takenSymbol.symbol);
            num.place = lookup(num.lexeme);
            column = 8;
        }
        if(!strcmp(takenSymbol.type, "identifier")){
            //每遇到一个标识符就将此标识符压入栈
            strcpy(id.lexeme, takenSymbol.symbol);
            id.place = lookup(id.lexeme);
            id_symb_stack[id_symb_stack_top].place = id.place;
            strcpy(id_symb_stack[id_symb_stack_top].lexeme, id.lexeme);
            id_symb_stack_top++;
            printf("****************     push %s\n", id.lexeme);
            column = 7;
        } 
		if(column >= 10){
            return 0;
        }
		if(action[state_stack[top]][column][0] == 's'){                    //移进
			state = atoi(action[state_stack[top]][column] + 1);
			top = top + 1;
			state_stack[top] = state;
			if(!strcmp(takenSymbol.type, "digit")){
                attribute_stack[top].number = (float)atof(takenSymbol.symbol);
            }
            else
				attribute_stack[top].linenum = takenSymbol.lineNum;
			do{
				takeNext();
			}while(ch != EOF && symbol[0] == '\0');
		}
		else if(action[state_stack[top]][column][0] == 'r'){                //归约
            p = atoi(action[state_stack[top]][column] + 1);
            column = produces(p) ;
            state = _goto[state_stack[top]][column] ;
            if(state == 0){
                return 0;
            }
            top = top + 1;
			state_stack[top] = state;
		}
		else if(action[state_stack[top]][column][0] == 'a'){               //接受
            column = produces(1);                                          //先归约，再接受
            return 1;
		}
		else{
            return 0;
        }
	}
	return 1;
}

int main(){
    printf("111111111111");
    identifierFile = fopen("identifier_table.txt", "w");
    digitFile = fopen("digit_table.txt", "w");
    outfile = fopen("symbol_table.txt", "w");
    infile = fopen("infile.txt", "r");
    threeAddressFile = fopen("three_address_code.txt", "w");

    ch = fgetc(infile);

    while(ch != EOF){
        do {
            takeNext();
        }while (ch != EOF && symbol[0] =='\0') ;
        if (LR1()){
            printf("\nRight\n\n");
        }
        else{
            printf("\nError\n\n");
            //去到下一行的开头，为接下来的分析做准备
            while(ch != EOF && ch != ';' && ch != '\n'){
                ch = fgetc(infile);
            }
        }
        if( ch != EOF ){
            ch = fgetc(infile);
        } 
    }

    fclose(infile);
    fclose(outfile);
    fclose(digitFile);
    fclose(identifierFile);
    fclose(threeAddressFile);
    return 0;
}