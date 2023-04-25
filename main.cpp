#include "header.h"

int main(){
	int pilih;
	
	printf("1. Login\n");
	printf("2. Register\n");
	printf("Pilih menu : ");
	scanf("%d", &pilih);
	
	switch(pilih){
		case 1:
			printf("\nIni menu login");
			break;
			
		case 2:
			printf("\nIni menu register");
			break;
	}
	
	return 0;
}
