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

alamatJP createlistJP(char* huruf)
{
	alamatJP D;
	D = (alamatJP)malloc(sizeof(jPenyakit)); // alokasi memori sebesar D
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

void insLastJP(alamatJP JP, alamatJP Last){
	prev(JP) = pLastJP;
	next(pLastJP) = JP;
	pLastJP = JP;
}

void viewAsc(alamat First){
	
//	int _X = getScreenWidth() / 2 - 70, _Y = getScreenHeight() / 2 - 16;
	alamat P;
	int i;
	i=1;
	if (First == Nil){
		printf("Daftar Kosong");
	}
		P = First;
	while (P != Nil)
	{
		printf("\t\t\t\t\t\t\t\t\t\t\t\t%d. %s \n", i, info(P));
		P = next(P);
		i++;
	}
}

void viewAscJP(){
	alamatJP P;
	int i;
	i=1;
	if (pFirstJP == Nil){
		printf("Daftar Kosong\n");
	}
		P = pFirstJP;
	while (P != Nil)
	{
		printf("\t\t\t\t\t\t\t\t\t\t\t\t%d. %s \n", i, info(P));
		P = next(P);
		i++;
	}
}


void inputTanya(alamat *First,alamat *Last){
	
	int _X = getScreenWidth() / 2 - 70, _Y = getScreenHeight() / 2 - 16;
	char input[100];
	alamat P;
		gotoxy (_X + 40, _Y + 15);
		printf("Masukkan pertanyaan :");
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
	int _X = getScreenWidth() / 2 - 70, _Y = getScreenHeight() / 2 - 16;
	char input[100];
	alamat P;
		gotoxy (_X + 40, _Y + 15);
		printf("Masukkan Diagnosis :");
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
	int _X = getScreenWidth() / 2 - 70, _Y = getScreenHeight() / 2 - 16;
	gotoxy (_X + 40, _Y + 14);
	printf("1. Input Pertanyaan");
	gotoxy (_X + 40, _Y + 15);
	printf("2. Input Diagnosis");
	gotoxy (_X + 40, _Y + 16);
	printf("3. Daftar Penyakit dan Diagnosis");
	gotoxy (_X + 40, _Y + 17);
	printf("Pilihan : ");
}
address findNodeWithValue(address root, char* value) {
    if (root == NULL) {
        return NULL; // Jika root kosong, return NULL
    }

    if (strcmp(root->question, value) == 0) {
        return root; // Jika nilai root sama dengan value, return root
    }

    address foundNode = findNodeWithValue(root->yes, value); // Cari node pada sub-tree yes
    if (foundNode == NULL) {
        foundNode = findNodeWithValue(root->no, value); // Jika tidak ditemukan pada sub-tree yes, cari pada sub-tree no
    }

    return foundNode;
}
void assignSubvarTree(address destNode, char valueNode[]){
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\tPilih pertanyaan atau diagnosis yang ditampilkan jika No :");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\tDiagnosis awali dengan huruf D (ex:D1)\n");
    scanf("%s",valueNode);
    assignNo(destNode,valueNode);
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\tPilih pertanyaan atau diagnosis yang ditampilkan jika Yes :");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\tDiagnosis awali dengan huruf D (ex:D1)\n");
    scanf("%s",valueNode);
    assignYes(destNode,valueNode);
}

address skemaTree(address root,alamat pPertanyaan, alamat pDiagnosis){
    
    int no;
    char valueNode[2];
    address searchPointer;
    if(isEmpty(root)){
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\tPilih Pertanyaan yang menjadi Root:");
	scanf("%s",&valueNode);
	simpanRoot(valueNode);
    root = createNode(valueNode);
	assignSubvarTree(root,valueNode);

    }
    
	else{
	printTree(root,0);
	printf("\nIngin input ke node apa: ");
	scanf("%s", &valueNode);
	searchPointer=findNodeWithValue(root,valueNode);
	simpanRoot(valueNode);
	assignSubvarTree(searchPointer,valueNode);
	}
    printTree(root,0);
    return root;

}

