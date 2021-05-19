#include"stdlib.h"
#include"stdio.h"
#include"string.h"

#define MAX_TABLE_LENGTH 1000    //符号表的容量为1000;

struct{
    int id;
    char value[256];
} table[MAX_TABLE_LENGTH];


int move[2][4] = {
    1, 1, 0, 0,
    1, 1, 1, 2
};

int tableLength = 0;

int getCharType(char ch){
    if(ch == '_'){
        return 0;
    }
    else if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')){
        return 1;
    }
    else if(ch >= '0' && ch <= '9'){
        return 2;
    }
    else{
        return 3;
    }
}

void main(){
    char ch;
    char symbol[256] = "";
    int state;
    int tail;
    int type;
    int symbolLength = 0;

    FILE* infile, * outfile;

    if((infile = fopen("test.txt", "r")) == NULL){
        printf("input file open failed");
        exit(-1);
    }

    if((outfile = fopen("table.txt", "w")) == NULL){
        printf("output file open failed");
        exit(-2);
    }

    ch = fgetc(infile);

    while(ch != EOF){
        state = 0;
        tail = 0;
        type = getCharType(ch);
        symbolLength = 0;
        while(ch != EOF){
            state = move[state][type];
            if(state == 1){
                symbol[tail] = ch;
                tail++;
                symbolLength++;
            }
            if(state == 2){
                break;
            }
            ch = fgetc(infile);
            type = getCharType(ch);
        }
        symbol[tail] = '\0';
        if(symbolLength > 0){
            int i;
            for( i = 0; i < tableLength && strcmp(table[i].value, symbol); i++);
            if(i >= tableLength){
                strcpy(table[tableLength].value, symbol);
                table[tableLength].id = tableLength;
                tableLength++;
            }
            printf("%d    %s\n", table[i].id, table[i].value);
        }
    }

    printf("      symbol table       \n");
    for(int i = 0; i < tableLength; i++){
        printf("%d        %s\n", table[i].id, table[i].value);
        fprintf(outfile, "%d        %s\n", table[i].id, table[i].value);
    }

    fclose(infile);
    fclose(outfile);
}
