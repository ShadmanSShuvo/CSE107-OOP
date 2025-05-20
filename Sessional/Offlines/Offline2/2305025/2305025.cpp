#include <iostream>
#include <cstring>
using namespace std;

class Student;

static int totalStudents = 0;
Student *students[100];


class Course
{
private:
    string name;
    float creditHour;

public:
    Course()
    {
        name = "NA";
        creditHour = 0;
    }
    Course(string name, float creditHour)
    {
        this->name = name;
        this->creditHour = creditHour;
    }

    string getName() { return name; }
    float getCreditHour() { return creditHour; }
    void setName(string name) { this->name = name; }
    void setCreditHour(float creditHour) { this->creditHour = creditHour; }
    void display()
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

public:
    Student()
    {
        name = "NA";
        id = 0;
        courses = nullptr;
        totalCourses = 0;
        maxCourses = 0;
        gradePoint = nullptr;

    }

    Student(string name, int id, int maxCourses)
    {
        this->name = name;
        this->id = id;
        this->maxCourses = maxCourses;
        this->totalCourses = 0;
        this->courses = new Course[maxCourses];
        this->gradePoint = new float[maxCourses];

    }

    // copy constructor
    Student(const Student &other)
    {
        this->name = other.name;
        this->id = other.id;
        this->totalCourses = other.totalCourses;
        this->maxCourses = other.maxCourses;
        this->courses = new Course[maxCourses];
        for (int i = 0; i < totalCourses; ++i)
        {
            courses[i] = other.courses[i];
        }
        this->gradePoint = new float[maxCourses];
        for (int i = 0; i < totalCourses; ++i)
        {
            gradePoint[i] = other.gradePoint[i];
        }

    }

   

    // destructor
    ~Student()
    {
        delete[] courses;
        delete[] gradePoint;
    }

    // Functions
    void setName(string name) { this->name = name; }
    void setId(int id) { this->id = id; }
    void setInfo(string name, int id)
    {
        this->name = name;
        this->id = id;
    }
    void addCourse(Course c)
    {
        if (totalCourses < maxCourses)
        {
            courses[totalCourses] = c;
            totalCourses++;
        }
        else
        {
            cout << "Cannot add more courses to " << this->name << endl;
            return;
        }
    }

    void addCourse(Course course, float gradePoint)
    {
        if (totalCourses < maxCourses)
        {
            this->courses[totalCourses] = course;
            this->gradePoint[totalCourses] = gradePoint;
            totalCourses++;
        }
        else
        {
            cout << "Cannot add more courses to " << endl;
            return;
        }
    }

    void setGradePoint(Course c, float gradePoint)
    {
        for (int i = 0; i < totalCourses; ++i)
        {
            if (c.getName() == courses[i].getName())
            {
                this->gradePoint[i] = gradePoint;
                break;
            }
        }
    }
    void setGradePoint(float *gradePoints, int n)
    {
        for (int i = 0; i < n; ++i)
        {
            this->gradePoint[i] = gradePoints[i];
        }
    }

    string getName()
    {
        return name;
    }
    float getCGPA()
    {
        float cgpa = 0;

        for (int i = 0; i < totalCourses; ++i)
        {
            if (gradePoint[i] >= 2)
            {
                cgpa += gradePoint[i] * courses[i].getCreditHour();
            }
        }
        float totalCrHr = this->getTotalCreditHours();
        return cgpa / totalCrHr;
    }
    float getGradePoint(Course c)
    {
        for (int i = 0; i < totalCourses; ++i)
        {
            if (c.getName() == courses[i].getName())
            {
                return this->gradePoint[i];
            }
        }
        return -1;
    }

    int getTotalCourses()
    {
        return totalCourses;
    }
    float getTotalCreditHours()
    {
        float totalCrHr = 0;
        for (int i = 0; i < totalCourses; ++i)
        {
            // totalCrHr += courses[i].getCreditHour();
            if (gradePoint[i] >= 2)
            {
                totalCrHr += courses[i].getCreditHour();
            }
        }
        return totalCrHr;
    }
    Course getMostFavoriteCourse()
    {
        Course temp = courses[0];
        float maxGP = gradePoint[0];
        for (int i = 1; i < totalCourses; ++i)
        {
            if (gradePoint[i] > maxGP)
            {
                maxGP = gradePoint[i];
                temp = courses[i];
            }
        }
        return temp;
    }
    Course getLeastFavoriteCourse()
    {
        Course temp = courses[0];
        float minGP = gradePoint[0];
        for (int i = 1; i < totalCourses; ++i)
        {
            if (gradePoint[i] < minGP)
            {
                minGP = gradePoint[i];
                temp = courses[i];
            }
        }
        return temp;
    }
    Course *getFailedCourses(int &count)
    {
        int cnt = 0;
        for (int i = 0; i < totalCourses; i++)
        {
            if (gradePoint[i] < 2)
            {
                cnt++;
            }
        }

        if (cnt == 0)
        {
            count = 0;
            return nullptr;
        }

        Course *temp = new Course[cnt];
        int indx = 0;
        for (int i = 0; i < totalCourses; ++i)
        {
            if (gradePoint[i] < 2)
            {
                temp[indx++] = courses[i];
            }
        }

        count = cnt;
        return temp;
    }
    void display()
    {
        cout << "==================================" << endl;
        cout << "Student Name: " << this->name << ", ID: " << this->id << endl;
        for (int i = 0; i < totalCourses; ++i)
        {
            cout << "Course Name: " << courses[i].getName() << ", Credit Hour: " << courses[i].getCreditHour() << ", gradePoint: " << gradePoint[i] << endl;
        }
        cout << "CGPA: " << getCGPA() << endl;
        cout << "Total Credit Hours Earned: " << getTotalCreditHours() << endl;
        cout << "Most Favorite Course: " << getMostFavoriteCourse().getName() << endl;
        cout << "Least Favorite Course: " << getLeastFavoriteCourse().getName() << endl;
        cout << "==================================" << endl;
    }
};

Student getTopper()
{
    if (totalStudents == 0)
        return Student();
    Student *temp = students[0];
    
    for (int i = 0; i < totalStudents; ++i)
    {
        if (students[i]->getCGPA() > temp->getCGPA())
        {
            temp = students[i];
        }
    }

    return *temp;
}

Student getTopper(Course c)
{
    Student *temp = nullptr;
    float highCG = -1.0;
    for (int i = 0; i < totalStudents; ++i)
    {
        if (students[i]->getGradePoint(c) > highCG)
        {
            highCG = students[i]->getGradePoint(c);
            temp = students[i];
        }
    }
    if (temp == nullptr)
        return Student();
    return *temp;
}

int main()
{
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
    Course *failedCourses = s5.getFailedCourses(failedCount);
    cout << "Failed Courses for " << s5.getName() << ":" << endl;
    for (int i = 0; i < failedCount; ++i)
    {
        failedCourses[i].display();
        //cout << endl;
    }
    delete[] failedCourses;
    cout << "==================================" << endl;
    Student topper = getTopper();
    cout << "Topper: " << topper.getName() << endl;
    cout << "Topper CGPA: " << topper.getCGPA() << endl;
    cout << "==================================" << endl;
    for (int i = 0; i < COURSE_COUNT; ++i)
    {

        Course c = courses[i];
        Student topperInCourse = getTopper(c);
        cout << "Topper in " << c.getName() << ": " << topperInCourse.getName() << endl;
        cout << "Topper in " << c.getName() << " gradePoint: " <<

            topperInCourse.getGradePoint(c) << endl;
        cout << "==================================" << endl;
    }
    return 0;
}