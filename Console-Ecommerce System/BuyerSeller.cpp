#include "BuyerSeller.h"

BuyerSeller::BuyerSeller(const User& user):User(user),User_Buyer(user),User_Seller(user)
{

}

void BuyerSeller::show()
{
	User_Seller::show();
	cout << "Items count: " << getNumOfItemsCart() << endl;
}


BuyerSeller::~BuyerSeller()
{
}
