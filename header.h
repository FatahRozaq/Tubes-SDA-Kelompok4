#include <stdio.h>
#include "boolean.h"


typedef  struct Node *address;
typedef struct Node {
	char question[100];
	address yes, no;
};

boolean isEmpty(address root);



