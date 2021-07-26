#include <ctype.h> // untuk menggunakan fungsi 'isdigit()'
#include <math.h>  // untuk menggunakan fungsi 'pow()'
#include "Tree.h"
#include "Stack.h"

//Deklarasi struktur data dan variabel
char token; // variabel untuk membaca karakter seperti operator matematis
Root *akar;	// Root dari Tree yaitu Akar
Stack *stack_kalkulator;	//Stack untuk menampung operator dari kalkulator

/* Modul-modul Program : */

//Nama modul :
//Jenis modul :
//Nama Penanggung Jawab :
//Tanggal/versi :

//Fungsi :

void tampilanError()	//modul untuk menampilkan pesan error
{
	printf("Input yang dimasukkan tidak diterima!");
	exit(1);	
	
	//Fungsi exit() : menghentikan proses pemanggilan modul
	//sumber :https://www.tutorialspoint.com/c_standard_library/c_function_exit.htm
}

/* Modul-modul Program : */

//Nama modul :
//Jenis modul :
//Nama Penanggung Jawab :
//Tanggal/versi :

//Fungsi :

void cekDanSetKarakter(char daunStack)	//Mengecek apakah elemen stack merupakan bilangan atau operator
{
	if(daunStack != token){	//jika leaf pada Stack bukan token (operator atau bilangan)
		tampilanError();	//menampilkan pesan error
	}
	
	token = getchar();		//mengambil token (elemen stack) berupa bilangan atau operator
}

/* Modul-modul Program : */

//Nama modul :
//Jenis modul :
//Nama Penanggung Jawab :
//Tanggal/versi :

//Fungsi :

void lingkaran()
{
   int jari_jari;
   float luasLingkaran, kelilingLingkaran;
 
   printf("\nMasukkan jari-jari lingkaran : ");
   scanf("%d", &jari_jari);
 
   luasLingkaran = 3.14 * jari_jari * jari_jari;
   printf("Luas Lingkaran : %f", luasLingkaran);
   
   luasLingkaran = 2 * 3.14 * jari_jari;
   printf("Keliling Lingkaran : %f", kelilingLingkaran);
}

/* Modul-modul Program : */

//Nama modul :
//Jenis modul :
//Nama Penanggung Jawab :
//Tanggal/versi :

//Fungsi :

void segitiga()
{
   int alas, tinggi, panjang1, panjang2, panjang3;
   float luasSegitiga, kelilingSegitiga;
 
   printf("\nMasukkan panjang alas segitiga : ");
   scanf("%d", &alas);
 
   printf("Masukkan panjang tinggi segitiga : ");
   scanf("%d", &tinggi);
 
   luasSegitiga = 0.5 * alas * tinggi;
   printf("\nLuas Segitiga : %f", luasSegitiga);
   
   printf("\nMasukkan panjang tinggi segitiga : ");
   scanf("%d", &panjang1);
   
   printf("Masukkan panjang tinggi segitiga : ");
   scanf("%d", &panjang2);
   
   printf("Masukkan panjang tinggi segitiga : ");
   scanf("%d", &panjang3);
   
   luasSegitiga = 0.5 * alas * tinggi;
   kelilingSegitiga = panjang1 + panjang2 + panjang3;
   
   printf("\nLuas Segitiga : %f", luasSegitiga);
   printf("\nKeliling Segitiga : %f", kelilingSegitiga);
}
 
/* Modul-modul Program : */

//Nama modul :
//Jenis modul :
//Nama Penanggung Jawab :
//Tanggal/versi :

//Fungsi :
 
void persegi_panjang()
{
 int panjang, lebar, luasPP, kelilingPP;
 
   printf("\nMasukkan panjang Persegi Panjang : ");
   scanf("%d", &panjang);
 
   printf("Masukkan panjang lebar persegi panjang : ");
   scanf("%d", &lebar);
 
   luasPP = panjang * lebar;
   kelilingPP = 2 * (panjang + lebar);
   
   printf("Luas Persegi Panjang : %d", luasPP);
   printf("Luas Persegi Panjang : %d", kelilingPP);
}

/* Modul-modul Program : */

//Nama modul :
//Jenis modul :
//Nama Penanggung Jawab :
//Tanggal/versi :

//Fungsi :

void persegi()
{
   int sisi, luasPersegi, kelilingPersegi;
	
   printf("\nMasukkan panjang sisi : ");
   scanf("%d", &sisi);
 
   luasPersegi = sisi * sisi;
   kelilingPersegi = 4 * sisi;
   
   printf("Luas Persegi : %d", luasPersegi);
   printf("Keliling Persegi : %d", kelilingPersegi);
}

