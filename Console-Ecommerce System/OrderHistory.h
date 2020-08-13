#pragma once
#ifndef __history_H
#define __history_H
#include "Order.h"
#include <vector>

class OrderHistory
{
private:
	vector<Order*> orders;
	int numOfOrders;
	double totalPrice;
	string buyerName;
	Address buyerAdd;
public:
	OrderHistory(string name,int numOfOrders,const Address& buyerAddres);
	OrderHistory(const OrderHistory& history);
	void setOrders(vector<Order*> orders);
	void setTotalPrice(double total);
	void setBuyerName(string name);
	const Order* getOrder(int num) const;
	void show();
};
#endif

