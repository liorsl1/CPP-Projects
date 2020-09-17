#pragma once
#include "StringKey.h"
#include<iostream>
#include<string>
using namespace std;

class Worker {
	StringKey* Name;
	unsigned int wYears;
	unsigned int Rank;

public:
	// theta(1) for every function
	Worker();
	Worker(const Worker& worker);
	~Worker();
	StringKey* GetKey();
	Worker* Read();
	void printDetails();
};