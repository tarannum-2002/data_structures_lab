//DELETION IN A LINKED LIST

#include<stdio.h>
#include<stdlib.h>
struct node {
     int data;
    struct node *next;
};
struct node *head;

void insertion() {
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

 void deleteAtStart() {
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
    
void deleteAtEnd() {
    struct node *ptr, *ptr1;
   if(head == NULL) {
       printf("Stack empty\n");
   } 
   else if(head -> next == NULL) {
       head = NULL;
       free(head);
       printf("Only node of the list is deleted\n");
   }
   else {
       ptr = head;
       while(ptr -> next != NULL) {
           ptr1 = ptr;
           ptr = ptr-> next;
       }
       ptr1 -> next = NULL;
       free(ptr);
       printf("Node deleted");
   }
}

void deleteRandom() {
    struct node *ptr, *temp;
    int loc, i;
    printf("Enter the location to be added at: ");
    scanf("%d", &loc);
    ptr = head;
    for(i = 0; i < loc; i++) {
        temp = ptr;
        ptr = ptr->next;
        if(ptr == NULL) {
            printf("Cannot delete at this location\n");
            return;
        }
    }
    temp->next = ptr->next;
    free(ptr);
    printf("Deleted Node: %d\n", loc+1);
}

void display() {
    struct node *ptr;
    ptr = head;
    if(head == NULL) {
        printf("List empty");
    }
    else {
        printf("List: \n");
        while(ptr != NULL) {
            printf("%d \n", ptr->data);
            ptr = ptr->next;
        }
    }
}

void main() {
    int choice;
    while(1) {
        printf("Deletion Operations: \n");
        printf("\n 1.Insertion\n 2.Delete at beginning\n 3.Delete at random location\n 4.Delete at end\n 5.Display\n 6.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: insertion();
                break;
            case 2: deleteAtStart();
                break;
            case 3: deleteRandom();
                break;
            case 4: deleteAtEnd();
                break;
            case 5: display();
                break;
            case 6: exit(1);
                break;
            default: printf("Invalid Choice");
        }
    }
}
