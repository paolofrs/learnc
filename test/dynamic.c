// this is a test code for dynamic allocation memory
//
// Author: Paolo Fresch
// 
// Info:   version 0.0 : 01-nov-2018 (17:41)
//                       file creation
//

// library 
#include<stdio.h>
#include<stdlib.h>

// decaler variables
int i=0; 
int j=0;
int nraw = 2;
int ncol = 3;

int main () {

    // inform the user the program is running
    printf("################\n here we go...\n############### \n ");

    // create the matrix of values
    int ** matrix;                                           // create the pointer to matrix (master pointer)
    matrix = (int **) malloc(nraw * sizeof(int *));         // allocate the space for array pointers
    for (i=0; i<nraw; i++) {
        *(matrix+i) = (int *) malloc(ncol * sizeof(int));    // allocate the space for each array (raw of the matrix)
    }

    // fill the matrix with data
    for (i=0; i<nraw; i++) {
        for (j=0; j<ncol; j++) { 
            *(*(matrix+i)+j) = j;
            // DEBUG
            //printf("%d",j);
            //printf("%x",*(*(matrix+i)+j));
        }
    }

    // pritn the matrix
    printf("\n\nThis is the result:\n");
    for (i=0; i<nraw; i++) {
        printf("    line %d - ", i);
        for (j=0; j<ncol; j++) {
            printf(" %d", *(*(matrix+i)+j));
        }
        printf("\n");
    }
    printf("\n\n");

    // now, take advantages of the dynamic thing...
    // add one line
    *(matrix+nraw) = (int *) malloc(ncol * sizeof(int));

    // fill it 
    for (j=0; j<ncol; j++) {
        *(*(matrix+nraw)+j) = j;
    }
    
    // re print the matrix (with one more line)
    printf("\n\nThis is the result:\n");
    for (i=0; i<=nraw; i++) {
        printf("    line %d - ", i);
        for (j=0; j<ncol; j++) {
            printf(" %d", *(*(matrix+i)+j));
        }
        printf("\n");
    }
    printf("\n\n");

    // free some portion of the memory (last 2 raw)
    for (i=2; i<=nraw; i++) {
        free(*(matrix+i));
    }    

    // free the memory
    for (i=0; i<nraw; i++) {    
        free(*(matrix+i));                    // free the arrays
    }
    free(matrix);                             // free the pointer to array of pointers to integer

return 0;
}

