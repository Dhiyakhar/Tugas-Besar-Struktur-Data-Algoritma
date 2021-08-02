/* 
Nama Kelompok : ROC 4
Nama Anggota :
1. Dhiya Fakhar Nafi (201524002)
2. Difa Moch Fadhilah (201524004)
3. Rijal Azmi
Kelas : 1A

Program yang dipilih : Kalkulator
Alasan : Mencari tantangan baru & mencoba mengimplementasikan ADT Tree

ADT yang digunakan :
1. ADT Tree (untuk menampung operator dan bilangan dalam bentuk struktur data Tree)
2. ADT Stack (untuk menampung operator dari operasi matematis)

Versi Program : 2.3 (Finalisasi Program pada fungsi beserta komentar penjelasannya)

Progres : 100% (Program 100%, perbaikan komentar 100%)
*/

#include <ctype.h> // untuk menggunakan fungsi 'isdigit()'
#include <math.h>  // untuk menggunakan fungsi 'pow()'
#include "Tree.h"
#include "Stack.h"

//Deklarasi struktur data dan variabel
char token;
Root *akar;	
Stack *stack_kalkulator;

/* Modul-modul Program "Utama" : */

//Nama modul : tampilanError
//Jenis modul : Prosedur
//Nama Penanggung Jawab : Dhiya Fakhar Nafi
//Tanggal/versi : 21 Juli 2021 
//Fungsi : Untuk menampilkan pesan error jika ada masukkan yang tidak sesuai

void tampilanError()	//modul untuk menampilkan pesan error
{
	printf("Input yang dimasukkan tidak diterima!");
	_Exit(0);
	
	//Fungsi _Exit() : Menghentikan program
	//sumber : https://iq.opengenus.org/ways-to-terminate-a-program-in-c/
}

//Nama modul : cekDanSetKarakter
//Jenis modul : prosedur
//Nama Penanggung Jawab : Dhiya Fakhar Nafi
//Tanggal/versi : 21 Juli 2021 
//Fungsi : Mengecek apakah karakter yang dimasukkan adalah operator dan angka.

void cekDanSetKarakter(char daunStack)
{
	if(daunStack != token){	
		tampilanError();	
	}
	
	token = getchar();	
}

//Nama modul : lingkaran
//Jenis modul : Prosedur
//Nama Penanggung Jawab : Difa Moch Fadhilah
//Tanggal/versi : 27 Juli 2021
//Fungsi : Modul untuk menghitung luas dan keliling lingkaran

void lingkaran()	
{
   int jari_jari;
   float luasLingkaran, kelilingLingkaran;
 
   printf("\nMasukkan jari-jari lingkaran : ");
   scanf("%d", &jari_jari);
 
   luasLingkaran = 3.14 * jari_jari * jari_jari;
   printf("\nLuas Lingkaran : %f", luasLingkaran);
   
   kelilingLingkaran = 2 * 3.14 * jari_jari;
   printf("\nKeliling Lingkaran : %f", kelilingLingkaran);
}	

//Nama modul : segitiga
//Jenis modul : Prosedur
//Nama Penanggung Jawab : Difa Moch Fadhilah
//Tanggal/versi : 27 Juli 2021
//Fungsi : Modul untuk menghitung luas dan keliling segitiga

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

//Nama modul : persegi_panjang
//Jenis modul : Prosedur
//Nama Penanggung Jawab : Difa Moch Fadhilah
//Tanggal/versi : 27 Juli 2021
//Fungsi : Modul untuk menghitung luas dan keliling persegi panjang
 
void persegi_panjang()
{
 int panjang, lebar, luasPP, kelilingPP;
 
   printf("\nMasukkan panjang Persegi Panjang : ");
   scanf("%d", &panjang);
 
   printf("\nMasukkan panjang lebar persegi panjang : ");
   scanf("%d", &lebar);
 
   luasPP = panjang * lebar;
   kelilingPP = 2 * (panjang + lebar);
   
   printf("Luas Persegi Panjang : %d", luasPP);
   printf("\nLuas Persegi Panjang : %d", kelilingPP);
}

