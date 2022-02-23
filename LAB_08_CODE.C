//Stack & Queue implementation using Linked List

#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *head;

void push() {
    struct node *ptr;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node *));
    if(ptr == NULL) {
        printf("Stack overflow\n");
    }
    else {
        printf("Enter value to be inserted: ");
        scanf("%d", &item);
        ptr->data = item;
        ptr->next = head;
        head = ptr;
        printf("Node inserted\n");
    }
}

    void pop() {
        struct node *ptr;
        if(head == NULL) {
            printf("Stack empty\n");
        }
        else {
            ptr = head;
            head = ptr ->next;
            free(ptr);
            printf("Node deleted\n");
        }
    }
    
    void stackDisplay() {
        struct node *ptr;
        ptr = head;
        if(head == NULL) {
            printf("Stack empty\n");
        }
        else {
            printf("Stack: \n");
            while(ptr != NULL) {
                printf("%d \n", ptr->data);
                ptr = ptr->next;
            }
        }
    }

    void enqueue() {
    struct node *ptr, *temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node *));
    if(ptr == NULL) {
        printf("Queue Full\n");
    }
    else {
        printf("Enter value to be inserted: ");
        scanf("%d", &item);
        ptr->data = item;
        if(head == NULL) {
            ptr->next = NULL;
            head = ptr;
            printf("Node inserted\n");
        }
        else {
            temp = head;
            while(temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->next = NULL;
            printf("Node inserted\n");
        }
    }
        
}

void dequeue() {
    struct node *ptr;
   if(head == NULL) {
       printf("Stack empty\n");
   }
   else {
       ptr = head;
       head = ptr ->next;
       free(ptr);
       printf("Node deleted\n");
   }
}

void queueDisplay() {
    struct node *ptr;
    ptr = head;
    if(head == NULL) {
        printf("Queue empty");
    }
    else {
        printf("Queue: \n");
        while(ptr != NULL) {
            printf("%d \n", ptr->data);
            ptr = ptr->next;
        }
    }
}

void main() {
    int choice;
    while(1) {
        printf("Stack Operations: 1.Push 2.Pop 3.Display 4.Exit\n");
        printf("Queue Operations: 5.Enqueue 6.Dequeue 7.Display 4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: push();
                break;
            case 2: pop();
                break;
            case 3: stackDisplay();
                break;
            case 5: enqueue();
                break;
            case 6: dequeue();
                break;
            case 7: queueDisplay();
                break;
            case 4: exit(1);
                break;
            default: printf("Invalid Choice");
        }
    }
    
}
