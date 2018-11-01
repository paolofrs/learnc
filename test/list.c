// this is a test code for use of list (push and pop items)
//
// Author: Paolo Fresch
// 
// Info:   version 0.0 : 01-nov-2018 (20:06)
//                       file creation
//

// library
#include<stdio.h>
#include<stdlib.h>

// variable decalration
// list item
typedef struct node {
    int val;
    struct node * next;
    } node_t;

int main() {
    
    // pointer to list item (initial pointer)
    node_t * head = NULL;

    head = malloc(sizeof(node_t));  // create the first item
    
    // put something inside the item
    head->val = 1;
    (*head).next = NULL;  // head-> or *(head). means the same!!

    // add an element at the end
    node_t * new;
    new = malloc(sizeof(node_t));
    head->next = new; 
    (*new).val = 2;
    (*new).next = NULL;


    // shows results
    printf("################\n here we go...\n############### \n ");
    printf("\n    value in the head: %d", head->val); 
    printf("\n    value in the new: %d", new->val);
    printf("\n\n");


}
