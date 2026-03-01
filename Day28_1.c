#include <stdio.h>
#include <stdlib.h>

// Structure for circular linked list node
struct Node {
    int data;
    struct Node* next;
};

// Create new node
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

// Insert at end in circular linked list
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    // If list is empty
    if (head == NULL) {
        head = newNode;
        newNode->next = head;   // Point to itself
        return head;
    }

    struct Node* temp = head;

    // Traverse to last node
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;   // Maintain circular property

    return head;
}

// Traverse circular linked list
void traverse(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;

    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(back to head)\n");
}

// Free circular linked list
void freeList(struct Node* head) {
    if (head == NULL)
        return;

    struct Node* temp = head->next;
    struct Node* nextNode;

    while (temp != head) {
        nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }

    free(head);
}

// Main function
int main() {
    struct Node* head = NULL;
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &value);
        head = insertAtEnd(head, value);
    }

    traverse(head);

    freeList(head);

    return 0;
}