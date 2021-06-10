#include"stdio.h"
#include"stdlib.h"
#define true 1
#define false 0
#define bool int

int graph[6][6] = {0, 6,  3, -1, 5, 9,
                  6, 0, -1, -1, 4, 7,
                  3, -1, 0,  6, 1, 8, 
                 -1, -1, 6,  0, 3, -1,
                  5, 4,  1,  3, 0, -1,
                  9, 7,  8, -1,-1, 0};

bool visited[6] = {false};

//递归
void DFS(int visiting_node){
    visited[visiting_node] = true;
    printf("%d\t", visiting_node);
    int present_node = 0;
    for(present_node = 0; present_node < 6; present_node++){
        if(graph[visiting_node][present_node] > 0){
            if(!visited[present_node]){
                DFS(present_node);
            }
        }
    }
}

void DFT(){
    int i = 0;
    for(i = 0; i < 6; i++){
        if(!visited[i]){
            DFS(i);
        }
    }
}

//非递归
int not_finished_nodes[6] = {-1, -1, -1, -1, -1, -1};
int top = 0;        //栈顶下标

void push(int node){
    not_finished_nodes[top] = node;
    top++;
}

int pop(){
    top--;
    return not_finished_nodes[top];
}

void DFS2(int visiting_node){
    bool visited[6] = {false};
    visited[visiting_node] = true;
    int present_node = 0;
    push(visiting_node);
    while(top > 0){
        visiting_node = pop();
        for(present_node = 0; present_node < 6; present_node++){
            if(graph[visiting_node][present_node] > 0){
                if(!visited[present_node]){
                    visited[present_node] = true;
                    push(visiting_node);
                    visiting_node = present_node;
                }
            }
        }
        printf("%d\t", visiting_node);
    }
}

void main(){
    DFT();
    printf("finish!");
    printf("\n");
    DFS2(0);
    printf("finish!");
}