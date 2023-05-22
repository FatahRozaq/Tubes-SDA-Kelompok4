#include "header.h"

void adminPage(){
	char inputAdminPage, *temp;
	int _X = getScreenWidth() / 2 - 70, _Y = getScreenHeight() / 2 - 16, menu = 1, profile = 1;

	system ("cls");
	for (;;) {
		layoutXY (4);
		
		gotoxy(_X + 28, _Y + 26);
		
		scanf (" %c", &inputAdminPage); fflush (stdin);
		if (inputAdminPage == 'm' || inputAdminPage == 'M') {
			if (menu == 1) {
				Menu:
				menu = 0;
				gotoxy(_X + 55, _Y + 14);
				printf ("%c        DATA PENYAKIT (A)         %c", 186, 186);
				gotoxy(_X + 55, _Y + 15);
				printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205, 205, 205, 205, 205,205,205,205,205 ,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205, 205, 205,188);
				
				gotoxy(_X + 55, _Y + 16);
				printf ("%c       KARAKTER PENYAKIT (K)      %c", 186, 186);
				gotoxy(_X + 55, _Y + 17);
				printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205, 205, 205, 205, 205,205,205,205,205 ,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205, 205, 205,188);
		
				gotoxy(_X + 55, _Y + 18);
				printf ("%c          DATA USER (S)           %c", 186, 186);
				gotoxy(_X + 55, _Y + 19);
				printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205, 205, 205, 205, 205,205,205,205,205 ,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205, 205, 205,188);
		
				gotoxy(_X + 55, _Y + 20);
				printf ("%c           BANTUAN (B)            %c", 186, 186);
				gotoxy(_X + 55, _Y + 21);
				printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205, 205, 205, 205, 205,205,205,205,205 ,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205, 205, 205,188);
		
				gotoxy(_X + 55, _Y + 22);
				printf ("%c             EXIT (X)             %c", 186, 186);
				gotoxy(_X + 55, _Y + 23);
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
		else if (menu == 0 && (inputAdminPage == 'a' || inputAdminPage == 'A')) {
			DifaDebugging();
			break;
		}
		else if (menu == 0 && (inputAdminPage == 'k' || inputAdminPage == 'K')) {
			karakteristikPenyakit ();
			break;
		}
		else if (menu == 0 && (inputAdminPage == 's' || inputAdminPage == 'S')) {
			userData ();
		}
		else if (menu == 0 && (inputAdminPage == 'b' || inputAdminPage == 'B')) {
			
		}
		else if (menu == 0 && (inputAdminPage == 'x' || inputAdminPage == 'X')) {
			exit (0);
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
		else if (menu == 0 && (inputAdminPage == 'c' || inputAdminPage == 'C')) {
			medicalCheckUp();
			break;
		}
		else {
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		}
	}
}

void userData(){
	char string[256], inputUserData;
	int menu = 1, profile = 1, a, _X = getScreenWidth() / 2 - 70, _Y = getScreenHeight() / 2 - 16;
	
	system ("cls");
	
	for (;;) {
		layoutXY (5);
		
		userData:
			a = 0;
			
			if ((file=fopen("user.txt", "a+")) == NULL)
			{
				gotoxy(_X + 12, _Y + 27);
				printf("          File cannot be open!        \n");
				exit(1);
			}
			gotoxy (_X + 40, _Y + 11);
			printf("\t| NO | USERNAME | ID | EMAIL | PASSWORD | USER |\n");
			gotoxy (_X + 40, _Y + 12);
			printf("    ==================================================");
			while ((fgets(string, 256, file)) != NULL) {
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
						printf ("%c             BACK (X)             %c", 186, 186);
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
			else if (menu == 0 && (inputUserData == 'x' || inputUserData == 'X')) {
				adminPage ();
				break;
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
			else {
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
			}
	}
}

void updateAdmin(){
	User edit[50];
	char id[50], checkPassword = '0', confirmPassword[20], checkEmail[50], str[1000], checkId[50], *pos, continueText [50]= "Press any key to continue ...";
	FILE *check;
	int index, i, _X = getScreenWidth() / 2 - 31, _Y = getScreenHeight() / 2 - 16, j;

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
					gotoxy(_X + 25, _Y + 3);
					printf ("  Update Profile");
					gotoxy(_X +22, _Y + 7);
					scanf("%[^\n]s", &edit[index].user);fflush(stdin);
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
						goto updateProfileUserUsername;
					}
					
				updateProfileUserId:
					
					gotoxy(_X +22, _Y + 11);
					scanf("%[^\n]s", &checkId);fflush(stdin);
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
						
						system ("cls");	
						layoutXY (2);
						gotoxy(_X + 25, _Y + 3);
						printf ("  Update Profile");
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
							
							system ("cls");	
							layoutXY (2);
							gotoxy(_X + 25, _Y + 3);
							printf ("  Update Profile");
							gotoxy(_X +22, _Y + 7);
							printf ("%s", edit[index].user);
							goto updateProfileUserId;
							break;
						}
					}
					fclose(check);
						
					strcpy(edit[index].userId, checkId);
					
				updateProfileUserEmail:
					
					gotoxy(_X +22, _Y + 15);
					scanf("%[^\n]s", &checkEmail);fflush(stdin);
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
						gotoxy(_X + 25, _Y + 3);
						printf ("  Update Profile");
						gotoxy(_X +22, _Y + 7);
						printf ("%s", edit[index].user);
						gotoxy(_X +22, _Y + 11);
						printf ("%s", edit[index].userId);
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
						
						system ("cls");	
						layoutXY (2);
						gotoxy(_X + 25, _Y + 3);
						printf ("  Update Profile");
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
				        if (ch == '\r') {
					        edit[index].password[k] = '\0';
					        break;
				        } 
						else if (ch == '\b' && i > 0) {
					        k--;
					        printf("\b \b");
				        }
						else if (ch != '\b') {
					        edit[index].password[k] = ch;
					        k++;
					        printf("*");
					    }
					}
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
						
						system ("cls");	
						layoutXY (2);
						gotoxy(_X + 25, _Y + 3);
						printf ("  Update Profile");
						gotoxy(_X +22, _Y + 7);
						printf ("%s", edit[index].user);
						gotoxy(_X +22, _Y + 11);
						printf ("%s", edit[index].userId);
						gotoxy(_X +22, _Y + 15);
						printf ("%s", edit[index].email);
						goto updateProfileUserPassword;
					}	
					
					gotoxy(_X +22, _Y + 23);
					i = 0;
					while (1) {
				        ch = getch();
				        if (ch == '\r') {
					        confirmPassword[i] = '\0';
					        break;
				        } 
						else if (ch == '\b' && i > 0) {
					        i--;
					        printf("\b \b");
				        }
						else if (ch != '\b') {
					        confirmPassword[i] = ch;
					        i++;
					        printf("*");
					    }
					}
				    
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
						
						system ("cls");	
						layoutXY (2);
						gotoxy(_X + 25, _Y + 3);
						printf ("  Update Profile");
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
