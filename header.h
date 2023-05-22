#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
#include <time.h>
#include <stdbool.h>
#include <locale.h>
#define Nil NULL
#define info(P) (P)->info
#define next(P) (P)->next
#define prev(P) (P)->prev

typedef char* infotype;			// variable bentukan bernama infotype dengan tipe char*
typedef struct tElmtlist *alamat; // variable pointer yang akan menunjuk ke alamat yang nilainya bernilai tElmtlist
typedef struct tKarakterPenyakit *addressKarakterPenyakit;

typedef struct tElmtlist
{
	alamat prev;
	infotype info;
	alamat next;
	
} ElmtList;

typedef struct{
	char 	userId[50],
		  	user[50], 
			email[50], 
			password[50],
			userAdmin[50];
} User;

typedef struct tKarakterPenyakit {
    int id;
    char namaPenyakit[50];
    char karakteristik[100];
    addressKarakterPenyakit next;
} karakterPenyakit;

typedef struct Node *address;
typedef struct Node {
	char question[100];
	address yes, no;
} Node;
typedef struct jPenyakit *alamatJP; 
typedef struct jPenyakit
{
	alamatJP prev;
	infotype info;
	address tree;
	alamatJP next;
	
} jPenyakit;
FILE *file;
User dataUser, logReg, check;

//layout.c
void gotoxy(int x, int y);
int getScreenWidth();
int getScreenHeight();
void layoutXY(int layoutType);
void printBanner ();
void printASCIIforBanner(char ch);

//loginRegister.c
void loginUser();
void registerUser();
void updateProfileUser();
void deletesProfileUser();

//admin.c
void adminPage ();
void userData ();
void updateAdmin ();
void deleteAdmin ();

//user.c
void userPage ();
void medicalCheckUp ();

//body.c
boolean isEmpty (address root);
Node* createNode (char question[]);
void deleteTree (Node *root);
void printNode (char leaf[]);
char* startAnalysis (address root);
void medicalCheckUpResults (char* diseaseResult);
void medicalCheckUpRecommendation ();
void medicalCheckUpDisclaimer ();
alamat createlist(char* huruf);
address rootPenyakit;
void insLast(alamat *P, alamat *Last);
void viewAsc(alamat First);
alamat inputPertanyaan();
void deleteTree(Node *root);
alamat searchList(alamat First, int noPertanyaan);
void simpanPertanyaan(alamat pPertanyaan,alamat pDiagnosis);
void createTree(alamat First);
void menuPertanyaan(alamat First);
void assignNo(address nodeTree, char pertanyaan[]);
void assignYes(address nodeTree, char pertanyaan[]);
void printLine(int space);
void printTree(address node, int space);
alamatJP pLastJP;
void simpanRoot(char root[]);
void simpanJPtoSkema(char jenisPenyakit[]);
alamatJP pFirstJP;
alamatJP searchJP(char jenPenyakit[]);
void simpanJenisPenyakit(char jenisPenyakit[]);
//karakterPenyakit
void karakteristikPenyakit();
addressKarakterPenyakit createNodePenyakit(int id, char* namaPenyakit, char* karakteristik);
void insertNode(addressKarakterPenyakit *head, int id, char* namaPenyakit, char* karakteristik);
void deleteNode(addressKarakterPenyakit *head, int id);
void updateNode(addressKarakterPenyakit *head, int id, char* namaPenyakit, char* karakteristik);
void displayList(addressKarakterPenyakit head);
void saveListToFile(addressKarakterPenyakit head, char* filename);
void loadListFromFile(addressKarakterPenyakit *head, char* filename);

//cariPenyakit
void cariPertanyaanJenisPenyakit(const char* nama_file, const char* jenis_penyakit, const char* nomor_pertanyaan);
void cariFilePenyakit();
