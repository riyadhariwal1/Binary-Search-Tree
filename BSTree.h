/*
 * BSTree.h
 *
 */

#ifndef BSTREE_H_
#define BSTREE_H_

#include "Customer.h"
#include "Node.h"
#include<vector>
#include<string>
using namespace std;

class BSTree {
private:
	friend class Node;

	void deleteTree(Node* node); //helper function for destrcutor
	void inOrder(Node* node); //helper function for print function. couts the customers in order
	void copyTree(Node* oldTree, Node* & newTree); //helper function for copy constructor. takes the root of the old tree to construct the new tree
	bool search(Customer & cust, Node* newNode); //helper function for search. Finds the customer starting at the root
	bool remove(Customer & cust, Node* node); //helper function for remove. 
	Node* findMin(Node* node); //finds the minimum node
	bool empty() const; //checks if tree is empty
	void orderedList(Node* node, vector<Customer>& vec_range); //orders the tree and puts the ordered contents in a vector

public:
	BSTree(); 
	BSTree(const BSTree & rbt); // Copy constructor
	virtual ~BSTree(); 

	// Creates and inserts a new customer (with the data shown in the parameters) in the tree, in a new tree node.
	bool insert(string, char, int);
	//void insert(Node* n);
	//void insert(Customer & c, Node* n);
	// Deletes the first node with a matching name and initial from the tree.
	// Returns true if the deletion was successful (that is, if the customer was found).
	// Note that two customers are equal if they have the same name and initial, regardless of the account balance.
	bool remove(string, char);

	//  Searches the tree for the given value, returning true if the customer is found
	bool search(string, char);

	// Returns a vector of Customers where the customer names (initial and last name)
	// are in the range specified in the parameters.  For example rangeSearch("Dobbs", 'A', "Fogg", D)
	// returns all customers whose names are between Dobbs A and Fogg D.
	vector<Customer> rangeSearch(string, char, string , char);

	// Prints the contents of the tree in sorted order.
	void inOrderPrint();

	Node* root;
};

#endif /* BSTREE_H_ */