//Nama modul : persegi
//Jenis modul : Prosedur
//Nama Penanggung Jawab : Difa Moch Fadhilah
//Tanggal/versi : 27 Juli 2021
//Fungsi : Modul untuk menghitung luas dan keliling persegi

void persegi()		
{
   int sisi, luasPersegi, kelilingPersegi;
	
   printf("\nMasukkan panjang sisi : ");
   scanf("%d", &sisi);
 
   luasPersegi = sisi * sisi;
   kelilingPersegi = 4 * sisi;
   
   printf("Luas Persegi : %d", luasPersegi);
   printf("\nKeliling Persegi : %d", kelilingPersegi);
}

//Nama modul : jumlahBilanganAsli
//Jenis modul : Prosedur
//Nama Penanggung Jawab : Rijal Azmi
//Tanggal/versi : 27 Juli 2021
//Fungsi : Menghitung jumlah dari bilangan asli

void jumlahBilanganAsli() {	
    int bilangan_positif, i = 1, jumlah_positif = 0;

    printf("\nMasukkan bilangan positif : ");
    scanf("%d", &bilangan_positif);

    for (i = 1; i <= bilangan_positif; ++i) {	// Fungsi Rekursif
        jumlah_positif += i;
    }

    printf("Jumlah dari %d = %d", bilangan_positif, jumlah_positif);
}

//Nama modul : pangkat
//Jenis modul : Prosedur
//Nama Penanggung Jawab : Rijal Azmi
//Tanggal/versi : 27 Juli 2021
//Fungsi : Menghitung jumlah dari bilangan asli

void pangkat() {
    double angka, eksponen, hasil_pangkat;
    
    printf("\nMasukkan bilangan yang akan menjadi eksponen : ");
    scanf("%lf", &angka);
    printf("Masukkan bilangan positif yang akan menjadi eksponen : ");
    scanf("%lf", &eksponen);

    // Hitung operasi perpangkatan dengan fungsi 'pow' dari math.h
    hasil_pangkat = pow(angka, eksponen);

    printf("Hasil %.1lf pangkat %.1lf adalah %.2lf", angka, eksponen, hasil_pangkat);
}

//Nama modul : faktorial
//Jenis modul : Prosedur
//Nama Penanggung Jawab : Rijal Azmi
//Tanggal/versi : 27 Juli 2021
//Fungsi : Menghitung jumlah dari bilangan asli

