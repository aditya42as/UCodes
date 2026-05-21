import java.io.*;

class Aditya_Move {
    public static void main(String arg[]){
        
        try {
            BufferedReader br = new BufferedReader(new FileReader("Numbers.txt"));
            BufferedWriter bw = new BufferedWriter(new FileWriter("Odd.txt"));
            String line;
            while((line = br.readLine()) != null) {
                String str[] = line.split(" ");
                for(String word: str) {
                    if(word.charAt(0) >= 48 && word.charAt(0) <= 57) {
                        int num = Integer.parseInt(word);
                        if(num % 2 != 0) {
                            bw.write(num + " ");
                        }
                    }
                }

            }
            br.close();
            bw.close();
        }
        catch(IOException e) {
            System.out.println(e.getMessage());
        }
    }
}
