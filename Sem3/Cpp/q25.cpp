/*Write a program to read and write from/to a file (char by 
char, word by word and line by line). */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string fname = "sample.txt";

    ofstream out(fname);
    out << "Hello world\nThis is a sample file.\nMy name is Aditya";
    out.close();
    cout << "Written to " << fname << "\n";

    ifstream in1(fname);
    cout << "\nChar by char:\n";
    char ch;
    while (in1.get(ch)) {
        cout << ch << " ";
    } 
    in1.close();
    cout <<"\n\n";

    ifstream in2(fname);
    cout << "\n\nWord by word:\n";
    string w;
    while (in2 >> w) {
        cout << w << "\n";
    }
    in2.close();
    cout <<"\n\n";

    ifstream in3(fname);
    cout << "\nLine by line:\n";
    string line;
    while (getline(in3, line)) {
        cout << line << "\n";
    }
    in3.close();
    cout <<"\n\n";
}
