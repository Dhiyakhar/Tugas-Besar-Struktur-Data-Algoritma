#include "Stack.h"

int isEmpty(Stack *stack)		//Memastikan apakah stack Kosong atau Tidak
{
	if(!stack) {				//Jika stack kosong
		printf("Stack Kosong!");
		return TRUE;			//mengembalikan nilai TRUE (1)
	}
	
	return stack->topNode == NULL;	//mengembalikan nilai elemen paling atas stack adalah NULL
}

StackNode* buatNodeStack()		//Alokasi Memori untuk membuat Node Stack
{
	StackNode *tampung = (StackNode*)calloc(sizeof(StackNode), 1);
	
	if(!tampung){				//Jika penampung kosong
		printf("Alokasi Memori Gagal!");
		return;
	}
	
	return tampung;				//mengembalikan value tampung
}

Stack* buatStack()				//Alokasi Memori untuk membuat Node Stack
{
	Stack *tampung = (Stack*)calloc(sizeof(Stack), 1);
	
	if(!tampung) {				//Jika penampung kosong
		printf("Alokasi Memori Gagal!");
		return;				
	}
	
	return tampung;				//mengembalikan value tampung
}

void cetakStack(StackNode *daunTree)	//mencetak elemen dari Stack
{
	if(!daunTree)				//jika Stack Kosong
	return;						//tidak mengembalikan apa-apa
	
	if(daunTree->cek_karakter){	//Jika pointer daunTree menunjuk ke cek_karakter
		printf("%c", daunTree->data.operatorMatematis);
	}
	
	else{						//Jika pointer daunTree menunjuk ke cek_karakter
		printf("%g", daunTree->data.bilangan);
	}
}

void push(Stack *stack, Data isiTree, int cek_karakter)	//Menambah elemen pada stack
{
	StackNode *tampung = buatNodeStack();	//melakukan alokasi memori pada Stack Tampung
	
	if(!tampung) {							//Jika Tampung = NULL, Alokasi memorinya gagal
		printf("Alokasi Memori Gagal!");
		return;
	}
	
	tampung->data = isiTree;				//Assign nilai isiTree ke data
	tampung->cek_karakter = cek_karakter;	//Assign nilai cek_karakter (BOOLEAN) ke cek_karakter pada pointer tampung
	tampung->pNode = stack->topNode;		//memindahkan pointer Stack ke elemen paling awal
	stack->topNode = tampung;				//Assign nilai tampung ke elemen paling atas
}

StackNode pop(Stack *stack)	//melepas atau menghapus elemen pada stack
{
	StackNode periksa;	//stack untuk memeriksa kondisi Stack sebelum melepas elemen
	
	periksa.data = dummy_data;		//inisialisasi data kosong
	periksa.cek_karakter = FALSE;	//boolean yang diinisialisasi FALSE (0) untuk mengecek karakter
	
	if(!stack || isEmpty(stack))	//Jika stack kosong (NULL)
	return periksa;					//tidak menghasilkan apa-apa
	
	periksa = *(stack->topNode);			//Stack menunjuk ke Pointer Node/elemen paling atas
	StackNode *tampung = stack->topNode;	//Pointer menunjuk ke Node/Elemen paling atas
	stack->topNode = tampung->pNode;		//Node/Elemen paling atas diisi oleh value dari pointer Node
	free(tampung);							//menghapus elemen yang ditunjuk
	return periksa;
}

void hapusStack(Stack *stack)	//Modul untuk menghapus Stack
{
	StackNode hapus;			//Stack bernama hapus untuk menghapus elemen stack
	
	while(!isEmpty(stack)) {	//Selama stack belum kosong
		hapus = pop(stack);		//menghapus elemen pada stack
		cetakStack(&hapus);		//mencetak elemen-elemen stack hapus
	}
	
}
