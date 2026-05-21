package student;
import java.util.*;

public class Student {
    int StudentID;
    String name;
    int age;

    public Student(int StudentID, String name, int age) {
        this.StudentID = StudentID;
        this.name = name;
        this.age = age;
    }
    public String getStudentInfo() {
        String str = "ID: " + StudentID + "\nName: " + name + "\nAge: " + age;
        return str;
    }
    
}
