#include "header.h"

boolean isEmpty(address root){
	if(root == NULL){
		return true;
	}else{
		return false;
	}
}

Node* createNode(char question[]) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    strcpy(newNode->question, question);
    newNode->yes = NULL;
    newNode->no = NULL;
    return newNode;
}

alamat createlist(char* huruf)
{
	alamat D;
	D = (alamat)malloc(sizeof(ElmtList)); // alokasi memori sebesar D
	info(D) = (char*)malloc((strlen(huruf)+1)*sizeof(char)); // alokasi memori sebesar string huruf yang akan disimpan
	strcpy(info(D), huruf); // salin string ke dalam node
	next(D) = Nil;						   // membuat list menunjuk ke nil
	prev(D) = Nil;
	return D;
}

void insLast(alamat *P, alamat *Last){
	prev(*P) = *Last;
	next(*Last) = *P;
	*Last = *P;
}

void viewAsc(alamat First){
	alamat P;
	int i;
	i=1;
	if (First == Nil){
		printf("Daftar Kosong");
	}
		P = First;
	while (P != Nil)
	{
		printf("%d. %s \n", i, info(P));
		P = next(P);
		i++;
	}
}

void inputTanya(alamat *First,alamat *Last){
	
	char input[100];
	alamat P;
		printf("\nMasukkan pertanyaan :");
		scanf("\n%[^\n]", input); // membaca input string dari pengguna
		
		if (*First == Nil){
			P = createlist(input);
			*First = P;
			*Last = P;
		}
		else{
			P = createlist(input);
			insLast(&P,Last);
		}
	
}
void inputDiagnosis(alamat *First,alamat *Last){
	
	char input[100];
	alamat P;
		printf("\nMasukkan Diagnosis :");
		scanf("\n%[^\n]", input); // membaca input string dari pengguna
		
		if (*First == Nil){
			P = createlist(input);
			*First = P;
			*Last = P;
		}
		else{
			P = createlist(input);
			insLast(&P,Last);
		}
	
}

void menuPilihanInput(){
	printf("\n1. Input Pertanyaan");
	printf("\n2. Input Diagnosis");
	printf("\n3. Daftar Penyakit dan Diagnosis");
	printf("\nPilihan : ");
}

alamat membangunModul(){
	char input[100],jenisPenyakit[30];
	alamat P,D,First,Last,pPenyakit,pDiagnosis;
	alamat lastPenyakit,lastDiagnosis;
	char choice;
	int pilih;
	lastPenyakit=Nil;
	lastDiagnosis=Nil;
	pPenyakit = Nil;
	pDiagnosis = Nil;
	First=Nil;
	Last=Nil;
	printf("\nMasukkan jenis penyakit :");
	scanf("%[^\n]",&jenisPenyakit);
	
	

	
	choice = 'y';
	do{
	system("cls");
	printf("\nJenis Penyakit : %s", jenisPenyakit);
	
	menuPilihanInput();
	scanf("%d",&pilih);
	
	if(pilih == 1){
		inputTanya(&pPenyakit,&lastPenyakit);
	}
	
	else if (pilih == 2){
		inputDiagnosis(&pDiagnosis,&lastDiagnosis);
	}
	
	else if (pilih == 3){
		printf("\nPenyakit : \n");
		viewAsc(pPenyakit);
		printf("\nDiagnosis : \n");
		viewAsc(pDiagnosis);
	}
		
		
		
		printf("\nKembali ke menu sebelumnya?");
		scanf("\n%c",&choice);
	}while(choice=='y'||choice=='Y');
	
	viewAsc(First);
	P=First;
	while(P!=Nil){
	//	simpanPertanyaan(info(P));
		P=next(P);
	}
	return First;
}

