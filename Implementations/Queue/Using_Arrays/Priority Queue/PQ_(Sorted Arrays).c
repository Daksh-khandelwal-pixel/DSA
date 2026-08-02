#include <stdio.h>
#define MAX 100

int arr[MAX];
int size = 0; // Tracks the number of active elements in the queue

// Inserts a new value while keeping the array sorted
void insertion(int value) {
    // Prevent array overflow
    if(size == MAX) {
        printf("Queue Overflow\n");
        return; 
    }

    int i = size - 1;

    // Shift larger elements one spot to the right to make room
    while(i >= 0 && arr[i] > value) {
        arr[i + 1] = arr[i];
        i--;
    }

    // Drop the new value into the empty spot
    arr[i + 1] = value; 
    size++; // Increase the active element count
}

// Removes and returns the largest element
int deletion() {
    // Prevent array underflow
    if(size == 0) {
        printf("Queue Underflow\n");
        return -1; 
    }

    // Shrink the boundary (--size) to "delete" the max element, then return it
    return arr[--size]; 
}

// Prints only the active elements in the queue
void display() {
    printf("Queue: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]); 
    }
    printf("\n");
}

// A simple main function to test the logic
int main() {
    int n, value;

    // Ask user for the number of elements
    printf("How many elements do you want to insert? ");
    scanf("%d", &n);

    // Read the values and insert them one by one
    printf("Enter %d values:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertion(value);
    }

    printf("\nAfter insertion:\n");
    display(); // Shows the sorted queue

    printf("\nDeleted max value: %d\n", deletion()); // Removes the largest number

    printf("\nAfter deletion:\n");
    display(); // Shows the queue after deletion

    return 0;
}