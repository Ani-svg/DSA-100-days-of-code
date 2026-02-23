#include <stdio.h>
#include <stdlib.h>

// Structure of node
struct Node {
    int data;
    struct Node* next;
};

// Function to create new node
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

// Function to insert at end
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

// Function to merge two sorted linked lists
struct Node* mergeLists(struct Node* head1, struct Node* head2) {
    struct Node* mergedHead = NULL;
    struct Node* mergedTail = NULL;

    while (head1 != NULL && head2 != NULL) {
        struct Node* newNode;

        if (head1->data <= head2->data) {
            newNode = createNode(head1->data);
            head1 = head1->next;
        } else {
            newNode = createNode(head2->data);
            head2 = head2->next;
        }

        if (mergedHead == NULL) {
            mergedHead = newNode;
            mergedTail = newNode;
        } else {
            mergedTail->next = newNode;
            mergedTail = newNode;
        }
    }

    // Add remaining elements
    while (head1 != NULL) {
        mergedTail->next = createNode(head1->data);
        mergedTail = mergedTail->next;
        head1 = head1->next;
    }

    while (head2 != NULL) {
        mergedTail->next = createNode(head2->data);
        mergedTail = mergedTail->next;
        head2 = head2->next;
    }

    return mergedHead;
}

// Function to display list
void display(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    int n1, n2, value, i;

    printf("Enter number of nodes in first sorted list: ");
    scanf("%d", &n1);

    for (i = 0; i < n1; i++) {
        scanf("%d", &value);
        head1 = insertEnd(head1, value);
    }

    printf("Enter number of nodes in second sorted list: ");
    scanf("%d", &n2);

    for (i = 0; i < n2; i++) {
        scanf("%d", &value);
        head2 = insertEnd(head2, value);
    }

    struct Node* mergedHead = mergeLists(head1, head2);

    printf("Merged Sorted List:\n");
    display(mergedHead);

    return 0;
}
