#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Ticket.h"

using namespace std;

class readFile {
public:
    
    ticket readTickeFile(const char* name) {
        ticket Ticket;

        ifstream file(name);
        if (!file.is_open()) {
            cerr << "Eroare la deschidere " << name << endl;
            exit(1);
        }

       
        int row ;
        int seat ;
        eventLocation location;
        event Event;
        movieCateg categ;
        teather categ2;

        while (file >> row >> seat>>Event>>location) {
            Ticket=ticket(row, seat, location, Event);
        }
        file.close();

        return Ticket;
    }
};
