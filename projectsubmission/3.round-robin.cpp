// Circular Linked List:
// 1.Round-Robin Scheduling: (Please follow the different constraints as
// discussed in the class)
// -Simulate a round-robin scheduling for a set of users in an department for
// printing task.
// -Users are represented by nodes in a circular linked list, and each iteration
// of the algorithm selects the next user in the circle.
// -Other customisations if you want to add
#include <iostream>
#include <string>

using namespace std;

struct User {
    string name;
    User* next;
};

class RoundRobinScheduler {
private:
    User* head;
    User* current;

public:
    RoundRobinScheduler() : head(nullptr), current(nullptr) {}

    void addUser(const string& name) {
        User* newUser = new User;
        newUser->name = name;
        newUser->next = nullptr;

        if (head == nullptr) {
            head = newUser;
            head->next = head; 
            current = head;    
        } else {
            newUser->next = head->next;
            head->next = newUser;
        }

        cout << "User added: " << name << endl;
    }

    
    void removeUser() {
        if (current == nullptr) {
            cout << "Scheduler is empty.\n";
            return;
        }

        User* temp = current->next;
        if (temp == current) { 
            delete current;
            head = nullptr;
            current = nullptr;
        } else {
            current->next = temp->next;
            if (temp == head) {
                head = temp->next;
            }
            delete temp;
        }

        cout << "Current user removed.\n";
    }

    void nextUser() {
        if (current == nullptr) {
            cout << "Scheduler is empty.\n";
            return;
        }

        cout << "Printing task for user: " << current->name << endl;
        current = current->next; 
    }

    
    void displayUsers() {
        if (current == nullptr) {
            cout << "Scheduler is empty.\n";
            return;
        }

        cout << "Users in the scheduler:\n";
        User* temp = head->next;
        cout << temp->name << " (current)" << endl;
        temp = temp->next;
        while (temp != head->next) {
            cout << temp->name << endl;
            temp = temp->next;
        }
    }

  
    ~RoundRobinScheduler() {
        while (head != nullptr) {
            removeUser();
        }
    }
};

int main() {
    RoundRobinScheduler scheduler;
    char choice;

    do {
        cout << "\nRound-Robin Scheduler Menu\n";
        cout << "1. Add User\n";
        cout << "2. Remove Current User\n";
        cout << "3. Next User (Perform Printing Task)\n";
        cout << "4. Display Users\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case '1': {
                string name;
                cout << "Enter user name: ";
                cin >> name;
                scheduler.addUser(name);
                break;
            }
            case '2':
                scheduler.removeUser();
                break;
            case '3':
                scheduler.nextUser();
                break;
            case '4':
                scheduler.displayUsers();
                break;
            case '5':
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != '5');

    return 0;
}
