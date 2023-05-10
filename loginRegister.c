#include "header.h"

void loginUser () {
	char str[1000]; char *pos; char *pas, continueText [50]= "Press any key to continue ...";
	int _X = getScreenWidth() / 2 - 31;
	int _Y = getScreenHeight() / 2 - 9;
	
	file = fopen("user.txt", "r");
	
	// Inisialisasi jendela cmd agar bersih
    system("cls");
	
	gotoxy(_X + 10, _Y + 19);
	printf("Don't have an account? Press r to register");
	layoutXY (1);
	
	gotoxy(_X + 52, _Y + 19);
    char inputLogin = getch ();
	if (inputLogin == 'r') {
		registerUser ();
	}
	system ("cls");
	layoutXY (1);

	gotoxy(_X + 22, _Y + 7);
	scanf_s("%[^\n]s", &logReg.user);fflush(stdin);

	gotoxy(_X + 22, _Y + 11);
	scanf_s("%[^\n]s", &logReg.userId);fflush(stdin);

	gotoxy(_X + 22, _Y + 15);
	char password[20];
    int i = 0;
    char ch;

	while (1) {
        ch = getch();
        if (ch == '\r') {  // if Enter key is pressed
	        password[i] = '\0';
	        break;
        } 
		else if (ch == '\b' && i > 0) {  // if Backspace key is pressed
	        i--;
	        printf("\b \b");
        }
		else if (ch != '\b') {
	        password[i] = ch;
	        i++;
	        printf("*");
	    }
	}
    strcpy (logReg.password, password);
	
	file = fopen("user.txt", "r");
	if (file == NULL){
		fclose(file);
		gotoxy(_X + 16, _Y + 19);
		printf("     User Not Found!     \n");
		
		gotoxy(_X + 16, _Y + 25);
		for(i = 0; continueText[i] != '\0'; i ++)
		{
		    printf ("%c", continueText[i]);
		    Sleep(50);
		}
		getch ();
		
//		lineText('b', "\t\t\t\tUser Not Found!\t\t\t\t\t");
        file = fopen("user.txt","a");
        fclose(file);
        file = fopen("user.txt","r");
	}
	
	strcpy(check.user, logReg.user);
	strcpy(check.userId, logReg.userId);
	strcpy(check.password, logReg.password);
	while (!feof(file)){
		fscanf(file,"%[^_]_%[^_]_%[^_]_%[^_]_%[^\n]\n",&dataUser.user, &dataUser.userId, &dataUser.email, &dataUser.password, &dataUser.userAdmin);fflush(stdin);
		if (strcmp(check.user, dataUser.user) == 0 && strcmp(check.userId, dataUser.userId) == 0 && strcmp(check.password, dataUser.password) == 0) {
			fclose(file);
			if (strcmp(dataUser.userAdmin, "0") == 0){
				strcpy(logReg.userAdmin, "0");
			}
			else {
				strcpy(logReg.userAdmin, "1");
			}
			goto coba;
		}
	}
	fclose(file);
	
	gotoxy(_X + 16, _Y + 19);
	printf("     The account doesn't exist!     \n");
	
	gotoxy(_X + 16, _Y + 25);
	for(i = 0; continueText[i] != '\0'; i ++)
	{
	    printf ("%c", continueText[i]);
	    Sleep(50);
	}
	getch ();
	
//	gotoxy(_X + 16, _Y + 25);
//	printf("     Press any key to continue ...");
//	getch ();
//	lineText('b', "\t\t\tThe account doesn't exist!\t\t\t\t");
	return loginUser ();
	
	coba:
		file = fopen("user.txt","r");
	    while (fgets(str, 1000, file) != NULL){
	        pos = strstr(str, logReg.user);
	        pas = strstr(str, logReg.password);
			if (pos != NULL && pas != NULL){
				fclose(file);
//				lineText('b', "\t\t\t\tSuccessfully Logged in!\t\t\t\t");
				
				gotoxy(_X + 16, _Y + 19);
				printf("     Successfully Logged in!     \n");
				
				gotoxy(_X + 16, _Y + 25);
				for(i = 0; continueText[i] != '\0'; i ++)
				{
				    printf ("%c", continueText[i]);
				    Sleep(50);
				}
				getch ();
				
				if(strcmp(dataUser.userAdmin, "1") == 0) {
					adminPage();
				}
				else {
					userPage();	
				}
			}
		}
		if (pos == NULL && pas == NULL) {
			fclose(file);
			gotoxy(_X + 16, _Y + 19);
			printf("     User Not Found!     \n");
			
			gotoxy(_X + 16, _Y + 25);
			for(i = 0; continueText[i] != '\0'; i ++)
			{
			    printf ("%c", continueText[i]);
			    Sleep(50);
			}
			getch ();
			
//			lineText('b', "\t\t\t\tUser Not Found!\t\t\t\t\t");
			loginUser ();
		}
}

