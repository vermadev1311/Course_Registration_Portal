#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include "Student.h"
#include "Course.h"

using namespace std;

// Generate unique Enrollment ID
string generateEnrollmentId() {
    static int counter = 2000;
    return "E" + to_string(counter++);
}

// Get current timestamp as string
string getCurrentTime() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char buf[30];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", ltm);
    return string(buf);
}

// Enroll student in a course
void enrollCourse(Student* student) {
    if (!student) {
        cout << "You must log in first.\n";
        return;
    }

    string courseId;
    cout << "\nEnter Course ID to enroll: ";
    cin >> courseId;

    // Check for duplicate
    ifstream infile("data/enrollments.csv");
    string line;
    while (getline(infile, line)) {
        stringstream ss(line);
        string eid, sid, cid, time;
        getline(ss, eid, ',');
        getline(ss, sid, ',');
        getline(ss, cid, ',');
        getline(ss, time, ',');

        if (sid == student->getId() && cid == courseId) {
            cout << "You are already enrolled in this course.\n";
            return;
        }
    }
    infile.close();

    string enrollId = generateEnrollmentId();
    string timestamp = getCurrentTime();

    ofstream file("data/enrollments.csv", ios::app);
    if (file.is_open()) {
        file << enrollId << "," << student->getId() << "," << courseId << "," << timestamp << "\n";
        file.close();
        cout << "Enrolled successfully in course " << courseId << "!\n";
    } else {
        cerr << "Could not open enrollments.csv\n";
    }
}

// Drop an enrolled course
void dropCourse(Student* student) {
    if (!student) {
        cout << "You must log in first.\n";
        return;
    }

    string courseId;
    cout << "\nEnter Course ID to drop: ";
    cin >> courseId;

    ifstream infile("data/enrollments.csv");
    ofstream temp("data/temp.csv");
    string line;
    bool found = false;

    if (infile.is_open() && temp.is_open()) {
        while (getline(infile, line)) {
            stringstream ss(line);
            string eid, sid, cid, time;
            getline(ss, eid, ',');
            getline(ss, sid, ',');
            getline(ss, cid, ',');
            getline(ss, time, ',');

            if (sid == student->getId() && cid == courseId) {
                found = true;
                continue; // skip this line (delete)
            }
            temp << eid << "," << sid << "," << cid << "," << time << "\n";
        }
        infile.close();
        temp.close();

        remove("data/enrollments.csv");
        rename("data/temp.csv", "data/enrollments.csv");

        if (found)
            cout << "Dropped course " << courseId << " successfully.\n";
        else
            cout << "You are not enrolled in " << courseId << ".\n";
    } else {
        cerr << "Could not process file.\n";
    }
}

// View all enrolled courses for the logged-in student
void viewEnrolledCourses(Student* student) {
    if (!student) {
        cout << "You must log in first.\n";
        return;
    }

    ifstream file("data/enrollments.csv");
    if (!file.is_open()) {
        cerr << "Could not open enrollments.csv\n";
        return;
    }

    string line;
    getline(file, line); // skip header if present

    cout << "\n--- Your Enrolled Courses ---\n";
    bool hasAny = false;
    while (getline(file, line)) {
        stringstream ss(line);
        string eid, sid, cid, time;
        getline(ss, eid, ',');
        getline(ss, sid, ',');
        getline(ss, cid, ',');
        getline(ss, time, ',');

        if (sid == student->getId()) {
            cout << "Course ID: " << cid << " (Enrolled on " << time << ")\n";
            hasAny = true;
        }
    }

    if (!hasAny) cout << "You are not enrolled in any courses yet.\n";
    file.close();
}
