#pragma once
#pragma once
#include<iostream>
#include"Ticket.h"
using namespace std;
// Abstract class
class TicketBase {
public:
	virtual void printSpecialMessage() const = 0; // Pure virtual method

	virtual ~TicketBase() {} // Virtual destructor for a base class
};


class VIPticket : public TicketBase {
public:
	// Implementing the pure virtual method
	void printSpecialMessage() const override {
		cout << "This is a VIP ticket. Enjoy the VIP experience!" << endl;
	}

};


class ticket : public TicketBase {
};
