#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
#include <time.h>
#include <stdbool.h>
#include <locale.h>

typedef struct{
	char 	userId[50],
		  	user[50], 
			email[50], 
			password[50],
			userAdmin[50];
} User;

typedef struct Node *address;
typedef struct Node {
	char question[100];
	address yes, no;
} Node;

FILE *file;
User dataUser, logReg, check;

//layout.c
void line(int lineType);
void lineText(char textType, char lineName[50]);
void headerLayout(char leftHeader[50], char leftHeader2[50], char title[50]);
void errorMessage();
void inputType(char *typeHere);
void layoutXY(int layoutType);

//loginRegister.c
void loginRegisterUser();
void loginUser();
void registerUser();
void profileUser();
void updateProfileUser();
void deletesProfileUser();
void helpLoginRegister();
void errorMessageEmail();

//admin.c
void adminPage ();
void userData ();
void updateAdmin ();
void deleteAdmin ();

//user.c
void menu ();
void medicalCheckUp ();
void profile ();
void exitProgram ();
void gotoxy(int x, int y);
int getScreenWidth();
int getScreenHeight();

//body.c
boolean isEmpty (address root);
Node* createNode (char question[]);
void deleteTree (Node *root);
void printNode (char leaf[]);
char* startAnalysis (Node *root);
void medicalCheckUpResults ();
void medicalCheckUpRecommendation ();
void medicalCheckUpDisclaimer ();
