//AVL TREE
#include <stdio.h>
#include "AVL_tree.h"

#define PRE_ORDER   0
#define IN_ORDER    1
#define POST_ORDER  2

int main(){

    //Create
    AVL_TREE* tree = create_avl_tree();

    // Left of Left 
    if(!AVL_insert(tree, 5))
        printf("tree insertion error\n");
    if(!AVL_insert(tree, 4))
        printf("tree insertion error\n");
    if(!AVL_insert(tree, 3))
        printf("tree insertion error\n");
    
    printf(" Left of Left\n");
    AVL_print(tree, IN_ORDER);
    printf("\n");
   

    // Delete
    if(!AVL_delete(tree, 5))
        printf("failed on deleting 5\n");
	if(!AVL_delete(tree, 4))
        printf("failed on deleting 4\n");
	if(!AVL_delete(tree, 3))
        printf("failed on deleting 3\n");
    
    printf(" After Deletion\n");
    AVL_print(tree, IN_ORDER);
    printf("\n");
  
        
    // Right of Right 
    if(!AVL_insert(tree, 3))
        printf("tree insertion error\n");
    if(!AVL_insert(tree, 4))
        printf("tree insertion error\n");
    if(!AVL_insert(tree, 5))
        printf("tree insertion error\n");

   
    printf(" Right of Right\n");
    AVL_print(tree, IN_ORDER);
    printf("\n");
   
    // Format tree
    AVL_format(tree);

    // Right of Left (Case : LH) 
    if(!AVL_insert(tree, 10))
        printf("tree insertion error\n");
    if(!AVL_insert(tree, 5))
        printf("tree insertion error\n");
    if(!AVL_insert(tree, 15))
        printf("tree insertion error\n");
    if(!AVL_insert(tree, 3))
        printf("tree insertion error\n");
    if(!AVL_insert(tree, 8))
        printf("tree insertion error\n");
    if(!AVL_insert(tree, 7))
        printf("tree insertion error\n");
    
    printf(" Right of Left (Case : LH) \n");
    AVL_print(tree, IN_ORDER);
    printf("\n");

    // Format tree
    AVL_format(tree);

    // Right of Left (Case : EH) 
    if(!AVL_insert(tree, 10))
        printf("tree insertion error\n");
    if(!AVL_insert(tree, 5))
        printf("tree insertion error\n");
    if(!AVL_insert(tree, 7))
        printf("tree insertion error\n");
        
    printf(" Right of Left (Case : EH) \n");
    AVL_print(tree, IN_ORDER);
    printf("\n");

    // Format tree
    AVL_format(tree);

    // Right of Left (Case : RH) 
    if(!AVL_insert(tree, 10))
        printf("tree insertion error\n");
    if(!AVL_insert(tree, 5))
        printf("tree insertion error\n");
    if(!AVL_insert(tree, 15))
        printf("tree insertion error\n");
    if(!AVL_insert(tree, 3))
        printf("tree insertion error\n");
    if(!AVL_insert(tree, 8))
        printf("tree insertion error\n");
    if(!AVL_insert(tree, 9))
        printf("tree insertion error\n");
    
    printf(" Right of Left (Case : RH) \n");
    AVL_print(tree, IN_ORDER);
    printf("\n");

    // Format tree
    AVL_format(tree);

    // Left of Right (Case : RH) 
    if(!AVL_insert(tree, 10))
        printf("tree insertion error\n");
    if(!AVL_insert(tree, 5))
        printf("tree insertion error\n");
    if(!AVL_insert(tree, 15))
        printf("tree insertion error\n");
    if(!AVL_insert(tree, 13))
        printf("tree insertion error\n");
    if(!AVL_insert(tree, 20))
        printf("tree insertion error\n");
    if(!AVL_insert(tree, 14))
        printf("tree insertion error\n");
    
    printf(" Left of Right (Case : RH) \n");
    AVL_print(tree, IN_ORDER);
    printf("\n");

    // Format tree
    AVL_format(tree);


    // Left of Right (Case : EH) 
    if(!AVL_insert(tree, 10))
        printf("tree insertion error\n");
    if(!AVL_insert(tree, 15))
        printf("tree insertion error\n");
    if(!AVL_insert(tree, 5))
        printf("tree insertion error\n");

    printf(" Left of Right (Case : EH) \n");
    AVL_print(tree, IN_ORDER);
    printf("\n");

    // Format tree
    AVL_format(tree);

    // Left of Right (Case : LH) 
    if(!AVL_insert(tree, 10))
        printf("tree insertion error\n");
    if(!AVL_insert(tree, 5))
        printf("tree insertion error\n");
    if(!AVL_insert(tree, 15))
        printf("tree insertion error\n");
    if(!AVL_insert(tree, 13))
        printf("tree insertion error\n");
    if(!AVL_insert(tree, 20))
        printf("tree insertion error\n");
    if(!AVL_insert(tree, 12))
        printf("tree insertion error\n");
    
    printf(" Left of Right (Case : LH) \n");
    AVL_print(tree, IN_ORDER);
    printf("\n");

    // Format tree
    AVL_format(tree);

    int data[2000];
    for(int i=0; i<2000; i++){
        data[i] = rand() % 10000;
    }

    for(int i=0; i<2000; i++){
        if(!AVL_insert(tree, data[i]))
            printf("tree insertion error\n");
    }        
    AVL_print(tree, IN_ORDER);    

        

         
}   


