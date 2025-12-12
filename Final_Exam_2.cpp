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
                    tail = nullptr;
                }
                delete temp;
            }
        }

        void displayQueue() {
            Customer* current = head;

            if (current == nullptr) {
                cout << "The queue for the coffee shop is currently empty!\n";
            }
            else {
                cout << "Current Queue for the Coffee Shop:\n";
                while (current != nullptr) {
                    cout << current->name << " ordered a " << current->order << endl;
                    current = current->next;
                }
            }
        }

};

const string NAMES[] = {"Alice", "Bob", "Charlie", "David", "Eve", "Frank", "Grace", "Heidi"};
const string COFFEE_ORDERS[] = {"Latte", "Cappuccino", "Large Espresso", "Cold Brew", "Small Americano", "Mocha"};
const string MUFFIN_ORDERS[] = {"Blueberry Muffin", "Chocolate Chip Muffin", "Banana Nut Muffin", "Poppy Seed Muffin"};

const int NUM_NAMES = 8;
const int NUM_COFFEE_ORDERS = 6;
const int NUM_MUFFIN_ORDERS = 4;

int main() {
    srand(time(0));

    ListQueue coffeeShopQueue;
    for(int i = 0; i < 3; i++) {
        string name = NAMES[rand() % NUM_NAMES];
        string order = COFFEE_ORDERS[rand() % NUM_COFFEE_ORDERS];
        coffeeShopQueue.addToBackOfQueue(name, order);
    }

    deque<pair<string, string>> muffinBoothQueue;
    for(int i = 0; i < 3; i++) {
        string name = NAMES[rand() % NUM_NAMES];
        string order = MUFFIN_ORDERS[rand() % NUM_MUFFIN_ORDERS];
        muffinBoothQueue.push_back({name, order});
    }

    for (int i = 0; i < 10; i++) {
        coffeeShopQueue.displayQueue();

        if (!coffeeShopQueue.isEmpty())
            coffeeShopQueue.customerServed();

        int customerJoinsCoffeeShop = (1 + rand() % 100);
        if (customerJoinsCoffeeShop <= 50) {
            string name = NAMES[rand() % NUM_NAMES];
            string order = COFFEE_ORDERS[rand() % NUM_COFFEE_ORDERS];
            coffeeShopQueue.addToBackOfQueue(name, order);
        }

        cout << endl;
        
        if (muffinBoothQueue.empty()) {
            cout << "The queue for the muffin booth is currently empty!";
        }
        else if (!muffinBoothQueue.empty()) {
            cout << "Current Queue for the Muffin Booth:\n";
            for (const auto& pair : muffinBoothQueue) {
                cout << pair.first << " ordered a " << pair.second << endl;
            }
        }
       
        if (!muffinBoothQueue.empty())
            muffinBoothQueue.pop_front();
        
        int customerJoinsMuffinBooth = (1 + rand() % 100);
        if (customerJoinsMuffinBooth <= 50) {
            string name = NAMES[rand() % NUM_NAMES];
            string order = MUFFIN_ORDERS[rand() % NUM_MUFFIN_ORDERS];
            muffinBoothQueue.push_back({name, order});
        }

        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    }

    cout << "Final Queues:\n";
    coffeeShopQueue.displayQueue();
    if (muffinBoothQueue.empty()) {
        cout << "The queue for the muffin booth is currently empty!";
    }
    else if (!muffinBoothQueue.empty()) {
            for (const auto& pair : muffinBoothQueue) {
                cout << pair.first << " ordered a " << pair.second << endl;
            }
    }

    return 0;
}