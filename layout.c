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
	int _X;
	int _Y;
	
	switch (layoutType) {
		case 1:
			_X = getScreenWidth() / 2 - 31;
			_Y = getScreenHeight() / 2 - 9;
			gotoxy(_X - 5, _Y);
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
			gotoxy(_X - 5, _Y + 23);
			printf("========================================================================\n");
			break;
			
		case 2:
			_X = getScreenWidth() / 2 - 31;
			_Y = getScreenHeight() / 2 - 16;
			gotoxy(_X - 5, _Y);
			printf("========================================================================\n");
			gotoxy(_X + 25, _Y + 2);
			printf("Register Page\n");
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
			printf("Email");
			gotoxy(_X +20, _Y + 15);
			printf("%c                                      %c\n",186,186);
			gotoxy(_X +20, _Y + 16);
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
			gotoxy(_X +2, _Y + 17);
			printf("\n");
			gotoxy(_X +20, _Y + 18);
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
			gotoxy(_X +4, _Y + 19);
			printf("Password");
			gotoxy(_X +20, _Y + 19);
			printf("%c                                      %c\n",186,186);
			gotoxy(_X +20, _Y + 20);
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
			gotoxy(_X +2, _Y + 21);
			printf("\n");
			gotoxy(_X +20, _Y + 22);
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
			gotoxy(_X +4, _Y + 23);
			printf("Re-password");
			gotoxy(_X +20, _Y + 23);
			printf("%c                                      %c\n",186,186);
			gotoxy(_X +20, _Y + 24);
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
			gotoxy(_X +2, _Y + 25);
			printf("\n");
			gotoxy(_X - 5, _Y + 30);
			printf("========================================================================\n");
			break;
	}
}

void printBanner() {
	int i,j;
	int widthOfScreen = getScreenWidth();
	int heightOfScreen = getScreenHeight();

	system ("cls");
	int _X = widthOfScreen / 2 - 59;
	int _Y = heightOfScreen / 2 - 9;
	
	char as[6][120] ={	"===]   ===]=======]======] ==] ======] =====] ==]          ======]==]  ==]=======] ======]==]  ==]    ==]   ==]======]",
					  	"====] ====|==[____/==[__==]==|==[____/==[__==]==|         ==[____/==|  ==|==[____/==[____/==| ==[/    ==|   ==|==[__==]",
					  	"==[====[==|=====]  ==|  ==|==|==|     =======|==|         ==|     =======|=====]  ==|     =====[/     ==|   ==|======[/",
					  	"==|L==[/==|==[__/  ==|  ==|==|==|     ==[__==|==|         ==|     ==[__==|==[__/  ==|     ==[_==]     ==|   ==|==[___/",
					  	"==| L_/ ==|=======]======[/==|L======]==|  ==|=======]    L======]==|  ==|=======]L======]==|  ==]    L======[/==|",
					  	"L_/     L_/L______/L_____/ L_/ L_____/L_/  L_/L______/     L_____/L_/  L_/L______/ L_____/L_/  L_/     L_____/ L_/"};
	
	char str [50] = "Welcome to";
	gotoxy(_X, _Y - 1);
	for(i = 0; str[i] != '\0'; i ++)
	{
	    printf ("%c", str[i]);
	    Sleep(50);
	}
	
	for (i = 0; i < 6; i++) {
		gotoxy(_X, _Y + 1 + i);
		for (j = 0; j < 120; j++) {
			printASCIIforBanner(as[i][j]);
		}
		printf("\n");
	    Sleep(50);
	}
	
	char subtitle [50] = "to check your health condition simply and easily.";
	gotoxy(_X + 32, _Y + 10);
	for(i = 0; subtitle[i] != '\0'; i ++)
	{
	    printf ("%c", subtitle[i]);
	    Sleep(15);
	}
	
	gotoxy(_X + 38, _Y + 15);
	printf ("[");
    char stra[] = "==================================";
    for(i = 0 ; i <= 40 ; i++) {
		printASCIIforBanner(stra[i]);
        stra[i] = '|';
        Sleep(50);
    }
	printf ("]");
	
	char start [50]= "Press any key to start ...";
	gotoxy(_X + 43, _Y + 18);
	for(i = 0; start[i] != '\0'; i ++)
	{
	    printf ("%c", start[i]);
	    Sleep(50);
	}
	
	Sleep(100);
	gotoxy(_X + 100, _Y + 27);
	printf ("Press x to exit");
	
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
	gotoxy(_X + 69, _Y + 18);
    char inputStart = getch ();
	if (inputStart == 'x') {
		exit (0);
	}
	loginUser ();
}

void printASCIIforBanner(char ch) {
	if (ch == '=') {
		printf("%c", 219);
	}
	else if (ch == '|') {
		printf("%c", 186);
	}
	else if (ch == ']') {
		printf("%c", 187);
	}
	else if (ch == '/') {
		printf("%c", 188);
	}
	else if (ch == '[') {
		printf("%c", 201);
	}
	else if (ch == 'L') {
		printf("%c", 200);
	}
	else if (ch == ' ') {
		printf("%c", 32);
	}
	else if (ch == '_') {
		printf("%c", 205);
	}
}

void lineText(char textType, char lineName[50]) {
	int _X;
	int _Y;
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
			
		case 'b':
			_X = getScreenWidth() / 2 - 31;
			_Y = getScreenHeight() / 2 - 9;
			gotoxy(_X - 18, _Y + 25);
			line(3);
			gotoxy(_X - 18, _Y + 26);
			line(0);
			gotoxy(_X - 18, _Y + 27);
			printf ("|\t%s\t|\n", lineName);
			gotoxy(_X - 18, _Y + 28);
			line(0);
			gotoxy(_X - 18, _Y + 29);
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
