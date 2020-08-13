#include "ValidationFuncs.h"

	bool verifyAddress(string country, string city, string postal) {
		/*bool checkCountry=false;
		bool checkCity = false;
		bool checkPost = false;*/
		//for (int i = 0; i < strlen(country); i++) { //check if country is valid
		//	if (!isalpha(country[i]))
		//		checkCountry = true;
		//}
		//for (int i = 0; i < strlen(city); i++) { //if city is valid
		//	if (!isalpha(city[i]))
		//		checkCity = true;
		//}
		//for (int i = 0; i < strlen(postal); i++) { //if postal code is valid
		//	if (!isdigit(postal[i]))
		//		checkPost = true;
		//}
		bool check = true;

		if (country.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != std::string::npos || country.length() < 2) {
			cout << "country needs to be atleast 2 letters.(no special characters)" << endl;
			check = false;
			
		}
		if (city.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != std::string::npos || city.length() < 2) {
			cout << "city needs to be atleast 2 letters." << endl;
			check = false;
		}
		if (postal.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890") != std::string::npos || postal.length() < 2) {
			cout << "postal code needs to be atleast 4 digits." << endl;
			check = false;
		}
		return check;

	}
	bool verifyUser(string username, string password) { //verification for the product's inputs.
		bool check = true;
		if (username.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890_") != std::string::npos ||username.length()<2) {
			cout << "username must consist more than 2 characters (no special characters.)." << endl;
			check=false;
		}
		if(password.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890_") != std::string::npos || password.length() < 2){
			cout << "password must consist more than 2 characters (no special characters)." << endl;
			check=false;
		}
		
		return check;
	}
	bool verifyProduct(string category, string name, double price) {
		bool check=true;
		if (name.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890_") != std::string::npos || name.length() < 2) {
			cout << "name of product must consist atleast 2 characters.(no special characters)" << endl;
			check= false;
		}
		if (category.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890_") != std::string::npos ||category.length() < 2) {
			cout << "category must consist atleast 3 characters.(no special characters)" << endl;
			check= false;
		}
		if (price < 0) {
			cout << "price must be non negative number." << endl;
			check= false;
		}
		return check;
	}
	//bool verifyPurchase(User_Seller* seller, BuyerSeller* buysell) { //solely for Buyer-seller type. pass the seller of the product, and check if the info equals to buyer-seller.
	//	return true;
	//}

