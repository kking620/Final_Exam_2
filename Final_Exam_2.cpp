#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Customer {
    string name;
    string order;

    Customer* next;

    Customer(string n, string o) {
        name = n;
        order = o;
        next = nullptr;   
    }
};

class ListQueue {
    private:
        Customer* head;
        Customer* tail;

    public:
        ListQueue() {
            head = nullptr;
            tail = nullptr;
        }

        void addToBackOfQueue(string name, string order) {
            Customer* newNode = new Customer(name, order);

            if (tail == nullptr) {
                tail = newNode;
                head = tail;
            }
            else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        void displayQueue() {
            Customer* current = head;

            if (current == nullptr) {
                cout << "The queue is currently empty!\n";
            }
            else {
                cout << "Current Queue:\n";
                while (current != nullptr) {
                    cout << current->name << " ordered a " << current->order << endl;
                    current = current->next;
                }
            }
        }

};

const string NAMES[] = {"Alice", "Bob", "Charlie", "David", "Eve", "Frank", "Grace", "Heidi"};
const string COFFEE_ORDERS[] = {"Latte", "Cappuccino", "Espresso", "Cold Brew", "Americano", "Mocha"};

const int NUM_NAMES = 8;
const int NUM_COFFEE_ORDERS = 6;

int main() {
    srand(time(0));

    ListQueue coffeeShopQueue;

    for(int i = 0; i < 3; i++) {
        string name = NAMES[rand() % NUM_NAMES];
        string order = COFFEE_ORDERS[rand() % NUM_COFFEE_ORDERS];
        coffeeShopQueue.addToBackOfQueue(name, order);
    }

    coffeeShopQueue.displayQueue();

    return 0;
}