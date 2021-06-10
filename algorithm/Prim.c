#include<stdlib.h>
#include<stdio.h>
#define true 1
#define false 0
#define bool int

//图的邻接矩阵
int cost[6][6] = {0, 6,  3, -1, 5, 9,
                  6, 0, -1, -1, 4, 7,
                  3, -1, 0,  6, 1, 8, 
                 -1, -1, 6,  0, 3, -1,
                  5, 4,  1,  3, 0, -1,
                  9, 7,  8, -1,-1, 0};

//边的基本数据结构
struct Path{
    int start;
    int end;
};

//判断数字是否在数组中
int isInArray(int value, int* array, int length){
	int i;
	for(i = 0; i < length; i++){
		if(array[i] == value){
			return true;
		}
	}
	return false;
}

//求数组中value大于零最小结点下标
int minIndex(int* array, int length){
	int min = 0, i, index = 0;
	for(i = 0; i < length; i++){
		if(array[i] > 0){
			if(min == 0){
				min = array[i];
				index = i;
			}
			else if(array[i] < min){
				min = array[i];
				index = i;
			}

		}
	}
	return index;
}

//输出数组
void printArray(int* array){
	int i = 0;
	for(i = 0; i < 6; i++){
		printf("%d\t", array[i]);
	}
	printf("\n");
}

void Prim(struct Path* tree){
	int nodes[6] = {-1};	//用于记录已被划入树中的结点
	int near[6] = {-1};		//near[i]表示：如果i不在树中，near[i]就是树中离i最近的结点；如果i在树中，那near[i]就等于0
	int counter = 1;		//用来记录当前生成树中的结点个数，[0:6]
	int i, j;
	nodes[0] = 0;
	int mincost;
	bool flag;
	while(counter < 6){
		//生成near
		for(j = 0; j < 6; j++){
			mincost = 0;
			flag = false;
			//j用来遍历图中所有结点，j即为结点编号
			//先看j是否在树中，在的话就直接把near值赋值为0
			if(isInArray(j, nodes, 6)){
				near[j] = 0;
			}
			//如果不在，就要一一检查树中结点与j的路径长度，找到最小的长度
			else{
				for(i = 0; i < counter; i++){
					//i用来遍历当前生成树中的结点，nodes[i]即为结点编号
					if(cost[j][nodes[i]] >= 0){
						if(mincost == 0){
							mincost = cost[j][nodes[i]];
						}
						else if(cost[j][nodes[i]] < mincost){
							mincost = cost[j][nodes[i]];
						}
						flag = true;
					}
				}
				if(flag){
					near[j] = mincost;
				}
				else{
					near[j] = -1;
				}
			}
		}
		int index = minIndex(near, 6);
		nodes[counter] = index;
		for(i = 0; i < 6; i++){
			if(cost[i][index] == near[index]){
				tree[counter - 1].start = i;
				tree[counter - 1].end = index;
				break;
			}
		}
		counter++;
	}
	return;
}

void main(){
	struct Path tree[5];
	Prim(tree);
	int i = 0;
	for(i = 0; i < 5; i++){
		printf("{%d, %d}\n", tree[i].start, tree[i].end);
	}
}
