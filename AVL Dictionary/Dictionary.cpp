#include "Dictionary.h"

Dictionary::Dictionary():treeDict()
{
}

Dictionary::~Dictionary()
{
}

Worker* Dictionary::Find(StringKey* k)
{
	return treeDict.Find(k);
}

int Dictionary::Insert(StringKey* k, Worker* d)
{
	if(k!= NULL && d != NULL)
		return treeDict.Insert(k,d);
}

Worker* Dictionary::Delete(StringKey* k)
{
	return treeDict.Delete(k);
}

void Dictionary::PrintDictionary()
{
	treeDict.InorderPrint();
}

void Dictionary::FreeAllElements()
{
	treeDict.FreeElements();
}

int Dictionary::isEmpty()
{
	return treeDict.isEmpty();
}
