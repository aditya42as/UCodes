/*Implement a real case scenario by a proper C++ code to 
provide the solution to Diamond Problem in C++. */
#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    void setPersonInfo(const string &name, int age) {
        this->name = name;
        this->age = age;
    }
    void showPerson() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Employee : virtual public Person {
protected:
    string company;
    float salary;
public:
    void setEmployeeInfo(const string &company, float salary) {
        this->company = company;
        this->salary = salary;
    }
    void showEmployee() const {
        cout << "Company: " << company << ", Salary: " << salary << endl;
    }
};

class Student : virtual public Person {
protected:
    string college;
    float marks;
public:
    void setStudentInfo(const string &college, float marks) {
        this->college = college;
        this->marks = marks;
    }
    void showStudent() const {
        cout << "College: " << college << ", Marks: " << marks << endl;
    }
};

class Intern : public Employee, public Student {
private:
    int duration;
public:
    void setInternInfo(int duration) {
        this->duration = duration;
    }
    void showIntern() const {
        showPerson();
        showEmployee();
        showStudent();
        cout << "Internship Duration: " << duration << " months" << endl;
    }
};

int main() {
    Intern i;
    i.setPersonInfo("Rahul", 21);
    i.setEmployeeInfo("TechCorp", 20000);
    i.setStudentInfo("ABC University", 85.5);
    i.setInternInfo(6);
    i.showIntern();
}
