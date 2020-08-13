#pragma once
#ifndef __buyer_H
#define __buyer_H
#include "User.h"
#include "Cart.h"
#include "OrderHistory.h"
#include "Feedback.h"
#include <vector>

class User_Buyer:virtual public User //continue with polymorphism +operators.
{
protected:
	int indexOfOrders;
	Cart cart;
	vector<OrderHistory*> order_history;
public:
	User_Buyer(const User& user);
	User_Buyer(const User_Buyer& user);
	virtual ~User_Buyer();
	void setUserInfo(User& user);
	void addItem(Product& _order);
	bool showCart();
	double getSumOfCart() const;
	bool operator<(const User_Buyer& b1) const;
	const Address& getProdSeller(int numOfHistory,int numOfOrder);
	string getSellerName(int numOfHistory, int numOfOrder);
	vector<Product*> getProductsInCart() const;
	int getNumOfItemsCart();
	vector<OrderHistory*> getPreviousHistory() const;
	void orderProducts(int numOfProd, vector<Address*> add, vector<int> serialID, vector<string> sellerName);
	void show();
	bool showHistory();
};
#endif
