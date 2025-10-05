#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "Course.h"

using namespace std;

// Helper to generate unique Course IDs
string generateCourseId() {
    static int counter = 101;
    return "C" + to_string(counter++);
}

// Add a new course
void addCourse() {
    string title, faculty;
    int credits, seats;

    cout << "\n--- Add New Course ---\n";
    cout << "Course Title: ";
    getline(cin >> ws, title);
    cout << "Credits: ";
    cin >> credits;
    cout << "Faculty Name: ";
    getline(cin >> ws, faculty);
    cout << "Total Seats: ";
    cin >> seats;

    string id = generateCourseId();

    ofstream file("data/courses.csv", ios::app);
    if (file.is_open()) {
        file << id << "," << title << "," << credits << "," << faculty << "," << seats << "\n";
        file.close();
        cout << "Course added successfully with ID: " << id << endl;
    } else {
        cerr << "Could not open courses.csv\n";
    }
}

// Display all available courses
void viewCourses() {
    ifstream file("data/courses.csv");
    if (!file.is_open()) {
        cerr << "Could not open courses.csv\n";
        return;
    }

    string line;
    getline(file, line); // skip header

    cout << "\n--- Available Courses ---\n";
    cout << "ID\tTitle\t\tCredits\tFaculty\t\tSeats\n";
    cout << "-----------------------------------------------\n";

    while (getline(file, line)) {
        stringstream ss(line);
        string id, title, credits, faculty, seats;
        getline(ss, id, ',');
        getline(ss, title, ',');
        getline(ss, credits, ',');
        getline(ss, faculty, ',');
        getline(ss, seats, ',');

        cout << id << "\t" << title << "\t" << credits << "\t" << faculty << "\t" << seats << endl;
    }

    file.close();
}
