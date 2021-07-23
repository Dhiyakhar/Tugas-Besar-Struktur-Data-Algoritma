#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include "Common.h"

typedef struct StackNode
{
	int cek_karakter;
	Data data;
	struct StackNode *pNode;
} StackNode;

typedef struct Stack
{
	StackNode *topNode;
} Stack;

int isEmpty(Stack *stack);		//Mengecek kondisi apakah stack kosong atau tidak

StackNode* buatNodeStack();
Stack* buatStack();

void cetakStack(StackNode*);

void push(Stack *stack, Data isiTree, int isChar);
StackNode pop(Stack *stack);

void hapusStack(Stack *stack);

#endif // STACK_H_INCLUDED
