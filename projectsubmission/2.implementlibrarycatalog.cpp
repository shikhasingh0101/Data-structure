// Singly Linked List:
// 1.Implement Library Catalog
// - Design a system to keep track of books in a library
// -Each node represents a book, and the linked list facilitates easy addition
// and removal of books.
// -Searching of a book by title / author name.
// -Other customisations if you want to add
#include <iostream>
#include <string>

using namespace std;

struct Book {
    string title;
    string author;
    int year;
    Book* next;
};

class LibraryCatalog {
private:
    Book* head;

public:
    LibraryCatalog() : head(nullptr) {}

    void addBook(const string& title, const string& author, int year) {
        Book* newBook = new Book;
        newBook->title = title;
        newBook->author = author;
        newBook->year = year;
        newBook->next = nullptr;

        if (head == nullptr) {
            head = newBook;
        } else {
            Book* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newBook;
        }

        cout << "Book added to catalog.\n";
    }
    void searchByTitle(const string& title) {
        Book* current = head;
        bool found = false;

        while (current != nullptr) {
            if (current->title == title) {
                cout << "Book found:\n";
                cout << "Title: " << current->title << endl;
                cout << "Author: " << current->author << endl;
                cout << "Year: " << current->year << endl;
                found = true;
                break;
            }
            current = current->next;
        }

        if (!found) {
            cout << "Book not found.\n";
        }
    }

    void searchByAuthor(const string& author) {
        Book* current = head;
        bool found = false;

        while (current != nullptr) {
            if (current->author == author) {
                cout << "Book found:\n";
                cout << "Title: " << current->title << endl;
                cout << "Author: " << current->author << endl;
                cout << "Year: " << current->year << endl;
                found = true;
            }
            current = current->next;
        }

        if (!found) {
            cout << "No books found by this author.\n";
        }
    }

    void displayCatalog() {
        if (head == nullptr) {
            cout << "Library catalog is empty.\n";
            return;
        }

        cout << "Library Catalog:\n";
        cout << "-----------------\n";
        Book* current = head;
        while (current != nullptr) {
            cout << "Title: " << current->title << endl;
            cout << "Author: " << current->author << endl;
            cout << "Year: " << current->year << endl;
            cout << "-----------------\n";
            current = current->next;
        }
    }

    void clearCatalog() {
        while (head != nullptr) {
            Book* temp = head;
            head = head->next;
            delete temp;
        }
        cout << "Catalog cleared.\n";
    }

 
    ~LibraryCatalog() {
        clearCatalog();
    }
};

int main() {
    LibraryCatalog catalog;
    char choice;

    do {
        cout << "Library Catalog Menu\n";
        cout << "1. Add Book\n";
        cout << "2. Search by Title\n";
        cout << "3. Search by Author\n";
        cout << "4. Display Catalog\n";
        cout << "5. Clear Catalog\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case '1': {
                string title, author;
                int year;
                cout << "Enter title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter author: ";
                getline(cin, author);
                cout << "Enter year: ";
                cin >> year;
                catalog.addBook(title, author, year);
                break;
            }
            case '2': {
                string title;
                cout << "Enter title to search: ";
                cin.ignore();
                getline(cin, title);
                catalog.searchByTitle(title);
                break;
            }
            case '3': {
                string author;
                cout << "Enter author to search: ";
                cin.ignore();
                getline(cin, author);
                catalog.searchByAuthor(author);
                break;
            }
            case '4':
                catalog.displayCatalog();
                break;
            case '5':
                catalog.clearCatalog();
                break;
            case '6':
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != '6');

    return 0;
}
