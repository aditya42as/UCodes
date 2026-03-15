#include <iostream>
#include <string>
using namespace std;

class Item {
private:
    int itemCode;
    string itemName;
    float price;
    int quantity;

public:
    Item() {
        itemCode = 0;
        itemName = "";
        price = 0.0;
        quantity = 0;
    }

};

class Inventory {
private:
    Item *list;
    int count;

public:
    Inventory(int n) {
        count = n;
        list = new Item[count];
    }

    ~Inventory() {
        delete[] list;
    }

    void addItems() {
        
    }

    void display() const {
        cout << "\n--- Inventory Details ---\n";
        cout << "Code   Name                 Price      Quantity\n";
        cout << "-----------------------------------------------\n";
        for (int i = 0; i < count; i++)
            list[i].show();
    }

    long long totalValue() const {
        long long sum = 0;
        for (int i = 0; i < count; i++)
            sum += list[i].value();
        return sum;
    }
};

int main() {
    int n;
    cout << "Enter number of items to add: ";
    cin >> n;

    if (n <= 0)
        return 0;

    Inventory inv(n);
    inv.addItems();
    inv.display();

    cout << "\nTotal Inventory Value = " << inv.totalValue() << "\n";
    return 0;
}
