#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PRINTDEBUG(...) do{\
char *debug;\                
debug = getenv("DEBUG");\
if(debug != NULL && !strcasecmp(debug, "y")){\
fprintf(stderr,__VA_ARGS__);\
}\
}while(0)\

int main(){
    int character;
    //fgetc = LEE/REGRESA ARACTER DEL STRING Y SE MUEVE AL SIGUIENTE CARACTER
    while(1){
        character = fgetc(stdin);
        if(feof(stdin)){
            break;
        }
        fputc(character,stdout);
        PRINTDEBUG("Character = %c\n", character);
        //fputc = IMPRIME A PANTALLA
    }
    return 0;

}