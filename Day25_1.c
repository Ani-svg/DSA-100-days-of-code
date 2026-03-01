#include <stdio.h>
#include <stdlib.h>

// Define structure for linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert node at end
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    
    if (head == NULL) {
        return newNode;
    }
    
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = newNode;
    return head;
}

// Function to count occurrences
int countOccurrences(struct Node* head, int key) {
    int count = 0;
    struct Node* temp = head;
    
    while (temp != NULL) {
        if (temp->data == key) {
            count++;
        }
        temp = temp->next;
    }
    
    return count;
}

// Function to free allocated memory
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function
int main() {
    struct Node* head = NULL;
    int n, value, key;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &value);
        head = insertAtEnd(head, value);
    }

    printf("Enter element to count: ");
    scanf("%d", &key);

    int result = countOccurrences(head, key);
    printf("Element %d occurs %d times.\n", key, result);

    freeList(head);

    return 0;
}