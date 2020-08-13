#include "Product.h"
#include <string.h>
#include <string>
#include <iostream>
using namespace std;
#pragma warning(disable:4996)

int Product::product_indicator = 0;
Product::Product(string category, string name, double price)
{
	serial_number = product_indicator++;
	setCategory(category);
	setName(name);
	setPrice(price);
}

Product::Product(const Product& prod)
{
	setCategory(prod._category);
	setName(prod._name);
	setPrice(prod._price);
	setSerial(prod.serial_number);
}

Product::~Product()
{
}

void Product::setCategory(string category)
{
	
	this->_category = category;
}

void Product::setName(string name)
{
	
	this->_name = name;
}

void Product::setPrice(double price)
{
	this->_price = price;
}

void Product::setSerial(int number)
{
	this->serial_number = number;
}

double Product::getPrice() const
{
	return this->_price;
}


string Product::getName() const
{
	return this->_name;
}

string Product::getCateg() const
{
	return this->_category;
}

int Product::getSerial()
{
	return this->serial_number;
}

std::ostream& operator<<(std::ostream& os, const Product& pr)
{
	os<< "Name: " << pr.getName() << ", Category: " <<pr.getCateg() << ", Price: " <<pr.getPrice() << " .";
	return os;
}
