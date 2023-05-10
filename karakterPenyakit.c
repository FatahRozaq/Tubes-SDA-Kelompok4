#include "header.h"

/* Fungsi untuk membuat node baru */
addressKarakterPenyakit createNodePenyakit(int id, char* namaPenyakit, char* karakteristik) {
    addressKarakterPenyakit newNode = (addressKarakterPenyakit) malloc(sizeof(karakterPenyakit));
    newNode->id = id;
    strcpy(newNode->namaPenyakit, namaPenyakit);
    strcpy(newNode->karakteristik, karakteristik);
    newNode->next = NULL;
    return newNode;
}

void insertNode(addressKarakterPenyakit *head, int id, char* namaPenyakit, char* karakteristik) {
    addressKarakterPenyakit current = *head;
    addressKarakterPenyakit newNode = createNodePenyakit(id, namaPenyakit, karakteristik);

    if (*head == NULL) {
        *head = newNode;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void deleteNode(addressKarakterPenyakit *head, int id) {
    addressKarakterPenyakit current = *head;
    addressKarakterPenyakit prev = NULL;

    if (current != NULL && current->id == id) {
        *head = current->next;
        free(current);
        return;
    }

    while (current != NULL && current->id != id) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        return;
    }

    prev->next = current->next;
    free(current);
}

void updateNode(addressKarakterPenyakit *head, int id, char* namaPenyakit, char* karakteristik) {
    addressKarakterPenyakit current = *head;

    while (current != NULL && current->id != id) {
        current = current->next;
    }

    if (current != NULL) {
        strcpy(current->namaPenyakit, namaPenyakit);
        strcpy(current->karakteristik, karakteristik);
    }
}

void saveListToFile(addressKarakterPenyakit head, char* filename) {
    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        printf("Gagal membuka file %s.\n", filename);
    } else {
        addressKarakterPenyakit p = head;
        while (p != NULL) {
            fprintf(file, "%d,%s,%s\n", p->id, p->namaPenyakit, p->karakteristik);
            p = p->next;
        }

        printf("Data berhasil disimpan ke file %s.\n", filename);
        fclose(file);
    }
}

void displayList(addressKarakterPenyakit head) {
	int _X = getScreenWidth() / 2 - 70, _Y = getScreenHeight() / 2 - 16, i = 0;
    addressKarakterPenyakit current = head;

    if (current == NULL) {
		gotoxy(_X + 45, _Y + 13);
        printf("Tidak ada data.\n");
    } else {
		gotoxy(_X + 45, _Y + 13);
        printf("ID\tNama Penyakit\t\tKarakteristik\n");
		gotoxy(_X + 45, _Y + 14);
        printf("-------------------------------------------------------\n");

        while (current != NULL) {
			gotoxy(_X + 45, _Y + 15 + i);
            printf("%d\t%s\t\t%s\n", current->id, current->namaPenyakit, current->karakteristik);
            current = current->next;
            i++;
        }
    }
}

void loadListFromFile(addressKarakterPenyakit *head, char* filename) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Gagal membuka file %s.\n", filename);
    } else {
        int id;
        char namaPenyakit[50], karakteristik[100];
        char line[200];

        while (fgets(line, sizeof(line), file)) {
            sscanf(line, "%d,%[^,],%[^\n]", &id, namaPenyakit, karakteristik);
            insertNode(head, id, namaPenyakit, karakteristik);
        }

        printf("Data berhasil dimuat dari file %s.\n", filename);
        fclose(file);
    }
}

