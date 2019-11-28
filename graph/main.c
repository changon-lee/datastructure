// ADT GRAPH
#include <stdio.h>
#include "ADT_llist.h"
#include "ADT_graph.h"

int main(){
    
    int i;
    
    GRAPH* graph = create_graph();

    int vertex[6] = {'A', 'B', 'C', 'D', 'E', 'F'};


    // vertex insertion test
    for(i=0; i<6; i++){
        if(!g_insert_vertex(graph, vertex[i]))
            printf("graph vertex insertion failed: %c\n", (char)vertex[i]);
        else
            printf("graph vertex insertion ok: %c\n", (char)vertex[i]);
    }

    if(!g_insert_vertex(graph, 'C'))
        printf("graph vertex insertion failed: %c already exist\n", 'C');
    else
        printf("graph vertex insertion ok: %c\n", 'C');
    

    printf("\nGraph's Vertex:\n");
    print_vertex_all(graph);
    printf("\n");

    // vertex delete test
    if(!g_delete_vertex(graph, 'B'))
        printf("graph vertex delete failed: %c\n", 'B');
    else
        printf("graph vertex delete ok: %c\n", 'B');
    

    printf("\nGraph's Vertex:\n");
    print_vertex_all(graph);
    printf("\n");

    // arc insertion test
    if(!g_insert_arc(graph, 'A', 'B'))
        printf("graph arc insertion failed: %c - >%c\n", 'A', 'B');
    else
        printf("graph arc insertion ok: %c -> %c\n", 'A', 'B');

    if(!g_insert_vertex(graph, 'B'))
        printf("graph vertex insertion failed: %c already exist\n", 'B');
    else
        printf("graph vertex insertion ok: %c\n", 'B');

    // retry arc insertion    
    if(!g_insert_arc(graph, 'A', 'B'))
        printf("graph arc insertion failed: %c - >%c\n", 'A', 'B');
    else
        printf("graph arc insertion ok: %c -> %c\n", 'A', 'B');

    if(!g_insert_arc(graph, 'B', 'A'))
        printf("graph arc insertion failed: %c - >%c\n", 'B', 'A');
    else
        printf("graph arc insertion ok: %c -> %c\n", 'B', 'A');
    
    if(!g_insert_arc(graph, 'B', 'E'))
        printf("graph arc insertion failed: %c - >%c\n", 'B', 'E');
    else
        printf("graph arc insertion ok: %c -> %c\n", 'B', 'E');

    if(!g_insert_arc(graph, 'E', 'B'))
        printf("graph arc insertion failed: %c - >%c\n", 'E', 'B');
    else
        printf("graph arc insertion ok: %c -> %c\n", 'E', 'B');
    

    if(!g_insert_arc(graph, 'B', 'C'))
        printf("graph arc insertion failed: %c - >%c\n", 'B', 'C');
    else
        printf("graph arc insertion ok: %c -> %c\n", 'B', 'C');

    if(!g_insert_arc(graph, 'C', 'B'))
        printf("graph arc insertion failed: %c - >%c\n", 'C', 'B');
    else
        printf("graph arc insertion ok: %c -> %c\n", 'C', 'B');
    

    if(!g_insert_arc(graph, 'C', 'D'))
        printf("graph arc insertion failed: %c - >%c\n", 'C', 'D');
    else
        printf("graph arc insertion ok: %c -> %c\n", 'C', 'D');

    if(!g_insert_arc(graph, 'D', 'C'))
        printf("graph arc insertion failed: %c - >%c\n", 'D', 'C');
    else
        printf("graph arc insertion ok: %c -> %c\n", 'D', 'C');
    

    if(!g_insert_arc(graph, 'C', 'E'))
        printf("graph arc insertion failed: %c - >%c\n", 'C', 'E');
    else
        printf("graph arc insertion ok: %c -> %c\n", 'C', 'E');
    
    if(!g_insert_arc(graph, 'E', 'C'))
        printf("graph arc insertion failed: %c - >%c\n", 'E', 'C');
    else
        printf("graph arc insertion ok: %c -> %c\n", 'E', 'C');


    if(!g_insert_arc(graph, 'D', 'E'))
        printf("graph arc insertion failed: %c - >%c\n", 'D', 'E');
    else
        printf("graph arc insertion ok: %c -> %c\n", 'D', 'E');
       
    if(!g_insert_arc(graph, 'E', 'D'))
        printf("graph arc insertion failed: %c - >%c\n", 'E', 'D');
    else
        printf("graph arc insertion ok: %c -> %c\n", 'E', 'D');
   

    if(!g_insert_arc(graph, 'E', 'F'))
        printf("graph arc insertion failed: %c - >%c\n", 'E', 'F');
    else
        printf("graph arc insertion ok: %c -> %c\n", 'E', 'F');
       
    if(!g_insert_arc(graph, 'F', 'E'))
        printf("graph arc insertion failed: %c - >%c\n", 'F', 'E');
    else
        printf("graph arc insertion ok: %c -> %c\n", 'F', 'E');
     
    printf("\nGraph's Arc:\n");
    print_arc_all(graph);
    printf("\n");

    // vertex delete test
    if(!g_delete_vertex(graph, 'B'))
        printf("graph vertex delete failed: %c\n", 'B');
    else
        printf("graph vertex delete ok: %c\n", 'B'); 
   

    printf("\nGraph's Arc:\n");
    print_arc_all(graph);
    printf("\n");

    // vertex delete test
    if(!g_delete_vertex(graph, 'D'))
        printf("graph vertex delete failed: %c\n", 'D');
    else
        printf("graph vertex delete ok: %c\n", 'D'); 
   

    printf("\nGraph's Arc:\n");
    print_arc_all(graph);
    printf("\n");

    // vertex delete test
    if(!g_delete_vertex(graph, 'E'))
        printf("graph vertex delete failed: %c\n", 'E');
    else
        printf("graph vertex delete ok: %c\n", 'E'); 
     
    printf("\nGraph's Arc:\n");
    print_arc_all(graph);
    printf("\n");


 

        


}
        



