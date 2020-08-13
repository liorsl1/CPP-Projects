#include "Order.h"
#include <iostream>
using namespace std;
#pragma warning(disable:4996)

Order::Order(const Product & product, const Address & sellerAddress,string sellerName):sellerAdd(sellerAddress),proInfo(product)
{
	setSellerName(sellerName);
}

Order::Order(const Order& order):proInfo(order.proInfo),sellerAdd(order.sellerAdd)
{
	setSellerName(order.sellerName);
}

void Order::setSellerName(string sellerName)
{
	this->sellerName = sellerName;
}

string Order::getSellerName() const
{
	return sellerName;
}

const Address& Order::getSellerAdd() const
{
	return this->sellerAdd;
}

void Order::show()
{
	cout <<endl<< "Product: "<< proInfo;
	cout << endl << "Sellers Name:" << sellerName;
	cout << endl << "Seller Address: ";sellerAdd.show();
}

