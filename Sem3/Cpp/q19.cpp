/*Create a class called Student that contains the data members like age, name, enroll_no, marks. Create another class called Faculty that contains data members like facultyName, facultyCode, salary,deptt, age, experience, gender. Create the function display() in both the classes to display the respective information. The derived Class Person demonstrates multiple inheritance. The program should be able to call both the base classes and displays their information. Remove the ambiguity (When we have exactly same variables or same methods in both the base classes, which one will be called?) by proper mechanism.*/

#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int age;
    int enroll_no;
    float marks;

public:
    void setStudent(const string &name, int age, int enroll_no, float marks) { 
        this->name = name;
        this->age = age;
        this->enroll_no = enroll_no;
        this->marks = marks;
    }

    void display() const {
        cout << "---- Student Details ----" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Enrollment No: " << enroll_no << endl;
        cout << "Marks: " << marks << endl;
    }
};

class Faculty {
private:
    string facultyName;
    string facultyCode;
    float salary;
    string deptt;
    int age;
    int experience;
    char gender;

public:
    void setFaculty(const string &facultyName, const string &facultyCode, float salary,
                    const string &deptt, int age, int experience, char gender) { 
        this->facultyName = facultyName; 
        this->facultyCode = facultyCode;
        this->salary = salary;
        this->deptt = deptt;
        this->age = age;
        this->experience = experience;
        this->gender = gender;
    }

    void display() const {
        cout << "\n---- Faculty Details ----" << endl;
        cout << "Name: " << facultyName << endl;
        cout << "Code: " << facultyCode << endl;
        cout << "Department: " << deptt << endl;
        cout << "Age: " << age << endl;
        cout << "Experience: " << experience << " years" << endl;
        cout << "Gender: " << gender << endl;
        cout << "Salary: " << salary << endl;
    }
};

class Person : public Student, public Faculty {
public:
    void show() const {
        Student::display();
        Faculty::display();
    }
};

int main() {
    Person p;
    p.setStudent("Rahul", 20, 1023, 88.5);
    p.setFaculty("Dr. Sharma", "F102", 85000.0, "Computer Science", 45, 20, 'M');
    p.show();

}
