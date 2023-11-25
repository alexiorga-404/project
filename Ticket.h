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
	ticket() :ID(generator++) {};

	ticket(int row, int seat, movieCateg categ, eventLocation location, event event):ID(generator++) {
		setRow(row);
		setSeat(seat);
		this->Event = event;
		this->location = location;
		movie = categ;
		IDs = new int[location.getSeats()];
		newTicket();
		location.seatPicked();
		
	};
	ticket(int row, int seat, teather categ, eventLocation location, event event) :ID(generator++) {
		setRow(row);
		setSeat(seat);
		this->Event = event;
		this->location = location;
		Teather = categ;
		IDs = new int[location.getSeats()];
		newTicket();
		location.seatPicked();
	};

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

	~ticket() {
		delete[] IDs;
		IDs = nullptr;
	};
};