#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    FILE *db = fopen("database.csv","r");
    char read[] = "yuvraj yuvraj yuvraj";
    char temp1[59];
    while(fgets(read, 59, db) != NULL){
        puts(temp1);
        printf("%s", temp1);
    }
}