import java.io.*;

class Aditya_Move1 {
    public static void main(String arg[]){
        
        try {
            BufferedReader br = new BufferedReader(new FileReader("Numbers.txt"));
            BufferedWriter bw = new BufferedWriter(new FileWriter("Odd1.txt"));
            String line;
            while((line = br.readLine()) != null) {
                String[] content = line.split(" ");
                for(String temp : content) {
                    try {
                        
                        int num = Integer.parseInt(temp);
                        if(num >= 48 && num <= 57) {
                            if(num % 2 != 0) {
                                bw.write(num + " ");
                            }
                        }
                    } 
                    catch(Exception e) {
                        int sum = 0;
                        for(char c : temp.toCharArray()) {
                            sum += (int) c;
                        }
                        if(sum % 2 != 0) {
                            bw.write(temp + " ");
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



