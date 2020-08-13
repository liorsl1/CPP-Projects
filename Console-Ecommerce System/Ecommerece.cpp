#include "Ecommerece.h"
#include "ValidationFuncs.h"
#include <ctime>


Ecommerece::Ecommerece(string name) : BuyersCount(0), SellersCount(0),SellerBuyerCount(0),UsersCount(0)
{
	ifstream File("Users.txt");
	if(File.peek()!= std::ifstream::traits_type::eof())  //checks if the file is empty.
		ReadFromFile(File);  //reads the file and loads the users.
		this->_name = name;
}


void Ecommerece::Menu()
{
	int Selection=0;
	const int size = 20;
	cout <<endl<< "1. Add Buyer account." << endl;
	cout << "2. Add Seller account." << endl;
	cout << "3. Add Buyer-Seller account." << endl;
	cout << "4. Sign In." << endl;
	cout << "5. Show Users information." << endl;
	cout << "6. Compare the price sum of two Buyers." << endl;
	cout << "7. Show all products by same name." << endl;
	cout << "8. Exit." << endl;

	
	do {
		cout << "The Main Menu, please choose an action by entering the respective number:" << endl;
		cin >> Selection;
		if (Selection == 1 || Selection == 2 || Selection==3) {		//Creating a user.
			string username, password, country,
				city, postal;
			cin.ignore();	// clean the buffer
			do {
				cout << "Please enter your User name: (Max 20 letters)" << endl;
				getline(cin, username);
			
			cout << endl << "Please enter your password:" << endl;
			getline(cin, password);
			} while (!verifyUser(username, password)||!checkUserName(username));
			do {
				cout << endl << "Please state your country:" << endl;
				getline(cin, country);
				cout << endl << "Please state your city:" << endl;
				getline(cin, city);
				cout << endl << "Please enter your postal code:" << endl;
				getline(cin,postal);
			} while (!verifyAddress(country, city, postal));
			Address address = Address(country, city, postal);
			User user = User(username, password, address);

			switch (Selection) {
				int option;
				cin.ignore();	// clean the buffer
			case 1:		//add buyer
			{
				User_Buyer buyer =User_Buyer(user);
				(*this)+=(buyer);
				cout << "Enter 1 for Buyers Menu, and another number to stay: ";
				cin >> option;
				if (option == 1)
					BuyerMenu(dynamic_cast<User_Buyer*>( Users[Users.size()-1]));
				break;
			}
			case 2:		//add seller
			{
				User_Seller seller = User_Seller(user);
				(*this)+=(seller);
				cout << "Enter 1 for Sellers Menu, and another key to stay: ";
				cin >> option;
				if (option == 1)
					SellerMenu(dynamic_cast<User_Seller*>(Users[Users.size()-1]));
				break;
			}
			case 3:		//add buyer-seller
				BuyerSeller buyersell = BuyerSeller(user);
				(*this)+=(buyersell);
				cout << "Enter 1 for the User Menu, and another key to stay: ";
				cin >> option;
				if (option == 1)
					BuySellMenu(dynamic_cast<BuyerSeller*>(Users[Users.size()-1]));
				break;
			}
		}
		////
		else if (Selection == 4) {
			string user, pass;
			do {
				cin.ignore();
				cout << "To cancel, press 0."<<endl;
				cout << "UserName: ";
				getline(cin, user);
				if (user.compare("0") == 0)	  //to break the cycle of signing in, press 0.
					break;
				cout << endl << "Password: ";
				getline(cin, pass);
			} while (!signIn(user, pass));
		}
		else if (Selection == 5) {
			int sel;
			cin.ignore();
			cout << "Choose which users to display(enter the number): 1. Buyers, 2. Sellers, 3. Buyers-Sellers.";
			cin >> sel;
			switch (sel) {
			case 1:
				showBuyers();
				break;
			case 2:
				showSellers();
				break;
			case 3:
				showBuySell();
				break;
			}
		}
		//compare between two buyers. with the operator <.
		else if (Selection == 6) {
			int sel;
			User_Buyer* buyer1;
			User_Buyer* buyer2;
			string user, postal;
			cin.ignore();
			cout << "Choose which users to compare between. \nTo do that, please insert their username and then their postal code:"<<endl;
				cout << "1. Username: ";
				getline(cin,user);
				cout << "Postal code: ";
				getline(cin, postal);
				buyer1 = findBuyer(user, postal);
				if (buyer1 == nullptr)
					cout << "Buyer not found, going back to Main Menu." << endl;
				else {
					cout << "2. Username: ";
					getline(cin, user);
					cout << "Postal code: ";
					getline(cin, postal);
					buyer2 = findBuyer(user, postal);
					if (buyer2 == nullptr)
						cout << "Buyer not found, going back to Main Menu." << endl;
					else {
						bool res= *buyer2 < *buyer1;
						if (res)  cout << buyer1->getUserName() << " (First buyer)" << "has greater cart price value."<<endl;
						else	  cout << buyer1->getUserName() << " (First user)" << "does not have greater cart price value."<<endl;
					}
				}
		}
		else if (Selection == 7) {
			string prname;
			cout << "Enter the specified name for the Product:" << endl;
			cin.ignore();
			getline(cin, prname);
			showAllProductsByNameGeneral(prname);
		}
		else if (Selection == 8) {

			WriteToFile(); //exiting and writing Users data to file.
			cout << "Exiting. Have a great day :)";
			return;
		}
	} while (Selection != 8);
}

