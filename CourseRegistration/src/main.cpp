#include <iostream>
#include "Course.h"
#include "User.h"
#include "Student.h"
#include "Enrollment.h"

// ==== Auth functions ====
void registerStudent();
Student* loginStudent();

// ==== Course functions ====
void addCourse();
void viewCourses();

// ==== Enrollment functions ====
void enrollCourse(Student* student);
void dropCourse(Student* student);
void viewEnrolledCourses(Student* student);

// ==== Slip Generation ====
void generateEnrollmentSlip(Student* student);

// ==== Admin Report ====
void viewAdminReport();
void saveAdminReportToFile();

// ==== Faculty/Admin Menu ====
void facultyAdminMenu() {
    int ch;
    while (true) {
        std::cout << "\n=== Faculty / Admin Panel ===\n";
        std::cout << "1. Add Course\n";
        std::cout << "2. View All Courses\n";
        std::cout << "3. View System Report\n";
        std::cout << "4. Save System Report to File\n";
        std::cout << "5. Back to Main Menu\n";
        std::cout << "Enter choice: ";
        std::cin >> ch;

        switch (ch) {
        case 1:
            addCourse();
            break;
        case 2:
            viewCourses();
            break;
        case 3:
            viewAdminReport();
            break;
        case 4:
            saveAdminReportToFile();
            break;
        case 5:
            return;
        default:
            std::cout << "Invalid choice.\n";
        }
    }
}

// ==== Student Menu ====
void studentMenu(Student* student) {
    int ch;
    while (true) {
        std::cout << "\n=== Student Panel ===\n";
        std::cout << "1. View All Courses\n";
        std::cout << "2. Enroll in a Course\n";
        std::cout << "3. Drop a Course\n";
        std::cout << "4. View My Enrollments\n";
        std::cout << "5. Generate Enrollment Slip\n";
        std::cout << "6. Logout\n";
        std::cout << "Enter choice: ";
        std::cin >> ch;

        switch (ch) {
        case 1:
            viewCourses();
            break;
        case 2:
            enrollCourse(student);
            break;
        case 3:
            dropCourse(student);
            break;
        case 4:
            viewEnrolledCourses(student);
            break;
        case 5:
            generateEnrollmentSlip(student);
            break;
        case 6:
            return;
        default:
            std::cout << "Invalid choice.\n";
        }
    }
}

// ==== Main Program ====
int main() {
    int choice;
    Student* loggedInStudent = nullptr;

    while (true) {
        std::cout << "\n=== Course Registration Portal ===\n";
        std::cout << "1. Student Registration\n";
        std::cout << "2. Student Login\n";
        std::cout << "3. Faculty/Admin Panel\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            registerStudent();
            break;
        case 2:
            loggedInStudent = loginStudent();
            if (loggedInStudent) {
                studentMenu(loggedInStudent);
                delete loggedInStudent;
                loggedInStudent = nullptr;
            }
            break;
        case 3:
            facultyAdminMenu();
            break;
        case 4:
            std::cout << "Exiting...Bye...\n";
            return 0;
        default:
            std::cout << "Invalid choice.\n";
        }
    }
    return 0;
}
