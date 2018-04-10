#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int W; // width of the building.
    int H; // height of the building.
    scanf("%d%d", &W, &H);
    int N; // maximum number of turns before game over.
    scanf("%d", &N);
    int X0;
    int Y0;
    scanf("%d%d", &X0, &Y0);
    
    int x1 = 0;
    int y1 = 0;
    int x2 = W - 1;
    int y2 = H - 1;

    // game loop
    while (1) {
        char bombDir[4]; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        scanf("%s", bombDir);
        fprintf(stderr, "%d %d\n", W,H);
        
      
        // Write an action using printf(). DON'T FORGET THE TRAILING \n
        // To debug: fprintf(stderr, "Debug messages...\n");
            
            if (strcmp(bombDir,"U")==0){
                fprintf(stderr, "Entra al U...\n");
              y2 = Y0-1;
            }
            else if (strcmp(bombDir,"UR")==0){
              fprintf(stderr, "Entra al UP...\n");
              x1 = X0+1;
              y2 = Y0-1;
            }
            else if (strcmp(bombDir,"R")==0){
                fprintf(stderr, "Entra al R...\n");
              x1 = X0+1;
            }
            else if (strcmp(bombDir,"DR")==0){
                fprintf(stderr, "Entra al DR...\n");
                x1 = X0+1;
                y1 = Y0+1;
            }
            else if (strcmp(bombDir,"D")==0){
                fprintf(stderr, "Entra al D...\n");
              y1 = Y0+1;
            }
            else if (strcmp(bombDir,"DL")==0){
                fprintf(stderr, "Entra al DL...\n");
              x2 = X0-1;
              y1 = Y0+1;
            }
            else if (strcmp(bombDir,"UL")==0){
                fprintf(stderr, "Entra al UL...\n");
              y2 = Y0-1;
              x2 = X0-1;
            }
            else {// move == L
              fprintf(stderr, "Entra al L...\n");
              x2 = X0-1;
            }
        fprintf(stderr, "Entra al x1: %d, x2: %d, y1: %d, y2: %d\n", x1,x2,y1,y2);
        
        X0 = x1 + (x2 - x1) / 2;
        Y0 = y1 + (y2 - y1) / 2;
        fprintf(stderr, "X0: %d Y0: %d\n", X0,Y0);
        
        printf("%d %d\n", X0, Y0);

        // the location of the next window Batman should jump to.
        
    }

    return 0;
}