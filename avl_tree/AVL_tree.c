#include "AVL_tree.h"

AVL_TREE* create_avl_tree() {
    AVL_TREE* tree = (AVL_TREE*)malloc(sizeof(AVL_TREE));
    tree->count = 0;
    tree->root = NULL;
    return tree;
}

T_NODE* find_largest_node(T_NODE* root){
    if(root->right == NULL)
        return root;
    else
        return find_largest_node(root->right);
}

T_NODE* rotate_left(T_NODE* root){
    T_NODE* new_root;
    // assign right of root to a new root
    new_root = root->right;    
    root->right = new_root->left;
    new_root->left = root;
    return new_root;
}    

T_NODE* rotate_right(T_NODE* root){
    T_NODE* new_root;
    // assign left of root to a new root
    new_root = root->left;
    root->left = new_root->right;
    new_root->right = root;
    return new_root;
}    

T_NODE* insert_rotate(T_NODE* root, T_NODE* new_node, bool* taller){
    if(root == NULL) // reach at leap node, ready to insert
    {
        root = new_node;
        *taller = true;
        return root;
    } 
    if((new_node->data)<(root->data)){
        // do insertion into left tree
        root->left = insert_rotate(root->left, new_node, taller);
        if(*taller){
            switch(root->balance){
                //Left of Left or right of left
                case LH: root=balance_left(root,taller);
                         break;
                case EH: root->balance = LH; break;
                case RH: root->balance = EH; 
                         *taller = false; break;
                }
        }
        return root;
        
    }else{
        //do insertion into right tree
        root->right = insert_rotate(root->right, new_node, taller);
        if(*taller){
            switch(root->balance){
                // left of right or right of left
                case LH: root->balance = EH;
                         *taller = false;
                         break;
                case EH: root->balance = RH; break;
                case RH: root = balance_right(root, taller); break;
                }
        }
        return root;
    }
    return root;
}  

T_NODE* delete_avl(T_NODE* root, int data, bool* success) {
    if(root == NULL)
        *success = false;
    //if data is smaller than root's data
    if(data < root->data)
        root->left = delete_avl(root->left, data, success);
    //if data is greater than root's data
    else if(data > root->data)
        root->right = delete_avl(root->right, data, success);
    //if data is same as root's data
    else{
        //node with only one child or no child
        if(root->left == NULL)
        {
            T_NODE* new_node = root->right;
            free(root);
            *success = true;
            return new_node;
        }
        else if(root->right == NULL)
        {
            T_NODE* new_node = root->left;
            free(root);
            *success = true;
            return new_node;
        }
        //node with two children
        T_NODE* new_node = find_largest_node(root->left);
        //change data
        root->data = new_node->data;
        root->left = delete_avl(root->left, new_node->data, success);
        }
    return root;
}    


T_NODE* balance_left(T_NODE* root, bool* taller){
    T_NODE* right_tree;
    T_NODE* left_tree;

    left_tree = root->left;
    switch(left_tree -> balance){
        //left of left
        case LH:
            root->balance = EH;
            left_tree->balance = EH;
            root = rotate_right(root);
            *taller = false;
            break;
        case EH:
            exit(0);
        //right of left    
        case RH: 
            right_tree = left_tree->right;
            switch(right_tree->balance){
            case LH:
                root->balance = RH;
                left_tree->balance = EH;
                break;
            case EH:
                root->balance = EH;
                left_tree->balance = EH;
                break;
            case RH:
                root->balance = EH;
                left_tree->balance = LH;
                break;
            }
            right_tree->balance = EH;
            root->left = rotate_left(left_tree);
            root       = rotate_right(root);
            *taller = false;
       }     
    return root;
}  

           
T_NODE* balance_right(T_NODE* root, bool* taller){
    T_NODE* right_tree;
    T_NODE* left_tree;

    right_tree = root->right;
    switch(right_tree -> balance){
        //right of right
        case RH:
            root->balance = EH;
            right_tree->balance = EH;
            root = rotate_left(root);
            *taller = false;
            break;
        case EH:
            exit(0);
        //left of right
        case LH:
            left_tree = right_tree->left;
            switch(left_tree->balance){
            case LH:
                root->balance = EH;
                right_tree->balance = RH;
                break;
            case EH:
                root->balance = EH;
                right_tree->balance = EH;
                break;
            case RH:
                root->balance = LH;
                right_tree->balance = EH;
                break;
            }    
            left_tree->balance = EH;
            root->right = rotate_right(right_tree);
            root        = rotate_left(root);
            *taller = false;
        }
    return root;

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

bool AVL_insert(AVL_TREE* tree, int data){
    T_NODE* new_node;
    bool taller;
    new_node = (T_NODE*)malloc(sizeof(T_NODE));
    if(!new_node) return false;
    new_node->balance = EH;
    new_node->right = NULL;
    new_node->left = NULL;
    new_node->data = data;

    tree->root = insert_rotate(tree->root, new_node, &taller);
    (tree->count)++;
    return true;
}

bool AVL_delete(AVL_TREE* tree, int data){
    bool success;
    T_NODE* newRoot;

    newRoot = delete_avl(tree->root, data, &success);
    if(success){
        tree->root = newRoot;
        (tree->count)--;
        if(tree->count == 0)
            tree->root = NULL;
    }
    return true;
}

bool AVL_format(AVL_TREE* tree){
    if(tree){
        tree->count = 0;
        tree->root = NULL;
    }    
   return true;
}    
    
  
void AVL_print(AVL_TREE* tree, int method) {
    printf("AVL_TREE:\n");
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

