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

void Delete_Tree(Node *root) {
    if (root == NULL) return;
    Delete_Tree(root->yes);
    Delete_Tree(root->no);
    free(root);
}

void Print_Node(char leaf[]){
	printf("Anda didiagnosa : %s", leaf);
}

void startAnalysis(Node *root) {
    char answer[10];
    printf("%s", root->question);
    scanf("%s", answer);
    if (strcmp(answer, "y") == 0) {
        if (root->yes != NULL) startAnalysis(root->yes);
//        else printf("Anda menderita penyakit jantung!\n");
    } else if (strcmp(answer, "n") == 0) {
        if (root->no != NULL) startAnalysis(root->no);
        else printf("Anda sehat.\n");
    } else {
        printf("Input tidak valid.\n");
        startAnalysis(root);
    }
}

void admin(){
	printf("test admin");
}

void user(){
	printf("test user");
}
