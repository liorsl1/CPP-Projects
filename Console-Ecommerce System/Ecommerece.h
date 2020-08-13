#ifndef __ECOMM_H
#define __ECOMM_H
#include <iostream>
#include <string.h>
#include "User_Buyer.h"
#include "User_Seller.h"
#include "BuyerSeller.h"
#include "OrderHistory.h"
#include <vector>
#include <fstream>
using namespace std;

#pragma warning(disable: 4996) 
class Ecommerece /*check for other inheritance options like orders and such, and implement operators.
				 and add the option for creating a buyer and seller account. (the buyer implements from seller the seller attributes,(seller is a type of buyer)). */
{
private:
	string _name;
	vector<User*> Users;
	int BuyersCount;
	int SellersCount;
	int SellerBuyerCount;
	int UsersCount;
public:
	Ecommerece(string name);
	void Menu();
	void BuyerMenu(User_Buyer* buyer);
	void SellerMenu(User_Seller* seller);
	void BuySellMenu(BuyerSeller* user);
	void operator+=(const User_Seller& buyer);
	void operator+=(const User_Buyer& buyer);
	void operator+=(const BuyerSeller& buyer);
	void addUser(const User_Buyer& buyer);
	void addUser(const User_Seller& seller);
	void addUser(const BuyerSeller& user);
	void showAllBuyerSellers(const BuyerSeller& user);
	vector<User*> getUsers()const;
	void showBuyers();
	void showBuySell();
	void showSellers();
	void getNumOfBuyers();
	void getNumOfSellers();
	Product* findProduct(int serial);
	User_Seller* findSellerBySerial(int serial);
	User_Seller* findSeller(string name, Address& add);
	User_Buyer* findBuyer(string name, string postal);
	void showAllProductsByNameGeneral(string name);
	void WriteToFile();
	void ReadFromFile(ifstream& File);
	vector<int> showAllProductsByName(string name);
	bool checkUserName(string name);
	bool signIn(string username, string password);

};
#endif // __ECOMM_H