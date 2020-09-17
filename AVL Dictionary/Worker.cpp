#include "Worker.h"

Worker::Worker()
{
	Name = new StringKey();
	wYears = 0;
	Rank = 0;
}

Worker::Worker(const Worker& worker):Name(worker.Name),wYears(worker.wYears),Rank(worker.Rank)
{
}

Worker::~Worker()
{
	delete(Name);
}

StringKey* Worker::GetKey()
{
	return Name;
}

Worker* Worker::Read()
{
	string years, rank;
	int numYears, numRank;
	Name = Name->Read();
	getline(cin, years, ' ');
	numYears = atoi(years.c_str());
	getline(cin, rank, '\n');
	numRank = atoi(rank.c_str());
	if (0 <= numYears , 0 <= numRank , Name!=NULL) {
		wYears = numYears;
		Rank = numRank;
	}
	else {
		return NULL;
	}
	return this;
}

void Worker::printDetails()
{
	Name->toString();
	cout << " , Years: " << wYears << " , Rank :" << Rank;
}
