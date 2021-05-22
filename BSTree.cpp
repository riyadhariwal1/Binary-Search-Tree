/*
 * BSTree.cpp
 *
 *  Created on: Mar 5, 2010
 *      Author: mori
 */

//453
#include "BSTree.h"
#include<vector>
#include<string>
#include<iostream>
using namespace std;


BSTree::BSTree() {
	root = NULL;
}

BSTree::~BSTree(){
	deleteTree(root);
}

//recursively iterates through the tree to delete the tree. 
void BSTree::deleteTree(Node* node){
	if(node != NULL){	
		deleteTree(node->left);
		deleteTree(node->right);
		delete node;
	}
}

//preorder traversal to create a new tree. creates new nodes to put the oldTree's customers in.
void BSTree::copyTree(Node* oldTree, Node* & newTree){
    if (oldTree){
        newTree = new Node;
        newTree->person = oldTree->person; //creates
        copyTree(oldTree->left, newTree->left);
        copyTree(oldTree->right, newTree->right);
    }
}

BSTree::BSTree(const BSTree & rbt){
	if(rbt.root == NULL){
		this->root = NULL;
	}
	else{//the old tree's contents will be copied into the new tree
		copyTree(rbt.root, this->root);
	}
}

bool BSTree::insert(string x, char y, int z) {
	Node* newNode = new Node(x, y, z); //new node, updating person

	if(empty()){
		this->root = newNode; //node becomes root
		return true;
	}
	else if(newNode->person == root->person){ //if person already exists
		return false;
	}
	else{
		Node* cur = this->root; //holds the current root
		while(cur){
			newNode->parent = cur;
			if(newNode->person > cur->person){ //if the node's customer is greater than the root's, 
				cur = cur->right; //the current will update to be the right child
			}
			else if(newNode->person < cur->person){
				cur = cur->left;
			}
			else if (newNode->person == cur->person){
				return false; //person already exists
			}
		}
		if(newNode->person < newNode->parent->person){ //if the node's customer is less than the node's parent's customer,
			newNode->parent->left = newNode; //the left child of the parent will be the node. so newNode becomes the left node since it is smaller
		}
		if(newNode->person > newNode->parent->person){
			newNode->parent->right = newNode;
		}
		else if(newNode->person == newNode->parent->person){ 
			return false;
		}
		delete cur;
		return true;
	}
	delete newNode;
	return false;
}

Node* BSTree::findMin(Node* node){
	if(node == NULL){
		return NULL;
	}
	while(node->left != NULL){ //keeps searching the left subtree till it finds the smallest
		node = node->left;
	}
	return node;
}

bool BSTree::remove(Customer & cust, Node* node) {
	if(node == NULL){
		return false;
	}
	else if(node->person > cust){ //finds the customer
		remove(cust, node->left);
	}
	else if(node->person < cust){
		remove(cust, node->right);
	}
	else if(node->person == cust){
		//if no children
		if(node->left == NULL && node->right == NULL){
			if(node->parent == NULL){ //if the parent is null, you simply delete the node
				delete node;
			}
			else{
				if(node->parent->left == node){ //else, find whether the node is a left or right child and make it null
					node->parent->left = NULL;
				}
				else{
					node->parent->right = NULL;
				}
			}
			delete node;
			return true;
		}
		//only right child
		else if(node->left == NULL && node->right != NULL){
			if(node == root){
				root = node->right; //the root becomes the right most child, updating it
				delete node;
			}  
			else if(node->parent->left == node){ // if the node is the left child,
				node->parent->left = node->right; //left child now holds the value of the right child
				delete node;
			}
			else{
				node->parent->right = node->right;
				delete node;
			}
			return true;
		}
		//only left child
		else if(node->left != NULL && node->right == NULL){ //similar to only right
			if(node == root){
				root = node->left;
				delete node;
			} 
			else if(node->parent->left == node){
				node->parent->left = node->left;
				delete node;
			}
			else{
				node->parent->right = node->left;
				delete node;
			}
			return true;
		}
		//both children
		else if(node->left != NULL && node->right != NULL){
			Node* min = findMin(node->right); //finds min
			node->person = min->person;
			remove(min->person, root->right); //recursively calls
			return true;
		}
		
	}
	return false;
}

bool BSTree::remove(string x, char y) {
	Customer c(x, y, 0);
	if(remove(c, this->root)){
		return true;
	}
	else{
		return false;
	}
}

bool BSTree::search(Customer & cust, Node* newNode){
	if(newNode == NULL){
		return false;
	}
	else if(newNode->person > cust){ //node's cust is greater, it'll search through left
		search(cust, newNode->left);
	}
	else if(newNode->person < cust){ //otherwise, right
		search(cust, newNode->right);
	}
	else if(newNode->person == cust){
		return true;
	}
}

bool BSTree::search(string x, char y) {
	Customer newCust(x, y, 0);

	if(search(newCust, this->root)){
		return true;
	}
	else{
		return false;
	}
}

vector<Customer> BSTree::rangeSearch(string x, char y, string z, char a) {
	Customer start(x, y, 0);
	Customer end(z, a, 0);
	vector<Customer> fullRange_vec; //contains all possible customers in order
	orderedList(root, fullRange_vec);
	vector<Customer> range_vec; //contains the range

	for(int i = 0; i < fullRange_vec.size(); i++){
		if(fullRange_vec[i] >= start && fullRange_vec[i] <= end){ //if between 
			range_vec.push_back(fullRange_vec[i]);
		}
	}
	return range_vec;
}

void BSTree::orderedList(Node* node, vector<Customer>& vec_range){
	if(node != NULL){
		if(node->left){
			orderedList(node->left, vec_range);
		}
		vec_range.push_back(node->person); //puts the customer in a vector in order
		if(node->right) {
			orderedList(node->right, vec_range);
		}
	}
}

void BSTree::inOrder(Node* node){
	if(node != NULL){
		if(node->left){
			inOrder(node->left);
		}
		cout << node->person;
		cout << endl;
		if(node->right) {
			inOrder(node->right);
		}
	}
}

void BSTree::inOrderPrint(){
	inOrder(root);
}

bool BSTree::empty() const{
	return (root == NULL);
}