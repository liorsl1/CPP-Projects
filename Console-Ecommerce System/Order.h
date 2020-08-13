#pragma once
#ifndef __Order_H
#define __Order_H
#include "Product.h"
#include "Address.h"
#include <string.h>
class Order
{
private:
	Product proInfo;
	string sellerName;
	Address sellerAdd;
public:
	Order(const Product& product, const Address& sellerAdd,string sellerName);
	Order(const Order& order);
	void setSellerName(string sellerName);
	string getSellerName() const;
	const Address& getSellerAdd()const;
	void show();
};
#endif