import java.util.Scanner;

class PowerException extends Exception {
    public PowerException(String msg) {
        super(msg);
    }
}

class Calculator {

    int power(int n, int p) throws PowerException {

        if(n == 0 && p == 0) {
            throw new PowerException("n and p should be non zero");
        }

        if(n < 0 || p < 0) {
            throw new PowerException("n and p should be non-negative");
        }

        int res = 1;
        for(int i = 0; i < p; i++) {
            res = res * n;
        }
        return res;
    }
}

class Aditya_Power {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter total no of pairs: ");
        int total = sc.nextInt();

        String res[] = new String[total];
        for(int i = 0; i < total; i++) {
            System.out.print("Enter base number: ");
            int n = sc.nextInt();
            System.out.print("Enter power number: ");
            int p = sc.nextInt();
            Calculator c = new Calculator();
            try {
                int ans = c.power(n,p);
                res[i] = String.valueOf(ans);
            }
            catch(PowerException e) {
                res[i] = e.getMessage();
            }
        }
        System.out.println("\n");
        for(int i =0; i <total; i++) {
            System.out.println(res[i]);
        }
        sc.close();

        
    }
}