#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include "Common.h"

typedef struct TreeNode
{
	int cek_karakter;
	Data data;
	
	struct TreeNode *parent;
	struct TreeNode *left;
	struct TreeNode *right;
} TreeNode;

typedef struct Root
{
	TreeNode *root;
} Root;

Root* buatAkarDaun();		//
TreeNode* buatDaunPohon();	//
TreeNode* buatAnak(TreeNode *nodeParent, Data isiTree, int cek_karakter);	//

void buatAnakKiri(TreeNode *nodeParent, Data isiTree, int cek_karakter);	//
void buatAnakKanan(TreeNode *nodeParent, Data isiTree, int cek_karakter);	//

void cetakTree(Data isiTree, int cek_karakter);	//

void pilihanTraversal(Root *root, int mode);			//
void preOrder(TreeNode *daunTree);		//
void inOrder(TreeNode *daunTree);		//
void postOrder(TreeNode *daunTree);		//

void hapusSemuaTree(Root* root);			//
void hapusNode(TreeNode *daunTree);			//

#endif
