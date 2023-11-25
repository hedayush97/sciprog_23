#include<stdio.h>
#include<stdlib.h>

// Define a structure for a cell in a linked list
struct cell {
    int content;
    struct cell *next;
};

// Function to create a new cell with the given content
struct cell *newcell(int n) {
    // Allocate a new cell in memory, fill its content, and set next to NULL
    struct cell *newCell = (struct cell*)malloc(sizeof(struct cell));
    if (newCell == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    newCell->content = n;
    newCell->next = NULL;

    return newCell;
}

// Function to push a new cell with the given content to the front of the list
struct cell *push(struct cell *list, int n) {
    // Insert a new cell at the front of the list with the given content
    struct cell *newCell = newcell(n);
    newCell->next = list;
    return newCell;
}

// Function to count the number of cells in the list
int countcells(struct cell *list) {
    int count = 0;
    while (list != NULL) {
        count++;
        list = list->next;
    }
    return count;
}

// Function to print the content of the cells in the order they're stored
void printlist(struct cell *list) {
    while (list != NULL) {
        printf("%d ", list->content);
        list = list->next;
    }
    printf("\n");
}

// Function to pop and deallocate the last cell of the list, returning its content
int pop(struct cell **list) {
    if (*list == NULL) {
        fprintf(stderr, "Error: Attempt to pop from an empty list\n");
        exit(EXIT_FAILURE);
    }

    struct cell *current = *list;
    struct cell *prev = NULL;

    // Traverse to the end of the list
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    int content = current->content;

    if (prev != NULL) {
        // If there is more than one element, update the previous cell's next pointer
        prev->next = NULL;
    } else {
        // If there was only one element, update the list pointer
        *list = NULL;
    }

    free(current);
    return content;
}

// Function to deallocate all linked cells of the list and return the number of cells freed
int deallocatelist(struct cell **list) {
    int count = 0;
    while (*list != NULL) {
        struct cell *temp = *list;
        *list = (*list)->next;
        free(temp);
        count++;
    }
    return count;
}

int main() {
    // Test the functions by allocating cells and printing their content
    struct cell *myList = NULL;

    myList = push(myList, 10);
    myList = push(myList, 28);
    myList = push(myList, 32);
    myList = push(myList, 40);
    myList = push(myList, 26);
    myList = push(myList, 14);

    printf("List: ");
    printlist(myList);

    printf("Number of cells: %d\n", countcells(myList));

    printf("Popped element: %d\n", pop(&myList));

    printf("List after popping: ");
    printlist(myList);

    printf("Deallocated %d cells\n", deallocatelist(&myList));

    return 0;
}
