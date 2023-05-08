#include "header.h"

void gotoxy(int x, int y) {
    COORD coord;
     
    coord.X = x;
    coord.Y = y;
     
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int getScreenWidth() {
    CONSOLE_SCREEN_BUFFER_INFOEX _infoex = {0};
    HANDLE handleOfConsoleOutput = NULL;

    handleOfConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    _infoex.cbSize = sizeof(_infoex);
    GetConsoleScreenBufferInfoEx(handleOfConsoleOutput, &_infoex);

    return _infoex.srWindow.Right;
}

int getScreenHeight() {
    CONSOLE_SCREEN_BUFFER_INFOEX _infoex = {0};
    HANDLE handleOfConsoleOutput = NULL;

    handleOfConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    _infoex.cbSize = sizeof(_infoex);
    GetConsoleScreenBufferInfoEx(handleOfConsoleOutput, &_infoex);

    return _infoex.srWindow.Bottom;
}
void menu() {
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 229); // asalnya 125, lalu 229 - alternatifnya 245. Ada lagi 252 (merah) atau 249 (biru cerah).
	
    // Make the console windows become full-size
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	
	// Inisialisasi jendela cmd agar bersih
    system("cls");
	system("title Sicuker Gamestore"); //SetConsoleTitle("Sicuker Gamestore");
	char inputMenu;
	int _X = getScreenWidth() / 2 - 31;
	int _Y = getScreenHeight() / 2 - 9;

	system("cls");
	gotoxy(_X - 2, _Y);
	printf("========================================================================\n");
	gotoxy(_X + 25, _Y + 2);
	printf("KALKULATOR STANDAR\n");
	gotoxy(_X + 2, _Y+5);
	printf("\n\n");
	gotoxy(_X +2, _Y + 6);
	printf("Ekspresi");
	gotoxy(_X +20, _Y + 6);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
	gotoxy(_X +2, _Y + 7);
	printf("Matematika");
	gotoxy(_X +20, _Y + 7);
	printf("%c                                      %c\n",186,186);
	gotoxy(_X +2, _Y + 8);
	printf("Yang Dihitung");
	gotoxy(_X +20, _Y + 8);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
	gotoxy(_X +2, _Y + 9);
	printf("\n");
	gotoxy(_X +2, _Y + 10);
	printf("Hasil");
	gotoxy(_X +20, _Y + 10);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
	gotoxy(_X +2, _Y + 11);
	printf("Perhitungan");
	gotoxy(_X +20, _Y + 11);
	printf("%c                                      %c\n",186,186);
	gotoxy(_X +2, _Y + 12);
	printf("Ekspresi");
	gotoxy(_X +20, _Y + 12);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
	gotoxy(_X +2, _Y + 13);
	printf("\n\n");
	gotoxy(_X +2, _Y + 15);
	printf("Silakan tekan huruf Q untuk kembali ke home menu : \n");
	gotoxy(_X +2, _Y + 16);
	printf("Atau tekan huruf apapun selain Q untuk kembali menggunakan kalkualtor standar");
	gotoxy(_X - 2, _Y + 18);
	printf("========================================================================\n");
	gotoxy(_X + 22, _Y + 7);
		
	char infix[40];
    char postfix[40];
	char timeCalculation[64];
	int checkPostfix = 0;
	char inputUserStd = 48;
		
		scanf(" %[^\n]%*c", infix);
		
		if (checkPostfix == -1) {
			printf("Ekspresi tidak valid");
		}

		gotoxy(_X + 21, _Y + 11);
		printf(" %.2f", postfix);

		gotoxy(_X + 53, _Y + 15);
		scanf(" %c", &inputUserStd);
		
	menu:
		headerLayout(" ", "\t", "Main Menu Page\t");
		line(0);
		lineText('o', "\t\t\t\t1. Profile\t\t\t\t\t");
		lineText('o', "\t\t\t\t2. Medical Check Up\t\t\t\t");
		lineText('o', "\t\t\t\t3. Settings\t\t\t\t\t");
		lineText('o', "\t\t\t\t4. Credits\t\t\t\t\t");
		lineText('o', "\t\t\t\t5. History\t\t\t\t");
		lineText('o', "\t\t\t\t6. Help\t\t\t\t\t\t");
		lineText('o', "\t\t\t\t7. Exit\t\t\t\t\t\t");
		line(0);
		inputType(&inputMenu);
		
		switch(inputMenu) {
			case '0':
				exitProgram ();
				break;
				
			case '1':
				profile ();
				break;
				
			case '2':
				medicalCheckUp ();
				break;
				
//			case '3':
//				settings();
//				break;
				
//			case '4':
//				credits();
//				break;
				
//			case '5':
//				dataTransaction();
//				break;
				
//			case '6':
//				userHelp();
//				break;
				
			case '7':
				exitProgram();
				break;	
				
			default:
				errorMessage();
				goto menu;
				break;
		}
		
}

