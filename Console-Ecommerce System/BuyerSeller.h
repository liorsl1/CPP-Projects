#pragma once
#ifndef __buysel_H
#define __buysel_H
#include "User_Buyer.h"
#include "User_Seller.h"
class BuyerSeller:public User_Buyer, public User_Seller
{
public:
	BuyerSeller(const User& user);
	void show();
	~BuyerSeller();
};
#endif