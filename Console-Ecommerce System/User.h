#pragma once
#ifndef __User_H
#define __User_H
#include "Address.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class User
{
protected:
	string user_Name;
	string _password;
	Address _address;
public:
	User(string name, string pass,Address& address);
	User(const User& user);
	User(ifstream& in);
	virtual ~User();
	inline void setUserName(string name);
	inline void setPassword(string pass);
	inline void setAddress(const Address& address);
	string getUserName() const;
	bool compareUserInfo(string username, string password);
	void showAddress();
	string AddressToString(bool tofile) const;
	const Address& getAddress()const;
	friend std::ostream& operator<<(std::ostream& os, const User& us);
	//friend std::istream& operator>>(istream& in, const User& us);
	//friend class User_Buyer;
	//friend class User_Seller;
};

#endif