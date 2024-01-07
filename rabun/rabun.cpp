#include <iostream>
#include <queue>
#include <string>

using namespace std;

queue<string> ticketQueue;
int maxQueueSize = 5;

void joinQueue(const string& person) {
    if (ticketQueue.size() < maxQueueSize) {
        ticketQueue.push(person);
        cout << person << " joined the ticket queue." << endl;
    }
    else {
        cout << "Queue is full! " << person << " cannot join the queue." << endl;
    }
}

void serveNext() {
    if (!ticketQueue.empty()) {
        cout << "Now serving: " << ticketQueue.front() << endl;
        ticketQueue.pop();
    }
    else {
        cout << "Queue is empty. No one to serve." << endl;
    }
}

void displayQueue() {
    cout << "Current queue:";
    if (ticketQueue.empty()) {
        cout << " Empty" << endl;
    }
    else {
        queue<string> tempQueue = ticketQueue;
        while (!tempQueue.empty()) {
            cout << " " << tempQueue.front();
            tempQueue.pop();
        }
        cout << endl;
    }
}

int main() {
    int choice;
    string person;

    do {
        cout << "\nMenu:\n";
        cout << "1. Join the queue\n";
        cout << "2. Serve the next person\n";
        cout << "3. Display queue\n";
        cout << "4. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the name to join the queue: ";
            cin >> person;
            joinQueue(person);
            break;

        case 2:
            serveNext();
            break;

        case 3:
            displayQueue();
            break;

        case 4:
            cout << "Exiting the program.\n";
            break;

        default:
            cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 4);

    return 0;
}