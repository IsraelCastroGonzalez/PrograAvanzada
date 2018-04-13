#include <stdio.h>
#include <unistd.h>

int main(){
    int pid;
    pid = fork();
    if(pid == 0){
        execl("D:\\Drive\\Escuela\\Progra Avanzada\\Practicas\\practica12\\hijo.c","hijo.exe", (char*)0);
        printf("Hola mundo soy el hijo.\n");
    }
    else{
        printf("Hola mundo, soy el perro amo.\n");
    }
    return 0;
}