#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>




void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;
  
    // Storing start time
    clock_t start_time = clock();
  
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}




int welcome(void){
    printf("Welcome\n");
    delay(5000);
    system("clear");
    return 0;
}



char losi(void){
    system("clear");
    printf("(L)ogin\n(S)ignup\n");
    char losi;
    scanf("%c",&losi);
    losi = tolower(losi);
    system("clear");
    return losi;
}




int main(void){
    //custom data-structure for profile
    typedef struct
    {
        char username[20];
        char password[16];
    }
    profile;
    profile template_profile;
    char a;
    //login and signup prompt
    do
    {
        a = losi();

        if(a == 'l'){
            printf("username:- ");
            scanf("%s",template_profile.username);
            printf("password:- ");
            scanf("%s",template_profile.password);
            break;
        }
        else if(a == 's'){
            printf("username:- ");
            scanf("%s",template_profile.username);
            printf("password:- ");
            scanf("%s",template_profile.password);
            break;
        }
        else{
            continue;
        }
    
    }while(1);

    system("clear");

    if(a == 'l'){
        //opening database
        FILE *db = fopen("database.csv","r");
        //exceptional handling
        if(db == NULL){
            printf("Some error opening file\n");
            return 1;
        }
        //buffer for read
        char buffer[42];

        int row = -1;
        int column = 0;
        while(fgets(buffer, 42, db)){
            column = 0;
            row++;
            char *data = strtok(buffer, ", ");
            while(data){
                if(strcmp(data,template_profile.username) == 0){
                    data = strtok(NULL,", ");
                    if(strcmp(data, template_profile.password) == 0){
                        printf("You are now logged in as %s\n",template_profile.username);
                        return 0;
                    }
                    else{
                        printf("Either the password or the username is not correct");
                        return 0;
                    }
                }
                data = strtok(NULL,", ");
            }
        }
        fclose(db);
        return 0;
    }
    else{
        //opening database
        FILE *db = fopen("database.csv","r+");
        //exceptional handling
        if(db == NULL){
            printf("Some error opening file\n");
            return 1;
        }
        //buffer for reading
        char buffer[42];

        int row = -1;

        while(fgets(buffer, 42, db)){
            row++;
            char *data = strtok(buffer, ", ");
            while(data){
                if(strcmp(data,template_profile.username) == 0){
                    printf("Username already exits");
                    return 0;
                }
                data = strtok(NULL,", ");
            }
        }
        
        fprintf(db, "\n%s, %s,",template_profile.username, template_profile.password);
        printf("Account created\n");
        
        fclose(db);
    }
}