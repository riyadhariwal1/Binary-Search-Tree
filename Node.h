/*
 * Node.h
 *
 *  Created on: Mar 5, 2010
 *      Author: mori
 */

#ifndef NODE_H_
#define NODE_H_

#include "Customer.h"

class Node {
public:
	//constructors
	Node();
	Node(string name, char init, int bal);

	Customer person;
	Node* left;
	Node* right;
	Node* parent;
};

#endif /* NODE_H_ */
