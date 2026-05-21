package enrollment;
import java.util.*;
import student.Student;
import course.Course;

public class Enrollment {
    Student s1;
    Course c1;
    public Enrollment(int StudentID, String name, int age, String CourseID, String CourseName, int Credits) {
        s1 = new Student(StudentID, name, age);
        c1 = new Course(CourseID, CourseName, Credits);
    }
    public String getEnrollmentInfo() {
        String str = s1.getStudentInfo() + c1.getCourseInfo();
        return str;
    }
}
