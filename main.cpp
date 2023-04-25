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
			printf("\n1. Admin");
			printf("\n2. User");
			scanf("%d", &pilih);
			switch(pilih){
				case 1:
					admin();
					break;
					
				case 2:
					user();
					break;
			}
			
			break;
			
		case 2:
			printf("\nIni menu register");
			break;
	}
	
	return 0;
}
