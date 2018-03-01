```
swap(char **st1,char **st1){
    char ** tmp = *st1;
    *st1 = *st2;
    *st2 = *tmp;
}
swap(&name, &lastname);
```
---

Tamaño???
isConsonant(char c);

```
#include <stdio.h>
#define MAXLENGHT 255
int main (){
    char word[MAXLENGHT]; //crear un espacio en memoria para un arreglo de 255 espacios
    printf("Introduce una cadena: ");
    scanf("%s", word);
    for(int i = 0; i < strlen(word); i++){
        if(isConsonant(word[i])){
            printf("%c",wor[i]);
        }
    }

}
```
---

