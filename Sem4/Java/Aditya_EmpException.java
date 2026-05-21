/*Write a java program to accept and print the employee 
details during runtime. The details will include employee 
id, name, dept_ Id. The program should raise an 
exception if user inputs incomplete or incorrect data
*/
import java.util.Scanner;

class Aditya_EmpException {

    public static void main(String arg[]) {

        Scanner sc = new Scanner(System.in);

        try {

            System.out.print("Enter Employee ID: ");
            int id = sc.nextInt();

            System.out.print("Enter Name: ");
            String name = sc.next();

            System.out.print("Enter Department ID: ");
            int dept = sc.nextInt();

            if(!Character.isUpperCase(name.charAt(0))) {
                throw new Exception("Name must start with capital letter");
            }

            if(id < 2001 || id > 5001) {
                throw new Exception("Invalid Employee ID");
            }

            if(dept < 1 || dept > 5) {
                throw new Exception("Invalid Department ID");
            }

            System.out.println("Valid Employee Details");

        } catch(Exception e) {
            System.out.println(e.getMessage());
        }
    }
}
