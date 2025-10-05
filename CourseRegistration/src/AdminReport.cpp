#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <ctime>
using namespace std;

string getTimeNow() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char buf[40];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", ltm);
    return string(buf);
}

void viewAdminReport() {
    int studentCount = 0, courseCount = 0, enrollmentCount = 0;
    map<string,int> courseEnrollMap;

    // Count students
    ifstream sfile("data/students.csv");
    string line;
    getline(sfile, line);
    while (getline(sfile, line)) studentCount++;
    sfile.close();

    // Count courses
    ifstream cfile("data/courses.csv");
    getline(cfile, line);
    while (getline(cfile, line)) courseCount++;
    cfile.close();

    // Count enrollments
    ifstream efile("data/enrollments.csv");
    getline(efile, line);
    while (getline(efile, line)) {
        enrollmentCount++;
        stringstream ss(line);
        string eid, sid, cid, ts;
        getline(ss, eid, ',');
        getline(ss, sid, ',');
        getline(ss, cid, ',');
        getline(ss, ts, ',');
        courseEnrollMap[cid]++;
    }
    efile.close();

    cout << "\n=== System Report ===\n";
    cout << "Total Registered Students : " << studentCount << endl;
    cout << "Total Courses Offered     : " << courseCount << endl;
    cout << "Total Enrollments         : " << enrollmentCount << endl;
    cout << "\n--- Enrollment per Course ---\n";
    for (auto &c : courseEnrollMap)
        cout << "Course ID " << c.first << " → " << c.second << " students\n";
    cout << "---------------------------------------\n";
}

void saveAdminReportToFile() {
    int studentCount = 0, courseCount = 0, enrollmentCount = 0;
    map<string,int> courseEnrollMap;

    // Count students
    ifstream sfile("data/students.csv");
    string line;
    getline(sfile, line);
    while (getline(sfile, line)) studentCount++;
    sfile.close();

    // Count courses
    ifstream cfile("data/courses.csv");
    getline(cfile, line);
    while (getline(cfile, line)) courseCount++;
    cfile.close();

    // Count enrollments
    ifstream efile("data/enrollments.csv");
    getline(efile, line);
    while (getline(efile, line)) {
        enrollmentCount++;
        stringstream ss(line);
        string eid, sid, cid, ts;
        getline(ss, eid, ',');
        getline(ss, sid, ',');
        getline(ss, cid, ',');
        getline(ss, ts, ',');
        courseEnrollMap[cid]++;
    }
    efile.close();

    ofstream out("data/reports/admin_report.txt");
    if (!out.is_open()) {
        cerr << "Could not create report file.\n";
        return;
    }

    out << "=== Course Registration System Report ===\n";
    out << "Generated On: " << getTimeNow() << "\n";
    out << "------------------------------------------\n";
    out << "Total Registered Students : " << studentCount << "\n";
    out << "Total Courses Offered     : " << courseCount << "\n";
    out << "Total Enrollments         : " << enrollmentCount << "\n";
    out << "\n--- Enrollment per Course ---\n";
    for (auto &c : courseEnrollMap)
        out << "Course ID " << c.first << " -> " << c.second << " students\n";
    out << "------------------------------------------\n";
    out << "End of Report\n";
    out.close();

    cout << "Admin report saved at: data/reports/admin_report.txt\n";
}
