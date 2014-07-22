#include <stdio.h>
#define LIMIT 1000

void createtree(int *tree, int index); 
void printtree(int *tree, int index);

int main() {
    int tree[LIMIT] = {};
    createtree(tree, 1);
    printtree(tree, 1);
    putchar('\n');
    return 0;
}


void createtree(int *tree, int index) {
    if(!tree) return;
    
    scanf("%d", &tree[index]);
    if(tree[index] == -1) return ;
    createtree(tree, index*2);
    createtree(tree, index*2+1);
}

void printtree(int *tree, int index) {
    if(!tree) return;
    if(tree[index] == -1) return;

    printtree(tree, index*2);
    printtree(tree, index*2+1);

    printf("%d ", tree[index]);
}



void tree() {
    int i;
    scanf("%d", &i);

    if(i== -1) return;
    tree();
    tree();

    printf("%d ", i);

}
