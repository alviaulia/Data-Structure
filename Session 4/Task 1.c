/*  TASK 1
    ALvi Aulia Fatikha
    2602182865 */

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

void insert_begin(struct node** head, int newData){
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode -> data = newData;
    newNode -> next = (*head);
    (*head) = newNode;
}

void delete_begin(struct node** head){
    if (*head == NULL)
        return;

    struct node* temp = *head;
    *head = (*head) -> next;
    free(temp);
}

void delete_last(struct node** head){
    if (*head == NULL)
        return;

    if ((*head) -> next == NULL){
        free(*head);
        *head = NULL;
        return;
    }

    struct node* temp = *head;
    while (temp -> next -> next != NULL)
        temp = temp -> next;
    free(temp -> next);
    temp->next = NULL;
}

void search_element(struct node* head, int value){
    while (head != NULL) {
        if (head -> data == value) {
            printf("Element %d is exist\n", value);
            return;
        }
        head = head -> next;
    }
    printf("Element %d doesn't exist\n", value);
}

int main(){
    struct node* head = NULL;

    insert_begin(&head, 50);
    insert_begin(&head, 45);
    insert_begin(&head, 32);
    insert_begin(&head, 20);

    printf("Data List: ");
    struct node* temp = head;
    while (temp != NULL){
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    printf("\n\n");


    delete_begin(&head);
    printf("After Removal of the First Element: ");
    temp = head;
    while (temp != NULL){
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    printf("\n");


    delete_last(&head);
    printf("After Removal of the Last Element: ");
    temp = head;
    while (temp != NULL){
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    printf("\n\n");

    printf("Searching element:\n");
    search_element(head, 45);
    search_element(head, 10);
    search_element(head, 20);

    return 0;
}
