#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include "Student.h"
#include "Course.h"

using namespace std;

string getTimestamp() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char buf[30];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", ltm);
    return string(buf);
}

void generateEnrollmentSlip(Student* student) {
    if (!student) {
        cout << "Please login first.\n";
        return;
    }

    ifstream enrollFile("data/enrollments.csv");
    ifstream courseFile("data/courses.csv");
    if (!enrollFile.is_open() || !courseFile.is_open()) {
        cerr << "Could not open enrollment or course file.\n";
        return;
    }

    // load courses in memory
    vector<pair<string,string>> courseList; // id,title
    string line;
    getline(courseFile, line);
    while (getline(courseFile, line)) {
        stringstream ss(line);
        string id, title, credits, faculty, seats;
        getline(ss, id, ',');
        getline(ss, title, ',');
        getline(ss, credits, ',');
        getline(ss, faculty, ',');
        getline(ss, seats, ',');
        courseList.push_back({id, title});
    }
    courseFile.close();

    // prepare output file
    string filename = "data/slips/" + student->getId() + "_enrollment_slip.txt";
    ofstream slip(filename);
    slip << "=== Enrollment Slip ===\n";
    slip << "Student Name : " << student->getName() << "\n";
    slip << "Student ID   : " << student->getId() << "\n";
    slip << "Email        : " << student->getEmail() << "\n";
    slip << "Generated On : " << getTimestamp() << "\n";
    slip << "-------------------------------------------\n";
    slip << "Course ID   | Course Title\n";
    slip << "-------------------------------------------\n";

    bool any = false;
    getline(enrollFile, line);
    while (getline(enrollFile, line)) {
        stringstream ss(line);
        string eid, sid, cid, ts;
        getline(ss, eid, ',');
        getline(ss, sid, ',');
        getline(ss, cid, ',');
        getline(ss, ts, ',');

        if (sid == student->getId()) {
            for (auto &c : courseList)
                if (c.first == cid)
                    slip << cid << "        | " << c.second << "\n";
            any = true;
        }
    }
    enrollFile.close();

    if (!any) slip << "(No enrollments found)\n";
    slip << "-------------------------------------------\n";
    slip << "Signature: ________________________________\n";
    slip.close();

    cout << "Enrollment slip generated: " << filename << "\n";
}
