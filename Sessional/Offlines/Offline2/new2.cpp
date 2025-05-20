#include <iostream>
#include <string>
using namespace std;

// Forward declaration of Student class for global variables
class Student;

// Global variables
Student* students[100]; // Assuming maximum 100 students
int totalStudents = 0;

class Course {
private:
    string name;
    float creditHour;

public:
    // Constructors
    Course() : name(""), creditHour(0.0f) {}
    Course(string name, float creditHour) : name(name), creditHour(creditHour) {}

    // Member functions
    string getName() { return name; }
    float getCreditHour() { return creditHour; }
    void setName(string name) { this->name = name; }
    void setCreditHour(float creditHour) { this->creditHour = creditHour; }
    void display() {
        cout << "Course Name: " << name << ", Credit Hour: " << creditHour;
    }
};

class Student {
private:
    string name;
    int id;
    Course* courses;
    int totalCourses;
    int maxCourses;
    float* gradePoints;

public:
    // Constructors and destructor
    Student() : name(""), id(0), courses(nullptr), totalCourses(0), maxCourses(0), gradePoints(nullptr) {}
    
    Student(string name, int id, int maxCourses) : 
        name(name), id(id), maxCourses(maxCourses), totalCourses(0) {
        courses = new Course[maxCourses];
        gradePoints = new float[maxCourses](); // Initialize to 0
    }
    
    // Copy constructor
    Student(const Student& other) {
        name = other.name;
        id = other.id;
        maxCourses = other.maxCourses;
        totalCourses = other.totalCourses;
        
        courses = new Course[maxCourses];
        gradePoints = new float[maxCourses];
        
        for (int i = 0; i < totalCourses; i++) {
            courses[i] = other.courses[i];
            gradePoints[i] = other.gradePoints[i];
        }
    }
    
    // Destructor
    ~Student() {
        delete[] courses;
        delete[] gradePoints;
    }

    // Member functions
    void setName(string name) { this->name = name; }
    void setId(int id) { this->id = id; }
    void setInfo(string name, int id) { this->name = name; this->id = id; }
    
    void addCourse(Course c) {
        if (totalCourses >= maxCourses) {
            cout << "Cannot add more courses to " << name << endl;
            return;
        }
        courses[totalCourses] = c;
        gradePoints[totalCourses] = 0.0f;
        totalCourses++;
    }
    
    void addCourse(Course c, float gradePoint) {
        if (totalCourses >= maxCourses) {
            cout << "Cannot add more courses to " << name << endl;
            return;
        }
        courses[totalCourses] = c;
        gradePoints[totalCourses] = gradePoint;
        totalCourses++;
    }
    
    void setGradePoint(Course c, float gradePoint) {
        for (int i = 0; i < totalCourses; i++) {
            if (courses[i].getName() == c.getName()) {
                gradePoints[i] = gradePoint;
                return;
            }
        }
    }
    
    void setGradePoint(float* gradePoints, int n) {
        for (int i = 0; i < n && i < totalCourses; i++) {
            this->gradePoints[i] = gradePoints[i];
        }
    }
    
    string getName() { return name; }
    
    float getCGPA() {
        float totalPoints = 0.0f;
        float totalCredits = 0.0f;
        
        for (int i = 0; i < totalCourses; i++) {
            // Only count courses where gradePoint >= 2.0
            if (gradePoints[i] >= 2.0) {
                totalPoints += gradePoints[i] * courses[i].getCreditHour();
                totalCredits += courses[i].getCreditHour();
            }
        }
        
        if (totalCredits == 0) return 0.0f;
        return totalPoints / totalCredits;
    }
    
    float getGradePoint(Course c) {
        for (int i = 0; i < totalCourses; i++) {
            if (courses[i].getName() == c.getName()) {
                return gradePoints[i];
            }
        }
        return 0.0f;
    }
    
    int getTotalCourses() { return totalCourses; }
    
    float getTotalCreditHours() {
        float totalCredits = 0.0f;
        for (int i = 0; i < totalCourses; i++) {
            if (gradePoints[i] >= 2.0) {
                totalCredits += courses[i].getCreditHour();
            }
        }
        return totalCredits;
    }
    
    Course getMostFavoriteCourse() {
        if (totalCourses == 0) return Course();
        
        int favoriteIndex = 0;
        for (int i = 1; i < totalCourses; i++) {
            if (gradePoints[i] > gradePoints[favoriteIndex]) {
                favoriteIndex = i;
            }
        }
        return courses[favoriteIndex];
    }
    
    Course getLeastFavoriteCourse() {
        if (totalCourses == 0) return Course();
        
        int leastIndex = 0;
        for (int i = 1; i < totalCourses; i++) {
            if (gradePoints[i] < gradePoints[leastIndex]) {
                leastIndex = i;
            }
        }
        return courses[leastIndex];
    }
    
