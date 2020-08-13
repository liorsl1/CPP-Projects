#include "User.h"
//#include <iostream>
#pragma warning(disable:4996)

//using namespace std;


User::User(string name, string pass,Address& address):_address(address)
{
	setUserName(name);
	setPassword(pass);
}

User::User(const User & user):_address(user._address)
{
	setAddress(user._address);
	setPassword(user._password);
	setUserName(user.user_Name);

}

User::User(ifstream& in) :_address("", "", "") // just to initialize the address in init line.
{
	string country, city, postal;
	getline(in, this->user_Name,' ');
	getline(in, this->_password, ' ');
	this->_address = Address(in);
}

User::~User()
{
}

inline void User::setUserName(string name)
{
	this->user_Name = name;
}

inline void User::setPassword(string pass)
{
	this->_password = pass;
}

inline void User::setAddress(const Address& address)
{
	this->_address = address;
}

string User::getUserName() const
{
	return this->user_Name;
}

bool User::compareUserInfo(string username, string password)
{
	if (this->user_Name.compare(username)==0 && this->_password.compare(password)==0)
		return true;
	return false;
}

void User::showAddress()
{
	cout << "country: " << _address._country << " , city:" << _address._city << " , Postal Code:" << _address.postalCode<<".";
}

string User::AddressToString(bool tofile) const
{
	string address;
	if (!tofile)
		address = "country: " + this->_address._country + ", city: " + this->_address._city + ", postal code:" + this->_address.postalCode;
	else
		address = this->_address._country + " " + this->_address._city + " " + this->_address.postalCode;	//if we need to write to file, write in that syntax.
	return address;
}

 const Address& User::getAddress() const
{
	return this->_address;
}

ostream& operator<<(ostream& os, const User& us)
{
	if (typeid(os) == typeid(ofstream)) {	//if we need to write to file, change syntax.
		os << us.user_Name << " "<<us._password<<" " << us.AddressToString(1); 
	}
	else {
		os << "User Name: " << us.getUserName() << ", Address: " << us.AddressToString(0);
	}
	return os;
}

//std::istream& operator>>(istream& in,  User& us)
//{
//	string s;
//	Address a("","","");
//	if (typeid(in) == typeid(ifstream)) {
//		getline(in,s );
//		us.setUserName(s);
//		in >> a;
//	}
//}
