#pragma once
#include "AVLTree.h"

class Dictionary {
	AVLTree treeDict;

public:
	Dictionary();
	~Dictionary();
	// theta(log(n))
	Worker* Find(StringKey* k);
	// theta(log(n))
	int Insert(StringKey* k, Worker* d);
	// theta(log(n))
	Worker* Delete(StringKey* k);
	// theta(n)
	void PrintDictionary();
	// theta(n)
	void FreeAllElements();
	// theta(1)
	int isEmpty();
};