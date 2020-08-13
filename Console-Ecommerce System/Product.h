#pragma once
#ifndef __Product_H
#define __Product_H
using namespace std;
#include <iostream>
class Product
{
public:
	static int product_indicator;
	Product(string category,string name, double price);
	Product(const Product& prod);
	~Product();
	void setCategory(string category);
	void setName(string name);
	void setPrice(double price);
	void setSerial(int number);
	double getPrice()const;
	friend std::ostream& operator<<(std::ostream& os, const Product& pr);
	/*void show();*/
	string getName() const;
	string getCateg()const;
	int getSerial();
private:
	string _category;
	string _name;
	double _price;
	int serial_number;
};

#endif