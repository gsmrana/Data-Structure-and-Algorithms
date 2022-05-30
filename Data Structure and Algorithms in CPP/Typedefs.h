#ifndef TYPEDEFS__H
#define TYPEDEFS__H

#include <stdint.h>

typedef struct item_node Node;

struct item_node
{
	int value;
	Node* leftNode;
	Node* rightNode;
};


#endif //TYPEDEFS__H