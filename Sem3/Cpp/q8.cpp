/* Practical No.8
Anna is a contender for valedictorian of her high school. She wants to know how many 
students (if any) have scored higher than her in the exams given during this semester. 
Create a class named Student with the following specifications: 
Ø An instance variable named scores holds a student's 5 exam scores. 
Ø A void input () function reads 5 integers and saves them to scores. 
Ø An int calculateTotalScore() function that returns the sum of the student's scores.  

Name: Aditya Singh
Section: E1
Roll no. 8
*/

#include <iostream>
using namespace std;
class Student {
    int scores[5];
public:
    void input() {
        cout << "Enter 5 scores: ";
        for (int i = 0; i < 5; i++) {
            cin >> scores[i];
        }
    }
    int calculateTotalScore() {
        int sum = 0;
        for (int i = 0; i < 5; i++) sum += scores[i];
        return sum;
    }
};
int main() {
    int n;
    cout << "Enter No. of students: ";
    cin >> n;
    Student s[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter scores for student " << i + 1 << ":\n";
        s[i].input();
    }
    int annaScore = s[0].calculateTotalScore();
    cout << "Anna's Total Score = " << annaScore << endl;

    cout << "Students who scored higher than Anna:"<<endl;
    int count = 0;

    for (int i = 1; i < n; i++) {
        int total = s[i].calculateTotalScore();
        if (total > annaScore) {
            cout << "Student " << i + 1 << " Score = " << total << endl;
            count++;
        }
    }

    if (count == 0) {
        cout << "No student scored higher than Anna.";
    } else {
        cout << "Total " << count << " student scored higher than Anna";
    }
}
