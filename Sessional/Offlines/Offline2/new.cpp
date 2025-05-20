#include <iostream>
#include <cstring>
using namespace std;

class Course
{
private:
    string name;
    float creditHour;

public:
    Course() : name("NA"), creditHour(0) {}
    Course(string name, float creditHour) : name(name), creditHour(creditHour) {}

    string getName() const { return name; }
    float getCreditHour() const { return creditHour; }
    void setName(string name) { this->name = name; }
    void setCreditHour(float creditHour) { this->creditHour = creditHour; }
    void display() const
    {
        cout << "Course Name: " << name << ", Credit Hour: " << creditHour << endl;
    }
};

class Student
{
private:
    string name;
    int id;
    Course *courses;
    int totalCourses;
    int maxCourses;
    float *gradePoint;
    static int totalStudents;
    static const int MAX_STUDENTS = 100;
    static Student* students[MAX_STUDENTS];

public:
    Student() : name("NA"), id(0), courses(nullptr), totalCourses(0), 
                maxCourses(0), gradePoint(nullptr)
    {
        if (totalStudents < MAX_STUDENTS) {
            students[totalStudents++] = this;
        }
    }

    Student(string name, int id, int maxCourses) : 
        name(name), id(id), maxCourses(maxCourses), totalCourses(0)
    {
        this->courses = new Course[maxCourses];
        this->gradePoint = new float[maxCourses];
        if (totalStudents < MAX_STUDENTS) {
            students[totalStudents++] = this;
        }
    }

    // copy constructor
    Student(const Student &other) : 
        name(other.name), id(other.id), totalCourses(other.totalCourses),
        maxCourses(other.maxCourses)
    {
        this->courses = new Course[maxCourses];
        for (int i = 0; i < totalCourses; ++i) {
            courses[i] = other.courses[i];
        }
        this->gradePoint = new float[maxCourses];
        for (int i = 0; i < totalCourses; ++i) {
            gradePoint[i] = other.gradePoint[i];
        }
        if (totalStudents < MAX_STUDENTS) {
            students[totalStudents++] = this;
        }
    }

    // destructor
    ~Student()
    {
        delete[] courses;
        delete[] gradePoint;
    }

    // Assignment operator
    Student& operator=(const Student& other) {
        if (this != &other) {
            delete[] courses;
            delete[] gradePoint;
            
            name = other.name;
            id = other.id;
            totalCourses = other.totalCourses;
            maxCourses = other.maxCourses;
            
            courses = new Course[maxCourses];
            gradePoint = new float[maxCourses];
            
            for (int i = 0; i < totalCourses; ++i) {
                courses[i] = other.courses[i];
                gradePoint[i] = other.gradePoint[i];
            }
        }
        return *this;
    }

    // Member functions
    void setName(string name) { this->name = name; }
    void setId(int id) { this->id = id; }
    void setInfo(string name, int id) {
        this->name = name;
        this->id = id;
    }

    void addCourse(Course c) {
        if (totalCourses < maxCourses) {
            courses[totalCourses] = c;
            totalCourses++;
        }
    }

    void addCourse(Course course, float gradePoint) {
        if (totalCourses < maxCourses && gradePoint >= 0.0 && gradePoint <= 4.0) {
            this->courses[totalCourses] = course;
            this->gradePoint[totalCourses] = gradePoint;
            totalCourses++;
        }
    }

    void setGradePoint(Course c, float gradePoint) {
        if (gradePoint < 0.0 || gradePoint > 4.0) return;
        
        for (int i = 0; i < totalCourses; ++i) {
            if (c.getName() == courses[i].getName()) {
                this->gradePoint[i] = gradePoint;
                break;
            }
        }
    }

    void setGradePoint(float *gradePoints, int n) {
        for (int i = 0; i < n && i < totalCourses; ++i) {
            if (gradePoints[i] >= 0.0 && gradePoints[i] <= 4.0) {
                this->gradePoint[i] = gradePoints[i];
            }
        }
    }

    string getName() const { return name; }
    int getId() const { return id; }

    float getCGPA() const {
        float totalPoints = 0;
        float totalCrHr = 0;
        
        for (int i = 0; i < totalCourses; ++i) {
            if (gradePoint[i] >= 2) {
                totalPoints += gradePoint[i] * courses[i].getCreditHour();
                totalCrHr += courses[i].getCreditHour();
            }
        }
        
        return (totalCrHr > 0) ? totalPoints / totalCrHr : 0;
    }

    float getGradePoint(Course c) const {
        for (int i = 0; i < totalCourses; ++i) {
            if (c.getName() == courses[i].getName()) {
                return gradePoint[i];
            }
        }
        return -1;
    }

    int getTotalCourses() const { return totalCourses; }

