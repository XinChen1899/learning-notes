#include"stdlib.h"
#include"stdio.h"
#include"time.h"


int array[10000] = {0};   //排序数组

/**
 * 打印array数组
 **/
void printArray(){
    for(int i = 0; i < 10000; i++){
        printf("%d\t", array[i]);
    }
}

void merge(int low, int mid, int high);

/**
 * 归并排序 
 **/
void mergeSort(int low, int high){
    int mid = 0;
    if(low < high){
        mid = (high + low)/2;
        mergeSort(low, mid);
        mergeSort(mid + 1, high);
        merge(low, mid, high);
    }
}

void merge(int low, int mid, int high){
    int h, i, j, k;
    int temp[10000] = {0};
    h = low;
    i = low;
    j = mid + 1;
    while(h <= mid && j <= high){
        if(array[h] <= array[j]){
            temp[i] = array[h];
            h++;
        }
        else{
            temp[i] = array[j];
            j++;
        }
        i++;
    }
    if(h > mid){
        for(k = j; k <= high; k++){
            temp[i] = array[k];
            i++;
        }
    }
    else{
        for(k = h; k <= mid; k++){
            temp[i] = array[k];
            i++;
        }
    }
    for(k = low; k <= high; k++){
        array[k] = temp[k];
    }
}

/**
 * 快速排序
 **/
void quickSort(int low, int high)
{
	if (low >= high)
		return;
	int key = 0, lo = low, hi = high;
	int temp;
	temp = array[lo];
	key = array[lo];
	while (lo < hi)
	{
		while (lo < hi && array[hi] > key)
			hi--;
		if (lo < hi)
		{
			array[lo] = array[hi];
			lo++;
		}
		while (lo < hi && array[lo] < key)
			lo++;
		if (lo < hi)
		{
			array[hi] = array[lo];
			hi--;
		}
	}
	array[lo] = key;
	quickSort(low, lo - 1);
	quickSort(lo + 1, high);
	return;
}

void main(){
    int arrTemp[10000];  //因为每做一次排序array都会变化，因此用此数组生成随机数组同时记录array的最初状态
    //生成随机数组
    for(int i = 0; i < 10000; i++){
        arrTemp[i] = rand()%50000+1;
    }
    for(int i = 0; i < 10000; i++){
        array[i] = arrTemp[i];
    }
    clock_t start, end;
    start = clock();
    quickSort(0, 9999);
    end = clock();
    //printArray();
    printf("quickSort:  time: %fms", (float)end - start);
    //将array还原到最开始的乱序状态
    for(int i = 0; i < 10000; i++){
        array[i] = arrTemp[i];
    }
    start = clock();
    mergeSort(0, 9999);
    end = clock();
    printf("mergeSort   time: %fms", (float)end - start);
}
