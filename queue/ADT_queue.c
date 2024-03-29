#include "ADT_queue.h"

QUEUE*
create_queue(){
	QUEUE* queue;
	queue = (QUEUE*)malloc(sizeof(QUEUE));
	if(queue){ // if queue has address
		queue->front = NULL;
		queue->rear = NULL;
		queue->count = 0;
		return queue;
	}
	else{
		return NULL;
	}
}

bool
enqueue(QUEUE* queue, void* in){
	QUEUE_NODE* new_node;
	new_node = (QUEUE_NODE*)malloc(sizeof(QUEUE_NODE));
	new_node->data_ptr = in;
	new_node->next = NULL;
	if(queue->count == 0){
		queue->front = new_node;
        queue->rear = new_node;
        
     	}
	else{
		queue->rear->next = new_node;
        queue->rear = new_node;
        
	}
    queue->count++;

    if(!queue){
        return false;}

        return true;
}

void* dequeue(QUEUE* queue) {
    if(queue->count == 0) return NULL;
    QUEUE_NODE* deleted_node;
    deleted_node = queue->front;
    void* item_ptr = queue->front->data_ptr;
    if(queue->count == 1) {
        queue->front = NULL;
        queue->rear = NULL;
    }
    else{
        queue->front = queue->front->next;}

    (queue->count)--;
    free(deleted_node);
    return item_ptr;

}

void* queue_hook_front(QUEUE* queue){
    if(queue->count == 0) return NULL;
    else { return queue->front->data_ptr; }

    }

void* queue_hook_rear(QUEUE* queue){
    if(queue->count == 0) return NULL;
    else { return queue->rear->data_ptr;}

    }

void destroy_queue(QUEUE* queue){
    if(queue!=NULL){
        while(queue->count != 0){
            printf("%d-th node is deleted\n", *(int*)queue->front->data_ptr);
            //delete data
            free(queue->front->data_ptr);
            //free node
            dequeue(queue);
                        }
        }
    }  