void Ecommerece::BuyerMenu(User_Buyer* buyer)
{
	int sel;
	cout<<endl<< "Welcome Back " << (*buyer).getUserName()<< "."<<endl;
	cout << "1. Add item to cart." << endl;
	cout << "2. Order items from cart." << endl;
	cout << "3. Send feedback to seller." << endl;
	cout << "4. Exit." << endl;
	do {
		cout << "Choose your action:" << endl;
		cin >> sel;
		switch (sel) {
		case 1:
		{
			string name;
			cout << "Enter the name of the product: " << endl;
			cin.ignore();
			getline(cin,name);
			vector<int> serial = showAllProductsByName(name);
			if (!serial.empty()) {
				cout << "choose the product: " << endl;
				cin >> sel;
				Product* pr = findProduct(serial[sel - 1]);
				(*buyer).addItem(*pr);
				cout << "Item added succesfully." << endl;
			}
			else {
				cout << "item does not exist, please try again." << endl;
			}
		}
		break;
		case 2:
		{
		if (buyer->showCart()) { //showing the cart while checking its not empty.
			vector<int> prodSerial;
			int count = 0;
			vector<string> sellerName;
			vector<Address*> address;
			vector<Product*> pr = buyer->getProductsInCart();
			cout << endl << "Pick a product by its number, to stop press 0: ";
			cin >> sel;
			if (sel != 0) {
				do {
					prodSerial.push_back(pr[sel-1]->getSerial());
					User_Seller* seller = findSellerBySerial(prodSerial[count]);
					sellerName.push_back(seller->getUserName());
					address.push_back(new Address(seller->getAddress()));
					count++;
					cin.ignore();
					cout << endl << "Pick a product by its number, to stop press 0 : ";
					cin >> sel;
				} while (sel > 0);

				//after the (*buyer) picks his items, sends the number of items,the serial numbers and the sellers names.
				buyer->orderProducts(count,address,prodSerial, sellerName); 
				cout << "Products Ordered successfully." << endl;
			}
		}
		else
		{
			cout << endl;
		}
	}
			break;
		case 3: 
			int history, prod;
			char buyerName[15],comment[100],date[30];
			if ((*buyer).showHistory()) {
				time_t t = time(NULL);    /*getting the systems date.*/
				tm* tPtr = localtime(&t);
				sprintf(date, "%d/%d/%d", (tPtr->tm_mday), (tPtr->tm_mon) + 1, (tPtr->tm_year) + 1900);
				cout << "Choose the number of Previous purchase: "<<endl;
				cin >> history;
				cout << "Choose the number of product: " << endl;
				cin.ignore();
				cin >> prod;
				Address sellerAdd= (*buyer).getProdSeller(history-1, prod-1); //the logic number is the (display number)-1.
				string name =(*buyer).getSellerName(history-1,prod-1);
				User_Seller* seller= findSeller(name, sellerAdd);
				cout << "Enter your name(Max 15 letters): " << endl;
				cin.ignore();
				cin.getline(buyerName, 15);
				cout << "Write a comment to " << name<<" (Max 100 letters):"<<endl;
				cin.getline(comment, 100);
				Feedback fd = Feedback(buyerName, date, comment);
				seller->addFeedback(fd);
			}
			break;
		}
	} while (sel != 4);

}

