#include <iostream>
#include <fstream>   
using namespace std;
int main() {
    char ch;
    ifstream fin("sample.txt");  

    if (!fin) {
        cout << "File Not Found!" << endl;  
    } 
    else {

        while (fin.get(ch)) {     
            cout << ch << "\t";     
        }
        cout << endl;

        fin.close();
    }
    
}