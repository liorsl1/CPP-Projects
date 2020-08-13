#include "Address.h"
#include <iostream>
using namespace std;
#pragma warning(disable:4996)

Address::Address(string country, string city, string postCode)
{
	setCountry(country);
	setCity(city);
	setPostCode(postCode);
}

Address::Address(ifstream& in)
{

	getline(in,this->_country,' ');
	getline(in, this->_city,' ');
	getline(in, this->postalCode);
	
}

void Address::setCountry(string country)
{
	this->_country = country;
}

void Address::setCity(string city)
{
	this->_city = city;
}

void Address::setPostCode(string postalCode)
{
	this->postalCode = postalCode;
}

string Address::getPostCode() const
{
	return this->postalCode;
}


void Address::show()
{
	cout << "Country: " << _country<<", City: "<<_city<<", Postal Code: "<<postalCode;
}

const bool Address::checkEqual(Address& add) const
{
	if (this->postalCode.compare(add.postalCode)==0 && this->_city.compare(add._city)==0 && this->postalCode.compare(add.postalCode)==0)
		return true;
	return false;
}
