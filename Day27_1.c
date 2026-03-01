#include <stdio.h>
#include <stdlib.h>

// Structure of node
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed\n");
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

// Get length of linked list
int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Find intersection point
struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    struct Node *ptr1 = head1;
    struct Node *ptr2 = head2;

    // Move pointer of longer list ahead
    if (len1 > len2) {
        for (int i = 0; i < diff; i++)
            ptr1 = ptr1->next;
    } else {
        for (int i = 0; i < diff; i++)
            ptr2 = ptr2->next;
    }

    // Traverse together
    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1 == ptr2)   // compare addresses
            return ptr1;

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return NULL;
}

// Display list
void display(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Main
int main() {
    // Creating first list
    struct Node* head1 = NULL;
    head1 = insertAtEnd(head1, 10);
    head1 = insertAtEnd(head1, 20);
    head1 = insertAtEnd(head1, 30);

    // Creating second list
    struct Node* head2 = NULL;
    head2 = insertAtEnd(head2, 5);
    head2 = insertAtEnd(head2, 15);

    // Creating intersection node
    struct Node* intersect = createNode(100);
    intersect->next = createNode(200);

    // Attach intersection
    struct Node* temp = head1;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = intersect;

    temp = head2;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = intersect;

    printf("List 1: ");
    display(head1);

    printf("List 2: ");
    display(head2);

    // Find intersection
    struct Node* result = findIntersection(head1, head2);

    if (result != NULL)
        printf("Intersection at node with data: %d\n", result->data);
    else
        printf("No intersection found\n");

    return 0;
}