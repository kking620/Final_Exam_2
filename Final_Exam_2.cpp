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

        bool isEmpty() {
            if(head == nullptr) {
                return true;
            }
            else {
                return false;
            }
        }

        void customerServed() {
            if(head == nullptr)
                return;
            else {
                Customer* temp = head;
                head = head->next;
                if(head == nullptr) {
                    tail == nullptr;
                }
                delete temp;
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
const string COFFEE_ORDERS[] = {"Latte", "Cappuccino", "Large Espresso", "Cold Brew", "Small Americano", "Mocha"};

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

    for (int i = 0; i < 10; i++) {
        coffeeShopQueue.displayQueue();

        if (!coffeeShopQueue.isEmpty())
            coffeeShopQueue.customerServed();

        int customerJoins = 1 + rand() % 100;
        if (customerJoins <= 50) {
            string name = NAMES[rand() % NUM_NAMES];
            string order = COFFEE_ORDERS[rand() % NUM_COFFEE_ORDERS];
            coffeeShopQueue.addToBackOfQueue(name, order);
        }

        cout << endl;
    }

    cout << "Final Queue:\n";
    coffeeShopQueue.displayQueue();

    return 0;
}