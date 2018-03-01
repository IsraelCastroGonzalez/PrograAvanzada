#include <stdio.h>

FILE *inicioLexema, *avance, *finalOfFile;

char obtenerSiguienteCaracter()
{
    return fgetc(avance);
}

void rechazarPalabra()
{
    long inicioPalabra = ftell(inicioLexema);
    fseek(avance, inicioPalabra, SEEK_SET);
}

int isfeof()
{
    char c = obtenerSiguienteCaracter();
    rechazarPalabra();
    return c == EOF;
}

void aceptarEspacio()
{
    long finPalabra = ftell(avance);
    fseek(inicioLexema, finPalabra, SEEK_SET);
}

int isNormalChar(int c)
{
    return (c != ' ' && c != '\n' && c != '\t' && c != EOF);
}

void operacionError()
{
    printf("%s %d\n", "no es un numero");
    exit(0);
}

int equalizer()
{
    char c = obtenerSiguienteCaracter();
    if (c == ' ' || c =='\n' || c == '\t')
    {
        if(c == '\n')
        {
            ++numeroLinea;
        }
        return 1;
    }
    rechazarPalabra();
    return -1;
}

int numeros()
{
    int estadoActual = 0;
    char c = obtenerSiguienteCaracter();
    

    while (isNormalChar(c) && estadoActual != -1 && c != ';')
    {
        switch (estadoActual){
        case 0:
            if(c == '0')
            {
                estadoActual = 1;
            }
            else if(isdigit(c))
            {
                estadoActual = 2;
            }
            else
            {
                estadoActual= -1;
            }
            break;
        case 1:
            if(c >= '1' && c <= '7')
            {
                estadoActual = 3;
            }
            else if(c == 'x' || c == 'X')
            {
                estadoActual = 4;
            }
            else if(c == '.')
            {
                estadoActual = 5;
            }
            else
            {
                estadoActual= -1;
            }
            break;
        case 2:
            if(isdigit(c))
            {
                estadoActual = 2;
            }
            else if(c == '.')
            {
                estadoActual = 5;
            }
            else
            {
                estadoActual = -1;
            }
            break;
        case 3:
            estadoActual = (c >= '0' && c <= '7') ? 3 : -1;
            break;
        case 4:
            estadoActual = (c >= '0' && c <= '9' || c >= 'a' && c <= 'f'|| c >= 'A' && c <= 'F') ? 4 : -1;
            break;
        case 5:
            estadoActual = (isdigit(c)) ? 6:-1;
            break;
        case 6:
            if(isdigit(c))
            {
                estadoActual = 6;
            }
            else if(c == 'e' || c == 'E')
            {
                estadoActual = 7;
            }
            else
            {
                estadoActual = -1;
            }
            break;
        case 7:
            if(isdigit(c))
            {
                estadoActual = 8;
            }
            else if(c == '+' || c == '-')
            {
                estadoActual = 9;
            }
            break;
        case 8:
            estadoActual = (isdigit(c)) ? 8 : -1;
            break;
        case 9:
            estadoActual = (isdigit(c)) ? 8 : -1;
            break;
        default:
            estadoActual = -1;
            break;
        }
        c = obtenerSiguienteCaracter();
    }

    if (estadoActual == 2 || estadoActual == 3 || estadoActual == 4 || estadoActual == 6 || estadoActual == 8)
    {
        return estadoActual;
    }
    rechazarPalabra();
    
    return -1;
}


int main()
{
    inicioLexema = fopen("origen.txt", "r");
    avance = fopen("origen.txt", "r");
    finalOfFile = fopen("origen.txt", "r");
    fseek(finalOfFile, 0, SEEK_END);

    int c; 

    while (!isfeof())
    {
        if(equalizer() != -1)
        {
            aceptarEspacio();
        }
        else if((c = numeros()) != -1)
        {
            aceptarPalabra();
            puts("Numero de punto flotante");
        }
        else
        {
            operacionError();
        }

    }

    fclose(inicioLexema);
    fclose(avance);
    //system("PAUSE");
    system("read -p 'Press Enter to continue...' var");
    //getc(stdin);
    return 0;
}