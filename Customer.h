/*
 * Customer.h
 *
 *  Created on: Mar 5, 2010
 *      Author: mori
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <string>
#include <iostream>
using namespace std;

class Customer {
public:
	Customer(string name, char init, int bal);
	Customer();
	
	string get_lastName();
	char get_initial();
	int get_balance();

	void set_balance(int bal);
	void set_all(string name, char init, int bal);

	bool operator<(const Customer & customer) const;
	bool operator<=(const Customer & customer) const;
	bool operator>(const Customer & customer) const;
	bool operator>=(const Customer & customer) const;
	bool operator==(const Customer & customer) const;
	bool operator!=(const Customer & customer) const;

private:
	string lastName;
	char initial;
	int balance;

	friend ostream& operator<<(ostream & os,  Customer & customer);
};

#endif /* CUSTOMER_H_ */
