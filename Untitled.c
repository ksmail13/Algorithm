#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char name[2][20];
    
    scanf("%s %s", &name[0], &name[1]);
    
    printf("%s %s\n", name[0], name[1]);
    printf("\t%d \t\t%d\n", strlen(name[0]), strlen(name[1]));
    return 0;
}