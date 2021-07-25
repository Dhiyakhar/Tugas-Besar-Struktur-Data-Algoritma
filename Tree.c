#include "Tree.h"

Root* buatAkarDaun()								//membuat Root pada Tree dengan alokasi memori
{
	Root* tampung = (Root*)calloc(sizeof(Root), 1);	//alokasi memori
	if(!tampung) {									//jika Tree tidak terbentuk
		printf("Alokasi memori gagal!");			//jika gagal, akan menampilkan pesan
		exit(1);
	}
	return tampung;
}

TreeNode* buatDaunPohon()										//Membuat leaf (daun) pada Tree dengan alokasi memori
{
	TreeNode* tampung = (TreeNode*)calloc(sizeof(TreeNode), 1); //alokasi memori
	if(!tampung){												//jika leaf pada Tree tidak terbentuk
		puts("Alokasi memori gagal!"); 							//jika gagal, akan menampilkan pesan
		exit(1);
	}
	return tampung;
}

TreeNode* buatAnak(TreeNode *nodeParent, Data isiTree, int cek_karakter)	//membuat anak Tree
{
	if(!nodeParent)									//jika Node pada Parent Tree tidak Null
	{
		nodeParent = buatDaunPohon();				//Alokasi memori leaf (anak) Tree
		nodeParent->data = isiTree;					//lakukan assign data ke nodeParent pointer data
		nodeParent->cek_karakter = cek_karakter;	//lakukan assign nilai Boolean dari cek_karakter ke nodeParent pointer data
		return nodeParent;
	}
	
	if(nodeParent->left && nodeParent->right)				//Jika pointer menunjuk pada Node kiri atau kanan
	{
		nodeParent = nodeParent->parent;					//pointer menunjuk pada parent
		
		if(!nodeParent)										//jika node parent tidak ada, mengembalikan nilai NULL
		return NULL;
		
		return buatAnak(nodeParent, isiTree, cek_karakter);	//mengembalikan modul buatAnak()
	}
	// mengembalikan pointer itu sendiri
	if(!cek_karakter) 											//jika cek_karakter = NULL	
	{
		if(nodeParent->right)									//Jika nodeParent menunjuk ke kanan
		{
			buatAnakKiri(nodeParent, isiTree, cek_karakter);	//Buat anak parent untuk sebelah kiri
		}
		else													//Jika nodeParent menunjuk ke kiri
		{
			buatAnakKanan(nodeParent, isiTree, cek_karakter);	//Buat anak parent untuk sebelah kanan
		}
		return nodeParent;										//Mengembalikan nodeParent
	}
	
	else // untuk operator, mengembalikan pointer dari node anak Parent.
	{

		if(nodeParent->left)	//Jika nodeParent menunjuk ke kiri
		{
			buatAnakKanan(nodeParent, isiTree, cek_karakter);	//membuat anak Kanan
			return nodeParent->right;	//pointer menunjuk ke sebeleah kanan
		}

		else
		{
			buatAnakKiri(nodeParent, isiTree, cek_karakter);	//membuat anak Kanan
			return nodeParent->left;	//pointer menunjuk ke sebeleah kanan
		}
	}
	
}

void buatAnakKiri(TreeNode *nodeParent, Data isiTree, int cek_karakter)
{
	TreeNode* tampung = buatDaunPohon();	//Melakukan alokasi memori untuk leaf Tree (Daun)
	
	if(!tampung)	//jika objek tampung Null
	return;			//tidak mengembalikan apa-apa
	
	tampung->data = isiTree;				//assign value pada pointer data dengan isiTree
	tampung->cek_karakter = cek_karakter;	//assign value pada pointer cek_karakter dengan value cek_karakter
	nodeParent->left = tampung;				//assign value pada pointer left dengan value tampung
	tampung->parent = nodeParent;			//assign value pada pointer parent dengan nodeParent
}

void buatAnakKanan(TreeNode *nodeParent, Data isiTree, int cek_karakter)
{
	TreeNode* tampung = buatDaunPohon();	//Melakukan alokasi memori untuk leaf Tree (Daun)
	
	if(!tampung)	//jika objek tampung Null
	return;			//tidak mengembalikan apa-apa
	
	tampung->data = isiTree;				//assign value pada pointer data dengan isiTree
	tampung->cek_karakter = cek_karakter;	//assign value pada pointer cek_karakter dengan value cek_karakter
	nodeParent->right = tampung;			//assign value pada pointer right dengan value tampung
	tampung->parent = nodeParent;			//assign value pada pointer parent dengan nodeParent
}


//** Cetak dan Pilih **//
void cetakTree(Data isiTree, int cek_karakter)		//mencetak Tree
{
	if(cek_karakter) {								//jika variabel cek_karakter adalah angka
		printf("%c", isiTree.operatorMatematis);	//mencetak operator Matematis
	}
	else {
		printf("%g", isiTree.bilangan);				//mencetak angka pada operasi matematik
	}
}

void pilihanTraversal(Root *root, int mode)
{
	TreeNode *tampung = root->root;	//pointer root menunjuk ke akar (paling atas)
	
	switch(mode)
	{
		case 1:	//Pilihan 1 : mencetak elemen Tree secara preOrder
			preOrder(tampung);
			break;
		case 2:	//Pilihan 2 : mencetak elemen Tree secara inOrder
			inOrder(tampung);
			break;
		case 3:	//Pilihan 3 : mencetak elemen Tree secara postOrder
			postOrder(tampung);
			break;
	}
}

//** Cetak, Traversal, dan Hapus **//

void preOrder(TreeNode *daunTree)	//Traversal secara preOrder
{
	if(!daunTree)	//jika leaf pada Tree tidak ada
	return;			//Modul berhenti
	
	cetakTree(daunTree->data, daunTree->cek_karakter);	//mencetak isi Tree
	preOrder(daunTree->left);							//Melakukan preorder ke kiri Tree
	preOrder(daunTree->right);							//Melakukan preorder ke kiri Tree
}

void inOrder(TreeNode *daunTree)	//Traversal secara inOrder
{
	if(!daunTree)	//jika daun (anak) dari Tree tidak ada
	return;			//tidak mengembalikan apa-apa
	
	inOrder(daunTree->left);							//melakukan postorder
	cetakTree(daunTree->data, daunTree->cek_karakter);	//mencetak isi Tree setelah dilakukan traversal
	inOrder(daunTree->right);							//melakukan postorder
}

void postOrder(TreeNode *daunTree)	//Traversal secara postOrder
{
	if(!daunTree)	//jika daun (anak) dari Tree tidak ada	
	return;			//tidak mengembalikan apa-apa
	
	postOrder(daunTree->left);							//melakukan postorder pada anak (child) sebelah kanan
	postOrder(daunTree->right);							//melakukan postorder pada anak (child) sebelah kanan
	cetakTree(daunTree->data, daunTree->cek_karakter);	//mencetak isi Tree setelah dilakukan traversal
}

void hapusNode(TreeNode *daunTree)	//Menghapus salah satu elemen node pada Tree
{
	if(!daunTree)	//jika daun (anak) dari Tree tidak ada	
	return;			//tidak mengembalikan apa-apa
	
	hapusNode(daunTree->left);	 //menghapus node pada Tree sebelah kiri
	hapusNode(daunTree->right); //menghapus node pada Tree sebelah kanan
	free(daunTree);				//menghapus node pada Tree
}

void hapusSemuaTree(Root* root)	//Menghapus semua elemen node pada Tree
{
	hapusNode(root->root);	//menghapus Tree pada Akar
}
