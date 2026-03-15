/*Reverse a string by kepping the word order same */
import java.util.Scanner;

class Aditya_reverse {
    public static void main(String arg[]) {

    Scanner sc = new Scanner(System.in);

    
    System.out.print("Enter String: ");
    String str = sc.nextLine();

    String[] words = str.split(" ");
    String ans = "";

    for (int i = 0; i < words.length; i++) {
            String word = words[i];
            String reverse = "";
            for (int j = word.length() - 1; j >= 0; j--) {
                reverse = reverse + word.charAt(j);
            }
            ans = ans + reverse + " ";
        }

    System.out.println("reversed: " + ans);
    sc.close();
    
    }
}