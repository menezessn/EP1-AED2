#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void main(){
    char empty[100] ="";
    char empty2[] = "";
    //printf("%s", empty);
    char fonte [] = "juntei";

    strcat(empty, fonte);
    printf("%s", empty);

    strcpy(empty, empty2);
    printf("%s", empty2);


}