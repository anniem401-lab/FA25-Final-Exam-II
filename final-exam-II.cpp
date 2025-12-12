// COMSC-210 | Final Exam II | Annie Morales
// IDE used: Visual Studio Code

#include <iomanip>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

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
};


int main()
{
    Node *head = nullptr;
    srand(time(0));

    string names[] = {"Alex", "Erick" , "Ashley", "Dustin", "Robin", "Steve", "Nancy", "Jane"};
    string drinks[] = {"Latte", "Cold Brew", "Espresso", "Mocha", "Cappuccino", "Iced Tea"};

    for (int i = 0; i < 5; i++) {

    }

    cout << "\nQueue at Coffee Booth: \n";

    return 0;
}
