#include "OrderHistory.h"
#include <iostream>
using namespace std;
#pragma warning(disable:4996)

OrderHistory::OrderHistory(string name,int numOfOrders,const Address& buyerAddres):orders(0),buyerAdd(buyerAddres),numOfOrders(numOfOrders),totalPrice(0)
{
	setBuyerName(name);
}

OrderHistory::OrderHistory(const OrderHistory& history):buyerAdd(history.buyerAdd)
{
	setBuyerName(history.buyerName);
	setOrders(history.orders);
	setTotalPrice(history.totalPrice);
	this->numOfOrders = history.numOfOrders;
}

void OrderHistory::setOrders(vector<Order*> orders)
{
	this->orders = orders;
}


void OrderHistory::setTotalPrice(double total)
{
	this->totalPrice = total+totalPrice;
}

void OrderHistory::setBuyerName(string name)
{
	
	this->buyerName = name;
}

const Order* OrderHistory::getOrder(int num) const
{
	return this->orders[num];
}

void OrderHistory::show()
{
	for (int i = 0; i < numOfOrders; i++) {
		cout << i+1<<". "; orders[i]->show();
		cout << endl;
	}
}