/* Modul-modul Program : */

//Nama modul :
//Jenis modul :
//Nama Penanggung Jawab :
//Tanggal/versi :

//Fungsi :

void jumlahBilanganAsli() {	//Menghitung jumlah dari bilangan asli
    int bilangan_positif, i = 1, jumlah_positif = 0;

    printf("\nMasukkan bilangan positif : ");
    scanf("%d", &bilangan_positif);

    for (i = 1; i <= bilangan_positif; ++i) {	//Rekursif
        jumlah_positif += i;
    }

    printf("Jumlah dari %d = %d", bilangan_positif, jumlah_positif);
}

/* Modul-modul Program : */

//Nama modul :
//Jenis modul :
//Nama Penanggung Jawab :
//Tanggal/versi :

//Fungsi :

void pangkat() {	//Menghitung jumlah dari bilangan asli
    double angka, eksponen, hasil_pangkat;
    
    printf("\nMasukkan bilangan yang akan menjadi eksponen : ");
    scanf("%lf", &angka);
    printf("Masukkan bilangan positif yang akan menjadi eksponen : ");
    scanf("%lf", &eksponen);

    // Hitung operasi perpangkatan dengan fungsi 'pow' dari math.h
    hasil_pangkat = pow(angka, eksponen);

    printf("%.1lf^%.1lf = %.2lf", angka, eksponen, hasil_pangkat);
}

/* Modul-modul Program : */

//Nama modul :
//Jenis modul :
//Nama Penanggung Jawab :
//Tanggal/versi :

//Fungsi :

void faktorial() {	//Menghitung jumlah dari bilangan asli
    int i=1,f=1,faktorial;
 
  printf("\nMasukkan angka : ");
  scanf("%d",&faktorial);
 
  for(i=1;i<=faktorial;i++)
      f=f*i;
 
  printf("Faktorial dari %d adalah %d",faktorial,f);
}


//Deklarasi 3 function
double kaliBagi();	//Modul perkalian dan pembagian
double jumlah();	//Modul penjumlahan dan perkalian
double faktor();	//Modul pemfaktoran

