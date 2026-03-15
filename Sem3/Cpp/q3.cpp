/*Practical No.3
Implement a C++ program to find the non-repeating characters in string. 

Name: Aditya Singh
Section: E1
Roll no. 8*/

#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);
    for(int i=0; i<s.length(); i++) {
        char c = s[i];
        if(c == ' ') continue;
        int count = 0;
        for(int j=0; j<s.length(); j++) {
            if(s[j] == c) count++;
        }
        if(count == 1) cout << c << " ";
    }
    cout << endl;
}

