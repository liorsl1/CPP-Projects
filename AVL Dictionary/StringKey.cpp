#include "StringKey.h"


StringKey::StringKey()
{
}

StringKey::StringKey(string first, string last) :FirstName(first), LastName(last) {

}
StringKey::StringKey(const StringKey& key) :FirstName(key.FirstName), LastName(key.LastName) {

}
StringKey::~StringKey()
{

}

StringKey* StringKey::Read() {
	getline(cin, FirstName, ' ');
	getline(cin, LastName, ' ');
	if ( 2 < FirstName.length() && FirstName.length() < 25 && 2 < LastName.length() && LastName.length() < 25 ) {
		return this;
	}
	return NULL;
}

int StringKey:: Compare(StringKey* sKey) {
	int res = 0;

	if (LastName.compare(sKey->LastName) > 0)
		res = 2;
	else if (LastName.compare(sKey->LastName) < 0)
		res = 1;
	//Last name equals, compare with first name
	else {
		if (FirstName.compare(sKey->FirstName) > 0)
			res = 2;
		else if (FirstName.compare(sKey->FirstName) < 0)
			res = 1;
	}
	return res;
}

void StringKey::toString()
{
	cout << "First Name: " << FirstName << " , Last Name: " << LastName;
}
