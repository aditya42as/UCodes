/*Templates are the foundation of generic programming, 
which involves writing code in a way that is independent 
of any particular type. Write a program that can create a 
list (create a class list) of given type (int, float, char etc.) 
and perform insertion and deletion on list object. */
#include <iostream>
#include <list>
using namespace std;

template <typename T>
class List {
private:
    list<T> L;

public:
    void insert_front(const T& val) {
        L.push_front(val);
    }

    void insert_back(const T& val) {
        L.push_back(val);
    }

    void delete_value(const T& val) {
        L.remove(val);
    }

    void display() const {
        if (L.empty()) {
            cout << "List is empty.\n";
            return;
        }
        for (const T& x : L)
            cout << x << " ";
        cout << endl;
    }
};

int main() {
    cout << "Integer List" << endl;
    List<int> intList;
    intList.insert_back(10);
    intList.insert_front(5);
    intList.insert_back(15);
    cout << "After insertion: ";
    intList.display();
    intList.delete_value(10);
    cout << "After deleting 10: ";
    intList.display();

    cout << "\nFloat List" << endl;
    List<float> floatList;
    floatList.insert_back(1.1f);
    floatList.insert_front(0.5f);
    floatList.insert_back(2.3f);
    cout << "After insertion: ";
    floatList.display();
    floatList.delete_value(0.5f);
    cout << "After deleting 0.5: ";
    floatList.display();

    cout << "\n Character List" << endl;
    List<char> charList;
    charList.insert_back('A');
    charList.insert_front('B');
    charList.insert_back('C');
    cout << "After insertion: ";
    charList.display();
    charList.delete_value('B');
    cout << "After deleting 'B': ";
    charList.display();
}
