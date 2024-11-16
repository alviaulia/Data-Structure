/*  TASK 2
    ALvi Aulia Fatikha
    2602182865 */

#include <stdio.h>
#include <stdlib.h>

struct node{
    int coeff;
    int power;
    struct node* next;
};

struct node* createNode(int coeff, int power){
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode -> coeff = coeff;
    newNode -> power = power;
    newNode -> next = NULL;

    return newNode;
}

void insert(struct node** poly, int coeff, int power){
    struct node* newNode = createNode(coeff, power);
    if (*poly == NULL){
            *poly = newNode;
    } else{
        struct node* temp = *poly;
        while (temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = newNode;
    }
}

void printPoly(struct node* poly){
    struct node* temp = poly;
    while (temp != NULL){
            printf("%dx^%d", temp -> coeff, temp -> power);
    if (temp -> next != NULL){
            printf(" + ");
        }
        temp = temp -> next;
    }
    printf("\n");
}

struct node* multiply(struct node* poly1, struct node* poly2){
    struct node* result = NULL;
    struct node* ptr1 = poly1;

    while (ptr1 != NULL){
        struct node* ptr2 = poly2;
        while (ptr2 != NULL){
            int coeff = ptr1 -> coeff * ptr2 -> coeff;
            int power = ptr1 -> power + ptr2 -> power;
            struct node* temp = result;
            while (temp != NULL){
                if (temp -> power == power){
                temp -> coeff += coeff;
                break;
                }
                temp = temp -> next;
            }
            if (temp == NULL){
                insert(&result, coeff, power);
            }
            ptr2 = ptr2 -> next;
        }
        ptr1 = ptr1 -> next;
    }

    return result;
}

int main(){
    struct node* poly1 = NULL;

    insert(&poly1, 3, 2);
    insert(&poly1, 5, 1);
    insert(&poly1, 6, 0);
    printf("Polinomial Pertama\t: ");
    printPoly(poly1);

    struct node* poly2 = NULL;
    insert(&poly2, 6, 1);
    insert(&poly2, 8, 0);
    printf("Polinomial Kedua\t: ");
    printPoly(poly2);

    struct node* result = multiply(poly1, poly2);
    printf("Hasil Perkalian\t\t: ");
    printPoly(result);

    return 0;
}