void medicalCheckUp () {
	
	Node *root = createNode("Apakah Anda mengalami sakit dada? (y/n) ");
    root->yes = createNode("Apakah sakit dada berlangsung lebih dari 5 menit? (y/n) ");
    root->no = createNode("Apakah Anda merasa sesak napas? (y/n) ");
    root->yes->yes = createNode("Anda menderita serangan jantung.");
    root->yes->no = createNode("Apakah Anda merasa pusing? (y/n) ");
    root->yes->no->yes = createNode("Anda menderita penyakit jantung koroner.");
    root->yes->no->no = createNode("Anda menderita angina.");
    root->no->yes = createNode("Anda menderita gagal jantung.");
    root->no->no = createNode("Apakah Anda merasa lelah? (y/n) ");
    root->no->no->yes = createNode("Anda menderita penyakit jantung bawaan.");
 
    startAnalysis(root);
}

void profile() {
	char inputProfile;
	
	profile:
		headerLayout(" ", "\t", "Profile Page\t");
		line(0);
		profileUser();
		line(0);
		lineText('o', "\t\t\t\t1. Update\t\t\t\t\t");
		lineText('o', "\t\t\t\t2. Delete\t\t\t\t\t");
		lineText('o', "\t\t\t\t3. Logout\t\t\t\t\t");
		lineText('o', "\t\t\t\t4. Back\t\t\t\t\t\t");
		line(0);
		inputType(&inputProfile);
		
		switch (inputProfile) {
//			case '0':
//				if (strcmp(logReg.userAdmin, "1") == 0) {
//					return adminPage();
//				}
//				else {
//					return menu();
//				}
//				break;
				
			case '1':
				updateProfileUser();
				break;
				
			case '2':
				deletesProfileUser();
				break;
				
			case '3':
				strcpy(logReg.userId, "");
				loginRegisterUser();
				break;
				
			case '4':
				if (strcmp(logReg.userAdmin, "1") == 0) {
					return adminPage();
				}
				else {
					return menu();
				}
				break;
				
			default:
				errorMessage();
				goto profile;
				break;
		}
}

void exitProgram() {
	char inputExit;
	
	exit:
		headerLayout("", "\t", "Exit Page\t");
		line(0);
		lineText('o', "\t\t\t Are you sure you want to exit?\t\t\t\t");
		line(0);
		lineText('o', "\t\t\t\t1. Yes\t\t\t\t\t\t");
		lineText('o', "\t\t\t\t2. No\t\t\t\t\t\t");
		line(0);
		inputType(&inputExit);
		
		switch(inputExit){
			case '1':
				line(0);
				line(2);
				exit(0);
				break;
				
			case '2':
				if (strcmp(logReg.userAdmin, "1") == 0) {
					adminPage();
				}
				else if (strcmp(logReg.userId, "") == 0) {
					loginRegisterUser();
				}
				else {
					menu();
				}
				break;
				
			default:
				errorMessage();
				goto exit;
				break;
		}
}
