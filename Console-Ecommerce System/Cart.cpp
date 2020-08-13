#include "Cart.h"
#include <iostream>
#include "Order.h"
using namespace std;

Cart::Cart():numOfItems(0),_productList(0)
{
}



void Cart::addItem(const Product& _order)
{
	numOfItems++;
	/*if (_productList == nullptr) {
		_productList = new Product*[1];
		_productList[0] = &_order;
	}
	else {
		 Product** previous = getProductsList();
		this->_productList = new Product*[numOfItems];
		for (int i = 0; i < numOfItems - 1; i++) {
			this->_productList[i] =new Product(*previous[i]);
		}
		this->_productList[numOfItems - 1] = &_order;
	}*/
	_productList.push_back(new Product(_order));
}

 vector<Product*> Cart::getProductsList() const
{
	return this->_productList;
}

int Cart::getNumOfItems()
{
	return this->numOfItems;
}
double Cart::getSumPrice() const
{
	double total=0;
	for (int i = 0; i < numOfItems; i++) {
		total += _productList[i]->getPrice();
	}
	return total;
}
//passes the serial ID of a product to make the order.
Product* Cart::orderProduct(int serialID)
{
	Product* order = nullptr;
	bool update = false;
	//if (_productList != nullptr) {
		for (int i = 0; i < _productList.size(); i++) {
			if (_productList[i]->getSerial() == serialID) {
				order = new Product(*(_productList[i]));
			    /*_productList[i]=nullptr;
				delete[]_productList[i];
				update = true;*/
				_productList.erase(_productList.begin() + i);
			}
			//else if (update) {//updates the products array inline.
			//	_productList[i-1] = _productList[i];
			//}
		}
		this->numOfItems--;
		/*Product** pr = _productList;
		_productList = new Product * [numOfItems];
		for (int i = 0; i < numOfItems; i++) {
			_productList[i] = new Product(*(pr[i]));
		}*/
	
	return order;
}

bool Cart::show()
{
	if (this->_productList.empty()) {
		cout << "Your cart is empty.";
		return false;
	}
	else {
		for (int i = 0; i < numOfItems; i++) {
			cout << endl;
			cout << (i + 1)<<". ";
			cout<<(*(_productList[i]));
		}
	}
	return true;
}
