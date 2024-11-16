/*  Alvi Aulia Fatikha
    2602182865
    No 2 GSLC Session 5 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char String[64];

typedef struct{
    String vga;
    int bcs;
    int vram;
    int power;
    int bandwidth;
}Type;

Type NewElement(char* vga, int bcs, int vram, int power, int bandwidth){
    Type element;
    strcpy(element.vga, vga);
    element.bcs = bcs;
    element.vram = vram;
    element.power = power;
    element.bandwidth = bandwidth;
    return element;
}

void display(Type info){
    printf("%-11s\t|  %4d MHz\t|  %2d GB\t|  %3d Watt\t|  %3d GB/s\t\n",
        info.vga, info.bcs, info.vram, info.power, info.bandwidth);
}

struct node{
	struct node* next;
	Type info;
	struct node* previous;
};

void pushFront(struct node** head, Type new_info){
	struct node* new_node = (struct node*) malloc(sizeof(struct node));

	new_node -> info = new_info;
	new_node -> next = (*head);
	new_node -> previous = NULL;

	if((*head) != NULL)
		(*head) -> previous = new_node;

	(*head) = new_node;
}

void pushBack(struct node** head, Type new_info){
	struct node* new_node = (struct node*) malloc(sizeof(struct node));

	struct node* last = *head;
	new_node -> info = new_info;
	new_node -> next = NULL;

	if(*head == NULL){
		new_node -> previous = NULL;
		*head = new_node;
		return;
	}

	while(last -> next != NULL)
		last = last -> next;
	last -> next = new_node;
	new_node -> previous = last;
	return;
}

void deleteAtIndex(struct node** head, int pos){
	int i = 1;
	struct node *position, *tmp;
	tmp = (*head);
	while(i <= pos - 1){
		tmp = tmp -> next;
		i++;
	}
	position = tmp -> next;
	tmp -> next = position -> next;
	position -> next -> previous = tmp;

	free(position);
}

void viewList(struct node* head){
	struct node* temp = head;

	while(temp -> next != NULL){
		display(temp -> info);
		temp = temp -> next;
	}
	display(temp -> info);
}

int main(int _argc, char const *_argv[]){
	struct node* head = NULL;

	pushBack(&head, NewElement("RTX-3070",    1580,  8, 650, 448));
	pushBack(&head, NewElement("RTX-3090",    1400, 24, 750, 936));
	pushBack(&head, NewElement("RTX-3090 Ti", 1860, 24, 850, 936));
	pushFront(&head, NewElement("RTX-3060",    1320, 12, 550, 384));

    puts("After Insertion:");
	viewList(head);

	deleteAtIndex(&head, 2);

    puts("\nAfter Deletion of Index 2:");
	viewList(head);

	return 0;
}
