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

    // game loop
    
    int currentBX = X0;
    int currentBY = Y0;
    int minimumH, maximumH = Y0;
    
    while (1) {
        char bombDir[4]; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        scanf("%s", bombDir);

        // Write an action using printf(). DON'T FORGET THE TRAILING \n
        // To debug: fprintf(stderr, "Debug messages...\n");
        fprintf(stderr, "WE READ %s\n", bombDir);
        
        if(strcmp(bombDir, "U") == 0){
            int nextMoveU = 0;
            //The next if checks if batman's already been up there comparing his position to his minimumH
            if(((currentBY)/2) <= 2 || (currentBY - minimumH)/2 <=5 ){
                nextMoveU = 1;
            }
            else{
                nextMoveU = (H - currentBY)/2;
            }
                        
            int batmanMoveV = currentBY - nextMoveU;
            
            currentBY = batmanMoveV;//UPDATE HIS CURRENT POSITION

            if(currentBY < minimumH){
                minimumH = currentBY;    
            }
            
            printf("%d %d\n", currentBX, batmanMoveV);
                
        }
        else if(strcmp(bombDir, "D") == 0){
            int nextMoveD = 0;
            if(((H - currentBY)/2) <= 2 ){
                nextMoveD = 1;
            }
            else{
                nextMoveD = (H - currentBY)/2;
            }
            int batmanMoveV = currentBY + nextMoveD;
            
            currentBY = batmanMoveV;//UPDATE HIS CURRENT POSITION
            
            if(currentBY < maximumH){
                maximumH = currentBY;    
            }
            
            printf("%d %d\n", currentBX, batmanMoveV);  
        }
        else if(strcmp(bombDir, "L") == 0){
                
        }
        else if(strcmp(bombDir, "R") == 0){
            int nextMoveR = 0;
            if(((W - currentBX)/2) <= 2 ){
                nextMoveR = 1;
            }
            else{
                nextMoveR = (W - currentBX)/2;
            }
            int batmanMoveH = currentBX + nextMoveR;
            
            currentBX = batmanMoveH;//UPDATE HIS CURRENT POSITION
            
            printf("%d %d\n", batmanMoveH, currentBY);  
        }
        
        
        if(strcmp(bombDir, "UR") == 0){
            int nextMoveR = (W - currentBX)/2;
            int batmanMoveH = currentBX + nextMoveR;
            int nextMoveU = (currentBY)/2;
            int batmanMoveV = currentBY - nextMoveU;
            
            currentBX = batmanMoveH;//UPDATE HIS CURRENT POSITION
            currentBY = batmanMoveV;//UPDATE HIS CURRENT POSITION
            
            if(currentBY < minimumH){
                minimumH = currentBY;    
            }
            
            //fprintf(stderr, "WE PRINT %d %d\n", batmanMoveH, batmanMoveV);
            printf("%d %d\n", batmanMoveH, batmanMoveV);    
        }
        else if(strcmp(bombDir, "DR") == 0){
            int nextMoveR = (W - currentBX)/2;
            int batmanMoveH = currentBX + nextMoveR;
            int nextMoveD = (H - currentBY)/2;
            int batmanMoveV = currentBY + nextMoveD;
            
            currentBX = batmanMoveH;//UPDATE HIS CURRENT POSITION
            currentBY = batmanMoveV;//UPDATE HIS CURRENT POSITION
            
            maximumH = currentBY;    
            
            //fprintf(stderr, "WE PRINT %d %d\n", batmanMoveH, batmanMoveV);
            printf("%d %d\n", batmanMoveH, batmanMoveV);    
        }
        else if(strcmp(bombDir, "UL") == 0){
            int nextMoveL = 0;
            int nextMoveU = 0;
            
            if((maximumH - minimumH)<=5){
                nextMoveU = 2;
            }else{
                nextMoveU = (currentBY)/2;
            }
            
            if(((currentBX-X0)/2) <= 5 ){
                nextMoveL = 1;
            }
            else{
                nextMoveL = (currentBX-X0)/2;
            }
            
            int batmanMoveV = currentBY - nextMoveU;
            int batmanMoveH = currentBX - nextMoveL;
            
            currentBX = batmanMoveH;//UPDATE HIS CURRENT POSITION
            currentBY = batmanMoveV;//UPDATE HIS CURRENT POSITION
            
            minimumH = currentBY;    
            
            
            //fprintf(stderr, "WE PRINT %d %d\n", batmanMoveH, batmanMoveV);
            printf("%d %d\n", batmanMoveH, batmanMoveV);    
        }
        else if(strcmp(bombDir, "DL") == 0){
            int nextMoveL = (currentBX)/2;
            int nextMoveD = 0;
            
            if((H - currentBY)/2 >= maximumH){
                nextMoveD = (maximumH - currentBY)/2;
            }else{
                nextMoveD = (H - currentBY)/2;
            }
            
            
            int batmanMoveH = currentBX - nextMoveL;
            int batmanMoveV = currentBY + nextMoveD;
            
            currentBX = batmanMoveH;//UPDATE HIS CURRENT POSITION
            currentBY = batmanMoveV;//UPDATE HIS CURRENT POSITION
            
            if(currentBY < maximumH){
                maximumH = currentBY;    
            }
            
            //fprintf(stderr, "WE PRINT %d %d\n", batmanMoveH, batmanMoveV);
            printf("%d %d\n", batmanMoveH, batmanMoveV);    
        }

        // the location of the next window Batman should jump to.
        
    }

    return 0;
}