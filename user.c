#include "header.h"

void userPage () {
	char inputUserPage;
	int _X = getScreenWidth() / 2 - 70, _Y = getScreenHeight() / 2 - 16, menu = 1, profile = 1;
	
	system ("cls");
	for (;;) {
		layoutXY (3);
		
		gotoxy(_X + 28, _Y + 26);
		scanf (" %c", &inputUserPage); fflush (stdin);
		if (inputUserPage == 'm' || inputUserPage == 'M') {
			if (menu == 1) {
				Menu:
				menu = 0;
				gotoxy(_X + 55, _Y + 14);
				printf ("%c       Medical Check Up (S)       %c", 186, 186);
				gotoxy(_X + 55, _Y + 15);
				printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205, 205, 205, 205, 205,205,205,205,205 ,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205, 205, 205,188);
		
				gotoxy(_X + 55, _Y + 16);
				printf ("%c           BANTUAN (B)            %c", 186, 186);
				gotoxy(_X + 55, _Y + 17);
				printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205, 205, 205, 205, 205,205,205,205,205 ,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205, 205, 205,188);
		
				gotoxy(_X + 55, _Y + 18);
				printf ("%c         TENTANG KAMI (T)         %c", 186, 186);
				gotoxy(_X + 55, _Y + 19);
				printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205, 205, 205, 205, 205,205,205,205,205 ,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205, 205, 205,188);
		
				gotoxy(_X + 55, _Y + 20);
				printf ("%c             EXIT (X)             %c", 186, 186);
				gotoxy(_X + 55, _Y + 21);
				printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205, 205, 205, 205, 205,205,205,205,205 ,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205, 205, 205,188);
	
			}
			else {
				menu = 1;
				system ("cls");
				if (profile == 0) {
					goto Profile;
				}
			}
		}
		else if (inputUserPage == 'p' || inputUserPage == 'P') {
			if (profile == 1) {
				Profile:
				profile = 0;
				char id[50];
								
				strcpy(id, logReg.userId);
			    file = fopen("user.txt", "r");
			    while (!feof(file)){
					fscanf(file,"%[^_]_%[^_]_%[^_]_%[^_]_%[^\n]\n",&dataUser.user, &dataUser.userId, &dataUser.email, &dataUser.password, &dataUser.userAdmin);
					fflush(stdin);
					if(strcmp(id, dataUser.userId) == 0){
						gotoxy(_X + 125, _Y + 1);
						printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205 ,205,205,205,205,205,205, 205,205,205,205, 187);
						gotoxy(_X + 141, _Y + 2);
						printf("%c", 186);
						gotoxy(_X + 125, _Y + 3);
						printf("%c %s ", 186, dataUser.user);
						gotoxy(_X + 141, _Y + 3);
						printf("%c", 186);
						gotoxy(_X + 125, _Y + 4);
					    printf("%c %s ", 186, dataUser.userId);
						gotoxy(_X + 141, _Y + 4);
						printf("%c", 186);
						gotoxy(_X + 125, _Y + 5);
					    printf("%c %s ", 186, dataUser.email);
						gotoxy(_X + 141, _Y + 5);
						printf("%c", 186);
						gotoxy(_X + 125, _Y + 6);
					    printf("%c %s ", 186, dataUser.password);
						gotoxy(_X + 141, _Y + 6);
						printf("%c", 186);
						gotoxy(_X + 125, _Y + 7);
						printf("==================", 186);
						gotoxy(_X + 125, _Y + 8);
						printf("%c   UPDATE (U)  %c", 186, 186);
						gotoxy(_X + 125, _Y + 9);
						printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205 ,205,205,205,205,205,205, 205,205,205,205, 188);
						gotoxy(_X + 125, _Y + 10);
						printf("%c   DELETE (D)  %c", 186, 186);
						gotoxy(_X + 125, _Y + 11);
						printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205 ,205,205,205,205,205,205, 205,205,205,205, 188);
						gotoxy(_X + 125, _Y + 12);
						printf("%c   LOGOUT (L)  %c", 186, 186);
						gotoxy(_X + 125, _Y + 13);
						printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205 ,205,205,205,205,205,205, 205,205,205,205, 188);
					}
				}
				fclose(file);
			}
			else {
				profile = 1;
				system ("cls");
				if (menu == 0) {
					goto Menu;
				}
			}
		}
		else if (menu == 0 && (inputUserPage == 's' || inputUserPage == 'S')) {
//			medicalCheckUp ();
			cariFilePenyakit();
			break;
		}
		else if (menu == 0 && (inputUserPage == 'b' || inputUserPage == 'B')) {
	//		diseaseData ();
		}
		else if (menu == 0 && (inputUserPage == 't' || inputUserPage == 'T')) {
	//		diseaseData ();
		}
		else if (menu == 0 && (inputUserPage == 'x' || inputUserPage == 'X')) {
			exit (0);
			break;
		}
		else if (profile == 0 && (inputUserPage == 'u' || inputUserPage == 'U')) {
			updateProfileUser();
		}
		else if (profile == 0 && (inputUserPage == 'd' || inputUserPage == 'D')) {
			deletesProfileUser();
		}
		else if (profile == 0 && (inputUserPage == 'l' || inputUserPage == 'L')) {
			strcpy(logReg.userId, "");
			printBanner ();
			break;
		}
		else {
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		}
	
	}
}

void medicalCheckUp () {
	char inputMedicalCheckUp;
	Node *root;
	
	
	int _X = getScreenWidth() / 2 - 70, _Y = getScreenHeight() / 2 - 16;

	system ("cls");
	layoutXY (8);
	
	gotoxy(_X + 28, _Y + 26);
	scanf (" %c", &inputMedicalCheckUp); fflush (stdin);
	
	switch (inputMedicalCheckUp) {
		case '1':
			medicalCheckUpResults (startAnalysis(rootPenyakit));
//			root = createNode("Apakah Anda mengalami sakit dada? (y/n) ");
//		    root->yes = createNode("Apakah sakit dada berlangsung lebih dari 5 menit? (y/n) ");
//		    root->no = createNode("Apakah Anda merasa sesak napas? (y/n) ");
//		    root->yes->yes = createNode("Anda menderita serangan jantung.");
//		    root->yes->no = createNode("Apakah Anda merasa pusing? (y/n) ");
//		    root->yes->no->yes = createNode("Anda menderita penyakit jantung koroner.");
//		    root->yes->no->no = createNode("Anda menderita angina.");
//		    root->no->yes = createNode("Anda menderita gagal jantung.");
//		    root->no->no = createNode("Apakah Anda merasa lelah? (y/n) ");
//		    root->no->no->yes = createNode("Anda menderita penyakit jantung bawaan.");
 
			break;
			
		case '2':
			
			break;
	}
	
//    diseaseResult = startAnalysis(root);
    
    
    getch ();
    userPage ();
//    printf("Penyakit anda : %s", diseaseResult);
}
