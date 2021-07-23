#include <ctype.h> // for 'isdigit()'
#include "Tree.h"
#include "Stack.h"

char token; // variable for reading a charactor
Root *akar;
Stack *stack_kalkulator;

void tampilanError()
{
	printf("Input yang dimasukkan tidak diterima!");
	exit(1);
}

void cekDanSetKarakter(char daunStack)
{
	if(daunStack != token){
		tampilanError();
	}
	
	token = getchar();
}

double kaliBagi();
double jumlah();
double faktor();

int main()
{
	double value;
	StackNode daunStack;
	TreeNode *daun_tree = NULL;
	
	/// make data structures for each cases
	akar = buatAkarDaun();
	stack_kalkulator = buatStack();

	/// process
    token = getchar();
    value = jumlah();
    
	// now, stack is already built

	/// construct tree
	while(!isEmpty(stack_kalkulator))
	{
		// As the stack is being removed, constructs tree
		daunStack = pop(stack_kalkulator);
		
		while(daunStack.cek_karakter)
		{
			// operator
			daun_tree = buatAnak(daun_tree, daunStack.data, daunStack.cek_karakter);
			
			if(akar->root == NULL)	
			akar->root = daun_tree;
			daunStack = pop(stack_kalkulator);
		}
		
		// bilangan
		daun_tree = buatAnak(daun_tree, daunStack.data, daunStack.cek_karakter);
		
		if(akar->root == NULL)	
		akar->root = daun_tree;
	}
	
    /// printing
    printf("\n Prefix : ");
    pilihanTraversal(akar, PREORDER);
    
    printf("\n Infix : ");
    pilihanTraversal(akar, INORDER);
    
    printf("\n Postfix : ");
    pilihanTraversal(akar, POSTORDER);
    
    printf("\n Hasil operasi Matematis : %g\n", value);

    /// delete
    hapusSemuaTree(akar);
    return 0;
}

/** \brief
 * push data in the stack with the method of post-fix
 * calculate addition and subtraction
 */
double jumlah()
{
	double penghitung = kaliBagi();
	Data isiTree;
	
	while(token == '+' || token == '-')
	{
		
		if(token == '+')
		{
			isiTree.operatorMatematis = '+';
			cekDanSetKarakter('+');
			penghitung += kaliBagi();
			push(stack_kalkulator, isiTree, TRUE);
		}
	
		else if(token == '-')
		{
			isiTree.operatorMatematis = '-';
			cekDanSetKarakter('-');
			penghitung -= kaliBagi();
			push(stack_kalkulator, isiTree, TRUE);
		}
		
	}
	return penghitung;
}

/** \brief
 * push data in the stack with the method of post-fix
 * calculate multiple and devision
 */
double kaliBagi()
{
	double penghitung = faktor();
	Data isiTree;
	
	while(token == '*' || token == '/')
	{
	
		if(token == '*')
		{
			isiTree.operatorMatematis = '*';
			cekDanSetKarakter('*');
			penghitung *= faktor();
			push(stack_kalkulator, isiTree, TRUE);
		}
	
		else if(token == '/')
		{
			isiTree.operatorMatematis = '/';
			cekDanSetKarakter('/');
			penghitung /= faktor();
			push(stack_kalkulator, isiTree, TRUE);
		}
	}
	return penghitung;
}

/** \brief
 * push data in the stack with the method of post-fix
 * regards faktor as a bilanganber
 */
double faktor()
{
	double penghitung = 0.0;
	Data isiTree;
	
	if(token == '(')
	{
		// start with new jumlah again
		cekDanSetKarakter('(');
		penghitung = jumlah();
		cekDanSetKarakter(')');
	}

	else if(token == '-')
	{
		// negation
		cekDanSetKarakter('-');
		isiTree.operatorMatematis = '-';
		penghitung = -faktor();
		push(stack_kalkulator, isiTree, TRUE);
		return penghitung;
	}
	
	else if(token == '+')
	{
		// there is no meaning, but just exception dealing
		cekDanSetKarakter('+');
		return faktor();
	}

	else if(isdigit(token))
	{
		ungetc(token, stdin);
		
		scanf("%lf", &penghitung);
		isiTree.bilangan = penghitung;
		push(stack_kalkulator, isiTree, FALSE);
		token = getchar();
	}
	
	else tampilanError();
	return penghitung;
}
