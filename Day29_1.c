#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create node
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

// Insert at end
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Get length
int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Rotate right by k places
struct Node* rotateRight(struct Node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    int length = getLength(head);

    k = k % length;  // handle k > length
    if (k == 0)
        return head;

    struct Node* temp = head;

    // Traverse to last node
    while (temp->next != NULL)
        temp = temp->next;

    // Make circular
    temp->next = head;

    // Find new tail position
    int stepsToNewTail = length - k;
    struct Node* newTail = head;

    for (int i = 1; i < stepsToNewTail; i++)
        newTail = newTail->next;

    // New head
    struct Node* newHead = newTail->next;

    // Break circular link
    newTail->next = NULL;

    return newHead;
}

// Print list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Free list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main
int main() {
    struct Node* head = NULL;
    int n, value, k;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &value);
        head = insertAtEnd(head, value);
    }

    printf("Enter k (number of rotations): ");
    scanf("%d", &k);

    printf("Original List:\n");
    printList(head);

    head = rotateRight(head, k);

    printf("Rotated List:\n");
    printList(head);

    freeList(head);

    return 0;
}