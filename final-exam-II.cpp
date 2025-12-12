// COMSC-210 | Final Exam II | Annie Morales
// IDE used: Visual Studio Code

#include <iomanip>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <deque>
using namespace std;

const int customers = 3;

struct Node {
    string name;
    string drink;
    string muffin;
    Node* next;
};

class Queue {
private:
    Node* head;
    Node* tail;

public:
    Queue() {
        head = nullptr;
        tail = nullptr;
    }

    void addCust(string name, string drink) {
        Node* newNode = new Node;
        newNode->name = name;
        newNode->drink = drink;
        newNode->next = head;
        head = newNode;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
    }

    bool empty() {
        return head == nullptr;
    }

    void serveCust() {
        if (!head) {
            cout << "No customer to serve.\n";
            return;
        }

        Node* temp = head;
        cout << "Serving: " << temp->name << " - " << temp->drink << endl;

        head = head->next;
        delete temp;

        if (head == nullptr) {
            tail = nullptr;
        }
    }

    void displayQueue() {
        Node* current = head;
        while (current != nullptr) {
            cout << "Name: " << current->name << " - " << "Drink: " << current->drink << endl;
            current = current->next;
        }
    }
};


int main()
{
    Node *head = nullptr;
    srand(time(0));

    Queue CB_line; // Coffee Booth
    deque<pair<string, string>> MB_line; // Muffin Booth

    string names[] = {"Alex", "Erick" , "Ashley", "Dustin", "Robin", "Steve", "Nancy", "Jane", "Jack", "Lily", "Miri", "Ben", "Max", "Lucas" , "Mike", "Pat", "Jen"};
    string drinks[] = {"Latte", "Cold Brew", "Espresso", "Mocha", "Cappuccino", "Iced Tea"};

    string muffins[] = {"Blueberry", "Chocolate", "Lemon", "Strawberry", "Banana Nut", "Coffee Cake"};

    cout << "\n== Coffee & Muffin Booth are open! ==" << endl;
    for (int i = 0; i < customers; i++) { // Coffee Booth
        string aName = names[rand() % 17];
        string aDrink = drinks[rand() % 6];
        CB_line.addCust(aName, aDrink);
    }

    for (int i = 0; i < customers; i++) {
        string aName = names[rand() % 15];
        string aMuffin = muffins[rand() % 6];
        MB_line.push_back({aName, aMuffin});
    }

    cout << "\nInitial queue at Coffee Booth: \n";
    cout << "----------------------------------\n";
    CB_line.displayQueue();
    cout << endl;

    // Simulation
    int roundsMax = 10;
    for (int i = 0; i < roundsMax; i++) {
        cout << "----------------------------------\n";
        cout << "Round #" << i + 1 << endl;

        if (!CB_line.empty()) {
            CB_line.serveCust();
        }
        else {
            cout << "Queue is empty.\n";
        }

        // 50% probability customer joins
        int prob = rand() % 100 + 1;
        if (prob <= 50) {
            string newName = names[rand() % 12];
            string newDrink = drinks[rand() % 6];
            cout << "New customer: " << newName << " - " << newDrink << endl;
            CB_line.addCust(newName, newDrink);
        }
    }
    cout << endl;
    return 0;
}
