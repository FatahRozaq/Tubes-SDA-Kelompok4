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

void lineText(char textType, char lineName[50]) {
	switch (textType) {
		case 'i':
			printf("|\t%s\t| ", lineName);
			break;
			
		case 'o':
			printf("|\t%s\t|\n", lineName);
			break;
			
		case 'a':
			printf("\n");
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
