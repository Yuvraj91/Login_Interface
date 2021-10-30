#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ncurses.h>
#include <ctype.h>
#include <stdbool.h>

//main
int main(void){

    //custom data structure
    typedef struct{
        char *username;
        char *password;
        char *name;
    }
    profile;
    
    //opening database
    FILE *db = fopen("database.csv","a");
    if(db == NULL){
        printf("Some error opening file\n");
        return 1;
    }
    
    //creating a temp profile
    profile temp;
    
    //losi function
    int a = 0;
    while(a==0){
        char losi;
        char read[59];
        printf("(L)ogin\n(S)ignup\n");
        scanf("%c",&losi);
        losi = tolower(losi);
        if(losi == 'l'){
            printf("Username:- ");
            scanf("%s", &temp.username);
            printf("Password:- ");
            scanf("%s", &temp.password);
            a++;
            char *temp1 = "";
            while(fgets( read, 59, db) != NULL){
                for(int i = 0, n = strlen(read); i < n ; i++){
                    if(read[i] == " "){
                        break;
                    }
                    temp1[i] = read[i]; 
                }
                if(strcmp(temp1, *temp.username) == 0){
                    printf("Username found\n");
                }
            }
        }
        else if(losi == 's'){
            printf("Name:- ");
            scanf("%s", &temp.name);
            printf("Username:- ");
            scanf("%s", &temp.username);
            printf("Password:- ");
            scanf("%s", &temp.password);
            a++;
        }
    }

    printf("%s %s", &temp.username, &temp.password);
}