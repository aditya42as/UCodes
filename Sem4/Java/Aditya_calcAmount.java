    import java.util.Scanner;

    class Aditya_calcAmount {
        public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);

            System.out.println("Press:");
            System.out.println("1. Term Deposit");
            System.out.println("2. Recurring Deposit");
            int ch = sc.nextInt();
            double p,r,n,a;
            switch (ch) {
                case 1:
                    System.out.print("Enter Principal amount: ");
                    p = sc.nextDouble();
                    System.out.print("Enter Rate of Interest: ");
                    r = sc.nextDouble();
                    System.out.print("Enter Time period in years: ");
                    n = sc.nextDouble();
                    a = p * Math.pow((1 + r / 100), n);
                    System.out.println("Maturity Amount = " + a);
                    break;

                case 2:
                    System.out.print("Enter Monthly installment: ");
                    p = sc.nextDouble();
                    System.out.print("Enter Rate of Interest: ");
                    r = sc.nextDouble();
                    System.out.print("Enter Time period in months: ");
                    n = sc.nextDouble();
                    a = p * n + (p * n * (n + 1) / 2) * (r / 100) * (1.0 / 12);
                    System.out.println("Maturity Amount = " + a);
                    break;

                default:
                    System.out.println("Invalid Input");
            }

            sc.close();
        }
    }
