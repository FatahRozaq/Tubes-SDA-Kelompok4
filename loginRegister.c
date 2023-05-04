#include "header.h"

void loginRegisterUser() {
	char inputLoginRegister, inputRegister;
	
	loginRegisterUser:
//		strcpy(logReg.userId, "");
		headerLayout(" ", "\t", "Login Register Page");
		line(0);
		lineText('o', "\t\t\t\t1. Login\t\t\t\t\t");
		lineText('o', "\t\t\t\t2. Register\t\t\t\t\t");
		lineText('o', "\t\t\t\t3. Help\t\t\t\t\t\t");
		lineText('o', "\t\t\t\t4. Exit\t\t\t\t\t\t");
		line(0);
		inputType(&inputLoginRegister);
	
		switch (inputLoginRegister) {
//		case '0':
//			exitProgram();
//			break;
			
		case '1':
			loginUser();
			break;
			
		case '2':
			line(0);
			lineText('o', "\t\t\t\t1. User\t\t\t\t\t\t");
			lineText('o', "\t\t\t\t2. Admin\t\t\t\t\t");
			line(0);
			inputType(&inputRegister);
			
			switch(inputRegister) {
				case '1':
					strcpy(logReg.userAdmin, "0");
					registerUser();
					break;
				 
				 case '2':
				 	strcpy(logReg.userAdmin, "1");
				 	registerUser();
				 	break;
				
				default:
					errorMessage();
					goto loginRegisterUser;
					break;
			}
			break;
			
		case '3':
			helpLoginRegister();
			break;
			
		case '4':
//			exitProgram();
			break;	
			
		default:
			errorMessage();
			goto loginRegisterUser;
			break;
		}
}

