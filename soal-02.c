/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul            : 7 - Stacks and Queues
*Percobaan        : -
*Hari dan Tanggal : Kamis, 7 April 2022
*Nama (NIM)       : -
*Asisten (NIM)    : -
*Nama File        : soal-02.c
*Deskripsi        : -
*/

#include<stdio.h>
#include<stdlib.h>

//Node and stack declaration
typedef struct Node { 
	int data; 
	struct Node* next; 
} Node;

typedef struct Stack {
	Node* head;
} Stack;

//function declaration
void push(Stack* stack, int new_data);
int pop(Stack* stack);
void EmptyStack(Stack* stack);

int main() {
	Stack* main_stack = (Stack*) malloc(sizeof(Stack));
	Stack* memory_stack = (Stack*) malloc(sizeof(Stack));

	main_stack->head=NULL;
	memory_stack->head=NULL;

	char operator='S';
	int operand,temp, final_value;
	scanf("%c", &operator);

	while(operator!='F') {
		if(operator=='P') {
			if(main_stack->head==NULL) {
				printf("Current Value : 0\n");
			}
			else {
				printf("Current Value : %d\n",main_stack->head->data);
			}
		}
		else if(operator=='Z') {
			if(main_stack->head==NULL) {
				printf("Bottom of stack\n");
			}
			else {
				push(memory_stack,pop(main_stack));
			}
		}
		else if(operator=='Y') {
			if(memory_stack->head==NULL) {
				printf("Top of Stack\n");
			}
			else {
				push(main_stack,pop(memory_stack));
			}
		}
		else if(operator=='+') { //yang dilakukan adalah operasi
			EmptyStack(memory_stack);
			scanf("%d",&operand);
			if(main_stack->head==NULL) {
				push(main_stack, operand);
			}
			else {
				push(main_stack, main_stack->head->data+operand);
			}          
		}
		scanf(" %c",&operator);
	}
	if(main_stack->head==NULL) {
		final_value=0;
	}
	else {
		final_value=main_stack->head->data;
	}
	printf("Final Value : %d\n", final_value);
}

//function

void push(Stack* stack, int new_data) {
	Node* new_node = (Node*) malloc(sizeof(Node));
	new_node->data = new_data;
	new_node->next = stack->head;

	stack->head = new_node;
}

int pop(Stack* stack) {
	int ret_val = 0;
	Node* temp = stack->head;

	if (temp != NULL) {
		ret_val = temp->data;
		stack->head = temp->next;

		free(temp);
	}

	return(ret_val);
}

void EmptyStack(Stack* stack) {
	while(stack->head!=NULL) {
		pop(stack);
	}
}
