#include "header.h"

// Fungsi untuk menambah node pada linked list
void addNode(addressKarakterPenyakit* headRef, int newId, char* newName, char* newAddress) {
    addressKarakterPenyakit newNode = (addressKarakterPenyakit)malloc(sizeof(karakterPenyakit));
    newNode->id = newId;
    strcpy(newNode->namaPenyakit, newName);
    strcpy(newNode->karakteristik, newAddress);
    newNode->next = *headRef;
    *headRef = newNode;
}

// Fungsi untuk mencari node pada linked list
addressKarakterPenyakit findNode(addressKarakterPenyakit head, int id) {
    addressKarakterPenyakit current = head;
    while (current != NULL) {
        if (current->id == id) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Fungsi untuk menghapus node dari linked list
void deleteNode(addressKarakterPenyakit* headRef, int id) {
    addressKarakterPenyakit current = *headRef;
    addressKarakterPenyakit previous = NULL;
    while (current != NULL) {
        if (current->id == id) {
            if (previous == NULL) {
                *headRef = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            printf("Data dengan id %d telah dihapus\n", id);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Data dengan id %d tidak ditemukan\n", id);
}

// Fungsi untuk mengedit node pada linked list
void editNode(addressKarakterPenyakit head, int id) {
    addressKarakterPenyakit nodeToEdit = findNode(head, id);
    if (nodeToEdit == NULL) {
        printf("Data dengan id %d tidak ditemukan\n", id);
        return;
    }
    char namaPenyakit[50];
    char karakteristik[100];
    printf("Nama (sebelumnya: %s): ", nodeToEdit->namaPenyakit);
    scanf("%s", namaPenyakit);
    printf("Alamat (sebelumnya: %s): ", nodeToEdit->karakteristik);
    scanf("%s", karakteristik);
    strcpy(nodeToEdit->namaPenyakit, namaPenyakit);
    strcpy(nodeToEdit->karakteristik, karakteristik);
    printf("Data dengan id %d telah diubah\n", id);
}

void karakteristikPenyakit(){
	int choice, id, newId;
    char namaPenyakit[50], karakteristik[100];
    addressKarakterPenyakit head = NULL;

    // Memuat data dari file teks dan menambahkannya pada linked list
    FILE* fp = fopen("karakterPenyakit.txt", "r");
    
    if (fp != NULL) {
	    char line[256];
	    while (fgets(line, sizeof(line), fp)) {
	        // Memecah baris menjadi tiga bagian: id, nama, dan alamat
	        char* token = strtok(line, ";");
	        newId = atoi(token);
	        token = strtok(NULL, ";");
	        strcpy(namaPenyakit, token);
	        token = strtok(NULL, ";");
	        strcpy(karakteristik, token);
	
	        // Menambah node pada linked list
	        addNode(&head, newId, namaPenyakit, karakteristik);
	    }
	    fclose(fp);
	    printf("Data berhasil dimuat dari file karakterPenyakit.txt\n");
	}

	// Menu utama
	while (1) {
	    printf("\n");
	    printf("========== MENU UTAMA ==========\n");
	    printf("1. Tambah data\n");
	    printf("2. Edit data\n");
	    printf("3. Hapus data\n");
	    printf("4. Lihat data\n");
	    printf("5. Simpan ke file\n");
	    printf("0. Back\n");
	    printf("Pilihan: ");
	    scanf("%d", &choice);
	
	    switch (choice) {
	        case 1:
	            // Menambah data baru
	            printf("Masukkan id: ");
	            scanf("%d", &id);
	            fflush(stdin);
	            if (findNode(head, id) != NULL) {
	                printf("Data dengan id %d sudah ada\n", id);
	                break;
	            }
	            printf("Masukkan nama: ");
	            scanf("%[^\n]s", &namaPenyakit);
	            fflush(stdin);
	            printf("Masukkan alamat: ");
	            scanf("%[^\n]s", &karakteristik);
	            fflush(stdin);
	            addNode(&head, id, namaPenyakit, karakteristik);
	            printf("Data dengan id %d berhasil ditambahkan\n", id);
	            break;
	
	        case 2:
	            // Mengedit data
	            printf("Masukkan id data yang ingin diubah: ");
	            scanf("%d", &id);
	            editNode(head, id);
	            break;
	
	        case 3:
	            // Menghapus data
	            printf("Masukkan id data yang ingin dihapus: ");
	            scanf("%d", &id);
	            deleteNode(&head, id);
	            break;
	
	        case 4:
	            // Menampilkan data
	            printf("\n");
	            printf("=========================================\n");
	            printf("| %-4s | %-36s | %-60s |\n", "ID", "Nama Penyakit", "Karakter Penyakit");
	            printf("=========================================\n");
	            addressKarakterPenyakit current = head;
	            while (current != NULL) {
	                printf("| %-4d | %-36s | %-60s |\n", current->id, current->namaPenyakit, current->karakteristik);
	                current = current->next;
	            }
	            printf("=========================================\n");
	            break;
	
	        case 5:
	            // Menyimpan linked list ke file teks
	            saveList(head, "karakterPenyakit.txt");
	            break;
	
	        case 0:
	            // Keluar dari program
	            printf("Program berakhir\n");
	            return 0;
	
	        default:
	            printf("Pilihan tidak valid\n");
	            break;
	    }
	}

	
}

void saveList(addressKarakterPenyakit head, char* filename) {
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Tidak bisa membuka file: %s\n", filename);
        return;
    }
    addressKarakterPenyakit current = head;
    while (current != NULL) {
        fprintf(fp, "%d_%s_%s\n", current->id, current->namaPenyakit, current->karakteristik);
        current = current->next;
    }
    fclose(fp);
    printf("Data linked list tersimpan dalam file: %s\n", filename);
}


