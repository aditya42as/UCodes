/*Write a java file handling program to count and display 
the number of palindromes present in a text file 
"myfile.txt" */
import java.util.*;
import java.io.*;

class Aditya_Palindrome {
    public static void main(String arg[]){
        
        try {
            BufferedReader br = new BufferedReader(new FileReader("myfile.txt"));
            int c = 0;
            String line;
            while((line = br.readLine()) != null) {
                String str[] = line.split(" ");
                for(String word: str) {
                    String rev = "";
                    for(int i = word.length() - 1; i >= 0; i--) {
                        rev = rev + word.charAt(i);
                    }
                    if(word.equals(rev)) {
                        c++;
                    }
                }

            }
            br.close();
            System.out.println("No. of palindromes: " + c);
        }
        catch(IOException e) {
            System.out.println(e.getMessage());
        }
    }
}