void faktorial() {
    int i=1,f=1,faktorial;
 
  printf("\nMasukkan angka : ");
  scanf("%d",&faktorial);
 
  for(i=1;i<=faktorial;i++)	//fungsi rekursif faktorial
      f=f*i;
 
  printf("\nFaktorial dari %d adalah %d",faktorial,f);
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
	
	printf("PROGRAM KALKULATOR PREFIX/INFIX/POSTFIX & UMUM : ");
	printf("\n\nNama Kelompok: ROC 4 ");
	printf("\nAnggota Kelompok : ");
	printf("\n1. Dhiya Fakhar Nafi");
	printf("\n2. Difa Moch Fadhilah");
	printf("\n3. Rijal Azmi Oktavia Setiabudi");
	printf("\n\nMasukkan operasi matematis : ");
	
	/// buat Struktur Data Stack dan Tree
	akar = buatAkarDaun();				//Membuat Root Tree
	stack_kalkulator = buatStack();		//Membuat Stack

	/// proses
    token = getchar();	//untuk mendapatkan 'token' karakter
    value = jumlah();	//untuk mendapatkan 'token' angka
    
	
	while(!isEmpty(stack_kalkulator))	//Jika stack tidak kosong, ketika elemen stack dilepas, leaf pada tree dibuat
	{
		daunStack = pop(stack_kalkulator);
		
		while(daunStack.cek_karakter)	//pengecekan Stack untuk operator
		{
			// memasukkan operator pada Leaf Tree
			daun_tree = buatAnak(daun_tree, daunStack.data, daunStack.cek_karakter);
			
			if(akar->root == NULL)
			akar->root = daun_tree;
			daunStack = pop(stack_kalkulator);	
		}
		
		// memasukkan bilangan pada Leaf Tree
		daun_tree = buatAnak(daun_tree, daunStack.data, daunStack.cek_karakter);
		
		if(akar->root == NULL)		
		akar->root = daun_tree;
	}
	
	//mencetak operasi secara prefix, infix, atau postfix sesuai dengan kebutuhan
	int pilihan;	
	
	printf(" Masukkan pilihan : ");
	scanf("%d", &pilihan);
        switch (pilihan) {
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
	
	/* Konversi dari Desimal ke Heksadesimal, Octal, dan Biner */
	
	//Deklarasi Kamus Data
	int biner[10],i;   					//Deklarasi variabel i bertipe integer dan larik a berisi 10 elemen bertipe integer
	int hasil = (int) value;    		//Melakukan konversi dari tipe data double ke tipe data integer
	long pembagi, hasil_bagi;			//Deklarasi variabel pembagi dan hasil_bagi bertipe long
	long nilai_decimal = (long) value;	//Melakukan konversi dari tipe data double ke tipe data long
    int octal[100], j;					//Deklarasi variabel j bertipe integer dan larik octal bertipe integer berisi 100 elemen
    long desimal_hexa, pembagi_hexa;	//Deklarasi pembagi dan angka desimal untuk dikonversi ke Hexadesimal
    int a, b = 0;						//Deklarasi variabel a dan b pengganti i dan j
    char hexadesimal_hexa[100];			//Menampung Karakter Heksadesimal
    long hasilBagi_hexa = (long) value;	//Konversi Hasil Bagi dari tipe double ke tipe long
    
//Nama Penanggung Jawab : Rijal Azmi
//Tanggal/versi : 27 Juli 2021
//Fungsi : Menghitung jumlah dari bilangan asli

	for(i=0;hasil>0;i++)    			
		{    
			biner[i]= hasil % 2;  		
			hasil=hasil/2;    		
		}    
		
	printf("\n Biner : ");

	for(i=i-1;i>=0;i--)    			
	{    
	printf("%d",biner[i]);    			
	}
	
//Nama Penanggung Jawab : Rijal Azmi
//Tanggal/versi : 27 Juli 2021
//Fungsi : Menghitung jumlah dari bilangan asli

	i = 1;
    hasil_bagi = nilai_decimal;			
    
	while (hasil_bagi != 0)				
    {
        octal[i++] = hasil_bagi % 8;
        hasil_bagi = hasil_bagi / 8;	
    }
    
	printf("\n Octal : ");
    for (j = i - 1; j > 0; j--)		
        printf("%d", octal[j]);	
    
//Nama Penanggung Jawab : Rijal Azmi
//Tanggal/versi : 27 Juli 2021
//Fungsi : Menghitung jumlah dari bilangan asli

	while (hasilBagi_hexa != 0)
    {
        pembagi_hexa = hasilBagi_hexa % 16;
        if (pembagi_hexa < 10)
            hexadesimal_hexa[b++] = 48 + pembagi_hexa;
        else
            hexadesimal_hexa[b++] = 55 + pembagi_hexa;
        hasilBagi_hexa = hasilBagi_hexa / 16;
    }
	
	printf("\n Heksadesimal : ");
	
    for (a = b; a >= 0; a--)
            printf("%c", hexadesimal_hexa[a]);
	
	//Memilih Program perhitungan
	int num;
	
    printf("\nMasukkan pilihan : ");
    printf("\n1 : Menghitung luas dan keliling lingkaran");
    printf("\n2 : Menghitung luas dan keliling persegi");
    printf("\n3 : Menghitung luas dan keliling segitiga");
    printf("\n4 : Menghitung luas dan keliling persegi panjang");
    printf("\n5 : Menghitung jumlah dari bilangan asli");
    printf("\n6 : Menghitung hasil perpangkatan");
    printf("\n7 : Menghitung faktorial");
    printf("\n8 : Keluar Program");
    
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
            case 8:	//jika pengguna memilih untuk keluar
            	break;
        }

    hapusSemuaTree(akar);	//menghapus semua data dengan cara menghapus akar Tree
    return 0;
}


/* Modul-modul Program "Main" : */

//Nama modul : jumlah
//Jenis modul : Function
//Nama Penanggung Jawab : Dhiya Fakhar Nafi
//Tanggal/versi : 21 Juli 2021

