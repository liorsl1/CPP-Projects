#pragma once
#ifndef __cart_H
#define __cart_H
#include "Product.h"
#include <vector>

class Cart
{
	private:
		vector<Product*> _productList;
		int numOfItems;
	public:
		Cart();
		void addItem(const Product& _order);
		 vector<Product*> getProductsList() const;
		int getNumOfItems();
		double getSumPrice() const;
		Product* orderProduct(int serialID);
		bool show();
};
#endif