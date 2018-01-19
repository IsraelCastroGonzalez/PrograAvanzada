#include <stdio.h>

int main(){
    int a = 250;
    int j = 0, k = 0, l = 0;
    int *p;
    long int d = a * a; //long no es necesario
    float f = (int)4.67;
    int e = 4;
    int c = f +e;
    p = &a;
    *p = 400;
    p++;
    *p = 5555;

    printf("a= %d, p= %p, j= %d, k= %d, l= %d\n",a,p,j,k,l);
    //cualquier caracter que empieze con % lo sustituye
    //con la variable indicada
    //printf("a = %d, d= %ld, f = %f, e = %e, c = %d\n", a,d,f,e,c);
    //printf("a = %p, d= %ld, f = %f, e = %e, c = %d\n", &a,d,f,e,c); //impre direccion en memoria


    return 0;
}