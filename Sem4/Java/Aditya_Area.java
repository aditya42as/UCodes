import java.util.Scanner;

abstract class Shape {
    abstract void rectangleArea(int l,int b);
    abstract void squareArea(int a);
    abstract void circleArea(int r);
}

class Area extends Shape {
    void rectangleArea(int l,int b) {
        System.out.println("Rectangle = "+ (l*b));
    }
    void squareArea(int a) {
        System.out.println("Square = "+ (a*a));
    }
    void circleArea(int r) {
        System.out.println("Circle = "+ (3.14*r*r));
    }

}

class Aditya_Area{
    public static void main(String arg[]) {
        Scanner sc = new Scanner(System.in);
        Area a = new Area();

        System.out.print("Enter length and breadth for rectangle: ");
        int l = sc.nextInt();
        int b = sc.nextInt();

        System.out.print("Enter length for sqaure: ");
        int s = sc.nextInt();

        System.out.print("Enter radius of circle: ");
        int r = sc.nextInt();

        a.rectangleArea(l,b);
        a.squareArea(s);
        a.circleArea(r);

        sc.close();
    }
}