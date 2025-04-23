#include <stdio.h>
#include <conio.h>

int writetofile(void)
{
    char user_input[20],inputtofile[20];
    FILE *filew;
    printf("What file do u want to write stuff too?:\t");
    scanf("%s",&user_input);
    filew = fopen(user_input,"w+");
    printf("Say ur messsage!");
    scanf("%s",inputtofile);
    fprintf(filew,"%s\n",inputtofile);
    fclose(filew);
    printf("done\n");
}
