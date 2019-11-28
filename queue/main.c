// ADT QUEUE
#include <stdio.h>
#include "ADT_queue.h"

typedef struct student{
    int id;
    int score;
} STD;

#define STD_N 20

int main() {
    
    int i;
    STD* std_ptr;

    //Creationi
    QUEUE* queue;
    queue = create_queue();

    //Memory Allocation
    STD* c[STD_N];
    for(i=0; i<STD_N; i++)
        c[i] = (STD*)malloc(sizeof(STD));


    //data
    for(i=0; i<STD_N; i++){
        c[i]->id    = i;
        c[i]->score = i;
    }

    //Data Insertion
    for(i=0; i<STD_N; i++){
        if(enqueue(queue,&(c[i]->id)))
            printf("Enqueue: %d\n", c[i]->id);
        else {
            printf("Enqueue failed\n");
            return -1;
        }
   

    }
    
    while(queue->count != 0){
        std_ptr = (STD*)malloc(sizeof(STD)); 
        std_ptr->id = *(int*)dequeue(queue);
        printf("Dequeue: %d\n", std_ptr->id);
    }

    for(i=0;i<STD_N;i++){

        if(enqueue(queue, &(c[i]->id)))
            printf("Enqueue: %d\n", c[i]->id);
        else{
            printf("Enqueue failed\n");
            return -1;
        }
    }

    //Destroy all queue
    destroy_queue(queue);

    return 0;

}


