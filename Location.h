#pragma once
#include<iostream>

using namespace std;
class eventLocation {

	int maxSeats = 0;
	int availableSeats = 0;
	int seatsPerRow = 0;
	int noRows = 0;
	char* name = nullptr;


public:

	int getSeats() {
		return maxSeats;
	}

	int getRows() {
		return noRows;
	}

	int getSeatsPerRow() {
		return seatsPerRow;
	}

	char* getName() {
		char* copy = new char[strlen(name) + 1];
		strcpy_s(copy, strlen(name) + 1, name);
		return copy;
	}

	int getRemaining() {
		return this->availableSeats;
	}

	void setSeats(int noSeats) {
		if (noSeats > 0)
			maxSeats = noSeats;
		else {
			cout << "wrong number";
			return;
		}
	}

	void setRows(int rows) {
		if (rows > 0 && rows < maxSeats)
			noRows = rows;
		else {
			cout << "wrong number" << endl;
			return;
		}
	}

	void setSeatsPerRow(int seats) {
		if (seats > 0 && seats < maxSeats && seats>noRows)
			seatsPerRow = seats;
		else {
			cout << "wrong number" << endl;
			return;
		}
	}

	void setName(char* name) {
		
	

		try {
			if (strlen(name) < 3)
				throw exception("wrong location name");
		}
		catch (const exception& e) {
			cout << e.what() << endl;
			return;
		}
			this->name = new char[strlen(name) + 1];
			strcpy_s(this->name, strlen(name) + 1, name);
	}

	void setRemaining(int seats) {
		if (seats >= 0 && seats <= maxSeats)
			availableSeats = seats;
		else {
			cout << "Wrong value";
			return;
		}
	}

	void seatPicked() {
		availableSeats--;
	}

	void seatRevoked() {
		availableSeats++;
	}

	eventLocation() {
		cout << "Location added succesfully" << endl;
	}

	eventLocation(int maxSeats, int noRows, int seatsPerRow, char* name)
	{
		setSeats(maxSeats);
		setRows(noRows);
		setSeatsPerRow(seatsPerRow);
		setName(name);
	}

	~eventLocation() {
		delete[] name;
		name = nullptr;
	}

	friend void operator<<(ostream& console, eventLocation& lcoation);
	friend istream& operator>>(istream& console, eventLocation& location);

	bool operator<(eventLocation location) {
		if (this->maxSeats < location.maxSeats) {
			return true;
		}
		else {
			return false;
		}
	}

	eventLocation& operator=(const eventLocation& source) {
		if (&source != this)
		{
			setRows(source.noRows);
			setSeats(source.maxSeats);
			setRemaining(source.availableSeats);
			setSeatsPerRow(source.seatsPerRow);
			setName(source.name);
		}
		return *this;
	}

};
void operator<<(ostream& console, eventLocation& location) {
	console << endl << "Number of total seats:" << location.maxSeats;
	console << endl << "Number of total rows:" << location.noRows;
	console << endl << "Name of lcoations is:" << location.name;
}

istream& operator>>(istream& console, eventLocation& location) {
	cout << "Enter the number of total seats: ";
	console >> location.maxSeats;

	cout << "Enter the number of total rows: ";
	console >> location.noRows;

	
	cout << "Enter the name of the location and press enter: ";
	location.name = new char[100];
	console >> location.name;

	return console;
}
