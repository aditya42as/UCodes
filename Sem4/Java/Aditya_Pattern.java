/*Program to find all the patterns of 0(1+)0 in the given 
string. Given a string containing 0's and 1's, find the total 
number of 0(1+)0 patterns in the string and output it.  */
import java.util.Scanner;

class Aditya_Pattern {
    public static void main(String arg[]) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter string: ");
        String str = sc.nextLine();

        int count = 0;

        for(int i = 0; i < str.length()-2; i++) {
            if(str.charAt(i) == '0') {
                int j = i+1;

                while(j < str.length() && str.charAt(j) == '1') {
                    j++;
                }

                if(j < str.length() && j > i+1 && str.charAt(j) == '0') {
                    count++;
                }
            }
        }

        System.out.println("Count = " + count);
    }
}