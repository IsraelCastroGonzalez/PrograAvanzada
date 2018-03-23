#include <stdio.h>
#include <string.h>

int main()
{
    char *filename = "myfile.txt";
    char *search = "pork";
    char *replace = "abierto";
    int character;
    int firstCharacter;
    int streamPos = 0;
    char isReplaced = 0;
    int i = 0;
    FILE *myFile = fopen(filename, "r");

    while (1)
    {
        character = fgetc(myFile);
        streamPos = ftell(myFile);
        if (feof(myFile))
        {
            break;
        }
        if(character == search[0]){
            i = 0;
            while(!feof(myFile) && search[i] == character){
                character = fgetc(myFile);
                i++;
            }
            if(feof(myFile)){
                break;
            }
            if( i == strlen(search)){
                fputs(replace, stdout);
                isReplaced = 1;
                fseek(myFile, -1, SEEK_CUR);
            }
            else{
                //rewind
                character = firstCharacter;
                fseek(myFile, streamPos, SEEK_SET);
            }
        }
        if(!isReplaced){
            fputc(character, stdout);
        }
        isReplaced = 0;
    }
    fclose(myFile);
    return 0;
}