/*Design a student management system using Java 
packages. The system should manage information 
about students, courses, and their enrolments. You will 
organize the functionality across multiple packages and 
use object-oriented principles such as encapsulation */
import java.util.Scanner;

import enrollment.Enrollment;

class Aditya_Package {
    public static void main(String arg[]) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter Student ID: ");
        int StudentID = sc.nextInt();
        sc.nextLine();
        System.out.print("Enter Student Name: ");
        String name = sc.nextLine();
        System.out.print("Enter Student Age: ");
        int age = sc.nextInt();
        sc.nextLine();
        System.out.print("Enter Course ID: ");
        String CourseID = sc.nextLine();
        System.out.print("Enter Course Name: ");
        String CourseName = sc.nextLine();
        System.out.print("Enter Course Credits: ");
        int Credits = sc.nextInt();

        Enrollment e1 = new Enrollment(StudentID, name, age, CourseID, CourseName, Credits);

        System.out.println("\n\n" + e1.getEnrollmentInfo());

        sc.close();
    }
}

