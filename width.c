#include <stdio.h>
#define DATA 0
#define LEFT 1
#define RIGHT 2
#define LIMIT 10000

int width[LIMIT][2]={};
int width_idx=0;
int q[LIMIT];
int qrear=0;
int search(int tree[LIMIT][3], int depth, int node, int index) {
    if(!tree) return 0;
    if(node== -1) return 0;
    search(tree, depth+1, tree[node][LEFT],index-1);

//    q[qrear][0] = node;
    q[qrear++] = depth;
    if(width_idx < depth) width_idx = depth;
//    printf("depth : %d node : %d index : %d width_idx : %d\n",depth, node, index, width_idx);
    search(tree, depth+1, tree[node][RIGHT], index+1);
    return index;
}

int main() {
    int tree[LIMIT][3] = {};
    int i,j, node_cnt;
    int index, max_width=0;
    scanf("%d", &node_cnt);
    for(i=0;i<node_cnt;i++) {
        scanf("%d %d %d", &tree[i+1][DATA], &tree[i+1][LEFT], &tree[i+1][RIGHT]);
    }

    search(tree, 1, 1, 0); 
    for(i=0;i<LIMIT;i++){
        width[i][0] = -1;
    }

    for(i=0;i<qrear;i++) {
//        printf("width[q[i]][0] : %d width[q[i]][1] : %d q[i]:%d i:%d\n", width[q[i]][0], width[q[i]][1], q[i], i);
        if(width[q[i]][0] == -1)
            width[q[i]][0] = i;
        else
            width[q[i]][1] = i;
    }

    for(i=1;i<width_idx;i++) {
        int temp;
        if(width[i][1] != 0)
            temp = width[i][1]-width[i][0]+1;
        else
            temp = 1;
        printf("temp : %d - %d = %d i : %d\n", width[i][1], width[i][0], temp, i);
        if(temp > max_width) {
            index = i;
            max_width = temp;
//            printf("index : %d max_width : %d\n", index, max_width);
        }
    }

    printf("%d %d\n", index, max_width);
    return 0;
}