int main()
{
	double value;					//Deklarasi value untuk menampung hasil operasi matematika
	StackNode daunStack;			//Objek stack bernama daunStack
	TreeNode *daun_tree = NULL;		//Objek tree bernama daun_tree
	
	printf("\n Masukkan operasi matematis : ");
	
	/// buat Struktur Data Stack dan Tree
	akar = buatAkarDaun();				//Membuat Root Tree
	stack_kalkulator = buatStack();		//Membuat Stack

	/// proses
    token = getchar();	//untuk mendapatkan 'token' karakter
    value = jumlah();	//untuk mendapatkan 'token' angka
    
	
	while(!isEmpty(stack_kalkulator))	//Jika stack tidak kosong
	{
		//ketika elemen stack dilepas, leaf pada tree dibuat
		daunStack = pop(stack_kalkulator);
		
		while(daunStack.cek_karakter)	//pengecekan Stack untuk operator
		{
			// memasukkan operator pada Leaf Tree
			daun_tree = buatAnak(daun_tree, daunStack.data, daunStack.cek_karakter);
			
			if(akar->root == NULL)	//jika akar Tree NULL
			akar->root = daun_tree;	//akar Tree membuat anak baru
			daunStack = pop(stack_kalkulator);	//daun stack berisi elemen stack yang baru dilepas (pop)
		}
		
		// memasukkan bilangan pada Leaf Tree
		daun_tree = buatAnak(daun_tree, daunStack.data, daunStack.cek_karakter);
		
		if(akar->root == NULL)		//jika akar Tree NULL
		akar->root = daun_tree;		//akar Tree membuat anak baru
	}
	
	//mencetak operasi secara prefix, infix, atau postfix
	int pilihan;	//Deklarasi pilihan
	
	printf(" Masukkan pilihan : ");
	scanf("%d", &pilihan);
        switch (pilihan) {	//memilih print secara prefix, infix, atau postfix
            case 1:
                printf("1. Prefix : ");
   				pilihanTraversal(akar, 1);	//mencetak data secara preorder
   				break;
                
            case 2:
                printf("2. Infix : ");
    			pilihanTraversal(akar, 2);	//mencetak data secara inorder
    			break;
                
            case 3:
                printf("3. Postfix : ");
 			   	pilihanTraversal(akar, 3);	//mencetak data secara postorder
 			   	break;
 			   	
            default:
                printf("Masukkan angka yang benar!");
                break;
        }
	
    printf("\n Hasil operasi Matematis : %g", value);
	
//KONVERSI KE HEXA BINER DAN OCTAL
	//Deklarasi Kamus Data
	int biner[10],i;   					//Deklarasi variabel i bertipe integer dan larik a berisi 10 elemen bertipe integer
	int hasil = (int) value;    		//melakukan konversi dari tipe data double ke tipe data integer
	long pembagi, hasil_bagi;			//Deklarasi variabel pembagi dan hasil_bagi bertipe long
	long nilai_decimal = (long) value;	//melakukan konversi dari tipe data double ke tipe data long
    int octal[100], j;					//Deklarasi variabel j bertipe integer dan larik octal bertipe integer berisi 100 elemen
	char hexadesimal[100];				//Deklarasi variabel hexadesimal bertipe larik (array) untuk menampung nilai heksadesimal hasil konversi dari desimal
    hasil_bagi = nilai_decimal;			//hasil bagi diassign dengan nilai desimal hasil operasi matematis
    
	for(i=0;hasil>0;i++)    			//selama hasilnya lebih dari 0
		{    
			biner[i]= hasil % 2;  		//sisa dari hasil pembagian 2 diassign ke array
			hasil=hasil/2;    			//hasil dibagi 2
		}    
		
	printf("\n Biner : ");
	for(i=i-1;i>=0;i--)    				//selama i tidak kurang dari 0
	{    
	printf("%d",biner[i]);    			//cetak isi larik a yang berisi nilai biner
	}
	
	//Modul octal
	i = 1;
    hasil_bagi = nilai_decimal;			//hasil bagi diassign dengan nilai desimal hasil operasi matematis
    
	while (hasil_bagi != 0)				//Selama hasil baginya belum 0
    {
        octal[i++] = hasil_bagi % 8;	//sisa pembagian hasil bagi dari 8 dimasukkan ke array octal
        hasil_bagi = hasil_bagi / 8;	//hasil bagi dibagi dengan 8
    }
    
	printf("\n Octal : ");
    for (j = i - 1; j > 0; j--)			//selama elemen pada array Octal masih ada
        printf("%d", octal[j]);			//menampilkan hasil konversi dari desimal ke octal
    
    /*
    //Modul heksa (BELUM FINAL!)
	i = 0;
	j = 0;
	
    while (hasil_bagi != 0)						//selama hasil baginya belum 0
    {
        pembagi = hasil_bagi % 16;				//nilai pembagi berasal dari sisa hasil bagi yang dibagi 16
        
        if (pembagi < 10)						//jika pembaginya kurang dari 10
            hexadesimal[j++] = 48 + pembagi;	//array heksadesimal berisi nilai pembagi ditambah 48
        else
            hexadesimal[j++] = 55 + pembagi;	//array heksadesimal berisi nilai pembagi ditambah 48
            
        hasil_bagi = hasil_bagi / 16;			//hasil bagi dibagi 16
    }
    
	// menampilkan heksadesimal
    for (i = j; i >= 0; i--)	//untuk semua elemen heksadesimal
            printf("\n Heksadesimal : %c", hexadesimal[i]);
            */
            
	//MODUL LUAS KELILING
	int num;
    printf("\nMasukkan pilihan : ");
    printf("\n1 : Menghitung luas dan keliling lingkaran");
    printf("\n2 : Menghitung luas dan keliling persegi");
    printf("\n3 : Menghitung luas dan keliling segitiga");
    printf("\n4 : Menghitung luas dan keliling persegi panjang");
    printf("\n5 : Menghitung jumlah dari bilangan asli");
    printf("\n6 : Menghitung hasil perpangkatan");
    printf("\n7 : Menghitung faktorial");
    
    printf("\n\nPilihan : ");
	scanf("%d", &num);
	
        switch (num) {
            case 1:
                lingkaran();
                break;
            case 2:
                persegi();
                break;
            case 3:
                segitiga();
                break;
            case 4:
                persegi_panjang();
                break;
            case 5:
                jumlahBilanganAsli();
                break;   
            case 6:
                pangkat();
                break; 
			case 7:
                faktorial();
                break;     
            default:
            	break;
        }

    hapusSemuaTree(akar);	//menghapus semua data dengan cara menghapus akar Tree
    return 0;
}


/* Modul-modul Program : */

//Nama modul :
//Jenis modul :
//Nama Penanggung Jawab :
//Tanggal/versi :

