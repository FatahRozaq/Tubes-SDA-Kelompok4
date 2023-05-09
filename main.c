#include "header.h"

int main(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleTextAttribute(hConsole, 229); // asalnya 125, lalu 229 - alternatifnya 245. Ada lagi 252 (merah) atau 249 (biru cerah).
	
    // Make the console windows become full-size
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	
	printBanner ();
}