//Fungsi :
//Push data di stack dengan metode post-fix
//Mempush operator penjumlahan dan pengurangan
//Mengecek apakah token (masukkan) adalah operator tambah atau kurang

double jumlah()
{
	double penghitung = kaliBagi();
	Data isiTree;
	
	while(token == '+' || token == '-')
	{
		
		if(token == '+')		//Mengecek apakah token adalah operator tambah
		{
			isiTree.operatorMatematis = '+';	
			cekDanSetKarakter('+');					
			penghitung += kaliBagi();				
			push(stack_kalkulator, isiTree, TRUE);	
		}
	
		else if(token == '-')	//Mengecek apakah token adalah operator tambah
		{
			isiTree.operatorMatematis = '-';		
			cekDanSetKarakter('-');					
			penghitung -= kaliBagi();			
			push(stack_kalkulator, isiTree, TRUE);
		}
		
	}
	return penghitung;	//mengembalikan penghitung
}

//Nama modul : kaliBagi
//Jenis modul : Function
//Nama Penanggung Jawab : Dhiya Fakhar Nafi
//Tanggal/versi : 21 Juli 2021

//Fungsi :
//push data di stack dengan metode post-fix
//untuk mempush operator perkalian dan pembagian
//Mengecek apakah token (masukkan) adalah operator pembagian atau perkalian

double kaliBagi()
{
	double penghitung = faktor();
	Data isiTree;
	
	while(token == '*' || token == '/')	//ketika token adalah tanda bintang (kali) dan bagi
	{
	
		if(token == '*')				//Mengecek apakah token adalah operator perkalian
		{
			isiTree.operatorMatematis = '*';
			cekDanSetKarakter('*');	
			penghitung *= faktor();	
			push(stack_kalkulator, isiTree, TRUE);
		}
	
		else if(token == '/')			//Mengecek apakah token adalah operator pembagian
		{
			isiTree.operatorMatematis = '/';
			cekDanSetKarakter('/');	
			penghitung /= faktor();	
			push(stack_kalkulator, isiTree, TRUE);
		}
	}
	return penghitung;	//mengembalikan operasi matematis yang masih tersedia
}

//Nama modul : faktor
//Jenis modul : Function
//Nama Penanggung Jawab : Dhiya Fakhar Nafi
//Tanggal/versi : 21 Juli 2021

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
		cekDanSetKarakter('(');	
		penghitung = jumlah();	
		cekDanSetKarakter(')');	
	}

	else if(token == '-')	//Mengecek apakah token adalah operator kurang
	{
		cekDanSetKarakter('-');	
		isiTree.operatorMatematis = '-';
		penghitung = -faktor();	
		push(stack_kalkulator, isiTree, TRUE);
		return penghitung;
	}
	
	else if(token == '+')	//Mengecek apakah token adalah operator tambah
	{
		cekDanSetKarakter('+');	
		return faktor();		//mengembalikan penghitung
	}
	
		/* Penjelasan fungsi dari sumber luar
	1. isdigit() : untuk mengecek apakah karakter yang dipassing adalah digit atau bukan
	2. ungetc(token, stdin) : Mengonversi karakter (char) ke bentuk data yang dapat diterima input
	
	sumber : https://www.programiz.com/c-programming/library-function/ctype.h/isdigit (1)
			 https://www.tutorialspoint.com/c_standard_library/c_function_ungetc.htm (2)
			 https://www.geeksforgeeks.org/isdigit-function-in-c-c-with-examples/(1)
	*/
	
	else if(isdigit(token))		//Untuk mengecek apakah karakter yang dipassing adalah digit atau bukan
	{
		ungetc(token, stdin);	//Mengonversi karakter (char) ke bentuk data yang dapat diterima input
		
		scanf("%lf", &penghitung);	//Menerima masukkan berupa operasi matematika yang diinginkan	
		isiTree.bilangan = penghitung;		
		push(stack_kalkulator, isiTree, FALSE);	
		token = getchar();	
	}
	
	else tampilanError();	//menampilkan error jika input tidak sesuai (bukan angka atau operator)
	return penghitung;		//mengembalikan nilai penghitung (operasi matematis)
}
