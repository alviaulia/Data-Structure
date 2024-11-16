/*  Alvi Aulia Fatikha
    2602182865
    No 1 GSLC Session 5 */

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
	Type info;
	struct node* next;
};

struct node* last = NULL;

Type NewElement(char* vga, int bcs, int vram, int power, int bandwidth){
    Type element;
    strcpy(element.vga, vga);
    element.bcs = bcs;
    element.vram = vram;
    element.power = power;
    element.bandwidth = bandwidth;

    return element;
}

void pushFront(Type data){
	struct node* tmp;
	tmp = (struct node*) malloc(sizeof(struct node));

	if(last == NULL){
		tmp -> info = data;
		tmp -> next = tmp;
		last = tmp;
	}
	else{
		tmp -> info = data;
		tmp -> next = last -> next;
		last -> next = tmp;
	}
}

void deleteAtIndex(int pos){
    int i = 1;
    struct node *tmp, *position;
    tmp = last -> next;

    if(last == NULL)
        return;

    else{
        while (i <= pos - 1){
            tmp = tmp->next;
            i++;
        }
        position = tmp -> next;
        tmp -> next = position -> next;

        free(position);
    }
}

void display(Type info){
    printf("%-11s\t|  %4d MHz\t|  %2d GB\t|  %3d Watt\t|  %3d GB/s\t\n",
       info.vga, info.bcs, info.vram, info.power, info.bandwidth);
}

void viewList(){
	if (last == NULL)
		printf("\nList is empty\n");

	else{
		struct node* tmp;
		tmp = last -> next;

		do{
			display(tmp -> info);
			tmp = tmp -> next;
		}while (tmp != last -> next);
	}
}

int main(int _argc, char const *_argv[]){
	pushFront(NewElement("RTX-3060", 1320, 12, 550, 384));
	pushFront(NewElement("RTX-3070", 1580, 8, 650, 448));
	pushFront(NewElement("RTX-3090", 1400, 24, 750, 936));
	pushFront(NewElement("RTX-3090 Ti", 1860, 24, 850, 936));

	puts("After Insertion:");
	viewList();

	deleteAtIndex(2);

	puts("\nAfter Deletion of Index 2:");
	viewList();

	return 0;
}
