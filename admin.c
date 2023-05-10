#include "header.h"
#define length 256

void adminPage(){
	headerLayout(" ", "\t", "Admin Page\t");
	char inputAdminPage;
	line(0);
	lineText('o', "\t\t\t\t1. Admin Profile\t\t\t\t");
	lineText('o', "\t\t\t\t2. User Data\t\t\t\t\t");
	lineText('o', "\t\t\t\t3. Disease Data\t\t\t\t\t");
	lineText('o', "\t\t\t\t4. Settings\t\t\t\t\t");
	lineText('o', "\t\t\t\t5. Data Transaction\t\t\t\t");
	lineText('o', "\t\t\t\t6. Exit\t\t\t\t\t\t");
	line(0);
	inputType(&inputAdminPage);
	line(0);
	
	switch(inputAdminPage){
		case '0':
			karakteristikPenyakit();
			break;
			
		case '1':
			profile();
			break;
//			
		case '2':
			userData();
			break;
//			
//		case '3':
//			adminGamesData();
//			break;
//			
//		case '4':
//			settings();
//			break;
//			
//		case '5':
//			dataTransaction();
//			break;
//			
		case '6':
			exitProgram();
			break;
			
		default:
			errorMessage();
			break;
	}
}

void userData(){
	char string[length], inputUserData;
	int a;
	userData:
		a = 0;
		headerLayout(" ", "\t", "Admin Page\t");
		
		if ((file=fopen("user.txt", "a+")) == NULL)
		{
			lineText('a', "\t\t\t\tFile cannot be open!\t\t\t\t");
			exit(1);
		}
		line(3);
		printf("\t| NO | USERNAME | ID | EMAIL | PASSWORD | USER |\n");
		line(3);
		while ((fgets(string, length, file)) != NULL) {
			a++;
			printf("\t%d. %s\r", a, string);
			line(1);
		}
		fclose(file);
		
		line(3);
		line(0);
		lineText('o', "\t\t\t\t1. Add User\t\t\t\t\t");
		lineText('o', "\t\t\t\t2. Update User\t\t\t\t\t");
		lineText('o', "\t\t\t\t3. Delete User\t\t\t\t\t");
		lineText('o', "\t\t\t\t4. Back\t\t\t\t\t\t");
		line(0);
		inputType(&inputUserData);
		
		switch(inputUserData){
//			case '0':
//				adminPage();
//				break;
				
			case '1':
				registerUser();
				break;
				
			case '2':
				updateAdmin();
				break;
				
			case '3':
				deleteAdmin();
				break;
				
			case '4':
				adminPage();
				break;
				
			default:
				errorMessage();
				goto userData;
				break;
		}
}

void updateAdmin(){
	User edit[50];
	int index,i;
	FILE *check;
	char str[1000], checkId[50]; char *pos;
	
	lineText('i', "Input ID");
	scanf("%s",&checkId);fflush(stdin);
	line(3);

	file=fopen("user.txt","r");
	index=0;
	while (!feof(file)){
		fscanf(file,"%[^_]_%[^_]_%[^_]_%[^_]_%[^\n]\n",&edit[index].user,&edit[index].userId,&edit[index].email,&edit[index].password,&edit[index].userAdmin);
		fflush(stdin);
			if(strcmp(edit[index].userId, checkId) == 0){
				updateProfileAdminUsername:
					lineText('i', "Update Username");
					scanf("%[^\n]",&edit[index].user);fflush(stdin);
					if (strlen(edit[index].user) > 13 ||  strlen(edit[index].user) < 6) {
						errorMessage();
						goto updateProfileAdminUsername;
					}
					
				
				
				updateProfileAdminId:
					lineText('i', "Update User ID");
					scanf("%s",&checkId);fflush(stdin);
					if (strlen(checkId) > 13 ||  strlen(checkId) < 6) {
						errorMessage();
						goto updateProfileAdminId;
					}
					
					check = fopen("user.txt", "r");
					while((fgets(str,1000,check)) != NULL){
						pos = strstr(str, checkId);
							if(pos != NULL){
								lineText('a', "\t\t\tThe User ID is already exist!\t\t\t\t");
								goto updateProfileAdminId;
								break;
							}
					}
					fclose(check);
					
					strcpy(edit[index].userId, checkId);
					
//					strcpy(check.userId, logReg.userId);
//					while (!feof(file)){
//						fscanf(file,"%[^_]_%[^_]_%[^_]_%[^\n]\n",&dataUser.user, &dataUser.userId, &dataUser.email, &dataUser.password);fflush(stdin);
//						if (strcmp(check.userId, dataUser.userId) == 0) {
//							fclose(file);
//							lineText('a', "\t\t\tThe ID is already in use!\t\t\t\t");
//							file=fopen("user.txt","r");
//							goto updateProfileAdminId;
//						}
//					}
					
				
				updateProfileAdminEmail:
					lineText('i', "Update Email");
					scanf("%s",&edit[index].email);fflush(stdin);
					if (strlen(edit[index].email) > 13 ||  strlen(edit[index].email) < 6) {
						errorMessage();
						goto updateProfileAdminEmail;
					}
					
					if(strchr(edit[index].email, '@' ) == NULL){
						errorMessageEmail();
						goto updateProfileAdminEmail;
					}
							
				updateProfileAdminPassword:
					lineText('i', "Update Password");
					scanf("%s",&edit[index].password);fflush(stdin);
					if (strlen(edit[index].password) > 13 ||  strlen(edit[index].password) < 6) {
						errorMessage();
						goto updateProfileAdminPassword;
					}
			}
			index++;
		}

	fclose(file);
		file=fopen("user.txt","w");
	for(i=0;i<index;i++){
		fprintf(file,"%s_%s_%s_%s_%s\n",edit[i].user,edit[i].userId,edit[i].email,edit[i].password,edit[i].userAdmin);
	}
	fclose(file);
	userData();
}

void deleteAdmin(){
	User deletes[50];
	int index,i;
	
	lineText('i', "Input ID");
	scanf("%s",&check.userId);fflush(stdin);
	line(3);
	
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
