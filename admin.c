#include "header.h"
#define length 256

void adminPage(){
	char inputAdminPage;
	int _X = getScreenWidth() / 2 - 70, _Y = getScreenHeight() / 2 - 16, menu = 1, profile = 1;
	
<<<<<<< HEAD
	system ("cls");
	for (;;) {
		layoutXY (4);
		
		gotoxy(_X + 28, _Y + 26);
		
		scanf (" %c", &inputAdminPage); fflush (stdin);
	//    inputUserPage = getch ();
		if (inputAdminPage == 'm' || inputAdminPage == 'M') {
			if (menu == 1) {
				Menu:
				menu = 0;
				gotoxy(_X + 55, _Y + 14);
				printf ("%c          DATA USER (S)           %c", 186, 186);
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
		else if (inputAdminPage == 'p' || inputAdminPage == 'P') {
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
//						gotoxy(_X + 125, _Y + 3);
//						printf("%c               %c", 186, 186);
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
		else if (menu == 0 && (inputAdminPage == 's' || inputAdminPage == 'S')) {
			userData ();
=======
	switch(inputAdminPage){
		case '0':
			karakteristikPenyakit();
			break;
			
		case '1':
			profile();
>>>>>>> d4473d0aa0f4af0f9c023f80bf4c619f9dfde2b2
			break;
		}
		else if (menu == 0 && (inputAdminPage == 'b' || inputAdminPage == 'B')) {
	//		diseaseData ();
		}
		else if (menu == 0 && (inputAdminPage == 't' || inputAdminPage == 'T')) {
	//		diseaseData ();
		}
		else if (menu == 0 && (inputAdminPage == 'x' || inputAdminPage == 'X')) {
			exitProgram ();
			break;
		}
		else if (profile == 0 && (inputAdminPage == 'u' || inputAdminPage == 'U')) {
			updateProfileUser();
		}
		else if (profile == 0 && (inputAdminPage == 'd' || inputAdminPage == 'D')) {
			deletesProfileUser();
		}
		else if (profile == 0 && (inputAdminPage == 'l' || inputAdminPage == 'L')) {
			strcpy(logReg.userId, "");
			printBanner ();
			break;
		}
		else {
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		}
	
	}
	
//	headerLayout(" ", "\t", "Admin Page\t");
//	char inputAdminPage;
//	line(0);
//	lineText('o', "\t\t\t\t1. Admin Profile\t\t\t\t");
//	lineText('o', "\t\t\t\t2. User Data\t\t\t\t\t");
//	lineText('o', "\t\t\t\t3. Disease Data\t\t\t\t\t");
//	lineText('o', "\t\t\t\t4. Settings\t\t\t\t\t");
//	lineText('o', "\t\t\t\t5. Data Transaction\t\t\t\t");
//	lineText('o', "\t\t\t\t6. Exit\t\t\t\t\t\t");
//	line(0);
//	inputType(&inputAdminPage);
//	line(0);
//	
//	switch(inputAdminPage){
////		case '0':
////			exitProgram();
////			break;
//			
//		case '1':
//			profile();
//			break;
////			
//		case '2':
//			userData();
//			break;
////			
////		case '3':
////			adminGamesData();
////			break;
////			
////		case '4':
////			settings();
////			break;
////			
////		case '5':
////			dataTransaction();
////			break;
////			
//		case '6':
//			exitProgram();
//			break;
//			
//		default:
//			errorMessage();
//			break;
//	}
}

void userData(){
	char string[length], inputUserData;
	int menu = 1, profile = 1, a, _X = getScreenWidth() / 2 - 70, _Y = getScreenHeight() / 2 - 16;
	
	system ("cls");
	
	for (;;) {
		layoutXY (5);
		
		userData:
			a = 0;
			
			if ((file=fopen("user.txt", "a+")) == NULL)
			{
				lineText('a', "\t\t\t\tFile cannot be open!\t\t\t\t");
				exit(1);
			}
			gotoxy (_X + 40, _Y + 11);
			printf("\t| NO | USERNAME | ID | EMAIL | PASSWORD | USER |\n");
			gotoxy (_X + 40, _Y + 12);
			printf("    ==================================================");
			while ((fgets(string, length, file)) != NULL) {
				a++;
				gotoxy (_X + 40, _Y + 12 + a);
				printf("\t%d. %s\r", a, string);
			}
			fclose(file);
			
			gotoxy(_X + 28, _Y + 26);
			scanf (" %c", &inputUserData); fflush (stdin);
			
			if (inputUserData == 'm' || inputUserData == 'M') {
				if (menu == 1) {
					Menu:
						menu = 0;
						gotoxy(_X + 101, _Y + 19);
						printf ("%c           ADD USER (A)           %c", 186, 186);
						gotoxy(_X + 101, _Y + 20);
						printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205, 205, 205, 205, 205,205,205,205,205 ,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205, 205, 205,188);
						
						gotoxy(_X + 101, _Y + 21);
						printf ("%c         UPDATE USER (B)          %c", 186, 186);
						gotoxy(_X + 101, _Y + 22);
						printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205, 205, 205, 205, 205,205,205,205,205 ,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205, 205, 205,188);
						
						gotoxy(_X + 101, _Y + 23);
						printf ("%c         DELETE USER (C)          %c", 186, 186);
						gotoxy(_X + 101, _Y + 24);
						printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205, 205, 205, 205, 205,205,205,205,205 ,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205, 205, 205,188);
			
						gotoxy(_X + 101, _Y + 25);
						printf ("%c             EXIT (C)             %c", 186, 186);
						gotoxy(_X + 101, _Y + 26);
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
			else if (inputUserData == 'p' || inputUserData == 'P') {
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
	//						gotoxy(_X + 125, _Y + 3);
	//						printf("%c               %c", 186, 186);
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
			else if (menu == 0 && (inputUserData == 'a' || inputUserData == 'A')) {
				registerUser();
			}
			else if (menu == 0 && (inputUserData == 'b' || inputUserData == 'B')) {
				updateAdmin();
			}
			else if (menu == 0 && (inputUserData == 'c' || inputUserData == 'C')) {
				deleteAdmin();
			}
			else if (profile == 0 && (inputUserData == 'u' || inputUserData == 'U')) {
				updateProfileUser();
			}
			else if (profile == 0 && (inputUserData == 'd' || inputUserData == 'D')) {
				deletesProfileUser();
			}
			else if (profile == 0 && (inputUserData == 'l' || inputUserData == 'L')) {
				strcpy(logReg.userId, "");
				printBanner ();
				break;
			}
			else if (profile == 0 && (inputUserData == 'x' || inputUserData == 'X')) {
				adminPage ();
				break;
			}
			else {
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
			}
	}
//		line(3);
//		line(0);
//		lineText('o', "\t\t\t\t1. Add User\t\t\t\t\t");
//		lineText('o', "\t\t\t\t2. Update User\t\t\t\t\t");
//		lineText('o', "\t\t\t\t3. Delete User\t\t\t\t\t");
//		lineText('o', "\t\t\t\t4. Back\t\t\t\t\t\t");
//		line(0);
//		inputType(&inputUserData);
//		
//		switch(inputUserData){
////			case '0':
////				adminPage();
////				break;
//				
//			case '1':
//				registerUser();
//				break;
//				
//			case '2':
//				updateAdmin();
//				break;
//				
//			case '3':
//				deleteAdmin();
//				break;
//				
//			case '4':
//				adminPage();
//				break;
//				
//			default:
//				errorMessage();
//				goto userData;
//				break;
//		}
}

void updateAdmin(){
	User edit[50];
	char id[50], checkPassword = '0', confirmPassword[20], checkEmail[50], continueText [50]= "Press any key to continue ...";
	FILE *check;
	int index, i, _X = getScreenWidth() / 2 - 31, _Y = getScreenHeight() / 2 - 16, j;
	char str[1000], checkId[50]; char *pos;

	gotoxy(_X + 100, _Y + 20);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205, 205, 205 ,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205, 205, 205,187);
	gotoxy(_X + 100, _Y + 21);
	printf("%c  Input ID: [             ]  %c\n",186,186);
	gotoxy(_X + 100, _Y + 22);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200, 205, 205, 205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205, 205, 205,188);
	
	gotoxy(_X + 114, _Y + 21);
	scanf("%s",&checkId);fflush(stdin);
	
	strcpy(id, logReg.userId);
	updateProfileUser:
	file=fopen("user.txt","r+");
	index=0;
	while (!feof(file)){
		fscanf(file,"%[^_]_%[^_]_%[^_]_%[^_]_%[^\n]\n",&edit[index].user,&edit[index].userId,&edit[index].email,&edit[index].password, &edit[index].userAdmin);
		fflush(stdin);
			if(strcmp(edit[index].userId, checkId) == 0){
				updateProfileUserUsername:
					
					system("cls");
					layoutXY (2);
					gotoxy(_X +22, _Y + 7);
					scanf("%[^\n]s", &edit[index].user);fflush(stdin);
//					lineText('i', "Update Username");
//					scanf("%[^\n]",&edit[index].user);fflush(stdin);
					if (strlen(edit[index].user) > 13 ||  strlen(edit[index].user) < 6) {

						gotoxy(_X + 12, _Y + 27);
						printf("Username consists of 6 - 13 characters!     \n");
						
						gotoxy(_X + 16, _Y + 32);
						for(i = 0; continueText[i] != '\0'; i ++)
						{
						    printf ("%c", continueText[i]);
						    Sleep(1);
						}
						getch ();
//						errorMessage();
						goto updateProfileUserUsername;
					}
					
				updateProfileUserId:
					
					gotoxy(_X +22, _Y + 11);
					scanf("%[^\n]s", &checkId);fflush(stdin);
//					lineText('i', "Update User ID");
//					scanf("%s",&checkId);fflush(stdin);
					if (strlen(checkId) > 13 ||  strlen(checkId) < 6) {
							
						gotoxy(_X + 12, _Y + 27);
						printf("User ID consists of 6 - 13 characters!     \n");
						
						gotoxy(_X + 16, _Y + 32);
						for(i = 0; continueText[i] != '\0'; i ++)
						{
						    printf ("%c", continueText[i]);
						    Sleep(1);
						}
						getch ();
//						errorMessage();
						
						system ("cls");	
						layoutXY (2);
						gotoxy(_X +22, _Y + 7);
						printf ("%s", edit[index].user);
						goto updateProfileUserId;
					}
					
					check = fopen("user.txt", "r");
					
					while((fgets(str,1000,check)) != NULL){
						pos = strstr(str, checkId);
						if(pos != NULL){
							
							gotoxy(_X + 12, _Y + 27);
							printf("   The account is already exist!     \n");
							
							gotoxy(_X + 16, _Y + 32);
							for(i = 0; continueText[i] != '\0'; i ++)
							{
							    printf ("%c", continueText[i]);
							    Sleep(1);
							}
							getch ();
//							lineText('a', "\t\t\tThe User ID is already exist!\t\t\t\t");
							goto updateProfileUserId;
							break;
						}
					}
					fclose(check);
						
					strcpy(edit[index].userId, checkId);
					
//					strcpy(check.user, edit[index].user);
//					strcpy(check.userId, edit[index].userId);
//					
//					if ((strcmp(check.user, dataUser.user) == 0 && strcmp(check.user, dataUser.userId) != 0 && strcmp(check.user, dataUser.email) != 0 && strcmp(check.user, dataUser.password) != 0) || (strcmp(check.userId, dataUser.user) != 0 && strcmp(check.userId, dataUser.userId) == 0 && strcmp(check.userId, dataUser.email) != 0 && strcmp(check.userId, dataUser.password) != 0)) {
//						lineText('a', "\t\t\tThe account is already exist!\t\t\t\t");
//						fclose(file);
//						goto updateProfileUser;
//					}
					
				updateProfileUserEmail:
					
					gotoxy(_X +22, _Y + 15);
					scanf("%[^\n]s", &checkEmail);fflush(stdin);
//					lineText('i', "Update Email");
//					scanf("%s",&edit[index].email);fflush(stdin);
					if (strlen(checkEmail) > 13 ||  strlen(checkEmail) < 6) {
						
						gotoxy(_X + 12, _Y + 27);
						printf("Email consists of 6 - 13 characters!     \n");
						
						gotoxy(_X + 16, _Y + 32);
						for(i = 0; continueText[i] != '\0'; i ++)
						{
						    printf ("%c", continueText[i]);
						    Sleep(1);
						}
						getch ();
						
						system ("cls");	
						layoutXY (2);
						gotoxy(_X +22, _Y + 7);
						printf ("%s", edit[index].user);
						gotoxy(_X +22, _Y + 11);
						printf ("%s", edit[index].userId);
//						errorMessage();
						goto updateProfileUserEmail;
					}
					
					if(strchr(checkEmail, '@' ) == NULL){
						
						gotoxy(_X + 16, _Y + 27);
						printf("    Email must contain '@'     \n");
						
						gotoxy(_X + 16, _Y + 32);
						for(i = 0; continueText[i] != '\0'; i ++)
						{
						    printf ("%c", continueText[i]);
						    Sleep(1);
						}
						getch ();
						
			//			lineText('b', "\t\t\t\tEmail must contain '@'\t\t\t\t");
						system ("cls");	
						layoutXY (2);
						gotoxy(_X +22, _Y + 7);
						printf ("%s", edit[index].user);
						gotoxy(_X +22, _Y + 11);
						printf ("%s", edit[index].userId);
						goto updateProfileUserEmail;
					}
					strcpy(edit[index].email, checkEmail);
				
				updateProfileUserPassword:
					
					gotoxy(_X +22, _Y + 19);
			
					char password[20];
				    int k = 0;
				    char ch;
				
					while (1) {
				        ch = getch();
				        if (ch == '\r') {  // if Enter key is pressed
					        edit[index].password[k] = '\0';
					        break;
				        } 
						else if (ch == '\b' && i > 0) {  // if Backspace key is pressed
					        k--;
					        printf("\b \b");
				        }
						else if (ch != '\b') {
					        edit[index].password[k] = ch;
					        k++;
					        printf("*");
					    }
					}
//					lineText('i', "Update Password");
//					scanf("%s",&edit[index].password);fflush(stdin);
					if (strlen(edit[index].password) > 13 ||  strlen(edit[index].password) < 6) {

						
						gotoxy(_X + 16, _Y + 27);
						printf("Password consists of 6 - 13 characters!     \n");
						
						gotoxy(_X + 16, _Y + 32);
						for(i = 0; continueText[i] != '\0'; i ++)
						{
						    printf ("%c", continueText[i]);
						    Sleep(1);
						}
						getch ();
						
		//				lineText('b', "\t\t\t\tPasswords are not match!\t\t\t\t");
						system ("cls");	
						layoutXY (2);
						gotoxy(_X +22, _Y + 7);
						printf ("%s", edit[index].user);
						gotoxy(_X +22, _Y + 11);
						printf ("%s", edit[index].userId);
						gotoxy(_X +22, _Y + 15);
						printf ("%s", edit[index].email);
//						errorMessage();
						goto updateProfileUserPassword;
					}	
					
					gotoxy(_X +22, _Y + 23);
					i = 0;
					while (1) {
				        ch = getch();
				        if (ch == '\r') {  // if Enter key is pressed
					        confirmPassword[i] = '\0';
					        break;
				        } 
						else if (ch == '\b' && i > 0) {  // if Backspace key is pressed
					        i--;
					        printf("\b \b");
				        }
						else if (ch != '\b') {
					        confirmPassword[i] = ch;
					        i++;
					        printf("*");
					    }
					}
				    
		//			scanf("%[^\n]s", &confirmPassword);fflush(stdin);
					if (strcmp(edit[index].password, confirmPassword) == 0) {
						checkPassword = '1';
						
						gotoxy(_X + 16, _Y + 27);
						printf("Successfully Registered in!     \n");
						
						gotoxy(_X + 16, _Y + 32);
						for(i = 0; continueText[i] != '\0'; i ++)
						{
						    printf ("%c", continueText[i]);
						    Sleep(1);
						}
						getch ();
						
		//				lineText('b', "\t\t\tSuccessfully Registered in!\t\t\t\t");
					}
					else
					{
						
						gotoxy(_X + 16, _Y + 27);
						printf("Passwords are not match     \n");
						
						gotoxy(_X + 16, _Y + 32);
						for(i = 0; continueText[i] != '\0'; i ++)
						{
						    printf ("%c", continueText[i]);
						    Sleep(1);
						}
						getch ();
						
		//				lineText('b', "\t\t\t\tPasswords are not match!\t\t\t\t");
						system ("cls");	
						layoutXY (2);
						gotoxy(_X +22, _Y + 7);
						printf ("%s", edit[index].user);
						gotoxy(_X +22, _Y + 11);
						printf ("%s", edit[index].userId);
						gotoxy(_X +22, _Y + 15);
						printf ("%s", edit[index].email);
						goto updateProfileUserPassword;
					}
					
			}
			index++;
		}

	fclose(file);
		file=fopen("user.txt","w");
	for(i=0;i<index;i++){
		fprintf(file,"%s_%s_%s_%s_%s\n",edit[i].user,edit[i].userId,edit[i].email,edit[i].password, edit[i].userAdmin);
	}
	fclose(file);
	getch ();
	userData ();
	
//	file=fopen("user.txt","r");
//	index=0;
//	while (!feof(file)){
//		fscanf(file,"%[^_]_%[^_]_%[^_]_%[^_]_%[^\n]\n",&edit[index].user,&edit[index].userId,&edit[index].email,&edit[index].password,&edit[index].userAdmin);
//		fflush(stdin);
//			if(strcmp(edit[index].userId, checkId) == 0){
//				updateProfileAdminUsername:
//					lineText('i', "Update Username");
//					scanf("%[^\n]",&edit[index].user);fflush(stdin);
//					if (strlen(edit[index].user) > 13 ||  strlen(edit[index].user) < 6) {
//						errorMessage();
//						goto updateProfileAdminUsername;
//					}
//					
//				updateProfileAdminId:
//					lineText('i', "Update User ID");
//					scanf("%s",&checkId);fflush(stdin);
//					if (strlen(checkId) > 13 ||  strlen(checkId) < 6) {
//						errorMessage();
//						goto updateProfileAdminId;
//					}
//					
//					check = fopen("user.txt", "r");
//					while((fgets(str,1000,check)) != NULL){
//						pos = strstr(str, checkId);
//							if(pos != NULL){
//								lineText('a', "\t\t\tThe User ID is already exist!\t\t\t\t");
//								goto updateProfileAdminId;
//								break;
//							}
//					}
//					fclose(check);
//					
//					strcpy(edit[index].userId, checkId);
//					
////					strcpy(check.userId, logReg.userId);
////					while (!feof(file)){
////						fscanf(file,"%[^_]_%[^_]_%[^_]_%[^\n]\n",&dataUser.user, &dataUser.userId, &dataUser.email, &dataUser.password);fflush(stdin);
////						if (strcmp(check.userId, dataUser.userId) == 0) {
////							fclose(file);
////							lineText('a', "\t\t\tThe ID is already in use!\t\t\t\t");
////							file=fopen("user.txt","r");
////							goto updateProfileAdminId;
////						}
////					}
//					
//				
//				updateProfileAdminEmail:
//					lineText('i', "Update Email");
//					scanf("%s",&edit[index].email);fflush(stdin);
//					if (strlen(edit[index].email) > 13 ||  strlen(edit[index].email) < 6) {
//						errorMessage();
//						goto updateProfileAdminEmail;
//					}
//					
//					if(strchr(edit[index].email, '@' ) == NULL){
//						errorMessageEmail();
//						goto updateProfileAdminEmail;
//					}
//							
//				updateProfileAdminPassword:
//					lineText('i', "Update Password");
//					scanf("%s",&edit[index].password);fflush(stdin);
//					if (strlen(edit[index].password) > 13 ||  strlen(edit[index].password) < 6) {
//						errorMessage();
//						goto updateProfileAdminPassword;
//					}
//			}
//			index++;
//		}
//
//	fclose(file);
//	file=fopen("user.txt","w");
//	for(i=0;i<index;i++){
//		fprintf(file,"%s_%s_%s_%s_%s\n",edit[i].user,edit[i].userId,edit[i].email,edit[i].password,edit[i].userAdmin);
//	}
//	fclose(file);
//	userData();
}

void deleteAdmin(){
	User deletes[50];
	int index, i, _X = getScreenWidth() / 2 - 31, _Y = getScreenHeight() / 2 - 16;

	
	gotoxy(_X + 100, _Y + 23);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205, 205, 205 ,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205, 205, 205,187);
	gotoxy(_X + 100, _Y + 24);
	printf("%c  Input ID: [             ]  %c\n",186,186);
	gotoxy(_X + 100, _Y + 25);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200, 205, 205, 205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205, 205, 205,188);
	
	gotoxy(_X + 114, _Y + 24);
	scanf("%s",&check.userId);fflush(stdin);
	
	file=fopen("user.txt","r");
	index=0;
	while (!feof(file)){
		fscanf(file,"%[^_]_%[^_]_%[^_]_%[^_]_%[^\n]\n",&deletes[index].user,&deletes[index].userId,&deletes[index].email,&deletes[index].password,&deletes[index].userAdmin);
		fflush(stdin);
		if(strcmp(deletes[index].userId, check.userId) != 0){
			index++;
		}
	}
		
	fclose(file);
		file=fopen("user.txt","w");
	for(i=0;i<index;i++){
		fprintf(file,"%s_%s_%s_%s_%s\n",deletes[i].user,deletes[i].userId,deletes[i].email,deletes[i].password,deletes[i].userAdmin);
	}
	fclose(file);
	
	userData();
}
