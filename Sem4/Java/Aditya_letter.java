/*Convert name string into initails and display it*/
import java.util.Scanner;

class Aditya_letter {
    public static void main(String arg[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter String: ");
        String str = sc.nextLine();

        String[] words = str.split(" ");
        String ans = "";
           
        int len = words.length;
        for(int i = 0; i < len - 1; i++) {
            ans = ans + words[i].charAt(0) + " ";
        }
        ans = ans + words[len - 1];
        
        System.out.println("Result: " + ans);
        sc.close();
    }
}
