import java.util.Scanner;

public class original {
}



import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Parse command line arguments
        System.out.println("Parsing command line arguments...");
        if (args.length < 2) {
            System.out.println("Error: Please provide number of students and courses as command-line arguments.");
            System.out.println("Example: java Main 3 3");
            scanner.close();
            return;
        }
        int numStudents = Integer.parseInt(args[0]);
        int numCourses = Integer.parseInt(args[1]);
        System.out.println("Number of students: " + numStudents);
        System.out.println("Number of courses: " + numCourses);
        System.out.println("---");

        // Input courses
        Course[] courses = new Course[numCourses];
        for (int i = 0; i < numCourses; i++) {
            System.out.println("\nCourse " + (i + 1));
            System.out.print("Enter course name: ");
            String courseName = scanner.nextLine();
            System.out.print("Enter course credit: ");
            double credit = scanner.nextDouble();
            scanner.nextLine(); // Consume newline
            courses[i] = new Course(courseName, credit);
        }
        System.out.println("---");

        // Input students
        Student[] students = new Student[numStudents];
        for (int i = 0; i < numStudents; i++) {
            System.out.println("\nEnter name of student " + (i + 1) + ": ");
            String name = scanner.nextLine();
            students[i] = new Student(name, numCourses, courses);

            for (int j = 0; j < numCourses; j++) {
                double mark;
                do {
                    System.out.print("Enter marks for " + courses[j].getName() + ": ");
                    mark = scanner.nextDouble();
                    if (mark < 0 || mark > 100) {
                        System.out.println("Marks must be between 0 and 100. Try again.");
                    }
                } while (mark < 0 || mark > 100);
                students[i].setMark(j, mark);
            }
            scanner.nextLine(); // Consume newline
        }
        System.out.println("---");

        // Process commands
        while (true) {
            System.out.println("\nEnter command: ");
            String command = scanner.nextLine().trim();
            String[] parts = command.split("\\s+");

            if (parts[0].equals("exit")) {
                System.out.println("\nTerminating...");
                break;
            } else if (parts[0].equals("display")) {
                if (parts.length < 2) {
                    System.out.println("Usage: display [all|student_name]");
                } else if (parts[1].equals("all")) {
                    for (Student student : students) {
                        if (student != null) {
                            student.displayDetails();
                        }
                    }
                } else {
                    boolean found = false;
                    for (Student student : students) {
                        if (student != null && student.getName().equals(parts[1])) {
                            student.displayDetails();
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        System.out.println("\nStudent " + parts[1] + " does not exist.");
                    }
                }
            } else if (parts[0].equals("delete")) {
                if (parts.length < 2) {
                    System.out.println("Usage: delete student_name");
                    continue;
                }
                int newSize = 0;
                for (Student student : students) {
                    if (student != null && !student.getName().equals(parts[1])) {
                        newSize++;
                    }
                }

                Student[] newStudents = new Student[newSize];
                int index = 0;
                for (Student student : students) {
                    if (student != null && !student.getName().equals(parts[1])) {
                        newStudents[index++] = student;
                    }
                }
                students = newStudents;
                System.out.println("\nSuccess, student " + parts[1] + " deleted.");
            }
        }
        scanner.close();
    }
}