#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define TRUE 1
#define FALSE 0

// ----------------------------------------- data prototype ---------------------------------------------

typedef int datatype;
/*typedef struct _sdata {
 void *data;                // save every data
 int type;                  // remember data type;
 } Data;
 
 
 // create data
 struct data *data_init(datatype data);
 // get data from structure
 datatype *data_data(const struct data *data);
 // del data
 void data_free(struct data *data);
 // print data
 void data_print(const struct data *data);*/
// ----------------------------------------- data prototype ---------------------------------------------

// ----------------------------------------- btree node prototype ---------------------------------------------
typedef struct binarytree_node {
    //struct data *data;
    int data;
    struct binarytree_node *l_child;
    struct binarytree_node *r_child;
    struct binarytree_node *parent;
}BinaryTreeNode;

#define IS_LEAF(node) ((node)->l_child == NULL && (node)->r_child == NULL)

// create node
struct binarytree_node *bnode_init(datatype data);
// delete node
void bnode_free(struct binarytree_node *node);
// add child
int bnode_add_child(struct binarytree_node *parent, struct binarytree_node *child);
// print node
void bnode_print(struct binarytree_node *node);
// ----------------------------------------- btree node prototype ---------------------------------------------

// ----------------------------------------- btree prototype ---------------------------------------------
typedef struct bst {
    struct binarytree_node *head;
}BinarySearchTree;

typedef void(*Job)(struct binarytree_node *node);

struct bst *bst_init();
void bst_free(struct bst *tree);
int bst_add_node(struct bst *tree, datatype data);
int bst_del_node(struct bst *tree, datatype data);
struct binarytree_node *bst_search(struct bst *tree, datatype data);

void binarytree_inorder(struct binarytree_node *node, Job job);
void binarytree_preorder(struct binarytree_node *node, Job job);
void binarytree_postorder(struct binarytree_node *node, Job job);
void binarytree_levelorder(struct binarytree_node *node, Job job);
// ----------------------------------------- btree prototype ---------------------------------------------

using namespace std;
// ----------------------------------------- main start ---------------------------------------------
int main(int argc, char *argv[]) {
    const int SIZE = 10;
    int i = 0;
    struct bst *t = bst_init();
    
    cout << "input : ";
    for (; i<SIZE; i++) {
        int data = rand() % SIZE;
        cout << data << " ";
        bst_add_node(t, data);
    }
    cout << endl;
    
    cout << "inorder : ";
    binarytree_inorder(t->head, bnode_print);
    
    cout << endl << "preorder : ";
    binarytree_preorder(t->head, bnode_print);
    
    cout << endl << "postorder : ";
    binarytree_postorder(t->head, bnode_print);
    
    cout << endl << "level order : ";
    binarytree_levelorder(t->head, bnode_print);
    
    while(t->head) {
        int temp;
        cout << endl << "delete : ";
        cin >> temp;
        
        bst_del_node(t, temp);
        
        if(t->head) {
            cout << " result(preorder) : ";
            binarytree_preorder(t->head, bnode_print);
        }
    }
    
    bst_free(t);
    return 0;
}
// ----------------------------------------- main end ---------------------------------------------
/*
 // µ•¿Ã≈Õ ª˝º∫
 struct data *data_init(int data) {
 struct data *new_data = (struct data *)calloc(1, sizeof(struct data));
 if (new_data) {
 new_data->data = (datatype *)calloc(1, sizeof(datatype));
 //(*((int*)new_data->data)) = data;
 //        *(new_data->data) = data;
 new_data->type = 0;
 return new_data;
 }
 return NULL;
 }
 
 // µ•¿Ã≈Õ∏¶ ∏Æ≈œ«—¥Ÿ.
 datatype *data_data(const struct data *data) {
 if (data) {
 return (datatype*)data->data;
 }
 return NULL;
 }
 
 // print data
 void data_print(const struct data *data) {
 if (data) {
 printf("type : int data : %d\n", *((int*)data->data));
 }
 }
 
 // µ•¿Ã≈Õ∏¶ «ÿ¡¶«—¥Ÿ.
 void data_free(struct data *data) {
 if (data) {
 free(data->data);
 free(data);
 }
 }
 */
// create node
struct binarytree_node *bnode_init(datatype data) {
    struct binarytree_node *new_node = (struct binarytree_node *)malloc(sizeof(struct binarytree_node));
    
    if (new_node) {
        
        //        new_node->data = data_init(data);
        memset(new_node, 0, sizeof(struct binarytree_node));
        new_node->data = data;
        return new_node;
    }
    else {
        printf("alloctation error\n");
        exit(1);
        return NULL;
    }
}

// delete node from memory
void bnode_free(struct binarytree_node *node) {
    if (node) {
        //        data_free(node->data);
//        cout << node->data << "free!" << endl;
        free(node);
//        cout << "free complete!" << endl;
    }
}

// add child
int bnode_add_child(struct binarytree_node *parent, struct binarytree_node *child, int left) {
    if (parent && child) {
        //        if(!parent->l_child) parent->l_child = child;
        //        else if(!parent->r_child) parent->r_child = child;
        //        else return 0;
        if (left) parent->l_child = child;
        else parent->r_child = child;
        return 1;
    }
    return 0;
}

// print node
void bnode_print(struct binarytree_node *node) {
    if (node) {
        //        data_print(node->data);
        printf("%d ", node->data);
    }
}

// create tree
struct bst *bst_init() {
    struct bst *new_tree = (struct bst *)malloc(sizeof(struct bst));
    if (new_tree) {
        memset(new_tree, 0, sizeof(struct bst));
        return new_tree;
    }
    
