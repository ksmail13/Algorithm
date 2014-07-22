/*****************************************************
 * depth
 * http://183.106.113.109/30stair/post.php?pname=depth 
 ***************************************************/
#include <stdio.h>

/**
 * get data from standard input
 * and check leaf
 *
 * @param depth : current depth of tree, depth_max : storage for save depth, double_child_cnt : storage for save node that has 2 childs
 * @return is null node
 */
int tree(int depth, int *depth_max, int *double_child_cnt) {
    int temp, left, right;
    scanf("%d", &temp);

    if(temp == -1) return 1;
    left = tree(depth+1, depth_max, double_child_cnt);
    right = tree(depth+1, depth_max, double_child_cnt);

    if(!left && !right) {
        // when node has 2 childs
        (*double_child_cnt)++;
    }
    else if(left && right) {
        // when leaf node
        if(*depth_max < depth) *depth_max = depth;
    }
    return 0;
}

int main()
{
    register int depth=0, double_child_cnt=0;
    tree(1, &depth, &double_child_cnt);

    printf("%d\n%d\n", double_child_cnt, depth);
    return 0;
}
