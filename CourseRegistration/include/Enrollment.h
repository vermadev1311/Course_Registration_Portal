// Enrollment.h 
#ifndef ENROLLMENT_H
#define ENROLLMENT_H

#include <string>

class Enrollment {
public:
    std::string enrollId;
    std::string studentId;
    std::string courseId;
    std::string timestamp;

    Enrollment() {}

    Enrollment(const std::string &eid, const std::string &sid,
               const std::string &cid, const std::string &time)
        : enrollId(eid), studentId(sid), courseId(cid), timestamp(time) {}
};

#endif
