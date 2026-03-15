/*Practical No.12
Create a class called Time that has separate int member data for hours, minutes and 
seconds. One constructor should initialize this data to 0, and another should initialize it 
to fixed values. A member function should display it in 11:59:59 format. A member 
function named add() should add two objects of type time passed as arguments. A main ( 
) program should create two initialized values together, leaving the result in the third 
time variable. 
Finally it should display the value of this third variable.*/

#include <iostream>
using namespace std;
class Time {
    int hours;
    int minutes;
    int seconds;
    public:
        Time() {
            hours = 0;
            minutes = 0;
            seconds = 0;
        }
        Time(int h, int m, int s) {
            hours = h;
            minutes = m;
            seconds = s;
        }
        void display() {
            cout << (hours < 10 ? "0" : "") << hours << ":" << (minutes < 10 ? "0" : "") << minutes << ":" << (seconds < 10 ? "0" : "") << seconds << endl;
        }
        void add(Time t1, Time t2) {
            seconds = t1.seconds + t2.seconds;
            minutes = t1.minutes + t2.minutes + seconds / 60;
            hours   = t1.hours   + t2.hours   + minutes / 60;
            seconds %= 60;
            minutes %= 60;
        }
};
int main() {
    Time t1(11, 59, 59);
    Time t2(2, 30, 45);
    Time t3;
    t3.add(t1, t2);
    cout << "First time: ";
    t1.display();
    cout << "Second time: ";
    t2.display();
    cout << "Added time: ";
    t3.display();
}
