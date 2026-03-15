/*Practical No.10
Create a class called Invoice that a hardware store might use to represent an invoice for 
an item sold at the store. An Invoice should include four pieces of information as 
instance. 
Data Members - 
• partNumber (type String) 
• partDescription (type String) 
• quantity of the item being purchased (type int) 
• price_per_item (type double) 
Your class should have a constructor that initializes the four instance variables.  
Provide a set and a get method for each instance variable. In addition, provide a method 
named getInvoiceAmount() that calculates the invoice amount (i.e., multiplies the 
quantity by the price per item), then returns the amount as a double value. If the quantity 
is not positive, it should 
be set to 0. If the price per item is not positive,it should be set to0.0. Write a test 
application named invoiceTest that demonstrates class Invoice’s capabilities. 

Name: Aditya Singh
Section: E1
Roll no. 8*/

#include <iostream>
using namespace std;

class Invoice {
    string partNumber, partDescription;
    int quantity;
    double price_per_item;
public:
    Invoice() {
        this->partNumber = "";
        this->partDescription = "";
        this->quantity = 0;
        this->price_per_item = 0.0;
    }
    Invoice(string partNumber, string partDescription, int quantity, double price_per_item) {
        this->partNumber = partNumber;
        this->partDescription = partDescription;
        this->quantity = (quantity > 0) ? quantity : 0;
        this->price_per_item = (price_per_item > 0) ? price_per_item : 0.0;
    }
    void setpartNum(string partNumber){
        this->partNumber = partNumber;
    }
    void setpartDesc(string partDescription) {
        this->partDescription = partDescription;
    }

    void setQuantity(int quantity) { 
        this->quantity = (quantity > 0) ? quantity : 0;;
    }
    void setPrice(double price_per_item) { 
        this->price_per_item = (price_per_item > 0) ? price_per_item : 0.0; 
    }
    void getpartNum(){
        cout << "Part Number: " << partNumber << endl;
    }
    void getpartDesc(){
        cout << "Part Description: " << partDescription << endl;
    }
    void getQuantity(){
        cout << "Quantity " << quantity << endl;
    }
    void getPrice(){
        cout << "Price: " << price_per_item << endl;
    }
    double getInvoiceAmount() {
        return quantity * price_per_item;
    }
};

int main() {
    int q;
    double p;
    string desc, num;

    Invoice inv1("101","Hammer",5,120);
    
    inv1.getpartNum();
    inv1.getpartDesc();
    inv1.getQuantity();
    inv1.getPrice();
    cout << "Total Amount: "<< inv1.getInvoiceAmount()<< endl;

    Invoice inv2;
    
    cout<< "Enter name/description of product: ";
    cin >> desc;
    cout<< "Enter part number of product: ";
    cin >> num;
    cout<< "Enter price of product: ";
    cin >> p;
    cout << "enter the quantity for the product: ";
    cin >> q;
    
    inv2.setpartNum(num);
    inv2.setpartDesc(desc);
    inv2.setQuantity(q);
    inv2.setPrice(p);

    inv2.getpartNum();
    inv2.getpartDesc();
    inv2.getQuantity();
    inv2.getPrice();
    cout << "Total Amount: "<< inv2.getInvoiceAmount()<< endl;
}
