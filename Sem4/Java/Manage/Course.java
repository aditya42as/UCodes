package course;
import java.util.*;
public class Course {
    String CourseID;
    String CourseName;
    int Credits;
    public Course(String CourseID, String CourseName, int Credits) {
        this.CourseID = CourseID;
        this.CourseName = CourseName;
        this.Credits = Credits;
    }
    public String getCourseInfo() {
        String str = "\nCourse ID: " + CourseID + "\nCourse Name: " + CourseName + "\nCredits: " + Credits;
        return str;
    }

}
