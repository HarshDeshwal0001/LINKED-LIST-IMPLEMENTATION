#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    printf("Inserted %d\n", value);
}

// Delete a node
void deleteNode(struct Node** head, int value) {
    struct Node *temp = *head, *prev = NULL;

    // If first node
    if (temp != NULL && temp->data == value) {
        *head = temp->next;
        free(temp);
        printf("Deleted %d\n", value);
        return;
    }

    // Search for value
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("%d not found\n", value);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Deleted %d\n", value);
}

// Print the list
void printList(struct Node* head) {
    printf("List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    printList(head);

    deleteNode(&head, 20);
    printList(head);

    deleteNode(&head, 100);  // not found
    printList(head);

    return 0;
}
