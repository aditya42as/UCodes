import java.util.Scanner;

class BankAccount {
    float balance;
    boolean flag = false;

    BankAccount() {
        this(0.0f);
    }

    BankAccount(float balance) {
        this.balance = balance;
    }

    synchronized void withdraw(float amount) {
        while(flag) {
            try {
                wait();
            } catch(InterruptedException e) {
                System.out.println(e.getMessage());
            }
        }

        if(balance < amount) {
            System.out.println("Insufficient balance");
        } 
        else {
            balance -= amount;
            System.out.println("balance: " + balance);
        }

        flag = true;
        notify();
    }

    synchronized void deposit(float amount) {
        while(!flag) {
            try {
                wait();
            } catch(InterruptedException e) {
                System.out.println(e.getMessage());
            }
        }
        if(amount < 0) {
            System.out.println("Invalid Amount");
        }
        else {
            balance += amount;
            System.out.println("balance: " + balance);
        }

        flag = false;
        notify();
    }
}

class Depositer extends Thread {
    BankAccount acc;
    Scanner sc;

    Depositer(BankAccount acc, Scanner sc) {
        this.acc = acc;
        this.sc = sc;
    }

    public void run() {
        for(int i = 1; i <= 5; i++) {
            System.out.print("Enter deposit amount: ");
            float amount = sc.nextFloat();
            acc.deposit(amount);
        }
    }
}

class Withdrawer extends Thread {
    BankAccount acc;
    Scanner sc;

    Withdrawer(BankAccount acc, Scanner sc) {
        this.acc = acc;
        this.sc = sc;
    }

    public void run() {
        for(int i = 1; i <= 5; i++) {
            sc.nextLine();
            System.out.print("Enter withdraw amount: ");
            float amount = sc.nextFloat();
            acc.withdraw(amount);
        }
    }
}

class Aditya_MultiBank {
    public static void main(String arg[]) {
        BankAccount b = new BankAccount();
        Scanner sc = new Scanner(System.in);

        Depositer d = new Depositer(b, sc);
        Withdrawer w = new Withdrawer(b, sc);

        d.start();
        w.start();
    }
}