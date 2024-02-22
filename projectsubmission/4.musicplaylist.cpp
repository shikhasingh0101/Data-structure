// Doubly Linked List:
// 1.Music playlist creation
// -Design a system to keep track of songs in a playlist
// -Song details are represented by nodes in a doubly linked list.
// -Navigate through previous and next song in the list
// -Display the songs according to producer, singer and genre.
// -Other customisations if you want to add
#include <iostream>
#include <string>

using namespace std;

struct Song {
    string title;
    string producer;
    string singer;
    string genre;
    Song* prev;
    Song* next;
};

class MusicPlaylist {
private:
    Song* head;
    Song* tail;
    Song* current;

public:
    MusicPlaylist() : head(nullptr), tail(nullptr), current(nullptr) {}

    void addSong(const string& title, const string& producer, const string& singer, const string& genre) {
        Song* newSong = new Song;
        newSong->title = title;
        newSong->producer = producer;
        newSong->singer = singer;
        newSong->genre = genre;
        newSong->prev = nullptr;
        newSong->next = nullptr;

        if (head == nullptr) {
            head = newSong;
            tail = newSong;
            current = newSong;
        } else {
            tail->next = newSong;
            newSong->prev = tail;
            tail = newSong;
        }

        cout << "Song added to playlist: " << title << endl;
    }

   
    void displayCurrentSong() {
        if (current == nullptr) {
            cout << "Playlist is empty.\n";
            return;
        }

        cout << "Current Song:\n";
        cout << "Title: " << current->title << endl;
        cout << "Producer: " << current->producer << endl;
        cout << "Singer: " << current->singer << endl;
        cout << "Genre: " << current->genre << endl;
    }
    void nextSong() {
        if (current == nullptr || current->next == nullptr) {
            cout << "No next song available.\n";
            return;
        }

        current = current->next;
        displayCurrentSong();
    }

   
    void previousSong() {
        if (current == nullptr || current->prev == nullptr) {
            cout << "No previous song available.\n";
            return;
        }

        current = current->prev;
        displayCurrentSong();
    }

    void displayByProducer(const string& producer) {
        Song* temp = head;
        bool found = false;

        cout << "Songs by Producer " << producer << ":\n";
        while (temp != nullptr) {
            if (temp->producer == producer) {
                cout << "Title: " << temp->title << endl;
                cout << "Singer: " << temp->singer << endl;
                cout << "Genre: " << temp->genre << endl;
                cout << "-----------------\n";
                found = true;
            }
            temp = temp->next;
        }

        if (!found) {
            cout << "No songs found by this producer.\n";
        }
    }

    void displayBySinger(const string& singer) {
        Song* temp = head;
        bool found = false;

        cout << "Songs by Singer " << singer << ":\n";
        while (temp != nullptr) {
            if (temp->singer == singer) {
                cout << "Title: " << temp->title << endl;
                cout << "Producer: " << temp->producer << endl;
                cout << "Genre: " << temp->genre << endl;
                cout << "-----------------\n";
                found = true;
            }
            temp = temp->next;
        }

        if (!found) {
            cout << "No songs found by this singer.\n";
        }
    }
    void displayByGenre(const string& genre) {
        Song* temp = head;
        bool found = false;

        cout << "Songs of Genre " << genre << ":\n";
        while (temp != nullptr) {
            if (temp->genre == genre) {
                cout << "Title: " << temp->title << endl;
                cout << "Producer: " << temp->producer << endl;
                cout << "Singer: " << temp->singer << endl;
                cout << "-----------------\n";
                found = true;
            }
            temp = temp->next;
        }

        if (!found) {
            cout << "No songs found in this genre.\n";
        }
    }
};

int main() {
    MusicPlaylist playlist;
    char choice;

    do {
        cout << "\nMusic Playlist Menu\n";
        cout << "1. Add Song\n";
        cout << "2. Display Current Song\n";
        cout << "3. Play Next Song\n";
        cout << "4. Play Previous Song\n";
        cout << "5. Display Songs by Producer\n";
        cout << "6. Display Songs by Singer\n";
        cout << "7. Display Songs by Genre\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case '1': {
                string title, producer, singer, genre;
                cout << "Enter song title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter producer: ";
                getline(cin, producer);
                cout << "Enter singer: ";
                getline(cin, singer);
                cout << "Enter genre: ";
                getline(cin, genre);
                playlist.addSong(title, producer, singer, genre);
                break;
            }
            case '2':
                playlist.displayCurrentSong();
                break;
            case '3':
                playlist.nextSong();
                break;
            case '4':
                playlist.previousSong();
                break;
            case '5': {
                string producer;
                cout << "Enter producer: ";
                cin.ignore();
                getline(cin, producer);
                playlist.displayByProducer(producer);
                break;
            }
            case '6': {
                string singer;
                cout << "Enter singer: ";
                cin.ignore();
                getline(cin, singer);
                playlist.displayBySinger(singer);
                break;
            }
            case '7': {
                string genre;
                cout << "Enter genre: ";
                cin.ignore();
                getline(cin, genre);
                playlist.displayByGenre(genre);
                break;
            }
            case '8':
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != '8');

    return 0;
}
