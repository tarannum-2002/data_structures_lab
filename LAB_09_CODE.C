//DOUBLY LINKED LIST

#include<stdio.h>
#include<stdlib.h>
struct node {
    struct node *prev;
    int data;
    struct node *next;
};
struct node *head;

void insertAtStart() {
    int item;
    struct node *ptr = (struct node *)malloc(sizeof(struct node *));
    if(head == NULL) {
        printf("Enter value to be inserted: ");
                scanf("%d", &item);
        ptr->next = NULL;
        ptr->prev = NULL;
        ptr->data = item;
        printf("Node Inserted: %d", item);
        head = ptr;
    }
    else {
        printf("Enter value to be inserted: ");
                scanf("%d", &item);
        ptr->data = item;
        ptr->prev = NULL;
        ptr->next = head;
        head->prev = ptr;
        head = ptr;
    }
}

void deleteSpecified() {
    struct node *ptr, *temp;
    int val;
    printf("Enter value: ");
    scanf("%d", &val);
    temp = head;
    while(temp->data != val) 
        temp = temp->next;
    if(temp->next == NULL) {
        printf("Cannot delete at this position");
    }
    else if(temp->next->next == NULL) {
        temp->next = NULL;
        printf("Node Deleted\n");
    }
    else {
        ptr = temp->next;
        temp->next = ptr->next;
        ptr->next->prev = temp;
        free(ptr);
        printf("Node Deleted\n");
    }
}

void display() {
    struct node *temp = head;
    if(head == NULL) {
        printf("List empty");
        return;
    }
    printf("List: \n");
    while(temp != NULL) {
            printf("%d\n", temp->data);
            temp = temp->next;
    }
}

void main() {
    int choice;
    while(1) {
        printf("\n1.Insert at left\n 2.Delete random node\n 3.Display List\n 4.Exit\n ");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: insertAtStart();
                break;
            case 2: deleteSpecified();
                break;
            case 3: display();
                break;
            case 4: exit(1);
                break;
            default: printf("Invalid Choice");
        }
    }
}
