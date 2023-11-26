#pragma once
#include<iostream>
#include "Eventr.h"
#include"Location.h"
using namespace std;

enum movieCateg{normal, VIP};
enum teather{categ1,categ2,box};

class ticket {

	const int ID;
	static int generator;// this will be used to generate unique identifieres 
	int* IDs = nullptr;//store id's
	
	int row = 0;
	int seat = 0;
	eventLocation location;
	event Event;
	movieCateg movie;
	teather Teather;

public:
	ticket() :ID(generateRandomID()) {};

	ticket(int row, int seat, movieCateg categ, eventLocation location, event event) :ID(generateRandomID()) {
		setRow(row);
		setSeat(seat);
		this->Event = event;
		this->location = location;
		movie = categ;
		IDs = new int[location.getSeats()];
		newTicket();
		location.seatPicked();
		
	};
	ticket(int row, int seat, teather categ, eventLocation location, event event) :ID(generateRandomID()){
		setRow(row);
		setSeat(seat);
		this->Event = event;
		this->location = location;
		Teather = categ;
		IDs = new int[location.getSeats()];
		newTicket();
		location.seatPicked();
	};
	
	static int generateRandomID() {
		static int counter = 0;
		return static_cast<int>(time(nullptr)) + counter++;
	}

	void newTicket() {
		IDs[ID - 1] = ID;
	}
	int getID() {
		return this->ID;
	}
	int getRow() {
		return this->row;
	}
	int getSeat() {
		return this->seat;
	}
	
	void setRow(int row) {
		try {
			if (row < 0)
				throw exception("wrong input");
		}
		catch (const exception& e) {
			cout << e.what();
			return;
		}
		this->row = row;
	}
	void setSeat(int seat) {
		try {
			if (seat < 0)
				throw exception("wrong input");
		}
		catch (const exception& e) {
			cout << e.what();
			return;
		}
		this->seat = seat;
	}

	bool isVIP(){
		return (movie == VIP);
	}
	void printTicketDetails() {
		cout << "Ticket ID: " << ID << endl;
		cout << "Event: " << Event.getName() << endl;
		cout << "Row and seat:" << this->row << " " << this->seat << endl;

	}

	~ticket() {
		delete[] IDs;
		IDs = nullptr;
	};

	bool operator!=(const ticket& anotherOne)//Dj khaleed
	{
		return!(this == &anotherOne);
	}

	friend void operator<<(ostream& console, ticket& Ticket);
	friend void operator>>(istream& console, ticket& Ticket);
};

void operator<<(ostream& console, ticket& Ticket) {
	console << endl << "Row number" << Ticket.getRow();
	console << endl << "Seat number:" << Ticket.getSeat();
	
}

void operator>>(istream& console, ticket& Ticket) {
	cout << "Enter the Row number: ";
	console >> Ticket.row;

	cout << "Enter the Seat number: ";
	console >> Ticket.seat;

	
}
