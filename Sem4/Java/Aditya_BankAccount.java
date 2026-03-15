
/*Write a java program to create a class named 'Bank ' and perform tasks as asked.*/
import java.util.Scanner;

class Bank {
    String name;
    String address;
    int accountNumber;
    double balance;

    static int nextAcc = 1001;

    Bank(String name, String address, double balance) {
        this.name = name;
        this.address = address;
        this.balance = balance;
        this.accountNumber = nextAcc++;
    }

    void display() {
        System.out.println("Name: " + name);
        System.out.println("Address: " + address);
        System.out.println("Account Number: " + accountNumber);
        System.out.println("Balance: " + balance);
    }

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if(amount <= balance) {
            balance -= amount;
        } else {
            System.out.println("Insufficient balance for account: " + accountNumber);
        }
    }

    void changeAddress(String address) {
        this.address = address;
    }
}

public class Aditya_BankAccount {
    public static void main(String arg[]) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of depositors: ");
        int n = sc.nextInt();
        sc.nextLine();

        Bank[] customers = new Bank[n];

        for(int i = 0; i < n; i++) {
            System.out.println("Enter details for depositor " + (i + 1));

            System.out.print("Name: ");
            String name = sc.nextLine();

            System.out.print("Address: ");
            String address = sc.nextLine();

            System.out.print("Initial Balance: ");
            double balance = sc.nextDouble();
            sc.nextLine();

            customers[i] = new Bank(name, address, balance);
        }

        System.out.print("\nEnter depositor index to display details: ");
        int index = sc.nextInt();
        sc.nextLine();
        customers[index].display();

        System.out.print("\nEnter depositor index to deposit money: ");
        index = sc.nextInt();
        System.out.print("Enter amount to deposit: ");
        double d = sc.nextDouble();
        customers[index].deposit(d);
        customers[index].display();

        System.out.print("\nEnter depositor index to withdraw money: ");
        index = sc.nextInt();
        System.out.print("Enter amount to withdraw: ");
        double w = sc.nextDouble();
        customers[index].withdraw(w);
        customers[index].display();

        sc.nextLine();
        System.out.print("\nEnter depositor index to change address: ");
        index = sc.nextInt();
        sc.nextLine();
        System.out.print("Enter new address: ");
        String newAdd = sc.nextLine();
        customers[index].changeAddress(newAdd);
        customers[index].display();
        sc.close();
    }
}
