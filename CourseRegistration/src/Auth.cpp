// Auth.cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "Student.h"

using namespace std;

string generateStudentId() {
    static int counter = 1000;
    return "S" + to_string(counter++);
}

// Register a new student
void registerStudent() {
    string name, email, password;
    cout << "\n--- Student Registration ---\n";
    cout << "Name: ";
    getline(cin >> ws, name);
    cout << "Email: ";
    getline(cin, email);
    cout << "Password: ";
    getline(cin, password);

    string id = generateStudentId();

    ofstream file("data/students.csv", ios::app);
    if (file.is_open()) {
        file << id << "," << name << "," << email << "," << password << "\n";
        file.close();
        cout << "Registration successful! Your ID is: " << id << endl;
    } else {
        cerr << "Error: Cannot open students.csv\n";
    }
}

// Login existing student
Student* loginStudent() {
    string email, password;
    cout << "\n--- Student Login ---\n";
    cout << "Email: ";
    getline(cin >> ws, email);
    cout << "Password: ";
    getline(cin, password);

    ifstream file("data/students.csv");
    if (!file.is_open()) {
        cerr << "Unable to open students.csv\n";
        return nullptr;
    }
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string id, name, mail, pass;

        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, mail, ',');
        getline(ss, pass, ',');

        if (mail == email && pass == password) {
            cout << "Login successful! Welcome, " << name << endl;
            file.close();
            return new Student(id, name, mail, pass);
        }
    }

    cout << "Invalid email or password.\n";
    file.close();
    return nullptr;
}
