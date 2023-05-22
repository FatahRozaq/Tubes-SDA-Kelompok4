#include "header.h"

int main(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleTextAttribute(hConsole, 229); // asalnya 125, lalu 229 - alternatifnya 245. Ada lagi 252 (merah) atau 249 (biru cerah).
	
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	
	system("title Medical Check Up");
	pFirstJP=Nil;
	pLastJP=Nil;
	DifaDebugging();
	
	printBanner ();
}
