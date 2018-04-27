#include <stdio.h>

typedef struct d{
    unsigned char day:4;
    unsigned char month:5;
    unsigned short year;
} Date;

int main (){
    Date today = {26,4,2018};
    printf("Today is %d/%d/%d \n", today.day, today.month, today.year);
    if((today.day ^ 26) == 0){
        printf("Today is 26\n");
    }
    return 0;
}