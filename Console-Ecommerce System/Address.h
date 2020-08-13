#pragma once
#ifndef __Address_H
#define __Address_H
#include <string>
#include <fstream>
using namespace std;
class Address
{
private:
	string _country;
	string _city;
	string postalCode;
public:
	Address(string country, string city, string postalCode);
	Address(ifstream& in);
	void setCountry(string country);
	void setCity(string city);
	void setPostCode(string postalCode);
	string getPostCode() const;
	void show();
	const bool checkEqual(Address& add)const;
	friend class User;
};

#endif