#pragma once
#ifndef __Feed_H
#define __Feed_H
#include <iostream>
using namespace std;
class Feedback
{
private:
	string BuyersName;
	string feedback_date;
	string _comment;
public:
	Feedback(string BuyersName,string feedback_date,string _comment);
	Feedback(const Feedback &feed);
	void setFeedDate(string date);
	void setComment(string comment);
	void setBuyersName(string name);
	string getDetails() const;

	friend std::ostream& operator<<(std::ostream& os, const Feedback& feed);

};

#endif