void deleteTree(Node *root) {
    if (root == NULL) return;
    deleteTree(root->yes);
    deleteTree(root->no);
    free(root);
}
alamat searchPertanyaan(alamat First, int noPertanyaan){
	int i;
	alamat Q;
	i=1;
	Q=First;
		while(info(Q)!=Nil&&i!=noPertanyaan){
						Q=next(Q);
						i++;
					}
	return Q;
}
void simpanPertanyaan(char pertanyaan[]){
	
	FILE *fp;
   char ch;
   char *filename = "daftarPertanyaan.txt";

   int angka;



   
   fp = fopen(filename, "a");

   /* Write content to file */
   fprintf(fp, "%s\n", pertanyaan);

   fclose(fp);

}
void createTree(alamat First){
	int pertanyaan;
	alamat pointPertanyaan;
	printf("\nMembuat modul penyakit :");
	viewAsc(First);
	printf("\n Pilih Pertanyaan yang menjadi Root:");
	scanf("%d",&pertanyaan);
	pointPertanyaan=searchPertanyaan(First,pertanyaan);
	printf("\n%s", info(pointPertanyaan));
}

void menuPertanyaan(alamat First){
	system("cls");
	int pilihan;
	viewAsc(First);

	printf("\nPilihan :");
	printf("\n1. Buat Modul Penyakit Berdasarkan Pertanyaan(Tree)");
	printf("\n2. Tambahkan pertanyaan");
	printf("\n3. Hapus pertanyaan");
	printf("\n4. Edit pertanyaan\n");
	scanf("%d",&pilihan);

	if(pilihan ==1){
		createTree(First);
	}
	else if(pilihan == 2){

	}
	else if(pilihan == 3){

	}
	else if(pilihan == 4){

	}
}

void printNode(char leaf[]){
	printf("Anda didiagnosa : %s", leaf);
}

void assignNo(address nodeTree, char pertanyaan[]){
	address P;
	P=createNode(pertanyaan);
	nodeTree->no=P;
}

void assignYes(address nodeTree, char pertanyaan[]){
	address P;
	P=createNode(pertanyaan);
	nodeTree->yes=P;
}

// Mencetak garis penghubung antara node dalam Binary Tree
void printLine(int space) {
	int i;
    for (i = 0; i < space; i++) {
        printf(" ");
    }
    printf("\n");
}

// Menampilkan Binary Tree dengan notasi grafik
void printTree(address node, int space) {
	int i;
    if (node == NULL) return;

    space += 10;

    printTree(node->no, space);
    printf("\n");
}

//char* startAnalysis(Node *root) {
//
//    for (i = 10; i < space; i++) printf(" ");
//
//    printf("%s", node->question);
//
//    if (node->yes != NULL && node->no != NULL) {
//        printLine(space);
//    }
//
//    printTree(node->yes, space);
//}

char* startAnalysis(Node *root) {
    char answer[10];
    Node *current = root;
    while (current != NULL) {
    	if(current->yes != NULL || current->yes != NULL){
    		printf("%s", current->question);
	        scanf("%s", answer);
	        if (strcmp(answer, "y") == 0) {
				current = current->yes;
	        } 
			else if (strcmp(answer, "n") == 0) {
	            current = current->no;
	            if (current == NULL) {
	                return("Anda sehat.\n");
	            }
	        } 
			else {
	            printf("Maaf, Input yang anda lakukan tidak valid.\n");
	        }
		}else{
			return(current->question);
		}
        
    }
    
}

void medicalCheckUpResults (char* diseaseResult) {
	//hasil cek kesehatan berdasarkan hasil dari startAnalysis
    printf("Penyakit anda : %s", diseaseResult);
	
	//data hasil cek kesehatan yang telah diinputkan pengecek
	
	//rujukan yang didapat sesuai dengan hasil cek kesehatan
	
	medicalCheckUpRecommendation ();
	
	medicalCheckUpDisclaimer();
}

void medicalCheckUpRecommendation () {
	//rekomendasi hal-hal yang perlu dilakukan oleh pengecek
}

void medicalCheckUpDisclaimer () {
	int _X = getScreenWidth() / 2 - 70, _Y = getScreenHeight() / 2 - 16;
	//disclaimer
	printf("\n\nAlat Cek Risiko ini bukanlah pengganti konsultasi medis. Selalu konsultasi\n");
	printf("ke dokter Anda sebelum memutuskan perawatan terkait sebuah penyakit.\n");
	printf("Hello Sehat tidak memberikan saran medis, diagnosis, atau perawatan.");

}
