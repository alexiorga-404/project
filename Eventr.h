#pragma once
#include<iostream>
using namespace std;

struct date {
	int day;
	int month;
	int year;
};

struct Time {
	int hour;
	int minute;
};

bool checkDate(date myDate) {
	if (myDate.day <= 31 && myDate.day > 0
		&& myDate.month <= 12 && myDate.month > 0 && myDate.year >= 2023)
		return true;
	else
		return false;
}

bool checkTime(Time myTime) {
	if (myTime.hour <= 23 && myTime.hour>= 0
		&& myTime.minute <=59 && myTime.minute>=0 )
		return true;
	else
		return false;
}

class event {

	
	date myDate;
	Time myTime;
	string name = "";


public:

	date getDate() {
		return myDate;
	}

	Time getRows() {
		return myTime;
	}

	string getName() {		
		return name;
	}


	void setDate(date myDate) {
		try {
			if (!checkDate(myDate))
				throw exception("wrong date");		
		}
		catch (const exception& e) {
			cout << e.what();
			return;
		}
		this->myDate = myDate;
	}

	void setTime(Time myTime) {
		try {
			if (!checkTime(myTime))
				throw exception("wrong time");
		}
		catch (const exception& e) {
			cout << e.what();
			return;
		}
		this->myTime=myTime;
	}

	void setName(string name) {
		
		try{
			if (name.length() <= 3 || islower(name[0]))
				throw exception("wrong date");
		}
		catch (const exception& e) {
			cout << e.what();
			return;
		}
		this->name = name;
	}

	

	
	event() {
		cout << "Event created succesfully"<<endl;
	}

	event(date myDate,Time myTime,string name)
	{
		setDate(myDate);
		setTime(myTime);
		setName(name);
	}

	~event() {
		cout << "done";
	}

	friend void operator<<(ostream& console, event& Event);
	friend istream& operator>>(istream& console, event& Event);

	

	bool operator==(Time myTime) {
		if (this->myTime.hour==myTime.hour && this->myTime.minute==myTime.minute) {
			return true;
		}
		else {
			return false;
		}

		//return (this->name == prod.name && this->price == prod.price);
	}
	void operator=(event& source) {
		if (&source == this)
			return;
		setDate(source.myDate);
		setTime(source.myTime);
		setName(source.name);
	}
	bool operator>(event& source) {
		if (this->myDate.year > source.myDate.year)
			return true;
		else if (this->myDate.month > source.myDate.month && this->myDate.year == source.myDate.year)
			return true;
		else if (this->myDate.day > source.myDate.day && this->myDate.year == source.myDate.year && this->myDate.month == source.myDate.month)
			return true;
		return false;
	}
	void printEventDetails() const {
		cout << "Event Details:" << endl;
		cout << "Name: " << name << endl;
		cout << "Date: " << myDate.day << ":" << myDate.month << ":" << myDate.year << endl;
		cout << "Time: " << myTime.hour << ":" << myTime.minute << endl;
	}

	
};
void operator<<(ostream& console, event& Event) {
	console << endl << "Name of event:" << Event.name;
	console << endl << "Date of the event is:" << Event.myDate.day<<":"<<Event.myDate.month << ":"<<Event.myDate.year;
	console << endl << "Time of event is:"<<Event.myTime.hour<<":"<<Event.myTime.minute;
}

istream& operator>>(istream& console, event& Event) {
	cout << "Enter the name for the event: ";
	console >> Event.name;

	cout << "Enter the date(day,month,year): ";
	console >> Event.myDate.day >> Event.myDate.month >> Event.myDate.year;

	// Assume name is a string (use char array if needed)
	cout << "Enter the time: ";
	console >> Event.myTime.hour >> Event.myTime.minute;

	return console;
}


