// this is a test code for use of list (push and pop items)
//
// Author: Paolo Fresch
// 
// Info:   version 0.0 : 01-nov-2018 (20:06)
//                       file creation
//
//         version 0.1 : 02-nov-2018 (11:46) 
//                       added push and pop functions
//

// library
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// variable decalration
//
// list item
typedef struct node {
    int val;
    struct node * next;
    } node_t;
// others
node_t * line = NULL;
int lin_ctr = 0;


/////////////////////////////////
// function decalaration
/////////////////////////////////
//
// push (add item on top of stack, model FILO)
void push (node_t ** head, int val) {
    node_t * new_node;
    new_node = malloc(sizeof(node_t));            // allocate the new item

    new_node->val = val;                          // insert the value in the new item
    new_node->next = *head;                       // assign the value pointed by head to next (next point to the former head)
    *head = new_node;                             // update the head with new_node address
}
// pop (remove item on top of stack, model FILO) returning the element
int pop(node_t ** head) {
    int retval = -1;
    node_t * next_node = NULL;

    if (*head==NULL) {
        return retval;
    }

    next_node = (*head)->next;                    // assign to next_node the address pointed by the head item
    retval = (*head)->val;                        // assign the value in the item to retval
    
    free(*head);
    *head = next_node;                            // update head pointer

    return retval;                                // return the value in the deleted item
}
// remove item by reference
int remove_by_ref(node_t ** head, int ref) {
    int retval = -1;
    bool last = false;
    bool check = false;
    
    node_t * current = *head;                     // current point to the head of the list
    node_t * prev = NULL;
    
    // check if the first items has the ref
    while ((*head)->val == ref) {
        //if (current->val == ref) {
        *head = current->next;                    // current value assign to head
        retval = current->val;                    // return the value 
        check = true;                             // set flag
        free(current);                            // delete the first item
        current = *head;                          // update current pointer
        //printf("\nfatto0\n");
    }  
    // scroll the list
    while (last != true) {
        prev = current;
        current = current->next;
        //printf("\nfatto1\n");
        if (current->val == ref) {
            prev->next = current->next;           // link previous and next items
            retval = current-> val;               // return the value
            check = true;                         // set flag 
            free(current);                        // free memory
        }
        if (current->next == NULL) {
            last = true;
        }
    }       
    return retval;
    if (check==false) {
        return -2;                                // return error code -1 (no value found)
    }
}

int main() {
    
    // infrom the user
    printf("################\n here we go...\n############### \n ");

    // pointer to list item (initial pointer)
    node_t * head = NULL;

    head = malloc(sizeof(node_t));                // create the first item
    
    // put something inside the item
    head->val = 1;
    (*head).next = NULL;                          // head-> or *(head). means the same!!

    // add an element at the end
    node_t * new;
    new = malloc(sizeof(node_t));
    head->next = new; 
    (*new).val = 2;
    (*new).next = NULL;

    // push elements
    push(&head, 3);
    push(&head, 8);

    // shows intermendite results
    line = head;
    lin_ctr = 0;
    while (line != NULL) {
         printf("\n    value in the item %d: %d", lin_ctr, line->val);
         line = line->next;
         lin_ctr += 1;        
    }
    printf("\n\n");
    
    // pop one element
    int delval = -2;
    delval = pop(&head);
    printf("    deleted val: %d\n", delval);
    
    // show the results after pop
    line = head;
    lin_ctr = 0;
    while (line != NULL) {
         printf("\n    value in the item %d: %d", lin_ctr, line->val);
         line = line->next;
         lin_ctr += 1;        
    }
    printf("\n\n");
    
    // remove a specific item
    delval = remove_by_ref(&head, 2);
    printf("    deleted val: %d\n", delval);
    
    // show the results after remove
    line = head;
    lin_ctr = 0;
    while (line != NULL) {
         printf("\n    value in the item %d: %d", lin_ctr, line->val);
         line = line->next;
         lin_ctr += 1;        
    }
    
    // infrom the user
    printf("\n\n    end! see you...\n\n");


}
