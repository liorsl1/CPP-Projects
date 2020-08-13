#include "User_Seller.h"
#include <iostream>
using namespace std;
#pragma warning(disable:4996)

User_Seller::User_Seller(const User& user):products_list(0),numOfProducts(0),numOfFeedbacks(0),User(user)
{
	_feedbacks =new Array<Feedback>(0);
}

User_Seller::User_Seller(const User_Seller& user):_feedbacks(user._feedbacks), products_list(user.products_list), numOfProducts(user.numOfProducts), numOfFeedbacks(user.numOfFeedbacks), User(user)
{
}

User_Seller::~User_Seller()
{
}


void User_Seller::addFeedback(Feedback& feed)
{
	this->numOfFeedbacks++;
	*(this->_feedbacks) += feed;
	
}

void User_Seller::addProduct(Product& product)
{
	numOfProducts++;
	this->products_list.push_back(new Product(product));
}


Product* User_Seller::findProduct(int serial) {
	for (int i = 0; i < numOfProducts; i++) {
		if (serial == products_list[i]->getSerial()) {
			return products_list[i];
		}
	}
	return nullptr;
}

void User_Seller::show()
{

	cout << *this << endl;
	cout << "Number of Products: " << this->numOfProducts << ", Number of Feedbacks: " << this->numOfFeedbacks<<endl;

}

int User_Seller::getNumOfProducts()
{
	return this->numOfProducts;
}


Array<Feedback> User_Seller::getFeedbacks() const
{
	return *this->_feedbacks;
}


vector<Product*> User_Seller::getProducts() const
{
	return this->products_list;
}

 void User_Seller::showFeedbacks()
 {
	 cout << *_feedbacks;
 }
