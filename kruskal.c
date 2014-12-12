#include <stdio.h>
#define LIMIT 100

struct vertex{
    int point[2];
    int weight;
}

struct b_tree{
    struct vertex *data[LIMIT];
    int size;
};

struct pset {
    int set[100];
    int cnt;
};

void ins_heap_overlap(struct b_tree *tree, struct vertex *data) {
    int i=1;
    while(tree->data[i] != NULL) {
        if(tree->data[i].weight >= data.weight) {
            i=<<1;
        }
        else {
            i=<<1;
            i++;
        }
    }

    tree->data[i] = data;
    tree->size++;
}

int main()
{
    int i;
    struct b_tree heap;
    struct pset set;
    memset(&heap, 0, sizeof(struct b_tree));
    memset(&set, 0, sizeof(struct set));

    int p1[] = {1,1,2,2,6,2,6,7,7,3,3,5};
    int p2[] = {2,6,6,7,7,3,5,5,3,5,4,4};
    int pw[] = {6,3,5,3,6,7,4,6,5,3,2,3};

    for(i=0;i<12;i++) {
        struct vertex *v = (struct vertex *) malloc(sizeof(struct vertex));
        v->point[0] = p1[i];
        v->point[1] = p2[i];
        v->weight = pw[i];
        ins_heap_overlap(&heap, v);
    }
    i=1
    while(heap.size>0) {
        while(heap.data[i<<1] != NULL) {
            i=<<1;
        }
        struct vertex* curr = heap.data[i];
        if(set.set[curr->point[0]] != set.set[curr->point[1]]) {
            set.cnt++;
            int p0=-1, p1=-1;
            if(set.set[curr->point[0]] != 0) {
                p0 = set.set[curr->point[0]];
            }
            if(set.set[curr->point[1]] != 0) {
                p1 = set.set[curr->point[1]];
            }
            set.set[curr->point[0]] = set.cnt;
            set.set[curr->point[1]] = set.cnt;
            
            
        }
        free(curr);
    }

    return 0;
}


