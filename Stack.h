#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include "boolean.h"

typedef union	
{
	double bilangan;		//menampung bilangan pada operasi matematis
	char operatorMatematis;	//menampung operator (+), (-), (*), (/) pada operasi matematis di Stack
} Data;

/*
Union mengalokasikan satu ruang penyimpanan umum untuk semua anggotanya. 
Anggota 'Union' hanya dapat diakses satu per satu.
*/

//sumber : https://binaryupdates.com/structures-typedef-union-in-c-programming/

typedef struct StackNode
{
	int cek_karakter;			//angka/value untuk menampung hasil Boolean (1 untuk TRUE, 0 untuk FALSE)
	Data data;					//Data bernama 'data'
	struct StackNode *pNode;	//pointer Node
	int data_kosong;
} StackNode;					//Nama objek

typedef struct Stack
{
	StackNode *topNode;			//pointer yang menunjuk posisi paling atas Node Stack
} Stack;						//Stack

int isEmpty(Stack *stack);		//Mengecek kondisi apakah stack kosong atau tidak

StackNode* buatNodeStack();		//membuat Node pada Stack
Stack* buatStack();				//membuat Stack

void cetakStack(StackNode*);	//Mencetak elemen pada stack

void push(Stack *stack, Data isiTree, int isChar);	//melakukan push pada stack
StackNode pop(Stack *stack);	//menghapus elemen pada stack

void hapusStack(Stack *stack);	//menghapus seluruh elemen stack

#endif 
