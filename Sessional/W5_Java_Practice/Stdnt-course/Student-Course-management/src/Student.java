public class Student {
    private String name;
    private double[] marks;
    private Course[] courses;

    public Student(String name, int numCourses, Course[] courses) {
        this.name = name;
        this.marks = new double[numCourses];
        this.courses = courses;
    }


    public Student(String name, double[] marks, Course[] courses) {
        this.name = name;
        this.marks = marks;
        this.courses = courses;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public double[] getMarks() {
        return marks;
    }

    public void setMarks(double[] marks) {
        this.marks = marks;
    }

    public Course[] getCourses() {
        return courses;
    }

    public void setCourses(Course[] courses) {
        this.courses = courses;
    }

    public void setMark(int index, double mark) {
        this.marks[index] = mark;
    }

    private double getGrade(double mark) {
        if (mark >= 80) return 4.00;
        if (mark >= 70) return 3.75;
        if (mark >= 60) return 3.50;
        if (mark >= 50) return 3.00;
        if (mark >= 40) return 2.00;
        return 0.00;
    }

    public double calculateGPA() {
        double totalPoints = 0.0;
        double totalCredits = 0.0;

        for (int i = 0; i < marks.length; i++) {
            totalPoints += getGrade(marks[i]) * courses[i].getCredit();
            totalCredits += courses[i].getCredit();
        }

        return totalCredits > 0 ? Math.round((totalPoints / totalCredits) * 100.0) / 100.0 : 0.0;
    }

    public void displayDetails() {
        System.out.println("\nGrades for " + name + ":");
        for (int i = 0; i < marks.length; i++) {
            System.out.printf("- Course: %s, Grade: %.2f\n",
                    courses[i].getName(), getGrade(marks[i]));
        }
        System.out.printf("- CGPA: %.2f\n", calculateGPA());
    }


}
