#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Student {
    int rollNo;
    string name;
    float marks;
};

void addStudent() {
    Student s;
    cout << "Enter Roll No: ";
    cin >> s.rollNo;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, s.name);
    cout << "Enter Marks: ";
    cin >> s.marks;

    ofstream file("students.txt", ios::app);
    if (file.is_open()) {
        file << s.rollNo << "," << s.name << "," << s.marks << endl;
        file.close();
        cout << "Student added successfully!\n";
    } else {
        cout << "Error opening file.\n";
    }
}

void viewStudents() {
    ifstream file("students.txt");
    string line;
    cout << "\n-- Student Records --\n";
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

void searchStudent(int rollNo) {
    ifstream file("students.txt");
    string line;
    bool found = false;
    while (getline(file, line)) {
        size_t pos1 = line.find(",");
        int r = stoi(line.substr(0, pos1));
        if (r == rollNo) {
            cout << "Record Found: " << line << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "Student not found.\n";
    file.close();
}

void menu() {
    int choice;
    do {
        cout << "\n--- Student Record Management ---\n";
        cout << "1. Add Student\n2. View Students\n3. Search by Roll No\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: {
                int roll;
                cout << "Enter Roll No to search: ";
                cin >> roll;
                searchStudent(roll);
                break;
            }
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);
}

int main() {
    menu();
    return 0;
}