void karakteristikPenyakit(){
	addressKarakterPenyakit head = NULL;
    char namaPenyakit[50], karakteristik[100], filename[50], inputKarakteristikPenyakit;
    int id, choice, menu = 1, profile = 1, a, _X = getScreenWidth() / 2 - 70, _Y = getScreenHeight() / 2 - 16;
	
	system ("cls");
	
	layoutXY (6);
    /* Load data dari file saat program dimulai */
	gotoxy (_X + 40, _Y + 11);
    printf("Masukkan nama file penyimpanan data: ");
    scanf("%s", filename);
	gotoxy (_X + 40, _Y + 13);
    loadListFromFile(&head, filename);
	getch ();
	
	system ("cls");
	for (;;) {
		layoutXY (7);
		
		gotoxy(_X + 28, _Y + 26);
		scanf (" %c", &inputKarakteristikPenyakit);
		
		if (inputKarakteristikPenyakit == 'm' || inputKarakteristikPenyakit == 'M') {
			if (menu == 1) {
				menu = 0;
				gotoxy(_X + 55, _Y + 15);
				printf ("%c          TAMBAH DATA (1)         %c", 186, 186);
				gotoxy(_X + 55, _Y + 16);
				printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205, 205, 205, 205, 205,205,205,205,205 ,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205, 205, 205,188);
				
				gotoxy(_X + 55, _Y + 17);
				printf ("%c        TAMPILKAN DATA (2)        %c", 186, 186);
				gotoxy(_X + 55, _Y + 18);
				printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205, 205, 205, 205, 205,205,205,205,205 ,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205, 205, 205,188);
				
				gotoxy(_X + 55, _Y + 19);
				printf ("%c           UBAH DATA (3)          %c", 186, 186);
				gotoxy(_X + 55, _Y + 20);
				printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205, 205, 205, 205, 205,205,205,205,205 ,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205, 205, 205,188);
	
				gotoxy(_X + 55, _Y + 21);
				printf ("%c          HAPUS DATA (4)          %c", 186, 186);
				gotoxy(_X + 55, _Y + 22);
				printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205, 205, 205, 205, 205,205,205,205,205 ,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205, 205, 205,188);
				
				gotoxy(_X + 55, _Y + 23);
				printf ("%c             BACK (X)             %c", 186, 186);
				gotoxy(_X + 55, _Y + 24);
				printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205, 205, 205, 205, 205,205,205,205,205 ,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205, 205, 205,188);
		
			}
			else {
				menu = 1;
				system ("cls");
			}
		}
		else if (menu == 0 && (inputKarakteristikPenyakit == '1')) {
			system ("cls");
			layoutXY (6);
			gotoxy(_X + 55, _Y + 11);
            printf("Masukkan data baru:\n");
			gotoxy(_X + 55, _Y + 12);
            printf("ID: ");
            scanf("%d", &id);
			gotoxy(_X + 55, _Y + 13);
            printf("Nama Penyakit: ");
            scanf("%s", namaPenyakit);
			gotoxy(_X + 55, _Y + 14);
            printf("Karakteristik: ");
            scanf("%s", karakteristik);
			gotoxy(_X + 55, _Y + 15);
            insertNode(&head, id, namaPenyakit, karakteristik);
			gotoxy(_X + 55, _Y + 17);
            printf("Data berhasil ditambahkan.\n");
			gotoxy(_X + 55, _Y + 19);
        	saveListToFile(head, filename);
        	getch ();
			menu = 1;
			system ("cls");
		}
		else if (menu == 0 && (inputKarakteristikPenyakit == '2')) {
			system("cls");
			layoutXY (6);
			gotoxy(_X + 45, _Y + 11);
            printf("Data saat ini:\n");
            displayList(head);
			gotoxy(_X + 55, _Y + 19);
        	getch ();
			menu = 1;
			system ("cls");
		}
		else if (menu == 0 && (inputKarakteristikPenyakit == '3')) {
			system("cls");
			layoutXY (6);
			gotoxy(_X + 55, _Y + 11);
            printf("Masukkan ID data yang ingin diubah: ");
            scanf("%d", &id);
			gotoxy(_X + 55, _Y + 12);
            printf("Masukkan data baru:\n");
			gotoxy(_X + 55, _Y + 13);
            printf("Nama Penyakit: ");
            scanf("%s", namaPenyakit);
			gotoxy(_X + 55, _Y + 14);
            printf("Karakteristik: ");
            scanf("%s", karakteristik);
			gotoxy(_X + 55, _Y + 15);
            updateNode(&head, id, namaPenyakit, karakteristik);
			gotoxy(_X + 55, _Y + 17);
            printf("Data berhasil diubah.\n");
			gotoxy(_X + 55, _Y + 19);
        	saveListToFile(head, filename);
        	getch ();
			menu = 1;
			system ("cls");
		}
		else if (menu == 0 && (inputKarakteristikPenyakit == '4')) {
			system ("cls");
			layoutXY (6);
			gotoxy(_X + 55, _Y + 11);
            printf("Masukkan ID data yang ingin dihapus: ");
            scanf("%d", &id);
			gotoxy(_X + 55, _Y + 12);
            deleteNode(&head, id);
			gotoxy(_X + 55, _Y + 14);
            printf("Data berhasil dihapus.\n");
			gotoxy(_X + 55, _Y + 19);
        	saveListToFile(head, filename);
        	getch ();
			menu = 1;
			system ("cls");
		}
		else if (menu == 0 && (inputKarakteristikPenyakit == 'x' || inputKarakteristikPenyakit == 'X')) {
			adminPage ();
		}
	}
}
