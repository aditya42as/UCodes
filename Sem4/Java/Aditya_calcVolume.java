/*Write a java program to create an interface that consists 
of a method to display volume () as an abstract method 
and redefine this method in the derived classes to suit 
their requirements. */

import java.util.Scanner;

interface DisplayAll {
    void setData(double radius, double height);
    abstract void displayVol();
}

class Cone implements DisplayAll {
    double radius, height;
    double cVol;

    public void setData(double radius, double height) {
        this.radius = radius;
        this.height = height;
    }

    public void displayVol() {
        cVol = (1.0/3) * 3.14 * radius * radius * height;
        System.out.println("Volume of Cone: " + cVol);
    }
}

class Hemisphere implements DisplayAll {
    double radius, height;
    double hVol;

    public void setData(double radius, double height) {
        this.radius = radius;
        this.height = height;
    }

    public void displayVol() {
        hVol = (2.0/3) * 3.14 * radius * radius * radius;
        System.out.println("Volume of Hemisphere: " + hVol);
    }
}

class Cylinder implements DisplayAll {
    double radius, height;
    double cyVol;

    public void setData(double radius, double height) {
        this.radius = radius;
        this.height = height;
    }

    public void displayVol() {
        cyVol = 3.14 * radius * radius * height;
        System.out.println("Volume of Cylinder: " + cyVol);
    }
}

class Aditya_calcVolume {
    public static void main(String arg[]) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter radius: ");
        double radius = sc.nextDouble();

        System.out.print("Enter height: ");
        double height = sc.nextDouble();

        Cone c1 = new Cone();
        c1.setData(radius, height);
        c1.displayVol();

        Hemisphere h1 = new Hemisphere();
        h1.setData(radius, 0);
        h1.displayVol();

        Cylinder cy1 = new Cylinder();
        cy1.setData(radius, height);
        cy1.displayVol();

        sc.close();
    }
}