// Student.h 
#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"
#include <vector>
#include <string>

class Student : public User {
private:
    std::vector<std::string> enrolledCourseIds;

public:
    Student() {}

    Student(const std::string &id_, const std::string &name_,
            const std::string &email_, const std::string &password_)
        : User(id_, name_, email_, password_) {}

    void enroll(const std::string &courseId) {
        enrolledCourseIds.push_back(courseId);
    }

    void drop(const std::string &courseId) {
        for (auto it = enrolledCourseIds.begin(); it != enrolledCourseIds.end(); ++it) {
            if (*it == courseId) {
                enrolledCourseIds.erase(it);
                break;
            }
        }
    }

    const std::vector<std::string>& getEnrolledCourses() const {
        return enrolledCourseIds;
    }
};

#endif
