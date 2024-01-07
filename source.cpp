

#include <iostream>
#include <fstream>  // Required for file operations
#include"Ticket.h"
using namespace std;


void displayMenu() {
    cout << "===== Menu =====" << endl;
    cout << "1. Buy Ticket" << endl;
    cout << "2. View Ticket Details" << endl;
    cout << "3. Save Tickets to File" << endl;
    cout << "4. Load Tickets from File" << endl;
    cout << "5. Exit" << endl;
    cout << "================" << endl;
}


void menu() {
    displayMenu();

    ticket Ticket;

    int choice;

    do {
       
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            Ticket.buyTicket(Ticket);
            break;
        case 2:
            Ticket.printTicketDetails();
            break;
        case 3:
            Ticket.saveToFile("ticket.dat");
            break;
        case 4:
            Ticket.loadFromFile("ticket.dat");
            break;
        case 5:
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
            break;
        }

    } while (choice != 5);


}

int main(int argc, char* argv[]) {

    ticket Ticket;

    menu();

    if (argc == 1) {
        // No command line arguments provided, interact with the user through the console
        // Your existing code for console interaction goes here
    }
    else if (argc == 2) {
        // One command line argument provided, assume it is a filename
        const char* filename = argv[1];
        ifstream file(filename);

        if (file.is_open()) {
            // File opened successfully, read input from the file
            // Your existing code for file input goes here
            file.close();
        }
        else {
            cout << "Error opening file: " << filename << endl;
        }
    }
    else {
        cout << "Usage: " << argv[0] << " [filename]" << endl;
        cout << "If filename is provided, read input from the file; otherwise, interact with the user through the console." << endl;
    }
    Ticket.saveToFile("tickets.dat");//save
    ticket loadTicket = ticket::loadFromFile("tickets.dat");//load

    return 0;
}
