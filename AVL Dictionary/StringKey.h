#pragma once
#include<iostream>
#include<string>
using namespace std;

class StringKey {

private:
	string FirstName;
	string LastName;
public:
	// theta(1) for every function, except for Compare.
	StringKey();
	StringKey(string first, string last);
	StringKey(const StringKey& key);
	~StringKey();
	StringKey* Read();
	// theta(n) - where n is the length of the string.
	int Compare(StringKey* sKey);
	void toString();
};