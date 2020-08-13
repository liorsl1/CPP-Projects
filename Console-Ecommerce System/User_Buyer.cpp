#include "User_Buyer.h"
#include <iostream>
using namespace std;

User_Buyer::User_Buyer(const User& user):order_history(0),indexOfOrders(0),User(user)
{
	
}

User_Buyer::User_Buyer(const User_Buyer& user):order_history(user.order_history), indexOfOrders(user.indexOfOrders), User(user)
{
	
}

User_Buyer::~User_Buyer()
{
}

void User_Buyer::addItem(Product& _order)
{
	this->cart.addItem(_order);
}

bool User_Buyer::showCart()
{
	return this->cart.show();
}

double User_Buyer::getSumOfCart() const
{
	return cart.getSumPrice();
}

//operator < compares between total price of carts.
bool User_Buyer::operator<(const User_Buyer& b1) const 
{
	return (this->getSumOfCart()<b1.getSumOfCart()) ? true:false;
}
const Address& User_Buyer::getProdSeller(int numOfHistory,int numOfOrder) /*sends the address of the right seller by chosen order.
																		  later on the address will be used to identify the seller.*/
{
	const Order* ord= order_history[numOfHistory]->getOrder(numOfOrder);
	return ord->getSellerAdd();
}

string User_Buyer::getSellerName(int numOfHistory, int numOfOrder)
{
	const Order* ord= order_history[numOfHistory]->getOrder(numOfOrder);
	return ord->getSellerName();
}


vector<Product*> User_Buyer::getProductsInCart() const
{

	return cart.getProductsList();
}

int User_Buyer::getNumOfItemsCart()
{
	return cart.getNumOfItems();
}

vector<OrderHistory*> User_Buyer::getPreviousHistory() const
{
	return order_history;
}


void User_Buyer::orderProducts(int numOfProd,vector<Address*> add,vector<int> serialID,vector<string> sellerName)
{
	double totalPrice=0;
	vector<Order*> order;
	for (int i = 0; i < numOfProd; i++) {
		Product* pr = cart.orderProduct(serialID[i]);
		order.push_back(new Order(*pr,*(add[i]), sellerName[i]));
		totalPrice += pr->getPrice();
	}
	//here we finished creating the orders, now insert to the order history.
	indexOfOrders++;
	order_history.push_back(new OrderHistory(this->user_Name, numOfProd, this->_address));
	order_history[order_history.size()-1]->setOrders(order);
	order_history[order_history.size() - 1]->setTotalPrice(totalPrice);
}

void User_Buyer::show()
{
	cout << *this<<endl;
	cout << "Items count: " << getNumOfItemsCart()<<endl;
}

bool User_Buyer::showHistory()
{
	if (order_history.empty()) {
		cout << "No previous orders to be found." << endl;
		return false;
	}
	else {
		for (int i = 0; i < indexOfOrders; i++) {
			cout << "Order No. "<<i+1 << ". "<<endl; order_history[i]->show();
			cout << endl;
		}
		return true;
	}
}
