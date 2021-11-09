#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;
  
    // Storing start time
    clock_t start_time = clock();
  
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}

void welcome(void){
    printf("Welcome\n");
    delay(10000);
    system("clear");
}

char losi(void){
    printf("(L)ogin\n(S)ignup");
    char losi;
    scanf("%c",&losi);
    losi = tolower(losi);
    return losi;
}
int main(void){
    welcome();
    losi();
}