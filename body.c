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
	printf("\n4. Menentukan skema tree pertanyaan dan diagnosis");
	printf("\nPilihan : ");
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
void assignSubvarTree(address destNode,alamat pPertanyaan, alamat pDiagnosis, char valueNode[])
{
	int no;
	alamat pointerDiagnosis,pointerPertanyaan;
	printf("\nPilih pertanyaan atau diagnosis yang ditampilkan jika No :");
	printf("\nDiagnosis awali dengan huruf D (ex:1D)\n");
	scanf("%s", valueNode);
	if(strstr(valueNode,"D")){
		no = atoi(valueNode);
		pointerDiagnosis = searchList(pDiagnosis, no);
		assignNo(destNode,info(pointerDiagnosis));
	}
	else{
		no = atoi(valueNode);
		pointerPertanyaan = searchList(pPertanyaan, no);
		assignNo(destNode,info(pointerPertanyaan));	
	}
	
	printf("\nPilih pertanyaan atau diagnosis yang ditampilkan jika Yes :");
	printf("\nDiagnosis awali dengan huruf D (ex:1D)\n");
	scanf("%s", valueNode);
	if(strstr(valueNode,"D")){
		no = atoi(valueNode);
		pointerDiagnosis = searchList(pDiagnosis, no);
		assignYes(destNode,info(pointerDiagnosis));
	}
	else{
		no = atoi(valueNode);
		pointerPertanyaan = searchList(pPertanyaan, no);
		assignYes(destNode,info(pointerPertanyaan));	
	}
}
alamat searchList(alamat First, int noList)
{
	int i;
	alamat Q;
	i = 1;
	Q = First;
	while (info(Q) != Nil && i != noList)
	{
		Q = next(Q);
		i++;
	}
	return Q;
}

address skemaTree(address root, alamat pPertanyaan, alamat pDiagnosis)
{

	int no;
	char valueNode[2];
	char isiNode[100];
	address searchPointer;
	alamat pointerPertanyaan, pointerDiagnosis;
	if (isEmpty(root))
	{
		printf("\n Pilih Pertanyaan yang menjadi Root:");
		scanf("%s", &valueNode);
		if (strstr(valueNode, "D"))
		{
			no = atoi(valueNode);
			pointerDiagnosis = searchList(pDiagnosis, no);
			root = createNode(info(pointerDiagnosis));
		}
		else
		{
			no = atoi(valueNode);
			pointerPertanyaan = searchList(pPertanyaan, no);
			root = createNode(info(pointerPertanyaan));
		}

		assignSubvarTree(root,  pPertanyaan,  pDiagnosis, valueNode);
	}

	else
	{
		printf("\nPertanyaan \n");
		viewAsc(pPertanyaan);
		printf("\nDiagnosis : \n");
		viewAsc(pDiagnosis);
		printTree(root, 8);

		printf("\nIngin input ke node mana: ");
		scanf("%s", &valueNode);
		if (strstr(valueNode, "D"))
		{
			no = atoi(valueNode);
			pointerDiagnosis = searchList(pDiagnosis, no);
			searchPointer = findNodeWithValue(root, info(pointerDiagnosis));
			assignSubvarTree(searchPointer,pPertanyaan,  pDiagnosis, valueNode);
		}
		else
		{
			no = atoi(valueNode);
			pointerPertanyaan = searchList(pPertanyaan, no);
			searchPointer = findNodeWithValue(root, info(pointerPertanyaan));
			assignSubvarTree(searchPointer,pPertanyaan,  pDiagnosis, valueNode);
		}
	}
	printTree(root, 8);
	return root;
}

address membangunModul(){
	char input[100],jenisPenyakit[30];
	alamat P,D,First,Last,pPertanyaan,pDiagnosis;
	address root;
	alamat lastPenyakit,lastDiagnosis;
	char choice;
	int pilih;
	lastPenyakit=Nil;
	lastDiagnosis=Nil;
	pPertanyaan = Nil;
	pDiagnosis = Nil;
	root=Nil;
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
		inputTanya(&pPertanyaan,&lastPenyakit);
	}
	
	else if (pilih == 2){
		inputDiagnosis(&pDiagnosis,&lastDiagnosis);
	}
	
	else if (pilih == 3){
		printf("\nPertanyaan \n");
		viewAsc(pPertanyaan);
		printf("\nDiagnosis : \n");
		viewAsc(pDiagnosis);
	}
	
	else if(pilih == 4){
		printf("\nPertanyaan : \n");
		viewAsc(pPertanyaan);
		printf("\nDiagnosis : \n");
		viewAsc(pDiagnosis);
		
	root =skemaTree(root,pPertanyaan,pDiagnosis);
	}
	
	else if(pilih== 5){
		return root;
	}
		
		
		
		printf("\n\nKembali ke menu sebelumnya?");
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
    address current = root;
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
