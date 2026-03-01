#include <stdio.h>
#include <stdlib.h>

// Structure of Node
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
struct Node* insertEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Delete first occurrence of key
struct Node* deleteKey(struct Node* head, int key) {
    struct Node *temp = head, *prev = NULL;

    // If head node itself holds the key
    if (temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        return head;
    }

    // Search for key
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key not found
    if (temp == NULL) {
        printf("Key not found in list.\n");
        return head;
    }

    // Unlink the node
    prev->next = temp->next;
    free(temp);

    return head;
}

// Display list
void display(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int n, value, key, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    printf("Enter key to delete: ");
    scanf("%d", &key);

    head = deleteKey(head, key);

    printf("Updated List:\n");
    display(head);

    return 0;
}
