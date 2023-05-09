#include "header.h"

void line(int lineType) {
	switch(lineType){
		case 1:
			printf("-------------------------------------------------------------------------------------------------\n");
			break;
			
		case 2:
			printf(" _______________________________________________________________________________________________ \n");
			break;
			
		case 3:
			printf("=================================================================================================\n");
			break;
			
		default:
			printf("|\t\t\t\t\t\t\t\t\t\t\t\t|\n");
			break;
	}
}

void layoutXY (int layoutType) {
	int _X = getScreenWidth() / 2 - 31;
	int _Y = getScreenHeight() / 2 - 9;
	
	switch (layoutType) {
		case 1:
			gotoxy(_X - 2, _Y);
			printf("========================================================================\n");
			gotoxy(_X + 28, _Y + 2);
			printf("Login Page\n");
			gotoxy(_X + 2, _Y+5);
			printf("\n\n");
			gotoxy(_X +20, _Y + 6);
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
			gotoxy(_X +4, _Y + 7);
			printf("Username");
			gotoxy(_X +20, _Y + 7);
			printf("%c                                      %c\n",186,186);
			gotoxy(_X +20, _Y + 8);
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
			gotoxy(_X +2, _Y + 9);
			printf("\n");
			gotoxy(_X +20, _Y + 10);
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
			gotoxy(_X +4, _Y + 11);
			printf("ID");
			gotoxy(_X +20, _Y + 11);
			printf("%c                                      %c\n",186,186);
			gotoxy(_X +20, _Y + 12);
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
			gotoxy(_X +2, _Y + 13);
			printf("\n");
			gotoxy(_X +20, _Y + 14);
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
			gotoxy(_X +4, _Y + 15);
			printf("Password");
			gotoxy(_X +20, _Y + 15);
			printf("%c                                      %c\n",186,186);
			gotoxy(_X +20, _Y + 16);
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
			gotoxy(_X +2, _Y + 17);
			printf("\n");
			break;
			
		case 2:
			
			break;
	}
}

void lineText(char textType, char lineName[50]) {
	
	switch (textType) {
		case 'i':
			printf("|\t%s\t| ", lineName);
			break;
			
		case 'o':
			printf("|\t%s\t|\n", lineName);
			break;
			
		case 'a':
			line(3);
			line(0);
			printf("|\t%s\t|\n", lineName);
			line(0);
			line(3);
			getch();
			break;
	}
}

void headerLayout(char leftHeader[50], char leftHeader2[50], char title[50]) {
	system("cls");
	line(2);
	line(0);
	printf("|\t%s\t\t\t|\tKelompok A4\t\t|\t\t\t\t|\n", leftHeader);
	printf("|\t%s\t\t|\t%s\t|\t\t\t\t|\n", leftHeader2, title);
	fclose(file);
	line(0);
	line(1);
}

void errorMessage() {
	lineText('a', "\t\tYou typed a wrong input, press any key to try again...\t\t");
}

void inputType(char *typeHere) {
	line(3);
	lineText('i', "Type here");
	scanf(" %s", &*typeHere);fflush(stdin);
	line(3);
}
