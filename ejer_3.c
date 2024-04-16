#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void cargarNombres(char* nombres[5], char* buff);

int main(int argc, char const *argv[])
{
    char* nombres[5];
    char *Buff; //variable auxiliar
    Buff= (char *) malloc(100*sizeof(char));

    // A. Cargar nombres
     cargarNombres(nombres, Buff);
    free(Buff);  
    return 0;
}
void cargarNombres(char* nombres[5], char* buff){
    for(int i = 0; i<strlen(nombres); i++){    
     printf ("Ingrese un nombre\n");
     gets(buff);
     strcpy(nombres[i],buff);
    }

    printf("\nNombres alamacenados");
    for (int i = 0; i < strlen(nombres); i++)
    {
        printf("Nombre [%d]", i+1, nombres[i]);
    }
    
}