void loginUser() {
	char str[1000]; char *pos; char *pas;
	
	file = fopen("user.txt", "r");
	line(3);
	lineText('i', "Username");
	scanf_s("%[^\n]s", &logReg.user);fflush(stdin);
	
	lineText('i', "ID\t");
	scanf_s("%[^\n]s", &logReg.userId);fflush(stdin);
	
	lineText('i', "Password");
	scanf_s("%[^\n]s", &logReg.password);fflush(stdin);
	
//	if(strcmp(logReg.user, "admin.ac.id") == 0 && strcmp(logReg.userId, "221511069") == 0 && strcmp(logReg.password, "*Admin6969#") == 0){
//		fclose(file);
//		adminPage();
//	}

	file = fopen("user.txt", "r");
	if (file == NULL){
		fclose(file);
		lineText('a', "\t\t\t\tUser Not Found!\t\t\t\t\t");
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
	lineText('a', "\t\t\tThe account doesn't exist!\t\t\t\t");
	return loginRegisterUser();
	
	coba:
		file = fopen("user.txt","r");
	    while (fgets(str, 1000, file) != NULL){
	        pos = strstr(str, logReg.user);
	        pas = strstr(str, logReg.password);
			if (pos != NULL && pas != NULL){
				fclose(file);
				lineText('a', "\t\t\t\tSuccessfully Logged in!\t\t\t\t");
				if(strcmp(dataUser.userAdmin, "1") == 0) {
					adminPage();
				}
				else {
					menu();	
				}
			}
		}
		if (pos == NULL && pas == NULL) {
			fclose(file);
			lineText('a', "\t\t\t\tUser Not Found!\t\t\t\t\t");
			loginRegisterUser();
		}
}

void registerUser() {
	char checkPassword = '0', confirmPassword[50], checkEmail[50];
	char str[1000]; char *pos; char *pas;
	
	registerUser:
		file=fopen("user.txt", "r+");
		line(3);
		lineText('i', "Username");
		scanf("%[^\n]s", &logReg.user);fflush(stdin);
		if (strlen(logReg.user) > 13 ||  strlen(logReg.user) < 6) {
			errorMessage();
			goto registerUser;
		}
		
	regUserId:
		lineText('i', "ID\t");
		scanf("%[^\n]s", &logReg.userId);fflush(stdin);
		if (strlen(logReg.userId) > 13 ||  strlen(logReg.userId) < 6) {
			errorMessage();
			goto regUserId;
		}
		
	strcpy(check.user, logReg.user);
	strcpy(check.userId, logReg.userId);
	while (!feof(file)){
		fscanf(file,"%[^_]_%[^_]_%[^_]_%[^_]_%[^\n]\n",&dataUser.user, &dataUser.userId, dataUser.email, dataUser.password, dataUser.userAdmin);fflush(stdin);
		if ((strcmp(check.user, dataUser.user) == 0 && strcmp(check.user, dataUser.userId) != 0 && strcmp(check.user, dataUser.email) != 0 && strcmp(check.user, dataUser.password) != 0) || (strcmp(check.userId, dataUser.user) != 0 && strcmp(check.userId, dataUser.userId) == 0 && strcmp(check.userId, dataUser.email) != 0 && strcmp(check.userId, dataUser.password) != 0)) {
			lineText('a', "\t\t\tThe account is already exist!\t\t\t\t");
			return loginRegisterUser();
		}
	}
		
	regEmail:
		lineText('i', "Email\t");
		scanf("%[^\n]s", &checkEmail);fflush(stdin);
		if (strlen(checkEmail) > 13 ||  strlen(checkEmail) < 6) {
			errorMessage();
			goto regEmail;
		}
		
		if(strchr(checkEmail, '@' ) == NULL){
				errorMessageEmail();
				goto regEmail;
		}
		
		strcpy(logReg.email, checkEmail);
		
	while (checkPassword == '0') {
		regPassword:
			lineText('i', "Password");
			scanf("%[^\n]s", &logReg.password);fflush(stdin);
			if (strlen(logReg.password) > 13 ||  strlen(logReg.password) < 6) {
				errorMessage();
				goto regPassword;
			}
	
			lineText('i', "Re-Password");
			scanf("%[^\n]s", &confirmPassword);fflush(stdin);
			if (strcmp(logReg.password, confirmPassword) == 0) {
				checkPassword = '1';
				lineText('a', "\t\t\tSuccessfully Registered in!\t\t\t\t");
			}
			else
			{
				errorMessage();
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
    	menu();
	}
}

void profileUser() {
	char id[50];
	
	strcpy(id, logReg.userId);
    file = fopen("user.txt", "r");
    while (!feof(file)){
		fscanf(file,"%[^_]_%[^_]_%[^_]_%[^_]_%[^\n]\n",&dataUser.user, &dataUser.userId, &dataUser.email, &dataUser.password, &dataUser.userAdmin);
		fflush(stdin);
		if(strcmp(id, dataUser.userId) == 0){
			printf("|\t\t\t\tUsername\t: %s\t\t\t\t\t|\n", dataUser.user);
		    printf("|\t\t\t\tID\t\t: %s\t\t\t\t\t|\n", dataUser.userId);
		    printf("|\t\t\t\tEmail\t\t: %s\t\t\t\t\t|\n", dataUser.email);
		    printf("|\t\t\t\tPassword\t: %s\t\t\t\t\t|\n", dataUser.password);
		}
	}
	fclose(file);
}

void updateProfileUser(){
	User edit[50];
	char id[50];
	FILE *check;
	int index,i;
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
					lineText('i', "Update Username");
					scanf("%[^\n]",&edit[index].user);fflush(stdin);
					if (strlen(edit[index].user) > 13 ||  strlen(edit[index].user) < 6) {
						errorMessage();
						goto updateProfileUserUsername;
					}
					
					
				updateProfileUserId:
					lineText('i', "Update User ID");
					scanf("%s",&checkId);fflush(stdin);
					if (strlen(checkId) > 13 ||  strlen(checkId) < 6) {
						errorMessage();
						goto updateProfileUserId;
					}
					
					check = fopen("user.txt", "r");
					
					while((fgets(str,1000,check)) != NULL){
						pos = strstr(str, checkId);
						if(pos != NULL){
							lineText('a', "\t\t\tThe User ID is already exist!\t\t\t\t");
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
					lineText('i', "Update Email");
					scanf("%s",&edit[index].email);fflush(stdin);
					if (strlen(edit[index].email) > 13 ||  strlen(edit[index].email) < 6) {
						errorMessage();
						goto updateProfileUserEmail;
					}
				
				updateProfileUserPassword:
					lineText('i', "Update Password");
					scanf("%s",&edit[index].password);fflush(stdin);
					if (strlen(edit[index].password) > 13 ||  strlen(edit[index].password) < 6) {
						errorMessage();
						goto updateProfileUserPassword;
					}	
					
				strcpy(edit[index].userAdmin, logReg.userAdmin);
			}
			index++;
		}

	fclose(file);
		file=fopen("user.txt","w");
	for(i=0;i<index;i++){
		fprintf(file,"%s_%s_%s_%s_%s\n",edit[i].user,edit[i].userId,edit[i].email,edit[i].password, edit[index].userAdmin);
	}
	fclose(file);
	strcpy(logReg.userId, "");
	loginRegisterUser();
	
}

void deletesProfileUser(){
	
	User deletes[50];
	char id[50];
	int index,i;
	
	strcpy(id, logReg.userId);

	file=fopen("user.txt","r");
	index=0;
	while (!feof(file)){
		fscanf(file,"%[^_]_%[^_]_%[^_]_%[^_]_%[^\n]\n",&deletes[index].user,&deletes[index].userId,&deletes[index].email,&deletes[index].password,deletes[index].userAdmin);
		fflush(stdin);
		if(strcmp(deletes[index].userId, id) != 0){
			index++;
		}
	}
		
	fclose(file);
		file=fopen("user.txt","w");
	for(i=0;i<index;i++){
		fprintf(file,"%s_%s_%s_%s_s\n",deletes[i].user,deletes[i].userId,deletes[i].email,deletes[i].password,deletes[index].userAdmin);
	}
	fclose(file);
	strcpy(logReg.userId, "");
	loginRegisterUser();
}

void helpLoginRegister(){
	headerLayout("", "\t", "Help Page\t");
	line(3);
	lineText('o', "\t\t\t\tREGISTER\t\t\t\t\t");
	line(3);
	
	lineText('o', "1. Username, ID, Email, Password can't more than 13 and less than 6 character\t");
	line(1);
	lineText('o', "2. Username, ID, Email, Password can contain character and number\t\t");
	line(1);
	lineText('o', "3. ID can't be same to other user ID\t\t\t\t\t\t");
	line(3);
	getch();
	loginRegisterUser();
}

void errorMessageEmail(){
	lineText('a', "\t\tMust contain '@', press any key to try again...\t\t\t");
}


//////////

void adminPage () {
	printf ("Berhasil login admin\n"); getch ();
	
}

void menu () {
	printf ("Berhasil login\n"); getch ();
	
	Node *root = createNode("Apakah Anda mengalami sakit dada?");
    root->yes = createNode("Apakah sakit dada berlangsung lebih dari 5 menit?");
    root->no = createNode("Apakah Anda merasa sesak napas?");
    root->yes->yes = createNode("Anda menderita serangan jantung.");
    root->yes->no = createNode("Apakah Anda merasa pusing?");
    root->yes->no->yes = createNode("Anda menderita penyakit jantung koroner.");
    root->yes->no->no = createNode("Anda menderita angina.");
    root->no->yes = createNode("Anda menderita gagal jantung.");
    root->no->no = createNode("Apakah Anda merasa lelah?");
    root->no->no->yes = createNode("Anda menderita penyakit jantung bawaan.");
 
    startAnalysis(root);
}
