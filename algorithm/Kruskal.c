#include"stdio.h"
#include"stdlib.h"
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
    int distance;
} paths[10] = {{2, 4, 1}, {0, 2, 3}, {3, 4, 3}, {1, 4, 4}, {0, 4, 5}, {0, 1, 6}, {2, 3, 6}, {1, 5, 7}, {2, 5, 8}, {0, 5, 9}};

int node_trees[3][6] = {-1, -1, -1, -1, -1, -1,
                        -1, -1, -1, -1, -1, -1,
                        -1, -1, -1, -1, -1, -1};    //子树结点集合
struct Path path_trees[3][5] = {{0, 0, 0}}; //子树边集合

//判断元素是否在数组中，返回布尔值
bool isInArray(int value, int* array, int length){
    int i = 0;
    for(i = 0; i < length; i++){
        if(array[i] == value){
            return true;
        }
    }
    return false;
}

//向结点子树插入结点
void insertNode(int node, int* node_tree){
    int i = 0;
    for(i = 0; i < 6; i++){
        if(node_tree[i] == -1){
            node_tree[i] = node;
            return;
        }
    }
}

//向边子树插入边
void insertPath(struct Path path, struct Path* path_tree){
    int i = 0;
    for(i = 0; i < 5; i++){
        if(path_tree[i].distance == 0){
            path_tree[i].start = path.start;
            path_tree[i].end = path.end;
            path_tree[i].distance = path.distance;
            return;
        }
    }
}

//获得结点所在子树的下标
int getTreeIndex(int node){
    int i = 0;
    for(i = 0; i < 3; i++){
        if(isInArray(node, node_trees[i], 6)){
            break;
        }
    }
    return i;
}

//合并两个结点子树
void unionNodeTree(int* tree1, int* tree2){
    int i, j;
    for(i = 0; i < 6 && tree2[i] != -1; i++){
        for(j = 0; j < 6 && tree1[j] != -1; j++);
        tree1[j] = tree2[i];
        tree2[i] = -1;
    }
}

//合并两个边子树
void unionPathTree(struct Path* tree1, struct Path* tree2){
    int i, j;
    for(i = 0; i < 5 && tree2[i].distance != 0; i++){
        for(j = 0; j < 5 && tree1[j].distance != 0; j++);
        tree1[j].start = tree2[i].start;
        tree1[j].end = tree2[i].end;
        tree1[j].distance = tree2[i].distance;
        tree2[i].start = 0;
        tree2[i].end = 0;
        tree2[i].distance = 0;
    }
}

//获得空子树的下标
int getEmptyTreeIndex(){
    int i;
    for(i = 0; i < 3; i++){
        if(node_trees[i][0] == -1){
            return i;
        }
    }
}

//获得最终结果所在子树的下标
int getResultTreeIndex(){
    int i;
    for(i = 0; i < 3; i++){
        if(node_trees[i][0] != -1){
            return i;
        }
    }
}

//核心算法
void Kruskal(){
    int counter = 0, i = 0, j = 0;
    struct Path min_path;
    bool flag = false;
    while(j < 10 && counter < 5){
        min_path.start = paths[j].start;
        min_path.end = paths[j].end;
        min_path.distance = paths[j].distance;
        flag = false;
        for(i = 0; i < 3; i++){
            if(isInArray(min_path.start, node_trees[i], 6) && isInArray(min_path.end, node_trees[i], 6)){
                flag = true;
                continue;
            }
            else if(isInArray(min_path.start, node_trees[i], 6)){
                int index = getTreeIndex(min_path.end);
                if(index < 3){
                    unionNodeTree(node_trees[i], node_trees[index]);
                    unionPathTree(path_trees[i], path_trees[index]);
                }
                else{
                    insertNode(min_path.end, node_trees[i]);
                }
                insertPath(min_path, path_trees[i]);
                counter++;
                flag = true;
                break;
            }
            else if(isInArray(min_path.end, node_trees[i], 6)){
                int index = getTreeIndex(min_path.start);
                if(index < 3){
                    unionNodeTree(node_trees[i], node_trees[index]);
                    unionPathTree(path_trees[i], path_trees[index]);
                }
                else{
                    insertNode(min_path.start, node_trees[i]);
                }
                insertPath(min_path, path_trees[i]);
                counter++;
                flag = true;
                break;
            }
        }
        if(!flag){
            int empty_tree_index = getEmptyTreeIndex();
            insertNode(min_path.start, node_trees[empty_tree_index]);
            insertNode(min_path.end, node_trees[empty_tree_index]);
            insertPath(min_path, path_trees[empty_tree_index]);
            counter++;
        }
        j++;
    }
}

void main(){
    int i, index;
    Kruskal();
    index = getResultTreeIndex();
    for(i = 0; i < 5; i++){
        printf("(%d, %d)\n", path_trees[index][i].start, path_trees[index][i].end);
    }
    printf("\n");
}