#include "Stack.h"

int isEmpty(Stack *stack)
{
	if(!stack) {
		printf("Stack Kosong!");
		return TRUE;
	}
	
	return stack->topNode == NULL;
}

StackNode* buatNodeStack()
{
	StackNode *tampung = (StackNode*)calloc(sizeof(StackNode), 1);
	
	if(!tampung){
		printf("Alokasi Memori Gagal!");
		return;
	}
	
	return tampung;
}

Stack* buatStack()
{
	Stack *tampung = (Stack*)calloc(sizeof(Stack), 1);
	
	if(!tampung) {
		printf("Alokasi Memori Gagal!");
		return;
	}
	
	return tampung;
}

void cetakStack(StackNode *daunTree)
{
	if(!daunTree)	
	return;
	
	if(daunTree->cek_karakter){
		printf("%c", daunTree->data.operatorMatematis);
	}
	
	else{
		printf("%g", daunTree->data.bilangan);
	}
}

void push(Stack *stack, Data isiTree, int cek_karakter)
{
	StackNode *tampung = buatNodeStack();
	
	if(!tampung) {
		puts("Alokasi Memori Gagal!");
		return;
	}
	
	tampung->data = isiTree;
	tampung->cek_karakter = cek_karakter;
	tampung->pNode = stack->topNode;
	stack->topNode = tampung;
}

StackNode pop(Stack *stack)
{
	StackNode res;
	
	res.data = dummy_data;
	res.cek_karakter = FALSE;
	
	if(!stack || isEmpty(stack))	
	return res;
	
	res = *(stack->topNode);
	StackNode *tampung = stack->topNode;
	stack->topNode = tampung->pNode;
	free(tampung);
	return res;
}

void hapusStack(Stack *stack)
{
	StackNode sn;
	
	while(!isEmpty(stack)) {
		sn = pop(stack);
		cetakStack(&sn);
	}
	
}
