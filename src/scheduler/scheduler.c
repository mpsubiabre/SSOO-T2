#include "scheduler.h"


LinkedList* linkedlist_init(int total_factories){
    LinkedList* linkedlist = malloc(sizeof(LinkedList));
    //linkedlist->head = NULL;
    //linkedlist->tail = NULL;
    total_factories = total_factories;
    return linkedlist;
}

void append_linkedlist(LinkedList* linkedlist, Process* process){
    linkedlist->tail->next = process;
    linkedlist->tail = process;    
}

void append_first(LinkedList* linkedlist, Process* process){
    linkedlist->tail->next = process;
    linkedlist->tail = process;
    linkedlist->head = process;
}

void print_linkedlist(LinkedList* linkedlist){
    for (Process* current = linkedlist ->head; current; current=current ->next)
    {
        printf("%s\n", current->name);
    }
}

void destroy_linkedlist(LinkedList* linkedlist)
{
    //liberar los procesos
    if (linkedlist->head)
    {
        Process* curr = linkedlist->head->next;
        Process* prev = linkedlist->head;
        while (curr)
        {
            free(prev);
            prev = curr;
            curr = curr ->next;
        }
        free(prev);
    }
    free(linkedlist);
}
/*Rec0gido de geeksforgeeks para eliminar un nodo de la lista
https://www.geeksforgeeks.org/delete-a-given-node-in-linked-list-under-given-constraints/
*/
void delete_process(LinkedList* linkedlist ,Process* current){
    Process* head = linkedlist->head;
    // es el primer nodo de la lista
    if(head == current)
    {
        if(head->next == NULL)
        {
           //SOLO HAY UN NODO
           //Falta borrarlo
           return; 
        }
        /*Se copia la info del nodo siguiente al head*/
        head->id_factory=head->next->id_factory;
        head->name =head->next->name;
        head->pid=head->next->pid;
        head->quantum=head->next->quantum;
        head->state=head->next->state;
        head->time_start=head->next->time_start;
        //agregar atributos
        /*Se guarda la direccion*/
        current = head->next;
        //Se remueve el link del siguiente nodo
        head->next = head->next->next;
        
        free(current);
        return;
    }
    // No es el primer nodo
    Process* prev = head;
    while (prev->next != NULL && prev->next!=current)
    {
        prev = prev->next;
    }
    if(prev->next == NULL){
        //NO esta presente en la lista
        return;
    }
    prev->next = prev->next->next;
    free(current);
    return;
}
