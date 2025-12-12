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
const vector<string> BRACELET_ORDERS = {"Macrame Bracelet", "Beaded Bracelet", "Charm Bracelet", "Leather Wrap Bracelet"};
const string BOOK_TITLES[] = {"C++ Primer", "Dune", "1984", "The Hitchhiker's Guide", "Frankenstein", "Dracula", "Moby Dick"};

const int NUM_NAMES = 8;
const int NUM_COFFEE_ORDERS = 6;
const int NUM_MUFFIN_ORDERS = 4;
const int NUM_BOOK_TITLES = 7;

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

    vector<pair<string, string>> braceletBoothQueue;
    for (int i = 0; i < 3; i++) {
        string name = NAMES[rand() % NUM_NAMES];
        string order = BRACELET_ORDERS[rand() % BRACELET_ORDERS.size()];
        braceletBoothQueue.push_back({name, order});
    }

    list<pair<string, string>> bookBoothQueue;
    for (int i = 0; i < 3; i++) {
        string name = NAMES[rand() % NUM_NAMES];
        string order = BOOK_TITLES[rand() % NUM_BOOK_TITLES];
        bookBoothQueue.push_back({name, order});
    }

    for (int i = 0; i < 10; i++) {
        cout << "Queue for the Coffee Shop:\n";
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

        cout << "Queue for the Muffin Booth:\n";
        if (muffinBoothQueue.empty()) {
            cout << "The queue for the muffin booth is currently empty!";
        }
        else {
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

        cout << endl;
        
        cout << "Queue for the Bracelet Booth:\n";
        if (braceletBoothQueue.empty()) {
            cout << "The queue for the bracelet booth is currently empty!";
        }
        else {
            for (int i = 0; i < braceletBoothQueue.size(); i++) {
                cout << braceletBoothQueue[i].first << " ordered a " << braceletBoothQueue[i].second << endl;
            }
        }

        if (!braceletBoothQueue.empty())
            braceletBoothQueue.erase(braceletBoothQueue.begin());
        
        int customerJoinsBraceletBooth = (1 + rand() % 100);
        if (customerJoinsBraceletBooth <= 50) {
            string name = NAMES[rand() % NUM_NAMES];
            string order = BRACELET_ORDERS[rand() % BRACELET_ORDERS.size()];
            braceletBoothQueue.push_back({name, order});
        }

        cout << endl;

        cout << "Queue for the Book Booth:\n";
        if (bookBoothQueue.empty()) {
            cout << "The queue for the book booth is currently empty!\n";
        }
        else {
            for (const auto& pair : bookBoothQueue) {
                cout << pair.first << " bought a copy of " << pair.second << endl;
            }
        }

        if(!bookBoothQueue.empty())
            bookBoothQueue.pop_front();

        int customerJoinsBookBooth = (1 + rand() % 100);
        if (customerJoinsBookBooth <= 50) {
            string name = NAMES[rand() % NUM_NAMES];
            string order = BOOK_TITLES[rand() % NUM_BOOK_TITLES];
            bookBoothQueue.push_back({name, order});
        }

        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    }

    cout << "\nFinal Queues:\n";
    cout << "~~~~~~~~~~~~~\n\n";
    
    cout << "Final Queue for the Coffee Shop (Singly Linked List):\n";
    coffeeShopQueue.displayQueue();
    cout << endl;

    cout << "Final Queue for the Muffin Booth (std::dequeue):\n";
    if (muffinBoothQueue.empty()) {
        cout << "The queue for the muffin booth is empty!\n";
    }
    else if (!muffinBoothQueue.empty()) {
            
            for (const auto& pair : muffinBoothQueue) {
                cout << pair.first << " ordered a " << pair.second << endl;
            }
    }
    cout << endl;

    cout << "Final Queue for the Bracelet Booth (std::vector):\n";
    if (braceletBoothQueue.empty()) {
        cout << "The queue for the bracelet booth is empty!\n";
    }
    else if (!braceletBoothQueue.empty()) {
        for (int i = 0; i < braceletBoothQueue.size(); i++) {
            cout << braceletBoothQueue[i].first << " ordered a " << braceletBoothQueue[i].second << endl;
        }
    }
    cout << endl;

    cout << "Final Queue for the Book Booth (std::list):\n";
        if (bookBoothQueue.empty()) {
            cout << "The queue for the book booth is empty!\n";
        }
        else {
            for (const auto& pair : bookBoothQueue) {
                cout << pair.first << " ordered a " << pair.second << endl;
            }
        }

    return 0;
}