void registerUser () {
	char checkPassword = '0', confirmPassword[20], checkEmail[50], str[1000]; char *pos; char *pas, continueText [50]= "Press any key to continue ...";
	int _X = getScreenWidth() / 2 - 31, _Y = getScreenHeight() / 2 - 16, i, j;

	system("cls");
	
	gotoxy(_X + 10, _Y + 27);
	printf("Already have an account? Press l to login");
	layoutXY (2);
	
	gotoxy(_X + 51, _Y + 27);
    char inputRegister = getch ();
	if (inputRegister == 'l') {
		loginUser ();
	}
	
	system("cls");
	layoutXY (2);
	gotoxy(_X + 15, _Y + 27);
	printf("If you are an admin, Press a");
    char inputRegisterAdmin = getch ();
	if (inputRegisterAdmin == 'a') {
		strcpy(logReg.userAdmin, "1");
	}
	else {	
		strcpy(logReg.userAdmin, "0");
	}
 	
	registerUser:
		system ("cls");
		layoutXY (2);
	
		file=fopen("user.txt", "r+");
//		line(3);
//		lineText('i', "Username");
		gotoxy(_X +22, _Y + 7);
		scanf("%[^\n]s", &logReg.user);fflush(stdin);
		if (strlen(logReg.user) > 13 ||  strlen(logReg.user) < 6) {
			gotoxy(_X + 12, _Y + 27);
			printf("Username consists of 6 - 13 characters!     \n");
			
			gotoxy(_X + 16, _Y + 32);
			for(i = 0; continueText[i] != '\0'; i ++)
			{
			    printf ("%c", continueText[i]);
			    Sleep(1);
			}
			getch ();
			
//			lineText('b', "\t\t\tUsername consists of 6 - 13 characters!\t\t\t");
			goto registerUser;
		}
		
	regUserId:
//		lineText('i', "ID\t");
		gotoxy(_X +22, _Y + 11);
		scanf("%[^\n]s", &logReg.userId);fflush(stdin);
		if (strlen(logReg.userId) > 13 ||  strlen(logReg.userId) < 6) {
			
			gotoxy(_X + 12, _Y + 27);
			printf("User ID consists of 6 - 13 characters!     \n");
			
			gotoxy(_X + 16, _Y + 32);
			for(i = 0; continueText[i] != '\0'; i ++)
			{
			    printf ("%c", continueText[i]);
			    Sleep(1);
			}
			getch ();
			
//			lineText('b', "\t\t\tUser ID consists of 6 - 13 characters!\t\t\t");
			system ("cls");	
			layoutXY (2);
			gotoxy(_X +22, _Y + 7);
			printf ("%s", logReg.user);
			goto regUserId;
		}
		
	strcpy(check.user, logReg.user);
	strcpy(check.userId, logReg.userId);
	while (!feof(file)){
		fscanf(file,"%[^_]_%[^_]_%[^_]_%[^_]_%[^\n]\n",&dataUser.user, &dataUser.userId, dataUser.email, dataUser.password, dataUser.userAdmin);fflush(stdin);
		if ((strcmp(check.user, dataUser.user) == 0 && strcmp(check.user, dataUser.userId) != 0 && strcmp(check.user, dataUser.email) != 0 && strcmp(check.user, dataUser.password) != 0) || (strcmp(check.userId, dataUser.user) != 0 && strcmp(check.userId, dataUser.userId) == 0 && strcmp(check.userId, dataUser.email) != 0 && strcmp(check.userId, dataUser.password) != 0)) {
			
			gotoxy(_X + 12, _Y + 27);
			printf("   The account is already exist!     \n");
			
			gotoxy(_X + 16, _Y + 32);
			for(i = 0; continueText[i] != '\0'; i ++)
			{
			    printf ("%c", continueText[i]);
			    Sleep(1);
			}
			getch ();
			
//			lineText('b', "\t\t\tThe account is already exist!\t\t\t\t");
			registerUser();
		}
	}
		
	regEmail:
//		lineText('i', "Email\t");
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
			
//			lineText('b', "\t\t\tEmail consists of 6 - 13 characters!\t\t\t");
			system ("cls");	
			layoutXY (2);
			gotoxy(_X +22, _Y + 7);
			printf ("%s", logReg.user);
			gotoxy(_X +22, _Y + 11);
			printf ("%s", logReg.userId);
			goto regEmail;
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
			printf ("%s", logReg.user);
			gotoxy(_X +22, _Y + 11);
			printf ("%s", logReg.userId);
			goto regEmail;
		}
		strcpy(logReg.email, checkEmail);
		
	while (checkPassword == '0') {
		regPassword:
//			lineText('i', "Password");
			gotoxy(_X +22, _Y + 19);
			
			char password[20];
		    int i = 0;
		    char ch;
		
			while (1) {
		        ch = getch();
		        if (ch == '\r') {  // if Enter key is pressed
			        password[i] = '\0';
			        break;
		        } 
				else if (ch == '\b' && i > 0) {  // if Backspace key is pressed
			        i--;
			        printf("\b \b");
		        }
				else if (ch != '\b') {
			        password[i] = ch;
			        i++;
			        printf("*");
			    }
			}
		    strcpy (logReg.password, password);
		    
//			scanf("%[^\n]s", &logReg.password);fflush(stdin);
			if (strlen(logReg.password) > 13 ||  strlen(logReg.password) < 6) {
				
				gotoxy(_X + 12, _Y + 27);
				printf("Password consists of 6 - 13 characters!     \n");
				
				gotoxy(_X + 16, _Y + 32);
				for(i = 0; continueText[i] != '\0'; i ++)
				{
				    printf ("%c", continueText[i]);
				    Sleep(1);
				}
				getch ();
				
//				lineText('b', "\t\t\tPassword consists of 6 - 13 characters!\t\t\t");
				system ("cls");	
				layoutXY (2);
				gotoxy(_X +22, _Y + 7);
				printf ("%s", logReg.user);
				gotoxy(_X +22, _Y + 11);
				printf ("%s", logReg.userId);
				gotoxy(_X +22, _Y + 15);
				printf ("%s", logReg.email);
				goto regPassword;
			}
	
//			lineText('i', "Re-Password");
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
			if (strcmp(logReg.password, confirmPassword) == 0) {
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
				printf ("%s", logReg.user);
				gotoxy(_X +22, _Y + 11);
				printf ("%s", logReg.userId);
				gotoxy(_X +22, _Y + 15);
				printf ("%s", logReg.email);
				goto regPassword;
			}
	}
		
    fprintf(file, "%s_%s_%s_%s_%s\n", logReg.user, logReg.userId, logReg.email, logReg.password, logReg.userAdmin);
    fclose(file);
    getch();
    
    if(strcmp(logReg.userAdmin, "1") == 0) {
    	adminPage();
	}
	else {
    	userPage();
	}
}

