#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

void cariPertanyaanJenisPenyakit(const char* nama_file, const char* jenis_penyakit, const char* nomor_pertanyaan) {
    FILE* file = fopen(nama_file, "r");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    char line[MAX_LINE_LENGTH];
    int is_jenis_penyakit = 0;

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        if (strncmp(line, "JenisPenyakit:", 14) == 0) {
            char* penyakit = line + 14;
            size_t penyakit_len = strlen(penyakit);
            if (penyakit[penyakit_len - 1] == '\n') {
                penyakit[penyakit_len - 1] = '\0'; // Menghapus karakter newline jika ada
            }
            if (strcmp(penyakit, jenis_penyakit) == 0) {
                is_jenis_penyakit = 1;
            } else {
                is_jenis_penyakit = 0;
            }
        } else if (is_jenis_penyakit && line[0] == 'Q' || is_jenis_penyakit && line[0] == 'D') {
            char nomor[MAX_LINE_LENGTH];
            sscanf(line, "%[^|]", nomor); // Membaca nomor pertanyaan dari baris

            if (strcmp(nomor, nomor_pertanyaan) == 0) {
            	if(is_jenis_penyakit && line[0] == 'Q'){
            		printf("Pertanyaan: %s", line);
				}else if(is_jenis_penyakit && line[0] == 'D'){
					printf("Diagnosis: %s", line);
//					exit(0);
				}
                
            }
        }
    }

    fclose(file);
}

void cariFilePenyakit() {
    const char* nama_file = "daftarPertanyaan.txt";
    char done;
    char jenis_penyakit[MAX_LINE_LENGTH];
    char nomor_pertanyaan[MAX_LINE_LENGTH];

    printf("Masukkan jenis penyakit yang ingin dicari: ");
    fgets(jenis_penyakit, MAX_LINE_LENGTH, stdin);
    jenis_penyakit[strcspn(jenis_penyakit, "\n")] = '\0'; // Menghapus karakter newline jika ada

    while (1) {
        printf("Masukkan nomor pertanyaan yang ingin dicari (tekan Enter untuk menghentikan): ");
        fgets(nomor_pertanyaan, MAX_LINE_LENGTH, stdin);
        nomor_pertanyaan[strcspn(nomor_pertanyaan, "\n")] = '\0'; // Menghapus karakter newline jika ada

        if (strlen(nomor_pertanyaan) == 0) {
            break; // Hentikan pengulangan jika input kosong
        }

        cariPertanyaanJenisPenyakit(nama_file, jenis_penyakit, nomor_pertanyaan);
    }
    
    printf("\nProgram selesai");
    scanf(" %c", &done);
}

