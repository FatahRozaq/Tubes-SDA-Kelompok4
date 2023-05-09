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
	char inputMenu;
	system ("cls");
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
