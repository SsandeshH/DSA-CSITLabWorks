#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;



void addAtBeginning(Node **head) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
    printf("Added %d at the beginning\n", data);
}

void addAtEnd(Node **head) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }
    printf("Added %d at the end\n", data);
}

void deleteFromBeginning(Node **head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    if (head->next == head) {
        head = NULL;
        free(temp);
    } else {
        struct Node* last = head;
        while (last->next != head)
            last = last->next;
        head = head->next;
        last->next = head;
        free(temp);
    }
    printf("Deleted from the beginning\n");
}

void deleteFromEnd(Node **head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *prev, *temp = head;
    if (head->next == head) {
        head = NULL;
        free(temp);
    } else {
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        free(temp);
    }
    printf("Deleted from the end\n");
}

void display(Node **head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
	Node* head;
	head=NULL;
    int choice, data;
    printf("1.Add at beginning\n2.Add at End\n3.Delete from beginning\n4.Delete from end\n5.Display\n6.Exit");
    do {
        printf("\nEnter: ");
		scanf("%d",&choice);
        switch (choice) {
            case 1:
                printf("Enter data to add at beginning: ");
                scanf("%d", &data);
                addAtBeginning(data);
                break;
            case 2:
                printf("Enter data to add at end: ");
                scanf("%d", &data);
                addAtEnd(data);
                break;
            case 3:
                deleteFromBeginning();
                break;
            case 4:
                deleteFromEnd();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 6);

    return 0;
}
