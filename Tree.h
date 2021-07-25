#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include "Common.h"

typedef struct TreeNode	//Tree
{
	int cek_karakter;	//Pointer info
	Data data;			//Pointer Data
	
	struct TreeNode *parent;	//pointer parent
	struct TreeNode *left;		//pointer anak kiri
	struct TreeNode *right;		//pointer anak kanan
} TreeNode;	//Nama objek

typedef struct Root
{
	TreeNode *root;		//pointer Root
} Root;	//Nama objek

Root* buatAkarDaun();		//membuat Root pada Tree
TreeNode* buatDaunPohon();	//membuat leaf pada Tree
TreeNode* buatAnak(TreeNode *nodeParent, Data isiTree, int cek_karakter);	//membuat Child pada Tree

void buatAnakKiri(TreeNode *nodeParent, Data isiTree, int cek_karakter);	//membuat leftChild pada Tree
void buatAnakKanan(TreeNode *nodeParent, Data isiTree, int cek_karakter);	//membuat rightChild pada Tree

void cetakTree(Data isiTree, int cek_karakter);	//mencetak isi dari tree

void pilihanTraversal(Root *root, int mode);	//pilihan traversal secara inorder, preorder, atau postorder
void preOrder(TreeNode *daunTree);		//traversal secara preOrder
void inOrder(TreeNode *daunTree);		//traversal secara inOrder
void postOrder(TreeNode *daunTree);		//traversal secara postOrder

void hapusSemuaTree(Root* root);			//hapus semua Tree melalui Root
void hapusNode(TreeNode *daunTree);			//hapus salah satu Node pada Tree

#endif