address membangunModul(){
	char input[100],jenisPenyakit[30];
	alamat P,D,First,Last,pPertanyaan,pDiagnosis;
	address root;
	alamat lastPenyakit,lastDiagnosis;
	alamatJP JP,pSearchJP;
	char choice;
	int pilih, _X = getScreenWidth() / 2 - 70, _Y = getScreenHeight() / 2 - 16;
	lastPenyakit=Nil;
	lastDiagnosis=Nil;
	pPertanyaan = Nil;
	pDiagnosis = Nil;
	root=Nil;
	First=Nil;
	Last=Nil;
	system ("cls");
	layoutXY (6);
	gotoxy (_X + 40, _Y + 11);
	viewAscJP();
	gotoxy (_X + 40, _Y + 12);
	printf("Masukkan jenis penyakit :");
	scanf("%[^\n]",&jenisPenyakit);
	
	if (pFirstJP == Nil){
			JP =createlistJP(jenisPenyakit);
			pFirstJP = JP;
			pLastJP = JP;
		}
		else{
			JP =createlistJP(jenisPenyakit);
			insLastJP(JP,pLastJP);
		}
	simpanJenisPenyakit(jenisPenyakit);
	simpanJPtoSkema(jenisPenyakit);

	
	choice = 'y';
	do{
	system("cls");
	layoutXY (6);
	gotoxy (_X + 40, _Y + 13);
	printf("Jenis Penyakit : %s", jenisPenyakit);
	
	menuPilihanInput();
	scanf("%d",&pilih);
	system ("cls");
	layoutXY (6);
	if(pilih == 1){
		inputTanya(&pPertanyaan,&lastPenyakit);
	}
	
	else if (pilih == 2){
		inputDiagnosis(&pDiagnosis,&lastDiagnosis);
	}
	
	else if (pilih == 3){
		system ("cls");
		layoutXY (9);
//		gotoxy (_X + 40, _Y + 11);
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\tPertanyaan \n");
		viewAsc(pPertanyaan);
//		gotoxy (_X + 40, _Y + 19);
		printf("\n\t\t\t\t\t\t\t\t\t\t\t\tDiagnosis : \n");
		viewAsc(pDiagnosis);
	}
	
	else if(pilih == 4){
	
		system ("cls");
		layoutXY (9);
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\tPertanyaan : \n");
		viewAsc(pPertanyaan);
		printf("\n\t\t\t\t\t\t\t\t\t\t\t\tDiagnosis : \n");
		viewAsc(pDiagnosis);
		
	root =skemaTree(root,pPertanyaan,pDiagnosis);
	JP->tree=root;
	printf("\n\nTree nya adalah root : %s",JP->tree->question);
	}
	
	else if(pilih== 5){
			simpanPertanyaan(pPertanyaan,pDiagnosis);
		return root;
	}
		
		
		
		gotoxy (_X + 40, _Y + 27);
		printf("Kembali ke menu sebelumnya?");
		scanf("\n%c",&choice);
	}while(choice=='y'||choice=='Y');
	
//	viewAsc(First);
//	P=First;
//	while(P!=Nil){
//		simpanPertanyaan(info(P));
//		P=next(P);
//	}
	
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

alamatJP searchJP(char jenPenyakit[]){
	alamatJP Q;
	Q =Nil;
	Q=pFirstJP;
		while(info(Q)!=Nil&&strcmp(info(Q), jenPenyakit)!=0){
						Q=next(Q);
					}
	return Q;
}

void simpanRoot(char root[]){
	
	FILE *fp;
   char ch;
   char *filename = "skemaTree.txt";
   
   fp = fopen(filename, "a");

   /* Write content to file */
   fprintf(fp, "Q%s|", root);

   fclose(fp);

}

void simpanJPtoSkema(char jenisPenyakit[]){
	
	FILE *fp;
   char ch;
   char *filename = "skemaTree.txt";
   
   fp = fopen(filename, "a");

   /* Write content to file */
   fprintf(fp, "JenisPenyakit:%s\n", jenisPenyakit);

   fclose(fp);

}
void simpanJenisPenyakit(char jenisPenyakit[]){
	
	FILE *fp;
   char ch;
   char *filename = "daftarPertanyaan.txt";

 



   
   fp = fopen(filename, "a");

   /* Write content to file */
   fprintf(fp, "JenisPenyakit:%s\n", jenisPenyakit);

   fclose(fp);

}
void simpanPertanyaan(alamat pPertanyaan,alamat pDiagnosis){
	
	FILE *fp;
   char ch;
   char *filename = "daftarPertanyaan.txt";

   int angka;
   angka=1;
   fp = fopen(filename, "a");

   /* Write content to file */
   while(pPertanyaan !=NULL){
   	fprintf(fp, "Q%d|%s\n",angka,pPertanyaan->info);
   	angka++;
   	pPertanyaan=next(pPertanyaan);
   }
   angka=1;
   while(pDiagnosis !=NULL){
   	fprintf(fp, "D%d|%s\n",angka, pDiagnosis->info);
   	angka++;
   	pDiagnosis=next(pDiagnosis);
   }
   

   fclose(fp);

}

//void fileToTree(){
//		FILE *fp;
//   char ch;
//   char *filename = "skemaTree.txt";
//
// 
//
//
//
//   
//   fp = fopen(filename, "a");
//
//   /* Write content to file */
//   //fprintf(fp, "JenisPenyakit:%s\n", jenisPenyakit);
//
//   fclose(fp);
//}


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

void simpanNo(char node[]){
	
	FILE *fp;
   char ch;
   char *filename = "skemaTree.txt";
   
   fp = fopen(filename, "a");

   /* Write content to file */

   
   fprintf(fp, "%s,", node);
 

   fclose(fp);

}

void simpanYes(char node[]){
	
	FILE *fp;
   char ch;
   char *filename = "skemaTree.txt";
   
   fp = fopen(filename, "a");

   /* Write content to file */

   
   fprintf(fp, "%s\n", node);
   
   

   fclose(fp);

}


void assignNo(address nodeTree, char pertanyaan[]){
	address P;
	P=createNode(pertanyaan);
	nodeTree->no=P;
	simpanNo(pertanyaan);
}

void assignYes(address nodeTree, char pertanyaan[]){
	address P;
	P=createNode(pertanyaan);
	nodeTree->yes=P;
	simpanYes(pertanyaan);
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
 if (node == NULL) return;
	int i;
    space += 10;

    printTree(node->yes, space);
    printf("\n");

    for (i = 10; i < space; i++) printf(" ");

    printf("%s", node->question);

    if (node->no != NULL && node->yes != NULL) {
        printLine(space);
    }

    printTree(node->no, space);
}

void DifaDebugging(){
	address root;
	int noPertanyaan;
	rootPenyakit=membangunModul();
	adminPage();
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

//char* startAnalysis(Node *root) {
//    char answer[10];
//    Node *current = root;
//    while (current != NULL) {
//    	if(current->yes != NULL || current->yes != NULL){
//    		printf("%s", current->question);
//	        scanf("%s", answer);
//	        if (strcmp(answer, "y") == 0) {
//				current = current->yes;
//	        } 
//			else if (strcmp(answer, "n") == 0) {
//	            current = current->no;
//	            if (current == NULL) {
//	                return("Anda sehat.\n");
//	            }
//	        } 
//			else {
//	            printf("Maaf, Input yang anda lakukan tidak valid.\n");
//	        }
//		}else{
//			return(current->question);
//		}
//        
//    }
//    
//}

char* startAnalysis(address root) {
    char answer[10];
    char jenPenyakit[20];
    char hasilAkhir[20];
    
    
    printf("Masukan jenis penyakit yang ingin dicari: ");
    scanf("%s", &jenPenyakit);
    alamatJP pointerJP = searchJP(jenPenyakit);
    address current = pointerJP->tree;
    
//    cariFilePenyakit();
    while (current != NULL) {
    	char newStr[4];
    	char* pNewStr = newStr;
    	*pNewStr++ = 'Q';
    	strcpy(pNewStr, current->question);
    	if(current->yes != NULL || current->no != NULL){
    		cariPertanyaanJenisPenyakit("daftarPertanyaan.txt", jenPenyakit, newStr);
//    		printf("%s", current->question);
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
			cariPertanyaanJenisPenyakit("daftarPertanyaan.txt", jenPenyakit, current->question);
//			return(current->question);
		}
        
    }
    
}

void medicalCheckUpResults (char* diseaseResult) {
	int _X = getScreenWidth() / 2 - 70, _Y = getScreenHeight() / 2 - 16;
	system ("cls");
	
	layoutXY (6);
	//hasil cek kesehatan berdasarkan hasil dari startAnalysis
	gotoxy (_X + 40, _Y + 11);
    printf("Penyakit anda : %s", diseaseResult);
	
	//data hasil cek kesehatan yang telah diinputkan pengecek
	
	//rujukan yang didapat sesuai dengan hasil cek kesehatan
	
	medicalCheckUpRecommendation ();
	
	medicalCheckUpDisclaimer();
}

void medicalCheckUpRecommendation () {
	int _X = getScreenWidth() / 2 - 70, _Y = getScreenHeight() / 2 - 16;
	//rekomendasi hal-hal yang perlu dilakukan oleh pengecek
	
	gotoxy (_X + 40, _Y + 13);
	printf (" REKOMENDASI\n");
}

void medicalCheckUpDisclaimer () {
	int _X = getScreenWidth() / 2 - 70, _Y = getScreenHeight() / 2 - 16;
	//disclaimer
	gotoxy (_X + 40, _Y + 21);
	printf (" DISCLAIMER\n");
	gotoxy (_X + 40, _Y + 23);
	printf ("Alat Cek Risiko ini bukanlah pengganti konsultasi medis. Selalu konsultasi\n");
	gotoxy (_X + 40, _Y + 24);
	printf ("ke dokter Anda sebelum memutuskan perawatan terkait sebuah penyakit.\n");
	gotoxy (_X + 40, _Y + 25);
	printf ("Program ini tidak memberikan saran medis, diagnosis, atau perawatan.");

}
