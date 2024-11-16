/*  Alvi Aulia Fatikha
    2602182865
    No 3 GSLC Session 5 */

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

struct node{
	struct node* previous;
	Type info;
	struct node* next;
};

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

void pushBack(struct node** head, Type info){
	if(*head == NULL){
		struct node* newNode = (struct node*) malloc(sizeof(struct node));
		newNode -> info = info;
		newNode -> next = newNode -> previous = newNode;
		*head = newNode;
		return;
	}

	struct node* last = (*head) -> previous;
	struct node* newNode = (struct node*) malloc(sizeof(struct node));
	newNode -> info = info;
	(*head) -> previous = newNode;
	newNode -> previous = last;
	newNode -> next = (*head);
	last -> next = newNode;
}

void pushFront(struct node** head, Type info){
	struct node* last = (*head) -> previous;
	struct node* newNode = (struct node*) malloc(sizeof(struct node));
	newNode -> next = (*head);
	newNode -> previous = last;
	last -> next = (*head) -> previous = newNode;

	*head = newNode;
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

	puts("FORWARD DIRECTION STACK");
	while(temp -> next != head){
		display(temp -> info);
		temp = temp -> next;
	}
	display(temp -> info);

	puts("\n");
	puts("REVERSE DIRECTION STACK");
	struct node* last = head -> previous;
	temp = last;
	while(temp -> previous != last){
		display(temp -> info);
		temp = temp -> previous;
	}
	display(temp -> info);
}

int main(int _argc, char const *_argv[]){
	struct node* head = NULL;

	pushBack(&head, NewElement("RTX-3060",    1320, 12, 550, 384));
	pushBack(&head, NewElement("RTX-3070",    1580,  8, 650, 448));
	pushBack(&head, NewElement("RTX-3090",    1400, 24, 750, 936));
	pushBack(&head, NewElement("RTX-3090 Ti", 1860, 24, 850, 936));

	puts("After Insertion:");
	viewList(head);

	deleteAtIndex(&head, 2);

	puts("\nAfter Deletion of Index 2:");
	viewList(head);

	return 0;
}
