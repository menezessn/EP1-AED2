#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
    char* a = (char*) malloc(sizeof(char));
    int n = 1;
    sprintf(a, "%d", n);
   
    printf("%s", a);
}