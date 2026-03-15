/*Practical No.2
Construct a C++ program that removes a specific character from a given string and 
return the updated string.

Name: Aditya Singh
Section: E1
Roll no. 8*/

#include <iostream>
#include <string>
using namespace std;
int main() {
    string str;
    char ch;
    cout << "Enter a string: ";
    getline(cin, str);
    cout << "Enter character to remove: ";
    cin >> ch;
    string result = "";
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != ch) result += str[i];
    }
    cout << "Updated string: " << result;
}
