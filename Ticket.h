#pragma once
#include<iostream>
#include "Eventr.h"
#include"Location.h"
using namespace std;

enum movieCateg { normal, VIP };
enum teather { categ1, categ2, box };

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

	ticket(int row, int seat, eventLocation location, event event) :ID(generateRandomID()) {
		setRow(row);
		setSeat(seat);
		this->Event = event;
		this->location = location;

		IDs = new int[location.getSeats()];
		newTicket();
		location.seatPicked();

	};

	ticket(int row, int seat, teather categ, eventLocation location, event event) :ID(generateRandomID()) {
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

	bool isVIP() {
		return (movie == VIP);
	}

	void printTicketDetails() {
		cout << "Ticket ID: " << ID << endl;
		cout << "Event: " << Event.getName() << endl;
		cout << "Row and seat:" << this->row << " " << this->seat << endl;

	}

	void saveToFile(const char* filename) const {
		ofstream file(filename, ios::binary | ios::app);
		if (file.is_open()) {
			file.write(reinterpret_cast<const char*>(this), sizeof(ticket));
			file.close();
		}
		else {
			cerr << "Error opening file for saving: " << filename <<  endl;
		}
	}
	static ticket loadFromFile(const char* filename) {
		ticket loadedTicket;

		ifstream file(filename, ios::binary);
		if (file.is_open()) {
			file.read(reinterpret_cast<char*>(&loadedTicket), sizeof(ticket));
			file.close();
		}
		else {
			cerr << "Error laoding file " << filename << endl;
		}

		return loadedTicket;
	}

	void buyTicket() {
		int row, seat;
		char locationName[100];
		char eventName[100];
		int eventDay, eventMonth, eventYear;
		int eventHour, eventMinute;

		 cout << "Enter the Row number: ";
		 cin >> row;

		 cout << "Enter the Seat number: ";
		 cin >> seat;

		 cout << "Enter the name for the event: ";
		 cin.ignore(); // Clear the newline character from the input buffer
		 cin.getline(eventName, sizeof(eventName));

		 cout << "Enter the date (day month year): ";
		 cin >> eventDay >> eventMonth >> eventYear;

		 cout << "Enter the time (hour minute): ";
		 cin >> eventHour >> eventMinute;

		 cout << "Enter the name of the location: ";
		 cin.ignore(); // Clear the newline character from the input buffer
		 cin.getline(locationName, sizeof(locationName));

		// Create a new ticket with the input details
		eventLocation location;
		location.setName(locationName);

		event Event;
		Event.setName(eventName);
		Event.setDate({ eventDay, eventMonth, eventYear });
		Event.setTime({ eventHour, eventMinute });

		// Assume the default category for simplicity
		movieCateg categ = normal;

		// Create a new ticket and assign it to the existing Ticket instance
		*this = ticket(row, seat, categ, location, Event);

		 cout << "Ticket purchased successfully." <<  endl;
	}

	~ticket() {
		delete[] IDs;
		IDs = nullptr;
	};

	bool operator!=(const ticket& anotherOne)//Dj khaleed
	{
		return!(this == &anotherOne);
	}

	ticket& operator=(const ticket& source) {
		// Check for self-assignment
		if (this == &source)
			return *this;

		// Perform deep copy of data members
		this->row = source.row;
		this->seat = source.seat;
		// Perform similar deep copies for other data members

		return *this;
	}

	friend void operator<<(ostream& console, ticket& Ticket);
	friend void operator>>(istream& console, ticket& Ticket);
};

void operator<<(ostream& console, ticket& Ticket) {
	console << endl << "Row number" << Ticket.getRow();
	console << endl << "Seat number:" << Ticket.getSeat();
	console << endl << "Location:" << Ticket.location;
	console << endl << "Event details:" << Ticket.Event;

}

void operator>>(istream& console, ticket& Ticket) {
	cout << "Enter the Row number: ";
	console >> Ticket.row;

	cout << "Enter the Seat number: ";
	console >> Ticket.seat;


}
