/*Write a java program to implement abstract class and 
abstract method to convert celsius to fahrenheit and vice versa*/
import java.util.Scanner;

abstract class Temperature{
    double temp;
    
    public void setTempData(double temp) {
        this.temp = temp;
    }

    abstract void changeTemp();
}

class Fahrenheit extends Temperature{
    double ctemp;
    void changeTemp() {
        ctemp = (temp - 32) * 5/9;
        System.out.println("Temperature in Celsius: " + ctemp);
    }
}

class Celsius extends Temperature{
    double ftemp;
    void changeTemp() {
        ftemp = 9/5 * (temp + 32);
        System.out.println("Temperature in Fahrenheit: " + ftemp);
    }
}

class Aditya_changeTemp{
    public static void main(String arg[]) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter temperature in Fahrenheit: ");
        double temp1 = sc.nextDouble();

        Fahrenheit f1 = new Fahrenheit();

        f1.setTempData(temp1);
        f1.changeTemp();

        System.out.print("Enter temperature in Celsius: ");
        double temp2 = sc.nextDouble();

        Celsius c1 = new Celsius();

        c1.setTempData(temp2);
        c1.changeTemp();

        sc.close();
    }
}