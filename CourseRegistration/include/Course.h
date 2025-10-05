// Course.h 
#ifndef COURSE_H
#define COURSE_H

#include <string>

class Course {
public:
    std::string id;
    std::string title;
    int credits;
    std::string faculty;
    int seats;

    Course() {}

    Course(const std::string &id_, const std::string &title_, int credits_,
           const std::string &faculty_, int seats_)
        : id(id_), title(title_), credits(credits_), faculty(faculty_), seats(seats_) {}
};

#endif
