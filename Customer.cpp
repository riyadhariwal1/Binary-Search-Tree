/*
 * Customer.cpp
 *
 *  Created on: Mar 5, 2010
 *      Author: mori
 */

#include "Customer.h"

Customer::Customer(string name, char init, int bal) 
: lastName(name), initial(init), balance(bal)
{}

Customer::Customer()
: lastName(" "), initial(' '), balance(0)
{}

string Customer::get_lastName(){
	return lastName;
}

char Customer::get_initial(){
	return initial;
}

int Customer::get_balance(){
	return balance;
}

void Customer::set_balance(int bal){
	balance = bal;
}

void Customer::set_all(string name, char init, int bal){
	balance = bal;
	lastName = name;
	initial = init;
}

bool Customer::operator<(const Customer & customer) const{
	if(this->lastName < customer.lastName){
		return true;
	}
	else if(this->lastName > customer.lastName){
		return false;
	}
	else if(this->lastName == customer.lastName){
		if(this->initial < customer.initial){
			return true;
		}
		else{
			return false;
		}
	}
}

bool Customer::operator<=(const Customer & customer) const{
	if(this->lastName < customer.lastName){
		return true;
	}
	else if(this->lastName > customer.lastName){
		return false;
	}
	else if(this->lastName == customer.lastName){
		if(this->initial > customer.initial){
			return false;
		}
		else{
			return true;
		}
	}
}

bool Customer::operator>(const Customer & customer) const{
	if(this->lastName > customer.lastName){
		return true;
	}
	else if(this->lastName < customer.lastName){
		return false;
	}
	else if(this->lastName == customer.lastName){
		if(this->initial > customer.initial){
			return true;
		}
		else{
			return false;
		}
	}
}

bool Customer::operator>=(const Customer & customer) const{
	if(this->lastName > customer.lastName){
		return true;
	}
	else if(this->lastName < customer.lastName){
		return false;
	}
	else if(this->lastName == customer.lastName){
		if(this->initial < customer.initial){
			return false;
		}
		else{
			return true;
		}
	}
}

bool Customer::operator==(const Customer & customer) const{
	if((this->lastName == customer.lastName) && (this->initial == customer.initial)){
		return true;
	}
	else{
		return false;
	}
}

bool Customer::operator!=(const Customer & customer) const{
	if((this->lastName != customer.lastName) || (this->initial != customer.initial)){
		return true;
	}
	else{
		return false;
	}
}


ostream& operator<<(ostream & os,  Customer & customer) {
	os << customer.lastName << ", " << customer.initial << ". (" << customer.balance << ")"; 
	return os;
}