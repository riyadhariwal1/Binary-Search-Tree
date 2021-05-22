/*
 * Node.cpp
 *
 *  Created on: Mar 5, 2010
 *      Author: mori
 */

#include "Node.h"

//default constructor
Node::Node()
: left(NULL), right(NULL), parent(NULL), person(" ", ' ', 0)
{}

//constructor
Node::Node(string name, char init, int bal)
: left(NULL), right(NULL), parent(NULL), person(name, init, bal)
{}