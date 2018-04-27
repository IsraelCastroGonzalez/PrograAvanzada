#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define NUM_THREADS 20

void * helloWorld(void * p){
    long id =(long)p;
    char *msg = (char *) malloc(25*sizeof(char));
    sprintf(msg,"Hello World %ld\n",id);
    return (void *)msg;
}

int main(){
    
    pthread_t threads[NUM_THREADS];
    long i;
    char *msg;

    for(i = 0; i < NUM_THREADS; i++){
        pthread_create(
            &threads[i],
            NULL,
            helloWorld,
            (void *)i
        );
    }

    for(i = 0; i < NUM_THREADS; i++){ 
        pthread_join(
            threads[i],
            (void *)&msg
        );
        printf("%s",msg);
        free(msg);
    }

    return 0;
}