void updateProfileUser(){
	User edit[50];
	char id[50], checkPassword = '0', confirmPassword[20], checkEmail[50], continueText [50]= "Press any key to continue ...";
	FILE *check;
	int index, i, _X = getScreenWidth() / 2 - 31, _Y = getScreenHeight() / 2 - 16, j;
	char str[1000], checkId[50]; char *pos;
	
	strcpy(id, logReg.userId);
	updateProfileUser:
	file=fopen("user.txt","r+");
	index=0;
	while (!feof(file)){
		fscanf(file,"%[^_]_%[^_]_%[^_]_%[^_]_%[^\n]\n",&edit[index].user,&edit[index].userId,&edit[index].email,&edit[index].password, &edit[index].userAdmin);
		fflush(stdin);
			if(strcmp(edit[index].userId, id) == 0){
				updateProfileUserUsername:
					
					system("cls");
					layoutXY (2);
					gotoxy(_X + 25, _Y + 3);
					printf ("  Update Profile");
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
					
					strcpy(logReg.user, edit[index].user);
					
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
//							lineText('a', "\t\t\tThe User ID is already exist!\t\t\t\t");
							goto updateProfileUserId;
							break;
						}
					}
					fclose(check);
						
					strcpy(edit[index].userId, checkId);
					strcpy(logReg.userId, edit[index].userId);
					
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
						gotoxy(_X + 25, _Y + 3);
						printf ("  Update Profile");
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
						gotoxy(_X + 25, _Y + 3);
						printf ("  Update Profile");
						gotoxy(_X +22, _Y + 7);
						printf ("%s", edit[index].user);
						gotoxy(_X +22, _Y + 11);
						printf ("%s", edit[index].userId);
						goto updateProfileUserEmail;
					}
					strcpy(edit[index].email, checkEmail);
					strcpy(logReg.email, edit[index].email);
				
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
						gotoxy(_X + 25, _Y + 3);
						printf ("  Update Profile");
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
					
					strcpy(logReg.password, edit[index].password);
				strcpy(edit[index].userAdmin, logReg.userAdmin);
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
	
    if(strcmp(logReg.userAdmin, "1") == 0) {
    	adminPage();
	}
	else {
    	userPage();
	}
	
}

void deletesProfileUser (){
	
	User deletes[50];
	char id[50];
	int index,i;
	
	strcpy(id, logReg.userId);

	file=fopen("user.txt", "r");
	index=0;
	while (!feof(file)){
		fscanf(file,"%[^_]_%[^_]_%[^_]_%[^_]_%[^\n]\n",&deletes[index].user,&deletes[index].userId,&deletes[index].email,&deletes[index].password,deletes[index].userAdmin);
		fflush(stdin);
		if(strcmp(deletes[index].userId, id) != 0){
			index++;
		}
	}
		
	fclose(file);
		file=fopen("user.txt", "w");
	for(i=0;i<index;i++){
		fprintf(file,"%s_%s_%s_%s_%s\n",deletes[i].user,deletes[i].userId,deletes[i].email,deletes[i].password,deletes[i].userAdmin);
	}
	fclose(file);
	strcpy(logReg.userId, "");
	printBanner ();
}
