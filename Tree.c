#include "Tree.h"

Root* buatAkarDaun()
{
	Root* tampung = (Root*)calloc(sizeof(Root), 1);
	if(!tampung) {
		printf("Alokasi memori gagal!");
		exit(1);
	}
	return tampung;
}

TreeNode* buatDaunPohon()
{
	TreeNode* tampung = (TreeNode*)calloc(sizeof(TreeNode), 1);
	if(!tampung){
		puts("Alokasi memori gagal!");
		exit(1);
	}
	return tampung;
}

TreeNode* buatAnak(TreeNode *nodeParent, Data isiTree, int cek_karakter)
{
	if(!nodeParent)
	{
		nodeParent = buatDaunPohon();
		nodeParent->data = isiTree;
		nodeParent->cek_karakter = cek_karakter;
		return nodeParent;
	}
	
	if(nodeParent->left && nodeParent->right)
	{
		nodeParent = nodeParent->parent;
		
		if(!nodeParent)	
		return NULL;
		
		return buatAnak(nodeParent, isiTree, cek_karakter);
	}

	if(!cek_karakter) // bilanganber, from right. return self node pointer.
	{
		if(nodeParent->right)
		{
			buatAnakKiri(nodeParent, isiTree, cek_karakter);
		}
		else
		{
			buatAnakKanan(nodeParent, isiTree, cek_karakter);
		}
		return nodeParent;
	}
	
	else // operator, from left. return its child node pointer.
	{

		if(nodeParent->left)
		{
			buatAnakKanan(nodeParent, isiTree, cek_karakter);
			return nodeParent->right;
		}

		else
		{
			buatAnakKiri(nodeParent, isiTree, cek_karakter);
			return nodeParent->left;
		}
	}
	
}

void buatAnakKiri(TreeNode *nodeParent, Data isiTree, int cek_karakter)
{
	TreeNode* tampung = buatDaunPohon();
	
	if(!tampung)	
	return;
	
	tampung->data = isiTree;
	tampung->cek_karakter = cek_karakter;
	nodeParent->left = tampung;
	tampung->parent = nodeParent;
}

void buatAnakKanan(TreeNode *nodeParent, Data isiTree, int cek_karakter)
{
	TreeNode* tampung = buatDaunPohon();
	if(!tampung)	
	return;
	
	tampung->data = isiTree;
	tampung->cek_karakter = cek_karakter;
	nodeParent->right = tampung;
	tampung->parent = nodeParent;
}

void cetakTree(Data isiTree, int cek_karakter)
{
	if(cek_karakter) {
		printf("%c", isiTree.operatorMatematis);
	}
	else {
		printf("%g", isiTree.bilangan);
	}
}

void pilihanTraversal(Root *root, int mode)
{
	TreeNode *tampung = root->root;
	
	switch(mode)
	{
		case PREORDER:
			preOrder(tampung);
			break;
		case INORDER:
			inOrder(tampung);
			break;
		case POSTORDER:
			postOrder(tampung);
			break;
	}
}

void preOrder(TreeNode *daunTree)
{
	if(!daunTree)	
	return;
	
	cetakTree(daunTree->data, daunTree->cek_karakter);
	preOrder(daunTree->left);
	preOrder(daunTree->right);
}

void inOrder(TreeNode *daunTree)
{
	if(!daunTree)	
	return;
	
	inOrder(daunTree->left);
	cetakTree(daunTree->data, daunTree->cek_karakter);
	inOrder(daunTree->right);
}

void postOrder(TreeNode *daunTree)
{
	if(!daunTree)	
	return;
	
	postOrder(daunTree->left);
	postOrder(daunTree->right);
	cetakTree(daunTree->data, daunTree->cek_karakter);
}

void hapusNode(TreeNode *daunTree)
{
	if(!daunTree)	
	return;
	
	hapusNode(daunTree->left);
	hapusNode(daunTree->right);
	free(daunTree);
}

void hapusSemuaTree(Root* root)
{
	hapusNode(root->root);
}
