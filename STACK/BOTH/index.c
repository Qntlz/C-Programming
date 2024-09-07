#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stackadt.h"
#include "stackADT_array.h"
// #include "stackADT_list.h"

/* Switch between array and linked list implementations by commenting out 
   the header file of the unused implementation. Uncomment the header of 
   the desired implementation.
*/

int main() {
    Stack S;

    // Initialize Stack
    initialize(&S);

    // Push
    push(S,'A');
    push(S,'B');
    push(S,'C');
    push(S,'D');
    

    // Display
    printf("Push:\n");
    displayStack(S);
    top(S);

    // Pop
    printf("\nPop:\n");
    pop(S);
    top(S);

    // Free allocated memory
    free(S->data);  // Free the array
    free(S->top);   // Free the list
    free(S);        // Then free the stack structure

    return 0;
}