//Fungsi :
//push data di stack dengan metode post-fix
//mempush operator penjumlahan dan pengurangan
double jumlah()
{
	double penghitung = kaliBagi();
	Data isiTree;
	
	while(token == '+' || token == '-')	//ketika operator merupakan penjumlahan atau pengurangan
	{
		
		if(token == '+')		//jika token adalah operator tambah
		{
			isiTree.operatorMatematis = '+';		//Assign operatorMatematis dengan karakter tambah
			cekDanSetKarakter('+');					//Memeriksa apakah tambah adalah operator
			penghitung += kaliBagi();				//mengurangi elemen pada penghitung (operasi matematis)
			push(stack_kalkulator, isiTree, TRUE);	//melakukan push elemen tambah (+) pada stack
		}
	
		else if(token == '-')	//jika token adalah operator tambah
		{
			isiTree.operatorMatematis = '-';		//Assign operatorMatematis dengan karakter kurang
			cekDanSetKarakter('-');					//Memeriksa apakah karakter kurang adalah operator
			penghitung -= kaliBagi();				//mengurangi elemen pada penghitung (operasi matematis)
			push(stack_kalkulator, isiTree, TRUE);	//melakukan push elemen tambah (-) pada stack
		}
		
	}
	return penghitung;	//mengembalikan penghitung
}

//Nama modul :
//Jenis modul :
//Nama Penanggung Jawab :
//Tanggal/versi :

//Fungsi :
//push data di stack dengan metode post-fix
//untuk mempush operator perkalian dan pembagian

double kaliBagi()
{
	double penghitung = faktor();
	Data isiTree;
	
	while(token == '*' || token == '/')	//ketika token adalah tanda bintang (kali) dan bagi
	{
	
		if(token == '*')
		{
			isiTree.operatorMatematis = '*';		//Assign operatorMatematis dengan karakter tersebut
			cekDanSetKarakter('*');					//Memeriksa apakah karakter adalah operator
			penghitung *= faktor();					//mengurangi elemen pada penghitung (operasi matematis)
			push(stack_kalkulator, isiTree, TRUE);	//melakukan push elemen perkalian (*) pada stack
		}
	
		else if(token == '/')
		{
			isiTree.operatorMatematis = '/';		//Assign operatorMatematis dengan karakter tersebut
			cekDanSetKarakter('/');					//Memeriksa apakah karakter adalah operator
			penghitung /= faktor();					//mengurangi elemen pada penghitung (operasi matematis)
			push(stack_kalkulator, isiTree, TRUE);	//melakukan push elemen pembagian (/) pada stack
		}
	}
	return penghitung;	//mengembalikan operasi matematis yang masih tersedia
}

//Nama modul :
//Jenis modul :
//Nama Penanggung Jawab :
//Tanggal/versi :

//Fungsi :
//push data di stack dengan metode post-fix
//untuk mempush operator tambah dan kurang
//untuk membuang operator kurung buka dan tutup
double faktor()
{
	double penghitung = 0.0;	//Deklarasi penghitung untuk menampung angka dan operator
	Data isiTree;				//Data bernama isiTree
	
	if(token == '(')	//Memastikan tanda kurung tidak masuk ke dalam notasi prefix, postfix, dan infix
	{
		cekDanSetKarakter('(');	//kurung buka
		penghitung = jumlah();	//operasi matematis melakukan pengecekan pada operasi jumlah dan pengurangan
		cekDanSetKarakter(')');	//kurung tutup
	}

	else if(token == '-')
	{
		cekDanSetKarakter('-');					//Memeriksa apakah karakter kurang adalah operator
		isiTree.operatorMatematis = '-';		//Assign operatorMatematis dengan karakter kurang
		penghitung = -faktor();					//mengurangi elemen pada penghitung (operasi matematis)
		push(stack_kalkulator, isiTree, TRUE);	//melakukan push elemen tambah (-) pada stack
		return penghitung;						//mengembalikan penghitung
	}
	
	else if(token == '+')
	{
		cekDanSetKarakter('+');	//Memeriksa apakah karakter kurang adalah operator
		return faktor();		//mengembalikan penghitung
	}
	
	//fungsi isdigit() : untuk mengecek apakah karakter yang dipassing adalah digit atau bukan
	//sumber : https://www.geeksforgeeks.org/isdigit-function-in-c-c-with-examples/
	else if(isdigit(token))	
	{
		ungetc(token, stdin);	//Mengonversi karakter (char) ke bentuk data yang dapat diterima input
		
		scanf("%lf", &penghitung);				//membaca input operasi matematis
		isiTree.bilangan = penghitung;			//Assign operasi matematis
		push(stack_kalkulator, isiTree, FALSE);	//mempush elemen operasi matematis ke Stack
		token = getchar();						//mengambil elemen token
	}
	
	else tampilanError();	//menampilkan error jika input tidak sesuai (bukan angka atau operator)
	return penghitung;		//mengembalikan nilai penghitung (operasi matematis)
}
