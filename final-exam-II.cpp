// COMSC-210 | Final Exam II | Annie Morales
// IDE used: Visual Studio Code

#include <iomanip>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

const int customers = 5;

struct Node {
    string name;
    string drink;
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

    Queue line;

    string names[] = {"Alex", "Erick" , "Ashley", "Dustin", "Robin", "Steve", "Nancy", "Jane", "Jack", "Lily", "Miri", "Ben"};
    string drinks[] = {"Latte", "Cold Brew", "Espresso", "Mocha", "Cappuccino", "Iced Tea"};

    for (int i = 0; i < 5; i++) {
        string aName = names[rand() % 11];
        string aDrink = drinks[rand() % 6];
        line.addCust(aName, aDrink);
    }

    cout << "\nQueue at Coffee Booth: \n";
    line.displayQueue();

    return 0;
}
