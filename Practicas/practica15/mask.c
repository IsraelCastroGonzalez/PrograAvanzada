#include <stdio.h>

#define MASK_FULL 0b010
#define MASK_DELETE 0b001

typedef struct s{
    char f:3;
} Flags;

int main(){
    Flags status;
    // 1- // status.f  = 0b011;
    status.f  = 0b110;

    // 1- // if((status.f & (MASK_FULL | MASK_DELETE)) == (MASK_FULL | MASK_DELETE)){
    if((status.f & (MASK_FULL | MASK_DELETE)) != 0){
    // 1- // printf("The data is full and deleted\n");
        printf("The data is full or deleted\n");
    }
    return 0;
}