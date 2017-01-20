#include <stdio.h>

int main()
{
    char cmd[50];
    
    printf("Inserire il comando: ");
    gets(cmd);

    // system(cmd);
    system("prova.bat");
    
    printf("\n\n");
    system("Pause");
}