void Ecommerece::SellerMenu(User_Seller* seller)
{
	int sel=0;

	cout <<endl<< "Welcome Back " <<(*seller).getUserName()<<"."<<endl;
	cout << "1. Add Product." << endl;
	cout << "2. Watch feedbacks." << endl;
	cout << "3. Exit." << endl;
	do {
		cout << "Choose your action:" << endl;
		cin >> sel;
		if (sel == 1)
		{
			string category, name;
			double price;
			do {
				cin.ignore();
				cout << "Product's category: " << endl;
				getline(cin,category);
				cout << "Product's name: " << endl;
				getline(cin,name);
				cout << "Product's price: " << endl;
				cin >> price;
			} while (!verifyProduct(category, name, price));
			Product pr = Product(category, name, price);
			seller->addProduct(pr);
			cout << "The product has been added."<<endl;
		}
		else if (sel == 2) {
			(*seller).showFeedbacks();
		}
	} while (sel != 3);
}

void Ecommerece::BuySellMenu(BuyerSeller* user)
{
	int sel;
	cout << "Choose what type of actions you would want to perform: for Buyers actions press 1, for Sellers press any other key." << endl;
	cin >> sel;
	if (sel == 1)
		BuyerMenu(user);
	else
		SellerMenu(user);

}



void Ecommerece::operator+=(const User_Seller& seller)
{
	this->UsersCount++;
	addUser(seller);
}

void Ecommerece::operator+=(const User_Buyer& buyer)
{
	this->UsersCount++;
	addUser(buyer);
}

void Ecommerece::operator+=(const BuyerSeller & buyersell)
{
	this->UsersCount++;
	addUser(buyersell);
}

void Ecommerece::showBuyers()
{
	for (int i = 0; i < Users.size(); i++) {
		User_Buyer* buyer = dynamic_cast<User_Buyer*>(Users[i]); //dynamically cast to access seller functions, from virtual base.
		if (buyer != nullptr) {
			buyer->show();
		}
	}
}
void Ecommerece::showSellers()
{
	for (int i = 0; i < Users.size(); i++) {
		User_Seller* seller = dynamic_cast<User_Seller*>(Users[i]); //dynamically cast to access seller functions, from virtual base.
		if (seller != nullptr) {
			seller->show();
		}
	}
}
void Ecommerece::showBuySell()
{
	for (int i = 0; i < Users.size(); i++) {
		BuyerSeller* buysel = dynamic_cast<BuyerSeller*>(Users[i]); //dynamically cast to access seller functions, from virtual base.
		if (buysel != nullptr) {
			buysel->show();
		}
	}
}

Product* Ecommerece::findProduct(int serial)
{
	Product* pr = nullptr;
	for (int i = 0;( i < Users.size() && pr==nullptr); i++) {
		User_Seller* seller = dynamic_cast<User_Seller*>(Users[i]); //dynamically cast to access seller functions, from virtual base.
		if (seller != nullptr) {
			pr = seller->findProduct(serial);
		}
	}
	return pr;
}

User_Seller* Ecommerece::findSellerBySerial(int serial)
{
	for (int i = 0; i < Users.size(); i++) {
		User_Seller* seller = dynamic_cast<User_Seller*>(Users[i]); //dynamically cast to access seller functions, from virtual base.
		if (seller != nullptr) {
			for (int j = 0; j < seller->getNumOfProducts(); j++) {
				if (serial == seller->getProducts()[j]->getSerial())
					return seller;
			}
		}
	}
	return nullptr;
}

User_Seller* Ecommerece::findSeller(string name, Address& add)
{
	for (int i = 0; i < Users.size(); i++) {
		User_Seller* seller = dynamic_cast<User_Seller*>(Users[i]); //dynamically cast to access seller functions, from virtual base.
		if (seller != nullptr) {
			if (name.compare(seller->getUserName())==0 && (seller->getAddress().checkEqual(add)))
				return seller;
		}
	}
	return nullptr;
}
User_Buyer* Ecommerece::findBuyer(string name, string postal)
{
	for (int i = 0; i < Users.size(); i++) {
		User_Buyer* buyer = dynamic_cast<User_Buyer*>(Users[i]); //dynamically cast to access buyer functions, from virtual base.
		if (buyer != nullptr) {
			if (name.compare(buyer->getUserName())==0 && postal.compare(buyer->getAddress().getPostCode())==0)
				return buyer;
		}
	}
	return nullptr;
}

