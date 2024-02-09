#include<iostream>
using namespace std;

struct Student {
    int rollno;
    string name;
    string dateofbirth;
};

int main() {
    int numstudents;

    cout << "How many students' data do you want to enter: ";
    cin >> numstudents;

    
    Student s[10];  
   
    for (int i = 0; i < numstudents; i++) {
        cout << "\nEnter details for Student " << i + 1 << ":\n";
        
        cout << "Roll Number: ";
        cin >> s[i].rollno;

        cout << "Name: ";
        cin.ignore(); 
        getline(cin, s[i].name);

        cout << "Date of Birth: ";
        getline(cin, s[i].dateofbirth);
    }

    cout << "\nStudent Information:\n";
    for (int i = 0; i < numstudents; i++) {
        cout << "\nStudent " << i + 1 << ":\n";
        cout << "Roll Number: " << s[i].rollno << endl;
        cout << "Name: " << s[i].name << endl;
        cout << "Date of Birth: " << s[i].dateofbirth << endl;
    }

    return 0;
}
