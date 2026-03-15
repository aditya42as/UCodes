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
            String reversedWord = "";

            for (int j = word.length() - 1; j >= 0; j--) {
                reversedWord = reversedWord + word.charAt(j);
            }

            ans = ans + reversedWord + " ";
        }

        System.out.println("Reversed: " + ans.trim());
        sc.close();
    }
}
