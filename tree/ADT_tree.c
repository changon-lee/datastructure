#include "ADT_tree.h"

BST_TREE* create_bst_tree() {
    BST_TREE* tree = (BST_TREE*)malloc(sizeof(BST_TREE));
    tree->count = 0;
    tree->root = NULL;
    return tree;
    }

T_NODE* find_smallest_node(T_NODE* root){
    if(root->left == NULL)
        return root;
    else
        return find_smallest_node(root->left);
}        

T_NODE* find_largest_node(T_NODE* root){
    if(root->right == NULL)
        return root;
    else
        return find_largest_node(root->right);
}

T_NODE* search_bst(T_NODE* root, int key){
    if(root == NULL)
        return NULL;
    //if key is smaller than data    
    if(key<(root->data))
        return search_bst(root->left, key);
    //if key is larger than data    
    else if(key>(root->data))
        return search_bst(root->right, key);
    else
        return root;
}

T_NODE* add_bst(T_NODE* root, int data){
    if(root == NULL){
        T_NODE* newPtr = (T_NODE*)malloc(sizeof(T_NODE));
        newPtr->right = NULL;
        newPtr->left = NULL;
        newPtr->data = data;
        return newPtr;
    }
    // if data is samaller than root's data
    if(data<root->data){
        root->left = add_bst(root->left, data);
    // if data is greater than or same as root's data    
    } else{
        root->right = add_bst(root->right, data);
        
    }
    return root;
}
    

T_NODE* delete_bst(T_NODE* root, int data, bool* success) {
    if(root == NULL)
        *success = false;
    //if data is smaller than root's data    
    if(data < root->data)
        root->left = delete_bst(root->left, data, success);
    //if data is greater than root's data    
    else if(data > root->data)
        root->right = delete_bst(root->right, data, success);
    //if data is same as root's data   
    else{
        //node with only one child or no child
        if(root->left == NULL)
        {
            T_NODE* delPtr = root->right;
            free(root);
            *success = true;
            return delPtr;
        }
        else if(root->right == NULL)
        {
            T_NODE* delPtr = root->left;
            free(root);
            *success = true;
            return delPtr;
        }
        //node with two children
        T_NODE* delPtr = find_largest_node(root->left);
        //change data
        root->data = delPtr->data;
        //delete changed data
        root->left = delete_bst(root->left, delPtr->data, success);
    }
    return root;
}

bool BST_insert(BST_TREE* tree, int data){
    T_NODE* newRoot;
    newRoot = add_bst(tree->root,data);
    if(newRoot == NULL) return false;
    else{
        tree->root = newRoot;
        (tree->count)++;
        return true;
    }
}
                    

void traverse_preorder(T_NODE* root){
    if(root){
        printf("%d,", root->data);
        traverse_preorder(root->left);
        traverse_preorder(root->right);
    }    
}

void traverse_postorder(T_NODE* root){
    if(root){
        traverse_postorder(root->left);
        traverse_postorder(root->right);
        printf("%d,", root->data);
    }    
}

void traverse_inorder(T_NODE* root){
    if(root){
        traverse_inorder(root->left);
        printf("%d,", root->data);
        traverse_inorder(root->right);
    }
}

bool BST_delete(BST_TREE* tree, int data){
    bool success;
    T_NODE* newRoot;

    newRoot = delete_bst(tree->root, data, &success);
    if(success){
        tree->root = newRoot;
        (tree->count)--;
        if(tree->count == 0)
            tree->root = NULL;
    }
    return true;
}

void BST_print (BST_TREE* tree, int method) {
    printf("BST_TREE:\n");
    printf(" size : %d\n", tree->count);
    printf(" data : ");

    if(method == 0)
        traverse_preorder(tree->root);
    else if(method == 1)
        traverse_inorder(tree->root);
    else if(method == 2)
        traverse_postorder(tree->root);
    else
        printf("type error");

    printf("\n");
}    