    float getTotalCreditHours() const {
        float totalCrHr = 0;
        for (int i = 0; i < totalCourses; ++i) {
            if (gradePoint[i] >= 2) {
                totalCrHr += courses[i].getCreditHour();
            }
        }
        return totalCrHr;
    }

    Course getMostFavoriteCourse() const {
        if (totalCourses == 0) return Course();
        
        Course temp = courses[0];
        float maxGrade = gradePoint[0];
        
        for (int i = 1; i < totalCourses; ++i) {
            if (gradePoint[i] > maxGrade) {
                maxGrade = gradePoint[i];
                temp = courses[i];
            }
        }
        return temp;
    }

    Course getLeastFavoriteCourse() const {
        if (totalCourses == 0) return Course();
        
        Course temp = courses[0];
        float minGrade = gradePoint[0];
        
        for (int i = 1; i < totalCourses; ++i) {
            if (gradePoint[i] < minGrade) {
                minGrade = gradePoint[i];
                temp = courses[i];
            }
        }
        return temp;
    }

    Course* getFailedCourses(int &count) const {
        Course* temp = new Course[totalCourses];
        count = 0;
        
        for (int i = 0; i < totalCourses; ++i) {
            if (gradePoint[i] < 2) {
                temp[count++] = courses[i];
            }
        }
        return temp;
    }

    void display() const {
        cout << "Student Name: " << name << ", ID: " << id << endl;
        for (int i = 0; i < totalCourses; ++i) {
            cout << "Course Name: " << courses[i].getName() 
                 << ", Credit Hour: " << courses[i].getCreditHour() 
                 << ", Grade Point: " << gradePoint[i] << endl;
        }
    }

    static Student getTopper() {
        if (totalStudents == 0) return Student();
        
        Student* topStudent = students[0];
        float maxCGPA = students[0]->getCGPA();
        
        for (int i = 1; i < totalStudents; ++i) {
            float currentCGPA = students[i]->getCGPA();
            if (currentCGPA > maxCGPA) {
                maxCGPA = currentCGPA;
                topStudent = students[i];
            }
        }
        
        return *topStudent;
    }

    static Student getTopper(Course c) {
        if (totalStudents == 0) return Student();
        
        Student* topStudent = nullptr;
        float maxGrade = -1;
        
        for (int i = 0; i < totalStudents; ++i) {
            float currentGrade = students[i]->getGradePoint(c);
            if (currentGrade > maxGrade) {
                maxGrade = currentGrade;
                topStudent = students[i];
            }
        }
        
        return (topStudent != nullptr) ? *topStudent : *students[0];
    }

    static int getTotalStudents() { return totalStudents; }
};

// Initialize static members
int Student::totalStudents = 0;
Student* Student::students[Student::MAX_STUDENTS];

int main()
{
    // Generate courses
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

    // Create and initialize students
    Student s1("Sheldon", 1, 5);
    for (int i = 0; i < COURSE_COUNT && i < 5; ++i) {
        s1.addCourse(courses[i], gradePoints[i]);
    }
    s1.display();

    Student s2("Penny", 2, 5);
    s2.addCourse(courses[0], 3.25);
    s2.addCourse(courses[2], 3.5);
    s2.addCourse(courses[5], 3.25);
    s2.display();

    Student s3 = s2;
    s3.setName("Leonard");
    s3.setId(3);
    s3.addCourse(courses[1], 3.75);
    s3.display();

    Student s4 = s3;
    s4.setInfo("Howard", 4);
    s4.addCourse(courses[3], 3.75);
    s4.display();

    Student s5 = s4;
    s5.setInfo("Raj", 5);
    s5.setGradePoint(courses[0], 1.5);
    s5.setGradePoint(courses[2], 2.0);
    s5.setGradePoint(courses[5], 1.75);
    s5.setGradePoint(courses[3], 3.75);
    s5.display();

    // Display failed courses
    int failedCount;
    Course* failedCourses = s5.getFailedCourses(failedCount);
    cout << "Failed Courses for " << s5.getName() << ":" << endl;
    for (int i = 0; i < failedCount; ++i) {
        failedCourses[i].display();
    }
    delete[] failedCourses;

    cout << "==================================" << endl;
    Student topper = Student::getTopper();
    cout << "Topper: " << topper.getName() << endl;
    cout << "Topper CGPA: " << topper.getCGPA() << endl;
    cout << "==================================" << endl;

    for (int i = 0; i < COURSE_COUNT; ++i) {
        Course c = courses[i];
        Student topperInCourse = Student::getTopper(c);
        cout << "Topper in " << c.getName() << ": " << topperInCourse.getName() << endl;
        cout << "Topper in " << c.getName() << " gradePoint: " 
             << topperInCourse.getGradePoint(c) << endl;
        cout << "==================================" << endl;
    }

    return 0;
}