    return NULL;
}

void bst_free(struct bst *tree) {
    if (tree) {
        binarytree_postorder(tree->head, bnode_free);
        free(tree);
    }
}

int bst_add_node(struct bst *tree, datatype data) {
    if (tree) {
        struct binarytree_node *curr = tree->head, *temp;
        if (!curr) {
            temp = bnode_init(data);
            tree->head = temp;
            tree->head->parent = NULL;
            return 1;
        }
        while (curr) {
            int currdata = curr->data;
            
            if (data > currdata) {
                if (curr->r_child != NULL) {
                    curr = curr->r_child;
                }
                else {
                    temp = bnode_init(data);
                    curr->r_child = temp;
                    curr->r_child->parent = curr;
                    return 1;
                }
            }
            else if (data < currdata) {
                if (curr->l_child != NULL) {
                    curr = curr->l_child;
                }
                else {
                    temp = bnode_init(data);
                    curr->l_child = temp;
                    curr->l_child->parent = curr;
                    return 1;
                }
            }
            else {
                //printf("exist %d\n", data);
                return 0;
            }
        }
    }
    return 0;
}
// delete leaf node
int bst_del_leaf_node (struct bst *tree, struct binarytree_node *node) {
    if(tree->head == node) {
        bnode_free(node);
        tree->head = NULL;
        return TRUE;
    }
    else if(node) {
        if(node->parent && node->parent->data > node->data) {
            node->parent->l_child = NULL;
        }
        else if(node->parent) {
            node->parent->r_child = NULL;
        }
        
        bnode_free(node);
        return TRUE;
    }
        return FALSE;
}

int bst_move_node(struct binarytree_node *dest, struct binarytree_node *target) {
    if(!dest || !target) return 0;
    
    // connect target's children between target's parent
    if(target->r_child) {
        target->parent->l_child = target->r_child;
        target->r_child->parent = target->parent;
    }
    else {
        if(target->parent->data > target->data)
            target->parent->l_child = NULL;
    }
    
    // connect new parent
    target->parent = dest->parent;
    if(target->parent && target->parent->data > target->data) {
        target->parent->l_child = target;
    }
    else if(target->parent) {
        target->parent->r_child = target;
    }
    
    // connect child
    if(dest->l_child != target)
        target->l_child = dest->l_child;
    else
        target->l_child = NULL;
    if(dest->r_child != target)
        target->r_child = dest->r_child;
    else
        target->r_child = NULL;
    
    return 1;
}

int bst_del_node(struct bst *tree, datatype data) {
    if (tree) {
        struct binarytree_node *del_node = bst_search(tree, data);
        struct binarytree_node *up_node = del_node->r_child;
        struct binarytree_node *parent = del_node->parent;
        
        if(!del_node) return 0;
        // if del_node is leaf then just delete node and disconnect link from parent
        if(IS_LEAF(del_node)) {
            return bst_del_leaf_node(tree, del_node);
        }
        else if(up_node){
            // move up_node to del_node's most lowest bigger data
            while(up_node->l_child) {
                up_node = up_node->l_child;
            }
            
            // up_node move to del_node
            bst_move_node(del_node, up_node);
            
            if(tree->head == del_node)
                tree->head = up_node;

            bnode_free(del_node);
            return 1;
        }
        else {
            up_node = del_node->l_child;
            if(parent && parent->data < del_node->data)
                parent->r_child = up_node;
            else if(del_node->parent)
                parent->l_child = up_node;
                
            if(tree->head == del_node)
                tree->head = up_node;
                
            bnode_free(del_node);
            return 1;
        }
    }
    return 0;
}

struct binarytree_node *bst_search(struct bst *tree, datatype data) {
    if (tree) {
        struct binarytree_node *curr = tree->head, *temp;
        if (!curr) {
            return NULL;
        }
        while (curr) {
            int currdata = curr->data;
            
            if (data > currdata) {
                if (curr->r_child != NULL) {
                    curr = curr->r_child;
                }
                else {
                    return NULL;
                }
            }
            else if (data < currdata) {
                if (curr->l_child != NULL) {
                    curr = curr->l_child;
                }
                else {
                    return NULL;
                }
            }
            else {
                return curr;
            }
        }
    }
    return NULL;
}

void binarytree_inorder(struct binarytree_node *node, Job job) {
    if (node) {
        binarytree_inorder(node->l_child, job);
        job(node);
        binarytree_inorder(node->r_child, job);
    }
}
void binarytree_preorder(struct binarytree_node *node, Job job) {
    if (node) {
        job(node);
        binarytree_preorder(node->l_child, job);
        binarytree_preorder(node->r_child, job);
    }
}
void binarytree_postorder(struct binarytree_node *node, Job job) {
    if (node) {
        binarytree_postorder(node->l_child, job);
        binarytree_postorder(node->r_child, job);
        job(node);
    }
}
void binarytree_levelorder(struct binarytree_node *node, Job job) {
    struct binarytree_node *nodelist[10000] = {};
    int start_idx=-1, end_idx=0;
    if(node) {
        nodelist[end_idx++] = node;
        while(start_idx < end_idx) {
            struct binarytree_node *node = nodelist[++start_idx];
            if(!node) break;
            //cout << endl <<"idx "<< start_idx << " " << end_idx << endl;
            job(node);
            if(node->l_child)
                nodelist[end_idx++] = node->l_child;
            if(node->r_child)
                nodelist[end_idx++] = node->r_child;
        }
    }
}