#include <stdio.h>
#include <stdlib.h>

#include "ADT_stack.h"

STACK*
create_stack(){
	STACK* stack = (STACK*)malloc(sizeof(STACK));
	stack->count = 0;
	stack->top = NULL;
	return stack;
}

bool
push(STACK* stack,void* in){
	STACK_NODE* new_node = (STACK_NODE*)malloc(sizeof(STACK_NODE));
	new_node->data_ptr = in;
	new_node->link = stack->top;
	stack->top = new_node;
	(stack->count)++;
	return true;
}

void*
pop(STACK* stack){
	if(stack->count == 0)
		return NULL;
	else{
		STACK_NODE* temp = stack->top;
		void* data_out = stack->top->data_ptr;
		stack->top = stack->top->link;
		free(temp);
		(stack->count)--;
		return data_out;
	}
}


void fill_space(int size){
    for(int i=0; i<size;i++){
    printf(" ");
    }
}