void Ecommerece::showAllProductsByNameGeneral(string name)
{
	vector<Product*> pr;
	int count = 0;
	for (int i = 0; i < Users.size(); i++) { //search for the name and show the right info for it.
		User_Seller* seller = dynamic_cast<User_Seller*>(Users[i]); //dynamically cast to access seller functions, from virtual base.
		if (seller != nullptr) {
			pr = seller->getProducts();
			int num = seller->getNumOfProducts();
			for (int j = 0; j < num; j++) {
				if ( name.compare(pr[j]->getName())==0) { //returns 0 for equal
					cout << " " << (count++) << ". ";
					cout<<*pr[j];
					cout << endl;
				}
			}
		}
	}
}

void Ecommerece::WriteToFile()
{
	ofstream FILE("Users.txt",ios::trunc);
	FILE << Users.size() << endl;
	for (int i = 0; i < Users.size(); i++) {
		FILE<<typeid(*Users[i]).name()<<endl<< (User)*Users[i]<<endl;
	}
	FILE.close();
	return;
}

void Ecommerece::ReadFromFile(ifstream& File)
{
	int size;
	File >> size;
	File.ignore();
	for (int i = 0; i < size; i++) {
		string type;
		getline(File, type);
		if (type.compare(typeid(User_Seller).name()) == 0)
			Users.push_back(new User_Seller(User(File)));
		else if (type.compare(typeid(User_Buyer).name()) == 0)
			Users.push_back(new User_Buyer(User(File)));
		else if (type.compare(typeid(BuyerSeller).name()) == 0)
			Users.push_back(new BuyerSeller(User(File)));
	}
}


void Ecommerece::getNumOfBuyers()
{
}

void Ecommerece::getNumOfSellers()
{
}


 
vector<int> Ecommerece::showAllProductsByName(string name)
{
	vector<Product*> pr;
	vector<int> serials;
	int count = 0;
	for (int i = 0; i < Users.size(); i++) {		//search for the name and show the right info for it.
		User_Seller* seller = dynamic_cast<User_Seller*>(Users[i]); //dynamically cast to access seller functions, from virtual base.
		if (seller!=nullptr) {
			pr = seller->getProducts(); 
			int num = seller->getNumOfProducts();
			for (int j = 0; j < num; j++) {
				if (name.compare(pr[j]->getName())==0) { //returns 0 for equal
					cout << " " << (++count) << ". ";
					cout<<*pr[j];
					cout << endl;
					serials.push_back((pr[j]->getSerial()));
				}
			}
		}
	}
	return serials;
}

bool Ecommerece::checkUserName(string name)
{
	for (int i = 0; i < Users.size(); i++) {
		if (name.compare(Users[i]->getUserName()) == 0) {
			cout << "Username is taken. please try a different one." << endl;
			return false;
		}
	}
	return true;
}


bool Ecommerece::signIn(string username, string password)
{
	for (int i = 0; i < Users.size(); i++) {
		if (Users[i]->compareUserInfo(username, password)) {
			/*..log in(grabs that account and assign it to its respective menu).*/
			if (typeid(*Users[i]) == typeid(User_Buyer))
				BuyerMenu(dynamic_cast<User_Buyer*>(Users[i]));
			else if (typeid(*Users[i]) == typeid(User_Seller))
				SellerMenu(dynamic_cast<User_Seller*>(Users[i]));
			else
				BuySellMenu(dynamic_cast<BuyerSeller*>(Users[i]));
			return true;
		}
	}
	cout << "(*)User doesn't exist, press enter to continue." << endl;
	return false;
}

void Ecommerece::addUser(const User_Buyer& buyer)
{
	this->BuyersCount++;
	Users.push_back(new User_Buyer(buyer));
}

void Ecommerece::addUser(const User_Seller& seller)
{
	this->SellersCount++;
	Users.push_back(new User_Seller(seller));
}

void Ecommerece::addUser(const BuyerSeller& user)
{
	Users.push_back(new BuyerSeller(user));
}

void Ecommerece::showAllBuyerSellers(const BuyerSeller & user)
{
	for (int i = 0; i < Users.size(); i++) {
		cout <<Users[i];
	}
}

	vector<User*> Ecommerece::getUsers() const
	{
		return this->Users;
	}

