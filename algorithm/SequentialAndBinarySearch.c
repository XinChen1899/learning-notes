#include"stdio.h"
#include"stdlib.h"
#include"time.h"

/**
 * 求字符串的长度
 **/
int lengthOfString(char* str){
    int i;
    for(i = 0; str[i] != '\0'; i++);
    return i;
}

/**
 * 对字符串进行遍历查找
 **/
int sequentialSearchChar(char* str, int length, char ch){
    for(int i = 0; i < length; i++){
        if(str[i] == ch){
            return i;
        }
    }
    return -1;
}

/**
 * 对字符串进行二分查找（递归）
 **/
int binarySearchChar(char* str, int high, int low, char ch){
    int mid = (high + low)/2;
    if(high < low){
        return -1;
    }
    if(str[mid] == ch){
        return mid;
    }
    else{
        int result1 = binarySearchChar(str, mid - 1, low, ch);
        if(result1 != -1){
            return result1;
        }
        else{
            return binarySearchChar(str, high, mid + 1, ch);
        }

    }
}

/**
 * 对升序数组进行顺序查找
 **/
int sequentialSearchInt(int* array, int num){
    for(int i = 0; i < 25; i++){
        if(array[i] == num){
            return i;
        }
    }
    return -1;
}

/**
 * 对升序数组进行二分查找
 **/
int binarySearchInt(int* array, int length, int num){
    int low = 0;
    int high = length - 1;
    int mid = 0;
    while(high >= low){
        mid = (high + low)/2;
        if(array[mid] == num){
            return mid;
        }
        else if(array[mid] > num){
            high = mid - 1;
        }
        else if(array[mid] < num){
            low = mid + 1;
        }
    }
    return -1;
}

void main(){
    clock_t start, end;
    /**
    char str[] = "jwhefuiohowjfhsiuhadjklqnkfr3u490uoqg3ru";
    char ch = 'a';
    int length = lengthOfString(str);
    int result1;
    int result2;
    start = clock();
    for(int i = 0; i < 100000; i++){
        result1 = sequentialSearch(str, length, ch);
    }
    end = clock();
    printf("sequential: %fms\n", (float)end - start);
    start = clock();
    for(int i = 0; i < 100000; i++){
        result2 = binarySearch(str, length - 1, 0, ch);
    }
    end = clock();
    printf("binary: %fms\n", (float)end - start);
    printf("sequential: %d\nbinary: %d", result1, result2);
    **/

    int array[25] = {1,3,4,5,6,8,10,13,15,19,21,25,27,28,33,37,38,41,44,45,46,51,56,59,63};
    int num = 41;
    start = clock();
    int result1, result2;
    for(int i = 0; i < 1000000; i++){
        result1 = sequentialSearchInt(array, num);
    }
    end = clock();
    printf("sequential: %d      time: %fms\n", result1, (float)end - start);
    start = clock();
    for(int i = 0; i < 1000000; i++){
        result2 = binarySearchInt(array, 25, num);
    }
    end = clock();
    printf("binary: %d      time: %fms\n", result2, (float)end - start);
}
