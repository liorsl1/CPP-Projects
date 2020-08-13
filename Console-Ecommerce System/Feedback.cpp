#include "Feedback.h"
#include <string.h>
#include <string>
#include <iostream>
using namespace std;
#pragma warning(disable:4996)

Feedback::Feedback(string BuyersName, string feedback_date, string _comment)
{
	setBuyersName(BuyersName);
	setFeedDate(feedback_date);
	setComment(_comment);
}

Feedback::Feedback(const Feedback& feed)
{
	setBuyersName(feed.BuyersName);
	setFeedDate(feed.feedback_date);
	setComment(feed._comment);
}



void Feedback::setFeedDate(string date)
{
	this->feedback_date = date;
}

void Feedback::setComment(string comment)
{
	this->_comment = comment;
}

void Feedback::setBuyersName(string name)
{
	this->BuyersName = name;
}

string Feedback::getDetails() const
{
	string feed;
	
	feed = "Buyers Name: " + BuyersName + ", Date: " + feedback_date + ", comment: " + _comment;
	return feed;
}

std::ostream& operator<<(std::ostream & os, const Feedback & feed)
{
	os << feed.getDetails();
	return os;
}
