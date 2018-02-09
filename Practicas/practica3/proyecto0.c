#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

typedef struct a {
    long *data;
    int dataSize;
    int position;
} Array;

void appendArray(Array *a, double value){
    if (a ->data == NULL)
        {
            a ->dataSize = 1;
            a ->position = 0;
            a ->data = (double *)malloc(a ->dataSize * sizeof(long));
        }
        if (a ->position == a ->dataSize)
        {
            a ->dataSize = 2 * a ->dataSize;
            a ->data = (double *)realloc(a ->data, a ->dataSize * sizeof(double));
        }
        a ->data [a->position] = value;
        a ->position = a ->position +1;
}

void printArrayReverse(Array a){
    for (int i = a.position - 1; i >= 0; i--){
        printf("%.4f\n",a.data[i]);
    }
}

int main()
{
    long Ai = 0;
    int c;
    Array results;

    do
    {
        c = getchar();
        while (!isdigit(c))
        {
            c = getchar();
        }
        Ai = 0;
        while (isdigit(c))
        {

            Ai = Ai * 10;
            Ai = Ai + (c - '0');
            c = getchar();
        }
        //STORAGE THE RESULT
        appendArray(&results, sqrt((double)Ai));
        
        //printf("%.4lf", results[position-1]); //hace que trunque a 4 decimales el resultado **como extra solito redondea asi que matamos una piedra a pajarasos

    } while (c != 10);
    printArrayReverse(results);
    return 0;
}