    Course* getFailedCourses(int& count) {
        count = 0;
        for (int i = 0; i < totalCourses; i++) {
            if (gradePoints[i] < 2.0) {
                count++;
            }
        }
        
        Course* failed = new Course[count];
        int index = 0;
        for (int i = 0; i < totalCourses; i++) {
            if (gradePoints[i] < 2.0) {
                failed[index++] = courses[i];
            }
        }
        return failed;
    }
    
    void display() {
        cout << "============================" << endl;
        cout << "Student Name: " << name << ", ID: " << id << endl;
        for (int i = 0; i < totalCourses; i++) {
            cout << "Course Name: " << courses[i].getName() 
                 << ", Credit Hour: " << courses[i].getCreditHour() 
                 << ", gradePoint: " << gradePoints[i] << endl;
        }
        cout << "CGPA: " << getCGPA() << endl;
        cout << "Total Credit Hours Earned: " << getTotalCreditHours() << endl;
        cout << "Most Favorite Course: " << getMostFavoriteCourse().getName() << endl;
        cout << "Least Favorite Course: " << getLeastFavoriteCourse().getName() << endl;
        cout << "============================" << endl;
    }
};

// Global functions
Student getTopper() {
    if (totalStudents == 0) return Student();
    
    Student* topper = students[0];
    for (int i = 1; i < totalStudents; i++) {
        if (students[i]->getCGPA() > topper->getCGPA()) {
            topper = students[i];
        }
    }
    return *topper;
}

Student getTopper(Course c) {
    Student* topper = nullptr;
    float highestGrade = -1.0f;
    
    for (int i = 0; i < totalStudents; i++) {
        float currentGrade = students[i]->getGradePoint(c);
        if (currentGrade > highestGrade) {
            highestGrade = currentGrade;
            topper = students[i];
        }
    }
    
    if (topper == nullptr) return Student();
    return *topper;
}

// Sample main function (provided in the assignment)
int main() {
    // generate courses
    const int COURSE_COUNT = 6;
    Course courses[COURSE_COUNT] = {
        Course("CSE107", 3),
        Course("CSE105", 3),
        Course("CSE108", 1.5),
        Course("CSE106", 1.5),
        Course("EEE164", 0.75),
        Course("ME174", 0.75),
    };

    float gradePoints[COURSE_COUNT] = {4.0, 4.0, 3.5, 3.5, 4.0, 3.25};

    // generate students
    Student s1 = Student("Sheldon", 1, 5);
    students[totalStudents++] = &s1;

    // add courses to s1
    s1.addCourse(courses[0]);
    s1.addCourse(courses[1]);
    s1.addCourse(courses[2]);
    s1.addCourse(courses[3]);
    s1.addCourse(courses[4]);
    s1.addCourse(courses[5]);
    s1.setGradePoint(gradePoints, s1.getTotalCourses());
    s1.display();

    Student s2 = Student("Penny", 2, 5);
    students[totalStudents++] = &s2;
    s2.addCourse(courses[0]);
    s2.addCourse(courses[2]);
    s2.addCourse(courses[5]);
    s2.setGradePoint(gradePoints, s2.getTotalCourses());
    s2.setGradePoint(courses[0], 3.25);
    s2.display();

    Student s3 = s2;
    students[totalStudents++] = &s3;
    s3.setName("Leonard");
    s3.setId(3);
    s3.setGradePoint(gradePoints, s3.getTotalCourses());
    s3.addCourse(courses[1], 3.75);
    s3.display();

    Student s4 = s3;
    students[totalStudents++] = &s4;
    s4.setInfo("Howard", 4);
    s4.setGradePoint(gradePoints, s4.getTotalCourses());
    s4.addCourse(courses[3], 3.75);
    s4.display();

    Student s5 = s4;
    students[totalStudents++] = &s5;
    s5.setInfo("Raj", 5);
    s5.setGradePoint(gradePoints, s5.getTotalCourses());
    s5.setGradePoint(courses[0], 1.5);
    s5.setGradePoint(courses[2], 2.0);
    s5.setGradePoint(courses[5], 1.75);
    s5.setGradePoint(courses[3], 3.75);
    s5.display();

    int failedCount;
    Course* failedCourses = s5.getFailedCourses(failedCount);
    cout << "Failed Courses for " << s5.getName() << ":" << endl;
    for (int i = 0; i < failedCount; ++i) {
        failedCourses[i].display();
        cout << endl;
    }
    delete[] failedCourses;

    cout << "================" << endl;
    Student topper = getTopper();
    cout << "Topper: " << topper.getName() << endl;
    cout << "Topper CGPA: " << topper.getCGPA() << endl;
    cout << "================" << endl;

    for (int i = 0; i < COURSE_COUNT; ++i) {
        Course c = courses[i];
        Student topperInCourse = getTopper(c);
        cout << "Topper in " << c.getName() << ":" << topperInCourse.getName() << endl;
        cout << "Topper in " << c.getName() << " gradePoint: " << topperInCourse.getGradePoint(c) << endl;
        cout << "================" << endl;
    }

    return 0;
}