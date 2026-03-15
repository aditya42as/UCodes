#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

int main() {
    vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    
    cout << "Size of vector: " << v.size() << endl;
    cout << "Capacity of vector: " << v.capacity() << endl;

    auto it = v.begin();
    cout << "Elements of the vector: ";
    while(it != v.end()) {
        cout << *it << " ";
        ++it;
    }
    cout << endl;

    v.pop_back();
    v.erase(v.begin() + 2);
    v.insert(v.begin() + 1, 43);

    it = v.begin();
    cout << "Elements of the vector after modifications: ";
    while(it != v.end()) {
        cout << *it << " ";
        ++it;
    }
    cout << endl << endl;


    list<int> l;

    l.push_back(23);
    l.push_back(75);
    l.push_back(45);
    l.push_front(34);
    l.push_front(24);

    cout << "Size of list: " << l.size() << endl;

    auto it1 = l.begin();
    cout << "Elements of the list: ";
    while(it1 != l.end()) {
        cout << *it1 << " ";
        ++it1;
    }
    cout << endl;

    l.pop_back();
    l.pop_front();
    l.remove(45);

    it1 = l.begin();
    cout << "Elements of the list after modifications: ";
    while(it1 != l.end()) {
        cout << *it1 << " ";
        ++it1;
    }
    cout << endl << endl;


    map<string, int> M;

    M["apple"] = 50;
    M["banana"] = 30;
    M["orange"] = 20;

    cout << "Size of map: " << M.size() << endl;

    auto it2 = M.begin();
    while(it2 != M.end()) {
        cout << it2->first << "=" << it2->second << "\t";
        ++it2;
    }
    cout << endl << endl;

    M.insert({"Guave", 43});

    auto it3 = M.find("banana");
    if (it3 != M.end()) {
        cout << "found banana at " << it3->second << "\n";
    }

    M.erase("banana");

    it2 = M.begin();
    while(it2 != M.end()) {
        cout << it2->first << "=" << it2->second << "\t";
        ++it2;
    }
    cout << endl << endl;

}
