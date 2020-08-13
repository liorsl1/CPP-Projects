#pragma once
#include "Ecommerece.h"
#pragma warning(disable: 4996) 

	//verification for the product's inputs.
	bool verifyProduct(string category, string name, double price); 
	//verification for the Users's inputs.
	bool verifyUser(string username, string password); 
	//verification for the Address's inputs.
	bool verifyAddress(string country, string city, string postal); 
