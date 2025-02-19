#include <stdio.h>

// Function prototypes
void insertInArray(int arr[], int *size, int element, int position);
void deleteFromArray(int arr[], int *size, int position);
void printArray(int arr[], int size);

int main() {
    int arr[100]; // Array with a maximum size of 100
    int size = 0; // Current size of the array
    int choice, element, position;

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Print\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                printf("Enter position: ");
                scanf("%d", &position);
                insertInArray(arr, &size, element, position);
                break;

            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteFromArray(arr, &size, position);
                break;

            case 3:
                printArray(arr, size);
                break;

            case 4:
                printf("Exiting the program.\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

// Insert an element into the array at a specific position
void insertInArray(int arr[], int *size, int element, int position) {
    if (position < 0 || position > *size) {
        printf("Invalid position! Position must be between 0 and %d.\n", *size);
        return;
    }
    if (*size >= 100) {
        printf("Array is full! Cannot insert more elements.\n");
        return;
    }
    // Shift elements to the right to make space for the new element
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    (*size)++;
    printf("Element %d inserted successfully at position %d.\n", element, position);
}

// Delete an element from the array at a specific position
void deleteFromArray(int arr[], int *size, int position) {
    if (position < 0 || position >= *size) {
        printf("Invalid position! Position must be between 0 and %d.\n", *size - 1);
        return;
    }
    if (*size == 0) {
        printf("Array is empty! Nothing to delete.\n");
        return;
    }
    // Shift elements to the left to fill the gap left by the deleted element
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
    printf("Element at position %d deleted successfully.\n", position);
}

// Print the current state of the array
void printArray(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty!\n");
        return;
    }
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
