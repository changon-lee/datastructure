#include "ADT_llist.h"
#include "ADT_graph.h"

// utility function
int compare_vertex(void* x, void* y){
    VERTEX* left = (VERTEX*)x;
    VERTEX* right = (VERTEX*)y;

    return left->data - right->data;
}

void print_vertex(void* x)
{
    VERTEX* vertex = (VERTEX*)x;
    printf(" - vertex: %c\n", (char)(vertex->data));
}

int compare_arc(void* x, void* y){
    ARC* left = (ARC*)x;
    ARC* right = (ARC*)y;


    return compare_vertex(left->to_vertex, right->to_vertex);
}

void print_arc(void* x)
{
    ARC* arc = (ARC*)x;

    printf("         -> : %c\n", (arc->to_vertex->data));
}

GRAPH* create_graph(){
    GRAPH* graph = (GRAPH*)malloc(sizeof(GRAPH));
    graph->vertex_list = create_list(compare_vertex, print_vertex);
    return graph;
}

bool g_insert_vertex(GRAPH* graph, int data){
    // create new vertex;
    VERTEX* new_vertex = (VERTEX*)malloc(sizeof(VERTEX));
    new_vertex->data = data;
    new_vertex->arc_list = create_list(compare_arc, print_arc);
    
    // insertion duplicated vertex is not allowed
    int vertex_loc = find_data(graph->vertex_list, new_vertex);
    if(vertex_loc != -1){
        return false;
    }    
    // insert vertex into list
    return add_node_at(graph->vertex_list, graph->vertex_list->count, new_vertex);
}

bool g_delete_vertex(GRAPH* graph, int data){
    bool success;
    // create node
    NODE* node = (NODE*)malloc(sizeof(NODE));
    node = graph->vertex_list->front;
    // create vertex
    VERTEX* del_vertex = (VERTEX*)malloc(sizeof(VERTEX));
    del_vertex->data = data;
    del_vertex->arc_list = create_list(compare_arc, print_arc);
    // first, delete vertex
    int vertex_loc = find_data(graph->vertex_list, del_vertex);
    if(vertex_loc != -1){
        success = del_node_at(graph->vertex_list, vertex_loc);
    }
    // second, delete arcs
    // create arc
    ARC* new_arc = (ARC*)malloc(sizeof(ARC));
    new_arc->to_vertex = del_vertex;

    while(node != NULL){
        VERTEX* find_vertex = (VERTEX*)(node->data_ptr);
        int arc_loc = find_data(find_vertex->arc_list, new_arc);
        if(arc_loc != -1){
            // delete arc
            success = del_node_at(find_vertex->arc_list, arc_loc);
        }
       
        node = node->next;
    }
    return success;
}

void print_vertex_all(GRAPH* graph){
    NODE* pos = graph->vertex_list->front;
    while(pos != NULL){
        (*graph->vertex_list->print_func)(pos->data_ptr);
        pos = pos->next;
    }
}

bool g_insert_arc(GRAPH* graph, int from, int to){
    //search from_vertex
    VERTEX tmp_vertex1;
    tmp_vertex1.data = from;
    tmp_vertex1.arc_list = NULL;

    int vertex_loc = find_data(graph->vertex_list, &tmp_vertex1);
    if(vertex_loc == -1){
        printf("from_vertex %c: not found\n", (char)from);
        return false;
    }    

    //get a vertex with from data
    VERTEX* from_vertex = (VERTEX*)get_data_at(graph->vertex_list, vertex_loc);

    VERTEX tmp_vertex2;
    tmp_vertex2.data = to;
    tmp_vertex2.arc_list = NULL;

    vertex_loc = find_data(graph->vertex_list, &tmp_vertex2);
    if(vertex_loc == -1){
        printf("to_vertex %c: not found\n", (char)to);
        return false; // nothing found
    }    

    //get a vertex with from data
    VERTEX* to_vertex = (VERTEX*)get_data_at(graph->vertex_list, vertex_loc);

    //create destination
    ARC* new_arc = (ARC*)malloc(sizeof(ARC));
    new_arc->to_vertex = to_vertex;
    
    //insert vertex into list
    return add_node_at(from_vertex->arc_list, from_vertex->arc_list->count, new_arc);

}

void print_arc_all(GRAPH* graph){
     
     NODE* vertex_pos = graph->vertex_list->front;

     while(vertex_pos != NULL){
        VERTEX* vertex_pos_vertex = (VERTEX*)(vertex_pos->data_ptr);
        NODE* arc_pos = vertex_pos_vertex->arc_list->front;
        printf("Vertex : %c\n", (char*)vertex_pos_vertex->data);
        
        while(arc_pos != NULL){
            (*vertex_pos_vertex->arc_list->print_func)(arc_pos->data_ptr);
            arc_pos = arc_pos->next;
        }
        vertex_pos = vertex_pos->next;
       
    }
    
}

