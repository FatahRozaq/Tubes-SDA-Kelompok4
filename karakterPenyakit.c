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
    addressKarakterPenyakit current = head;

    if (current == NULL) {
        printf("Tidak ada data.\n");
    } else {
        printf("ID\tNama Penyakit\t\tKarakteristik\n");
        printf("-------------------------------------------------------\n");

        while (current != NULL) {
            printf("%d\t%s\t\t%s\n", current->id, current->namaPenyakit, current->karakteristik);
            current = current->next;
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
    int choice, id;
    char namaPenyakit[50], karakteristik[100], filename[50];

    printf("Masukkan nama file penyimpanan data: ");
    scanf("%s", filename);
    loadListFromFile(&head, filename);

    printf("\n=== SISTEM CRUD LINKED LIST ===\n");
    do {
        printf("\nMenu:\n");
        printf("1. Tambah data karakter penyakit\n");
        printf("2. Tampilkan data karakter penyakit \n");
        printf("3. Ubah data\n");
        printf("4. Hapus data\n");
        printf("0. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Masukkan data baru:\n");
                printf("ID: ");
                scanf("%d", &id);
                printf("Nama Penyakit: ");
                scanf("%s", namaPenyakit);
                printf("Karakteristik: ");
                scanf("%s", karakteristik);
                insertNode(&head, id, namaPenyakit, karakteristik);
                printf("Data berhasil ditambahkan.\n");
                break;
            case 2:
                printf("Data saat ini:\n");
                displayList(head);
                break;
            case 3:
                printf("Masukkan ID data yang ingin diubah: ");
                scanf("%d", &id);
                printf("Masukkan data baru:\n");
                printf("Nama Penyakit: ");
                scanf("%s", namaPenyakit);
                printf("Karakteristik: ");
                scanf("%s", karakteristik);
                updateNode(&head, id, namaPenyakit, karakteristik);
                printf("Data berhasil diubah.\n");
                break;
            case 4:
                printf("Masukkan ID data yang ingin dihapus: ");
                scanf("%d", &id);
                deleteNode(&head, id);
                printf("Data berhasil dihapus.\n");
                break;
            case 0:
                printf("Program selesai.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
                break;
        }
        /* Simpan data ke file setelah setiap operasi */
        saveListToFile(head, filename);
 	}while (choice != 0);
 	
}
