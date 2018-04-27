#include <stdio.h>

int main(){
    int pid = fork();
    if(pid == 0){
        pid = fork();
        if(pid == 0){
            printf("Soy el daemon\n");
            fclose(stdout);
            fclose(stdin);
            while(1){

            }
        }
    }

    return 0;
}