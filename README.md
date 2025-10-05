# 📘 Course Registration Portal (C++)

A console-based **Course Registration System** built in **C++** that simulates a real-world college course registration workflow.  
This project demonstrates **Object-Oriented Programming (OOP)**, **file handling**, and **modular design** using multiple source/header files.

---

## 🚀 Features

### 👨‍🎓 Student Module
- Student **Registration** (creates and stores user data in `students.csv`)
- Student **Login** (authenticates via email & password)
- **View Available Courses**
- **Enroll / Drop Courses**
- **View Enrolled Courses**
- **Generate Enrollment Slip** (saved in `data/slips/`)

### 🧑‍🌭 Faculty / Admin Module
- **Add New Courses**
- **View All Courses**
- **View System Report**
- **Save Report to File** (`data/reports/admin_report.txt`)

### 🗂️ Admin Report Includes:
- Total number of registered students
- Total available courses
- Total enrollments
- Enrollment count per course

---

## 🧱 Technologies Used
- **Language:** C++17
- **Concepts:** Classes, Inheritance, File I/O, Encapsulation, Modular Programming
- **Compiler:** MinGW / g++
- **IDE (optional):** Visual Studio Code or Code::Blocks

---

## 💃 Folder Structure
```
CourseRegistration/
├── include/
│   ├── Course.h
│   ├── User.h
│   ├── Student.h
│   └── Enrollment.h
│
├── src/
│   ├── main.cpp
│   ├── Auth.cpp
│   ├── CourseManager.cpp
│   ├── EnrollmentManager.cpp
│   ├── SlipGenerator.cpp
│   └── AdminReport.cpp
│
├── data/
│   ├── students.csv
│   ├── courses.csv
│   ├── enrollments.csv
│   ├── slips/
│   │   └── [Student_ID]_enrollment_slip.txt
│   └── reports/
│       └── admin_report.txt
│
└── build/
    └── app.exe
```

---

## ⚙️ Setup Instructions

### 1️⃣ Prerequisites
- Install **MinGW** or any C++ compiler supporting C++17.
- Add compiler path to system environment variables.
- Install **VS Code** (recommended) with the C++ extension.

### 2️⃣ Clone the Repository
```bash
git clone https://github.com/<your-username>/CourseRegistrationPortal.git
cd CourseRegistrationPortal
```

### 3️⃣ Create Folder Structure
Ensure these directories exist:
```
data/
├── students.csv
├── courses.csv
├── enrollments.csv
├── slips/
└── reports/
```

### 4️⃣ Initialize CSV Files
Create these empty files (with headers):
```csv
# students.csv
id,name,email,password

# courses.csv
course_id,title,credits,faculty,seats

# enrollments.csv
enroll_id,student_id,course_id,timestamp
```

### 5️⃣ Build & Run
```bash
g++ -std=c++17 src\*.cpp -Iinclude -o build\app.exe
build\app.exe
```

---

## 🖥️ Application Flow

### Main Menu
```
=== Course Registration Portal ===
1. Student Registration
2. Student Login
3. Faculty/Admin Panel
4. Exit
```

### Student Panel
```
=== Student Panel ===
1. View All Courses
2. Enroll in a Course
3. Drop a Course
4. View My Enrollments
5. Generate Enrollment Slip
6. Logout
```

### Faculty / Admin Panel
```
=== Faculty / Admin Panel ===
1. Add Course
2. View All Courses
3. View System Report
4. Save System Report to File
5. Back to Main Menu
```

---

## 📟 Sample Outputs

**Student Registration**
```
--- Student Registration ---
Name: Dev
Email: dev123@gmail.com
Password: 1234
✅ Registration successful! Your ID is: S1000
```

**Student Login**
```
--- Student Login ---
Email: dev123@gmail.com
Password: 1234
✅ Login successful! Welcome, Dev
```

**Generate Enrollment Slip**
```
🧾 Enrollment slip generated: data/slips/S1000_enrollment_slip.txt
```

**Admin Report Example**
```
=== System Report ===
Total Registered Students : 5
Total Courses Offered     : 3
Total Enrollments         : 8

--- Enrollment per Course ---
Course ID C101 → 4 students
Course ID C102 → 3 students
Course ID C103 → 1 students
---------------------------------------
🧾 Admin report saved at: data/reports/admin_report.txt
```

---

## 📝 Key Concepts Used

| Concept | Description |
|----------|--------------|
| **Classes & Objects** | Modeled entities like Student, Course, Enrollment |
| **Inheritance** | Student inherits from User |
| **File Handling** | Data persistence using CSV files |
| **Encapsulation** | Private data members with public methods |
| **Modular Design** | Code divided into multiple source and header files |

---

## 👨‍💻 Author
**Dev Verma**  
💼 [LinkedIn](https://www.linkedin.com/in/vermadev13/) | 🐙 [GitHub](https://github.com/vermadev1311/)

---

## 🗪 License
This project is licensed under the **MIT License** — you’re free to use, modify, and distribute with attribution.

```
MIT License © 2025 Dev Verma
```

---

## 🎯 Future Improvements
- Add password encryption  
- Integrate with SQLite / MySQL for better data management  
- GUI version using Qt or wxWidgets  
- PDF generation for slips & reports  

---

## 🏁 Conclusion
This project was developed as part of a **C++ training program**, showcasing the practical implementation of OOP, file handling, and modular C++ application design.

> 💡 *"Learning by building real-world applications is the best way to master programming!"*