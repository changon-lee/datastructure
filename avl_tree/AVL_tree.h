#ifndef AVL_tree
#define AVL_tree

#define LH +1
#define EH 0
#define RH -1

#include <stdio.h>
#include <stdlib.h>

// AVL Tree Node
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
    int balance;
} T_NODE;    

// AVL Tree

typedef struct{
    int count;
    T_NODE* root;
} AVL_TREE;


// Operations
AVL_TREE*   create_avl_tree();
T_NODE*     find_largest_node   (T_NODE* root);
T_NODE*     rotate_left         (T_NODE* root);
T_NODE*     rotate_right        (T_NODE* root);
T_NODE*     insert_rotate       (T_NODE* root, T_NODE* new_node, bool* taller);
T_NODE*     delete_avl          (T_NODE* root, int data, bool* success);
T_NODE*     balance_left        (T_NODE* root, bool* taller);
T_NODE*     balance_right       (T_NODE* root, bool* taller);

void        traverse_preorder   (T_NODE* root);
void        traverse_inorder    (T_NODE* root);
void        traverse_postorder  (T_NODE* root);

bool        AVL_insert      (AVL_TREE* tree, int data);
bool        AVL_delete      (AVL_TREE* tree, int data);
bool        AVL_format      (AVL_TREE* tree);

void        AVL_print       (AVL_TREE* tree, int method);

#endif


