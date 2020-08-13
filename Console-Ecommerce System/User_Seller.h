#pragma once
#ifndef __seller_H
#define __seller_H
#include "User.h"
#include "Feedback.h"
#include "Product.h"
#include "Array.h"
#include <vector>
class User_Seller:virtual public User
{
protected:
	Array<Feedback>*_feedbacks;
	vector<Product*> products_list;
	int numOfProducts;
	int numOfFeedbacks;
public:
	User_Seller(const User& user);
	User_Seller(const User_Seller& user);
	virtual ~User_Seller();
	void addFeedback(Feedback& feed);
	void addProduct(Product& product);
	void show();
	Product* findProduct(int serial);
	int getNumOfProducts();
	Array<Feedback> getFeedbacks() const;
	vector<Product*> getProducts() const;
	void showFeedbacks();

};
#endif
