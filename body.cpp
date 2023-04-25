#include "header.h"

boolean isEmpty(address root){
	if(root == NULL){
		return true;
	}else{
		return false;
	}
}

Node* Create_Node(char question[]) {
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

void admin(){
	printf("test admin");
}

void user(){
	printf("test user");
}
