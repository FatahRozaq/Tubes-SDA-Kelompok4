#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "boolean.h"


typedef  struct Node *address;
typedef struct Node {
	char question[100];
	address yes, no;
};

boolean isEmpty(address root);

Node* Create_Node(char question[]);

void Delete_Tree(Node *root);

void Print_Node(char leaf[]);

void admin();

void user();
