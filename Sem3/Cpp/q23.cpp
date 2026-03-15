/*The task is to debug the existing code to successfully October 15, October 29, 
execute all provided test files. You are required to extend 
the existing code so that it handles the 
std::invalid_argument exception properly. More 
specifically, you have to extend the implementation of the 
process_input function. It takes integer n as an argument 
and has to work as follows: 
(a) It calls function largest_proper_divisor(n). 
(b) If this call returns a value without raising an exception, 
it should print in a single line result=d where d is the 
returned value. 
(c) Otherwise, if the call raises an invalid_argument 
exception, it has to print in a single line the string 
representation of the raised exception, i.e., its message. 
(d) Finally, no matter if the exception is raised or not, it 
should print in a single line returning control flow to the 
caller after any other previously printed output.*/

#include <iostream>
#include <stdexcept>
using namespace std;

long largest_proper_divisor(int n) {
    if (n <= 1) throw invalid_argument("invalid input");
    for (int d = n/2; d >= 1; --d) {
        if (n % d == 0) return d;
    }
    return 1; 
}

void process_input(int n) {
    try {
        long d = largest_proper_divisor(n);
        cout << "result=" << d << '\n';
    } catch (const invalid_argument& e) {
        cout << e.what() << '\n';
    }
    cout << "returning control flow to the caller\n";
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    process_input(n);
    return 0;
}
